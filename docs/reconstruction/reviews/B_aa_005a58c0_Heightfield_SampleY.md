# Review B (skeptical / adversarial): `aa_005a58c0` Heightfield_SampleY

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a58c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B — live Ghidra; body + xrefs) |
| **Counterpart** | `reviews/A_aa_005a58c0_Heightfield_SampleY.md` |
| **System** | `world-terrain` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on kernel ABI/scale/clamp/÷scale/role; **reject** overclaims that this is map-null-gate, cast-terrain, wheel ray, or a finished bit-exact port |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `this` is `CVOGMap*` (same as `004cd220` / `004cfe60`) | **Falsified** — layout is HF dims/scales at `+0x0C/+0x10/+0x30/+0x34/+0x38`; map gate **rewrites ECX** from `map+0xe4e0` before JMP/CALL |
| 2 | Function metadata `undefined FUN_005a58c0(void)` is full ABI | **Falsified** — body **`RET 8`**; two stack floats; return **ST0** (`float10` decompile) |
| 3 | Trunc uses float→uint **bitcast** | **Falsified** — body **`CVTTSS2SI`** (trunc toward zero) |
| 4 | Clamp upper bound is `dim−1` (last cell only) | **Falsified** — **`dim−2`** so bilinear can sample `cell+1` |
| 5 | This unit null-checks heightfield / returns 0.0 | **Falsified** — **no** null test; null handled by `004cd220` gate or caller |
| 6 | This unit is `CVOGMap_CastTerrainHeight` | **Falsified** — no ray, no filter 5/18, no `FUN_0055e530`, no hit lerp |
| 7 | This is wheel / suspension contact Y | **Falsified** — pure HF grid sample; wheel path is `TtPhantom::castRay` family |
| 8 | Return is raw heightmap texel without scale | **Falsified** — **`FDIV [this+0x34]`** always |
| 9 | Scaffold "unknown system" / CastTerrain-only callee name is final | **Superseded** — multi-caller HF sample kernel; name **Probable** `Heightfield_SampleY` |
| 10 | Ready for bit-exact seal of full package | **Fail** — runtime/diff open; `FUN_005a5810` product dual open |
| 11 | Args are full XYZ or (x,y) | **Falsified** — stack is **X then Z** only (callers: pos[0]/pos[2]) |
| 12 | Writes map / entity / camera fields | **Falsified** — pure; only CALL + FDIV + RET |

---

## 2. Decisive dataflow (raw ≡ live ≡ body)

```
// thiscall ECX = Heightfield* hf
// stack: float worldX, float worldZ
// RET 8; return ST0

gx = *(hf + 0x30) * worldX
gz = *(hf + 0x38) * worldZ

cellX = min(max(0, trunc_toward_zero(gx)), *(int*)(hf + 0x0C) - 2)
cellZ = min(max(0, trunc_toward_zero(gz)), *(int*)(hf + 0x10) - 2)

fx = gx - (float)cellX
fz = gz - (float)cellZ

raw = FUN_005a5810(hf, cellX, cellZ, fx, fz)   // bilinear; OWN not dualed
return raw / *(float*)(hf + 0x34)
```

Live re-decompile (2026-07-29, force refresh) matches 2026-07-23 raw CF. ABI sealed by epilogue `C2 08 00` + stack operand offsets after `PUSH ESI`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| this = HF*, not map | **High** | Wrong ECX → crash / garbage Y |
| RET 8 / two float XZ | **High** | Stack imbalance on tail from `004cd220` |
| Scale X/Z at +0x30/+0x38 | **High** | Wrong grid mapping |
| Clamp to dim−2 | **High** | OOB on bilinear `cell+1` or edge hole |
| ÷ height scale +0x34 | **High** | Y off by constant factor (spawn/snap float) |
| Not cast / not wheel | **High** | Port to wrong collision path |
| Callee bilinear structure | **High structure; product open** | Corner order / vtbl wrong if ported from memory alone |
| Exact product method name | **Probable** | Rename churn only |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0x30` scale X | Invented? | **No** — first `MOVSS`/`MULSS` on this |
| `+0x38` scale Z | Invented? | **No** — second scale path |
| `+0x0C` / `+0x10` dims | Invented? | **No** — loaded for clamp; −2 applied |
| `+0x34` divisor | Invented? | **No** — epilogue `FDIV [ESI+0x34]` |
| Tail target from `004cd220` | Wrong? | **No** — prior dual: `E9` → `005a58c0` |
| RET 8 | Decompiler void? | **Body wins** — `C2 08 00` at `005a5954` |
| Hidden cast inside | Missed CALL? | **Only** `FUN_005a5810`; no `0055e530` / castRay |
| dim−2 vs dim−1 | Off-by-one? | **dim−2 intentional** for bilinear extent |
| Bitcast trunc | Decompiler `(uint)`? | **CVTTSS2SI** in body |

---

## 5. Surviving contract for AutoCore

```
// Heightfield_SampleY (Probable name) @ 0x005a58c0
float SampleY(Heightfield* hf, float worldX, float worldZ):
  gx = hf.scaleX * worldX          // +0x30
  gz = hf.scaleZ * worldZ          // +0x38
  cellX = clamp(trunc(gx), 0, hf.dimX - 2)   // +0x0C
  cellZ = clamp(trunc(gz), 0, hf.dimZ - 2)   // +0x10
  raw = BilinearSample(hf, cellX, cellZ, gx-cellX, gz-cellZ)  // FUN_005a5810
  return raw / hf.heightScale      // +0x34

// Do NOT:
//  - pass CVOGMap* as this (use map+0xe4e0 or CVOGMap_SampleHeightfieldY gate)
//  - substitute CastTerrainHeight (physics refine) unless caller needs ray
//  - invent (x,y,z) three-arg form or omit ÷+0x34
//  - treat as wheel suspension contact
// Pair with:
//  - CVOGMap_SampleHeightfieldY (null-safe map gate)
//  - CVOGMap_CastTerrainHeight (HF + vertical cast)
//  - creature FindTerrainHeight (gate + optional refine)
```

---

## 6. Open questions

1. Product / PDB symbol string for `0x005a58c0`.
2. Dual / name for `FUN_005a5810` (bilinear + vtbl height get).
3. Asset meaning of scale triple (`+0x30/+0x34/+0x38`) vs TGA/heightmap headers.
4. Behavior when `*(hf+0x34) == 0` (no guard).
5. Server-side equivalent pure HF sample (if any) vs client-only mesh HF.

**Verdict:** **accept-with-gaps**
