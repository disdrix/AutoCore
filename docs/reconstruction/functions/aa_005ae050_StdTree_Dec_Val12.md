# Function record: StdTree_Dec_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae050` |
| **Canonical name** | `StdTree_Dec_Val12` (Inferred) |
| **Ghidra name** | `FUN_005ae050` |
| **Address** | `0x005ae050` |
| **Body range** | `0x005ae050`–`0x005ae0a0` exclusive (**80** B / `0x50`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map iterator (Val12) |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + ABI + Val12 layout sealed; product demangle open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005ae050_StdTree_Dec_Val12.md`, `reviews/B_aa_005ae050_StdTree_Dec_Val12.md` (2026-07-29 W29-E) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005ae050`
- Role: MSVC `_Tree::_Dec` / iterator-- / Prevnode for **Val12** nodes (isnil@+0x19)
- Prior mis-role in some texts as “tree insert” — **rejected**; insert is always-insert helpers (`005ae4e0` / `0051c1c0` / `00573510` family)

## Purpose

Advance a tree iterator to the in-order predecessor of the current node. Used by Val12 unique insert-or-find paths to obtain the neighbor before deciding insert vs equal-key hit.

## Signature

```c
void __fastcall StdTree_Dec_Val12(StdTreeNode_Val12** it);
// ECX = it; bare RET; void
```

## Algorithm

1. If `(*it)->isnil`: `*it = node->right` (end → rightmost).
2. Else if left not nil: set `*it` to rightmost of left subtree.
3. Else: walk parent chain while current is parent's left; if parent not nil set `*it = parent`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ae050_FUN_005ae050.md`
- Annotated: `docs/reconstruction/raw/aa_005ae050_FUN_005ae050.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Dec_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005ae050.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005ae050-00572ab0-w29e-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers (7)** | `FUN_0053a8e0`, `Skill_CategoryCooldownMap_Insert` (`0x0051d2f0`), `FUN_00573810`, `FUN_0053a1a0`, `FUN_005e18d0`, `FUN_005aed20`, `FUN_005accf0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow predecessor algorithm | **High** |
| Val12 isnil@+0x19 / links +0/+4/+8 | **High** |
| ECX = node**; bare RET | **High** |
| Shared multi-map helper (not product-specific) | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Successor twin: `aa_005ae0b0` `StdTree_Inc_Val12`
- Insert-or-find consumer: `aa_00573810` `StdMap_InsertOrFind_Val12_UintKey`
- Buynode: `aa_005ae220` `StdTree_Buynode_Val12`
