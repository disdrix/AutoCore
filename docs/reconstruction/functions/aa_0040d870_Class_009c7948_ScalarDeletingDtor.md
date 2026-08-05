# Function record: Class_009c7948_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d870` |
| **Canonical name** | `Class_009c7948_ScalarDeletingDtor` (**Inferred** structural) |
| **Ghidra name** | `FUN_0040d870` |
| **Address** | `0x0040d870` |
| **Body** | `0x0040d870`–`0x0040d88e` exclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** W33-A — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC scalar-deleting destructor for the class whose primary vtbl is `PTR_FUN_009c7948`. Always runs the derived complete dtor (`Class_009c7948_CompleteDtor` / `FUN_0040d890`), then frees the heap host when `(flags & 1)`. Returns `this` in EAX. Peer of base-family scalar `Class_009c7938_ScalarDeletingDtor` @ `0x0040d590`.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall Class_009c7948_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_009c7948[0]` @ `0x009c7948` |
| Callees | `FUN_0040d890` (complete), `operator_delete` |

## Artifacts

- Raw (+ W33-A append): `docs/reconstruction/raw/aa_0040d870_FUN_0040d870.md`
- Annotated: `docs/reconstruction/raw/aa_0040d870_FUN_0040d870.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Class_009c7948_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0040d870.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040d870_Class_009c7948_ScalarDeletingDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040d870_Class_009c7948_ScalarDeletingDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_0040d870_FUN_0040d870.md`
- Scratch: `docs/reconstruction/tmp/a_0040d870.md`
- Complete peer: `docs/reconstruction/functions/aa_0040d890_Class_009c7948_CompleteDtor.md` (W32-C)

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| vtbl[0] slot | **High** |
| Complete callee identity | **High** (W32-C) |
| Product MSVC demangle | **Low** |
| Vtbl slots [1]/[2] | **Open** |
