# Function record: hkDefaultAnalogDriverInput_FilterSteer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdf20` |
| **Canonical name** | `hkDefaultAnalogDriverInput_FilterSteer_Inferred` (**Inferred** — product helper English open) |
| **Ghidra name** | `FUN_005fdf20` |
| **Prior scaffold** | `FUN_005fdf20` (scaffold clean/function record; no Named_CalleeOf_* present) |
| **Address** | `0x005fdf20`–`0x005fdf97` inclusive (**120 B** / `0x78`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Agent** | MEGA-026 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Purpose

Classic **deadzone + dual-slope** filtered steering on the Havok-style analog driver input object. Reads raw signed steer at `+0x1c` and filter knobs at `+0x28..+0x38`; returns signed filtered steer on FPU ST0. Leaf (no callees).

```text
abs = |raw(+0x1c)|
if abs < deadzone(+0x38): return 0
sign = (raw > 0) ? +1 : −1
if abs < inner(+0x28): return (abs − deadzone) * slope_inner(+0x2c) * sign
else: return ((abs − inner) * slope_outer(+0x30) + base(+0x34)) * sign
```

## Signature

```c
// __thiscall: ECX = this; no stack args; plain RET; float on ST0
float __thiscall hkDefaultAnalogDriverInput_FilterSteer_Inferred(
    hkDefaultAnalogDriverInput *this);
```

## Layout (this — reads)

| Offset | Field |
|---|---|
| +0x1c | raw signed steer input |
| +0x28 | inner-zone upper threshold |
| +0x2c | inner-zone slope |
| +0x30 | outer-zone slope |
| +0x34 | outer-zone base / intercept |
| +0x38 | deadzone threshold |

Caller-owned status slots (not written here): `+0x0c` accel, `+0x10` brake, **`+0x14` steer (written by calcStatus from this return)**, `+0x18` handbrake, `+0x19` reverse.

## Globals

| Symbol | VA | Value |
|---|---|---|
| `g_flZero` | `0x00a0f518` | `0.0f` |
| `g_flOne` | `0x00a0f2a0` | `1.0f` |
| `DAT_00aaa668` | `0x00aaa668` | `−1.0f` |

## Call graph

| Role | Target |
|---|---|
| **Callers (1)** | `hkDefaultAnalogDriverInput_calcStatus` `0x005fe520` site `0x005fe58d` |
| Callees | **none** (leaf) |
| Sibling | `hkDefaultAnalogDriverInput_calcReverse` `0x005fe0b0` |

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/hkDefaultAnalogDriverInput_FilterSteer_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005fdf20.cpp`
- Raw: `docs/reconstruction/raw/aa_005fdf20_FUN_005fdf20.md`
- Annotated: `docs/reconstruction/raw/aa_005fdf20_FUN_005fdf20.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_005fdf20_hkDefaultAnalogDriverInput_FilterSteer_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005fdf20_hkDefaultAnalogDriverInput_FilterSteer_Inferred.md`
- Report: `docs/agents/task-dual-ab-005fdf20-mega-026-report.md`
- FUN record: `docs/reconstruction/functions/aa_005fdf20_FUN_005fdf20.md`

## Confidence

| Claim | Level |
|---|---|
| Filtered-steer CF | **Confirmed** |
| thiscall ECX=this; plain RET; ST0 | **Confirmed** |
| Caller set (1) → +0x14 | **Confirmed** |
| Constants 0 / +1 / −1 | **Confirmed** |
| Product helper English | **Inferred** / open |
