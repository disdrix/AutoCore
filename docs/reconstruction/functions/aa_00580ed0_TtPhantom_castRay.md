# Function record: TtPhantom_castRay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00580ed0` |
| **Canonical name** | `TtPhantom_castRay` |
| **Ghidra name** | `FUN_00580ed0` |
| **Address** | `0x00580ed0`–`0x005810fd` (**558 B** / `0x22E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control / physics |
| **Plate** | `"TtPhantom::castRay"` @ `0x009d4574` |
| **ABI** | `__thiscall`; ECX=this; stack `ray*`, `result*`; **`RET 8`** |
| **Dual** | MEGA-101 2026-08-05 — **accept-with-gaps** (A + B) |
| **Terminal / runtime Confirmed** | **false** / not claimed |

## Purpose

Retail **phantom geometry raycast** backend:

1. Optional filter prep from ray flag + `phantom+8→+0xd0` (not forwarded in decompile — gap).
2. For each collidable in `phantom+0x80` / count `+0x84`:
   - World start/end → body-local via `R^T * (P - T)`.
   - `shape->vtbl[+0x20](hitFlag, localRay, result)`.
   - On hit flag: `result+0x20 = collidable`.
3. If hit: `FUN_005d6ae0` rotates normal body-local → world.

## Consumers

| Caller | Role |
|---|---|
| `FUN_0064bbd0` (wheel collide packer) | Suspension ray; primary vehicle port seam |
| `CVOGCreature_FindTerrainHeight` | Phantom path when `creature+0x254 != 0`; else map terrain sibling |

## Not this function

| VA / name | Why different |
|---|---|
| `CVOGMap_CastTerrainHeight` | Map heightfield **Y** only |
| `MapCollisionCtx_CastRay` `0x0055e530` | Different cast context (prior dual) |

## Port notes

- Preserve **fraction along ray** + **world normal** + hit/miss via `result+0x20`.
- Geometry-later: inject world query with same I/O; do not bake terrain-Y-only into wheel compression.
- Pair with `FUN_005d6ae0` for normal basis if emitting body-local hits.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00580ed0_FUN_00580ed0.md` |
| Annotated | `docs/reconstruction/raw/aa_00580ed0_FUN_00580ed0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TtPhantom_castRay.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00580ed0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00580ed0_TtPhantom_castRay.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00580ed0_TtPhantom_castRay.md` |
| FUN record | `docs/reconstruction/functions/aa_00580ed0_FUN_00580ed0.md` |
| Report | `docs/agents/task-dual-ab-00580ed0-mega-101-report.md` |
