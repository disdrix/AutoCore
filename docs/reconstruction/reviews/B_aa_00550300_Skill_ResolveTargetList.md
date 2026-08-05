# Review B (skeptical / adversarial): `aa_00550300` Skill_ResolveTargetList

| Field | Value |
|---|---|
| **Stable ID** | `aa_00550300` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` (dual residual strengthen `2026-07-29`) |
| **Counterpart** | `reviews/A_aa_00550300_Skill_ResolveTargetList.md` |
| **Residual scratch** | `reviews/a_00550300.md` |
| **Verdict** | **accept** on helper/outFlags writer chain; **accept-with-gaps** on gather/runtime |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Only single target always | **Falsified** — gather path when `+0x624` bits demand multi/area |
| 2 | Applies status itself | **Falsified** — list resolve only; no ApplyStatus |
| 3 | This body ORs bits 4/8/0x10 | **Falsified** — exclusive Filter `0x0054ff00` |
| 4 | RangeCheck itself ORs bit2 | **Falsified** — RangeCheck returns `g_flZero`; **this body** does `*outFlags \|= 2` |
| 5 | Bit1 and bit2 are mutually exclusive | **Falsified** — range-fail `goto` no-primary can OR **both** (consumer prioritizes bit2) |
| 6 | ValidateTargetForSkill is a callee | **Falsified** — Filter + Range + Gather only |
| 7 | Bit dictionary English fully product-named | **Partial** — UX strings High; original enum names Probable/open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Flag-driven gather CF | **High** | Wrong target set size |
| Count return | **High** | Miss multi-hit |
| Bit1 writer site / gates | **Confirmed** | False “no target” fail |
| Bit2 writer site (post RangeCheck) | **Confirmed** | Wrong OOR vs filter fail |
| Filter sole writer of 4/8/0x10 | **Confirmed** | Mis-attribute toast codes |
| Bit English product names | Probable | Mislabel logs (UX still High) |
| Gather ABI product | Tentative | Wrong multi-target port |

---

## 3. Cross-check against raw

```
wipe → ResolveObject → Filter → (Range | no-primary)
  Filter reject bits 4/8/0x10 in Filter body
  Range zero → *outFlags |= 2; fall to no-primary
  no-primary → maybe *outFlags |= 1; or self-pos / ground continue
  optional GatherTargetsInArea; return count
Clean ≡ raw CF (2026-07-29 re-decompile; helper names plate-renamed).
```

Sole-caller recheck: `get_function_callers(0x0054ff00)` and `(0x0058c0a0)` → **only** `Skill_ResolveTargetList`.

---

## 4. Surviving contract for AutoCore

```
ResolveTargetList(skill, outList[100], gatherCtx, source, tfid…, fallbackPos, outFlags*):
  // outFlags ownership
  //   bit1  = this (no usable primary; Ground/self gates suppress)
  //   bit2  = this after RangeCheck==0 (OOR); consumer → eSkillResponses 0x0D
  //   4/8/0x10 = Filter only
  // never returns eSkillResponses; never calls ValidateTargetForSkill
  seed primary → Filter → Range → optional Gather
  return count
```

Pair with: `Skill_GatherTargetsInArea`, `Client_Skill_ResolveCastTarget`, `CVOGReaction_CastSkillOnTarget` null-list path.

---

## 5. Open questions

1. ~~Publish +0x614 bits~~ **Partial High:** tooltip English Self/Ally/Enemy/Minion/Ground (+ Remains/Convoy); residual `a_00550300.md`.
2. Live multi-target cast capture — still open.
3. ~~FUN_0054ff00 / bit4 writers~~ **Sealed** at Filter `0x0054ff00` (sole).
4. ~~FUN_0058c0a0~~ **Role sealed:** `Skill_RangeCheckTargetForResolveList_Inferred`; bit2 **OR'd in this body** (not in helper).
5. ~~Bit1 vs bit2 exclusivity~~ **Sealed dual-bit:** can both set; consumer bit2-first.
6. Full `+0x624` English enum; Gather ABI names — open.

**Verdict residual 2026-07-29 strengthen:** **accept** on dual residual outFlags bits **1/2** this body + Filter/RangeCheck link; **accept-with-gaps** on gather/runtime.
