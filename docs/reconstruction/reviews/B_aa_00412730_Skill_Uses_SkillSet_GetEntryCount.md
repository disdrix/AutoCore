# Review B (skeptical / adversarial): `aa_00412730` Skill_Uses_SkillSet_GetEntryCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_00412730` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00412730_Skill_Uses_SkillSet_GetEntryCount.md` |
| **Verdict** | **accept-with-gaps** — alias not product API |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is the thin (end-begin)/0x18 helper | Falsified — different VA/body |
| 2 | Finished NPC skill logic seal | Overstated — string alias |
| 3 | Safe to call as GetEntryCount | Falsified — wrong contract |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alias-only naming | High | Wrong function wired |
| Bulk CF fidelity | Medium | Internal residual |
| Product use of this VA | Tentative | Wasted reverse effort |

---

## 3. Cross-check against raw

```
string-alias bulk FUN_00412730; NOT aa_00402d80 thin helper.
Clean body ≡ raw bulk; name is evidence-only.
```

---

## 4. Surviving contract for AutoCore

```
Skill_Uses_SkillSet_GetEntryCount @ 0x412730:
  indexing alias only; use SkillSet_GetEntryCount for length
  AutoCore: ignore for skill-set size
```

---

## 5. Open questions

1. Keep dual for ledger completeness only.
2. Prefer thin unit dual for product.

**Verdict:** **accept-with-gaps** — alias not product API
