# Review B (skeptical / adversarial): `aa_00442760` Skill_Uses_SkillSet_GetEntryCount_00442760

| Field | Value |
|---|---|
| **Stable ID** | `aa_00442760` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00442760_Skill_Uses_SkillSet_GetEntryCount_00442760.md` |
| **Verdict** | **accept-with-gaps** — alias not product API |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is thin GetEntryCount | Falsified — bulk different VA |
| 2 | Finished skill-set API | Overstated |
| 3 | Safe drop-in for length queries | Falsified |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alias vs thin distinction | High | Wrong wire |
| Bulk internals | Tentative | Unneeded port risk |
| Callee GetEntryCount edge | Medium | Missed real dependency |

---

## 3. Cross-check against raw

```
string-alias bulk @ 0x00442760; thin length helper is aa_00402d80.
Clean ≡ raw bulk CF.
```

---

## 4. Surviving contract for AutoCore

```
Skill_Uses_SkillSet_GetEntryCount_00442760:
  ledger alias; do not use as SkillSet_GetEntryCount
  AutoCore: ignore unless call-graph forces
```

---

## 5. Open questions

1. Optional coverage demotion.
2. Map Named_CalleeOf_* children only if needed.

**Verdict:** **accept-with-gaps** — alias not product API
