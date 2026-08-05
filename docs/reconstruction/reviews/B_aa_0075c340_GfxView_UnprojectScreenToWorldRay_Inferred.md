# Review B (skeptical / adversarial): `aa_0075c340` GfxView_UnprojectScreenToWorldRay_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075c340` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual — live Ghidra) |
| **Counterpart** | `reviews/A_aa_0075c340_GfxView_UnprojectScreenToWorldRay_Inferred.md` |
| **System** | `input-drive-control` (secondary) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on NDC→ray CF + dual outs + mode branch; **reject** overclaims that this is drive-steer, is a full camera controller, has a product string name, or that callees are fully dualed |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is the DriveControlTick steer / look-local writer | **Falsified** — no `SetSteerInput`, no `local_d*`, no `entity+0x618` |
| 2 | Function has a retail string name | **Falsified** — body has no string; gfxView class string lives on **sibling** `FUN_0075b7f0` |
| 3 | `g_flLevelUpUiBase_Inferred` is a UI level-up constant here | **Falsified as semantics** — image float is **2.0** (NDC scale); name is global misnomer |
| 4 | Single output vector | **Falsified** — always fills `param_3` triple; mode 0/1 also fill `param_4` |
| 5 | Mode 0 and mode 1 same dir path | **Falsified** — mode 0 normalize+transform local; mode 1 copies basis `+0x20..28` |
| 6 | Always writes `param_4` | **Falsified** — mode ∉ {0,1} leaves `param_4` unchanged |
| 7 | Y is not flipped | **Falsified** — `ly = scaleY * (0 − ny)` |
| 8 | `this` is the vehicle entity | **Falsified** — ECX is gfxView; call sites load view from `+0xe890`, `+0x2a4`, camera `+0xc0` |
| 9 | Scaffold “Named_CalleeOf_DriveControlTick” is the only caller | **Falsified** — 6 callers including InteractClickPick |
| 10 | Ready for bit-exact port of transform chain | **Fail** — `FUN_00972fa0` / `FUN_009729d0` decompile is register-arg messy; not sealed OWN |
| 11 | Projection ensure is optional / no-op | **Falsified** — always called; rebuilds `+0xf8/+0xfc` when dirty (sibling body) |
| 12 | Constants are invent | **Falsified** — `read_memory` 1.0 / 2.0 |

---

## 2. Decisive dataflow (raw ≡ live)

```
// ECX = gfxView*
nx = (float)screen[0] / (float)this->width  * 2.0 - 1.0
ny = (float)screen[1] / (float)this->height * 2.0 - 1.0
FUN_0075b7f0(this)                         // ensure projection / near extents

local.x = this->nearExtentX * nx           // +0xf8
local.y = this->nearExtentY * (-ny)        // +0xfc
local.z = this->nearZ                      // +0xf0

param_3[0..2] = Transform(local)           // FUN_00972fa0

if this->mode == 0:                        // +0xec
  param_4 = Normalize(local)               // FUN_0076f5f0
  if dirty(*(this+8)): FUN_00972e50()
  FUN_009729d0(param_4)                    // world direction
elif this->mode == 1:
  basis = *(this+8)
  if dirty(basis): basis = FUN_00972e50()
  param_4 = *(vec3*)(basis + 0x20)
else:
  return                                   // param_4 untouched
```

Live re-decompile 2026-07-29 matches 2026-07-23 raw capture.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| NDC + Y flip + near local | **High** | Wrong aim ray / inverted pitch |
| Viewport ints at `+0xdc/+0xe0` | **High** | Div0 / wrong FOV stretch |
| Mode 0 unit world dir | **High** | Raycast direction inverted/unnormalized |
| Mode 1 basis triple | **High CF** | Ortho path wrong origin |
| Dual outs used as origin+dir by DCT | **High** | Camera slots / pick miss |
| gfxView class (sibling string) | **High** | Wrong type ownership |
| Product method name | **Inferred only** | Naming debt |
| Transform callee bit-exact | **Open / Medium** | Port matrix mismatch |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `*2−1` NDC | Guess? | **No** — body uses named 2.0/1.0 globals; bytes re-read |
| `+0xf8 * nx` | Invented scale? | **No** — live; sibling writes those fields from FOV |
| Y flip | Optional? | **Required** — `(0.0 - fVar4)` |
| Normalize only mode 0 | Also mode 1? | **No** — mode 1 skips normalize path |
| Dirty bit before dir xform | Dead? | **No** — both arms test `+0xbc & 1` |
| Drive axis side effect | Hidden? | **None** |
| Only DCT callee | Unique? | **No** — pick + 4 other FUN_* |
| `g_flLevelUpUiBase` product meaning here | UI XP? | **No** — pure **2.0** constant |

---

## 5. Surviving contract for AutoCore

```
GfxView_UnprojectScreenToWorldRay(view, screenXY[2], outNear[3], outDir[3]):
  nx, ny = pixel_to_ndc(screenXY, view.width, view.height)  // *2-1, y later flipped
  EnsureProjection(view)
  local = (view.nearExtX * nx, view.nearExtY * (-ny), view.nearZ)
  outNear = CameraTransformPoint(view.basis, local)
  if view.mode == perspective:
    outDir = Normalize(local); DirtyResolve(basis); outDir = CameraTransformDir(outDir)
  elif view.mode == ortho:
    outDir = basis.position_xyz   // +0x20
  // else: outDir unchanged
```

Port must preserve: integer viewport divisors, Y flip, always-call ensure, dual outs, mode trichotomy.

---

## 6. Open attacks (remain)

1. Is mode-1 triple **position** or **direction** in product docs? Body is a plain copy — callers may interpret either way; DCT combat paths observed use mode-0 primarily.
2. `FUN_00972fa0` decompiler register confusion (`in_EAX` / `unaff_EDI`) — do not claim bit-exact matrix without a dedicated dual.
3. Screen buffer at DCT: globals `DAT_00d1d86c/870` are stored into stack then passed as `int*` — confirm they remain integer pixels at all call sites (High for epilogue; other sites use `DAT_00d17948+0xc/0x10`).

---

## 7. Verdict

Agree with A: **accept-with-gaps**. Reject any claim that this unit is drive control, that the Ghidra symbol `g_flLevelUpUiBase_Inferred` is domain-correct here, or that the transform callees are finished. Body CF for OWN VA is **High**.
