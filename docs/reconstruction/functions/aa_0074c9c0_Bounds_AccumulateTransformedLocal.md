# Function record: Bounds_AccumulateTransformedLocal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074c9c0` |
| **Canonical name** | `Bounds_AccumulateTransformedLocal` |
| **Ghidra name** | `FUN_0074c9c0` |
| **Address** | `0x0074c9c0` |
| **Body range** | `0x0074c9c0`–`0x0074ce55` (Ghidra); epilogue **`ret 12`** |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | graphics / bounds |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; ABI, gate, sphere merge, 8-corner AABB, constants sealed; product English / matrix helper dual open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0074c9c0_Bounds_AccumulateTransformedLocal.md`, `reviews/B_aa_0074c9c0_Bounds_AccumulateTransformedLocal.md` |
| **Last reviewed** | `2026-07-29` (W21-O) |

## Alias

- `FUN_0074c9c0` (Ghidra)
- `Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_0074c9c0` (auto parent-seed — **incomplete**; multi-caller mesh/bounds accumulate)

## Purpose

Accumulate a **local sphere + AABB** volume into a **destination bounds** object after transforming the local volume by a matrix derived from a reference object and scaling the radius by relative object scale vectors. Used when attaching/registering mesh or special-event geometry into a parent/world bounds accumulator (e.g. owner `+0x414`, global `DAT_00d1eb60` as xform ref).

## Signature

```c
// Machine: ECX=dest; stack xformRef, local, scaleSrc; ret 12
void Bounds_AccumulateTransformedLocal(
    BoundsVolume *dest /*ECX*/,
    void *xformRef /*stack0*/,
    BoundsVolume *local /*stack1*/,
    void *scaleSrc /*stack2*/);
```

## Layout (BoundsVolume)

| Offset | Field | Role |
|---:|---|---|
| `+0x00` | center xyz | sphere center |
| `+0x0c` | radius | sphere radius |
| `+0x10` | xzExtent | abs(sqrt((maxx-cx)^2+(maxz-cz)^2)) on dest |
| `+0x14` | aabbMin | local/dest AABB min |
| `+0x20` | aabbMax | local/dest AABB max |
| `+0x2c` | gate | local: skip if ≠0; dest: cleared after update |

## Algorithm

1. If `local.gate != 0` → return.
2. `FUN_0044b5c0(xformRef → matrix)`.
3. Project `local.center` via `FUN_0076f6e0` → world center.
4. `worldR` = scale-ratio × `local.radius` (uniform X or full |scale| path via `+0xb8`).
5. Merge world sphere into `dest` (empty replace / contain / expand with `*0.5`).
6. For corners `i=0..7`, mix local AABB min/max, project, expand dest AABB (with sphere window clamps).
7. `dest.gate = 0`; write `dest.xzExtent`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0074c9c0_FUN_0074c9c0.md`
- Annotated: `docs/reconstruction/raw/aa_0074c9c0_FUN_0074c9c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Bounds_AccumulateTransformedLocal.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0074c9c0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0074c9c0-0044e100-w21o-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0044b5c0`; `FUN_0076f6e0` (Math_Mat4TransformPoint3_Project); SQRT/ABS; `DAT_00a0f298` |
| **Callers (sample)** | `FUN_004bdb10` / `004bdb70` / `004be440` / `004be7d0` / `004bf450` mesh chains; `ClientSpecialEvent_TeleportIn_ctor`; `ClientSpecialEvent_Respawn_Update`; `FUN_007647c0`; `FUN_0096dc80` / `0096daa0`; `FUN_00855ff0` |

## Confidence

| Claim | Level |
|---|---|
| ECX dest + 3 stack + ret 12 | **High** |
| Gate +0x2c early-out | **High** |
| Sphere merge with 0.5f | **High** |
| 8-corner AABB expand | **High** |
| Scale fields +0x9c/+0xa0/+0xa4, flag +0xb8 | **High** use |
| Product class names | Open |
| Exact float-min select bit-identity of AABB chain | **Probable** (decomp-faithful) |
| Runtime / bit-exact | Open |

## Related

- `aa_0076f6e0` Math_Mat4TransformPoint3_Project
- `aa_0044e100` unrelated (this batch peer only)
- ClientSpecialEvent TeleportIn / Respawn attach paths
