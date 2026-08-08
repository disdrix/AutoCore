# Review A (reconstruction fidelity): `aa_0051de60` SkillCNDHash_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051de60` |
| **VA** | `0x0051de60`–`0x0051de7d` inclusive (**30 B** / exclusive end `0x0051de7e`) |
| **Canonical name** | `SkillCNDHash_ScalarDeletingDtor_Inferred` |
| **Ghidra name** | `FUN_0051de60` |
| **Review date** | `2026-08-04` (WQ9F-H OWN dual) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9F-H) |
| **Counterpart** | `reviews/B_aa_0051de60_SkillCNDHash_ScalarDeletingDtor_Inferred.md` |
| **System** | skills-abilities / skill-family CNDHash |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full body) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **scalar-deleting destructor** (vtbl[0] of `PTR_FUN_009ce1b8`): always run skill CNDHash complete dtor `FUN_0051de80`; if `(flags & 1)` free the host with `operator_delete`; return `this`. Pairs with dualed `SkillCNDHash_Ctor_Inferred` (same vtbl install).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9F-H append) | `docs/reconstruction/raw/aa_0051de60_FUN_0051de60.md` |
| Annotated | `docs/reconstruction/raw/aa_0051de60_FUN_0051de60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillCNDHash_ScalarDeletingDtor_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0051de60.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051de60_SkillCNDHash_ScalarDeletingDtor_Inferred.md` |
| Ctor peer | `SkillCNDHash_Ctor_Inferred` / `aa_0051dd60` (WQ9D-A) |
| Pattern peer | `Class_009c7938_ScalarDeletingDtor` (W31-E **accept**) |
| Live | decompile ≡ 30 B hex; DATA vtbl dword @ `0x009ce1b8` = `0x0051de60` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall SkillCNDHash_ScalarDeletingDtor_Inferred(void* self, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **Confirmed** |
| flags | stack (`F6 44 24 08 01`) | **Confirmed** |
| return | EAX = ESI = this | **Confirmed** |
| cleanup | `C2 04 00` | **Confirmed** |

---

## 4. Control flow (bytes authority)

```
ESI = this
call FUN_0051de80              // complete dtor
if (flags & 1):
  operator_delete(this)
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 30 B hex | **Confirmed** |
| bit0 gate only (not vector) | `test …,1` / `je` | **Confirmed** |
| False noreturn ignored | epilogue present after delete | **Confirmed** |
| vtbl[0] | DATA `009ce1b8` → `0051de60` | **Confirmed** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (30 B):

```
568bf1e818000000f644240801740956e8adb9f6ff83c4048bc65ec20400
```

Pad `CC CC` then complete dtor `FUN_0051de80`.

---

## 6. Callers / classification

| Item | Value | Conf |
|---|---|---|
| Classification | MSVC scalar deleting dtor / skill CNDHash | **High** |
| Code CALL sites | none (vtbl dispatch only) | **Confirmed** |
| DATA xref | `0x009ce1b8` vtbl[0] | **Confirmed** |
| Callees | `FUN_0051de80`, `operator_delete` | **Confirmed** |

---

## 7. Naming gate

| Evidence | Present? |
|---|---|
| MSVC scalar dtor template (complete + flags&1 + ret 4) | **Yes** |
| Same vtbl as dualed SkillCNDHash_Ctor | **Yes** (`PTR_FUN_009ce1b8`) |
| Complete dtor string `HashError:Destructor…` on callee | **Yes** (evidence-only; not OWN) |
| Product/PDB English class name | **No** |

**Decision:** promote **`SkillCNDHash_ScalarDeletingDtor_Inferred`** — family High (vtbl + ctor dual); product English **Inferred**.

Reject: complete-dtor identity for this VA; vector deleting dtor; generic `Class_009ce1b8_*` only (SkillCNDHash family already sealed).

---

## 8. Gaps

1. Product/PDB demangle for host class.
2. Complete dtor `FUN_0051de80` dual not owned here.
3. Full vtbl method map beyond slot 0.
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
