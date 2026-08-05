# Review A (reconstruction fidelity): `aa_00810360` Client_OnVehicleSwitchFailure

| Field | Value |
|---|---|
| **Stable ID** | `aa_00810360` |
| **VA** | `0x00810360` |
| **Canonical name** | `Client_OnVehicleSwitchFailure` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00810360_Client_OnVehicleSwitchFailure.md` |
| **System tag** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/Client_OnVehicleSwitchFailure.cpp` |
| Raw | `docs/reconstruction/raw/aa_00810360_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Vehicle chassis switch failures (inventory fit / vehicle not found). Strings include vehicle not found in inventory / chassis inventory fit.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Vehicle not found / fit failure strings | High | Strings |
| Chassis switch failure UX | High | Purpose |
| Client toast only | High | No vehicle spawn |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Map switch-fail reason → toast | Yes |

---

## 4. Gaps

1. Full reason enum for chassis switch.

**Verdict:** **accept-with-gaps**
