# Function record: Client_SelectHostileUnderScreenPick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921f70` |
| **Canonical name** | `Client_SelectHostileUnderScreenPick_Inferred` |
| **Address** | `0x00921f70`–`0x009221de` (**623** bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` / client target pick |
| **Completion status** | **Dual A/B sealed** (accept-with-gaps) — 2026-07-29 W20-Q |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_00921f70` | Ghidra default |
| `Client_SelectHostileUnderScreenPick_Inferred` | **canonical** (role; no product string) |

## Purpose

Screen-cursor unproject → ray/height hit → distance-scaled hostile gather (mode **2**, max **1**, range = `0.375 * dist` capped at **40**) → `Client_SelectTargetObject` (or clear). Returns **0** if local char missing / busy (`+0x4f1`); else **1**.

## Signature (sealed)

```c
// __cdecl  no formals; bare ret
uint32_t Client_SelectHostileUnderScreenPick_Inferred(void);
// AL: 0 gate fail; 1 pick path completed
```

## Constants (byte-sealed)

| VA | Value |
|---|---|
| `0x00aaacbc` | 0.015f |
| `0x00aaa6fc` | 25.0f |
| `0x00a1109c` | 40.0f |
| gather scoreArg | -1.0f |
| null TFID | `0x00a158b8` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00921f70_FUN_00921f70.md`
- Annotated: `docs/reconstruction/raw/aa_00921f70_FUN_00921f70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_SelectHostileUnderScreenPick_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00921f70.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00921f70_Client_SelectHostileUnderScreenPick_Inferred.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00921f70_Client_SelectHostileUnderScreenPick_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_00921f70_FUN_00921f70.md`

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller | site `0x00922262` | sole CODE xref (UI visibility fall-through; parent `ret 8`) |
| Callee | `0x0075c340` | `GfxView_UnprojectScreenToWorldRay_Inferred` |
| Callee | `0x004cd220` | height / scalar helper |
| Callee | `0x004e9530` | `Math_CopyFloat3ToFloat4_Inferred` |
| Callee | `0x0058d330` | `Skill_GatherTargetsInArea` (mode 2, max 1) |
| Callee | `0x0040b150` | `TFID_NotEquals` |
| Callee | `0x004bb950` | `Object_ResolveFromTFID` |
| Callee | `0x0093e120` | `Client_SelectTargetObject_Inferred` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** / **Confirmed** |
| Constants | **Confirmed** (`read_memory`) |
| Mode 2 / maxTargets 1 | **Confirmed** |
| Product binding (keybind name) | Open |
| Runtime | Open |
