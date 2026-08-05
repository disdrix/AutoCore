# Function record: GfxView_UnprojectScreenToWorldRay_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075c340` |
| **Canonical name** | `GfxView_UnprojectScreenToWorldRay_Inferred` |
| **Address** | `0x0075c340` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` (secondary camera / pick ray) |
| **Completion status** | **Dual A/B present** — three-rep refined 2026-07-29; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Alias

| Name | Notes |
|---|---|
| `FUN_0075c340` | Ghidra default / scaffold |
| `Named_CalleeOf_Client_Input_DriveControlTick_0075c340` | Auto parent-seed name (incomplete — multi-caller) |
| `GfxView_UnprojectScreenToWorldRay_Inferred` | **Canonical** — role from CF + sibling `gfxView.cpp` string on `FUN_0075b7f0` |

## Purpose

Convert integer screen pixel coordinates through this **gfxView**’s viewport and projection into a world-space ray: near-plane world point (`param_3`) + direction or ortho origin (`param_4`). Called from DriveControlTick (combat look raycast + SECTION 15 camera slots) and interact click-pick.

## Signature (decompiler-derived)

```c
void __thiscall GfxView_UnprojectScreenToWorldRay_Inferred(
    GfxView *this,      // ECX — param_1
    int *screenXY,      // param_2 — int[2] pixel x,y
    float *outWorldNear,// param_3 — vec3 world near-plane point
    float *outWorldDir  // param_4 — vec3 world unit dir (mode 0) or basis triple (mode 1)
);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0075c340_FUN_0075c340.md`
- Annotated: `docs/reconstruction/raw/aa_0075c340_FUN_0075c340.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GfxView_UnprojectScreenToWorldRay_Inferred.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0075c340_GfxView_UnprojectScreenToWorldRay_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0075c340_GfxView_UnprojectScreenToWorldRay_Inferred.md`
- Scratch: `tmp/a_0075c340.md`

## Callers / callees

**Callers (live xrefs):**

| Function | VA |
|---|---|
| `Client_Input_DriveControlTick` | `0x009223b0` |
| `Client_InteractClickPickTarget` | `0x009247b0` |
| `FUN_00921f70` | `0x00921f70` |
| `FUN_00925820` | `0x00925820` |
| `FUN_00490070` | `0x00490070` |
| `FUN_005995a0` | `0x005995a0` |

**Callees:** `FUN_0075b7f0` (projection ensure / gfxView.cpp), `FUN_00972fa0` (transform point), `FUN_0076f5f0` (normalize3), `FUN_00972e50` (dirty basis rebuild), `FUN_009729d0` (transform direction).

## Layout (this)

| Off | Role |
|---:|---|
| `+0x08` | Basis / transform object |
| `+0xdc` | Viewport width (int) |
| `+0xe0` | Viewport height (int) |
| `+0xec` | Mode: 0 perspective, 1 ortho |
| `+0xf0` | Near plane (f32) |
| `+0xf8` | Near extent X |
| `+0xfc` | Near extent Y |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| NDC `*2−1` + Y flip | **High** (`read_memory` 2.0/1.0) |
| Dual out-params origin + dir | **High** (caller usage) |
| gfxView class | **High** (sibling path string) |
| Product method name | **Inferred** |
| Transform callee internals | **Medium / open** (OWN boundary) |
| Runtime golden | **Open** |
