# Review A (reconstruction fidelity): `aa_0051de80` SkillCNDHash_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051de80` |
| **VA** | `0x0051de80`–`0x0051deea` inclusive (**107 B** / `0x6B`) |
| **Canonical name** | `SkillCNDHash_CompleteDtor_Inferred` |
| **Ghidra name** | `FUN_0051de80` |
| **Review date** | `2026-08-04` (WQ9G-A OWN dual) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9G-A) |
| **Counterpart** | `reviews/B_aa_0051de80_SkillCNDHash_CompleteDtor_Inferred.md` |
| **System** | skills-abilities / skill-family CNDHash |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (body + strings + vtbl) + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **complete object destructor** for skill-family CNDHash: reinstall vtbl `PTR_FUN_009ce1b8`, soft-log if traversal-locked (`HashError:Destructor…`), destroy bucket table, tear down freelist/slab host at `+0x20`. Does **not** free the host object (scalar deleting dtor does that when `flags&1`). Sole code caller of dualed `SkillCNDHash_ScalarDeletingDtor_Inferred` (`0x0051de60`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9G-A append) | `docs/reconstruction/raw/aa_0051de80_FUN_0051de80.md` |
| Annotated | `docs/reconstruction/raw/aa_0051de80_FUN_0051de80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillCNDHash_CompleteDtor_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0051de80.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051de80_SkillCNDHash_CompleteDtor_Inferred.md` |
| Scalar peer | `SkillCNDHash_ScalarDeletingDtor_Inferred` / `aa_0051de60` (WQ9F-H) |
| Ctor peer | `SkillCNDHash_Ctor_Inferred` / `aa_0051dd60` (WQ9D-A) |
| Destroy nested | `SkillCNDHash_DestroyBucketTable_Inferred` / `aa_004cba60` (WQ9E-A) |
| Live | decompile ≡ 107 B hex for CF; strings @ `0x00a2c270` / `0x00a15844`; vtbl dword0 @ `0x009ce1b8` = scalar |

---

## 3. Signature (sealed)

```c
// ECX=this; no stack args; bare RET; void
void __thiscall SkillCNDHash_CompleteDtor_Inferred(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **Confirmed** |
| stack args | none (bare `C3`) | **Confirmed** |
| return | void | **Confirmed** |
| cleanup | bare `ret` | **Confirmed** |

---

## 4. Control flow (bytes authority)

```
SEH_enter(LAB_009a371b)
*this = PTR_FUN_009ce1b8
if (lock@+0x1d != 0):
  log HashError:Destructor…; log VOG_DEBUG_STOP   // continue
SkillCNDHash_DestroyBucketTable_Inferred(this)    // 004cba60
FUN_0059c8a0(this+0x20)                           // LEA ECX,[ESI+0x20]
SEH_leave; ret
```

| Stage | Match | Conf |
|---|---|---|
| SEH frame | `6A FF 68 1B 37 9A 00 64…` | **Confirmed** |
| Vtbl install | `C7 06 B8 E1 9C 00` | **Confirmed** |
| Soft lock log | strings + continue (no abort) | **Confirmed** |
| Destroy then freelist host | `CALL 004cba60` then `LEA +0x20; CALL 0059c8a0` | **Confirmed** |
| Bare ret | `C3` | **Confirmed** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (107 B):

```
6A FF 68 1B 37 9A 00 64 A1 00 00 00 00 50 64 89 25 00 00 00 00
51 56 8B F1 89 74 24 04 C7 06 B8 E1 9C 00 80 7E 1D 00
C7 44 24 10 00 00 00 00 74 1B
68 70 C2 A2 00 6A 00 E8 C3 65 28 00
68 44 58 A1 00 6A 00 E8 B7 65 28 00
83 C4 10
8B CE E8 8D DB FA FF
8D 4E 20 E8 C5 E9 07 00
8B 4C 24 08 5E 64 89 0D 00 00 00 00 83 C4 10 C3
```

Pad `CC` after `C3`. Immediately precedes this VA is scalar dtor body ending at `0x0051de7d`.

---

## 6. Callers / classification

| Item | Value | Conf |
|---|---|---|
| Classification | MSVC complete object dtor / skill CNDHash | **High** |
| Code CALL sites | 1 — `0x0051de63` (scalar deleting dtor) | **Confirmed** |
| DATA vtbl[0] | `0x009ce1b8` → `0x0051de60` (scalar, not this) | **Confirmed** |
| Callees | `FUN_007a4480`×2, `004cba60`, `0059c8a0` | **Confirmed** |

---

## 7. Naming gate

| Evidence | Present? |
|---|---|
| MSVC complete dtor shape (vtbl reinstall + teardown; no free host) | **Yes** |
| String `HashError:Destructor, already locked for traversal` | **Yes** |
| Same vtbl as dualed SkillCNDHash_Ctor / ScalarDeletingDtor | **Yes** |
| Sole caller is dualed scalar deleting dtor | **Yes** |
| Product/PDB English class name | **No** |

**Decision:** promote **`SkillCNDHash_CompleteDtor_Inferred`** — family High (string + vtbl + scalar caller); product English **Inferred**.

Reject: scalar-dtor identity for this VA; vector deleting dtor; scaffold VOG_DEBUG_STOP-only name; inventory CNDHash dtor merge.

---

## 8. Gaps

1. Product/PDB demangle for host class.
2. Full dual of freelist/slab teardown `FUN_0059c8a0` (not OWN).
3. Full vtbl method map beyond ctor/scalar/complete chain.
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
