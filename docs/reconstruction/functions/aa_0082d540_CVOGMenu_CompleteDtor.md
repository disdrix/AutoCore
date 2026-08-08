# Function record: CVOGMenu_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082d540` |
| **Canonical name** | `CVOGMenu_CompleteDtor` (RTTI product demangle sealed) |
| **Ghidra name** | `FUN_0082d540` |
| **Address** | `0x0082d540` |
| **Body** | `0x0082d540`–`0x0082d58e` (**79 B** / `0x4F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC intermediate complete dtor — `CVOGMenu` / `PTR_FUN_00a72f6c` |
| **Completion status** | **Dual-reviewed** WQ9K-G — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Intermediate complete destructor for product class **CVOGMenu** (menu layer between derived menus like **CMenuChatlog** and shared dialog base **CNDUIDialog**):

1. Install `PTR_FUN_00a72f6c` at `*this`.
2. `FUN_0082ce20` — owned hash/map teardown at dword `[0x14d]` (EH state 0).
3. Chain `FUN_00792c20` / `CNDUIDialog_CompleteDtor` (EH state −1).

Does **not** free `this`. Scalar path is `FUN_004166d0` (vtbl[0] of `00a72f6c`).

## Signature

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor (no operator_delete this)
void __fastcall CVOGMenu_CompleteDtor(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_004166d0` @ scalar; `FUN_008327f0` CMenuChatlog complete; other CVOGMenu-derived completes; SEH Unwind |
| Callees | `FUN_0082ce20` (menu hash); `FUN_00792c20` (CNDUIDialog complete) |

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
| [0] | `0x004166d0` | scalar-deleting dtor |
| [1] | `0x00790cc0` | shared (same family as CNDUIDialog) |
| [2] | `0x007a7de0` | shared |
| [3] | `0x007567e0` | shared |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0082d540_FUN_0082d540.md`
- Annotated: `docs/reconstruction/raw/aa_0082d540_FUN_0082d540.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGMenu_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0082d540.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0082d540_CVOGMenu_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_0082d540_CVOGMenu_CompleteDtor.md`
- Scaffold: `docs/reconstruction/functions/aa_0082d540_FUN_0082d540.md`
- Derived complete: `aa_008327f0` CMenuChatlog_CompleteDtor (WQ9J-C)
- Base complete: `aa_00792c20` CNDUIDialog_CompleteDtor (WQ9K-G)

## Confidence

| Claim | Level |
|---|---|
| Product class = CVOGMenu (RTTI) | **High** |
| Intermediate vtbl install + hash + CNDUIDialog chain | **High** |
| ABI SEH + ADD ESP,0x10; RET | **High** |
| Complete vs scalar | **High** (scalar is `004166d0`) |
| Hash field map / dual of `0082ce20` | **Open** |
| Vtbl slots [1+] English | **Open** |
| Runtime | **Open** |
