# Review A (reconstruction fidelity): `aa_004fb370` Vehicle_SoftPoseAndWheelTerrainSnap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fb370` |
| **VA** | `0x004fb370` |
| **Canonical name** | `Vehicle_SoftPoseAndWheelTerrainSnap_Inferred` (was `FUN_004fb370`) |
| **Ghidra symbol** | `FUN_004fb370` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — soft pose residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fb370_Vehicle_SoftPoseAndWheelTerrainSnap_Inferred.md` |
| **System** | input-drive-control / vehicle ghost soft-pose |
| **Callees** | `VehicleNet_SoftPoseSyncFromBody_Inferred` `0x0053e600`, `CVOGMap_SampleHeightfieldY` `0x004cd220`, `CVOGPhysics_SetPosition` `0x0040d2a0` |
| **Callers** | Ghidra `get_function_callers` empty (likely **vtable** / this-adjust thunk); inverse: soft-pose dual lists this as caller of `0x0053e600` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Vehicle tick path (MSVC this-adjust interior pointer)** that:

1. **Soft-pose syncs** body ↔ soft buffer via `FUN_0053e600(param_2)`.
2. Optionally **snaps chassis Y** to terrain under the first near-ground wheel.

Decompiler shows large **negative offsets** from `param_1` (`−0x66c`, `−0x668`, `−0x56d`, `−0x4d0`, `−0x418`) — multi-inherit / adjusted `this`. Absolute entity mapping residual; relative graph is solid.

CF:

```
// Gate: nested flag@+0x7e OR this-0x56d char
if (!gate) return;

FUN_0053e600(param_2);   // SoftPoseSyncFromBody

// Need: soft/phys host (this-0x668), wheel container (this-0x4d0)+inner,
//       axle/wheel count byte at *(this-0x418)+0xb0 > 0
if (!wheels_ready) return;

i = 0; off = 0
while true:
  wheel = wheelTable + off          // stride 0xC0
  terrainY = SampleHeightfieldY(wheel.x, wheel.z)   // FUN_004cd220
  if (wheel.y - terrainY) < DAT_00aaa6d4:   // ≈ -0.1f  → contact / below threshold
    break
  off += 0xC0; i++
  if i >= wheelCount: return        // no wheel close enough

// Snap position using host basis +0xb0 (or adjusted fallback when no soft host)
pos = { host.x, terrainY + 1.0f, host.z, 0 }
SetPosition(&pos)                   // FUN_0040d2a0
```

`read_memory` `0x00aaa6d4` → `cd cc cc bd` = **−0.1f** (wheel height vs terrain gate).

Y lift uses **`g_flOne` (1.0)** above sampled terrain — not the soft-pose 30.0 far threshold (that lives inside `0x0053e600`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004fb370` |
| Constant | `read_memory` `0x00aaa6d4` → **−0.1f** |
| Nested dual | `A_aa_0053e600_VehicleNet_SoftPoseSyncFromBody_Inferred.md` |
| SetPosition dual | `A_aa_0040d2a0_CVOGPhysics_SetPosition.md` |
| Height sample | `A_aa_004cd220_CVOGMap_SampleHeightfieldY.md` (if present) |
| Raw / clean | `raw/aa_004fb370_*`, `FUN_004fb370.cpp` |

---

## 3. Signature

```c
// ECX = adjusted vehicle/physics view (negative offsets)
// param_2 forwarded into SoftPoseSyncFromBody (decomp width uncertain)
void __thiscall SoftPoseAndWheelTerrainSnap(AdjustedVehicle *this, undefined4 param_2);
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Always tries SoftPoseSyncFromBody when gated | **High** |
| Wheel loop stride **0xC0** | **High** |
| Terrain sample via `FUN_004cd220` on wheel XZ | **High** |
| Contact gate **wheelY − terrainY < −0.1** | **High** |
| Snap Y = terrain + **1.0** then SetPosition | **High** |
| Exact this-adjust base → entity absolute | **Medium** residual |
| Caller site / vtable slot English | **Open** |
| Network wire IO here | **None** (falsified — local soft + terrain) |

**Verdict:** **accept-with-gaps**
