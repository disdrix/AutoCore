# Function record: CNDUIDialog_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792c20` |
| **Canonical name** | `CNDUIDialog_CompleteDtor` (RTTI product demangle sealed) |
| **Ghidra name** | `FUN_00792c20` |
| **Address** | `0x00792c20` |
| **Body (true)** | `0x00792c20`–`0x00792d12` (**243 B** / `0xF3`) |
| **Body (Ghidra DB)** | Truncated at `00792ceb` — false noreturn on member `operator_delete` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC shared UI base complete dtor — `CNDUIDialog` / `PTR_FUN_00a98f44` |
| **Completion status** | **Dual-reviewed** WQ9K-G — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Shared complete destructor for product class **CNDUIDialog** (NDUI dialog/panel base used by menus, tutorial windows, inventory grids, etc.):

1. Install `PTR_FUN_00a98f44` at `*this`.
2. `FUN_007917c0` — traverse/release child hash at `+0x4c0` (`[0x130]`).
3. Null-safe scalar-delete owned pointers at `+0x4c0`, `+0x4c8`…`+0x4d8` (skip `+0x4c4`).
4. `FUN_00415e90` list-shell clear with ESI = `this+0x4dc`.
5. `operator_delete(*(this+0x4e0))` then zero — **member free only; returns**.
6. Chain deeper window complete `FUN_007b5be0` (EH −1).

Does **not** free host `this`. Scalar path is `FUN_004280d0` (vtbl[0] of `00a98f44`). Peer ctor `FUN_00792d20` (prior dual named `NDUIContainerPanel_Ctor_Inferred` — product rename residual toward **CNDUIDialog**).

## Signature

```c
// ECX = this; SEH; ADD ESP,0x10; RET; void; complete dtor (no operator_delete this)
void __fastcall CNDUIDialog_CompleteDtor(void* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | Shared: `FUN_0082d540` (CVOGMenu), `FUN_0097a8a0` (CWndTutorial), many NDUI completes; Unwind |
| Callees | `FUN_007917c0`, `FUN_00415e90`, `operator_delete` (member @ +0x4e0), `FUN_007b5be0` |

## RTTI

| Item | Value |
|---|---|
| COL ptr | dword @ `0x00a98f40` → `0x00ab7e6c` |
| type_info | `0x00afe1c8` |
| Mangled | `.?AVCNDUIDialog@@` |
| Demangled | **CNDUIDialog** |

## Vtbl (first slots)

| Slot | Address | Role |
|---|---|---|
| [0] | `0x004280d0` | scalar-deleting dtor |
| [1] | `0x00790cc0` | shared with CVOGMenu family |
| [2] | `0x007a7de0` | shared |
| [3] | `0x007567e0` | shared |

## Owned offsets (sealed CF)

| Byte off | Dword idx | Action |
|---|---|---|
| `+0x4c0` | `[0x130]` | scalar-delete after `007917c0` |
| `+0x4c4` | `[0x131]` | **skipped** (not freed here) |
| `+0x4c8`…`+0x4d8` | `[0x132]`…`[0x136]` | scalar-delete each |
| `+0x4dc` | list shell | `FUN_00415e90` (ESI) |
| `+0x4e0` | `[0x138]` | `operator_delete` member then zero |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00792c20_FUN_00792c20.md`
- Annotated: `docs/reconstruction/raw/aa_00792c20_FUN_00792c20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDUIDialog_CompleteDtor.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00792c20.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00792c20_CNDUIDialog_CompleteDtor.md`
- Review B: `docs/reconstruction/reviews/B_aa_00792c20_CNDUIDialog_CompleteDtor.md`
- Scaffold: `docs/reconstruction/functions/aa_00792c20_FUN_00792c20.md`
- Intermediate caller: `aa_0082d540` CVOGMenu_CompleteDtor (WQ9K-G)
- Peer ctor: `aa_00792d20` (prior `NDUIContainerPanel_Ctor_Inferred`)

## Confidence

| Claim | Level |
|---|---|
| Product class = CNDUIDialog (RTTI) | **High** |
| Fat complete CF + offset map + base chain | **High** (bytes) |
| Decompiler tail incomplete / Ghidra body truncated | **High** |
| Complete vs scalar | **High** (scalar is `004280d0`) |
| Owned-slot English roles | **Open** |
| Deep base `007b5be0` dual | **Open** |
| Runtime | **Open** |
