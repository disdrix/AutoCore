# Function record: StdVector_DwordResize_EcxCount_EdxVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00456780` |
| **Canonical name** | `StdVector_DwordResize_EcxCount_EdxVec_Inferred` |
| **Ghidra name** | `FUN_00456780` |
| **Address** | `0x00456780` |
| **Body** | **117 B** (`0x00456780`–`0x004567f5` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | STL dword vector resize (ECX-count / EDX-vec ABI) |
| **Name confidence** | **Inferred** (structural; no product/PDB plate) |
| **Dual** | **accept** (W38-H A+B) |

## Role

Resize dword vector to `n` elements, filling new slots with stack value. Used widely (pool freelist pop shrink, physics asset vectors, hash/list hosts).

## ABI

| Slot | Value |
|---|---|
| EDX | `vec*` |
| ECX | `newCount` |
| stack | `fill` (uint32) |
| cleanup | `RET 4` |

## Rejected aliases

- `Named_CalleeOf_Named_gfxBody_00456780`
- Conflation with `FUN_0044a380` (EAX-count / ECX-vec) or `FUN_004367f0` (`RET 8`)

## Artifacts

See `aa_00456780_FUN_00456780.md`.
