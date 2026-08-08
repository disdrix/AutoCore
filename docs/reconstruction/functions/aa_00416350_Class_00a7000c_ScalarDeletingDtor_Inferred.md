# Function record: Class_00a7000c_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416350` |
| **Canonical name** | `Class_00a7000c_ScalarDeletingDtor_Inferred` (**Inferred** structural) |
| **Ghidra name** | `FUN_00416350` |
| **Address** | `0x00416350` |
| **Body** | `0x00416350`–`0x0041636e` exclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** WQ9I-H — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC scalar-deleting destructor for the class whose primary vtbl is `PTR_FUN_00a7000c`. Always runs the complete dtor (`FUN_00832fa0`), then frees the heap host when `(flags & 1)`. Returns `this` in EAX. Bound as **vtbl[0]** at `0x00a7000c`.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall Class_00a7000c_ScalarDeletingDtor_Inferred(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_00a7000c[0]` @ `0x00a7000c` |
| Callees | `FUN_00832fa0` (complete), `operator_delete` |

## Full body hex

```
568bf1e848cc4100f644240801740956e8bd34070083c4048bc65ec20400
```

## Artifacts

- Raw (+ WQ9I-H append): `docs/reconstruction/raw/aa_00416350_FUN_00416350.md`
- Annotated: `docs/reconstruction/raw/aa_00416350_FUN_00416350.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Class_00a7000c_ScalarDeletingDtor_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00416350.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00416350_Class_00a7000c_ScalarDeletingDtor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00416350_Class_00a7000c_ScalarDeletingDtor_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00416350_FUN_00416350.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| vtbl[0] slot | **High** |
| Complete callee identity | **High** (static) |
| Product MSVC demangle | **Low** |
| Vtbl slots [1+] | **Open** |
