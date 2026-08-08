# Function record: StdTree_LowerBound_StringKey_Isnil131_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403c60` |
| **Canonical name** | `StdTree_LowerBound_StringKey_Isnil131_Inferred` |
| **Ghidra name** | `FUN_00403c60` |
| **Address** | `0x00403c60`–`0x00403ca6` inclusive (**71 B** / `0x47`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `client::stdtree` / skills-abilities residual |
| **Completion status** | **Dual-sealed 2026-08-05 MEGA-041** |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | false |
| **Verdict** | **accept-with-gaps** |

## Purpose

In-place MSVC red-black tree **`lower_bound`** for the **isnil@+0x131** large-node family used by string-keyed maps (slash-command table callers; erase/free peers in same family).

## Signature

```c
// EAX = map* (_Myhead at +4); stack const std::string*; EAX = node*; RET 4
StdTreeNode* StdTree_LowerBound_StringKey_Isnil131_Inferred(
    /*EAX*/ void *map,
    /*stack*/ const std::string *key);
```

## Naming gate

| Evidence | Present? |
|---|---|
| Classic lower_bound CF (cand on `!(node.key < key)`) | **Yes** |
| isnil @ +0x131 sealed | **Yes** |
| string key @ +0x0C + IAT `operator<` | **Yes** |
| EAX-map + stack key + RET 4 | **Yes** |
| Family peers (iterator++ / erase isnil131) | **Yes** |
| Product/PDB host type English | **No** |

**Decision:** promote **`StdTree_LowerBound_StringKey_Isnil131_Inferred`**. Retire `Named_CalleeOf_*QuickBar*` scaffold. `_Inferred` retained for open product map type.

## Related units

| VA | Name | Relation |
|---|---|---|
| `0x00403d60` | `FUN_00403d60` (upper_bound peer) | twin inverted compare |
| `0x00404000` | `StdTree_IteratorIncrement_Isnil131` | dualed family; range walk |
| `0x00408ad0` | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` | family erase |
| `0x00407b70` | `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred` | family erase-range |
| `0x00402210` | `Map_LowerBoundFindByCharKey` | different isnil/key family |
| `0x0093bd10` | slash dispatch (undualed) | primary product caller |
| `0x00957820` | slash help list (undualed) | range caller |

## Artifacts

See `aa_00403c60_FUN_00403c60.md` for full path table.
