# Review B (skeptical / adversarial): `aa_004c4140` Creature_GetTheory

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4140` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004c4140_Creature_GetTheory.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | "Debug dump only" scaffold name | 10 callers: accuracy, UI Theory, req gates, pool math | **Falsified as exclusive role** |
| 2 | Returns float accuracy probability | Returns **int** [1,250]; parent casts to float for bonus | **Not probability** — raw Theory points |
| 3 | Same formula as Combat getter | Combat/Perception have vehicle vfunc floor; Theory only [1,250] | **Stand as simpler sibling** |
| 4 | Base always ≤200 in data so cap dead | Cap is real code path (`cmp ax,200`) | **Live code** — keep |
| 5 | Floor 1 means "missing stat → 1 Theory" | Yes: sum < 2 → 1 | **Stand** |
| 6 | Name must be AccuracyBonus | UI string is **"Theory"**; accuracy is a *consumer* | **Theory preferred** |
| 7 | Closed form differs from expanded decompile | Integer `clamp(min(b,200)+x,1,250)` matches all branches | **Equivalent** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX creature + ints | **High** | Wrong ABI port |
| Offsets + clamp | **High** | Wrong stat totals |
| Theory product name | **High** | Doc only |
| Accuracy bonus = Theory points as float | **High** for caller path | Wrong hit curve if different short used |
| Field names base/bonus | **Probable** | Doc only |
| No vehicle min is complete product truth | **Medium** residual | If decompiler hid call (unlikely — leaf, no CALL bytes in body) |

---

## 3. Cross-check against raw / bytes

```
raw ≡ live decompile ≡ clean expanded CF
entry: mov ax, [ecx+0x140]
bonus: movsx from […+0x148]
tails: mov eax,1; ret  |  mov eax,250; ret  |  sum; ret
no CALL instructions in body → leaf sealed without disassemble_bytes
```

Clean closed-form comment is documentation; production plate keeps decompiler-shaped branches for bit-exact CF review.

---

## 4. Surviving contract for AutoCore

```
// Theory stat for creature (character combat stats block)
int Creature_GetTheory(Creature* c):
  base  = (int16)c->field_140
  bonus = (int16)c->field_148
  return clamp(min(base, 200) + bonus, 1, 250)

// Accuracy chain (parent):
//   if attacker has creature: atkBonus = (float)Creature_GetTheory(creature)
//   else atkBonus = 0
```

Port as integer Theory; do not rename to "accuracy chance". Do not add vehicle floor without new evidence on **this** VA.

---

## 5. Open questions

1. DB column / wire names for the two shorts.
2. Design reason Theory lacks Combat/Perception vehicle floor.
3. Live dump: Theory UI value == this formula for modified gear.
4. Interaction of Theory with accuracy float scale (is +Theory meant as raw points into score?).

**Verdict:** **accept-with-gaps** — adversarial kills debug-only and float-probability misreads; Theory clamp leaf stands.
