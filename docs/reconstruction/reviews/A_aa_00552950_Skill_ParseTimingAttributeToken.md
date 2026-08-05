# Review A (reconstruction fidelity): `aa_00552950` Skill_ParseTimingAttributeToken

| Field | Value |
|---|---|
| **Stable ID** | `aa_00552950` |
| **VA** | `0x00552950` |
| **Canonical name** | `Skill_ParseTimingAttributeToken` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00552950_Skill_ParseTimingAttributeToken.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Parse/match skill attribute token names (`cast_time`, `cooldown`, `duration`, `pulse_*`, `power_*`, `range*`, `splash_radius`) against a lowercase token stream and emit formatted values or **Infinite** markers. Large switchy CF (~343 lines, 50 ifs). Token parser for skill attribute display/edit paths.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00552950_Skill_ParseTimingAttributeToken.md` (or `aa_00552950_FUN_00552950.md`) |
| Annotated | `docs/reconstruction/raw/aa_00552950_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_ParseTimingAttributeToken.cpp` |
| Function record | `docs/reconstruction/functions/aa_00552950_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Token set cast_time/cooldown/duration/…` | High | Strings |
| `Infinite marker path` | High | String |
| `Returns 0 on no match paths` | High | returns |
| `Does not mutate skill CD` | High | Parse/format |
| `Edit-path write residual` | Medium | May be display-only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Token match → format value | Yes |
| No invented cast request | Yes |

---

## 5. Gaps / open

1. Whether any branch writes skill fields (edit) vs format only.
2. Full token list completeness.

**Verdict:** **accept-with-gaps**
