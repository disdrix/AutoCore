# Function record: InventoryGrid_RemoveItemByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571d80` |
| **Canonical name** | `InventoryGrid_RemoveItemByCoid` |
| **Ghidra name** | `FUN_00571d80` |
| **Address** | `0x00571d80` |
| **Body range** | `0x00571d80` – `0x00571da6` (39 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual A/B sealed** — accept (thin wrapper; ABI + rel32 Confirmed) |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept** (`A_` / `B_`) |
| **Last reviewed** | `2026-08-04` (WQ8R-D) |

## Alias

- `FUN_00571d80`
- Prior scaffold: `Named_CalleeOf_Client_RecvInventoryUseItemResponse_00571d80`

## Purpose

One-shot **find-by-COID then remove** on a client inventory grid:

1. `InventoryGrid_FindItemByCoid(this, coidLo, coidHi)` → first list item with matching `+0x160/+0x164`.
2. `InventoryGrid_RemoveItem(this, item, removeQty=**1**, forceFull)` — peel/unstamp/detach per sealed Remove body.
3. Return Remove's `item*` / null.

## Signature (byte-sealed 2026-08-04)

```c
// MSVC __thiscall; RET 0x0C
ItemObject* InventoryGrid_RemoveItemByCoid(
    InventoryGrid* this,   // ECX
    int32_t        coidLo, // stack0
    int32_t        coidHi, // stack1
    int            forceFull // stack2 (passed to RemoveItem)
);
```

## Behavioral summary

| Path | Result |
|------|--------|
| No matching COID | Find → null → Remove null-gate → **null** |
| Match + peel remain & force=0 | Remove peel path → **null** (cells stay) |
| Match + full remove | Remove full path → **item\*** |

`removeQty` is **always 1** (imm `push 1`); only forceFull is caller-controlled among remove args.

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / size | **Confirmed** |
| Signature / `RET 0x0C` | **Confirmed** |
| Rel32 Find + Remove | **Confirmed** |
| removeQty literal 1 | **Confirmed** |
| Return = Remove EAX | **High** |
| Naming | **High** (composition of dualed callees) |
| Runtime / bit-exact | Open |

## Open questions

- PDB English name
- Full per-caller forceFull product meaning
- Runtime confirmation of peel vs full across sell/use paths

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00571d80_FUN_00571d80.md` (+ WQ8R-D append)
- Annotated: `docs/reconstruction/raw/aa_00571d80_FUN_00571d80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_RemoveItemByCoid.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00571d80.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00571d80_InventoryGrid_RemoveItemByCoid.md`
- Review B: `docs/reconstruction/reviews/B_aa_00571d80_InventoryGrid_RemoveItemByCoid.md`
- Scaffold record: `docs/reconstruction/functions/aa_00571d80_FUN_00571d80.md`

## Callers / callees

**Callees:** `InventoryGrid_FindItemByCoid` `0x00571010`; `InventoryGrid_RemoveItem` `0x00571b80`.

**Callers:** `Client_RecvInventoryUseItemResponse` `0x00810280`; `FUN_00810170`; `FUN_00810670`; `FUN_004f8e00`.
