# Review A (reconstruction fidelity): `aa_00552180` Skill_FormatTimingAttributeLines

| Field | Value |
|---|---|
| **Stable ID** | `aa_00552180` |
| **VA** | `0x00552180` |
| **Canonical name** | `Skill_FormatTimingAttributeLines` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00552180_Skill_FormatTimingAttributeLines.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Emit skill timing/attribute debug or tooltip lines for `cast_time`, `cooldown`, `duration`, `pulse_period/count/duration`, `power_cost`, `range`, `tether_range` including instant/infinite special cases. Large body (~515 lines). Paired with FormatCooldownDurationRangeLines and ParseTimingAttributeToken.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00552180_Skill_FormatTimingAttributeLines.md` (or `aa_00552180_FUN_00552180.md`) |
| Annotated | `docs/reconstruction/raw/aa_00552180_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_FormatTimingAttributeLines.cpp` |
| Function record | `docs/reconstruction/functions/aa_00552180_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Token names cast_time/cooldown/duration/…` | High | Strings |
| `Instant/infinite special cases` | High | Plate |
| `Pulse + power + range family` | High | Plate |
| `Format only` | High | No cast |
| `All infinite thresholds sealed` | Medium | Magic constants |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Per-attribute emit CF | Yes |
| No invented parse mutation | Yes |

---

## 5. Gaps / open

1. Thresholds for Infinite/instant.
2. Caller: debug dump vs player tooltip.

**Verdict:** **accept-with-gaps**
