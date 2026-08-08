# Function record: UI_Window_OnCommand_Class8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082f510` |
| **Canonical name** | `UI_Window_OnCommand_Class8_Inferred` (**INFERRED**) |
| **Address** | `0x0082f510` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI command dispatch / skills (case 1) |
| **Completion status** | **Partial** — three-rep + dual A/B sealed **WQ8R-F 2026-08-04**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (not run; no Launcher) |

## Alias

| Name | Notes |
|---|---|
| `FUN_0082f510` | Ghidra default / scaffold |
| “UI cmd case” | Dual residual shorthand in `a_009418e0` (case 1 → skill **0xED5**) |

## Purpose

UI window command handler for **command class 8**: jump-table dispatch of subcommand ids **1..0xd** (dialog show/hide family + hardcoded `Client_CastSkillFromQuickBarSlot(0xED5)`), with a dead-vehicle early path that vcalls `this+0x47c` and forwards to base `FUN_0082c780`. Non-class-8 / unknown case falls through to base unless cmdId == **70000**.

## Signature

```c
// __thiscall; RET 8
uint32_t __thiscall UI_Window_OnCommand_Class8_Inferred(
    int* self, int cmdClass, int cmdId);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0082f510_FUN_0082f510.md` |
| Annotated | `docs/reconstruction/raw/aa_0082f510_FUN_0082f510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Window_OnCommand_Class8_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0082f510.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0082f510_UI_Window_OnCommand_Class8_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0082f510_UI_Window_OnCommand_Class8_Inferred.md` |
| Agent report | `docs/agents/task-dual-ab-008c4fc0-0082f510-wq8rf-report.md` |

Scaffold record: `functions/aa_0082f510_FUN_0082f510.md`.

## Callers

| Kind | Address | Notes |
|---|---|---|
| DATA vtable | `0x00a72514` | Slot value `0x0082f510`; **0** direct CALL sites |

## Callees

| VA | Name | Role |
|---|---|---|
| `0x009418e0` | `Client_CastSkillFromQuickBarSlot` | Case 1: skill id **0xED5** |
| `0x0082c780` | `FUN_0082c780` | Base/default forwarder |
| `0x007fef20` | `FUN_007fef20` | Dialog index show/hide family |
| `0x007fca10` | `FUN_007fca10` | Close/flush path when dialog already visible |
| `0x00889410` / `0x00888b00` / `0x00889fb0` | dialog helpers | Cases 4 / 5 / 0xb |

## Key layouts / constants

| Symbol | Role |
|---|---|
| `cmdClass == 8` | Specialized switch |
| `cmdId` 1..0xd | Jump table `@0x0082f794` |
| skill **0xED5** | Hardcoded cast case 1 |
| `DAT_00d1a840` | Global client (ESI at cast) |
| `DAT_00d1b870/874/880` | Dialog object globals |
| vtbl `+0x3d8` | Is-visible style probe (shared UI) |
| vehicle MI vtbl `+0x194` | Dead/non-operable probe |
| this vtbl `+0x47c` | Pre-forward UI hook on dead path |
| cmdId **70000** | Sentinel absorb (no base call) |
| `RET 8` | Two stack formals |

## Confidence

| Claim | Level |
|---|---|
| Control flow live ≡ raw | **High** |
| ABI thiscall + ret 8 | **High** |
| Class-8 case map + jump table | **High** |
| Case 1 skill **0xED5** + ESI client | **High** |
| DATA-only entry `0x00a72514` | **High** |
| Product window class / skill 0xED5 English | **Open** |
| Dialog global product names | **Tentative** |
| Runtime / bit-exact | **Open** |
