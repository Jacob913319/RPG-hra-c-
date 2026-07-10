import express from 'express';
import cors from 'cors';

const app = express();
const PORT = process.env.PORT || 4001;

app.use(cors());
app.use(express.json());

app.get('/health', (_request, response) => {
  response.json({ ok: true, service: 'ai-workflow-editor-server' });
});

app.get('/api/meta', (_request, response) => {
  response.json({
    phase: 1,
    features: ['workflow-canvas', 'drag-and-drop', 'node-editing', 'topological-order-preview']
  });
});

app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});