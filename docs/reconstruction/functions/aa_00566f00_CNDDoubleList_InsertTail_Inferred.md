# Function record: CNDDoubleList_InsertTail_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00566f00` |
| **Canonical name** | `CNDDoubleList_InsertTail_Inferred` |
| **Address** | `0x00566f00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` (primary consumer) + generic CNDDoubleList utility |
| **Completion status** | **Dual A/B present** — accept-with-gaps; CF + layout byte-sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Review date** | `2026-07-29` |

## Alias / prior names

| Name | Status |
|------|--------|
| `FUN_00566f00` | Ghidra scaffold |
| `Named_VOG_DEBUG_STOP_00566f00` | **Rejected** — assert string only, not product role |
| `CNDDoubleList_InsertTail_Inferred` | **Canonical** (`_Inferred` — no PDB method string) |

## Purpose

Append a payload pointer as the new **tail** of a CS-protected doubly-linked list matching the CNDDoubleList layout (head `+0x1c`, tail `+0x20`, count `+0x24`, traversal lock `+0x28`, CS `+4`). Inventory place uses the embedded list at **`InventoryGrid+0x2c`** with the item pointer as payload.

## Signature

```c
// __thiscall, RET 4
uint32_t __thiscall CNDDoubleList_InsertTail_Inferred(
    void* list,      // ECX — CNDDoubleList-shaped host
    void* payload);  // stack0 — e.g. ItemObject* from Place
// Success: returns 0. Locked or OOM: throws (0x80070005 / 0x8007000e).
```

## Layout (sealed)

| Offset | Field |
|--------|--------|
| `list+0x00` | vtbl (`+4` = allocate node) |
| `list+0x04` | `CRITICAL_SECTION` |
| `list+0x1c` | head node* |
| `list+0x20` | tail node* |
| `list+0x24` | count |
| `list+0x28` | traversal-lock flag (byte) |
| `node+0x04` | payload* |
| `node+0x08` | next* |
| `node+0x0c` | prev* |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00566f00_FUN_00566f00.md`
- Annotated: `docs/reconstruction/raw/aa_00566f00_FUN_00566f00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDDoubleList_InsertTail_Inferred.cpp`
- Prior scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00566f00.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00566f00_CNDDoubleList_InsertTail_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00566f00_CNDDoubleList_InsertTail_Inferred.md`
- Residual: `docs/reconstruction/reviews/a_00566f00.md`
- Prior function record: `docs/reconstruction/functions/aa_00566f00_FUN_00566f00.md` (superseded by this file)

## Callers / callees

**Callers (Ghidra):** `0x00571620` PlaceItemFootprint; `0x00572730`; `0x00564f60` CreateCreature; `0x00564290` CreateTemplateVehicle; `0x00563a30`; `0x00563a70`.

**Callees:** `EnterCriticalSection` / `LeaveCriticalSection`; list `vtbl+4` (allocate); `FUN_007a4480` (debug); `_CxxThrowException`.

## Confidence

| Claim | Level |
|---|---|
| Control flow + append semantics | **Confirmed** (bytes) |
| List / node offsets | **Confirmed** |
| Place `this = grid+0x2c` | **Confirmed** |
| Product method name | **Open** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
