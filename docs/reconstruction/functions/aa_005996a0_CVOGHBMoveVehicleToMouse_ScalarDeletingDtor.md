# Function record: CVOGHBMoveVehicleToMouse_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005996a0` |
| **Canonical name** | `CVOGHBMoveVehicleToMouse_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_005996a0` |
| **Address** | `0x005996a0` |
| **Body range** | `0x005996a0`–`0x005996bd` (30 B / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` / heartbeat MoveVehicleToMouse lifecycle |
| **Completion status** | **dualed** — A/B **accept** |
| **Dual A/B** | `reviews/A_aa_005996a0_CVOGHBMoveVehicleToMouse_ScalarDeletingDtor.md`, `reviews/B_aa_005996a0_CVOGHBMoveVehicleToMouse_ScalarDeletingDtor.md` |
| **Last reviewed** | `2026-08-05` (R12-028) |

## Naming evidence

| Source | Value |
|---|---|
| Vtbl slot 0 | `PTR_FUN_009d5590+0` → this VA |
| RTTI | `.?AVCVOGHBMoveVehicleToMouse@@` @ type desc `0x00af33e0` |
| Pattern | MSVC scalar deleting dtor (`flags&1` → `operator_delete`; `RET 4`) |
| Family | same shape as dualed `CVOGHBMoveVehicle_ScalarDeletingDtor` / `CVOGHBBase_ScalarDeletingDtor` |
| Complete sibling | `FUN_00599570` (restore ToMouse vtbl + chain MoveVehicle complete; no free) |
| Shared OnEnd | `CVOGHBMoveVehicle_OnEnd` @ `0x00636ba0` (vtbl+0x10, MEGA-017) |
| Shared OnHeartBeat | `0x00636cc0` (vtbl+0x0c) |
| Contrast | base MoveVehicle vtbl[0] = `0x00636d10` (parent dual R11-024 — not this) |

**Decision:** promote **`CVOGHBMoveVehicleToMouse_ScalarDeletingDtor`** (class RTTI-sealed; role sealed by MSVC scalar pattern + vtbl[0]). **No** `_Inferred` suffix. **Never Runtime Confirmed.**

## Purpose / signature / artifacts

See twin record `aa_005996a0_FUN_005996a0.md`.
