# Review B (skeptical / adversarial): `aa_00552950` Skill_ParseTimingAttributeToken

| Field | Value |
|---|---|
| **Stable ID** | `aa_00552950` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00552950_Skill_ParseTimingAttributeToken.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always Infinite | Falsified — multi token |
| 2 | Is FormatCooldownDurationRangeLines | Falsified — token match sibling |
| 3 | Server validation | Falsified — client parse |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Token vocabulary | High | Miss attributes |
| Infinite path | High | Wrong UI |
| Edit vs display | Tentative | Accidental write |

---

## 3. Cross-check against raw

```
match lowercase token; emit value or Infinite; else 0.
Clean ≡ raw outline.
```

---

## 4. Surviving contract for AutoCore

```
ParseTimingAttributeToken(stream, skill):
  attribute token display/edit helper
  pair FormatTimingAttributeLines
  AutoCore skill XML/UI tooling
```

---

## 5. Open questions

1. Prove no skill field writes on parse-only callers.
2. Complete token enum.

**Verdict:** **accept-with-gaps**
