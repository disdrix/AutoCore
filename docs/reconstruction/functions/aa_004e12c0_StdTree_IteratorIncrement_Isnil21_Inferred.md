# Function record: StdTree_IteratorIncrement_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e12c0` |
| **Canonical name** | `StdTree_IteratorIncrement_Isnil21_Inferred` |
| **Ghidra name** | `FUN_004e12c0` |
| **Prior aliases** | `Named_CalleeOf_*` (**rejected** as role — call-chain label only) |
| **Address** | `0x004e12c0`–`0x004e130b` exclusive (**75 B** / `0x4B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities (partition assignment); role = shared `client::stdtree` |
| **Completion status** | **Dual-sealed 2026-08-05 R13-003** — algorithm/ABI/is_nil@+0x21 **High** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Terminal** | false |
| **Parent dual** | `0x00405650` StdTree_EraseAndRebalance_Isnil21_Inferred (R12-009) |
| **Dual start** | 2686 |

## Purpose

MSVC `_Tree_iterator::operator++` / tree **successor** in place. Advances `*it` to the next in-order node (or nil/end). Uses **is_nil** flag at node **`+0x21`**.

```text
// ECX = iterator*  (holds node*)
node = *it
if (node->isnil(+0x21) == 0):          // real node
  right = node->right(+8)
  if (right->isnil == 0):
    // successor = leftmost of right subtree
    walk left(+0) while child not nil
    *it = that
    return
  // else climb parents(+4) while was right-child
  parent = node->parent
  while (!parent->isnil && *it == parent->right)
    *it = parent; parent = parent->parent
  *it = parent
// if already nil: no-op
```

## Signature

```c
// ECX = node**; void; plain RET (C3)
void StdTree_IteratorIncrement_Isnil21_Inferred(int32_t *it /*ECX*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e12c0_FUN_004e12c0.md`
- Annotated: `docs/reconstruction/raw/aa_004e12c0_FUN_004e12c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil21_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_004e12c0.cpp`
- Reviews: `reviews/A_aa_004e12c0_StdTree_IteratorIncrement_Isnil21_Inferred.md`, `reviews/B_aa_004e12c0_StdTree_IteratorIncrement_Isnil21_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_004e12c0_FUN_004e12c0.md`
- Agent report: `docs/agents/task-dual-ab-004e12c0-r13-report.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `FUN_00405650` @ `0x004056b6` | parent erase isnil21 (R12-009 dualed) |
| Caller | `FUN_00406560` @ `0x0040668e` | insert-hint isnil21 |
| Caller | `FUN_004e3e70` @ `0x004e3efb` | erase isnil21 |
| Caller | `FUN_00511c00` @ `0x00511c8b` | erase isnil21 |
| Caller | `FUN_0059d300` @ `0x0059d38b` | erase isnil21 + DestroyStr14 |
| Caller | `FUN_005a2ea0` @ `0x005a2f2b` | erase isnil21 |
| Caller | `FUN_005a4590` @ `0x005a461b` | erase isnil21 |
| Caller | `FUN_005ae6d0` @ `0x005ae75b` | erase isnil21 family |
| Callee | *(none)* | leaf |

## Key offsets (node)

| Offset | Role | Confidence |
|---|---|---|
| +0 | left child | **High** |
| +4 | parent | **High** |
| +8 | right child | **High** |
| +0x20 | color (unused here; family peer) | **Inferred** (from erase family) |
| +0x21 | is_nil (byte) | **High** |

## Related units

| VA | Name | Relation |
|---|---|---|
| `0x00405650` | `StdTree_EraseAndRebalance_Isnil21_Inferred` | **parent dual** — calls this as successor |
| `0x00457cc0` | `StdTree_IteratorIncrement_Isnil19` | same CF; isnil **+0x19** |
| `0x004cb270` | `StdTree_IteratorIncrement_Inferred` | same CF; isnil **+0x29** |
| `0x00408590` | `StdTree_IteratorIncrement_Isnil31` | same CF; isnil **+0x31**; **EDX** ABI |
| `0x00568200` | `StdTree_IteratorIncrement_Isnil49` | same CF; isnil **+0x49**; **ECX** ABI |
| `0x00404000` | `StdTree_IteratorIncrement_Isnil131` | same CF; isnil **+0x131**; **EDX** ABI |
| `0x004313d0` | `StdTree_IteratorDecrement` | predecessor polarity |

## Confidence

| Claim | Level |
|---|---|
| ABI + in-place `*it` update | **High** |
| Successor CF (right-min / parent climb) | **High** |
| is_nil @ +0x21 | **High** |
| Shared helper across 8 erase/hint sites | **High** |
| Product English template name | **Inferred** |
| Runtime Confirmed | **not claimed** |
