# Review B (skeptical / adversarial): `aa_004ceba0` Skill_NonCreatureCastAutoHit

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ceba0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004ceba0_Skill_NonCreatureCastAutoHit.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Structure/inanimate-only helper | Name + AutoHit strings suggest that, but creature path has full score math and sole accuracy-chain caller is `005531d0` → creature combat | **Over-narrow** — unit is shared score kernel; AutoHit is *branch* |
| 2 | Always misses structures | Inanimate → return **1.0** (auto hit) | **Falsified** |
| 3 | UI / debug formatter only | Float return compared to roll threshold in `00553240` | **Falsified** |
| 4 | Finished full hit formula including 4070/41c0 | High pcode discards those returns; FLOAT_ADD only uses `creature+0x260` + first float | **Overstated** if claimed finished; **seal partial** |
| 5 | `skill+0x24` scales the score | Passed as 3rd arg; **no high-pcode use** in body | **Likely false for product** — only parent -1 sentinel uses skill accuracy |
| 6 | `g_flKillSpreeBonusPerStack` is kill-spree mechanic here | Same 0.05f constant reused as **min clamp** | **Name misleading**; value sealed, XP semantics not |
| 7 | Return is damage multiplier | Parent treats as hit probability vs `(roll%100)*0.01` | **Falsified as damage** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null attacker → 1.0 / null victim → 0.0 | **High** | Wrong fail-open/closed |
| Inanimate / non-creature AutoHit → 1.0 | **High** | Structures unhittable or always-miss |
| Score role in accuracy chain | **High** | Wrong combat gate port |
| Level ±9 band → 0.95 / 0.05 | **High** | Level disparity wrong |
| Clamp [0.05, 0.95] + vehicle floor 0.15 | **High** | Score domain wrong |
| Base = `*(cre+0x260)+attackerBonus` | **High** (pcode) | Missed skill scale |
| `skill+0x24` unused in body | **High** pcode / **Medium** absolute | If asm uses it, skill accuracy broken on server port |
| 4070/41c0 dead returns | **High** pcode / residual asm risk | Missed atk/def stats |
| vfunc product names | **Tentative** | Doc only |

---

## 3. Cross-check against raw / pcode

```
raw decompile ≡ clean scaffold CF
high pcode FLOAT ops only:
  FLOAT_ADD  creature+0x260 + stack0
  FLOAT_LESSEQUAL / FLOAT_LESS for 0.15 / 0.95 / 0.05 clamp
CALL 004c4070 / 004c41c0: out=- (unused)
stack formals used: 10/14/18 (+ collapsed first float at 0)
```

Clean does **not** invent skill-grant or net send. Residual: decompiler `unaff_retaddr` naming is defective (first float param).

---

## 4. Surviving contract for AutoCore

```
// Accuracy score in [0,1]-ish; parent: hit if score > (roll%100)*0.01
float ScoreNonCreatureCastAutoHit(float atkBonus, float unused0, float skillAccIgnored,
                                  Entity* atk, Entity* vic, char* diag):
  if !atk: diag="No Attacker"; return 1.0
  if !vic: diag="No Victim";   return 0.0
  if !GetCreature(vic):  diag="Victim inanimate (AutoHit)"; return 1.0
  if !GetCreature(atk):  diag="Non-Creature cast (AutoHit)"; return 1.0
  // level band if either lacks vehicle component
  if !HasVeh(atk) or !HasVeh(vic):
    d = Level(atk)-Level(vic)
    if d > 9: return 0.95
    if d < -9: return 0.05
  score = *(f32*)(GetCreature(atk)+0x260) + atkBonus
  if HasVeh(atk) and HasVeh(vic) and score < 0.15: score = 0.15
  else: score = clamp(score, 0.05, 0.95)
  return score
```

Wire into `Skill_AccuracyHitCheck_Inferred` only after parent handles `skill+0x24 == -1.0` auto-hit.

Do **not** port `FUN_004c4070`/`41c0` into this score until proven live.

---

## 5. Open questions

1. Asm confirmation that `skillAccuracy` and 4070/41c0 are truly dead (FPU/stack).
2. Product name / regen path for `creature+0x260` (precomputed hit chance?).
3. Live-capture scores: crate AutoHit 1.0; equal-level creature mid-band; ±10 level extremes 0.95/0.05.
4. `FUN_0056cf00` product meaning (second caller).
5. Align constant names: prefer `g_flAccuracyScoreMax` / `Min` / `VehicleFloor` over kill-spree alias for this unit.

**Verdict:** **accept-with-gaps** — adversarial cuts overclaim of full combat formula; sealed gates + clamp + chain position stand.
