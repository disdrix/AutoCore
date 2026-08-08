# Function record: CWidgetRotateVehicle_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004160f0` |
| **Canonical name** | `CWidgetRotateVehicle_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004160f0` |
| **Address** | `0x004160f0` |
| **Body** | `0x004160f0`–`0x0041610f` exclusive (**31 B** / `0x1F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CWidgetRotateVehicle / MSVC scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** WQ9I-F — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC scalar-deleting destructor for **CWidgetRotateVehicle**. Always runs complete dtor `FUN_00416110` (installs base `PTR_LAB_00a9bbe8`), then frees heap host when `(flags & 1)`. Returns `this` in EAX. Virtual-dtor DATA slot is `PTR_LAB_00a6ff94[+0x0C]` (base virtual methods occupy earlier slots).

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall CWidgetRotateVehicle_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — dword @ `0x00a6ffa0` |
| Callees | `FUN_00416110` (complete), `operator_delete` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004160f0_FUN_004160f0.md`
- Annotated: `docs/reconstruction/raw/aa_004160f0_FUN_004160f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CWidgetRotateVehicle_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004160f0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004160f0_CWidgetRotateVehicle_ScalarDeletingDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_004160f0_CWidgetRotateVehicle_ScalarDeletingDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_004160f0_FUN_004160f0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| Product RTTI `CWidgetRotateVehicle` | **High** |
| vtbl slot +0x0C (not [0]) | **High** |
