# Function record: UI_Cs2dTabs_SelectTab_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00888b00` |
| **Canonical name** | `UI_Cs2dTabs_SelectTab_Inferred` (**INFERRED**) |
| **Address** | `0x00888b00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer (UI Cs2d R&D / Memorization tabs) |
| **Completion status** | **Partial** — three-rep + dual A/B sealed **R11-031 2026-08-05**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (not run; no Launcher) |

## Alias

| Name | Notes |
|---|---|
| `FUN_00888b00` | Ghidra default / scaffold synonym |
| `Named_CalleeOf_Client_Input_PollBoundActions_00888b00` | Prior auto-name; superseded |

## Purpose

Client UI helper: select tab **0 (R&D)** or **1 (Memorization)** on the Cs2d tabs host. Not an inventory grab/drop/equip packet path.

## Signature

```c
// Custom: EAX = tabIndex; stack (window*, force); RET 8
void UI_Cs2dTabs_SelectTab_Inferred(int* window, int force);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00888b00_FUN_00888b00.md` |
| Annotated | `docs/reconstruction/raw/aa_00888b00_FUN_00888b00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Cs2dTabs_SelectTab_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00888b00.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00888b00_UI_Cs2dTabs_SelectTab_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00888b00_UI_Cs2dTabs_SelectTab_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00888b00_FUN_00888b00.md` |
| Agent report | `docs/agents/task-dual-ab-00888b00-r11-report.md` |

## Callers / callees

See scaffold record `aa_00888b00_FUN_00888b00.md` (same VA).

## Confidence

| Claim | Level |
|---|---|
| Role = 2-tab select on Cs2d host | **High** |
| ABI EAX + stack2 + RET 8 | **High** |
| Product English name | **Open** (`_Inferred`) |
| Runtime | **Open** |
