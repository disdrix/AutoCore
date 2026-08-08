# Function record: InventoryGrid_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573910` |
| **Canonical name** | `InventoryGrid_ScalarDeletingDtor` (**Inferred** structural) |
| **Ghidra name** | `FUN_00573910` |
| **Address** | `0x00573910` |
| **Body** | `0x00573910`–`0x0057392d` exclusive (**29 B** / `0x1D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer / InventoryGrid |
| **Completion status** | **Dual-reviewed** WQ8R-E — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC scalar-deleting destructor for the InventoryGrid class whose primary vtbl is `PTR_FUN_009d3390`. Always runs the complete dtor (`FUN_005725a0`), then frees the heap host when `(flags & 1)`. Returns `this` in EAX.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall InventoryGrid_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_009d3390[0]` @ `0x009d3390`; virtual destroy from cargo path `Vehicle_CreateCargoInventoryFromPageCount` (`vtbl[0](1)` on vehicle+`0x2b0`) |
| Callees | `FUN_005725a0` (complete), `operator_delete` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00573910_FUN_00573910.md`
- Annotated: `docs/reconstruction/raw/aa_00573910_FUN_00573910.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00573910.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00573910_InventoryGrid_ScalarDeletingDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_00573910_InventoryGrid_ScalarDeletingDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_00573910_FUN_00573910.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| vtbl[0] slot | **High** |
| InventoryGrid family (ctor + cargo parent) | **High** |
| Product MSVC demangle | **Low** |
