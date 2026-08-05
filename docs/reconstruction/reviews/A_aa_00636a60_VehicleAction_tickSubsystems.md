# Review A (reconstruction fidelity): `aa_00636a60` VehicleAction_tickSubsystems

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636a60` |
| **VA** | `0x00636a60` |
| **Canonical name** | `VehicleAction_tickSubsystems` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00636a60_VehicleAction_tickSubsystems.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WI-MOV-003: despite name, **`this` is hkVehicleFramework** (entity action handle **+0x40**), not VehicleAction. Call site `applyAction` `0x005987a2`: ECX=`[ESI+0x40]`. Body: optional profile stamp **"TtVehicle"**; **fw+8 += dt**; vtbl **+0x14** on self then **7 children** at **+0x14..+0x2c**; vtbl **+0x18** post-tick. Entity **+0x1a0** is 0xC handle: [0]=VehicleAction*, [4]=framework*, [8]=driverInput (PushDriveAxes → ctrl+0x20 throttle).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00636a60_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00636a60_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleAction_tickSubsystems.cpp` |
| Function record | `docs/reconstruction/functions/aa_00636a60_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `this = framework not VehicleAction` | High | WI-MOV-003 plate |
| `fw+8 accumulates dt` | High | Body |
| `vtbl+0x14 self + 7 children` | High | Plate |
| `vtbl+0x18 post-tick` | High | Plate |
| `Profile string TtVehicle` | High | DAT path |
| `Child component order identity` | Medium | Map to Wheels/Chassis/… |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| dt accumulate → tick self+children → post | Yes |
| No invent thr store here | Yes |

---

## 5. Gaps / open

1. Map child slots +0x14..+0x2c to framework components.
2. Rename away from VehicleAction_* when safe.

**Verdict:** **accept-with-gaps**
