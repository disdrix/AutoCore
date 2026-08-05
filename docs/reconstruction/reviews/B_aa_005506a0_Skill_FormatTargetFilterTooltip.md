# Review B (skeptical / adversarial): `aa_005506a0` Skill_FormatTargetFilterTooltip

| Field | Value |
|---|---|
| **Stable ID** | `aa_005506a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005506a0_Skill_FormatTargetFilterTooltip.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Authoritative target filter | Falsified — tooltip text |
| 2 | Small function | Falsified — huge format |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Flag bits → strings | High | Wrong tooltip |
| Buffer overflow residual | Tentative | Crash UI |

---

## 3. Cross-check against raw

```
for filter flags on skill: sprintf description into out buf.
Clean ≡ raw CF; string table residual.
```

---

## 4. Surviving contract for AutoCore

```
FormatTargetFilterTooltip(skillDef, buf, ...):
  client tooltip only
  AutoCore: optional UX parity
```

---

## 5. Open questions

1. Extract flag→string map.

**Verdict:** **accept-with-gaps**
