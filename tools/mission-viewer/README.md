# Mission Viewer

Offline browser for Auto Assault missions. Merges `missions.glm` (story text + objective requirements) with `clonebase.wad` mission records (giver NPC, level/race/class gates, prerequisite missions, rewards, objective XP/credits/positions) and resolves clonebase CBIDs to display names.

## Files

| File | Purpose |
|------|---------|
| `mission-viewer-standalone.html` | **Primary deliverable** — open in any browser; all data embedded |
| `missions.json` | Same data as JSON (for tooling / `index.html`) |
| `index.html` | Dev page that `fetch`es `missions.json` (needs a local HTTP server) |
| `viewer-template.html` | HTML/JS shell used by the exporter |

## Open

**Shareable single file:** double-click `mission-viewer-standalone.html` (or open it from disk).

**Split JSON + HTML:**

```powershell
cd tools/mission-viewer
python -m http.server 8080
```

Then open `http://localhost:8080/`.

Deep-link a mission: `mission-viewer-standalone.html#mission-2945`

## Regenerate

Requires a game install with `missions.glm` and `clonebase.wad` (default `C:\Program Files (x86)\NetDevil\Auto Assault`, or set `AA_INSTALL`).

```powershell
python scripts/export_missions_json.py
```

Useful flags:

```powershell
python scripts/export_missions_json.py --limit 100          # smoke test
python scripts/export_missions_json.py --no-names           # skip CBID name scan
python scripts/export_missions_json.py --glm D:\aa\missions.glm --wad D:\aa\clonebase.wad
```

## What the viewer shows

- Search and filters (requirement type, mission type, core/side, prereqs, level)
- Giver NPC, continent, race/class/level gates, prerequisite missions (clickable)
- Story text with client markup (`[$imp]`, `[$npc]`, `[$loc]`, `[$emote]`, …)
- Sequenced objective flow with typed requirement cards:
  - **patrol** — waypoint COID lists, auto-complete distance
  - **kill** / **kill_aggregate** — counts and target CBIDs
  - **collect** / **deliver** — items and turn-in NPCs
  - **useitem** — place/explode/destroy/use patterns
  - escort, mission gates, timers, money, stunt, crazy taxi, …
- **Dev mode** — slots, COIDs, WorldPosition, ContinentObject, internal names

Field names align with server models under `src/AutoCore.Game/Mission/`.
