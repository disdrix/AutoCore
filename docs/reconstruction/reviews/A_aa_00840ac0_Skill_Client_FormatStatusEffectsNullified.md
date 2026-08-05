# Review A (reconstruction fidelity): `aa_00840ac0` Skill_Client_FormatStatusEffectsNullified

| Field | Value |
|---|---|
| **Stable ID** | `aa_00840ac0` |
| **VA** | `0x00840ac0` |
| **Canonical name** | `Skill_Client_FormatStatusEffectsNullified` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00840ac0_Skill_Client_FormatStatusEffectsNullified.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client combat log/tooltip formatter for skills that nullify status effects. Builds `\nStatus Effects Nullified: %s\n` using skill rank reevaluation and `Skill_FormatTargetFilterTooltip` (`FUN_005506a0`). Substantial CF (~287 lines, 28 ifs). Display/format only — not status application (that is `Skill_ApplyStatusEffectLocal` / 0x2031).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00840ac0_Skill_Client_FormatStatusEffectsNullified.md` (or `aa_00840ac0_FUN_00840ac0.md`) |
| Annotated | `docs/reconstruction/raw/aa_00840ac0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_Client_FormatStatusEffectsNullified.cpp` |
| Function record | `docs/reconstruction/functions/aa_00840ac0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `String Status Effects Nullified` | High | Literal |
| `Uses FormatTargetFilterTooltip` | High | Callee |
| `May SetRankAndReevaluate for display` | High | Callees |
| `No S2C apply` | High | Format only |
| `in_EAX skill/context ABI residual` | Medium | Decomp |
| `Large body fully typed` | Low | Scaffold residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Rank/context → format nullify list string | Yes |
| No invented apply packet | Yes |

---

## 5. Gaps / open

1. Which skill flag selects nullify formatter branch.
2. Exact list source of nullified effect names.

**Verdict:** **accept-with-gaps**
