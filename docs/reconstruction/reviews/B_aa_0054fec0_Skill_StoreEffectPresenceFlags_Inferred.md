# Review B (skeptical / adversarial): `aa_0054fec0` Skill_StoreEffectPresenceFlags_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054fec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9E-B OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_0054fec0_Skill_StoreEffectPresenceFlags_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This unit **is** `Skill_ReevaluateForCurrentRank` | Same store pattern | **Falsified** — no Evaluate call; body only 57 B; different VA |
| 2 | Body **computes** presence bits | Confuse with `00627be0` | **Falsified** — single call to presence leaf; no field scans |
| 3 | Always ORs `4` into `+0x624` | Miss zero-`+0x620` path | **Falsified** — plain store when `+0x620==0` |
| 4 | Always sets `0x100000` on `+0x620` | Miss `+0x148` gate | **Falsified** — only when `+0x148==0` and `+0x620!=0` |
| 5 | `or al,4` is not full dword OR | Partial-byte trap | **Benign** — bit 2 of EAX is exactly `\|4` on the dword |
| 6 | Has active static callers | Assume used | **Overstated** — zero xrefs; may be dead twin of Reevaluate store |
| 7 | Name invents “Store/Presence” without evidence | Symbol inflation | **Role holds** — explicit store to `+0x624` of presence return; product noun open (`_Inferred`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Store CF + bit ops | **High** | Wrong targeting flags after rank change |
| ECX = skill | **High** | Corrupt wrong object |
| Not Evaluate | **High** | Double Evaluate if ported wrong |
| Live reachability of this VA | **Low** | Dead-code port noise only |
| Bit enum English | **Low** | Doc only |

---

## 3. Cross-check against raw ≡ live

```text
mask = Skill_ComputeEffectPresenceFlags_Inferred(skill)  // ECX=skill
if skill[+0x620] == 0:
  skill[+0x624] = mask
else:
  skill[+0x624] = mask | 4
  if skill[+0x148] == 0:
    skill[+0x620] |= 0x100000
```

Reevaluate path (not this body):

```text
Skill_EvaluateRankedElements(...)
// then same store as above (inlined)
```

---

## 4. Surviving contract for AutoCore

```
Skill_StoreEffectPresenceFlags_Inferred(skill):
  mask = Skill_ComputeEffectPresenceFlags_Inferred(skill)
  if skill.flags620 == 0: skill.flags624 = mask
  else:
    skill.flags624 = mask | 4
    if skill.gate148 == 0: skill.flags620 |= 0x100000
// Port as shared helper used by rank reeval (even if retail inlines).
// Do NOT merge with Evaluate. Do NOT always |4.
```

**Port tests:** `+0x620==0` → `+0x624` equals presence return; non-zero `+0x620` → bit2 set; `+0x148!=0` → leave `+0x620` bit20 clear.

**Verdict:** **accept-with-gaps** — adversarial Evaluate/always-|4 confusions **fail**; zero-caller residual remains.
