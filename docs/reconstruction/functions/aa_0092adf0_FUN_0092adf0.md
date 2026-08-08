# Function record: FUN_0092adf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092adf0` |
| **Canonical name** | `TargetFilter_FindNearestWorldObjByCbidList_Inferred` |
| **Ghidra name** | `FUN_0092adf0` |
| **Address** | `0x0092adf0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / inventory-adjacent |
| **Completion status** | **Dual A/B complete** (WQ8R-I 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (static seal only) |

## Purpose

Alias record for Ghidra `FUN_0092adf0`. See named record:

`docs/reconstruction/functions/aa_0092adf0_TargetFilter_FindNearestWorldObjByCbidList_Inferred.md`

## Signature

```c
// EDI = ctx; ret 0x0C
uint32_t FUN_0092adf0(float *origin, void **bestOut, float *bestDistSq);
```

## Artifacts

- Named clean: `reconstructed-exact/TargetFilter_FindNearestWorldObjByCbidList_Inferred.cpp`
- Twin: `reconstructed-exact/FUN_0092adf0.cpp`
- Raw / annotated / dual A/B under `aa_0092adf0_*`

## Confidence

| Claim | Level |
|---|---|
| Control flow + inventory Find gate | **High / Sealed** |
| Canonical name product English | **Tentative** |
