# Review A (reconstruction fidelity): `aa_004e8a40` Math_QuatExtractForwardZ

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8a40` |
| **VA** | `0x004e8a40` |
| **Body span** | `004e8a40` – `004e8acb` |
| **Ghidra symbol** | `FUN_004e8a40` |
| **Canonical name** | `Math_QuatExtractForwardZ` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_004e8a40_Math_QuatExtractForwardZ.md` |
| **System** | `input-drive-control` (pure math leaf; primary drive consumers) |
| **Dual status** | **Present** |
| **Verdict** | **accept** (math leaf sealed; runtime golden optional) |

---

## 1. Purpose

Leaf helper: convert a unit quaternion **`q = (x,y,z,w)`** at `float[4]` into the chassis **forward (+Z)** world-space direction as a homogeneous `float[4]` with **W forced to 0**.

Closed form (unit quat → rotation-matrix **column 2**):

```
out.x = 2*(z*x + y*w)
out.y = 2*(z*y - x*w)
out.z = 1 - 2*(x² + y²)
out.w = 0
```

**Not this unit:** right (+X) sibling `0x004e8ad0`, up (+Y) sibling `0x004e8b60`, or any thr/HB/steer controller write. PushDriveAxes / MoveToTarget / applyAction **call** this for `dot(vel, forward)` and heading dots only.

**Calling convention:** stack args (`param_1`, `param_2`) — **not** `__thiscall`. Leaf: **no calls**, single basic block, cyclomatic complexity **1**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e8a40_FUN_004e8a40.md` |
| Annotated | `docs/reconstruction/raw/aa_004e8a40_FUN_004e8a40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004e8a40.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e8a40_FUN_004e8a40.md` |
| Prior verified physics | `docs/reconstruction/physics/verified/fn_004e8ad0_basisExtract.md` (covers sibling set; this dual OWN-ONLY seals `0x004e8a40`) |
| Consumer dual | `reviews/A_aa_004fbc10_VehicleEntity_PushDriveAxesToController.md` |

**This pass (live):** Ghidra MCP `decompile_function` @ `0x004e8a40`; `get_function_by_address` body `004e8a40`–`004e8acb`; `get_function_xrefs`; `read_memory` @ `0x00a0f2a0`, `0x00a10e74`. **Not performed:** Launcher, runtime golden samples, bit-exact binary diff, sibling body re-seal.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf: no calls, single return | **High** | Live decompile; body span to `004e8acb` |
| `param_1` = quat XYZW `float[4]` | **High** | Indices 0..3 = x,y,z,w; consumers pass rb `+0x30` / entity `+0x94` |
| `param_2` = out direction `float[4]`, W=0 | **High** | Final store `param_2[3] = 0.0` |
| Scale constant `g_flLevelUpUiBase_Inferred` @ `0x00a10e74` = **2.0f** | **High** | `read_memory` LE `00 00 00 40` |
| Diagonal constant `g_flOne` @ `0x00a0f2a0` = **1.0f** | **High** | `read_memory` LE `00 00 80 3f` |
| Ghidra name `g_flLevelUpUiBase_Inferred` is UI misnomer here | **High** | Shared 2.0f pool; role is quat scale factor only |
| Output = rotation-matrix **column 2** (local +Z → world) | **High** | Closed form matches standard unit-quat matrix |
| Identity `(0,0,0,1)` → forward `(0,0,1,0)` | **High** | Hand algebra from body |
| No re-normalize of input or output | **High** | Body has no sqrt/div; non-unit quat → non-unit axis |
| Clean ≡ raw ≡ live CF | **High** | Identical stores / order |
| Bit-exact / runtime golden | **Open** | Deferred (leaf algebra closed) |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Load TWO = `g_flLevelUpUiBase_Inferred` | **Yes** |
| Load x,y,z,w from `param_1[0..3]` | **Yes** |
| `out[0] = (z*x + y*w) * TWO` | **Yes** |
| `out[1] = (z*y - x*w) * TWO` | **Yes** |
| `out[2] = ONE - (x*x + y*y) * TWO` | **Yes** |
| `out[3] = 0.0` | **Yes** |
| No branches / no callees | **Yes** |

### 4.1 Live decompile (2026-07-29)

```c
void FUN_004e8a40(float *param_1, float *param_2)
{
  float fVar1;  // x
  float fVar2;  // y
  float fVar3;  // z
  float fVar4;  // w
  float fVar5;  // 2.0

  fVar5 = g_flLevelUpUiBase_Inferred;   // 2.0 @ 0xa10e74
  fVar1 = *param_1;                     // x
  fVar2 = param_1[1];                   // y
  fVar3 = param_1[2];                   // z
  fVar4 = param_1[3];                   // w
  *param_2     = (fVar3 * fVar1 + fVar2 * fVar4) * g_flLevelUpUiBase_Inferred;
  param_2[1]   = (fVar3 * fVar2 - fVar1 * fVar4) * fVar5;
  param_2[2]   = g_flOne - (fVar1 * fVar1 + fVar2 * fVar2) * fVar5;
  param_2[3]   = 0.0;
  return;
}
```

Matches 2026-07-23 raw body bit-for-bit at CF level.

### 4.2 Port-ready closed form

```c
// TWO = 2.0f @ 0xa10e74; ONE = 1.0f @ 0xa0f2a0
void Math_QuatExtractForwardZ(const float q[4], float out[4]) {
    float x = q[0], y = q[1], z = q[2], w = q[3];
    out[0] = (z*x + y*w) * TWO;         // 2(xz + yw)
    out[1] = (z*y - x*w) * TWO;         // 2(yz - xw)
    out[2] = ONE - (x*x + y*y) * TWO;   // 1 - 2(x² + y²)
    out[3] = 0.0f;
}
```

---

## 5. Constants (re-verified `read_memory` this pass)

| Symbol (Ghidra) | Addr | LE bytes | float32 | Role here |
|-----------------|------|----------|--------:|-----------|
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | **1.0** | diagonal term `1 − 2·(x²+y²)` |
| `g_flLevelUpUiBase_Inferred` | `0x00a10e74` | `00 00 00 40` | **2.0** | quaternion factor **2** on every term |

No other globals, no tables, no vtables.

---

## 6. Callers (OWN-ONLY xrefs — product roles of **this** leaf)

Live `get_function_xrefs` (non-exhaustive highlight of drive path):

| Site | Parent | Role of forward |
|------|--------|-----------------|
| `0x004fbe43` | `VehicleEntity_PushDriveAxesToController` | `dot(linVel, forward)` for overspeed thr polarity |
| `0x004fc82e` | `Drive_CVOGVehicle_MoveToTarget3DPoint` (`FUN_004fc650`) | `fAlign` / `fwdSpeed` dots vs aim dir |
| `0x005993fd` | `VehicleAction_applyAction` | chassis forward for action/steer path |
| many | AI pursue / heading / skill range / debug | same leaf math |

**OWN-ONLY boundary:** dual does **not** re-seal caller bodies; product role of outputs is established by prior consumer duals + verified physics doc.

---

## 7. Gaps / open

1. Runtime / differential golden (identity + 90° yaw samples) — algebra sealed; optional.
2. Bit-exact vs retail EXE image — deferred.
3. Sibling right/up extractors are documented elsewhere; not re-owned here.

**Verdict:** **accept** — leaf math dual sealed with live decompile + constant `read_memory`. Package is complete for static reconstruction of **this VA**.
