# Review A (reconstruction fidelity): `aa_0053f1f0` VehicleNet_SoftPoseChase_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053f1f0` |
| **VA** | `0x0053f1f0` |
| **Canonical name** | `VehicleNet_SoftPoseChase_Inferred` (was `FUN_0053f1f0`) |
| **Ghidra symbol** | `FUN_0053f1f0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of ApplyNetworkPose soft graph) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053f1f0_VehicleNet_SoftPoseChase_Inferred.md` |
| **System** | input-drive-control / vehicle ghost soft-pose |
| **Sibling** | `SoftPoseIntegrate` `0x0053eb90`; seed/sync `0x0053e600`; apply `0x0053eec0` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Chase live soft-buffer pose toward network target** (periodic catch-up companion to ApplyNetworkPose soft fill + SoftPoseIntegrate).

High-level CF (live decompile):

1. Ensure soft buffer at `entity+0x28` via `FUN_0053e020`.
2. Early-out **0** if `‖buf.pos‖ ≤ ε` (`DAT_009d0010` ≈ **1.19e-7** from `read_memory`).
3. Compute error vector `buf.pos − netPos` (and w component); `errLen = ‖xyz‖`.
4. If `errLen ≤ param_8` (snap radius arg): optionally zero `param_4` vel if non-zero using zero plate `DAT_00b04610..`.
5. Else branch on `DAT_00b04606` mode flag:
   - **Mode 0 (smooth):** scale error by `dt * g_flVehicleHpTechCoeff`, min-step against `g_flLevelUpUiBase_Inferred`, blend factor using `DAT_009d000c` (**15.0**) − other constants; update `param_3` pos and `param_4` vel; set dirty.
   - **Mode 1 (alt):** copy/chase with `DAT_00af2450` / `g_flMultiKillCountBlend` style clamps (global names likely **mislabeled** in Ghidra — treat as soft-pose constants).
6. Rotation blend: basis extract `FUN_004e8a40` / `FUN_004e8ad0` on `param_6` vs buffer `+0x10`; if dot &lt; `DAT_00aaa660` → slerp-like `FUN_00567e90` with clamp, zero angVel out.
7. If `param_9` and `SoftPoseIntegrate(dt, 0)` fails: zero lin/ang vel outs and buffer `+0x20/+0x30` vel slots.

Returns **1** if any chase write occurred, else **0**.

**Xrefs:** DATA-only vtable slots (`0x009ce850`, `0x009ceba0`, …) — virtual method; no direct code CALL found.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0053f1f0` |
| Xrefs | `get_xrefs_to` → **DATA** vtable entries only |
| Constants | `read_memory` `0x009d0010`→~1.19e-7; `0x009d000c`→**15.0**; `0x00af2458`→**15.0** |
| Related duals | `A_aa_0053eec0_*`, `A_aa_0053eb90_*`, `A_aa_0053e020_*` |
| Raw / clean | `raw/aa_0053f1f0_*`, `FUN_0053f1f0.cpp` |

---

## 3. Signature (decompiler-shaped)

```c
uint8_t __thiscall SoftPoseChase(
  Entity *this,
  float dt,                 // param_2
  float *ioPos,             // param_3
  float *ioLinVel,          // param_4
  float *ioAngVel,          // param_5
  float *ioRot,             // param_6 (quat)
  undefined4 unused,        // param_7
  float snapRadius,         // param_8
  char doIntegrateGate);    // param_9
```

Exact arg-order at every virtual site: **residual**.

---

## 4. Soft buffer map (this unit + siblings)

| Buf off | Field (inferred) |
|---|---|
| `+0x00` | pos xyzw |
| `+0x10` | rot quat |
| `+0x20` | lin vel |
| `+0x30` | ang vel |

Matches SoftPoseIntegrate parent map.

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = soft chase / catch-up (not pack/unpack) | **High** |
| ε empty-buffer gate ~1.19e-7 | **High** |
| Uses 15.0 blend envelope | **High** |
| Virtual (DATA xrefs only) | **High** |
| Mode flag `DAT_00b04606` product meaning | **Medium** residual |
| Ghidra-named globals (LevelUp/MultiKill) are soft-pose consts | **High mislabel risk** — values sealed, names Tentative |
| Full bit-exact formula | **Open** |

**Verdict:** **accept-with-gaps**
