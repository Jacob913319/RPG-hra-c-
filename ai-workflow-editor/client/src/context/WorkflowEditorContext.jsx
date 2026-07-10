import { createContext, useContext } from 'react';

const WorkflowEditorContext = createContext(null);

export function WorkflowEditorProvider({ value, children }) {
  return <WorkflowEditorContext.Provider value={value}>{children}</WorkflowEditorContext.Provider>;
}

export function useWorkflowEditor() {
  const context = useContext(WorkflowEditorContext);

  if (!context) {
    throw new Error('useWorkflowEditor must be used inside WorkflowEditorProvider');
  }

  return context;
}