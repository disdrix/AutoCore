# Review A (reconstruction fidelity): `aa_005d7100` CVOGHBAIFollowVehicle_FireWeapons

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7100` |
| **VA** | `0x005d7100` |
| **Canonical name** | `CVOGHBAIFollowVehicle_FireWeapons` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d7100_CVOGHBAIFollowVehicle_FireWeapons.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Geometry-gated weapon fire for follow/driver AI: build **front/turret/rear** fire masks from relative target angles; **param_2 may-fire** flag (DoLogic always calls). Target pos vtbl+0x1a0 vs self pose; independent of drive/idle. Scoped `CVOGHBAIFollowVehicle::FireWeapons`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d7100_CVOGHBAIFollowVehicle_FireWeapons.md` |
| Annotated | `docs/reconstruction/raw/aa_005d7100_CVOGHBAIFollowVehicle_FireWeapons.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIFollowVehicle_FireWeapons.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d7100_CVOGHBAIFollowVehicle_FireWeapons.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Scoped string FireWeapons` | **High** | Present |
| `param_2 may-fire gate (char)` | **High** | Early if 0 |
| `Target pos from this+0x18 → +0xa0 vtbl+0x1a0` | **High** | Body |
| `Self pose +0xbc ground/air +0x84/+0xb0` | **High** | Shared offset pattern |
| `Relative angles → fire mask local_3c` | **High** | Front/turret/rear |
| `Decoupled from drive state` | **High** | DoLogic always calls |
| `FPU-heavy mask build` | **High** | Large residual |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| May-fire gate | **Yes** |
| Target/self geometry | **Yes** |
| Mask build + apply tail | **Yes** |

---

## 5. Gaps / open

1. Exact angle thresholds for front/turret/rear bits.
2. Weapon group apply callees.
3. may-fire false call sites vs always-true DoLogic.
4. Runtime fire mask vs facing.

**Verdict:** **accept-with-gaps**
