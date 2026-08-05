# Function record: WorldCast_SetupCollectorAndDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006cad80` |
| **Canonical name** | `WorldCast_SetupCollectorAndDispatch_Inferred` |
| **Ghidra name** | `FUN_006cad80` |
| **Address** | `0x006cad80` |
| **Body range** | `0x006cad80`–`0x006cae18` (exclusive end `0x006cae19`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world / map collision cast |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + collector map sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_006cad80_WorldCast_SetupCollectorAndDispatch_Inferred.md`, `reviews/B_aa_006cad80_WorldCast_SetupCollectorAndDispatch_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W19-M) |

## Alias

- `FUN_006cad80` (Ghidra)
- `Named_CalleeOf_Named_CalleeOf_CVOGMap_CastTerrainHeight_006cad80` (auto parent-seed — **narrow**; prefer WorldCast_SetupCollectorAndDispatch)

## Purpose

Fill cast-collector fields from ray / optional filter / result, pack a stack ray packet, dispatch **`world->vtbl[+0x30]`**. Map/world collision path (via `MapCollisionCtx_CastRay`), not vehicle phantom cast.

## Signature

```c
// RET 0x14
void __thiscall WorldCast_SetupCollectorAndDispatch_Inferred(
    void *collector,   // ECX
    void *world,       // stack 0
    uint32_t *ray,     // stack 1
    void *filter,      // stack 2 (nullable)
    uint32_t extra,    // stack 3
    void *result);     // stack 4
```

## Algorithm

1. `collector+4 = ray`; `collector+0xc = result`.
2. `collector+8 = filter ? filter+0x14 : 0`.
3. `collector+0x34 = (ray[byte+0x20] && filter) ? filter+0x10 : 0`.
4. Pack packet `{ray[0..3], 1, ray+0x10, 0x10, extra}`.
5. `world->vtbl[+0x30](packet, collector, 0)` thiscall on world.
6. `ret 0x14`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_006cad80_FUN_006cad80.md`
- Annotated: `docs/reconstruction/raw/aa_006cad80_FUN_006cad80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/WorldCast_SetupCollectorAndDispatch_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_006cad80.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-006cad80-00561320-w19m-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | Indirect `world->vtbl[+0x30]` only |
| **Callers** | CODE: `MapCollisionCtx_CastRay` @ `0x0055e565` (1 xref) |

## Confidence

| Claim | Level |
|---|---|
| ABI thiscall + ret 0x14 | **High** |
| Collector field map | **High** |
| Ray flag at +0x20 | **High** |
| World vtbl+0x30 dispatch | **High** |
| Not phantom cast | **High** |
| Product/PDB symbol | Open |
| Filter / ray English | Open / inferred |

## Related

- `aa_0055e530` MapCollisionCtx_CastRay (sole wrapper)
- `CVOGMap_CastTerrainHeight` `0x004cfe60`
- Contrast `TtPhantom::castRay` `0x00580ed0`
