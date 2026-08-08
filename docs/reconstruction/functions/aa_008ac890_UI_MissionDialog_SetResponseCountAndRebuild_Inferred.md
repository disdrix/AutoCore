# Function record: UI_MissionDialog_SetResponseCountAndRebuild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac890` |
| **Canonical name** | `UI_MissionDialog_SetResponseCountAndRebuild_Inferred` |
| **Ghidra symbol** | `FUN_008ac890` |
| **Address** | `0x008ac890`–`0x008ac8af` exclusive (**31** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / client UI mission dialog |
| **Completion status** | **Dual A/B sealed** (MEGA-109 2026-08-05) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- `FUN_008ac890`
- ~~`Named_CalleeOf_Named_NUM_RESPONSE_COLUMNS_008ac890`~~ (retired)

## Purpose

Thin **response chrome rebuild peer**: write `dialog+0x510` (response count) from EAX with **max 8** clamp, then call dualed `UI_MissionDialog_BuildResponseButtons_Inferred` so the NPC 2d response strip matches the new count.

Primary producer path: XML/string property **`NUM_RESPONSES`** inside `FUN_008ac8b0` (sibling of **`NUM_RESPONSE_COLUMNS`** which stores `+0x640` only).

## Signature (recovered)

```c
// ECX = MissionDialogUi*  |  EAX = requested_count  |  bare RET
void UI_MissionDialog_SetResponseCountAndRebuild_Inferred(void);
```

Readable form:

```c
void UI_MissionDialog_SetResponseCountAndRebuild_Inferred(
    MissionDialogUi* dialog /* ECX */,
    int requested_count /* EAX */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008ac890_FUN_008ac890.md`
- Annotated: `docs/reconstruction/raw/aa_008ac890_FUN_008ac890.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_MissionDialog_SetResponseCountAndRebuild_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_008ac890.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008ac890_UI_MissionDialog_SetResponseCountAndRebuild_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008ac890_UI_MissionDialog_SetResponseCountAndRebuild_Inferred.md`
- Dual report: `docs/agents/task-dual-ab-008ac890-mega-109-report.md`

## Callers / callees

| Direction | Targets |
|---|---|
| Callers | `FUN_008ac8b0` (NUM_RESPONSES); ASCII NUM_RESPONSES @ `0x008ad224`; `FUN_0093e450` (via `FUN_005795b0` size) |
| Callees | `UI_MissionDialog_BuildResponseButtons_Inferred` (`0x008ac110`) |

## Confidence

| Claim | Level |
|---|---|
| Store + clamp + rebuild CF | **High** |
| Field `+0x510` = response count | **High** (peer dual) |
| Max 8 | **High** (immediate + JLE) |
| Product spelling | **Inferred** |
| Runtime | Open |
