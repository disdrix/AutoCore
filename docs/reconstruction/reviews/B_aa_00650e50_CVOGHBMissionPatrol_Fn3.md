# Review B (skeptical / adversarial): `aa_00650e50` CVOGHBMissionPatrol_Fn3

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650e50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00650e50_CVOGHBMissionPatrol_Fn3.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on packed gate + out token |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always progresses patrol | **Falsified — cast/hash/equality/resolve gates** |
| 2 | No fail path | **Falsified — FailMission** |
| 3 | Distance fully in Tick only | **Falsified — ResolveObjectTarget here** |
| 4 | Finished field names for +0x24 pack | **Overstated** |
| 5 | Type 0xb definitely XP | **Overstated — objective eval code** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Progress vs FailMission split | High | Wrong mission outcome |
| EvaluatePendingObjectives 0xb | High | Wrong objective class |
| ResolveObjectTarget gate | High | Progress out of range |
| Packed equality +0xfc | Tentative | Always fail/always pass |
| Out token DAT_00af5174 | Tentative | List mis-status |

---

## 3. Cross-check against raw

```
cast owner Character else out=token;
hash mission; if key hit:
  if pack==char+0xfc && ResolveObjectTarget: EvalPending(0xb); Reschedule; return
  else FailMission(mission+0x14c)
out=token.
Clean ≡ raw CF; field names partial.
```

---

## 4. Surviving contract for AutoCore

```
MissionPatrol_Fn3:
  distance/target resolve + mission fail/progress sibling of Tick
  success → EvaluatePendingObjectives type 0xb + reschedule
  failure → FailMission — do not soft-ignore miss
  pair with Fn6 + Tick; AutoCore AutoPatrol must honor fail conditions
  HB +0x24 pack is NOT combat heat semantics here
```

---

## 5. Open questions

1. Name DAT_00af5174 and char+0xfc.
2. Seal HB extension layout beyond base 0x28.
3. Live: progress vs fail when out of radius.
4. Cross-check EvaluatePendingObjectives dual for type 0xb.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on packed gate + out token
