import { useCallback, useMemo, useRef, useState } from 'react';
import ReactFlow, {
  addEdge,
  Background,
  Controls,
  MiniMap,
  MarkerType,
  useEdgesState,
  useNodesState,
  useReactFlow
} from 'reactflow';
import 'reactflow/dist/style.css';
import WorkflowNode from './nodes/WorkflowNode';
import { WorkflowEditorProvider } from './context/WorkflowEditorContext';
import { BLOCK_TYPES, createNodeData, createNodeId, createWorkflowOrder } from './workflow';

const nodeTypes = {
  workflowNode: WorkflowNode
};

function WorkflowCanvas() {
  const wrapperRef = useRef(null);
  const reactFlow = useReactFlow();
  const [nodes, setNodes, onNodesChange] = useNodesState([]);
  const [edges, setEdges, onEdgesChange] = useEdgesState([]);
  const [selectedType, setSelectedType] = useState(BLOCK_TYPES[0].type);

  const updateNodeContent = useCallback((nodeId, content) => {
    setNodes((currentNodes) =>
      currentNodes.map((node) =>
        node.id === nodeId
          ? {
              ...node,
              data: {
                ...node.data,
                content
              }
            }
          : node
      )
    );
  }, [setNodes]);

  const removeNode = useCallback((nodeId) => {
    setNodes((currentNodes) => currentNodes.filter((node) => node.id !== nodeId));
    setEdges((currentEdges) => currentEdges.filter((edge) => edge.source !== nodeId && edge.target !== nodeId));
  }, [setEdges, setNodes]);

  const onDragStart = useCallback((event, blockType) => {
    event.dataTransfer.setData('application/reactflow', blockType);
    event.dataTransfer.effectAllowed = 'move';
    setSelectedType(blockType);
  }, []);

  const getDropPosition = useCallback((event) => {
    if (typeof reactFlow.screenToFlowPosition === 'function') {
      return reactFlow.screenToFlowPosition({ x: event.clientX, y: event.clientY });
    }

    const bounds = wrapperRef.current?.getBoundingClientRect();

    return reactFlow.project({
      x: event.clientX - (bounds?.left ?? 0),
      y: event.clientY - (bounds?.top ?? 0)
    });
  }, [reactFlow]);

  const onDragOver = useCallback((event) => {
    event.preventDefault();
    event.dataTransfer.dropEffect = 'move';
  }, []);

  const onDrop = useCallback((event) => {
    event.preventDefault();

    const blockType = event.dataTransfer.getData('application/reactflow') || selectedType;
    const block = BLOCK_TYPES.find((item) => item.type === blockType);

    if (!block) {
      return;
    }

    const position = getDropPosition(event);
    const nodeId = createNodeId();

    setNodes((currentNodes) => [
      ...currentNodes,
      {
        id: nodeId,
        type: 'workflowNode',
        position,
        data: createNodeData(block.type)
      }
    ]);
  }, [getDropPosition, selectedType, setNodes]);

  const onConnect = useCallback((connection) => {
    setEdges((currentEdges) =>
      addEdge(
        {
          ...connection,
          type: 'smoothstep',
          animated: true,
          markerEnd: {
            type: MarkerType.ArrowClosed
          }
        },
        currentEdges
      )
    );
  }, [setEdges]);

  const runWorkflow = useCallback(() => {
    const result = createWorkflowOrder(nodes, edges);
    const order = result.orderedNodes.map((node, index) => ({
      step: index + 1,
      id: node.id,
      type: node.data.blockType,
      label: node.data.label,
      content: node.data.content
    }));

    console.log('Workflow execution order:', order);

    if (result.hasCycle) {
      console.warn('Workflow obsahuje cyklus, topologické řazení je neúplné.', result.unresolvedNodes);
    }
  }, [edges, nodes]);

  const contextValue = useMemo(() => ({
    updateNodeContent,
    removeNode
  }), [removeNode, updateNodeContent]);

  return (
    <WorkflowEditorProvider value={contextValue}>
      <div className="app-shell">
        <aside className="sidebar">
          <div className="sidebar__brand">
            <p className="sidebar__eyebrow">AI workflow editor</p>
            <h1>Vizuální skladatel bloků</h1>
            <p>
              Fáze 1: drag & drop canvas, editace bloků a konzolový run bez skutečných AI volání.
            </p>
          </div>

          <div className="sidebar__section">
            <div className="sidebar__section-head">
              <h2>Bloky</h2>
              <span>přetáhni na plátno</span>
            </div>

            <div className="palette">
              {BLOCK_TYPES.map((block) => (
                <button
                  key={block.type}
                  type="button"
                  className={`palette-item ${selectedType === block.type ? 'is-active' : ''}`}
                  draggable
                  onDragStart={(event) => onDragStart(event, block.type)}
                >
                  <span className="palette-item__accent" style={{ backgroundColor: block.accent }} />
                  <span className="palette-item__content">
                    <strong>{block.label}</strong>
                    <small>{block.description}</small>
                  </span>
                </button>
              ))}
            </div>
          </div>

          <div className="sidebar__section sidebar__section--run">
            <button className="run-button" type="button" onClick={runWorkflow}>
              Spustit workflow
            </button>
            <p>
              Výstup se zatím vypíše do konzole jako topologické pořadí uzlů podle propojení.
            </p>
          </div>
        </aside>

        <main className="canvas-wrap" ref={wrapperRef}>
          <ReactFlow
            className="workflow-canvas"
            nodes={nodes}
            edges={edges}
            nodeTypes={nodeTypes}
            onNodesChange={onNodesChange}
            onEdgesChange={onEdgesChange}
            onConnect={onConnect}
            onDrop={onDrop}
            onDragOver={onDragOver}
            fitView
            snapToGrid
            snapGrid={[20, 20]}
            defaultEdgeOptions={{
              type: 'smoothstep',
              animated: true,
              markerEnd: { type: MarkerType.ArrowClosed },
              style: {
                strokeWidth: 2.5,
                stroke: '#7dd3fc'
              }
            }}
            proOptions={{ hideAttribution: true }}
          >
            <Background gap={24} size={1} color="rgba(148, 163, 184, 0.18)" />
            <Controls showInteractive={false} />
            <MiniMap
              nodeColor={(node) => node.data?.accent ?? '#94a3b8'}
              maskColor="rgba(5, 10, 22, 0.7)"
              className="workflow-minimap"
            />
          </ReactFlow>

          {nodes.length === 0 ? (
            <div className="empty-state">
              <h2>Začni přetažením bloku</h2>
              <p>
                Přetáhni jeden z bloků z levého panelu na plátno a pak ho propojuj čarami.
              </p>
            </div>
          ) : null}
        </main>
      </div>
    </WorkflowEditorProvider>
  );
}

export default function App() {
  return <WorkflowCanvas />;
}