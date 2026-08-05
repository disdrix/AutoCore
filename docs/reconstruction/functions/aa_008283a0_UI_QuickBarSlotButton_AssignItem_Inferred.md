# Function record: UI_QuickBarSlotButton_AssignItem_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008283a0` |
| **Canonical name** | `UI_QuickBarSlotButton_AssignItem_Inferred` |
| **Address** | `0x008283a0` |
| **Body range** | `0x008283a0` – `0x0082859e` (0x1FE bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / quickbar / inventory-items |
| **Calling convention** | button in **EAX**; itemId in **ECX**; plain **`ret`**; returns `1` |
| **Completion status** | **Dual A/B sealed** — CF + ABI + layout + rel32; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_008283a0_UI_QuickBarSlotButton_AssignItem_Inferred.md` |
| **Dual B** | `reviews/B_aa_008283a0_UI_QuickBarSlotButton_AssignItem_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W24-J) |

## Alias

- Ghidra: `FUN_008283a0`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_008283a0`

## Purpose

Assign an **item id** to one QuickBar **slot-button**:

1. `itemId == -1` → clear active slot; return 1.
2. Detect same-bind (`kind==2 && idLo/idHi match`) to skip re-clear of selection.
3. Cache item id (cdq), set `payloadKind=2`, clear `pSkill`, compute flat slot `page*10+col`.
4. On local character: **set item** COID then **clear skill** (`SetQuickBarSkill` −1).
5. If binding changed and selected: `SetSelected(0)`.
6. Rebuild icon via `GiveItemByCbid` + path helper; refresh chrome; return 1.

## Signature

```c
uint32_t UI_QuickBarSlotButton_AssignItem_Inferred(
    /*EAX*/ UI_QuickBarSlotButton* button,
    /*ECX*/ int32_t itemId);
/* plain ret; always returns 1 on observed paths */
```

## Layout (button)

| Offset | Type | Role |
|---:|---|---|
| `+0x4fc` | byte | `fSelected` |
| `+0x4fe` | byte | icon-state (cleared) |
| `+0x500` | int | column |
| `+0x504` | int | page |
| `+0x548` | int | payloadKind (**2** = item) |
| `+0x550` | int64 | item id (cdq) |
| `+0x558` | ptr | pSkill (**0** on item bind) |
| `+0x55c` | int | flat slot |
| `+0x564` | ptr | icon widget |
| `+0x574`/`+0x578` | ptr | chrome widgets |
| `+0x57c` | ptr | owned child (destroy) |

## Machine seal (`read_memory` 2026-07-29)

| Call site | Target | Symbol |
|---:|---:|---|
| `0x008283ae` | `0x008274c0` | `QuickBar_ClearActiveSlot_INFERRED` |
| `0x00828445` | `0x00520890` | `CVOGCharacter_SetQuickBarItem` |
| `0x00828463` | `0x005208c0` | `CVOGCharacter_SetQuickBarSkill` |
| `0x00828479` | `0x00826780` | `UI_QuickBarSlotButton_SetSelected` |
| `0x008284ac` | `0x0051a170` | `CVOGReaction_GiveItemByCbid` |

## Callers

| Caller | Site | Role |
|---|---:|---|
| `FUN_008a0e10` (page rebind) | `0x008a0e9f` | kind==2 item column rebind |
| (unnamed UI) | `0x00828de4`, `0x00828fd3` | assign/drag paths |

## Callees

| VA | Name |
|---:|---|
| `0x008274c0` | `QuickBar_ClearActiveSlot_INFERRED` |
| `0x00520890` | `CVOGCharacter_SetQuickBarItem` |
| `0x005208c0` | `CVOGCharacter_SetQuickBarSkill` |
| `0x00826780` | `UI_QuickBarSlotButton_SetSelected` |
| `0x0051a170` | `CVOGReaction_GiveItemByCbid` |
| `0x0085d970` | path extract residual |
| (virtuals) | icon/chrome vtbl slots |

## Twin

`UI_QuickBarSlotButton_AssignSkill_Inferred` @ `0x00826860` — kind=1; skill* in EAX; button stack; `ret 4`; clears item then sets skill.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008283a0_FUN_008283a0.md` (+ W24-J append)
- Annotated: `docs/reconstruction/raw/aa_008283a0_FUN_008283a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_AssignItem_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_008283a0.cpp`

## Confidence

| Claim | Level |
|---|---|
| Function boundary + body size | **High** |
| ABI EAX-button + ECX-itemId + plain ret | **High** |
| payloadKind=2 item + slot page*10+col | **High** |
| SetQuickBarItem then SetQuickBarSkill(-1) | **High** (rel32) |
| GiveItemByCbid icon path | **High** (rel32) |
| Product English method name | **Inferred** |
| Item id domain (CBID vs COID) | **Probable** (GiveItemByCbid lo) |
| Runtime / bit-exact | **Open** |

## Open questions

1. Product C++ method name on the slot-button class.
2. Exact id domain (template CBID vs instance COID) for ECX.
3. Full `FUN_0085d970` path dual.
4. Whether wire `QuickBarUpdate` (C2S 0x2062) is sent by callers.
5. Runtime / differential.
