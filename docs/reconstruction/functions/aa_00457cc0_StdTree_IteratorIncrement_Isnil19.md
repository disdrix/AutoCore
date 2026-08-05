# Function record: StdTree_IteratorIncrement_Isnil19

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457cc0` |
| **Canonical name** | `StdTree_IteratorIncrement_Isnil19` |
| **Ghidra name** | `FUN_00457cc0` |
| **Prior aliases** | `Named_CalleeOf_Named_assPreloader_00457cc0` (**rejected** — multi-caller shared util) |
| **Address** | `0x00457cc0`–`0x00457d0b` exclusive (**75 B** / `0x4B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `client::stdtree` |
| **Completion status** | **Dual-sealed 2026-08-04 W38-B** — algorithm/ABI/is_nil@+0x19 **High** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC `_Tree_iterator::operator++` / tree **successor** in place. Advances `*it` to the next in-order node (or nil/end). Uses **is_nil** flag at node **`+0x19`** (Val12 family — smaller than `+0x29` / `+0x49` twins).

## Signature

```c
// EDX = iterator (node**); void; plain RET (C3)
// ECX unused (decompiler phantom param_1)
void StdTree_IteratorIncrement_Isnil19(int32_t *it /*EDX*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00457cc0_FUN_00457cc0.md`
- Annotated: `docs/reconstruction/raw/aa_00457cc0_FUN_00457cc0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil19.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00457cc0.cpp`
- Reviews: `reviews/A_aa_00457cc0_StdTree_IteratorIncrement_Isnil19.md`, `reviews/B_aa_00457cc0_StdTree_IteratorIncrement_Isnil19.md`
- Scaffold record: `docs/reconstruction/functions/aa_00457cc0_FUN_00457cc0.md`
- Agent report: `docs/agents/task-dual-ab-00457cc0-0096a630-w38b-report.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `FUN_0040b440` | map/list walk; `LEA EDX` |
| Caller | `FUN_0043be60` | tree walk |
| Caller | `FUN_0043d7d0` | tree walk |
| Caller | `FUN_00447350` | `LEA EDX,[ESP+0x6c]` |
| Caller | `FUN_0046c450` | tree walk |
| Caller | `FUN_0046f6e0` | tree walk |
| Caller | `FUN_00970e50` | AssPreloader stale retire |
| Caller | `FUN_00971050` | AssPreloader path |
| Caller | `FUN_00971480` | AssPreloader drain tally |
| Callee | *(none)* | leaf |

## Key offsets (node)

| Offset | Role | Confidence |
|---|---|---|
| +0 | left child | **High** |
| +4 | parent | **High** |
| +8 | right child | **High** |
| +0x19 | is_nil (byte) | **High** |

## Related units

| VA | Name | Relation |
|---|---|---|
| `0x004cb270` | `StdTree_IteratorIncrement_Inferred` | same CF; isnil **+0x29** |
| `0x00568200` | `StdTree_IteratorIncrement_Isnil49` | same CF; isnil **+0x49**; **ECX** ABI |
| `0x004313d0` | `StdTree_IteratorDecrement` | predecessor; **EDX** ABI like this unit |
| `0x0043d5e0` | `StdMap_FindEq_UintKey_Val12` | Val12 isnil@+0x19 family |

## Confidence

| Claim | Level |
|---|---|
| ABI + in-place `*it` update | **High** |
| Successor CF (right-min / parent climb) | **High** |
| is_nil @ +0x19 | **High** |
| Not AssPreloader-private | **High** (9 callers) |
| Product English template name | **Inferred** |
