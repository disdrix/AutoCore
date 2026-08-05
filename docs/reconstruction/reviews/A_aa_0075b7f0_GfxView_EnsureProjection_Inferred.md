# Review A (reconstruction fidelity): `aa_0075b7f0` GfxView_EnsureProjection_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075b7f0` |
| **VA** | `0x0075b7f0` |
| **Canonical name** | `GfxView_EnsureProjection_Inferred` |
| **Prior scaffold names** | `FUN_0075b7f0`, `Named_gfxView_0075b7f0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual — live Ghidra decompile + `read_memory` constants) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_0075b7f0_GfxView_EnsureProjection_Inferred.md` |
| **System** | graphics / client camera (feeds unproject / pick ray) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`thiscall` method on a **gfxView** object (source path string in body:
`C:\vog\1_code\palantir\palantir\graphics\gfxView.cpp`, log line **0xa9**).

**Ensure / rebuild projection** when dirty:

1. Sync zoom/scale cache `this+0x58` from authoritative `this+0xc`; set dirty `this+0x48` if they differ.
2. Early-out success (`0`) if not dirty.
3. Fail (`0xffffffff`) + log if `|far − near| < ε` (`DAT_00a0f718` = **0.01**).
4. Branch on projection mode `this+0xec`:
   - **0 perspective:** FOV → cot(half-FOV) × aspect × zoom → scaleX/Y at `+0x110/+0x114`; optional infinite-style Z scale via `DAT_00aaa880` (**10000**); fill 4×4 via `FUN_0043f210`; write **near extents** `+0xf8/+0xfc = near / scaleX|Y`; fill frustum-plane / basis floats (`atan` half-angles).
   - **1 ortho:** invZoom; `FUN_0043f2e0` ortho matrix (register-messy callee); near extents from ortho rect deltas × invZoom × **0.5**; axis-aligned plane coeffs.
   - **else:** skip matrix/extent rebuild (fall through to clear dirty).
5. Clear dirty `+0x48`, set ready flag `+0xcc = 1`, return `0`.

Primary consumer contract for siblings: **`+0xf8` / `+0xfc` near half-extents at the near plane** (used by `GfxView_UnprojectScreenToWorldRay` `0x0075c340`).

**Calling convention:** MSVC `__thiscall` — gfxView `this` in **ECX** (`param_1` in decompiler). Returns `0` ok / skip, `0xffffffff` near≈far failure.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0075b7f0_FUN_0075b7f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0075b7f0_FUN_0075b7f0.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/GfxView_EnsureProjection_Inferred.cpp` |
| Prior scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0075b7f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0075b7f0_GfxView_EnsureProjection_Inferred.md` |
| Sibling consumer | `aa_0075c340` / `0x0075c340` unproject (calls this) |
| Scratch | `tmp/a_0075b7f0.md` |

**This pass (live):** Ghidra `decompile_function` @ `0x0075b7f0`; `batch_decompile` callees `0x0043f210` (16-float matrix copy), `0x0043f2e0` (ortho fill — XMM/reg messy, roles only); `get_function_callers`; `read_memory` constants below. **Not performed:** Launcher, runtime golden, bit-exact image diff, full dual of matrix callees / frustum-plane product names.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body CF ≡ 2026-07-23 raw ≡ live decompile | **High** | Identical control structure |
| `__thiscall` gfxView `this` in ECX | **High** | Fastcall param_1; callers pass view |
| Class / file = gfxView.cpp | **High** | Path + near/far error string in body |
| Dirty gate `+0x48` + zoom sync `+0xc`→`+0x58` | **High** | First two ifs |
| `+0xf0` near / `+0xf4` far (f32) | **High** | Diff vs ε; extents use near |
| ε `DAT_00a0f718` = **0.01** | **High** | `read_memory` LE `0a d7 23 3c` |
| Mode `+0xec` 0=persp / 1=ortho | **High CF** | Same enum as sibling unproject |
| Viewport ints `+0xdc` / `+0xe0` | **High** | Aspect branch `iVar2 < iVar1` |
| FOV at `+0x10c`; half-angle via × **0.5** then `tan` | **High** | `DAT_00a0f298` = 0.5 |
| Scales `+0x110/+0x114` = cot(halfFOV)×aspect×zoom | **High** | `1/tan` then aspect + `* +0x58` |
| Near extents `+0xf8 = near/+0x110`, `+0xfc = near/+0x114` | **High** | Explicit `near * (1/scale)` |
| Z scale when `+0x14d == 0`: `10000/(10000−near)` | **High** | `DAT_00aaa880` = 10000 |
| `FUN_0043f210` = write 4×4 projection floats | **High CF** | 16-float memcpy body; dest via ECX |
| Ortho extents from rect `+0x118..+0x124` × invZoom × 0.5 | **High** | Mode-1 block |
| Frustum-plane float block `+0x5c..+0xb8` filled | **High CF** | Product plane layout naming open |
| Product C++ method name | **Inferred** | Role sealed; no method string |
| `FUN_0043f2e0` bit-exact ortho math | **Medium / open** | Decompiler XMM failure — not dualed |
| Runtime golden | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Zoom cache sync + dirty set | **Yes** |
| Early return 0 if not dirty | **Yes** |
| Near≈far → log line 0xa9 → return −1 | **Yes** |
| Mode 0: FOV cot + aspect + zoom → matrix + extents + atan planes | **Yes** |
| Mode 1: invZoom + ortho matrix + rect extents + axis planes | **Yes** |
| Mode other: skip rebuild, join epilogue | **Yes** |
| Clear dirty; set `+0xcc`; return 0 | **Yes** |

### 4.1 Perspective near-extent formula (sealed)

```
// this = gfxView*
if (this->zoomCache(+0x58) != this->zoom(+0xc)) {
  this->dirty(+0x48) = 1
  this->zoomCache = this->zoom
}
if (!dirty) return 0
if |far(+0xf4) - near(+0xf0)| < 0.01: log; return -1

if mode(+0xec) == 0:  // perspective
  cot = 1 / tan(fov(+0x10c) * 0.5)
  if height(+0xe0) < width(+0xdc):
    sx = cot;  sy = width * cot / height
  else:
    sx = height * cot / width;  sy = cot
  sx *= zoomCache;  sy *= zoomCache   // store +0x110 / +0x114
  zScale = 1.0
  if flag(+0x14d) == 0:
    zScale = 10000 / (10000 - near)
  // projection matrix via FUN_0043f210:
  //   diag(sx, sy, zScale) with M[2][3]=1, M[3][2]= -near*zScale  (D3D-style)
  nearExtX(+0xf8) = near / sx
  nearExtY(+0xfc) = near / sy
  // + atan(1/sx), atan(1/sy) → sin/cos plane rows at +0x5c..+0xb8
  dirtyPlanes(+0x49) = 1

elif mode == 1:  // ortho
  invZ = 1 / zoomCache
  FUN_0043f2e0( bottom(+0x120)*invZ, near, far )  // + XMM L/R/T (messy)
  nearExtX = (right(+0x11c) - left(+0x118)) * invZ * 0.5
  nearExtY = (top(+0x124) - bottom(+0x120)) * invZ * 0.5
  // axis-aligned plane coeffs; dirtyPlanes = 1

// join:
this->dirty = 0
this->ready(+0xcc) = 1
return 0
```

### 4.2 Constants (this pass `read_memory`)

| Symbol (Ghidra) | VA | LE hex | f32 |
|---|---|---|---:|
| `DAT_00a0f718` (near/far ε) | `0x00a0f718` | `0a d7 23 3c` | **0.01** |
| `DAT_00a0f298` (half) | `0x00a0f298` | `00 00 00 3f` | **0.5** |
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | **1.0** |
| `DAT_00aaa880` (Z far-ish const) | `0x00aaa880` | `00 40 1c 46` | **10000.0** |
| `DAT_00aaa668` | `0x00aaa668` | `00 00 80 bf` | **−1.0** |
| Imm `0x3f800000` (matrix) | — | — | **1.0** |

### 4.3 Callers (live xrefs — roles only; OWN body only dualed)

| Caller | VA | Role |
|---|---|---|
| `FUN_0075c340` | `0x0075c340` | Unproject screen→world ray (always ensures projection) |
| `FUN_0075c680` | `0x0075c680` | gfxView sibling consumer |
| `FUN_0075c6e0` | `0x0075c6e0` | gfxView sibling consumer |
| `FUN_0075c7e0` | `0x0075c7e0` | gfxView sibling consumer |
| `FUN_00496920` | `0x00496920` | Secondary |
| `CVOGTerrainChunker_SubmitForRendering` | `0x005c1940` | Terrain submit path |

### 4.4 Layout on `this` (body-backed)

| Off | Type | Role |
|---:|---|---|
| `+0x0c` | f32 | Zoom / scale (authoritative) |
| `+0x48` | u8 | Projection dirty |
| `+0x49` | u8 | Planes/extents dirty (set when rebuilt) |
| `+0x58` | f32 | Zoom cache (compared to `+0xc`) |
| `+0x5c..+0xb8` | f32 block | Frustum / plane coefficients (persp atan or ortho axes) |
| `+0xcc` | u8 | Ready / projection-valid flag |
| `+0xdc` | int | Viewport width |
| `+0xe0` | int | Viewport height |
| `+0xec` | int | Mode: 0 perspective, 1 ortho |
| `+0xf0` | f32 | Near plane |
| `+0xf4` | f32 | Far plane |
| `+0xf8` | f32 | **Near extent X** (sibling unproject) |
| `+0xfc` | f32 | **Near extent Y** |
| `+0x10c` | f32 | FOV (radians; half used with tan) |
| `+0x110` | f32 | Scale X (cot×aspect×zoom) |
| `+0x114` | f32 | Scale Y |
| `+0x118` | f32 | Ortho left |
| `+0x11c` | f32 | Ortho right |
| `+0x120` | f32 | Ortho bottom |
| `+0x124` | f32 | Ortho top |
| `+0x14d` | u8 | When **0**, use 10000-based Z scale |

---

## 5. Gaps / open

1. Product C++ method name (EnsureProjection / UpdateProjection / CreateProjectionMatrix…).
2. Exact destination offset of the 4×4 written by `FUN_0043f210` (ECX at call — not dualed callee layout).
3. Bit-exact ortho matrix (`FUN_0043f2e0` XMM decompile incomplete).
4. English names for each frustum plane float at `+0x5c..+0xb8`.
5. Runtime golden (dirty flip → extents match FOV).

**Verdict:** **accept-with-gaps** — dirty gate, near/far ε, perspective near-extent formula, mode branch, constants sealed; product names + matrix dest offset + ortho callee open.
