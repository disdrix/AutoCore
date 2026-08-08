# Function record: UI_TabsC_SetActiveTab_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00889410` |
| **Canonical name** | `UI_TabsC_SetActiveTab_Inferred` (**INFERRED**) |
| **Address** | `0x00889410`–`0x008896f3` (**740 B** / `0x2E4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer |
| **Completion status** | **Dual sealed R11-032 2026-08-05**; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (not run; no Launcher; Terminal **false**) |

## Alias

| Name | Notes |
|---|---|
| `FUN_00889410` | Ghidra default / scaffold twin |
| `Named_CalleeOf_Client_Input_PollBoundActions_00889410` | Scaffold chain — **retired as product** |

## Purpose

Set the active tab on the client **`i_d_tabs_c_*`** inventory dialog (global `DAT_00d1b874`):

| tabIndex | Content pane | Tab button | XML (ctor `FUN_00889960`) |
|---------:|--------------|------------|---------------------------|
| 0 | `dialog+0x50c` | `+0x518` | `i_d_tabs_c_2d_tab_char.xml` |
| 1 | `dialog+0x514` | `+0x520` | `i_d_tabs_c_2d_tab_achievements.xml` |
| 2 | `dialog+0x510` | `+0x51c` | `i_d_tabs_c_2d_tab_locker.xml` |

Writes `dialog+0x530`, toggles pane visibility (vtbl `+0x3d8`/`+0x43c`/`+0x440`/`+0x4`), selects one tab button via `FUN_00822cb0`+vtbl`+0x94`, deselects the other two via `FUN_00822cb0`+`FUN_00756c90`.

## Signature

```c
// hybrid __usercall; RET 8; void
void UI_TabsC_SetActiveTab_Inferred(
    int tabIndex /* @EAX */,
    int *dialog  /* stack+4 */,
    char force   /* stack+8 */);
```

Gate: host vtbl`+0x3d8` true **and** (`force != 0` **or** `tabIndex != dialog+0x530`).

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00889410_FUN_00889410.md` |
| Annotated | `docs/reconstruction/raw/aa_00889410_FUN_00889410.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_TabsC_SetActiveTab_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00889410.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00889410_UI_TabsC_SetActiveTab_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00889410_UI_TabsC_SetActiveTab_Inferred.md` |
| Agent report | `docs/agents/task-dual-ab-00889410-r11-report.md` |

Scaffold record: `functions/aa_00889410_FUN_00889410.md`.

## Callers

| Kind | Address / name | Notes |
|---|---|---|
| CALL | `FUN_00889960` @ `0x00889c5c` | ctor force re-apply; EAX=`[dialog+0x530]` |
| CALL | `FUN_0082f510` @ `0x0082f5de` | class-8 cmd case 4; EAX=0 |
| CALL | `Client_Input_PollBoundActions` | three sites; EAX 0/1/2 |
| CALL | residual 11 more | force 0/1; tab 0/1/2 / computed |

**14** `UNCONDITIONAL_CALL` xrefs total.

## Callees

| VA | Role |
|---|---|
| `0x00822cb0` | Tab button select/deselect chrome (`ESI` widget, `BL` selected, stack force) |
| `0x00756c90` | Remove widget from parent group (`EDI` widget) |
| child vtbls | `+0x3d8` / `+0x43c` / `+0x440` / `+0x4` / `+0x94` |

## Key layouts / constants

| Symbol | Role |
|---|---|
| `DAT_00d1b874` | Host dialog global |
| `dialog+0x530` | Active tab index |
| tabIndex 0/1/2 | char / achievements / locker |
| force | bypass same-tab early-out |
| `RET 8` | two stack formals |

## Confidence

| Claim | Level |
|---|---|
| Control flow live ≡ raw | **High** |
| ABI hybrid usercall + RET 8 | **High** |
| Tab/XML map + pane matrix | **High** |
| 14 callers / 2 named callees | **High** |
| Product method / class English | **Open** |
| Official vtbl method names | **Open** |
| Runtime / bit-exact | **Open** |
