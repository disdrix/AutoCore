# Review B (skeptical / adversarial): `aa_0075b7f0` GfxView_EnsureProjection_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075b7f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual — live Ghidra) |
| **Counterpart** | `reviews/A_aa_0075b7f0_GfxView_EnsureProjection_Inferred.md` |
| **System** | graphics / client camera |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on dirty gate + near/far ε + mode trichotomy + **near extent** formulas + constants; **reject** overclaims that this is unproject, is a camera controller, names product matrix slots without evidence, or that `FUN_0043f2e0` is bit-exact sealed |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This unprojects screen→world | **Falsified** — no screen args; rebuilds projection + extents only |
| 2 | Always rebuilds every call | **Falsified** — early return 0 when `+0x48 == 0` |
| 3 | Near/far always accepted | **Falsified** — `|f−n| < 0.01` logs and returns `0xffffffff` |
| 4 | ε is invent / 1e-6 | **Falsified** — `read_memory` `0x00a0f718` = **0.01** |
| 5 | FOV used full-angle in tan | **Falsified** — multiplies by **0.5** (`DAT_00a0f298`) first |
| 6 | Near extents = scales | **Falsified** — extents = `near * (1/scale)` → `+0xf8/+0xfc` |
| 7 | Aspect always width/height | **Falsified** — branch `height < width` swaps which axis gets raw cot |
| 8 | Z scale always 1 | **Falsified** — when `+0x14d == 0`, `10000/(10000−near)` |
| 9 | Mode 1 uses FOV | **Falsified** — ortho path uses `+0x118..+0x124` rect + invZoom |
| 10 | Modes other than 0/1 rebuild | **Falsified** — `mode != 1` after failed mode-0 test → `goto` epilogue only |
| 11 | Class is vehicle / drive | **Falsified** — path `…\graphics\gfxView.cpp` |
| 12 | `DAT_00aaa880` is UI XP | **Falsified as use here** — pure **10000.0** Z constant |
| 13 | `FUN_0043f2e0` sealed bit-exact | **Fail** — decompiler loses L/R/T in XMM; role only |
| 14 | Product method name known | **Fail** — role inferred; no method string |
| 15 | Returns void | **Falsified** — `0` / `0xffffffff` |

---

## 2. Decisive dataflow (raw ≡ live)

```
// ECX = gfxView*
if (zoomCache(+0x58) != zoom(+0xc)):
  dirty(+0x48) = 1; zoomCache = zoom
if !dirty: return 0
if abs(far(+0xf4) - near(+0xf0)) < 0.01:
  vog_LogMessage(gfxView.cpp, 0xa9, 3, "Couldn't create projection matrix, near and far planes too close.")
  return 0xffffffff

if mode(+0xec) == 0:
  cot = 1/tan(fov(+0x10c)*0.5)
  aspect-correct → sx,sy; sx*=zoom; sy*=zoom   // +0x110/+0x114
  zScale = (+0x14d==0) ? 10000/(10000-near) : 1
  FUN_0043f210( matrix with sx,sy,zScale,1,-near*zScale, … )
  +0xf8 = near/sx;  +0xfc = near/sy
  // atan half-angles → sin/cos plane block; +0x49=1
elif mode == 1:
  invZ = 1/zoom
  FUN_0043f2e0(bottom*invZ, near, far)   // ortho matrix (XMM messy)
  +0xf8 = (right-left)*invZ*0.5
  +0xfc = (top-bottom)*invZ*0.5
  // axis planes; +0x49=1
// else: no rebuild

dirty = 0; ready(+0xcc) = 1; return 0
```

Live re-decompile 2026-07-29 matches 2026-07-23 raw capture.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dirty + zoom sync | **High** | Stale projection / skip needed rebuild |
| Near/far ε 0.01 | **High** | Silent matrix or false fail |
| Persp near extents near/sx, near/sy | **High** | Unproject ray wrong FOV stretch |
| Half-FOV tan path | **High** | Double/half FOV bug |
| Mode 0/1/other trichotomy | **High** | Wrong matrix family |
| Ortho rect extents ×0.5 | **High CF** | Ortho pick scale wrong |
| gfxView ownership | **High** | Wrong type |
| Product method name | **Inferred only** | Naming debt |
| Matrix dest offset / FUN_0043f2e0 | **Open / Medium** | Port matrix mismatch |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `+0xf8 = near/sx` | Invented? | **No** — `near * (g_flOne / +0x110)` live |
| ε 0.01 | Guess? | **No** — bytes re-read |
| FOV ×0.5 | Full FOV? | **No** — `DAT_00a0f298` = 0.5 |
| Aspect branch | Always W/H? | **No** — `if height < width` swaps cot axis |
| Z 10000 path | Always? | **No** — gated on `+0x14d == 0` |
| Ortho uses FOV | Same as persp? | **No** — rect + invZoom only |
| Early-out when clean | Always rebuild? | **No** — return 0 if `+0x48==0` |
| Drive-axis side effect | Hidden? | **None** |
| Sibling unproject dependency | Optional? | **No** — unproject always calls this first |

---

## 5. Surviving contract for AutoCore

```
GfxView_EnsureProjection(view) -> int:
  if view.zoomCache != view.zoom:
    view.dirty = true; view.zoomCache = view.zoom
  if !view.dirty: return 0
  if abs(view.far - view.near) < 0.01:
    log(gfxView.cpp:0xa9, near/far too close); return -1

  if view.mode == perspective:
    cot = 1/tan(view.fov * 0.5)
    (sx, sy) = aspect_correct(cot, width, height) * zoomCache
    zScale = (view.zFlag14d == 0) ? 10000/(10000 - near) : 1
    WritePerspMatrix(sx, sy, zScale, near)
    view.nearExtX = near / sx
    view.nearExtY = near / sy
    WritePerspPlanesFromAtan(1/sx, 1/sy, …)
  elif view.mode == ortho:
    invZ = 1 / zoomCache
    WriteOrthoMatrix(…)
    view.nearExtX = (right - left) * invZ * 0.5
    view.nearExtY = (top - bottom) * invZ * 0.5
    WriteOrthoPlanes(…)
  // else: no matrix/extent write

  view.dirty = false
  view.ready = true
  return 0
```

Port must preserve: dirty early-out, 0.01 ε, half-FOV tan, aspect swap, near/scale extents, 10000 Z gate, ortho half-width extents, return codes.

---

## 6. Open attacks (remain)

1. Where is the 4×4 projection matrix stored on `gfxView` (ECX into `FUN_0043f210`)?
2. Full product names for plane slots `+0x5c..+0xb8` (left/right/top/bottom/near/far rows?).
3. `FUN_0043f2e0` SSE path — recover L/R/T from assembly if ortho port is required.
4. Whether `+0x10c` is vertical FOV or horizontal (body uses it once then aspect-corrects — convention open).
5. Runtime: dirty clear + extent values under known FOV/viewport.

---
