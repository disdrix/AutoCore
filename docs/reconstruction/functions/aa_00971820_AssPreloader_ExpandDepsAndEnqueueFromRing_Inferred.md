# Function record: AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971820` |
| **Canonical name** | `AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred` |
| **Ghidra name** | `FUN_00971820` |
| **Address** | `0x00971820`–`0x009718fd` (**222 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assPreloader / asset preload pipeline |
| **Completion status** | Dual A/B sealed W32-K 2026-07-29 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

For each key in a caller-supplied GuardedVector ring, expand dependency keys into a local ring and enqueue eligible keys into the AssPreloader pending set via `AssPreloader_EnqueueEligibleFromRing_Inferred`.

## Signature

```c
// ECX = host; stack source ring; RET 4; returns 0
uint32_t AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred(
    void* host /*ECX*/,
    GuardedVectorHeader* source /*stack*/);
```

## Host / local offsets (sealed)

| Off | Role |
|-----|------|
| host `+0x110` | resource cache* (context for `FUN_00744360` via `*(cache+0x64)`) |
| local ring | temp GuardedVector: push key, expand deps, hand to enqueue |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00971820_FUN_00971820.md`
- Annotated: `docs/reconstruction/raw/aa_00971820_FUN_00971820.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00971820.cpp`
- FUN record: `docs/reconstruction/functions/aa_00971820_FUN_00971820.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_00971820_AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred.md`, `B_…`
- Agent report: `docs/agents/task-dual-ab-00971820-00972140-w32k-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI + RET 4 + return 0 | **High** |
| Expand-then-enqueue role | **High** |
| AssPreloader product family | **High** (via callee chain) / method English **Inferred** |
| Nested `FUN_00744360` product plate | **Open** (W32-L) |
| Runtime / bit-exact | **Open** |
