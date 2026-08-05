# Review B (skeptical / adversarial): `aa_00523e60` Character_SkillHash_RefreshOnLevelChange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00523e60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00523e60_Character_SkillHash_RefreshOnLevelChange_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Grants skill points / XP | **Falsified** — hash walk + clear only |
| 2 | Unlocked traversal always OK | **Falsified** — asserts lock via NDError strings |
| 3 | Touches every skill unconditionally | **Falsified** — rank `+0xdc>0` **and** flag bit0 at `+0x615` |
| 4 | Only LevelUp caller | **Open** — name/strings also general; parent sealed as LevelUp callee |

---

## 2. Surviving contract for AutoCore

```
OnLevelChange_RefreshSkills(char):
  lock skill-hash traversal
  for each skill: if active-rank and flag: clear cast binding (0x5fc path)
  unlock
Do not implement as blanket skill reset without gates.
```

**Verdict:** **accept-with-gaps**
