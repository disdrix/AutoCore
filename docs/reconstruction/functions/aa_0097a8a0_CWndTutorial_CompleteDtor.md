# Function record: CWndTutorial_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0097a8a0` |
| **Canonical name** | `CWndTutorial_CompleteDtor` (RTTI product demangle sealed) |
| **Ghidra name** | `FUN_0097a8a0` |
| **Address** | `0x0097a8a0` |
| **Body** | `0x0097a8a0`–`0x0097a8da` (**59 B** / `0x3B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC derived complete dtor — `CWndTutorial` / `PTR_FUN_00a6f61c` |
| **Completion status** | **Dual-reviewed** WQ9J-C — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Derived complete destructor for **CWndTutorial**: install `PTR_FUN_00a6f61c`, then chain deep UI base complete `FUN_00792c20`. Does **not** free `this`. Scalar path is `FUN_004160b0` (WQ9I-E).

## Signature

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor (no operator_delete this)
void __fastcall CWndTutorial_CompleteDtor(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004160b0` @ `0x004160b3` (scalar-deleting; vtbl[0] of `00a6f61c`) |
| Callees | `FUN_00792c20` (deep UI base complete) |

## RTTI

| Item | Value |
|---|---|
| COL ptr | dword @ `0x00a6f618` → `0x00ab5cec` |
| type_info | `0x00affaa4` |
| Mangled | `.?AVCWndTutorial@@` |
| Demangled | **CWndTutorial** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0097a8a0_FUN_0097a8a0.md`
- Annotated: `docs/reconstruction/raw/aa_0097a8a0_FUN_0097a8a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CWndTutorial_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0097a8a0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0097a8a0_CWndTutorial_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_0097a8a0_CWndTutorial_CompleteDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_0097a8a0_FUN_0097a8a0.md`
- Scalar: `aa_004160b0` Class_00a6f61c_ScalarDeletingDtor (WQ9I-E)

## Confidence

| Claim | Level |
|---|---|
| Product class = CWndTutorial (RTTI) | **High** |
| Derived vtbl install + base complete chain | **High** |
| ABI SEH + ADD ESP,0x10; RET | **High** |
| Complete vs scalar | **High** (scalar is `004160b0`) |
| Deep base field map / dual | **Open** |
| Vtbl slots [1+] | **Open** |
| Runtime | **Open** |
