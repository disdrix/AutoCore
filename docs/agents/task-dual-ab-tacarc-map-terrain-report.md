# Dual A/B review batch — CVOGTacArc / CVOGMap / CVOGTerrain (cap 20)

**Date:** 2026-07-23  
**Scope:** Clean units under `docs/reconstruction/reconstructed-exact` matching `CVOGTacArc_*`, `CVOGMap_*`, `CVOGMapPath_*`, `CVOGTerrain*`, plus related `CVOGCreature_FindTerrainHeight`, that lacked **both** `A_aa_*` and `B_aa_*` under `docs/reconstruction/reviews/`.  
**Excluded:** Launcher (never).  
**Cap:** 20 pairs (40 files).  
**Prior context:** Wave-2 client/CVOG backlog called out terrain / tacarc / map helpers as still dual-missing after HBAI/HB waves.

## Selection

Pre-batch filter scan: **25** clean units matching TacArc/Map/Terrain/Waypoint/FindTerrain missing both A+B.  
This batch: **20** (full TacArc set, core Map/MapPath, explore/tile/height/tint pipeline, FindTerrainHeight).  
Held for next batch: **5** (chunker/chunk + waypoint).

## Pairs written

| # | Stable ID | Name | A verdict | B notes |
|---|---|---|---|---|
| 1 | `aa_00632af0` | CVOGTacArc_ctor | accept-with-gaps | client visual; color pack; FUN_0096* embeds |
| 2 | `aa_00632900` | CVOGTacArc_dtor_helper | **accept** | free mesh [0xb] + embed [6]; FUN teardown |
| 3 | `aa_00633590` | CVOGTacArc_vdtor | **accept** | scalar deleting dtor |
| 4 | `aa_00632a20` | CVOGTacArc_SetStateColor | accept-with-gaps | state 0/1/2/else RGB; MatZFailColor |
| 5 | `aa_006334e0` | CVOGTacArc_Initialize | accept-with-gaps | owner +0x20; mesh + bounds + UpdateMesh(0) |
| 6 | `aa_00633180` | CVOGTacArc_InitializeMesh | accept-with-gaps | NDTacArc.fx + veh_tacarc*.dds |
| 7 | `aa_00632c10` | CVOGTacArc_UpdateMesh | accept-with-gaps | owner cone fields; accessory +0x19c |
| 8 | `aa_004cfe60` | CVOGMap_CastTerrainHeight | **accept** | HF+ray; miss→hfY; filter 5/18; **not** wheels |
| 9 | `aa_004c6100` | CVOGCreature_FindTerrainHeight | accept-with-gaps | body? castRay : map cast; +foot 0x120 |
| 10 | `aa_005b05f0` | CVOGMap_LookupVariable | accept-with-gaps | hash chain; static +0x48 / computed |
| 11 | `aa_005afbc0` | CVOGMap_SetVariable | accept-with-gaps | write + listeners vtbl+0x13c; no create |
| 12 | `aa_005df950` | CVOGMapPath_AdvanceAndSteer | accept-with-gaps | stride 0x20; accept r; reaction COID |
| 13 | `aa_004a8b90` | CVOGTerrain_SampleExploredAreaId | **accept** | G>>3 area 1..32; OOB 0 |
| 14 | `aa_004a8c00` | CVOGTerrain_GetTileIndex | **accept** | G&7 tile layer; same +0x3dc |
| 15 | `aa_005bedd0` | CVOGTerrain_BuildTileUVTable | accept-with-gaps | 4096×0x80 LUT @ 0xb45520 |
| 16 | `aa_004a86f0` | CVOGTerrain_ApplyTilesetTextures | accept-with-gaps | +0x1c → 8 slots; Universal default |
| 17 | `aa_004aa0f0` | CVOGTerrain_StreamMapHeader | accept-with-gaps | MapVersion 0x3e=62; header only |
| 18 | `aa_004aba80` | CVOGTerrain_LoadMapImage | accept-with-gaps | height16 (A<<8)\|B; G tile+area |
| 19 | `aa_004ab100` | CVOGTerrain_LoadTintMap | accept-with-gaps | `_tint.tga` → +0x3a4 white default |
| 20 | `aa_004a9c70` | CVOGTerrain_ReloadRandomTintFile | accept-with-gaps | `_verttint` 8px; tileset name helper |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

## High-signal findings (for AutoCore)

1. **CastTerrainHeight is not wheel collide.** Miss returns **heightfield Y** (not `yStart`); end Y = hfY+**0.01**; filter **5 / 18** from flag. Use for spawn/snap/air-stab only; wheels stay on `TtPhantom::castRay`.
2. **FindTerrainHeight dual path:** physics body at creature `+0x254` → castRay; else map cast with `bLocal`; always add foot **`+0x120`**. Static IsNPC may skip client snap.
3. **Map G channel dual use:** low 3 bits = tile layer (`GetTileIndex`); high 5 = explore area id (`SampleExploredAreaId` >> 3). Same buffer **`terrain+0x3dc`**.
4. **LoadMapImage height packing:** `height16 = (A<<8)|B` — B is low height byte, not noise. World Y still needs HeightScale seal.
5. **Map variables:** Lookup/Set share hash; Set **does not create** on miss; listeners at node `+0x58..+0x5c` via ResolveObjectTarget + vtbl **+0x13c**.
6. **MapPath_AdvanceAndSteer:** point stride **0x20**; accept radius at point float **[3]**; inside radius can fire reaction COID **[4]/[5]**; index `0xFFFFFFFF` = nearest. Critical for NPC path / leash.
7. **TacArc is client UI only:** `NDTacArc.fx` + `veh_tacarc.dds`; state colors discrete; not server combat cone authority.
8. **StreamMapHeader MapVersion 62 (`0x3e`)**; dims/grid/tileset feed ApplyTilesetTextures + LoadMapImage; header ≠ height load.
9. **BuildTileUVTable** global 4096-entry blend LUT — server sim does not need it; rendering ports must match constants.

## Not done (remaining in filter)

| Name | Notes |
|---|---|
| `CVOGTerrainChunk_BuildVertexBuffer` | **Done** — see `task-dual-ab-chunk-waypoint-report.md` |
| `CVOGTerrainChunk_GetCornerData` | **Done** — see `task-dual-ab-chunk-waypoint-report.md` |
| `CVOGTerrainChunker_SubmitForRendering` | **Done** — see `task-dual-ab-chunk-waypoint-report.md` |
| `CVOGWaypoint_InitFromSpawn` | **Done** — see `task-dual-ab-chunk-waypoint-report.md` |
| `CVOGWaypoint_UpdateState` | **Done** — see `task-dual-ab-chunk-waypoint-report.md` |

Post-batch holdout was **5**; follow-up batch closed all five (`docs/agents/task-dual-ab-chunk-waypoint-report.md`).

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (40 new files)
- One-shot writer (tmp): `tmp/write_dual_reviews_tacarc_map_terrain.py`
- Report: `docs/agents/task-dual-ab-tacarc-map-terrain-report.md`
- No Launcher touched; no servers started.
