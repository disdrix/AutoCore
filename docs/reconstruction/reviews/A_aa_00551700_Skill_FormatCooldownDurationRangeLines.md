# Review A (reconstruction fidelity): `aa_00551700` Skill_FormatCooldownDurationRangeLines

| Field | Value |
|---|---|
| **Stable ID** | `aa_00551700` |
| **VA** | `0x00551700` |
| **Canonical name** | `Skill_FormatCooldownDurationRangeLines` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00551700_Skill_FormatCooldownDurationRangeLines.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Format compact skill combat/tooltip lines: **Cooldown**, **Duration**, **Power every**, **Range** (single or min–max meters), Maintain Limit, Splash, Chance percent; optional stealthed gate prefix. Large real formatter (~490 lines, 38 ifs). UI companion to `Skill_FormatTimingAttributeLines` / `ParseTimingAttributeToken`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00551700_Skill_FormatCooldownDurationRangeLines.md` (or `aa_00551700_FUN_00551700.md`) |
| Annotated | `docs/reconstruction/raw/aa_00551700_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_FormatCooldownDurationRangeLines.cpp` |
| Function record | `docs/reconstruction/functions/aa_00551700_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Emits Cooldown/Duration/Power/Range strings` | High | Literals |
| `Range min-max vs single` | High | CF branches |
| `Stealthed prefix gate` | High | Plate |
| `No cast mutation` | High | Format only |
| `Field offsets for each metric` | Medium | Shared skill runtime |
| `Full line order sealed` | Medium | Large body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Per-metric gates → sprintf lines | Yes |
| No invented network | Yes |

---

## 5. Gaps / open

1. Exact skill runtime offsets for each metric.
2. Stealth gate field identity.

**Verdict:** **accept-with-gaps**
