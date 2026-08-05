# Function record: StdVector_DwordResize_EaxCount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044a380` |
| **Canonical name** | `StdVector_DwordResize_EaxCount_Inferred` |
| **Ghidra name** | `FUN_0044a380` |
| **Address** | `0x0044a380` |
| **Body** | **105 B** (`0x0044a380`–`0x0044a3e9` exclusive) |
| **Module** | `autoassault.exe` |
| **System** | STL dword vector resize (EAX-count ABI) |
| **Name confidence** | **Inferred** (structural; no product/PDB plate) |
| **Dual** | **accept** (W37-Z A+B) |

## Role

Resize dword vector to `n` elements, filling new slots with stack value. Primary NestedHash bucket-vector rebuild helper under insert rehash (`FUN_0046bf90` @ `0x0046bfe3`).

## ABI

| Slot | Value |
|---|---|
| ECX | `vec*` |
| EAX | `newCount` |
| stack | `fill` (uint32) |
| cleanup | `RET 4` |

## Rejected aliases

- `Named_CalleeOf_Named_effVertexDecl_0044a380`
- Conflation with `FUN_004367f0` (`RET 8` stack-count twin)

## Artifacts

See `aa_0044a380_FUN_0044a380.md`.
