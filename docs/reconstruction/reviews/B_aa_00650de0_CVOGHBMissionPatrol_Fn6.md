# Review B (skeptical / adversarial): `aa_00650de0` CVOGHBMissionPatrol_Fn6

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650de0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00650de0_CVOGHBMissionPatrol_Fn6.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on FUN_005083f0 + caller roles |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same as Fn3 including FailMission | **Falsified — no FailMission** |
| 2 | No progress call | **Falsified — EvalPending 0xb** |
| 3 | No cleanup tail | **Falsified — FUN_005083f0 always** |
| 4 | Finished FUN_005083f0 | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Soft miss (no fail) | High | Mission stuck vs failed |
| Type 0xb progress | High | Wrong objective |
| Always cleanup tail | High | Leaked HB if skipped |
| FUN_005083f0 | Tentative | Wrong teardown |

---

## 3. Cross-check against raw

```
cast owner; if ok && ResolveObjectTarget: EvalPending(0xb);
FUN_005083f0(p2,p3) always.
Clean ≡ raw CF.
```

---

## 4. Surviving contract for AutoCore

```
MissionPatrol_Fn6:
  softer companion: progress if target resolves, never FailMission here
  always runs FUN_005083f0 teardown/helper with param_2/3
  do not treat as complete patrol AI — pair Tick + Fn3
  AutoCore: distinguish fail-on-miss (Fn3) vs soft path (Fn6)
```

---

## 5. Open questions

1. Name FUN_005083f0.
2. Caller graph: which mission state invokes Fn3 vs Fn6.
3. Live teardown order with Tick.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on FUN_005083f0 + caller roles
