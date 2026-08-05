# Review B (skeptical / adversarial): `aa_004c4b20` Creature_KillXpHpRatio01_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4b20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004c4b20_Creature_KillXpHpRatio01_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Clamp high threshold is 1.0 input | High knee is **0.4** → snaps to 1.0 | **Falsified** as identity clamp |
| 2 | Uses mission XP bias | No `g_flMissionXpRoundBias` in body | **Falsified** |
| 3 | Returns integer percent | ST0 float | **Falsified** |
| 4 | `DAT_009cb8b8` is 0.1 | Bytes = **0.4f** | **Falsified** 0.1 |
| 5 | Sole kill-XP formula | Only ratio; percent at template+0x500 | **Survives** partial role |

---

## 2. Live ≡ raw

Matches annotated. Call sites both in OnDeath type switch.

---

## 3. Surviving contract

```
// ST0 = clamp01_knees(cur/max, lo=0.1, hi_snap=0.4→1)
```

**Verdict:** **accept-with-gaps**.
