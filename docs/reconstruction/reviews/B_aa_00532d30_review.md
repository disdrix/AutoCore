# Review B (skeptical / adversarial): `CVOGCharacter_LevelUp` @ `0x00532d30`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00532d30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00532d30_review.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Research packing at row+0x18 is fully known | **Weak** — only low short is added; high half unused here |
| 2 | Skill-HB walk is required for pool grants | **Overstated** — pools are written before HB walk; walk is refresh |
| 3 | LogicUI always fires on level-up | **Falsified** — gated by `bNotifyUi` (AddExperience passes true) |
| 4 | LevelDown is a perfect inverse | **Falsified** — LevelDown does not reverse `+0x580` research |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| Level / skill / attrib / research offsets | High | Wrong AutoCore progress fields |
| Map key = currentLevel+1 | High | Off-by-one on table row |
| HB / FUN_* side effects | Low–Medium | Missing skill refresh on level |
| HP-delta for LogicUI | Medium | UI-only; combat pools still recalced |

---

## 3. Surviving contract for AutoCore

```
LevelUp(character, notifyUi):
  row = tExperienceLevel[character.Level + 1]
  character.Level += 1
  character.SkillPoints  += row.skill
  character.AttribPoints += row.attrib
  character.Research     += row.research
  refresh combat pools / auto-missions if local
  if notifyUi: send LogicUI 0x2D snapshot
```

---

## 4. Open questions

1. Exact row struct field names in game DB vs client map.
2. Whether server must emit CharacterLevel after LevelUp or client-only is enough for solo.

**Verdict:** Safe for porting pool grants; do not invent research reverse on LevelDown.
