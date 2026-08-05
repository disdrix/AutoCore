# Review B (skeptical / adversarial): `CVOGObjectiveRequirement_Patrol_InitActive` @ `0x0060e3d0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e3d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0060e3d0_CVOGObjectiveRequirement_Patrol_InitActive.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always starts HB | **Falsified — gated on +0x18 and continent +0x7e** |
| 2 | +0x18 is AutoComplete | **Likely wrong — GetFlags maps AutoComplete to +0x10, AutoFail to +0x18** |
| 3 | No-op when new fails | **Partial — enqueues null? Start(null) risk if not checked** |
| 4 | Server must mirror HB | **Overstated — client range HB; server has MissionPatrolProgress** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate polarity | High | Missing auto-fail HB |
| HB size 0x40 / ctor | High | Heap smash |
| AutoFail vs AutoComplete field | Medium | Wrong mode |

---

## 3. Surviving contract for AutoCore

```
Patrol_InitActive(req, stateObj):
  FUN_004de760(stateObj, 0)
  if req[+0x18] && continent[+0x7e]:
    hb = CVOGHBMissionPatrol_ctor(stateObj, req) or null
    enqueue continent HB list; Start(hb)
```

---

## 4. Open questions

1. Null-safe Start path.
2. Link HB tick dual reviews.
3. Server does not enqueue this client HB.

**Verdict:** accept-with-gaps.
