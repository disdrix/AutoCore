# Function record: StdTree_UpperBound_StringKey_Isnil131_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403d60` |
| **Canonical name** | `StdTree_UpperBound_StringKey_Isnil131_Inferred` |
| **Ghidra name** | `FUN_00403d60` |
| **Address** | `0x00403d60`–`0x00403da6` inclusive (**71 B** / `0x47`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `client::stdtree` / skills-abilities residual |
| **Completion status** | **Dual-sealed 2026-08-05 R10-020** |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | false |
| **Verdict** | **accept-with-gaps** |

## Purpose

In-place MSVC red-black tree **`upper_bound`** for the **isnil@+0x131** large-node family used by string-keyed maps (slash-help range callers; lower_bound/iterator++ peers in same family).

## Signature

```c
// EAX = map* (_Myhead at +4); stack const std::string*; EAX = node*; RET 4
StdTreeNode* StdTree_UpperBound_StringKey_Isnil131_Inferred(
    /*EAX*/ void *map,
    /*stack*/ const std::string *key);
```

## Naming gate

| Evidence | Present? |
|---|---|
| Classic upper_bound CF (cand on `key < node.key`) | **Yes** |
| isnil @ +0x131 sealed | **Yes** |
| string key @ +0x0C + IAT `operator<` | **Yes** |
| EAX-map + stack key + RET 4 | **Yes** |
| Twin lower_bound inverted compare | **Yes** |
| Family peers (iterator++ / lower_bound isnil131) | **Yes** |
| Product/PDB host type English | **No** |

**Decision:** promote **`StdTree_UpperBound_StringKey_Isnil131_Inferred`**. `_Inferred` retained for open product map type.

## Related units

| VA | Name | Relation |
|---|---|---|
| `0x00403c60` | `StdTree_LowerBound_StringKey_Isnil131_Inferred` | twin inverted compare (parent dual) |
| `0x00404000` | `StdTree_IteratorIncrement_Isnil131` | dualed family; range walk |
| `0x00408ad0` | `StdTree_EraseAndRebalance_Isnil131_DestroyStr0C_Inferred` | family erase |
| `0x00407b70` | `StdMap_EraseRange_Isnil131_DestroyStr0C_Inferred` | family erase-range |
| `0x00402210` | `Map_LowerBoundFindByCharKey` | different isnil/key family |
| `0x00957820` | slash help list (undualed) | sole product caller (2 sites) |

## Artifacts

See `aa_00403d60_FUN_00403d60.md` for full path table.
