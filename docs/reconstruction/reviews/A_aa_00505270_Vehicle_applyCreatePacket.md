# Review A (reconstruction fidelity): `aa_00505270` Vehicle_applyCreatePacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_00505270` |
| **VA** | `0x00505270` |
| **Canonical name** | `Vehicle_applyCreatePacket` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00505270_Vehicle_applyCreatePacket.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Apply CreateVehicle / ghost-create packet fields onto vehicle runtime (`this` relative base with negative offsets in decompile). Copies flags (**pkt+0x151/+0x152**), resolves hardpoint/weapon template fields, may invoke equip nest helpers, and seeds combat/visual state. Sibling of create path with `Vehicle_EquipFromCreate`. Large CF (~187 body lines, if×22). Residual: decompiler uses relative `param_1 - N` bases — absolute field map incomplete.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00505270_Vehicle_applyCreatePacket.md` (or `aa_00505270_FUN_00505270.md`) |
| Annotated | `docs/reconstruction/raw/aa_00505270_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_applyCreatePacket.cpp` |
| Function record | `docs/reconstruction/functions/aa_00505270_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Create-packet apply onto vehicle` | High | Name + create pipeline |
| `Copies pkt flag bytes +0x151/+0x152` | High | Body stores |
| `Nested hardpoint/template resolve` | High | Multi if CF |
| `Pairs EquipFromCreate / create lifecycle` | High | Call graph |
| `Absolute field map vs relative bases` | Medium | Decomp relative |
| `Full 0x201D field coverage` | Medium | Partial |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Read packet → write vehicle fields → nested setup | Yes |
| No invented drive tick | Yes |

---

## 5. Gaps / open

1. Seal absolute offsets for all pkt→entity maps.
2. Which fields EquipFromCreate owns vs this body.
3. Ghost vs local create differences.

**Verdict:** **accept-with-gaps**
