# Function record: InventoryGrid_ContainsItem

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571b60` |
| **Canonical name** | `InventoryGrid_ContainsItem` |
| **Ghidra name** | `FUN_00571b60` |
| **Address** | `0x00571b60` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **accept-with-gaps** — dual A/B 2026-07-29; body byte-sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- `FUN_00571b60`
- Partition-map role: “Occupancy check before place” (call-site usage with pos vfuncs; body is list membership)
- Prior scaffold: `Named_CalleeOf_Client_RecvInventoryDropResponse_00571b60`

## Purpose

Return whether `item` is already present in the inventory grid’s embedded item list at `grid+0x2c` (`FUN_00415c00`). Null item → false. Does not inspect cell COIDs or footprints.

## Signature (byte-sealed)

```c
// MSVC __thiscall; RET 4
uint8_t InventoryGrid_ContainsItem(InventoryGrid* this /*ECX*/, void* item /*stack*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00571b60_FUN_00571b60.md`
- Annotated: `docs/reconstruction/raw/aa_00571b60_FUN_00571b60.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_ContainsItem.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00571b60_InventoryGrid_ContainsItem.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00571b60_InventoryGrid_ContainsItem.md`
- Residual: `docs/reconstruction/reviews/a_00571b60.md`
- Legacy scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00571b60.cpp` (superseded)

## Callers / callees

**Callees:** `FUN_00415c00` (tail) — list contains with TraversalLock.

**Callers (Ghidra xref):**  
`Client_RecvInventoryDropResponse` (`0x00813730`), `FUN_0080d570`, `FUN_0080d930`, `FUN_00810670`, `FUN_0084b770`, `FUN_008c03c0`, `FUN_0093d110`, `FUN_009440e0`, `FUN_00944d50`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from bytes | **Confirmed** |
| ABI thiscall + RET 4 | **Confirmed** |
| List base `+0x2c` | **Confirmed** |
| Semantic “contains item*” | **High** |
| Parameter retail names | Probable |
| Runtime / bit-exact | Open |
