# Function record: CWndVehicle_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004160d0` |
| **Canonical name** | `CWndVehicle_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004160d0` |
| **Address** | `0x004160d0` |
| **Body** | `0x004160d0`–`0x004160ee` exclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CWndVehicle / MSVC scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** WQ9I-F — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC scalar-deleting destructor for the class whose primary vtbl is `PTR_FUN_00a6fbcc`. RTTI seals product name **CWndVehicle** (`.?AVCWndVehicle@@`). Always runs the complete dtor (`FUN_00834520`), then frees the heap host when `(flags & 1)`. Returns `this` in EAX.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall CWndVehicle_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_00a6fbcc[0]` @ `0x00a6fbcc` |
| Callees | `FUN_00834520` (complete), `operator_delete` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004160d0_FUN_004160d0.md`
- Annotated: `docs/reconstruction/raw/aa_004160d0_FUN_004160d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CWndVehicle_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004160d0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004160d0_CWndVehicle_ScalarDeletingDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_004160d0_CWndVehicle_ScalarDeletingDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_004160d0_FUN_004160d0.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| vtbl[0] slot | **High** |
| Product RTTI `CWndVehicle` | **High** |
