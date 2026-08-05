# Function record: UI_VehicleInvSheet_RebuildStatsLabels_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0087d810` |
| **Canonical name** | `UI_VehicleInvSheet_RebuildStatsLabels_Inferred` |
| **Address** | `0x0087d810` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `inventory-transfer` |
| **Completion status** | **Dual-sealed** (A/B 2026-07-29) — structural; not bit-exact full body |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Ghidra name** | `FUN_0087d810` |

## Purpose

Vehicle inventory sheet stats/label rebuild. Stack `sheet*`. Gates on `DAT_00d1b644`, `DAT_00d1b6d8`, `sheet+0x514`. Empty bind clears label widgets `+0x55c..+0x580`; full path fills name/DPS/power-heat/range/resists/size text (locale + sprintf). Client UI only.

## Signature

```c
void UI_VehicleInvSheet_RebuildStatsLabels_Inferred(void* sheet /* stack */);
```

## Callers / callees

- Callers: `FUN_008800e0`, `FUN_00802b70`, `FUN_00802c80`
- Callees: `FUN_007a6de0`, `sprintf`, vehicle pool getters, many UI vfuncs, `FUN_0087d690`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0087d810_FUN_0087d810.md`
- Annotated: `docs/reconstruction/raw/aa_0087d810_FUN_0087d810.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0087d810.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0087d810_UI_VehicleInvSheet_RebuildStatsLabels_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0087d810_UI_VehicleInvSheet_RebuildStatsLabels_Inferred.md`

## Confidence

| Claim | Level |
|---|---|
| Gates + widget map + string roles | High |
| Full numeric formulas bit-exact | Open |
