# Function record: CNDUIDialog_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004280d0` |
| **Canonical name** | `CNDUIDialog_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004280d0` |
| **Address** | `0x004280d0` |
| **Body** | `0x004280d0`–`0x004280ee` exclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | CNDUIDialog / MSVC scalar-deleting destructor (partition: skills-abilities) |
| **Completion status** | **Dual-reviewed** MEGA-140 — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC scalar-deleting destructor for the class whose primary vtbl is `PTR_FUN_00a98f44`. RTTI seals product name **CNDUIDialog** (`.?AVCNDUIDialog@@`). Always runs the complete dtor (`FUN_00792c20` / `CNDUIDialog_CompleteDtor`), then frees the heap host when `(flags & 1)`. Returns `this` in EAX.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall CNDUIDialog_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_00a98f44[0]` @ `0x00a98f44` |
| Callees | `FUN_00792c20` (complete), `operator_delete` @ `0x00489822` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004280d0_FUN_004280d0.md`
- Annotated: `docs/reconstruction/raw/aa_004280d0_FUN_004280d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIDialog_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004280d0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004280d0_CNDUIDialog_ScalarDeletingDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_004280d0_CNDUIDialog_ScalarDeletingDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_004280d0_FUN_004280d0.md`
- Parent complete: `docs/reconstruction/reconstructed-exact/CNDUIDialog_CompleteDtor.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| vtbl[0] slot | **High** |
| Product RTTI `CNDUIDialog` | **High** |
