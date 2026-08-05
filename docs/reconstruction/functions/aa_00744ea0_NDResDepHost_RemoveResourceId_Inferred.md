# Function record: NDResDepHost_RemoveResourceId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00744ea0` |
| **Canonical name** | `NDResDepHost_RemoveResourceId_Inferred` |
| **Ghidra name** | `FUN_00744ea0` |
| **Address** | `0x00744ea0` |
| **Body** | **526 B** (`0x00744ea0`–`0x007450ae` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | ND resource dependency host |
| **Name confidence** | **Inferred** (erase CF + `DAT_00d1f050` host wiring; no product plate) |
| **Dual** | **accept-with-gaps** (W38-AE A+B) |

## Role

Unregister resource id from dependency host maps/vector; optional recursive cascade when `recurse != 0`.

## ABI

| Slot | Value |
|---|---|
| ECX | host `this*` |
| stack+4 | `int* pId` |
| stack+8 | `char recurse` |
| cleanup | `RET 8` |
| return | bool AL |

## Rejected aliases

- `Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh_00744ea0`
- Registration/insert reinterpretation

## Artifacts

See `aa_00744ea0_FUN_00744ea0.md`.
