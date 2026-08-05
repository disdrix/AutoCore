# Review A (reconstruction fidelity): `aa_004fb660` Vehicle_createVehicleAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fb660` |
| **VA** | `0x004fb660` |
| **Canonical name** | `Vehicle_createVehicleAction` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fb660_Vehicle_createVehicleAction.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Create vehicle action bundle at **entity+0x1a0** = new **0xC** block: `[0]=VehicleAction*`, `[4]=hkVehicleFramework*`, `[8]=driverInput` from `FUN_005fe020`. Builds framework via `Vehicle_buildHavokVehicleFramework`; `VehicleAction_ctor(entity, rb, framework, mode)`. Duplicate guard logs "Would have duplicate vehicle actions". Requires entity+**8** non-null for alloc path. Sole producer of framework for sim vehicles.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004fb660_Vehicle_createVehicleAction.md` (or `aa_004fb660_FUN_004fb660.md`) |
| Annotated | `docs/reconstruction/raw/aa_004fb660_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vehicle_createVehicleAction.cpp` |
| Function record | `docs/reconstruction/functions/aa_004fb660_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `+0x1a0 triple {action, framework, input}` | High | Plate |
| `Calls buildHavokVehicleFramework` | High | Sole caller relation inverse |
| `Duplicate action log+cleanup` | High | String + FUN_004f7d60 |
| `Driver input FUN_005fe020` | High | Plate |
| `Exact VehicleAction_ctor args` | Medium | Partial |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Guard duplicate → new 0xC → framework → action ctor | Yes |
| No invent inventory | Yes |

---

## 5. Gaps / open

1. Seal VehicleAction_ctor signature.
2. mode2 / param meanings.

**Verdict:** **accept-with-gaps**
