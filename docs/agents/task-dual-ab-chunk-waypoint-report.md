# Dual A/B review batch — TerrainChunk / Chunker / Waypoint (remaining 5)

**Date:** 2026-07-23  
**Scope:** The **5** clean units held after the TacArc/Map/Terrain batch (`task-dual-ab-tacarc-map-terrain-report.md`):  
`CVOGTerrainChunk_GetCornerData`, `CVOGTerrainChunk_BuildVertexBuffer`, `CVOGTerrainChunker_SubmitForRendering`, `CVOGWaypoint_InitFromSpawn`, `CVOGWaypoint_UpdateState`.  
**Excluded:** Launcher (never).  
**Cap:** 5 pairs (10 files).  
**Prior context:** Completes the TacArc/Map/Terrain/Waypoint name-filter dual-missing set (25 = 20 prior + 5 this batch).

## Selection

All five units already had raw / annotated / clean / function-record scaffolds; both `A_aa_*` and `B_aa_*` were missing.

## Pairs written

| # | Stable ID | Name | A verdict | B notes |
|---|---|---|---|---|
| 1 | `aa_005bf480` | CVOGTerrainChunk_GetCornerData | **accept** | tile/tint at (x−1,y−1); height16 @ +0x3e0 |
| 2 | `aa_005c01e0` | CVOGTerrainChunk_BuildVertexBuffer | accept-with-gaps | UV LUT combo×0x80; height16×scale; LOD |
| 3 | `aa_005c1940` | CVOGTerrainChunker_SubmitForRendering | accept-with-gaps | LOD bands + hide + submit vcalls |
| 4 | `aa_005d5580` | CVOGWaypoint_InitFromSpawn | **accept** | path COID + patrol +0x4c; state 0/2 |
| 5 | `aa_005d6300` | CVOGWaypoint_UpdateState | accept-with-gaps | +0x50 switch → four FUN handlers |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **GetCornerData tile offset:** height is on the vertex grid; **tile index + tint** come from **`(x-1, y-1)`** via `GetTileIndex` / `FUN_004a8c40`. Mis-porting same-cell samples breaks blend seams.
2. **BuildVertexBuffer links BuildTileUVTable:** 4 corner tiles (3 bits each) → 12-bit combo → **`DAT_00b45520 + combo*0x80`**. Equal four tiles: solid variant U offset **`(rand&3)*0.125`**. Y = **height16 × `*(param_2+0x44)`** (HeightScale/256). Client mesh only; pairs prior UV dual.
3. **SubmitForRendering is LOD/cull, not sim:** scoped phases LOD calculations → Submit chunks; per-chunk **`+0xd4` hide**, **`+0xd8` LOD** from **`DAT_00af3f98`** (6 bands); max-detail may `FUN_005c18a0`. Not a server stream radius.
4. **InitFromSpawn is the waypoint field seal:** `+0x40/+0x44` MapPath COID, `+0x48` extra, **`+0x4c` patrol float**, **`+0x50` = 0 or 2** from `param_6`, `+0x51` flags; pose `+0x20..+0x2c` zeroed (filled later by handlers). Aligns with spawn `MapPathCoid` / `InitialPatrolDistance` and AutoCore ghost path block.
5. **UpdateState is dispatch-only:** switch on **`+0x50`** → `FUN_005d5750` / `005d5960` / `005d5cc0` / `005d5680`. Called from ReturnToNormalLocation / path follow. Handler bodies still need rename + dual for bit-exact pose advance (pairs MapPath_AdvanceAndSteer).

## Not done (follow-ups, not dual-missing in this filter)

| Item | Notes |
|---|---|
| `FUN_005d5750` / `5960` / `5cc0` / `5680` | Waypoint state handlers — name + dual |
| `FUN_004a8c40` | Corner tint/color sample |
| `FUN_005c18a0` | Max-detail rebuild path from chunker |
| LOD table `0xaf3f98` dump | Band distance constants |
| Vertex format publish | BuildVertexBuffer stride/layout for any render port |

Post-batch: **0** remaining dual-missing in the TacArc/Map/Terrain/Waypoint name filter that drove the prior holdout list.

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (10 new files)
- One-shot writer (tmp): `tmp/write_dual_reviews_chunk_waypoint_remaining.py`
- Report: `docs/agents/task-dual-ab-chunk-waypoint-report.md`
- No Launcher touched; no servers started.
