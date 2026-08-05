# Function record: GfxView_EnsureProjection_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075b7f0` |
| **Canonical name** | `GfxView_EnsureProjection_Inferred` |
| **Address** | `0x0075b7f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics / client camera (feeds unproject / pick) |
| **Completion status** | **Dual A/B present** — three-rep refined 2026-07-29; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Alias

| Name | Notes |
|---|---|
| `FUN_0075b7f0` | Ghidra default / scaffold |
| `Named_gfxView_0075b7f0` | Auto string seed from path |
| `GfxView_EnsureProjection_Inferred` | **Canonical** — dirty-gated projection + **near extents** rebuild; path `gfxView.cpp` |

## Purpose

Ensure the **gfxView** projection is current: sync zoom cache, reject near≈far, rebuild perspective or ortho projection matrix, write **near half-extents** at `+0xf8/+0xfc` (consumed by unproject), and fill frustum-plane floats. Early-outs when not dirty.

## Signature (decompiler-derived)

```c
uint32_t /* 0 ok / 0xffffffff fail */ __thiscall GfxView_EnsureProjection_Inferred(
    GfxView *this   // ECX — param_1
);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0075b7f0_FUN_0075b7f0.md`
- Annotated: `docs/reconstruction/raw/aa_0075b7f0_FUN_0075b7f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GfxView_EnsureProjection_Inferred.cpp`
- Prior scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0075b7f0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0075b7f0_GfxView_EnsureProjection_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0075b7f0_GfxView_EnsureProjection_Inferred.md`
- Scratch: `tmp/a_0075b7f0.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_0075b7f0_FUN_0075b7f0.md`

## Callers / callees

**Callers (live xrefs):**

| Function | VA |
|---|---|
| `FUN_0075c340` (`GfxView_UnprojectScreenToWorldRay_Inferred`) | `0x0075c340` |
| `FUN_0075c680` | `0x0075c680` |
| `FUN_0075c6e0` | `0x0075c6e0` |
| `FUN_0075c7e0` | `0x0075c7e0` |
| `FUN_00496920` | `0x00496920` |
| `CVOGTerrainChunker_SubmitForRendering` | `0x005c1940` |

**Callees:** `vog_LogMessage`, `fptan` / `fpatan` / `fcos` / `fsin` / `ABS`, `FUN_0043f210` (16-float matrix write), `FUN_0043f2e0` (ortho matrix fill).

## Layout (this) — near extents focus

| Off | Role |
|---:|---|
| `+0x0c` / `+0x58` | Zoom authoritative / cache |
| `+0x48` | Dirty (rebuild gate) |
| `+0xdc` / `+0xe0` | Viewport W / H (int) |
| `+0xec` | Mode 0 persp / 1 ortho |
| `+0xf0` / `+0xf4` | Near / far |
| `+0xf8` / `+0xfc` | **Near extent X / Y** |
| `+0x10c` | FOV |
| `+0x110` / `+0x114` | Scale X / Y (cot×aspect×zoom) |
| `+0x118..+0x124` | Ortho L/R/B/T |
| `+0x14d` | Gate 10000-based Z scale when 0 |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| Near extents formulas | **High** (`read_memory` constants) |
| Dirty + near/far ε 0.01 | **High** |
| gfxView class (path string) | **High** |
| Product method name | **Inferred** |
| Ortho matrix callee bit-exact | **Medium / open** |
| Runtime golden | **Open** |
