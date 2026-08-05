# Function record: CVOGObjectiveRequirement_Collect_DeserializeXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611a00` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_DeserializeXml` |
| **Prior name** | `FUN_00611a00` |
| **Scaffold alias** | `Mission_Mission_collect_objective_requirement_lacking_ch_*` (error-string derived; not primary) |
| **Address** | `0x00611a00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__thiscall` (ECX = Collect req; stack0 = MSXML node) |
| **Completion status** | **Human-refined** — dual A/B sealed 2026-07-29 (static field map) |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Load Collect objective requirement fields from mission XML/MSXML child attributes into the Collect requirement object. Virtual method at **vtable +0x48** on `PTR_FUN_009e12c4`.

Does **not** evaluate progress, grant loot, or mutate inventory.

## Signature

```c
void __thiscall CVOGObjectiveRequirement_Collect_DeserializeXml(
    void* this,          // ECX — CVOGObjectiveRequirement_Collect*
    void* xmlNode);      // stack0 — requirement element (MSXML COM)
```

## Field map

| Offset | XML name | Type / rule |
|-------:|----------|-------------|
| `+0x08` | `slot` (attribute via helper) | byte |
| `+0x10` | `CBID` | i32 item id |
| `+0x14` | `NumToCollect` | i32 need |
| `+0x18` | `TakeAllItems` | bool **(==1)** |
| `+0x19` | `TargetIsPlayer` | bool **(!=0)** |
| `+0x1a` | `TargetIsTemplateVehicle` | bool **(!=0)** |
| `+0x1c` | (count) | i32, max 10 |
| `+0x20`..`+0x44` | `OptionalTargetCBID` | i32[10], init -1 |
| `+0x48` | `OptionalDropPercent` | float (`_wtof`) |
| `+0x4c` | `GiveToAllConvoyMembers` | bool **(==1)** |
| `+0x50` | `AllowedType` | i32 |
| `+0x54` | `AllowedClass` | i32 |
| `+0x58` | level-restriction flag | byte set if Min/Max present |
| `+0x5c` | `RequireLevelMin` | i32 |
| `+0x60` | `RequireLevelMax` | i32 |
| `+0x64` | `ContinentCBID` | i32 |

Post-parse: if `CBID==-1 && !TargetIsPlayer` → error log with mission name.

## Vtable + class

| Item | Value |
|------|-------|
| Class vtable | `PTR_FUN_009e12c4` |
| This slot | `+0x48` → `0x00611a00` (DATA @ `0x009e130c`) |
| Ctor | `0x00611690` type code **2** |
| Action | `+0x04` → `0x00611f20` |
| Eval | `+0x10` → `0x00611940` |
| SlotAction | `+0x18` → `0x006124b0` |

## Callers / callees

| Direction | Targets |
|-----------|---------|
| Callers | **none** (virtual only) |
| DATA xref | `0x009e130c` |
| Callees | `FUN_00799820`, `_wcsicmp`, `_wtol`, `_wtof`, `SysFreeString`, `FUN_0040d230`, `FUN_007a4480`, MSXML COM |

## Artifacts

- Dual A: `docs/reconstruction/reviews/A_aa_00611a00_CVOGObjectiveRequirement_Collect_DeserializeXml.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00611a00_CVOGObjectiveRequirement_Collect_DeserializeXml.md`
- Raw: `docs/reconstruction/raw/aa_00611a00_FUN_00611a00.md`
- Annotated: `docs/reconstruction/raw/aa_00611a00_FUN_00611a00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_Collect_DeserializeXml.cpp`
- Scaffold clean (legacy): `reconstructed-exact/FUN_00611a00.cpp`
- Chain: `reviews/CHAIN_2026-07-29_inventory_collect.md`
- Port: `src/AutoCore.Game/Mission/Requirements/ObjectiveRequirementCollect.cs`

## Confidence

| Claim | Level |
|---|---|
| Role / name | **High** |
| Field offsets + bool polarity | **High / Confirmed** |
| Vtable +0x48 | **High / Confirmed** |
| COM ordinal dictionary | Probable |
| Runtime / PDB / bit-exact | Open |
