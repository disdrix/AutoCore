# Review A (reconstruction fidelity): `aa_007f4c50` DB_ReadPowerPlantSpecific

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f4c50` |
| **VA** | `0x007f4c50` |
| **Canonical name** | `DB_ReadPowerPlantSpecific` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007f4c50_DB_ReadPowerPlantSpecific.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Load **tPowerPlant** row into `SPowerPlant_Specific` for a clonebase ID. `__thiscall(this, pDbContext, pOutSpecific)`. SQL shape: `SELECT intHeatMaximum, intPowerMaximum, sinPowerRegenRate, sinCoolRate FROM tPowerPlant WHERE IDCloneBase=?`. Out struct **0xC**: `+0` HeatMax, `+4` PowerMax, `+8` PowerRegenRate short, `+A` CoolRate short — copied onto clonebase plant fields used at **+0xB0..+0xBA** (Vehicle regen getters). DBReader COM/stream path with many `FUN_004231d0` binds; inactive this → error `-0x7fffbffc`. Large residual COM scaffolding + unreachable blocks.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007f4c50_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007f4c50_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DB_ReadPowerPlantSpecific.cpp` |
| Function record | `docs/reconstruction/functions/aa_007f4c50_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Four-column power plant specific row | High | Plate SELECT |
| Out struct 0xC layout | High | Plate |
| Clonebase plant +0xB0..+0xBA consumers | High | Vehicle regen docs |
| Inactive this early error | High | Clean |
| DBReader error string path | High | Embedded string |
| Full COM bind order bit-exact | Medium | FUN_* residual |
| Unreachable blocks stripped | Medium | Ghidra warnings |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| guard → open reader → bind columns → fill out → cleanup | Yes |
| Does not equip plant onto vehicle | Yes |

---

## 5. Gaps / open

1. Seal clonebase destination offsets for each of 4 fields.
2. Map sin* column storage (float vs short) on wire vs struct.
3. Bit-exact DB path deferred.

**Verdict:** **accept-with-gaps**
