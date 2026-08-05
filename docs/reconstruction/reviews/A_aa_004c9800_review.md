# Review A (reconstruction fidelity): `aa_004c9800` Experience_LevelDiffBaseXp

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9800` |
| **VA** | `0x004c9800` |
| **Canonical name** | `Experience_LevelDiffBaseXp` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c9800_Experience_LevelDiffBaseXp.md` |
| Annotated | `docs/reconstruction/raw/aa_004c9800_Experience_LevelDiffBaseXp.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Experience_LevelDiffBaseXp.cpp` |
| Prior art | `docs/XP.md` § Level-difference base |
| Caller | `CVOGCombat_CalculateAndAwardKillXP` clean/raw (`grey=true`) |

---

## 2. Signature

| Element | Raw | Clean | Match |
|---|---|---|---|
| Convention | `__cdecl` 3 params | Same | **Yes** |
| `(victim, player, enableGreyCheck)` | Present | Same order/names | **Yes** |
| Return | `uint` base XP | `unsigned` | **Yes** |

---

## 3. Control flow vs raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| `diff = player - victim` | Present | Present | **Yes** |
| Hard branch when signed diff < 0 | Present | Present | **Yes** |
| Hard floor clamp to `-9` (`0xfffffff7`) when not `-10 < diff` | Present | Present | **Yes** |
| `GetCreatureXpForLevel(player - hardDiff)` | Present | Present | **Yes** |
| Extra term only when `diff < hardDiff` | Present | Present | **Yes** |
| `trunc(abs(extra) * base * g_flHardKillInterpolate)` | Present | Present | **Yes** |
| Grey early-out: `diff > 9 && grey` → 0 | Present | Present | **Yes** |
| Easy base = `GetCreatureXpForLevel(victim)` | Present | Present | **Yes** |
| Easy adj when grey && `diff > 0` | Present | Present | **Yes** |
| `ROUND(\|diff\| * 1.5 * base * -0.1)` | Present | Present | **Yes** |
| `max(0, base+adj)` via `& ((sum<0)-1)` | Present | Present (parenthesized) | **Yes** |

---

## 4. Constants

| Symbol | Address | XP.md / clean |
|---|---|---|
| `g_dGreyKillSlopeA` | `0x009CBB68` | `1.5` double |
| `g_dGreyKillSlopeB` | `0x009CBB60` | `-0.1` double |
| `g_flHardKillInterpolate` | `0x00AAA6A4` | `0.005f` |

---

## 5. Gaps

1. `ROUND` / x87 rounding mode not re-verified against live FPU control word.
2. `Experience_GetCreatureXpForLevel` table contents not re-dumped in this review.
3. Prep-clamp (±3) is **call-site** responsibility — correct that clean does not re-apply it.

**Verdict:** Clean tracks raw hard/easy CF, clamps, abs idioms, and max(0) mask. **accept-with-gaps.**
