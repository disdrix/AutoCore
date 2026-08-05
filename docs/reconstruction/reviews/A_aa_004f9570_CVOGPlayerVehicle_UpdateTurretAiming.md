# Review A (reconstruction fidelity): `aa_004f9570` CVOGPlayerVehicle_UpdateTurretAiming

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f9570` |
| **VA** | `0x004f9570` |
| **Canonical name** | `CVOGPlayerVehicle_UpdateTurretAiming` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004f9570_CVOGPlayerVehicle_UpdateTurretAiming.md` |
| **System tag** | `vehicle-combat` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Clean | `docs/reconstruction/reconstructed-exact/CVOGPlayerVehicle_UpdateTurretAiming.cpp` |
| Raw | `docs/reconstruction/raw/aa_004f9570_*` (annotated if present) |
| Reviews dir | `docs/reconstruction/reviews/` |

**Purpose (from clean plate / body):** Player vehicle turret aim update. Early-outs if turret handles +0x340/+0x344 null; mode/flag checks including nested +0x4ce. Samples vehicle orientation via *(+0x48) vtbl+0xc (rows at +0x80..+0x98). Invokes turret object methods vtbl+0x18/+0x14 on both handles. Optional multi-kill blend path using g_flMultiKillCountBlend with accessory fields. Large float-local function; client presentation / local aim — not server hit validation.

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Requires +0x340 and +0x344 non-null | High | Early returns |
| Vehicle basis via +0x48 vfunc +0xc | High | Loads +0x80..+0x98 |
| Turret vtbl +0x18 / +0x14 apply | High | Calls |
| g_flMultiKillCountBlend accessory path | Medium | Body |
| Multiple early-return gates (11 returns) | High | CF stats |
| Client aim/presentation heavy | Medium | No wire write in plate |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Gate nulls → sample vehicle xform → push to turret handles | Yes |

---

## 4. Gaps

1. Full aim math (pitch/yaw limits, mouse vs target).
2. Identity of objects at +0x340/+0x344.
3. Whether any aim is networked from this function.

**Verdict:** **accept-with-gaps**
