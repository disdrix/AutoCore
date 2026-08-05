# Review A (reconstruction fidelity): `aa_004e8b60` Math_QuatExtractUp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8b60` |
| **VA** | `0x004e8b60` |
| **Canonical name** | `Math_QuatExtractUp_Inferred` (was `FUN_004e8b60`) |
| **Ghidra symbol** | `FUN_004e8b60` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004e8b60_Math_QuatExtractUp_Inferred.md` |
| **System** | math / vehicle upright (calcWheelTorque, air paths) |
| **Dual status** | **Present** |
| **Verdict** | **accept** — unit-quat → world +Y column sealed |

---

## 1. Purpose

Extract **body up axis (+Y)** as a homogeneous direction `(x,y,z,0)` from orientation quaternion `q=(x,y,z,w)`:

```
out.x = 2*(x*y - z*w)
out.y = 1 - 2*(x² + z²)
out.z = 2*(z*y + x*w)
out.w = 0
```

Scalar **2.0** is the global decomp names `g_flLevelUpUiBase_Inferred` (shared 2.0f plate; verified sibling set uses TWO @ `0xa10e74`). Sibling extractors:

| VA | Axis |
|---|---|
| `FUN_004e8ad0` | right (+X) |
| **`FUN_004e8b60`** | **up (+Y)** |
| `FUN_004e8a40` | forward (+Z) |

Primary vehicle consumer: `VehicleAction_calcWheelTorque` upright power; also turret aim, unstick tilt, etc.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004e8b60` |
| Raw | `raw/aa_004e8b60_FUN_004e8b60.md` |
| Verified set | `physics/verified/fn_004e8ad0_basisExtract.md` §3.3 |
| Xrefs | calcWheelTorque, UpdateTurretAiming, unstick `0x0091d660`, … |

---

## 3. Body ≡ standard rotation-matrix column 1

Matches unit-quaternion basis column for +Y (see verified closed-form).

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Formula matches up column | **High** |
| out.w = 0 | **High** |
| TWO factor is 2.0 | **High** (sibling verified + algebra) |
| Not forward/right | **High** (siblings) |

**Verdict:** **accept**
