# Function record: CMenuChatlog_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_008327f0` |
| **Canonical name** | `CMenuChatlog_CompleteDtor` (RTTI product demangle sealed) |
| **Ghidra name** | `FUN_008327f0` |
| **Address** | `0x008327f0` |
| **Body** | `0x008327f0`–`0x0083282a` (**59 B** / `0x3B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC derived complete dtor — `CMenuChatlog` / `PTR_FUN_00a70524` |
| **Completion status** | **Dual-reviewed** WQ9J-C — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Derived complete destructor for **CMenuChatlog**: install `PTR_FUN_00a70524`, then chain intermediate base complete `FUN_0082d540` (→ `00a72f6c` + `0082ce20` + deep base `00792c20`). Does **not** free `this`. Scalar path is `FUN_004165f0` (WQ9I-J).

## Signature

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor (no operator_delete this)
void __fastcall CMenuChatlog_CompleteDtor(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004165f0` @ `0x004165f3` (scalar-deleting; vtbl[0] of `00a70524`) |
| Callees | `FUN_0082d540` (intermediate base complete) |

## RTTI

| Item | Value |
|---|---|
| COL ptr | dword @ `0x00a70520` → `0x00ab5e54` |
| type_info | `0x00affb04` |
| Mangled | `.?AVCMenuChatlog@@` |
| Demangled | **CMenuChatlog** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008327f0_FUN_008327f0.md`
- Annotated: `docs/reconstruction/raw/aa_008327f0_FUN_008327f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CMenuChatlog_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_008327f0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008327f0_CMenuChatlog_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_008327f0_CMenuChatlog_CompleteDtor.md`
- Scaffold record: `docs/reconstruction/functions/aa_008327f0_FUN_008327f0.md`
- Scalar: `aa_004165f0` Class_00a70524_ScalarDeletingDtor_Inferred (WQ9I-J)

## Confidence

| Claim | Level |
|---|---|
| Product class = CMenuChatlog (RTTI) | **High** |
| Derived vtbl install + base complete chain | **High** |
| ABI SEH + ADD ESP,0x10; RET | **High** |
| Complete vs scalar | **High** (scalar is `004165f0`) |
| Intermediate base field map / dual | **Open** |
| Vtbl slots [1+] | **Open** |
| Runtime | **Open** |
