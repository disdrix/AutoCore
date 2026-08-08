# Function record: CVOGHBMoveVehicle_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636d10` |
| **Canonical name** | `CVOGHBMoveVehicle_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_00636d10` |
| **Address** | `0x00636d10` |
| **Body range** | `0x00636d10`–`0x00636d2d` (30 B / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` / heartbeat MoveVehicle lifecycle |
| **Completion status** | **dualed** — A/B **accept** |
| **Dual A/B** | `reviews/A_aa_00636d10_CVOGHBMoveVehicle_ScalarDeletingDtor.md`, `reviews/B_aa_00636d10_CVOGHBMoveVehicle_ScalarDeletingDtor.md` |
| **Last reviewed** | `2026-08-05` (R11-024) |

## Naming evidence

| Source | Value |
|---|---|
| Vtbl slot 0 | `PTR_FUN_009e3b70+0` → this VA |
| RTTI | `.?AVCVOGHBMoveVehicle@@` @ type desc `0x00af33c0` |
| Pattern | MSVC scalar deleting dtor (`flags&1` → `operator_delete`; `RET 4`) |
| Family | same shape as dualed `CVOGHBBase_ScalarDeletingDtor` / `CVOGMenu_ScalarDeletingDtor` |
| Complete sibling | `FUN_00636b90` (restore same vtbl + base chain; no free) |
| OnEnd sibling | `CVOGHBMoveVehicle_OnEnd` @ `0x00636ba0` (vtbl+0x10, MEGA-017) |
| Contrast | ToMouse vtbl[0] = `0x005996a0` (not this) |

**Decision:** promote **`CVOGHBMoveVehicle_ScalarDeletingDtor`** (class RTTI-sealed; role sealed by MSVC scalar pattern + vtbl[0]).

## Purpose / signature / artifacts

See twin record `aa_00636d10_FUN_00636d10.md`.
