# Function record: BuildRaceClassSuffix_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f550` |
| **Canonical name** | `BuildRaceClassSuffix_Inferred` |
| **Address** | `0x0051f550` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI / garage resource path suffix |
| **Completion status** | **Dual A/B present** (2026-07-29); accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_0051f550`
- Prior: `Named_CalleeOf_Drive_Vehicle_0051f550` (alias noise — not drive physics)

## Purpose

Clear static buffer `DAT_00b04600`, append race token `_h/_m/_b` (0/1/2) and class token `_c/_e/_o/_r` (0..3) from rodata `0x009ceee0`, return buffer pointer. Used for garage icon paths (`i_d_v_2d_icon_race` + suffix).

## Signature

```c
char* BuildRaceClassSuffix_Inferred(int raceIndex, int classIndex);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051f550_FUN_0051f550.md`
- Annotated: `docs/reconstruction/raw/aa_0051f550_FUN_0051f550.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0051f550.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0051f550_BuildRaceClassSuffix_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0051f550_BuildRaceClassSuffix_Inferred.md`

## Callers / callees

- Callers: `FUN_00521080`, `FUN_008801b0` (garage)
- Callees: none (inline strcat-style)

## Confidence

| Claim | Level |
|---|---|
| Token table bytes | **Confirmed** |
| Race H/M/B mapping | **High** |
| Class c/e/o/r English | **Probable** |
