# Function record: CVOGDialog_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004130d0` |
| **Canonical name** | `CVOGDialog_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004130d0` |
| **Address** | `0x004130d0` |
| **Body** | `0x004130d0`–`0x004130ee` exclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / CVOGDialog / MSVC scalar-deleting destructor |
| **Completion status** | **Dual-reviewed** R12-010 — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Terminal** | **false** (no runtime Confirmed) |

## Purpose

MSVC scalar-deleting destructor for the class whose primary vtbl is `PTR_FUN_00a58c6c`. RTTI seals product name **CVOGDialog** (`.?AVCVOGDialog@@`, parent dual R11-030). Always runs the complete dtor (`FUN_0087b7d0`), then frees the heap host when `(flags & 1)`. Returns `this` in EAX.

## Signature

```c
// ECX = this; stack flags; RET 4; returns this*
void* __thiscall CVOGDialog_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | DATA only — `PTR_FUN_00a58c6c[0]` @ `0x00a58c6c` |
| Callees | `FUN_0087b7d0` (complete), `operator_delete` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004130d0_FUN_004130d0.md`
- Annotated: `docs/reconstruction/raw/aa_004130d0_FUN_004130d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGDialog_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004130d0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004130d0_CVOGDialog_ScalarDeletingDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_004130d0_CVOGDialog_ScalarDeletingDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_004130d0_FUN_004130d0.md`
- Report: `docs/agents/task-dual-ab-004130d0-r12-report.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (bytes) | **High** |
| ABI ECX + RET 4 + return this | **High** |
| flags bit0 → operator_delete | **High** |
| vtbl[0] slot | **High** |
| Product RTTI `CVOGDialog` | **High** (parent dual seal + this vtbl[0]) |
| Complete dtor internals | Open (not owned) |
