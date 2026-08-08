# Function record: UI_TabChrome_SetSelected_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00822cb0` |
| **Canonical name** | `UI_TabChrome_SetSelected_Inferred` (**INFERRED**) |
| **Address** | `0x00822cb0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer (UI tab chrome helper) |
| **Completion status** | **Partial** — three-rep + dual A/B sealed **R12-002 2026-08-05**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (not run; no Launcher) |

## Alias

| Name | Notes |
|---|---|
| `FUN_00822cb0` | Ghidra default / scaffold synonym |
| `Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00822cb0` | Prior auto-name; superseded as canonical |

## Purpose

Client UI helper: given a widget in **ESI**, selected flag in **BL**, and stack **force**, apply tab chrome selected/unselected visuals (optional child restyle + companion visibility + conditional size delta) and store selected at `+0x4FC`. Used by tab selectors on active/inactive tab chrome; after unselect (BL=0) parents often call `FUN_00756c90` move-to-front. Not an inventory grab/drop/equip packet path.

## Signature

```c
// Custom: ESI = widget*; BL = selected; force@stack; RET 4
void UI_TabChrome_SetSelected_Inferred(char force /*stack*/);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00822cb0_FUN_00822cb0.md` |
| Annotated | `docs/reconstruction/raw/aa_00822cb0_FUN_00822cb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_TabChrome_SetSelected_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00822cb0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00822cb0_UI_TabChrome_SetSelected_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00822cb0_UI_TabChrome_SetSelected_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00822cb0_FUN_00822cb0.md` |
| Agent report | `docs/agents/task-dual-ab-00822cb0-r12-report.md` |

## Callers / callees

See scaffold record `aa_00822cb0_FUN_00822cb0.md` (same VA).

## Confidence

| Claim | Level |
|---|---|
| Role = tab chrome set-selected | **High** |
| ABI ESI+BL+force / RET 4 | **High** |
| Product English name | **Open** (`_Inferred`) |
| Runtime | **Open** |
