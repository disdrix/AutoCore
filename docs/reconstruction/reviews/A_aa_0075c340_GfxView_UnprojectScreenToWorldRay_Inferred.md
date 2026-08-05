# Review A (reconstruction fidelity): `aa_0075c340` GfxView_UnprojectScreenToWorldRay_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075c340` |
| **VA** | `0x0075c340` |
| **Canonical name** | `GfxView_UnprojectScreenToWorldRay_Inferred` |
| **Prior scaffold names** | `FUN_0075c340`, `Named_CalleeOf_Client_Input_DriveControlTick_0075c340` |
| **Review date** | `2026-07-29` (OWN-ONLY dual — live Ghidra decompile + `read_memory` constants + call-site ECX) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_0075c340_GfxView_UnprojectScreenToWorldRay_Inferred.md` |
| **System** | `input-drive-control` (secondary camera / pick ray; also interact-click) |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`thiscall` method on a **gfxView** object (sibling `FUN_0075b7f0` logs `…\graphics\gfxView.cpp`). Converts an integer **screen pixel** `(x,y)` into a world-space **ray**:

1. NDC map: `nx = (x / width) * 2 − 1`, `ny = (y / height) * 2 − 1`  
   (`width = this+0xdc`, `height = this+0xe0`; scale constants **2.0** @ `0x00a10e74`, **1.0** @ `0x00a0f2a0`).
2. Ensure projection/view scales fresh via `FUN_0075b7f0(this)` (rebuilds `+0xf8/+0xfc` from FOV/near when dirty).
3. Camera-local near-plane point:
   - `lx = *(this+0xf8) * nx`
   - `ly = *(this+0xfc) * (−ny)`  // Y flip
   - `lz = *(this+0xf0)`          // near plane
4. **`outWorldNear` (param_3)** ← transform local point through camera matrix (`FUN_00972fa0`).
5. Branch on projection mode `*(this+0xec)`:
   - **0 (perspective):** copy local → `outDir`, **normalize** (`FUN_0076f5f0`), optionally dirty-resolve camera basis (`FUN_00972e50` when `*(this+8)+0xbc & 1`), transform direction (`FUN_009729d0`) → **`outWorldDir` (param_4)**.
   - **1 (ortho):** `outWorldDir` ← copy three floats from basis object at `*(this+8)` (+ optional dirty resolve) offsets `+0x20/+0x24/+0x28` (camera world position / basis origin — not the normalized local ray).
   - **else:** only `param_3` written; `param_4` untouched.

**Does not** write vehicle drive axes (`+0x614/+0x618/+0x61c`). Used by DriveControlTick for combat look raycast + SECTION 15 world camera slot fill, and by interact click-pick.

**Calling convention:** MSVC `__thiscall` — gfxView `this` in **ECX**; stack: `int* screenXY`, `vec3* outWorldNear`, `float* outWorldDir`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0075c340_FUN_0075c340.md` |
| Annotated | `docs/reconstruction/raw/aa_0075c340_FUN_0075c340.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxView_UnprojectScreenToWorldRay_Inferred.cpp` |
| Prior scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0075c340.cpp` |
| Function record | `docs/reconstruction/functions/aa_0075c340_GfxView_UnprojectScreenToWorldRay_Inferred.md` |
| System map | `docs/reconstruction/systems/input-drive-control.md` (camera residual context) |
| Parent | `Client_Input_DriveControlTick` `0x009223b0` (×3 call sites) |
| Sibling projector | `FUN_0075b7f0` `0x0075b7f0` (gfxView.cpp string; projection rebuild) |
| Scratch | `tmp/a_0075c340.md` |

**This pass (live):** Ghidra `decompile_function` @ `0x0075c340`; `batch_decompile` callees `0x0075b7f0`, `0x00972fa0`, `0x0076f5f0`, `0x00972e50`, `0x009729d0` (roles only — OWN body is 75c340); `get_function_callers`; `get_assembly_context` at DCT/pick call sites; `read_memory` `0x00a0f2a0` / `0x00a10e74`. **Not performed:** Launcher, runtime golden, bit-exact binary diff, full dual of callees.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body CF ≡ 2026-07-23 raw ≡ live decompile | **High** | Byte-identical control structure |
| `__thiscall` gfxView `this` in ECX | **High** | Params: ECX + 3 stack; call sites load view into ECX |
| Screen args are int pixel x,y | **High** | Cast to float; divided by int width/height |
| NDC formula `(p/size)*2 − 1` | **High** | `read_memory`: 2.0 LE `00 00 00 40`, 1.0 LE `00 00 80 3f` |
| `this+0xdc` / `+0xe0` = viewport W/H (int) | **High** | Used as divisors; sibling projector same offsets |
| `this+0xf0` = near plane Z (f32) | **High** | Copied to local Z; sibling uses as near |
| `this+0xf8/+0xfc` = view half-extents at near | **High** | Written by `FUN_0075b7f0` from FOV/aspect |
| `this+0xec` mode 0 = perspective, 1 = ortho | **High CF** | Sibling projector branches same enum; product enum name open |
| Mode 0: param_4 = unit **world direction** | **High** | normalize + transform; DCT raycast / ground intersect |
| Mode 0/always: param_3 = world near-plane **point** | **High CF** | Caller uses as ray origin |
| Mode 1: param_4 from basis `+0x20..+0x28` | **High CF** | Direct float triple copy |
| Dirty bit `*(this+8)+0xbc & 1` → `FUN_00972e50` | **High** | Both modes |
| Y flip via `(0 − ny)` | **High** | Explicit in body |
| Callee `FUN_0075b7f0` is gfxView projection ensure | **High** | Path string `gfxView.cpp` |
| Does not touch drive axes | **High** | Zero axis stores; pure out-params |
| Product C++ method name | **Inferred** | No local string; role from CF + sibling path |
| Full transform math of `FUN_00972fa0` / `FUN_009729d0` | **Medium** | OWN uses them as black-box world map; not dualed here |
| Ortho mode semantic product name | **Tentative** | Mode id sealed; marketing name open |
| Runtime golden (mouse→ray) | **Open** | Deferred |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| NDC x/y from pixel / viewport | **Yes** |
| Call projection ensure | **Yes** |
| Local near point from scales × NDC + near Z | **Yes** |
| World-transform local → `param_3` triple | **Yes** |
| Mode 0: copy local → normalize → dirty? → dir transform → `param_4` | **Yes** |
| Mode 1: basis origin triple → `param_4` | **Yes** |
| Mode other: early return after `param_3` only | **Yes** |
| No invent drive-axis / ActionMap side effects | **Yes** |

### 4.1 Formula (sealed body)

```
// this = gfxView*
nx = (float)screen[0] / (float)*(int*)(this+0xdc) * 2.0f - 1.0f
ny = (float)screen[1] / (float)*(int*)(this+0xe0) * 2.0f - 1.0f
EnsureProjection(this)   // FUN_0075b7f0
local = { *(this+0xf8)*nx, *(this+0xfc)*(-ny), *(this+0xf0) }
outNear = TransformPoint(cameraBasis, local)   // FUN_00972fa0 → param_3

if mode == 0:  // perspective
  outDir = Normalize(local)                    // FUN_0076f5f0
  if dirty(basis): RebuildBasis(basis)         // FUN_00972e50
  outDir = TransformDirection(outDir)          // FUN_009729d0 → param_4
elif mode == 1:  // ortho
  basis = *(this+8)
  if dirty(basis): basis = RebuildBasis(basis)
  outDir = { basis+0x20, +0x24, +0x28 }        // position triple
// else: param_4 unchanged
```

Constants (this pass `read_memory`):

| Symbol (Ghidra) | VA | LE hex | f32 |
|---|---|---|---:|
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | **1.0** |
| `g_flLevelUpUiBase_Inferred` (misnomer; used as **2.0**) | `0x00a10e74` | `00 00 00 40` | **2.0** |

### 4.2 Callers (live xrefs — roles only)

| Caller | VA | ECX setup (asm) | Use of outs |
|---|---|---|---|
| `Client_Input_DriveControlTick` | `0x009223b0` ×3 | e.g. `[obj+0xe890]`, `[ESI+0x2a4]`, `*(*(DAT_00d1b644+0xe894)+0xc0)` | combat look raycast `FUN_004cff70`; SECTION 15 ground project → camera slots `+0x11c/120/124` |
| `Client_InteractClickPickTarget` | `0x009247b0` | `[EBX+0x2a4]` | click pick ray |
| `FUN_00921f70`, `FUN_00925820`, `FUN_00490070`, `FUN_005995a0` | misc | view host | secondary consumers |

### 4.3 Layout on `this` (body-backed)

| Off | Type | Role |
|---:|---|---|
| `+0x08` | ptr | Camera basis / transform object |
| `+0xdc` | int | Viewport width |
| `+0xe0` | int | Viewport height |
| `+0xec` | int | Projection mode (0 persp / 1 ortho) |
| `+0xf0` | f32 | Near plane |
| `+0xf8` | f32 | Horizontal near extent (× NDC x) |
| `+0xfc` | f32 | Vertical near extent (× −NDC y) |

Basis object (`*(this+8)`):

| Off | Role |
|---:|---|
| `+0xbc` bit0 | Dirty — rebuild before use |
| `+0x20..+0x28` | Mode-1 triple written to `param_4` |

---

## 5. Relationship to DriveControlTick camera residual

- Look **locals** (`local_d*`) and **steer** (`entity+0x618`) are separate (prior camera dual).
- This unit is the **screen→world ray** helper behind SECTION 15 world camera slots and some combat look raycasts.
- Screen input at DCT epilogue: `DAT_00d1d86c` / `DAT_00d1d870` (cursor/viewport pixel pair) packed into stack `fStack_b4` (decompiler shows float store of those DWORDs — pixel ints bit-cast into the two-int buffer).
- Epilogue consumes outs as ray origin + dir, intersects ground (`FUN_004cd220` + t = (oy−groundY)/|dy|), writes `*(camObj+0x11c/120/124)`.

---

## 6. Gaps (accept)

1. Product method name (no string in this body) — `_Inferred`.
2. Full matrix math inside `FUN_00972fa0` / `FUN_009729d0` (not OWN dual).
3. Ortho mode field names at basis `+0x20` (position vs other) — used as triple copy only.
4. Runtime mouse golden / multi-monitor edge cases.
5. Whether `param_3` is exactly near-plane world point vs camera-origin-plus — CF matches near-local transform; product comment open.

---

## 7. Verdict

**accept-with-gaps** — NDC math, viewport/mode offsets, dual out-params, perspective normalize path, and caller ECX view hosts are **High**. Product naming and deep transform callees remain open; not a blocker for DCT camera-slot provenance.
