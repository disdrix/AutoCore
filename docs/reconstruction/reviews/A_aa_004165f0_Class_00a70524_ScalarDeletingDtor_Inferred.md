# Review A (reconstruction fidelity): `aa_004165f0` Class_00a70524_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004165f0` |
| **VA** | `0x004165f0` |
| **Canonical name** | `Class_00a70524_ScalarDeletingDtor_Inferred` |
| **Ghidra name** | `FUN_004165f0` |
| **Prior scaffold** | `FUN_004165f0` partial trio |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004165f0_Class_00a70524_ScalarDeletingDtor_Inferred.md` |
| **System** | MSVC scalar-deleting destructor / `PTR_FUN_00a70524` |
| **Wave** | WQ9I-J OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**MSVC scalar-deleting destructor (vtbl[0])** for class with primary vtbl `PTR_FUN_00a70524`:

```text
// ECX = this; stack flags; RET 4; returns this*
complete_dtor(this) via FUN_008327f0
if (flags & 1) operator_delete(this)
return this
```

Complete installs `PTR_FUN_00a70524` then chains base `FUN_0082d540`. Peer ctor `FUN_00832830` (not owned) uses same vtbl + `"i_m_chatlog.xml"`.

**Not** the neighbor `00416590` shell ctor.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| **ECX** | `this` |
| stack `[esp+4]` | `flags` (byte; bit0 tested) |
| return | `this*` in EAX; **`RET 4`** |

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra ≡ scaffold CF |
| Bytes | `read_memory` 30 B — `56 8B F1` / CALL complete / TEST bit0 / delete / `C2 04 00` |
| Xrefs | DATA only `0x00a70524` → `0x004165f0` |
| Complete | live decompile `FUN_008327f0` |
| Vtbl | `read_memory` @ `0x00a70524` |
| Raw / annotated / clean | named + twin plates |

**Not performed:** Launcher, runtime, ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| ESI=this; CALL complete | **Yes** |
| flags&1 → operator_delete | **Yes** |
| Always return this; RET 4 | **Yes** |
| Invented branches | **None** |
| Decompiler “delete noreturn” | **Ignored** (bytes prove epilogue) |

---

## 5. Gaps

- Product/MSVC demangle (chatlog string is peer-ctor evidence only).
- Complete / base dual residual.
- Vtbl slots [1+].
- Runtime / bit-exact / differential.

---

## 6. Verdict

**accept-with-gaps** — classic scalar-deleting CF/ABI/vtbl[0] sealed. Product class English residual. Not reject.
