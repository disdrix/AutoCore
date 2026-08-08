# Function record: FUN_005fdf20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdf20` |
| **Canonical name** | `hkDefaultAnalogDriverInput_FilterSteer_Inferred` (see named record) |
| **Ghidra name** | `FUN_005fdf20` |
| **Address** | `0x005fdf20`–`0x005fdf97` inclusive (**120 B** / `0x78`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Agent** | MEGA-026 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Leaf piecewise-linear **filtered steer** helper for `hkDefaultAnalogDriverInput`. Computes deadzone → inner ramp → outer ramp+base from raw signed steer at `this+0x1c`, multiplies by sign, returns float on FPU ST0. Sole caller `calcStatus` stores result at status `+0x14`.

## Signature (decompiler-shaped twin)

```c
// Machine: ECX=this; plain RET; float on ST0
float __fastcall FUN_005fdf20(int param_1 /* this */);
```

## Call graph

| Role | Target |
|---|---|
| Callers | `hkDefaultAnalogDriverInput_calcStatus` `0x005fe520` @ `0x005fe58d` |
| Callees | **none** (leaf) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005fdf20_FUN_005fdf20.md`
- Annotated: `docs/reconstruction/raw/aa_005fdf20_FUN_005fdf20.annotated.md`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005fdf20.cpp`
- Clean named: `docs/reconstruction/reconstructed-exact/hkDefaultAnalogDriverInput_FilterSteer_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_005fdf20_hkDefaultAnalogDriverInput_FilterSteer_Inferred.md`
- Review A: `docs/reconstruction/reviews/A_aa_005fdf20_hkDefaultAnalogDriverInput_FilterSteer_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_005fdf20_hkDefaultAnalogDriverInput_FilterSteer_Inferred.md`
- Report: `docs/agents/task-dual-ab-005fdf20-mega-026-report.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow (3-exit piecewise filter) | **Confirmed** |
| ECX=this; plain RET; ST0 return | **Confirmed** |
| Sole caller → +0x14 steer | **Confirmed** |
| Field offsets +0x1c/28/2c/30/34/38 | **Confirmed** |
| Product English | **Inferred** / open |
