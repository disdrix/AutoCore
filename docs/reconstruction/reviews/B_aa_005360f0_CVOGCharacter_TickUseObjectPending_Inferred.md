# Review B (skeptical / adversarial): `aa_005360f0` CVOGCharacter_TickUseObjectPending_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005360f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005360f0_CVOGCharacter_TickUseObjectPending_Inferred.md` |
| **Agent** | W26-S OWN-ONLY |
| **Verdict** | **accept** on CF/ABI/timer/commit; product English remains Probable only |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as ResolveUseObjectPending | Different entry; only ticks timer; calls Resolve | **Falsified** |
| 2 | Cancels (commit=0) on expiry | Bytes `push 1` | **Falsified** |
| 3 | Always runs | Triple gate; returns 0 when inactive | **Falsified** always |
| 4 | cdecl / ECX unused | `ret 4` + ECX-relative loads | **Falsified** |
| 5 | Returns void | AL bool paths | **Falsified** |
| 6 | Multiplies dt or clamps | Single `subss` only | **Falsified** multiply claim |
| 7 | Many callers | Only `00930040` CODE xref | **Survives** as single caller |
| 8 | Arms the timer | Only decrements; no store of initial duration | **Falsified** arm claim |
| 9 | Clean invents EvaluatePending | No direct call; only Resolve | **Falsified** invent |
| 10 | Dead scaffold | Live caller + sealed sibling | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Timer offset `+0xc80` | **High** | Wrong pending slot |
| Commit polarity 1 | **High** | Cancel vs complete desync |
| Bool thiscall ret 4 | **High** | ABI break |
| Sole caller frame-dt | **High** | Wrong dt source |
| Product English | **Tentative** | Docs only |

---

## 3. Cross-check against raw / image

### Spine

```
if !vbase or !pending or timer<=0: return 0
timer -= dt
if timer<=0: Resolve(commit=1)
return 1
```

### Image seals

| Fact | Pattern |
|---|---|
| Vbase load | `8B 41 04 8B 50 04 8B 84 0A A8 00 00 00` |
| Flag gate | `80 B9 7C 0C 00 00 00` |
| Timer COMISS | `0F 2F 89 80 0C 00 00` |
| Sub dt | `F3 0F 5C 44 24 04` |
| Commit | `6A 01 E8 …` → `00535ed0` |
| Epilogues | `B0 01 C2 04 00` / `32 C0 C2 04 00` |

### Contrast sibling `FUN_00535ed0`

Resolve clears pending and may EvaluatePending kind **10** or UI **0x14**. This unit **only** ticks and optionally invokes Resolve with commit. Do **not** alias.

Clean preserves spine. **No invented EvaluatePending. No cancel polarity.**

---

## 4. Surviving contract for AutoCore

```
// Per-frame pending use-object countdown
bool TickUseObjectPending(Character ch, float dt):
  if not ch.HasVBase() or not ch.UsePendingActive(+0xc7c) or ch.Timer(+0xc80) <= 0:
    return false
  ch.Timer -= dt
  if ch.Timer <= 0:
    ResolveUseObjectPending(ch, commit=true)
  return true
```

Port must use the same gate order and commit-on-expiry polarity; do not cancel on timer zero.
