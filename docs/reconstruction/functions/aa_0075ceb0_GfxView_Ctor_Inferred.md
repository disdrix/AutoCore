# Function record: GfxView_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075ceb0` |
| **Canonical name** | `GfxView_Ctor_Inferred` |
| **Address** | `0x0075ceb0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics / client camera (GfxView) |
| **Completion status** | **Dual A/B present** — refined 2026-07-29 W31-O; nested product English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Alias

| Name | Notes |
|---|---|
| `FUN_0075ceb0` | Ghidra default / scaffold |
| `Named_gfxView_0075ceb0` | Auto string seed from `gfxView` |
| `GfxView_Ctor_Inferred` | **Canonical** — path-sealed ctor |

## Purpose

Construct a **GfxView** instance (product source `graphics\gfxView.cpp`) on a pre-allocated **0x150** block: vtbl, zoom, aligned transform, identity matrices, default near/far/FOV, background vertex buffer + `PalViewBackground.fx`, or hard-abort on severity-3 failure.

## Signature (sealed)

```c
// ECX = GfxView* (0x150); returns this; SEH; plain RET after ADD ESP,0x2C
GfxView * __fastcall GfxView_Ctor_Inferred(GfxView *this);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0075ceb0_FUN_0075ceb0.md`
- Annotated: `docs/reconstruction/raw/aa_0075ceb0_FUN_0075ceb0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GfxView_Ctor_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0075ceb0.cpp`
- Prior named scaffold: `docs/reconstruction/reconstructed-exact/Named_gfxView_0075ceb0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0075ceb0_GfxView_Ctor_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0075ceb0_GfxView_Ctor_Inferred.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_0075ceb0_FUN_0075ceb0.md`
- Scratch: `docs/reconstruction/tmp/a_0075ceb0.md`

## Callers / callees

**Callers (2):**

| Function | Site |
|---|---|
| `FUN_004cda90` (`Client_InitPalantirViewBundle_Inferred`) | `0x004cdac8` |
| `FUN_00968a50` | `0x00968a71` |

**Callees:** `_aligned_malloc`, `FUN_00972cc0`, `FUN_0073f590`, `FUN_0043f780`×2, `FUN_00414bc0`, `FUN_00414c20`, `FUN_00414b60`, `FUN_00989e00`, `FUN_009701d0`, `FUN_0076d1b0`, `fopen`/`fprintf`/`fclose`, `raise`, `ExitProcess`.

## Layout (highlights)

| Off | Default | Role |
|---:|---|---|
| `+0x00` | `PTR_FUN_00a9edc8` | vtbl |
| `+0x08` | aligned xform | 0xC0 @ 16 |
| `+0x0C` | 1.0 | zoom |
| `+0x40` | self (ok path) | back-pointer |
| `+0x48` / `+0xCC` | 1 | dirty flags |
| `+0xF0` / `+0xF4` | 0.5 / 10000 | near / far |
| `+0x104` | 1000 | separate float |
| `+0x10C` | π/3 | FOV |
| `+0x14D` | 0 | Z-scale gate |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** (≡ raw) |
| Product path / effect strings | **High** |
| Near/far/FOV/zoom constants | **High** (`read_memory`) |
| Object size 0x150 | **High** (factories) |
| Nested D3D helper product names | **Open** |
| Transform return EAX/EDX pairing | **Medium** |
| Product MSVC demangle | **Inferred** |
| Runtime golden | **Open** |
