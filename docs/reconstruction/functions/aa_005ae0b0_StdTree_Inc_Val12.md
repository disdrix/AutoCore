# Function record: StdTree_Inc_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae0b0` |
| **Canonical name** | `StdTree_Inc_Val12` (Inferred) |
| **Ghidra name** | `FUN_005ae0b0` |
| **Address** | `0x005ae0b0` |
| **Body range** | `0x005ae0b0`–`0x005ae0fb` exclusive (**75** B / `0x4B`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map iterator (Val12) |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + ABI + Val12 layout sealed; product demangle open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005ae0b0_StdTree_Inc_Val12.md`, `reviews/B_aa_005ae0b0_StdTree_Inc_Val12.md` (2026-07-29 W28-N) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005ae0b0`
- `Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_005ae0b0` (legacy seed — **narrow**; unit is shared Val12 tree helper)
- Role: MSVC `_Tree::_Inc` / iterator++ for **Val12** nodes (isnil@+0x19)

## Purpose

Advance a tree iterator to the in-order successor of the current node. Used by Val12 single-node erase and related walkers to compute the post-erase iterator value.

## Signature

```c
void __fastcall StdTree_Inc_Val12(StdTreeNode_Val12** it);
// ECX = it; bare RET; void
```

## Algorithm

1. If `(*it)->isnil`: return (no-op).
2. If right child not nil: set `*it` to leftmost node of right subtree.
3. Else: walk parent chain while current is parent's right; set `*it` to that parent.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ae0b0_FUN_005ae0b0.md`
- Annotated: `docs/reconstruction/raw/aa_005ae0b0_FUN_005ae0b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Inc_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005ae0b0.cpp`
- Legacy alias: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_005ae0b0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005b3b20-005ae0b0-w28n-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers (9)** | `FUN_004188e0`, `FUN_0040d5b0`, `FUN_004e4130`, `FUN_005399f0`, `FUN_0053a8e0`, `FUN_00572ab0`, `FUN_00573250`, `FUN_005ae990`, `FUN_005e15a0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow successor algorithm | **High** |
| Val12 isnil@+0x19 / links +0/+4/+8 | **High** |
| ECX = node**; bare RET | **High** |
| Shared multi-map helper | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Erase consumer: `aa_005ae990` `StdTree_EraseNode_Val12`
- Peer erase clones: `aa_004e4130`, `aa_005399f0`, `aa_00573250`
- Rotates: `aa_00573170` Lrotate, `aa_00418c10` Rrotate
- Buynode: `aa_005ae220` `StdTree_Buynode_Val12`
