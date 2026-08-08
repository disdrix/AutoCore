# Review A (reconstruction fidelity): `aa_00520330` Object_SetCrewHostBackLink_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520330` |
| **VA** | `0x00520330`–`0x0052033d` exclusive |
| **Body size** | **13 B** |
| **Canonical name** | `Object_SetCrewHostBackLink_Inferred` |
| **Ghidra name** | `FUN_00520330` |
| **Prior alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_00520330` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00520330_Object_SetCrewHostBackLink_Inferred.md` |
| **System** | skills-abilities / vehicle crew |
| **Agent** | WQ9E-D OWN-ONLY dual |
| **Live tools** | `batch_decompile`, `analyze_function_complete`, `get_function_by_address`, `read_memory`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept** — leaf ABI/bytes/field sealed; product English residual only (non-blocking) |

---

## 1. Purpose

**Crew-host back-link leaf setter.** Stores a crew-host pointer (or null) at `object+0xCB0`. Complements dualed Insert/Clear and is the field convoy UI reads for membership.

```c
// __thiscall; RET 4; void
void Object_SetCrewHostBackLink_Inferred(Object* self, void* crewHostOrNull);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | ≡ raw: single store `*(this+0xCB0)=arg` |
| Body bytes | `8B 44 24 04 89 81 B0 0C 00 00 C2 04 00` |
| Function meta | `00520330`–`0052033c` body end |
| Callers | Insert `005755b0`, Clear `00574a90`, `00574a30`, `005750e0`, `00575200`, `005752c0`, `0094dab0` |
| Prior dual | Insert seals `ecx=member; push host` → **member+0xCB0=host** |
| Consumer | convoy dual reads `*(local+0xCB0)` as crew host |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 13 B / `ret 4` | **Confirmed** | bytes |
| `*(this+0xCB0) = arg0` | **Confirmed** | `mov [ecx+0xCB0],eax` |
| Leaf / 0 callees | **Confirmed** | analyze |
| 7 callers (Insert/Clear family) | **Confirmed** | callers tool |
| Role = crew host back-link | **High** | dualed Insert/Clear + convoy read |
| Product C++ name | **Inferred** | no demangle |

---

## 4. Control flow

```
eax = stack_arg0
*(ecx + 0xCB0) = eax
ret 4
```

---

## 5. Gaps (acceptable)

1. Product / MSVC demangle for field and class.
2. Whether non-crew systems share `+0xCB0` (not in this caller set).
3. Runtime / bit-exact (Terminal false).

**Verdict:** **accept** — CF fully sealed; name `_Inferred` for product English only.
