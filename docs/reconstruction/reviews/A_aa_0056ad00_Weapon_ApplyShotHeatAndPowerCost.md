# Review A (reconstruction fidelity): `aa_0056ad00` Weapon_ApplyShotHeatAndPowerCost

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056ad00` |
| **VA** | `0x0056ad00` |
| **Canonical name** | `Weapon_ApplyShotHeatAndPowerCost` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0056ad00_Weapon_ApplyShotHeatAndPowerCost.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Applies **shot heat + optional power cost** for player-vehicle weapons. Only when owner object type **0xE** (player vehicle path): (1) `Weapon_CanFireHeatCheck` — fail → return 0; (2) if weapon short **+0xD6** > 0, debit creature power via vtbls (abort if power ≤ cost); (3) `Vehicle_AddHeat(sinHeat at weapon +0xD4)`. Returns **1** applied, **0** blocked. Non-0xE owners fall through to return **1** without cost.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0056ad00_*.md` |
| Annotated | `docs/reconstruction/raw/aa_0056ad00_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Weapon_ApplyShotHeatAndPowerCost.cpp` |
| Function record | `docs/reconstruction/functions/aa_0056ad00_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gated to owner type 0xE | High | Body |
| CanFireHeatCheck before costs | High | Body |
| Power cost weapon+0xD6 optional | High | Body |
| Vehicle_AddHeat(weapon+0xD4) | High | Body |
| Return 0 blocked / 1 ok | High | Body |
| Non-0xE skips costs returns 1 | High | Fallthrough |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| if type0xE: heatcheck → maybe power → AddHeat; return 0|1 | Yes |

---

## 5. Gaps / open

1. Confirm power vtbl +0x210 / debit +0xb0 identities.
2. sinHeat units vs MaxHeat scale.

**Verdict:** **accept-with-gaps**
