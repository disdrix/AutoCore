# Function record: VehiclePaintColor_LookupById_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519d20` |
| **Canonical name** | `VehiclePaintColor_LookupById_Inferred` |
| **Address** | `0x00519d20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | vehicle paint / tint |
| **Completion status** | **Dual A/B present** (2026-07-29); accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_00519d20`
- Prior: `Named_CalleeOf_Named_CalleeOf_Client_RecvInventoryUsePaint_00519d20`

## Purpose

Lookup paint/tint color payload by id in globals `DAT_00b042b4` (mask) / `DAT_00b042bc` (buckets) / `DAT_00b042b8` (count). Lazy-loads via `FUN_00519a30`. Returns first dword of value payload or 0. Distinct from medal table (`DAT_00b042e0`).

## Signature

```c
void* VehiclePaintColor_LookupById_Inferred(uint32_t id);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00519d20_FUN_00519d20.md`
- Annotated: `docs/reconstruction/raw/aa_00519d20_FUN_00519d20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_00519d20.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00519d20_VehiclePaintColor_LookupById_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00519d20_VehiclePaintColor_LookupById_Inferred.md`

## Callers / callees

- Callers: `FUN_004fcd80`, garage `FUN_008801b0`, tooltip/UI many
- Callees: `FUN_00519a30` (lazy)

## Confidence

| Claim | Level |
|---|---|
| Hash lookup CF | **Confirmed** |
| Paint/tint domain | **High** |
| Product payload type | **Open** |
