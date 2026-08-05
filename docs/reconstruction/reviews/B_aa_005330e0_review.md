# Review B (skeptical / adversarial): `CVOGCharacter_LevelDown` @ `0x005330e0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005330e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005330e0_review.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | LevelDown fully undoes LevelUp | **Falsified** — no research reverse; odd-level path has no LevelUp mirror |
| 2 | Map lookup uses post-decrement level | **Falsified** — key is current level before `--` |
| 3 | Fastcall vs thiscall naming matters for ports | **Weak** — single `this` pointer; AutoCore uses C# methods |
| 4 | Clamp to 0 means pools never go negative server-side | **Client-only evidence** — server must decide independently |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| Level-- + skill/attrib reverse | High | Wrong de-level on negative XP |
| Research not reversed | High | Over-grant research if server “undoes” research |
| Odd-level base-stat path | Medium | Rare negative-XP edge |

---

## 3. Surviving contract for AutoCore

```
LevelDown(character):
  row = tExperienceLevel[character.Level]   // BEFORE decrement
  character.Level -= 1
  character.SkillPoints  = max(0, SkillPoints  - row.skill)
  character.AttribPoints = max(0, AttribPoints - row.attrib)
  // do NOT invent research undo unless new evidence
  refresh pools / auto-missions if local
```

---

## 4. Open questions

1. Is odd-level base-stat path ever hit in live negative-XP content?
2. Should AutoCore reject negative XP entirely (no LevelDown) for multiplayer safety?

**Verdict:** Use for de-level pools only; do not claim perfect LevelUp inverse.
