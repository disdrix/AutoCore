# Review B (skeptical / adversarial): `aa_0091a5f0` Client_Camera_ApplyLookOffset

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091a5f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0091a5f0_Client_Camera_ApplyLookOffset.md` |
| **Evidence** | Same live decompile + `read_memory` as A; DCT call sites; basis-extract verified notes |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|-------|--------|---------|
| 1 | This is a **steer** helper / writes `+0x618` | Scan body for `0x618` / axis setters | **Falsified.** No drive-axis stores; callees are basis/quat/pos apply. |
| 2 | Soft look 0.2 inside apply **is** soft-steer band | Soft steer is ±0.5 immediates on `SetSteerInput` | **Falsified as merge.** `DAT_00a0f70c=0.2` here **scales** forward basis on xz-zero path only. DCT soft look steps also use 0.2 on `local_d4` — shared constant, different sinks. |
| 3 | `param_1` is FOV | Only used as ≠1.0 gate, fold/acos input, mode deadband | **Unproven.** Product FOV name rejected; keep as **look scale**. |
| 4 | Always rotates camera even when scale==1 | Scale≠1 branch skipped when `param_1 == g_flOne` | **Partial survive.** Mode byte + look-vector path still run when scale==1 (DCT second site passes 1.0). |
| 5 | ESI is always the vehicle | Body uses multi-inherit `*(ESI+4)+4+ESI` fallbacks; DCT may pass character or vtbl`+0x1d8` object | **Partial.** Treat as **look helper object**, not sealed vehicle*. |
| 6 | Mode `0xFF` means “invalid” exclusively | Ternary: below deadband→1, in band→0, above→0xFF | **Survive as CF.** Product enum names open. |
| 7 | `FUN_004e8a40` is up-vector | Verified: **forward (+Z)**; up is sibling `0x004e8b60` | **Falsified if claimed as up.** A’s table correct. |
| 8 | Hemisphere wrap uses π | `DAT_00aaa7dc` = **2π** (`da0fc940`) | **Falsified if π.** Sealed TAU wrap. |
| 9 | Two callers only is incomplete | `get_function_xrefs` → DCT only | **Survive (High)** for this image. |
| 10 | Clean renames prove runtime identity | Renames are documentation | **Accepted limit** — static dual only. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Not a drive-axis writer | **High** | Bogus AutoCore steer coupling |
| Callers = DCT only (2 sites) | **High** | Missed other camera entries |
| Forward/right basis extract roles | **High** | Wrong pitch/hemisphere geometry |
| Constant table (25, 2π, ±1, deadband, 0.2, 0.5) | **High** | Bad port of apply math |
| Mode byte thresholds around 1.0 | **High** CF | Wrong `+0x14c` semantics |
| ESI object C++ type | **Medium** | Wrong layout ports |
| `lookScale` product meaning | **Low–Med** | FOV/aim mislabel |
| `FUN_00567ce0` full stack wiring | **Medium** | Wrong axis for scale≠1 quat |
| Sticky `+0x304` product name | **Medium** | Residual look after release mis-modeled |
| Bit-exact / runtime | **Open** | Silent drift vs retail |

---

## 3. Cross-check against raw

```
Client_Camera_ApplyLookOffset(lookScale, lookVec):  // ESI = helper
  dtLike = *(g_timeMgr + 0x30)
  if !helper || !helper.obj: return
  if lookScale != 1:
    // pitch from vehicle/object forward vs world Z; fold scale; half-angle quat; apply
  helper.modeByte(+0x14c) = classify(lookScale vs ~1)
  if lookVec.x|z active or sticky(+0x304):
    // world pos = pos + R*lookVec; apply; maybe damp; sticky=1
```

Clean ≡ raw CF; names are sealed roles not retail symbols.

---

## 4. Surviving contract for AutoCore

```
Camera look apply is a DCT callee only.
  Inputs: look scale (seed 1.0; hard ±0.03 / soft ±0.2 steps live in DCT, not here),
          look vector (stack), ESI look helper.
  Side effects: orientation path when scale≠1; mode byte +0x14c;
                optional world offset apply; sticky +0x304.
  MUST NOT be wired into SetSteerInput / thr / HB.
  Soft 0.2 reuse: damp inside apply ≠ soft-steer ±0.5.
```

---

## 5. Must not claim

- Yaw/pitch/roll component names without further RE.
- That this dual closes all of UF-003 (skills / airborne remain parent residual).
- Bit-exact camera product behavior or FOV naming for `lookScale`.
- That ESI is always `VehicleEntity*` or always `Character*`.
- That `DAT_00a0f70c` “means soft steer” in this function.

---

## 6. Open questions (B keeps pressure)

1. Listing-seal ESI register at both CALL sites (MOV ESI, … before CALL).
2. Name `DAT_00d09874+0x30` (dt vs other).
3. Seal `FUN_00567ce0` axis source (global `DAT_00afda50` region layout).
4. Type id **6** at vtbl`+0x18` product meaning.
5. Live: hold soft look — confirm `+0x14c` / sticky `+0x304` transitions.

**Verdict:** **accept-with-gaps**
