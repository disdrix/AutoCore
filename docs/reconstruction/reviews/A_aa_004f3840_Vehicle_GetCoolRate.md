# Review A (reconstruction fidelity): `aa_004f3840` Vehicle_GetCoolRate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3840` |
| **VA** | `0x004f3840` |
| **Canonical name** | `Vehicle_GetCoolRate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f3840_Vehicle_GetCoolRate.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept** |

---

## 1. Purpose

Thin combat-pool getter: heat cool amount applied each regen pulse. Returns **plant.nCoolRate + vehicle.nCoolRateAdjust** when plant present; else **nCoolRateAdjust + 1**. Plant cool short at **plant+0xBA**; vehicle adjust short **+0x1E4** (session map). Used by OnTick with `Vehicle_AddHeat` (negative delta) and slowed when `Vehicle_IsAnyWeaponFiring`. UI scale one-third is display-only.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f3840_*.md` |
| Annotated | `docs/reconstruction/raw/aa_004f3840_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_GetCoolRate.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f3840_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Cool = plant.nCoolRate + vehicle adjust` | High | Clean body |
| `No plant → adjust + 1` | High | Body |
| `plant cool +0xBA / adjust +0x1E4` | High | Combat-pool map |
| `Firing slow is caller-side` | High | IsAnyWeaponFiring + OnTick |
| `Display scale not applied` | High | Comment only |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| plant? plant.cool+adjust : adjust+1 | Yes |
| No heat write here | Yes |

---

## 5. Gaps / open

1. Confirm adjust signedness (can be negative?).
2. Document overheat cool frac interaction is OnTick-side.

**Verdict:** **accept**
