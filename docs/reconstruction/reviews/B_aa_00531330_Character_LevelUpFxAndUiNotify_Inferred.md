# Review B (skeptical / adversarial): `aa_00531330` Character_LevelUpFxAndUiNotify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531330` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00531330_Character_LevelUpFxAndUiNotify_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Applies level-up XP / attributes | **Falsified** — FX + UI packets only |
| 2 | Always plays FX | **Falsified** — only when `flag==1` and load returns non-null |
| 3 | Always constructs FX master | **Falsified** — only if `+0xcb8==0` under flag==1 |
| 4 | LogicUi sends only when flag==1 | **Falsified** — three trailing short checks run regardless |

---

## 2. Surviving contract for AutoCore

```
LevelUpNotify(char, isLevelUpFlag):
  if isLevelUpFlag:
    ensure FxMaster at +0xcb8; try play level-up FX on self/vehicle; LogicUi
  if unspent-skill/attr shorts nonzero: LogicUi each
No XP arithmetic here.
```

**Verdict:** **accept-with-gaps**
