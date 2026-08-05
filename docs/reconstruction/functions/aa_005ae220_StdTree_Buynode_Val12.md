# Function record: StdTree_Buynode_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae220` |
| **Canonical name** | `StdTree_Buynode_Val12` (Inferred) |
| **Ghidra name** | `FUN_005ae220` |
| **Address** | `0x005ae220` |
| **Body range** | `0x005ae220`–`0x005ae268` exclusive (**72** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map node allocation |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + ABI sealed; product demangle open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005ae220_StdTree_Buynode_Val12.md`, `reviews/B_aa_005ae220_StdTree_Buynode_Val12.md` (2026-07-29 W24-I) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005ae220`
- `Named_CalleeOf_Named_CalleeOf_Skill_CategoryCooldownMap_Insert_005ae220` (legacy xref scaffold — **narrow/misleading**; unit is shared)
- Role: `_Tree::_Buynode` for **12-byte** values (node size **0x1c**)

## Purpose

Allocate and initialize one red-black tree node: three links, three-dword value copy, color byte, isnil=0. Return pointer or null on `operator_new` failure.

## Signature

```c
StdTreeNode_Val12* __stdcall StdTree_Buynode_Val12(
    StdTreeNode_Val12* left,
    StdTreeNode_Val12* parent,
    StdTreeNode_Val12* right,
    const uint32_t value3[3],
    uint8_t color);
// RET 0x14; EAX = node* | null
```

## Algorithm

1. `node = operator_new(0x1c)`; if null return null.
2. `node->{left,parent,right} = args`.
3. Copy `value3[0..2]` → `node+0x0c`.
4. `node->color = color`; `node->isnil = 0`.
5. Return node.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ae220_FUN_005ae220.md`
- Annotated: `docs/reconstruction/raw/aa_005ae220_FUN_005ae220.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val12.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005ae220.cpp`
- Legacy alias: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Skill_CategoryCooldownMap_Insert_005ae220.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005ae220-00827670-w24i-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `operator_new` only |
| **Callers** | `FUN_0051c1c0` (category-cooldown map insert+rebalance), `FUN_00539210`, `FUN_00567450`, `FUN_00573510`, `FUN_005ae4e0`, `FUN_005e13b0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| `ret 0x14` + 5 stack args | **High** |
| Node layout + isnil=0 | **High** |
| EAX return (not void) | **High** |
| Shared multi-map helper | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Twin larger payload: `FUN_005ae1c0` (`operator_new(0x24)`, Val20)
- Consumer dual: `Skill_CategoryCooldownMap_Insert` / `aa_0051d2f0`
- Header/nil helpers: RbTree empty-header family (Node1c)
