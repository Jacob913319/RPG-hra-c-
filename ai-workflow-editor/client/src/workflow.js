export const BLOCK_TYPES = [
  {
    type: 'text-input',
    label: 'Textový vstup',
    description: 'Uživatel napíše prompt ručně.',
    accent: '#f59e0b',
    placeholder: 'Zadej prompt nebo vstupní text...'
  },
  {
    type: 'ai-text',
    label: 'AI text blok',
    description: 'Zatím jen placeholder pro budoucí LLM krok.',
    accent: '#22c55e',
    placeholder: 'Konfigurace AI text bloku...'
  },
  {
    type: 'ai-media',
    label: 'AI obrázek/video blok',
    description: 'Placeholder pro generování médií.',
    accent: '#38bdf8',
    placeholder: 'Konfigurace obrázku nebo videa...'
  },
  {
    type: 'publish',
    label: 'Publikační blok',
    description: 'Placeholder pro export nebo publikaci.',
    accent: '#fb7185',
    placeholder: 'Nastavení publikace...'
  }
];

export function getBlockType(blockType) {
  return BLOCK_TYPES.find((item) => item.type === blockType) ?? BLOCK_TYPES[0];
}

export function createNodeId() {
  if (typeof crypto !== 'undefined' && crypto.randomUUID) {
    return `node-${crypto.randomUUID()}`;
  }

  return `node-${Date.now()}-${Math.random().toString(16).slice(2)}`;
}

export function createWorkflowOrder(nodes, edges) {
  const nodeById = new Map(nodes.map((node) => [node.id, node]));
  const adjacency = new Map(nodes.map((node) => [node.id, []]));
  const incoming = new Map(nodes.map((node) => [node.id, 0]));

  for (const edge of edges) {
    if (!nodeById.has(edge.source) || !nodeById.has(edge.target)) {
      continue;
    }

    adjacency.get(edge.source).push(edge.target);
    incoming.set(edge.target, incoming.get(edge.target) + 1);
  }

  const queue = nodes.filter((node) => incoming.get(node.id) === 0).map((node) => node.id);
  const ordered = [];

  while (queue.length > 0) {
    const currentId = queue.shift();
    ordered.push(nodeById.get(currentId));

    for (const nextId of adjacency.get(currentId) ?? []) {
      const nextIncoming = incoming.get(nextId) - 1;
      incoming.set(nextId, nextIncoming);

      if (nextIncoming === 0) {
        queue.push(nextId);
      }
    }
  }

  const hasCycle = ordered.length !== nodes.length;

  return {
    orderedNodes: ordered.filter(Boolean),
    hasCycle,
    unresolvedNodes: hasCycle ? nodes.filter((node) => !ordered.find((item) => item.id === node.id)) : []
  };
}

export function createNodeData(blockType, onRemove) {
  const block = getBlockType(blockType);

  return {
    blockType: block.type,
    label: block.label,
    description: block.description,
    accent: block.accent,
    placeholder: block.placeholder,
    content: block.type === 'text-input' ? 'Napiš první prompt sem...' : '',
    onRemove
  };
}