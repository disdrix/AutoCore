# Function record: StdVector_DwordEraseRange_EbxVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469f10` |
| **Canonical name** | `StdVector_DwordEraseRange_EbxVec_Inferred` |
| **Ghidra name** | `FUN_00469f10` |
| **Address** | `0x00469f10` |
| **Body** | **49 B** (`0x00469f10`–`0x00469f41` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | STL dword vector erase-range (EBX-vec ABI) |
| **Name confidence** | **Inferred** (structural; no product/PDB plate) |
| **Dual** | **accept** (W38-N A+B) |

## Role

Erase `[first, last)` from a dword vector by sliding the tail and publishing `end`. Sole sealed consumer: `StdVector_DwordResize_EaxCount_Inferred` shrink arm.

## ABI

| Slot | Value |
|---|---|
| EBX | `vec*` |
| EAX | `outIt*` (`*outIt = first`) |
| stack | `first`, `last` |
| cleanup | `RET 8` |

## Rejected aliases

- `Named_CalleeOf_Named_CalleeOf_Named_effVertexDecl_00469f10`
- Conflation with `FUN_00410490` (`RET 0xC` thiscall + memmove twin)

## Artifacts

See `aa_00469f10_FUN_00469f10.md`.
