# Review A (reconstruction fidelity): `aa_0060e3d0` CVOGObjectiveRequirement_Patrol_InitActive

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060e3d0` |
| **VA** | `0x0060e3d0` |
| **Canonical name** | `CVOGObjectiveRequirement_Patrol_InitActive` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0060e3d0_CVOGObjectiveRequirement_Patrol_InitActive.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On activate: FUN_004de760(state,0); if AutoFail-like flag **req+0x18** and continent ready **+0x7e**, allocate 0x40, construct heartbeat via FUN_00650d30 (CVOGHBMissionPatrol), enqueue on continent HB list +0xe4ec, Start.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `raw/aa_0060e3d0_CVOGObjectiveRequirement_Patrol_InitActive.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Patrol_InitActive.cpp` |
| HB | `CVOGHBMissionPatrol family 0x00650d30+` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| FUN_004de760 prologue always | **High** | raw |
| Gate flag +0x18 and continent +0x7e | **High** | raw |
| operator_new(0x40) + FUN_00650d30 | **High** | raw |
| Enqueue +0xe4ec + CVOGHBBase_Start | **High** | raw |
| SEH frame present | **High** | frame setup |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Prologue | **Yes** |
| Gate | **Yes** |
| Alloc/ctor/enqueue/start | **Yes** |

---

## 5. Gaps

1. Confirm +0x18 is AutoFail (matches GetFlags dump) vs AutoComplete.
2. FUN_004de760 exact role (RTTI/init).
3. Full HB tick contract.

**Verdict:** accept-with-gaps.
