# Function record: StdTree_IteratorIncrement_Isnil49

| Field | Value |
|---|---|
| **Stable ID** | `aa_00568200` |
| **Canonical name** | `StdTree_IteratorIncrement_Isnil49` |
| **Ghidra name** | `FUN_00568200` |
| **Prior aliases** | `Named_CalleeOf_Client_UpdateMissionJournal_00568200` (incomplete — multi-caller; role was misread as id-fill) |
| **Address** | `0x00568200`–`0x0056824a` (74 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared `client::stdtree` |
| **Completion status** | **Dual-sealed 2026-07-29 W22-B** — algorithm/ABI/is_nil@+0x49 **High** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC `_Tree_iterator::operator++` / tree **successor** in place. Advances `*it` to the next in-order node (or nil/end). Uses **is_nil** flag at node **`+0x49`** (larger value-node family than twin `aa_004cb270` @ `+0x29`).

## Signature

```c
// __fastcall; ECX = iterator (node**); void
void __fastcall StdTree_IteratorIncrement_Isnil49(int32_t *it);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00568200_FUN_00568200.md`
- Annotated: `docs/reconstruction/raw/aa_00568200_FUN_00568200.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_IteratorIncrement_Isnil49.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00568200.cpp`
- Reviews: `reviews/A_aa_00568200_StdTree_IteratorIncrement_Isnil49.md`, `reviews/B_aa_00568200_StdTree_IteratorIncrement_Isnil49.md`
- Scaffold record: `docs/reconstruction/functions/aa_00568200_FUN_00568200.md`

## Callers / callees

| Direction | VA / name | Notes |
|---|---|---|
| Caller | `Client_UpdateMissionJournal` `0x008ae130` | journal tree walk; `LEA ECX,[ESP+…]` |
| Caller | `FUN_00538780` | map walk |
| Caller | `FUN_00568c60` | map walk |
| Caller | `FUN_00569560` | `StdMap_InsertWithHint_IntKey` successor probe |
| Callee | *(none)* | leaf |

## Key offsets (node)

| Offset | Role | Confidence |
|---|---|---|
| +0 | left child | **High** |
| +4 | parent | **High** |
| +8 | right child | **High** |
| +0x49 | is_nil (byte) | **High** |

## Confidence

| Claim | Level |
|---|---|
| ABI + in-place `*it` update | **High** |
| Successor CF (right-min / parent climb) | **High** |
| is_nil @ +0x49 | **High** |
| Not journal id-vector fill | **High** (falsified) |
| Product English template name | **Inferred** |
