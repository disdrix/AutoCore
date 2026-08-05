# Review A (reconstruction fidelity): `aa_007c6110` Drive_tVehicleTemplate

| Field | Value |
|---|---|
| **Stable ID** | `aa_007c6110` |
| **VA** | `0x007c6110` |
| **Canonical name** | `Drive_tVehicleTemplate` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007c6110_Drive_tVehicleTemplate.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **row loader** for `//tVehicleTemplate/row` — vehicle template definitions (chassis/drive params). ~547-line DBReader with many unreachable blocks. Feeds vehicle create / template apply paths (`Drive_LoadOneVehicleTemplate_*`, equip pipelines).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007c6110_*.md` |
| Annotated | `docs/reconstruction/raw/aa_007c6110_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Drive_tVehicleTemplate.cpp` |
| Function record | `docs/reconstruction/functions/aa_007c6110_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| tVehicleTemplate loader | High | Embedded path |
| Vehicle template data bring-up | High | Domain |
| Large DBReader | High | Body size |
| Full column map sealed | Medium | Residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| bind/read vehicle template rows | Yes |

---

## 5. Gaps / open

1. Seal columns used by Havok framework build descriptors.
2. Link to Vehicle_buildHavokVehicleFramework consumers.

**Verdict:** **accept-with-gaps**
