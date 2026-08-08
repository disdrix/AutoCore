# Review B (skeptical / adversarial): `aa_0051de60` SkillCNDHash_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051de60` |
| **VA** | `0x0051de60` |
| **Canonical name** | `SkillCNDHash_ScalarDeletingDtor_Inferred` |
| **Review date** | `2026-08-04` (WQ9F-H OWN dual) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0051de60_SkillCNDHash_ScalarDeletingDtor_Inferred.md` |
| **System** | skills-abilities / skill-family CNDHash |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0051de60` only | Scaffold; role is sealed |
| Complete dtor / `SkillCNDHash_Dtor` as this VA | **Reject** — no vtbl install, no member teardown; only calls `FUN_0051de80` |
| Vector deleting dtor | **Reject** — no array count / no `operator_delete[]`; single flags bit0 |
| `Class_009ce1b8_ScalarDeletingDtor` only | Acceptable alternate; SkillCNDHash family name preferred (ctor dual + HashError string on complete) |
| Product English without `_Inferred` | **Reject** — no PDB demangle |
| `SkillCNDHash_ScalarDeletingDtor_Inferred` | **Accept** — MSVC scalar template + family evidence |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| This is the complete-object dtor body | **Fails** — body is 30 B wrapper only |
| cdecl / stack this | **Fails** — `8B F1`; vtbl thiscall |
| Always frees heap | **Fails** — `test flags,1` / `je` skips delete |
| Never frees heap | **Fails** — bit0 path calls `operator_delete` |
| Ghidra noreturn truncates | **Fails** — full 30 B reaches `MOV EAX,ESI; POP ESI; RET 4` |
| Wrong vtbl family | **Fails** — dword @ `0x009ce1b8` = `0x0051de60`; ctor installs same |
| Different unit than SkillCNDHash | **Fails** — same vtbl as dualed ctor; complete dtor uses HashError:Destructor |

---

## 3. Agreement with Review A

- Scalar deleting CF + ABI ret 4: **agree Confirmed**
- vtbl[0] DATA xref: **agree Confirmed**
- Family name with `_Inferred`: **agree**
- Gaps (product English, complete dtor dual, runtime): **agree open**

---

## 4. Residual risks

- Do not port complete-dtor member teardown into this VA.
- Virtual callers may pass flags=0 (no free) when object is subobject — preserve bit0 gate.
- Complete dtor traversal-lock check is callee behavior, not this wrapper.

**Verdict:** **accept-with-gaps**
