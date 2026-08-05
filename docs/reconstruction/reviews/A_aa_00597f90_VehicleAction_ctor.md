# Review A (reconstruction fidelity): `aa_00597f90` VehicleAction_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00597f90` |
| **VA** | `0x00597f90` |
| **Canonical name** | `VehicleAction_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00597f90_VehicleAction_ctor.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

VehicleAction constructor (MSVC `__thiscall`). Initializes action object with multi-arg setup (params include framework/driver-related opaque args in decomp). Calls base/init helper **FUN_00636370**, stamps globals **DAT_009d54e0 / DAT_009c7bc0**, exception registration prologue. Pairs `Vehicle_createVehicleAction` (+0x1a0 handle) and `buildHavokVehicleFramework`. Residual: full field-zero map and param_2–5 roles.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00597f90_*.md` |
| Annotated | `docs/reconstruction/raw/aa_00597f90_*.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleAction_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00597f90_*.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Ctor for VehicleAction object` | High | Name + createVehicleAction graph |
| `FUN_00636370 base init` | High | Body |
| `Exception prologue present` | High | MSVC pattern |
| `param_2–5 semantic map` | Medium | Decomp names weak |
| `Full member zero/init list` | Medium | Partial seal |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| register EH → base init → field stamps | Yes |
| No invent physics build here | Yes |

---

## 5. Gaps / open

1. Seal param map vs createVehicleAction args.
2. Name FUN_00636370.

**Verdict:** **accept-with-gaps**
