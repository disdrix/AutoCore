# Review A (reconstruction fidelity): `aa_004f3870` Vehicle_GetPowerRegenRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3870` |
| **VA** | `0x004f3870` |
| **Canonical name** | `Vehicle_GetPowerRegenRate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f3870_Vehicle_GetPowerRegenRate.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept** |

---

## 1. Purpose

Thin combat-pool getter: raw power points added each regen pulse from equipped power plant. If `pPowerPlant` (vehicle **+0x268**) non-null, return plant **nPowerRegenRate** (short **plant+0xB8**); else return **1**. UI display multiplies by `g_flDisplayRateScaleOneThird` as MKz/sec — **not** applied here. Called from `VehicleCombatPool_OnTick`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f3870_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004f3870_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_GetPowerRegenRate.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f3870_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Plant short +0xB8 is power regen` | High | Combat-pool map + clean |
| `Plant ptr vehicle+0x268` | High | Session RE map |
| `No plant → return 1` | High | Body |
| `Display scale not in body` | High | Comment-only UI note |
| `Does not touch creature power fields` | High | Pure vehicle plant read |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| plant? plant.nPowerRegen : 1 | Yes |
| No invent scale multiply | Yes |

---

## 5. Gaps / open

1. Seal plant struct field name plate.
2. Confirm creature power apply is OnTick not this getter.

**Verdict:** **accept**
