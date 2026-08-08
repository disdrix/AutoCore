# Function record: UI_Widget_MoveToFrontInParentGroup_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00756c90` |
| **Canonical name** | `UI_Widget_MoveToFrontInParentGroup_Inferred` (**INFERRED**) |
| **Address** | `0x00756c90` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer (UI tab/group chrome helper) |
| **Completion status** | **Partial** — three-rep + dual A/B sealed **R12-003 2026-08-05**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (not run; no Launcher) |

## Alias

| Name | Notes |
|---|---|
| `FUN_00756c90` | Ghidra default / scaffold synonym |
| `Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00756c90` | Prior auto-name; superseded as canonical |

## Purpose

Client UI helper: given a widget in **EDI**, if it has a parent group at `+0x88` and that group's child-pointer vector is not a singleton, remove the widget from the vector (if present) and re-insert it at the front via `FUN_00456960` InsertN. Used by tab selectors on collapsed/inactive tab chrome after `FUN_00822cb0` BL=0. Not an inventory grab/drop/equip packet path.

## Signature

```c
// Custom: EDI = widget*; no stack args; RET
uint32_t UI_Widget_MoveToFrontInParentGroup_Inferred(void);
// returns 0, or 0xFFFFFFFF if widget+0x88 == 0
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00756c90_FUN_00756c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00756c90_FUN_00756c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Widget_MoveToFrontInParentGroup_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00756c90.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00756c90_UI_Widget_MoveToFrontInParentGroup_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00756c90_UI_Widget_MoveToFrontInParentGroup_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00756c90_FUN_00756c90.md` |
| Agent report | `docs/agents/task-dual-ab-00756c90-r12-report.md` |

## Callers / callees

See scaffold record `aa_00756c90_FUN_00756c90.md` (same VA).

## Confidence

| Claim | Level |
|---|---|
| Role = parent-group vector move-to-front | **High** |
| ABI EDI + RET + EAX status | **High** |
| Product English name | **Open** (`_Inferred`) |
| Runtime | **Open** |
