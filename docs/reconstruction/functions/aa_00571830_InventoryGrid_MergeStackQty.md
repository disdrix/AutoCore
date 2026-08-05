# Function record: InventoryGrid_MergeStackQty

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571830` |
| **Canonical name** | `InventoryGrid_MergeStackQty` |
| **Address** | `0x00571830` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual reviewed** (A + B + residual 2026-07-29); accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Status |
|------|--------|
| `FUN_00571830` | Ghidra default |
| `InventoryGrid_AddQtyByCoid` | Acceptable alias |
| `Named_VOG_DEBUG_STOP_00571830` | **Rejected** — miss-path string only |

## Purpose

Merge a quantity **delta** onto an existing inventory-grid stack found by **instance COID** (`item+0x160/+0x164`). Sets qty via item vtbl Get/Set (`+0x25C` / `+0x260`), dirties item (and optional owner at `grid+0x24`) with flag `0x20000`, stamps grid dirty byte `@+0x21`. Returns 1 on hit, 0 on miss. **Does not** place, stamp cells, or clamp max stack.

## Signature (byte-sealed)

```c
// __thiscall, callee cleans 0x0C
uint8_t InventoryGrid_MergeStackQty(
    InventoryGrid* this,  // ECX
    int qtyDelta,         // stack0
    int coidLo,           // stack1
    int coidHi);          // stack2
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00571830_FUN_00571830.md`
- Annotated: `docs/reconstruction/raw/aa_00571830_FUN_00571830.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_MergeStackQty.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00571830.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00571830_InventoryGrid_MergeStackQty.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00571830_InventoryGrid_MergeStackQty.md`
- Residual: `docs/reconstruction/reviews/a_00571830.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_00571830_FUN_00571830.md` (superseded by this)

## Callers / callees

**Callees:** `InventoryGrid_FindItemByCoid` (`0x00571010`), `FUN_00512670` (object dirty `\|0x20000`), `FUN_007a4480` (debug log; called with enable=0).

**Callers (sample):** `Client_RecvInventoryAddItem`, `Client_SendInventoryAddItem`, `FUN_00945540` (loot place merge), `FUN_008012f0`, `FUN_00587c00`, `FUN_0052aae0`.

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI from bytes | **High / Sealed** |
| Role = stack qty merge by COID | **High / Sealed** |
| No place / no capacity in body | **High / Sealed** |
| Parameter semantic names | **High** (caller + bytes) |
| Product symbol / dirty-flag English names | **Open / Probable** |
| Runtime / bit-exact | **Open** |
