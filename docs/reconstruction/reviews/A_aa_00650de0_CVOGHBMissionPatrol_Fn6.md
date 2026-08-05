# Review A (reconstruction fidelity): `aa_00650de0` CVOGHBMissionPatrol_Fn6

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650de0` |
| **VA** | `0x00650de0` |
| **Canonical name** | `CVOGHBMissionPatrol_Fn6` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00650de0_CVOGHBMissionPatrol_Fn6.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Mission-patrol companion helper: RTDynamicCast `*(this+0x18)` owner→Character; if cast ok and `CVOGReaction_ResolveObjectTarget(0, *(this+0x30), *(this+0x34))` succeeds → `EvaluatePendingObjectives(char, 0xb, 0,0,0)`. **No FailMission** path. Always tails `FUN_005083f0(param_2, param_3)` (HB cleanup/teardown helper family). Setup/teardown companion to Fn3 + Tick — not the full patrol formula alone.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00650de0_CVOGHBMissionPatrol_Fn6.md` |
| Annotated | `docs/reconstruction/raw/aa_00650de0_CVOGHBMissionPatrol_Fn6.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMissionPatrol_Fn6.cpp` |
| Function record | `docs/reconstruction/functions/aa_00650de0_CVOGHBMissionPatrol_Fn6.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Cast owner +0x18 → Character` | **High** | Entry |
| `ResolveObjectTarget(0, +0x30, +0x34)` | **High** | Same family as Fn3 |
| `On success EvalPendingObjectives type 0xb` | **High** | Progress |
| `No FailMission call` | **High** | Unlike Fn3 |
| `Always FUN_005083f0(param_2,param_3)` | **High** | Epilogue |
| `Skips eval if cast or resolve fails` | **High** | Silent miss |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Cast + resolve + optional eval + cleanup | **Yes** |
| No invented fail mission | **Yes** |

---

## 5. Gaps / open

1. FUN_005083f0 identity (stop/detach/destroy HB?).
2. When callers use Fn6 vs Fn3 vs Tick.
3. param_2/param_3 meanings for FUN_005083f0.
4. +0x30/+0x34 vs Fn3 HB[1] period field mapping.

**Verdict:** **accept-with-gaps**
