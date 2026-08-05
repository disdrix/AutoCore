# Review B (skeptical / adversarial): `aa_004c41c0` Creature_GetPerception

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c41c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004c41c0_Creature_GetPerception.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | "Debug dump only / TargetAccuracy" scaffold | UI `"Perception"` + 12 callers; dump packs **P** not TargetAccuracy | **Falsified exclusive role** |
| 2 | Same as Theory (floor 1 only) | Live body has thr via vtbl+0x1DC; Theory is thr-less | **Stand as Combat twin** |
| 3 | Returns float accuracy probability | Returns **int**; thr can be **-100** | **Not probability** |
| 4 | Ghidra "leaf" means no calls | Classification ignores indirect CALL | **Indirect call sealed** |
| 5 | thr always 1 so -100 dead | Encode produces -100 when probe==0 | **Both values live code** |
| 6 | Name must be Object_GetTargetAccuracy* | Combat owns TargetAccuracy UI string; this unit is **Perception** | **Perception preferred** |
| 7 | Closed form max(score,thr) differs from expanded decompile | Integer equivalence holds for all short inputs + thr∈{1,-100} | **Equivalent** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX creature + ints | **High** | Wrong ABI port |
| Offsets + clamp | **High** | Wrong stat totals |
| thr encode 1/-100 | **High** | Wrong vehicle floor |
| Perception product name | **High** | Doc only |
| vtbl+0x1DC = "in vehicle" | **Probable** | Doc / design |
| Field names base/bonus | **Probable** | Doc only |

---

## 3. Cross-check against raw / bytes

```
raw ≡ live decompile ≡ clean expanded CF
entry: push esi; mov esi,ecx; mov ax,[esi+0x142]
bonus: movsx from [esi+0x14a]
thr:   call [edx+0x1DC]; neg; sbb; and 0x65; add -100
tails: score RET (pop esi; ret) | thr RET (pop esi; ret)
static callees empty; two identical indirect calls on separate paths
```

Do not port as Theory-style floor-1 leaf. Do not rename to TargetAccuracy (that string is Combat consumer path).

---

## 4. Surviving contract for AutoCore

```
// Perception stat for creature (character combat stats block)
int Creature_GetPerception(Creature* c):
  base  = (int16)c->field_142
  bonus = (int16)c->field_14a
  score = clamp_max(min(base, 200) + bonus, 250)
  thr   = MI_probe_vtbl_1DC(c) ? 1 : -100
  return max(score, thr)

// Port as integer Perception; keep thr path; do not CSE the second probe away
// without proving retail bit-identity is not required.
```

---

## 5. Open questions

1. DB column / wire names for the two shorts.
2. Product name of MI slot `+0x1DC`.
3. Live dump: Perception UI value == this formula for vehicle vs on-foot.
4. Interaction with Skill_NonCreatureCastAutoHit discarded-return residual.

**Verdict:** **accept-with-gaps** — adversarial kills debug-only and Theory-leaf misreads; Perception clamp+thr stands.
