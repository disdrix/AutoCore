# Review B (skeptical / adversarial): `aa_004c9800` Experience_LevelDiffBaseXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9800` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Verdict** | **accept-with-gaps** on control flow; **needs-more-evidence** for worked numeric table examples |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Grey ≥10 always returns 0 | **Partial** — only when `bEnableGreyCheck`; kill path passes `true`, but other callers (if any) could disable |
| 2 | Easy slope is exactly −15%/level | **Overstated as continuous %** — formula is `ROUND(\|d\| * 1.5 * base * -0.1)` = `ROUND(-0.15 * \|d\| * base)`, integer after ROUND; not compound multi-step |
| 3 | Hard path “boosts victim level” | **Misstated if read as victim row** — lookup key is `player - hardDiff` (boosted), not raw victim |
| 4 | Hard floor is −10 | **Falsified** — clamp constant is **−9** (`0xfffffff7`); gate is `-10 < diff` to keep raw |
| 5 | Extra hard interpolate always runs | **Falsified** — only when raw diff is more negative than clamp (diff ≤ −10) |
| 6 | Prep ±3 clamp lives in this function | **Falsified** — call-site only (`CalculateAndAwardKillXP`) |
| 7 | `max(0, …)` is a stdlib call | **Falsified** — bit-mask `(sum) & ((sum<0)-1)` |

---

## 2. Surviving skeleton

```
diff = P - V
if diff < 0:
  hard = (diff > -10) ? diff : -9
  base = CreatureXP[P - hard]
  if diff < hard:
    base += trunc(abs(diff - hard) * base * 0.005)
  return base
if grey && diff >= 10: return 0
base = CreatureXP[V]
if grey && diff > 0:
  base = max(0, base + ROUND(|diff| * 1.5 * base * -0.1))
return base
```

---

## 3. Open questions

1. Exact CreatureXP table values for worked examples (L1 same-level ≈ 39 in XP.md) — not re-sealed here.
2. Any non-kill callers of this helper with `bEnableGreyCheck=false`?
3. Interaction of call-site victim clamp with hard boost: double-capping high victims?

---

## 4. Verdict

Branch structure and constants match raw. Do not invent “−15% compound” or “−10 floor” without the exact clamp/ROUND surface. Numeric end-to-end XP still needs table + GLOBAL scalar (caller) evidence.
