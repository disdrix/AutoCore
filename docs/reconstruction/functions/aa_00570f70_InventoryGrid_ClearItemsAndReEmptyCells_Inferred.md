# Function record (named): InventoryGrid_ClearItemsAndReEmptyCells_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570f70` |
| **Semantic name** | `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` |
| **Ghidra name** | `FUN_00570f70` |
| **Address** | `0x00570f70`–`0x0057100d` inclusive (**158 B** / `0x9E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Partition** | MEGA-090; soft hint `InventoryGrid_FreeCellArray` |
| **Naming basis** | Item-walk teardown + `List_RemoveAll` + dualed `AllocateCellArray` re-empty; not free-only |
| **Status** | Dual sealed MEGA-090 (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias / superseded

- Scaffold: `FUN_00570f70` (2026-07-23)
- Partition hint: `InventoryGrid_FreeCellArray` — **rejected as sole name** (body re-allocates empty cells; does full item teardown first)
- No `Named_CalleeOf_*` scaffold present for this VA

## Purpose

Full **clear** of an `InventoryGrid`:

1. `List_TraversalLock` on embedded list at **`grid+0x2c`**.
2. Walk payloads via `LockedList_TryAdvanceIterator_Inferred`; for each item:
   - `vtbl+0x158(0)` detach/unbind
   - if `item+0xa4 != 0` → `FUN_004d4790` (queue delete)
   - else → scalar-deleting dtor `(*vtbl)(1)`
3. Inline TraversalUnlock (`list+0x28` / `LeaveCS(list+4)`).
4. `List_RemoveAll` residual list nodes (requires unlock — RemoveAll throws if locked).
5. `InventoryGrid_AllocateCellArray_Inferred` — free old cell buffer, alloc empty `-1` fill.

Does **not** destroy the grid object, delete the final cell buffer (parent complete-dtor does), or place items.

## Signature

```c
// __fastcall / thiscall-shaped; ECX=InventoryGrid*; void; bare RET
void __fastcall InventoryGrid_ClearItemsAndReEmptyCells_Inferred(InventoryGrid *grid);
```

## Layouts

### InventoryGrid (partial — this unit)

| Off | Field | Conf |
|----:|-------|------|
| `+0x28` | cell array* (rewritten by Allocate) | **High** |
| `+0x2c` | embedded List host | **High** |
| `+0x30` | List CS | **High** |
| `+0x54` | List TraversalLock flag | **High** |

### List host (shared)

| Off | Field | Conf |
|----:|-------|------|
| `+0x04` | `CRITICAL_SECTION` | **High** |
| `+0x1c` | head | **High** (family) |
| `+0x28` | TraversalLock flag | **High** |

## Callers

| Caller | Site | Role |
|---|---|---|
| `FUN_005725a0` | `0x005725cf` | InventoryGrid complete-dtor: clear then `operator_delete(+0x28)` |
| `FUN_005876c0` | `0x005876ca` | if `*(host+0x35c)` clear that grid |
| `FUN_00884720` | `0x0088473a` | clear cargo grid at `*(host+0x510)+0xce0` |

## Twin / family

| Unit | VA | Diff |
|---|---|---|
| Thin re-empty | `0x00570f50` | RemoveAll + Allocate only (no item walk) |
| Allocate | `0x00570720` | cell buffer only (dualed) |
| Complete dtor | `0x005725a0` | parent; calls this then frees cells |
| TraversalUnlock leaf | `0x0040c700` | same unlock CF inlined here |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00570f70_FUN_00570f70.md`
- Annotated: `docs/reconstruction/raw/aa_00570f70_FUN_00570f70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_ClearItemsAndReEmptyCells_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00570f70.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00570f70_FUN_00570f70.md`
- Reviews: `A_aa_00570f70_…`, `B_aa_00570f70_…`
- Report: `docs/agents/task-dual-ab-00570f70-mega-090-report.md`

## Confidence

| Claim | Level |
|---|---|
| ABI ECX=grid, bare RET | **High** |
| list@+0x2c; lock/unlock/RemoveAll/Allocate order | **High** |
| item+0xa4 gate + vtbl+0x158 | **High** (bytes) |
| Product English for detach / gate | **Open** |
| Retail symbol | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
