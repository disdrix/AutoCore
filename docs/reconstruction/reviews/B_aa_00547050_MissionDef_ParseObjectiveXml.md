# Review B (skeptical / adversarial): `aa_00547050` MissionDef_ParseObjectiveXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_00547050` |
| **VA** | `0x00547050` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00547050_MissionDef_ParseObjectiveXml.md` |
| **System** | `missions-progression` |
| **Dual status** | **Written this pass** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function body is the short decompiler snippet only | **Falsified as complete** — callees list 30+ functions; force_decompile still truncates; asm shows full factory |
| 2 | Runtime objective evaluator / CompleteObjective | **Falsified** — sole caller is EnsureXml Objective tag; strings are parse/log only |
| 3 | Collect ctor lives elsewhere | **Falsified** — sole xref `0x00547337` inside this unit |
| 4 | Deliver ctor lives elsewhere | **Falsified** — sole xref `0x00547385` inside this unit |
| 5 | Sequence error is cosmetic dead string | **Falsified** — branch logs + early return after size probe |
| 6 | `+0x130` is awardable flag (old GiveMission prose) | **Falsified as awardable-bit** — used as objective count (matches GiveMission residual) |
| 7 | Exhaustive type table sealed bit-exact | **Fail** — residual unmapped arms |
| 8 | clean C++ is port-ready | **Fail** — scaffold omits arms |
| 9 | Runtime / bit-exact | **Fail** |

---

## 2. Competing interpretations

| Interpretation | Status |
|---|---|
| Mission-def Objective XML factory | **Wins** (caller + strings + ctors) |
| Generic XML walker for any document | Loses — mission-specific error strings + objective slot writes |
| Requirement *runtime* dispatch table | Loses — constructors only; no eval vtbl calls in factory arms |

---

## 3. Port risks

| Risk | Impact |
|---|---|
| Porting from truncated clean | Missing requirement types silently |
| Wrong objective count field | Sequence overflow or under-alloc |
| Parent pointer not `+0x13c[seq]` | Requirement owner wrong → crash/eval miss |
| Treating as server logic | Client hydrate-only |

---

## 4. Independence

Rebuilt role from callers, UTF-16 type table `read_memory`, and `get_assembly_context` on Collect/Deliver arms — not from scaffold clean prose.

**Verdict:** Accept role + sealed Collect/Deliver factory edges. Reject any claim that decompiler body alone is the function. Gaps on remaining type arms are honest.
