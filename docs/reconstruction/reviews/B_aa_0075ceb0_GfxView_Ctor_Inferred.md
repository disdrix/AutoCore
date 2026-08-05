# Review B (skeptical / adversarial): `aa_0075ceb0` GfxView_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075ceb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-O) |
| **Counterpart** | `reviews/A_aa_0075ceb0_GfxView_Ctor_Inferred.md` |
| **Scratch** | `tmp/a_0075ceb0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Far default is 1000 (`DAT_00a0f520`) | **Falsified as far** — `+0xF4` gets `DAT_00aaa880` (**10000**); `DAT_00a0f520` lands at **`+0x104`**. Factories may later overwrite far. |
| 2 | Near default not 0.5 | **Falsified** — `param_1[0x3c]=DAT_00a0f298` = 0.5; factory SetNear also 0.5 |
| 3 | FOV is degrees 60 stored raw | **Nuance** — stored as **π/3 radians** float, not integer 60 |
| 4 | Not a ctor (init method on live object) | **Falsified** — vtbl install, SEH, return this, called after `operator_new(0x150)` |
| 5 | Class not GfxView | **Falsified as class identity** — path `gfxView.cpp`, effect `PalViewBackground.fx`, layout matches EnsureProjection |
| 6 | Product method name sealed | **Overstated** — structural ctor; demangle open → `_Inferred` |
| 7 | Decompile invents crash path | **Falsified** — strings + `ExitProcess(3)` present in raw/live |
| 8 | Object size unknown | **Falsified** — both code xrefs allocate **0x150** before call |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this / return this | **High** | Wrong construction ABI |
| Size 0x150 | **High** | Heap overrun |
| near/far/FOV defaults | **High** | Camera wrong until factory overrides |
| Path-sealed class | **High** | Mis-bucket unit |
| Transform +0x08 pairing | **Medium** | Null/wrong xform |
| Nested D3D helpers | **Open** | Port stubs incomplete |
| Product demangle | **Inferred** | Naming only |

---

## 3. Cross-check against raw + constants

```
raw: param_1[0x3c] = DAT_00a0f298;  // +0xF0
     param_1[0x3d] = DAT_00aaa880;  // +0xF4
     param_1[0x41] = DAT_00a0f520;  // +0x104
     param_1[0x43] = DAT_00aaa628;  // +0x10C

read_memory:
  0.5 / 10000 / 1000 / π/3  respectively
```

Prologue hex begins with SEH push `LAB_009b25d7` and loads `g_flOne` via `MOVSS` from `0x00a0f2a0`. Epilogue `ADD ESP,0x2C; RET` after FS restore.

Do **not** conflate ctor far **10000** with factory far **1000|500** from W30-F — factory overwrites after SetNear.

---

## 4. Surviving contract for AutoCore

```
// GfxView ctor (pre-alloc 0x150, ECX=this, return this):
//   vtbl PTR_FUN_00a9edc8; zoom=1; aligned transform @ +0x08
//   near=0.5, far=10000, FOV=pi/3, dirty +0x48/+0xCC = 1
//   create background VB + PalViewBackground.fx or ExitProcess(3)
//   success: +0x40=this; zero mid block
// Pair SetNear (0x0075b3b0) / EnsureProjection (0x0075b7f0) after factory overrides.
// Do not invent far=1000 as ctor default.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/defaults/path; residual gaps on nested helpers and demangle → **accept-with-gaps**.
