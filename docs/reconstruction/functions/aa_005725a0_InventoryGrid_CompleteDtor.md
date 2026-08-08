# Function record: InventoryGrid_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005725a0` |
| **Canonical name** | `InventoryGrid_CompleteDtor` |
| **Ghidra name** | `FUN_005725a0` |
| **Address** | `0x005725a0`–`0x0057264d` inclusive (**174 B** / `0xAE`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Classification** | worker |
| **Wave** | MEGA-061 OWN-ONLY dual (2026-08-05) |
| **Verdict** | **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

MSVC **complete-object destructor** for InventoryGrid (vtbl `PTR_FUN_009d3390`, object size **0x68**). Reverse of `InventoryGrid_ctor_Inferred`. Sole code caller is dualed `InventoryGrid_ScalarDeletingDtor` (vtbl[0]). Host free is **not** performed here.

## Signature (sealed)

```c
// ECX = InventoryGrid* this; no stack args; void; bare RET (C3)
void __thiscall InventoryGrid_CompleteDtor(InventoryGrid *self);
```

## Body stages

1. Reinstall `PTR_FUN_009d3390`.
2. `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` (`0x00570f70`).
3. `operator_delete[]` cell array @ `+0x28` (null-safe); zero.
4. Map @ `+0x5c`: `FUN_00573700` erase-all; `operator_delete` sentinel @ `+0x60`; zero head/size.
5. List @ `+0x2c`: vtbl `009d3384` → `FUN_004bc950`; vtbl `009cb334` → `FUN_004bc950`.
6. `DeleteCriticalSection` @ `+0x30`.
7. SEH restore; `RET`.

## Callers / callees

| Role | Target | Status |
|---|---|---|
| Caller | `0x00573910` ScalarDeletingDtor | dualed **accept** |
| Callee | `0x00570f70` ClearItemsAndReEmptyCells | dualed MEGA-090 |
| Callee | `operator_delete[]` `0x0048981c` | CRT |
| Callee | `0x00573700` map erase-range | residual |
| Callee | `operator_delete` `0x00489822` | CRT |
| Callee | `0x004bc950` list drain | residual |
| Callee | IAT `DeleteCriticalSection` | Win32 |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_005725a0_FUN_005725a0.md`
- Annotated: `docs/reconstruction/raw/aa_005725a0_FUN_005725a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/InventoryGrid_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005725a0.cpp`
- FUN record: `docs/reconstruction/functions/aa_005725a0_FUN_005725a0.md`
- Dual A: `docs/reconstruction/reviews/A_aa_005725a0_InventoryGrid_CompleteDtor.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005725a0_InventoryGrid_CompleteDtor.md`
- Report: `docs/agents/task-dual-ab-005725a0-mega-061-report.md`

## Related

| VA | Name | Relation |
|---|---|---|
| `0x00573910` | `InventoryGrid_ScalarDeletingDtor` | vtbl[0] wrapper |
| `0x00572650` | `InventoryGrid_ctor_Inferred` | reverse |
| `0x00570f70` | `ClearItemsAndReEmptyCells_Inferred` | stage 1 |
| `0x00570720` | `AllocateCellArray_Inferred` | clear re-empty |

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor role / ABI / full CF | **High** |
| InventoryGrid family / layout | **High** |
| Product demangle | Open (naming-only) |
| Runtime Confirmed | Open |
