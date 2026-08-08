# Review A (reconstruction fidelity): `aa_004166d0` CVOGMenu_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004166d0` |
| **VA** | `0x004166d0` |
| **Body** | `0x004166d0`–`0x004166ed` inclusive (**30 B** / `0x1E`) |
| **Canonical name** | `CVOGMenu_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004166d0` |
| **Prior scaffold** | `FUN_004166d0` partial trio |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004166d0_CVOGMenu_ScalarDeletingDtor.md` |
| **System** | skills-abilities (partition) / MSVC scalar-deleting — CVOGMenu |
| **Wave** | MEGA-138 OWN |
| **Verdict** | **accept** |

---

## 1. Purpose

**MSVC scalar-deleting destructor (vtbl[0])** for product class **CVOGMenu** (`PTR_FUN_00a72f6c`):

```text
// ECX = this; stack flags; RET 4; returns this*
CVOGMenu_CompleteDtor(this) via FUN_0082d540
if (flags & 1) operator_delete(this)
return this
```

Complete (dualed WQ9K-G) installs `PTR_FUN_00a72f6c`, tears down menu hash via `FUN_0082ce20`, chains `CNDUIDialog_CompleteDtor`. RTTI `.?AVCVOGMenu@@` seals product English — no `_Inferred` suffix.

**Not** the complete body, not a vector-deleting form, not a free-only leaf.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **ECX** | `this` (CVOGMenu*) |
| stack `[esp+4]` after push | `flags` (byte; bit0 tested at `[esp+8]` after ESI push) |
| return | `this*` in EAX; **`RET 4`** |

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra ≡ scaffold CF |
| Bytes | `read_memory` 30 B — `56 8B F1` / CALL complete / TEST bit0 / delete+ADD ESP,4 / `C2 04 00` |
| Body range | `get_function_by_address` `004166d0`–`004166ed` |
| Xrefs | DATA only `0x00a72f6c` → `0x004166d0` |
| Complete | dualed `aa_0082d540` `CVOGMenu_CompleteDtor` |
| Vtbl + RTTI | `read_memory` @ `0x00a72f6c` / `0x00a72f68` / `0x00afe39c` |
| Raw / annotated / clean | named + twin plates |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| ESI=this; CALL `FUN_0082d540` | **Yes** |
| flags&1 → operator_delete + ADD ESP,4 | **Yes** (bytes; decompiler may omit ADD under noreturn) |
| Always return this; RET 4 | **Yes** |
| Invented branches | **None** |
| Decompiler “delete noreturn” | **Ignored** (bytes prove epilogue) |
| Product name from RTTI | **Yes** — `.?AVCVOGMenu@@` |

---

## 5. Gaps

- Vtbl slots [1+] English (shared family; not owned).
- Runtime / bit-exact / differential.
- Hash-field dual residual lives under complete `0082ce20`, not this shell.

None of the gaps threaten CF/ABI/name seal for this unit.

---

## 6. Verdict

**accept** — classic scalar-deleting CF/ABI/vtbl[0]/RTTI product name sealed. Complete callee dualed. Not reject.
