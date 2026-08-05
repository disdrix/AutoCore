# Review B (skeptical / adversarial): `aa_005330e0` CVOGCharacter_LevelDown

| Field | Value |
|---|---|
| **Stable ID** | `aa_005330e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005330e0_CVOGCharacter_LevelDown.md` |
| **Verdict** | **accept-with-gaps** on CF; research non-reverse is High-confidence absence |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Reverses research points | **Falsified — no +0x580 store** |
| 2 | Uses post-decrement level for table lookup | **Falsified — lookup before --** |
| 3 | Always mutates even if no table row | **Falsified — end-iterator bail** |
| 4 | Finished exact | **Overstated — helper + row payload gaps** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Current-level lookup then -- | High | Wrong grant reverse |
| Skill/attrib clamp ≥0 | High | Negative pools |
| No research reverse | High | Incorrect de-level economy |
| Odd-level base stats | Tentative | Wrong attrib drift |

---

## 3. Cross-check against raw

```
ensure XP table;
lower_bound(current level);
if not end:
  dirty|0x80; level--; pools -= row; clamp;
  if odd(level): base-stat -1 helpers;
  vehicle recalc; vtbl+0x5c; copy +0x12e→+0x12c; +0x4f2=1;
  if local +0x7e: SearchAutoMissions.
Clean ≡ raw; no research reverse.
```

---

## 4. Surviving contract for AutoCore

```
On LevelDown (negative XP loop / de-level):
  reverse ONE level using CURRENT row grants for skill/attrib only
  clamp pools to ≥0; optional odd-level base-stat decrement
  do NOT reverse research pool (+0x580)
  refresh vehicle combat pools; local player SearchAutoMissions
Call only from AddExperience negative path when below threshold.
```

---

## 5. Open questions

1. Full tExperienceLevel column map.
2. Whether LevelUp odd-path is exact inverse of these four shorts.
3. Runtime capture of multi-level de-level loop interaction.

**Verdict:** **accept-with-gaps** on CF; research non-reverse is High-confidence absence
