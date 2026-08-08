# Function record: CVOGMenu_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004166d0` |
| **Canonical name** | `CVOGMenu_ScalarDeletingDtor` (RTTI product demangle sealed) |
| **Ghidra name** | `FUN_004166d0` |
| **Address** | `0x004166d0` |
| **Body** | `0x004166d0`–`0x004166ed` inclusive (**30 B** / `0x1E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities (partition) / UI menu intermediate over CNDUIDialog |
| **Completion status** | **Dual-reviewed** MEGA-138 — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

MSVC **scalar-deleting destructor** for product class **CVOGMenu** (vtbl[0] of `PTR_FUN_00a72f6c`):

1. Always call complete dtor `CVOGMenu_CompleteDtor` / `FUN_0082d540` (install primary vtbl, menu hash teardown at dword `[0x14d]`, chain `CNDUIDialog_CompleteDtor`).
2. If `(flags & 1)` → `operator_delete(this)`.
3. Return `this`.

Does **not** implement teardown itself — that lives in the complete path. Distinct from complete (no free, no flags formal).

## Signature

```c
// ECX = this; stack uint8_t flags; RET 4; returns this*
void* __thiscall CVOGMenu_ScalarDeletingDtor(void* self, uint8_t flags);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (code) | none (virtual via vtbl) |
| Xrefs | DATA only — `PTR_FUN_00a72f6c[0]` @ `0x00a72f6c` |
| Callees | `CVOGMenu_CompleteDtor` (`0x0082d540`); `operator_delete` (`0x00489822`) |

## RTTI

| Item | Value |
|---|---|
| COL ptr | dword @ `0x00a72f68` → `0x00ab6214` |
| type_info | `0x00afe39c` |
| Mangled | `.?AVCVOGMenu@@` |
| Demangled | **CVOGMenu** |

## Vtbl (first slots)

| Slot | Address | Role |
|---|---|---|
| [0] | `0x004166d0` | this scalar-deleting dtor |
| [1] | `0x00790cc0` | shared (open) |
| [2] | `0x007a7de0` | shared (open) |
| [3] | `0x007567e0` | shared (open) |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_004166d0_FUN_004166d0.md`
- Annotated: `docs/reconstruction/raw/aa_004166d0_FUN_004166d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGMenu_ScalarDeletingDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004166d0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004166d0_CVOGMenu_ScalarDeletingDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_004166d0_CVOGMenu_ScalarDeletingDtor.md`
- Scaffold: `docs/reconstruction/functions/aa_004166d0_FUN_004166d0.md`
- Complete: `aa_0082d540` `CVOGMenu_CompleteDtor` (WQ9K-G dualed)

## Confidence

| Claim | Level |
|---|---|
| Product class = CVOGMenu (RTTI) | **High** |
| Scalar-deleting CF / flags bit0 | **High** |
| ABI ECX this / RET 4 / return this | **High** |
| Complete callee = `0082d540` | **High** |
| Vtbl slots [1+] English | **Open** |
| Runtime | **Open** |
