# Function record: Class_009c7938_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d590` |
| **Canonical name** | `Class_009c7938_ScalarDeletingDtor` (**Inferred** structural) |
| **Ghidra name** | `FUN_0040d590` |
| **Address** | `0x0040d590` |
| **Body** | `0x0040d590`–`0x0040d5ad` exclusive (**29 B** / `0x1D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** W31-E — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC scalar-deleting destructor for the class whose primary vtbl is `PTR_FUN_009c7938`. Always runs the complete dtor (`FUN_0040d820`), then frees the heap host when `(flags & 1)`. Returns `this` in EAX.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall Class_009c7938_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_009c7938[0]` @ `0x009c7938` |
| Callees | `FUN_0040d820` (complete), `operator_delete` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040d590_FUN_0040d590.md`
- Annotated: `docs/reconstruction/raw/aa_0040d590_FUN_0040d590.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Class_009c7938_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0040d590.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d590_Class_009c7938_ScalarDeletingDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d590_Class_009c7938_ScalarDeletingDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_0040d590_FUN_0040d590.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| vtbl[0] slot | **High** |
| Product MSVC demangle | **Low** |
