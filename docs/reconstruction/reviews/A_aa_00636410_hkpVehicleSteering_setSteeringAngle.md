# Review A (reconstruction fidelity): `aa_00636410` hkpVehicleSteering_setSteeringAngle

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636410` |
| **VA** | `0x00636410` |
| **Canonical name** | `hkpVehicleSteering_setSteeringAngle` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00636410_hkpVehicleSteering_setSteeringAngle.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept** |

---

## 1. Purpose

Trivial `__thiscall` float setter: **`*(this+0x50) = param_2`**. Called from `VehicleAction_applyAction` mode-**0x02** path with ramped **VA+0x28** (and from related setup FUN_00597ec0). Despite older plate speculation about SpeedLimiter, verified applyAction treats this as **steering-angle input store** into the steering component, not AbsoluteTopSpeed math. 45-line clean.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00636410_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00636410_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkpVehicleSteering_setSteeringAngle.cpp` |
| Function record | `docs/reconstruction/functions/aa_00636410_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Single store this+0x50 = float` | High | Body |
| `Caller applyAction passes VA+0x28` | High | Verified note |
| `Not SpeedLimiter implementation` | High | No math in body |
| `Full consumer read sites of +0x50` | Medium | Need hkDefaultSteering_update |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| assign +0x50; return | Yes |
| No invent limiter formula | Yes |

---

## 5. Gaps / open

1. Confirm hkDefaultSteering_update reads +0x50 / desc+0x14 path.
2. Rename any leftover SpeedLimiter comments.

**Verdict:** **accept**
