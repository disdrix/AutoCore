# Function record: VehicleNet_PackUpdate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f5de0` |
| **Canonical name** | `VehicleNet_PackUpdate` |
| **Address** | `0x005f5de0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` (TNL GhostVehicle pack) |
| **Completion status** | **Human-refined** — dual A/B 2026-07-29; three-rep scaffold present |
| **Dual A/B** | **Present** — `reviews/A_aa_005f5de0_VehicleNet_PackUpdate.md`, `reviews/B_aa_005f5de0_VehicleNet_PackUpdate.md` |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Source |
|---|---|
| `VehicleNet_PackUpdate` | Ghidra symbol + dual seal |
| `Drive_Packing_initial_update_for_vehicle_I64` | Embedded string scaffold alias |
| `FUN_005f5de0` | Pre-rename stable stem (file keeps this id) |

## Purpose

Client TNL **GhostVehicle packUpdate** (virtual; DATA xref `0x009dd1e0`). Mask-gated serialization of vehicle create body (initial), hardpoints, owner GM/AI, **PositionMask** pose + quantized thr/steer, and combat pools. Sibling **unpack** is `VehicleNet_UnpackGhostVehicle` @ `0x005f7720`. Server production mirror: `GhostVehicle.cs::PackUpdate`.

## Signature (decompiler-derived)

```c
// __thiscall / virtual packUpdate shape (Ghidra)
uint * VehicleNet_PackUpdate(
    int ghost,           // ghost / NetObject (parent @ +0x50)
    undefined4 unused_or_stream_ctx,
    uint mask_lo,        // low 32 of 64-bit update mask
    uint mask_hi,        // high 32
    undefined4 conn);    // connection handle for skill helpers
```

Return: decompiler emits stack residue — **true TNL dirty-mask ABI residual** (see dual B).

## Behavioral summary

1. Fail if `ghost+0x50 == 0`.
2. Resolve vehicle entity via parent vfunc `+0x1d4`.
3. **`DAT_00d1798c != 0` → initial** create body + set dirty `0x80`; else skills-delta only for `mask & 0x80`.
4. Pack wheel / front / turret / rear / melee / ornament / armor hardpoints from mask bits.
5. Pack GM, health, pose (`mask & 2`), combat tail (heat/shield/power/token).
6. Pose: pos/rot/vel/angVel → firing byte → drive-flags byte → thr `+0x614` (6b) → steer `+0x618` (6b) → turret `+0x158`.

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | **High** (Ghidra + strings) |
| Signature | **Probable** (mask halves High; return residual) |
| Control flow | **High** (live decompile ≡ raw) |
| Naming | **High** (Ghidra + wire role) |
| Mask → section map | **High** (constants + `read_memory` table) |
| Owner-leaf English | **Low–Medium** residual |
| Side effects | **High CF** (BitStream writes only) |
| Overall | **accept-with-gaps** |

## Open questions

- Return dirty-mask ABI vs decompiler stack return
- Initial 7th optional float offset (`+0x210` alias?)
- Runtime / differential equivalence vs server C#

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_005f5de0_FUN_005f5de0.md` |
| Annotated | `raw/aa_005f5de0_FUN_005f5de0.annotated.md` |
| Clean | `reconstructed-exact/FUN_005f5de0.cpp` |
| Dual A | `reviews/A_aa_005f5de0_VehicleNet_PackUpdate.md` |
| Dual B | `reviews/B_aa_005f5de0_VehicleNet_PackUpdate.md` |
| Sibling unpack | `functions/aa_005f7720_*` / dual A/B |
| Server mirror | `src/AutoCore.Game/TNL/Ghost/GhostVehicle.cs` |
| Pose notes | `physics/verified/server_ghost_pack_notes.md` |
