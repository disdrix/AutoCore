# Function record: StdTree_IteratorIncrement_Isnil131

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404000` |
| **Canonical name** | `StdTree_IteratorIncrement_Isnil131` |
| **Ghidra name** | `FUN_00404000` |
| **Address** | `0x00404000`–`0x00404057` inclusive (**88 B** / `0x58`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `client::stdtree` |
| **Completion status** | **Dual-sealed 2026-08-05 WQ9L-A** |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | false |
| **Verdict** | **accept** |

## Purpose

In-place MSVC red-black tree iterator **successor** (`operator++`) for the **isnil@+0x131** large-node family used by string-valued maps (erase-range `00407b70` / erase `00408ad0`).

## Signature

```c
// EDX = node**; void; plain RET (C3)
void StdTree_IteratorIncrement_Isnil131(int32_t *it /*EDX*/);
```

## Naming gate

| Evidence | Present? |
|---|---|
| Classic successor CF (right→leftmost / parent climb) | **Yes** |
| isnil @ +0x131 sealed in every branch | **Yes** |
| EDX iterator ABI + plain RET | **Yes** |
| Call sites LEA EDX then CALL | **Yes** |
| Product/PDB English host type | **No** |

**Decision:** promote **`StdTree_IteratorIncrement_Isnil131`** (offset-qualified family peer; algorithm proven → no `_Inferred` suffix, matching isnil31/19/49 peers).

## Related units

| VA | Name | Relation |
|---|---|---|
| `0x00408590` | `StdTree_IteratorIncrement_Isnil31` | same CF; isnil **+0x31** |
| `0x00408ad0` | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` | caller (OWN peer) |
| `0x00407b70` | `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred` | caller |

## Artifacts

See `aa_00404000_FUN_00404000.md` for full path table.
