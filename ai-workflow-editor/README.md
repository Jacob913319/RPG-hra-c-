# AI Workflow Editor

Fáze 1 obsahuje plně funkční vizuální editor workflow:

- React canvas přes celou obrazovku
- drag & drop bloků z levého panelu
- propojování bloků čarami
- editaci textu přímo v blocích
- topologické seřazení workflow při kliknutí na `Spustit workflow`
- připravený Express backend pro pozdější AI logiku

## Struktura

- `client/` - React + React Flow frontend
- `server/` - Node.js + Express backend stub
- `package.json` - root workspace a společné skripty

## Lokální spuštění

1. Nainstaluj závislosti v kořeni projektu:

   ```bash
   npm install
   ```

2. Spusť oba procesy najednou:

   ```bash
   npm run dev
   ```

3. Frontend poběží na `http://localhost:5173`.
4. Backend poběží na `http://localhost:4001`.

## Poznámka

Backend je zatím jen připravený skeleton. Žádné reálné AI volání se ve fázi 1 neprovádí.