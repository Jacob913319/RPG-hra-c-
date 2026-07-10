import { memo } from 'react';
import { Handle, Position } from 'reactflow';
import { useWorkflowEditor } from '../context/WorkflowEditorContext';

function WorkflowNode({ id, data }) {
  const { updateNodeContent, removeNode } = useWorkflowEditor();

  return (
    <div className="workflow-node" style={{ '--node-accent': data.accent }}>
      <Handle className="workflow-handle workflow-handle-target" type="target" position={Position.Left} />

      <div className="workflow-node__header">
        <div>
          <p className="workflow-node__type">{data.label}</p>
          <p className="workflow-node__description">{data.description}</p>
        </div>

        <button className="workflow-node__remove" type="button" onClick={() => removeNode(id)}>
          ×
        </button>
      </div>

      <textarea
        className="workflow-node__textarea"
        value={data.content}
        placeholder={data.placeholder}
        onChange={(event) => updateNodeContent(id, event.target.value)}
      />

      <div className="workflow-node__footer">
        <span className="workflow-node__footer-label">Vstup</span>
        <span className="workflow-node__footer-label">Výstup</span>
      </div>

      <Handle className="workflow-handle workflow-handle-source" type="source" position={Position.Right} />
    </div>
  );
}

export default memo(WorkflowNode);