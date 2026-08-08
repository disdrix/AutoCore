# Function record: StdTree_IteratorIncrement_Isnil31

| Field | Value |
|---|---|
| **Stable ID** | `aa_00408590` |
| **Canonical name** | `StdTree_IteratorIncrement_Isnil31` |
| **Ghidra name** | `FUN_00408590` |
| **Prior aliases** | `Named_CalleeOf_Client_NotifyActiveMissionChanged_00408590` (**rejected** as role — call-chain label only) |
| **Address** | `0x00408590`–`0x004085db` exclusive (**75 B** / `0x4B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `client::stdtree` |
| **Completion status** | **Dual-sealed 2026-08-04 WQ9H-H** — algorithm/ABI/is_nil@+0x31 **High** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Terminal** | false |

## Purpose

MSVC `_Tree_iterator::operator++` / tree **successor** in place. Advances `*it` to the next in-order node (or nil/end). Uses **is_nil** flag at node **`+0x31`**.

## Signature

```c
// EDX = iterator (node**); void; plain RET (C3)
// ECX unused (decompiler phantom param_1)
void StdTree_IteratorIncrement_Isnil31(int32_t *it /*EDX*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00408590_FUN_00408590.md`
- Annotated: `docs/reconstruction/raw/aa_00408590_FUN_00408590.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil31.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00408590.cpp`
- Reviews: `reviews/A_aa_00408590_StdTree_IteratorIncrement_Isnil31.md`, `reviews/B_aa_00408590_StdTree_IteratorIncrement_Isnil31.md`
- Scaffold record: `docs/reconstruction/functions/aa_00408590_FUN_00408590.md`
- Agent report: `docs/agents/task-dual-ab-00408590-00408640-wq9hh-report.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `FUN_00408ed0` @ `0x00408f38` | `LEA EDX,[ESP+0x6c]`; post-check isnil+0x31 |
| Caller | `FUN_00944770` @ `0x00944956` | `LEA EDX,[ESP+0x10]`; post-check isnil+0x31 |
| Callee | *(none)* | leaf |

## Key offsets (node)

| Offset | Role | Confidence |
|---|---|---|
| +0 | left child | **High** |
| +4 | parent | **High** |
| +8 | right child | **High** |
| +0x31 | is_nil (byte) | **High** |

## Related units

| VA | Name | Relation |
|---|---|---|
| `0x00457cc0` | `StdTree_IteratorIncrement_Isnil19` | same CF; isnil **+0x19** |
| `0x004cb270` | `StdTree_IteratorIncrement_Inferred` | same CF; isnil **+0x29** |
| `0x00568200` | `StdTree_IteratorIncrement_Isnil49` | same CF; isnil **+0x49**; **ECX** ABI |
| `0x004313d0` | `StdTree_IteratorDecrement` | predecessor; **EDX** ABI |
| `0x004085e0` | freelist residual (WQ9H-A) | **VA neighbor only** — not this unit |

## Confidence

| Claim | Level |
|---|---|
| ABI + in-place `*it` update | **High** |
| Successor CF (right-min / parent climb) | **High** |
| is_nil @ +0x31 | **High** |
| Not CNDHash freelist | **High** |
| Product English template name | **Inferred** |
