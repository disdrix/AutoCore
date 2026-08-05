# Function record: Map_Tree_Predecessor_Isnil15_Edx

| Field | Value |
|---|---|
| **Stable ID** | `aa_004129f0` |
| **Canonical name** | `Map_Tree_Predecessor_Isnil15_Edx` (Inferred) |
| **Ghidra name** | `FUN_004129f0` |
| **Address** | `0x004129f0` |
| **Body range** | `0x004129f0`–`0x00412a40` inclusive (**81** B / `0x51`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map iterator (isnil@+0x15) |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + EDX ABI + isnil15 layout sealed; product demangle open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004129f0_Map_Tree_Predecessor_Isnil15_Edx.md`, `reviews/B_aa_004129f0_Map_Tree_Predecessor_Isnil15_Edx.md` (2026-08-04 W38-M) |
| **Last reviewed** | `2026-08-04` |

## Alias

- `FUN_004129f0`
- Role: MSVC `_Tree::_Dec` / iterator-- / Prevnode for **isnil@+0x15** nodes
- **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_bActiveObj_004129f0`
- Peer (ECX ABI): `Map_Tree_Predecessor_Isnil15` @ `0x005a2850` (W19-N)

## Purpose

Advance a tree iterator to the in-order predecessor of the current node. Shared leaf used by multiple map walk / insert-or-find style callers that pass the iterator in **EDX**.

## Signature

```c
void Map_Tree_Predecessor_Isnil15_Edx(MapTreeNode_Isnil15** it /*EDX*/);
// bare RET; void; no stack args
```

## Algorithm

1. If `(*it)->isnil`: `*it = node->right` (end → rightmost).
2. Else if left not nil: set `*it` to rightmost of left subtree.
3. Else: walk parent chain while current is parent's left; if parent not nil set `*it = parent`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004129f0_FUN_004129f0.md` (+ W38-M append)
- Annotated: `docs/reconstruction/raw/aa_004129f0_FUN_004129f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Map_Tree_Predecessor_Isnil15_Edx.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004129f0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004129f0-00463e30-w38m-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers (8)** | `FUN_00411fa0`, `FUN_0041b360`, `FUN_0041d680`, `FUN_00421050`, `FUN_0043daf0`, `FUN_00452190`, `FUN_004582e0`, `FUN_00458510` |

## Confidence

| Claim | Level |
|---|---|
| Control flow predecessor algorithm | **High** |
| isnil@+0x15 / links +0/+4/+8 | **High** |
| EDX = node**; bare RET | **High** |
| Shared multi-map helper (not product-specific) | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- ECX peer: `aa_005a2850` `Map_Tree_Predecessor_Isnil15`
- Val12 dec (isnil@+0x19, ECX): `aa_005ae050` `StdTree_Dec_Val12`
- Successor family: `StdTree_Inc_Val12` (`0x005ae0b0`)
