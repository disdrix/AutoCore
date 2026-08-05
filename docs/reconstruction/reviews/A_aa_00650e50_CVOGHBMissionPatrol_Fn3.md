# Review A (reconstruction fidelity): `aa_00650e50` CVOGHBMissionPatrol_Fn3

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650e50` |
| **VA** | `0x00650e50` |
| **Canonical name** | `CVOGHBMissionPatrol_Fn3` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00650e50_CVOGHBMissionPatrol_Fn3.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Mission-patrol HB helper: RTDynamicCast owner→Character; if null write `DAT_00af5174` to out and return. Load packed dword from HB debounce/pad bytes (+0x24..); compare to char dual-base `...+0xa8 → +0xfc` value; `CNDHash_LookupByKey(char+0x548, key from HB extension)`; on hit: if packed==charVal **and** `CVOGReaction_ResolveObjectTarget(0, HB+period fields)` succeeds → `EvaluatePendingObjectives(char, 0xb, 0,0,0)` + `RescheduleAfterFire`; else `CVOGReaction_FailMission` from mission block `+0x14c`. Miss paths write `DAT_00af5174`. Complements Tick TFID gate — **distance/target resolve + fail mission** live here.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00650e50_CVOGHBMissionPatrol_Fn3.md` |
| Annotated | `docs/reconstruction/raw/aa_00650e50_CVOGHBMissionPatrol_Fn3.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBMissionPatrol_Fn3.cpp` |
| Function record | `docs/reconstruction/functions/aa_00650e50_CVOGHBMissionPatrol_Fn3.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `RTDynamicCast owner → CVOGCharacter` | **High** | Entry |
| `Null cast → *out=DAT_00af5174 return` | **High** | Early |
| `Packed HB +0x24.. compared to char ...+0xfc` | **High** | Equality gate |
| `CNDHash_LookupByKey(char+0x548, HB key)` | **High** | Mission lookup |
| `ResolveObjectTarget(0, HB period fields) gate` | **High** | Target present |
| `Success: EvaluatePendingObjectives(..., 0xb, ...)` | **High** | Type 0xb progress |
| `Success: RescheduleAfterFire` | **High** | Re-arm HB |
| `Fail path: FailMission from hash+0x14c` | **High** | Mission fail |
| `Default *out=DAT_00af5174` | **High** | Status token |
| `pOutNextDelayMs residual / decomp framing` | **Probable** | Unaff/uninit note |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Cast + hash + gates + progress/fail | **Yes** |
| No invented objective type beyond 0xb | **Yes** |

---

## 5. Gaps / open

1. DAT_00af5174 meaning (status / next delay token).
2. What packed +0x24 dword encodes (not combat heat debounce reuse).
3. char ...+0xfc field name.
4. Whether Tick or Fn3 is primary progress authority.
5. ResolveObjectTarget args from HB[1] layout (period fields may be mis-typed extension).

**Verdict:** **accept-with-gaps**
