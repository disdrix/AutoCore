# Review B (skeptical / adversarial): `aa_00627ec0` Skill_ComputeEffectScore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00627ec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9E-B OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_00627ec0_Skill_ComputeEffectScore_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This unit **stores** `skill+0x624` | Confuse with store helper / Reevaluate | **Falsified** — no stores; pure float → ceil |
| 2 | Is the presence leaf itself | Same callee address region | **Falsified** — calls `00627be0`; large weighted body |
| 3 | Scores always use all banks | Ignore presence gates | **Falsified** — each bank behind bit test |
| 4 | Bits `0x800`/`0x1000` come from presence scan | Assume only scan bits | **Falsified** — presence leaf does not set them; OR’d from `skill+0xc` |
| 5 | `g_flLevelUpUiBase_Inferred` is “level-up UI” here | Trust global name | **Overstated name only** — value is sealed **2.0f**; used as literal two |
| 6 | Return is float score | Miss ceil | **Falsified** — `(int)ceil` |
| 7 | Single-skill UI display only | Miss dual-call sites | **Falsified** — callers score **two** skills and compare |
| 8 | Name invents “Score” without evidence | Symbol inflation | **Role holds** — magnitude sum + ceil + compare; product noun open (`_Inferred`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Presence-gated CF | **High** | Wrong HB priority |
| Float pool values | **High** | Numeric drift |
| ECX = skill | **High** | Score wrong object |
| Product metric English | **Low** | Doc only |
| Exact signed-short branch shape vs compiler | **Med** | decompiler gotos; clean mirrors raw |

---

## 3. Cross-check against raw ≡ live

```text
score = 0; weight = 1
flags = Skill_ComputeEffectPresenceFlags_Inferred(skill)
if flags & 0x1:   // pair bank + scale
if flags & 0x100: // second pair bank
if flags & 0x40:  // four i16 * duration * 0.001
if flags & 0x8:   // signed short bank
if flags & 0x2:   // f32 +0x3c
if flags & 0x800: // i16 +0
if flags & 0x10:  // byte +0xda * 2
if flags & 0x1000:// score *= weight * 5
// ungated +0x4c term; duration scale; charge scale
if score < 1: score = 1
return (int)ceil(score)
```

Caller pattern (sealed @ `FUN_00625b00`):

```text
s1 = Skill_ComputeEffectScore_Inferred(skillA)  // often obj+0x24
s2 = Skill_ComputeEffectScore_Inferred(skillB)
if s1 < s2: prefer B (return 2)
```

---

## 4. Surviving contract for AutoCore

```
Skill_ComputeEffectScore_Inferred(skill) -> int
  // Pure function of skill fields + sealed float pool.
  // Must call presence leaf first; must NOT write +0x624.
  // Keep presence bit map stable with Skill_ComputeEffectPresenceFlags_Inferred.
  // Port ceil + floor(1.0) exactly for compare stability.
```

**Port tests:** all-zero effects with `+0xc==0` → return 1 (floor); single bit-0x1 bank non-zero changes score; dual compare order matches when scores unequal.

**Verdict:** **accept-with-gaps** — adversarial store/leaf/all-banks confusions **fail**; product score English residual remains.
