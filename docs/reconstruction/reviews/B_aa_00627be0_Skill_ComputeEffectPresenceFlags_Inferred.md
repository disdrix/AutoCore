# Review B (skeptical / adversarial): `aa_00627be0` Skill_ComputeEffectPresenceFlags_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00627be0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9D-E OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_00627be0_Skill_ComputeEffectPresenceFlags_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Body **writes** `skill+0x624` | Confuse with Reevaluate store | **Falsified** — leaf return only; stores are in callers |
| 2 | Is `Skill_EvaluateRankedElements` | Rank reeval parent conflation | **Falsified** — no table lookup; pure presence scan |
| 3 | Scans a **separate def blob**, not skill | Offsets collide with runtime `+0x620` | **Falsified at call sites** — `mov ecx,esi` with ESI=pSkill; same object has `+0x620` in caller |
| 4 | Bit `0x400` set only once | Two OR sites | **Overstated if assumed single** — two independent float groups both OR `0x400` (benign) |
| 5 | Bit `0x20000` only from floats | Miss int+float gate | **Falsified if missed** — also `(+0x134!=0 && +0x138!=0)` |
| 6 | Return is pure computed flags | Ignore base `+0xc` | **Falsified** — always `*(+0xc) \| flags` |
| 7 | Targeting-mode full enum sealed here | `+0x624` docs | **Overstated** — this unit only builds presence mask; enum English remains open |
| 8 | Name invents “Presence” without evidence | Symbol inflation | **Role holds** — every bank is non-zero test; product noun open (`_Inferred`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf CF + bit map | **High** | Wrong skill flag port |
| ECX = skill | **High** | Scan wrong object |
| `+0x624` store is caller | **High** | Double-write / wrong owner |
| Bank combat English | **Low** | Doc only |
| Base `+0xc` semantics | **Med** | Spurious static bits |

---

## 3. Cross-check against raw ≡ live

```text
flags = 0
scan +0x60[6] i16      → | 0x1
scan +0x6c[6] i16      → | 0x8
scan +0xa8[6] f32      → | 0x80
scan +0x78/+0x90 pairs → | 0x100
scan +0x84/+0x9c pairs → | 0x200
misc floats            → | 0x400
+0xd0..+0xd8 i16       → | 0x40
+0x38/+0x13c           → | 0x20
+0xda char             → | 0x10
+0x3c                  → | 0x2
+0x40                  → | 0x8000
+0x10c..+0x118         → | 0x10000
+0x124/+0x128          → | 0x20000
+0x12c/+0x130          → | 0x400
(+0x134 && +0x138)     → | 0x20000
return *(+0xc) | flags
```

Caller post-process (not this body):

```text
mask = Skill_ComputeEffectPresenceFlags_Inferred(skill)
if skill[+0x620] == 0: skill[+0x624] = mask
else:
  skill[+0x624] = mask | 4
  if skill[+0x148] == 0: skill[+0x620] |= 0x100000
```

---

## 4. Surviving contract for AutoCore

```
Skill_ComputeEffectPresenceFlags_Inferred(skill):
  return skill.baseFlags(+0xc) | presence_bits_from_nonzero_effect_fields
// Port: pure function of skill fields; no side effects.
// After EvaluateRankedElements / rank change: recompute then assign +0x624
//   (with caller |4 when +0x620 nonzero).
```

**Port tests:** all-zero effects → return equals `*(+0xc)` only; single non-zero short at `+0x60` → bit0 set; do not store `+0x624` inside this function.

**Verdict:** **accept-with-gaps** — adversarial store/Evaluate/def-blob confusions **fail**; bank English residual remains.
