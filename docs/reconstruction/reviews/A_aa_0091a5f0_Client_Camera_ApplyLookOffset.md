# Review A (reconstruction fidelity): `aa_0091a5f0` Client_Camera_ApplyLookOffset

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091a5f0` |
| **VA** | `0x0091a5f0` |
| **Canonical name** | `Client_Camera_ApplyLookOffset` (was `FUN_0091a5f0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0091a5f0_Client_Camera_ApplyLookOffset.md` |
| **System** | `input-drive-control` (camera / look apply) |
| **Evidence** | Live Ghidra `decompile_function` `0x0091a5f0` + callees; `read_memory` DAT floats; DCT callers `0x0092278b` / `0x00922f13`; prior DCT camera residual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **camera / look-offset apply** helper. Sole callers are `Client_Input_DriveControlTick` (two sites). Consumes look **scale** (`param_1` / DCT `local_d4`) and look **vector** (`param_2` / `&local_d0` or combat seed). Implicit object context in **ESI** (DCT “look helper” `piStack_a8`: local character or vtbl`+0x1d8` camera object).

Does **not** write vehicle drive axes (`entity+0x614/+0x618/+0x61c`). Separates from soft-steer ±0.5 (UF-006) and hard/soft look **steps** owned by DCT SECTION 7.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0091a5f0_FUN_0091a5f0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0091a5f0_FUN_0091a5f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Camera_ApplyLookOffset.cpp` |
| Function record | `docs/reconstruction/functions/aa_0091a5f0_Client_Camera_ApplyLookOffset.md` |
| Parent dual | `reviews/A_aa_009223b0_*_camera_refresh.md` |
| Basis extract verified | `physics/verified/fn_004e8ad0_basisExtract.md` |

---

## 3. Signature / convention

```c
// Stack: float lookScale, float *lookVec4  (xyzw-ish; DCT uses local_d0..c4)
// ESI   : look-helper object*  (unaff_ESI; set by caller — DCT piStack_a8)
// Returns void
void Client_Camera_ApplyLookOffset(float lookScale, float *lookVec);
```

| Claim | Confidence | Notes |
|---|---|---|
| Two stack args: scale + vec ptr | **High** | decompile + both DCT call sites |
| ESI = look helper object | **High** CF | body uses `unaff_ESI+8/+0x14c/+0x304`; DCT only calls when `piStack_a8 != 0` |
| Does not take vehicle as stack arg | **High** | no pVehicle param; rb via `*(ESI+8)+0x3c` |
| Exact MSVC decoration / thiscall vs custom ESI | **Medium** | decompiler “unaff”; listing not re-walked this pass |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
local_54 = *(DAT_00d09874 + 0x30)          // time/scale global
gate: ESI != 0 && *(ESI+8) != 0
  if lookScale != 1.0:
    quat = rb(+0x3c)+0x30..0x3c
    forward = FUN_004e8a40(quat)           // +Z basis
    pitchDot = forward · worldZ(0,0,1)     // DAT_00afda60..68
    clamp pitchDot to [-1,1]
    pitch = acos(pitchDot); non-finite → 0
    FUN_004e8ad0(quat, tmp)                // right (+X) into local_20
    if forward · worldX(1,0,0) < 0:        // DAT_00afda70..78
      pitch = TAU - pitch                  // DAT_00aaa7dc = 2π
    fold lookScale about 1.0 → |delta| arg + sign local_58 ∈ {+1,-1}
    clamp folded ≥ -1
    ang = acos(folded); non-finite → 0
    FUN_00567ce0(... half-angle quat build from axis*ang + pitch)
    FUN_00404dc0()                         // push/apply orientation path
  mode byte ESI+0x14c:
    lookScale < ~0.99999 → 1
    in [~0.99999, ~1.00001] → 0
    > ~1.00001 → 0xFF
  if lookVec.x != 0 || lookVec.z != 0 || ESI+0x304 != 0:
    if rb present && type_vtbl(+0x18)==6:
      FUN_0053d970(); SetObjectActiveState(active=1, flag=0)
    pos  = rb+0xb0 else entity-local +0x84
    quat = rb+0x30 else entity-local +0x94
    FUN_004e8bf0(pos, quat, lookVec, out)  // world = pos + R*offset
    FUN_004c3a40(out)                      // nan-check + gated apply
    if lookVec.x==0 && lookVec.z==0:
      scale forward basis * 0.2; zero pos; FUN_004c3a40; return
    else ESI+0x304 = 1
return
```

| Stage | Match |
|---|---|
| Outer ESI / +8 gate | Yes |
| Scale≠1 orientation branch | Yes |
| Mode ternary → `+0x14c` | Yes |
| Look-vector apply + sticky `+0x304` | Yes |
| Early return on xz-zero damp path | Yes |
| No drive-axis stores in body | Yes |

---

## 5. Constants sealed (`read_memory` 2026-07-29)

| DAT | Hex LE | f32 | Role in this unit |
|-----|--------|----:|-------------------|
| `DAT_00aaa668` | `000080bf` | **−1.0** | clamp min; fold sign |
| `DAT_00aaa6fc` | `0000c841` | **25.0** | scale rate with `local_54` |
| `DAT_00aaa7dc` | `da0fc940` | **≈6.283185 (2π)** | pitch hemisphere wrap |
| `DAT_00aaa948` | `58ff7f3f` | **≈0.99999** | mode deadband low |
| `_DAT_00aaa9bc` | `5400803f` | **≈1.00001** | mode deadband high |
| `DAT_00a0f70c` | `cdcc4c3e` | **0.2** | damp scale when look xz both 0 (reuse of soft-look step DAT; **different role**) |
| `DAT_00a0f298` | `0000003f` | **0.5** | half-angle in `FUN_00567ce0` |
| `DAT_00a27c3c` | `db0f4940` | **≈π** | `FUN_0040d0a0` acos edge for x≤−1 |
| `DAT_00afda60..68` | — | **(0,0,1)** | world Z for pitch dot |
| `_DAT_00afda70..78` | — | **(1,0,0)** | world X hemisphere test |
| `g_flOne` | — | **1.0** | identity scale / fold pivot |

---

## 6. Callees (roles sealed High as math/apply; product names residual)

| VA | Role |
|----|------|
| `0x004e8a40` | Quat → **forward (+Z)** basis (verified sibling of `fn_004e8ad0`) |
| `0x004e8ad0` | Quat → **right (+X)** basis |
| `0x004e8bf0` | `out = pos + Rotate(quat, lookVec)` world offset compose |
| `0x0040d0a0` | Safe **acos** (edge 0 / π) |
| `0x00567ce0` | Axis-angle → unit quat via sin/cos(**0.5**·θ) |
| `0x004c3a40` | NaN assert path + gated entity apply (`0xC7` style mask at +0xb8) |
| `0x00404dc0` | Orientation/camera push after scale≠1 branch |
| `0x0053d970` | Type-6 special: ensure object active path |
| `CVOGSpawnPoint_SetObjectActiveState` | Spawn/active state pair (1,0) |

---

## 7. Callers

| Site | Parent | Args |
|------|--------|------|
| `0x0092278b` | `Client_Input_DriveControlTick` | `(local_d4, &local_d0)` after normalize/scale when `piStack_a8 != 0` |
| `0x00922f13` | same | `(1.0f, &fStack_a0)` combat/default seed look when mode flags allow |

Only these two xrefs (`get_function_xrefs` / callers).

---

## 8. Separation from steer (inherits DCT camera residual)

| Axis | This unit | Steer |
|------|-----------|-------|
| Storage | ESI flags `+0x14c/+0x304`; camera/pose via callees; global `DAT_00afda50` region | `entity+0x618` only via `SetSteerInput` |
| Args | look scale + look vec | not present |
| Soft 0.2 DAT | **damp** on zero-xz path inside apply | **not** soft-steer (±0.5 immediates) |

---

## 9. Gaps / open

1. Exact product name / C++ type of ESI object (character vs dedicated camera helper dual layout).
2. Semantic labels yaw/pitch/roll for `lookVec` components (DCT `local_d0/cc/c8/c4` still unproven).
3. Product meaning of `lookScale` (FOV vs blend vs aim multiplier) — only known as arg0 ≠1.0 gate + mode byte.
4. Full prototype of `FUN_00567ce0` stack (this/axis/angle wiring) — CF High as half-angle quat build; arg order residual.
5. `DAT_00d09874+0x30` exact field name (dt vs other scale).
6. Runtime / differential / bit-exact vs retail: **OPEN**.

**Verdict:** **accept-with-gaps**
