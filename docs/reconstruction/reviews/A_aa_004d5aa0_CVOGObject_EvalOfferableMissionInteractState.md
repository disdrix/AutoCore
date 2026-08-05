# Review A (reconstruction fidelity): `aa_004d5aa0` CVOGObject_EvalOfferableMissionInteractState

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d5aa0` |
| **VA** | `0x004d5aa0` |
| **Canonical name** | `CVOGObject_EvalOfferableMissionInteractState` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d5aa0_CVOGObject_EvalOfferableMissionInteractState.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Walk global mission table for missions matching this object NPC CBID + continent; skip completed/active; if `CheckMissionRequirements` returns 0 (eligible), return **6** (core==0) or **7** (core!=0) from mission+0x169; else 0. Uses hash traversal locks.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d5aa0_CVOGObject_EvalOfferableMissionInteractState.md` |
| Annotated | `docs/reconstruction/raw/aa_004d5aa0_CVOGObject_EvalOfferableMissionInteractState.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_EvalOfferableMissionInteractState.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d5aa0_CVOGObject_EvalOfferableMissionInteractState.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Hash traverse with lock byte +0x1d` | **High** | Body |
| `Skip completed via HasCompletedMission` | **High** | Body |
| `Match CBID this+0xa8→+0x34 and continent +0xfc` | **High** | Body |
| `Active mission → EvalActiveObjectiveInteractState continue` | **High** | Body |
| `Eligible → 6 or 7 from CoreMission@+0x169` | **High** | (*(char*)+0x169!=0)+6 |
| `Requirements fail → state 0` | **High** | Body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Traverse + filters + return states | **Yes** |

---

## 5. Gaps / open

1. unaff_EDI passed to CheckMissionRequirements — residual.
2. Full mission table structure open.

**Verdict:** **accept-with-gaps**
