# Review A (reconstruction fidelity): `aa_005002d0` Vehicle_CalcMaxHitPoints

| Field | Value |
|---|---|
| **Stable ID** | `aa_005002d0` |
| **VA** | `0x005002d0` |
| **Canonical name** | `Vehicle_CalcMaxHitPoints` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005002d0_Vehicle_CalcMaxHitPoints.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Player vehicle max HP formula. With owner (vfunc **+0x1dc**): race=chassis+**0x531**, class=chassis+**0x532**, level=owner vfunc **+0x27c**; raceTerm = level × `g_flVehicleHpRaceMult[race]` + base **60**; tech = `Character_GetTechForPoolCalcs`; basePool = tech × ~**3** + classMult[class] × raceTerm; armorFactor from armor@**+0x254** field **+0xb4**; chassisArmorAdd short@**+0x1d8** (INFERRED); ceil(armor + basePool×(1+hpPct@**+0xe4**) + hpFlat@**+0xe8** + chassisArmorAdd). Fallback NPC clone path vfunc **+0x1d8** else **+0x244**. AutoCore: `VehicleHitPointCalculator.CalculatePlayerMaxHp`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005002d0_Vehicle_CalcMaxHitPoints.md` (or `aa_005002d0_FUN_005002d0.md`) |
| Annotated | `docs/reconstruction/raw/aa_005002d0_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_CalcMaxHitPoints.cpp` |
| Function record | `docs/reconstruction/functions/aa_005002d0_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Player path race/class/level formula` | High | Plate + body |
| `Base 60 + race mult tables` | High | Plate |
| `Armor@+0x254 +0xb4 factor` | High | Plate |
| `hpPct +0xe4 / hpFlat +0xe8` | High | Plate |
| `NPC fallback paths` | High | Plate |
| `chassisArmorAdd +0x1d8` | Medium | INFERRED |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Owner present → player formula → ceil; else fallback | Yes |
| No invented shield math | Yes |

---

## 5. Gaps / open

1. Seal race/class mult table addresses.
2. Confirm +0x1d8 chassisArmorAdd.

**Verdict:** **accept-with-gaps**
