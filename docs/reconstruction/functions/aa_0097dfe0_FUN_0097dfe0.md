# Function record: UI_DataGaugeWidget_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0097dfe0` |
| **Canonical name** | `UI_DataGaugeWidget_ctor` |
| **Ghidra alias** | `UI_CooldownGaugeWidget_ctor` |
| **Former name** | `FUN_0097dfe0` |
| **Address** | `0x0097dfe0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / quickbar cooldown gauge |
| **Completion status** | **Dual A/B complete** (2026-07-29) — three-rep scaffold present; accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (static decompile only) |

## Purpose

UI **data/cooldown gauge** widget constructor (size **`0x4bc`**). Base `FUN_00863f10`, vtable `PTR_FUN_00a62454`, tail defaults at `+0x4a8..+0x4b8`. Used by QuickBar builders and other UI factories. Not cooldown update math.

## Signature (sealed)

```c
void * UI_DataGaugeWidget_ctor(void *this);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0097dfe0_FUN_0097dfe0.md`
- Annotated: `docs/reconstruction/raw/aa_0097dfe0_FUN_0097dfe0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0097dfe0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0097dfe0_UI_DataGaugeWidget_ctor.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0097dfe0_UI_DataGaugeWidget_ctor.md`

## Callers / callees

| Direction | Symbol | Note |
|---|---|---|
| Callers | `QuickBar_BuildItemButtonWidgets`, `QuickBar_BuildSkillButtonWidgets`, multiple UI `FUN_008*` | multi-use |
| Callee | `FUN_00863f10` | base widget ctor |

## Confidence

| Claim | Level |
|---|---|
| Thin ctor field inits | **High** |
| Cooldown-gauge product role | **High** (XML/callers) |
| Data vs Cooldown English name | **Medium** (dual aliases) |
| Constant semantics 15/4/`DAT_00d1e504` | **Low–Medium** |
| Runtime | **Open** |
