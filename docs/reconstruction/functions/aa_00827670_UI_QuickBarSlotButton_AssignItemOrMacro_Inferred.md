# Function record: UI_QuickBarSlotButton_AssignItemOrMacro_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00827670` |
| **Canonical name** | `UI_QuickBarSlotButton_AssignItemOrMacro_Inferred` (Inferred) |
| **Ghidra name** | `FUN_00827670` |
| **Address** | `0x00827670` |
| **Body range** | `0x00827670`–`0x00827918` exclusive (**680** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / quickbar |
| **Completion status** | **partial** — dual A/B **accept**; CF + ABI + chrome kinds sealed; product English open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00827670_UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.md`, `reviews/B_aa_00827670_UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.md` (2026-07-29 W24-I) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00827670`
- `Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_00827670` (legacy — CreateCharacter only via rebind)
- Prior plate hint `UI_macro_icon` — partial (macro is kind **5** only)

## Purpose

Bind a non-skill payload (item/macro id + kind) onto one QuickBar slot-button, mirror into local character arrays (**set item, clear skill**), refresh chrome for kinds 3/4/5.

## Signature

```c
// Retail live-ins: ESI=button, EAX=kind, [esp+4]=id; RET 4; AL=1
uint32_t UI_QuickBarSlotButton_AssignItemOrMacro_Inferred(
    UI_QuickBarSlotButton* button /*ESI*/,
    int32_t kind /*EAX*/,
    int32_t id /*stack*/);
```

## Algorithm

1. Same-bind gate on (kind, id64).  
2. Store id/kind/flatSlot; clear +0x558.  
3. `SetQuickBarItem(char, page*10+col, id)` + `SetQuickBarSkill(..., -1)`.  
4. Optional SetSelected(0).  
5. Icon/chrome by kind 3/4/5; always return 1.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00827670_FUN_00827670.md`
- Annotated: `docs/reconstruction/raw/aa_00827670_FUN_00827670.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00827670.cpp`
- Legacy: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_00827670.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005ae220-00827670-w24i-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `CVOGCharacter_SetQuickBarItem`, `CVOGCharacter_SetQuickBarSkill`, `FUN_00826780`, `FUN_008264f0`, `sprintf`, icon vtbls |
| **Callers** | `FUN_008a0e10` (type 5 rebind); `0x00828cbb`…`0x00829000` (EAX=5 sites) |

## Confidence

| Claim | Level |
|---|---|
| Control flow + body size | **High** |
| ESI/EAX/stack ABI | **High** |
| Exclusive item vs skill | **High** |
| Kind 3/4/5 strings | **High** |
| Product English | **Inferred** |
| Runtime / differential | Open |

## Related

- Skill twin: `UI_QuickBarSlotButton_AssignSkill_Inferred` (`0x00826860`)
- Item-object sibling: `FUN_008283a0` (table type 2)
- Rebind: `QuickBar_RebindPageColumns_Inferred` (`0x008a0e10`)
- SetSelected: `UI_QuickBarSlotButton_SetSelected` (`0x00826780`)
