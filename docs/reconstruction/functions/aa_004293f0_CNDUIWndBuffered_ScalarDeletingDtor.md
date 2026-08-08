# Function record: CNDUIWndBuffered_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004293f0` |
| **Canonical name** | `CNDUIWndBuffered_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004293f0` |
| **Address** | `0x004293f0` |
| **Body** | `0x004293f0`–`0x0042940d` exclusive (**29 B** / `0x1D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / CNDUIWndBuffered / MSVC scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** R10-009 — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Parent dual** | `0x0078ca80` `CNDUIWndBuffered_CompleteDtor` |

## Purpose

MSVC scalar-deleting destructor for `CNDUIWndBuffered` (RTTI-sealed; primary vtbl `PTR_FUN_00a99f74`). Always runs the complete dtor (`CNDUIWndBuffered_CompleteDtor` / `FUN_0078ca80`), then frees the heap host when `(flags & 1)`. Returns `this` in EAX.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall CNDUIWndBuffered_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_00a99f74[0]` @ `0x00a99f74` |
| Callees | `CNDUIWndBuffered_CompleteDtor` (`FUN_0078ca80`), `operator_delete` @ `0x00489822` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004293f0_FUN_004293f0.md`
- Annotated: `docs/reconstruction/raw/aa_004293f0_FUN_004293f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004293f0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004293f0_CNDUIWndBuffered_ScalarDeletingDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_004293f0_CNDUIWndBuffered_ScalarDeletingDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_004293f0_FUN_004293f0.md`
- Report: `docs/agents/task-dual-ab-004293f0-r10-report.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| vtbl[0] slot | **High** |
| Product class (CNDUIWndBuffered) | **High** (parent RTTI dual) |
