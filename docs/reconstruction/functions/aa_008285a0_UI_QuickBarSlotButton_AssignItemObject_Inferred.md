# Function record: UI_QuickBarSlotButton_AssignItemObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008285a0` |
| **Canonical name** | `UI_QuickBarSlotButton_AssignItemObject_Inferred` |
| **Address** | `0x008285a0` |
| **Body range** | `0x008285a0` – `0x00828756` (`0x1B7` bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / client UI quickbar |
| **Calling convention** | item object* in **EAX**; button in **ESI**; plain **`ret`**; returns `0`/`1` |
| **Completion status** | **Dual A/B sealed** — CF + ABI + layout + rel32; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_008285a0_UI_QuickBarSlotButton_AssignItemObject_Inferred.md` |
| **Dual B** | `reviews/B_aa_008285a0_UI_QuickBarSlotButton_AssignItemObject_Inferred.md` |
| **Last reviewed** | `2026-08-05` (R11-026) |

## Alias

- Ghidra: `FUN_008285a0`
- Prior scaffold: `aa_008285a0_FUN_008285a0` (2026-07-23)

## Purpose

Assign a live **item object** to one QuickBar **slot-button**:

1. Reject null item (return 0).
2. Detect same-bind (`kind==2 && idLo/idHi match cdq(cloneId)`) to skip re-clear of selection.
3. Cache item id from `*( *(item+0xa8)+0x34 )`; set `payloadKind=2`; clear `pSkill`; compute flat slot `page*10+col`.
4. On local character (`DAT_00d1b6d8`): **set item** then **clear skill** (`SetQuickBarSkill` −1).
5. If binding changed and selected: `SetSelected(0)`.
6. Rebuild icon via `FUN_0085d970(item, pathBuf)` + icon/chrome virtuals; return 1.

## Signature

```c
uint32_t UI_QuickBarSlotButton_AssignItemObject_Inferred(
    /*EAX*/ void* itemObject,
    /*ESI*/ UI_QuickBarSlotButton* button);
/* plain ret; 0 if item null, else 1 */
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

## Item object

| Offset | Role |
|---:|---|
| `+0xa8` | ptr → clonebase-like host |
| host `+0x34` | int32 id (CDQ → button id64) |

## Machine seal (`read_memory` / `disassemble_function` 2026-08-05)

| Call site | Target | Symbol |
|---:|---:|---|
| `0x0082864c` | `0x00520890` | `CVOGCharacter_SetQuickBarItem` |
| `0x0082866a` | `0x005208c0` | `CVOGCharacter_SetQuickBarSkill` |
| `0x00828681` | `0x00826780` | `UI_QuickBarSlotButton_SetSelected` |
| `0x008286ad` | `0x0085d970` | inventory texture path extract |

Epilog: plain `RET` (`C3`) at `0x00828756`. Entry: `SUB ESP,0x104`.

## Callers (xrefs)

| Site | Notes |
|---:|---|
| `0x00828b00` | `EAX = *(DAT_00d1b6d8 + 0xcd0)` then CALL; test AL |
| `0x00828ef8` | `EAX=EBX; ESI=EBP` then CALL; test AL |

## Callees

| VA | Name |
|---:|---|
| `0x00520890` | `CVOGCharacter_SetQuickBarItem` |
| `0x005208c0` | `CVOGCharacter_SetQuickBarSkill` |
| `0x00826780` | `UI_QuickBarSlotButton_SetSelected` |
| `0x0085d970` | path extract residual (Inventory Texture) |
| (virtuals) | icon/chrome/button vtbl slots |

## Twins

| VA | Name | Distinction |
|---:|---|---|
| `0x008283a0` | `UI_QuickBarSlotButton_AssignItem_Inferred` | item **id** in ECX; button EAX; GiveItemByCbid icon; −1 clear path |
| `0x00826860` | `UI_QuickBarSlotButton_AssignSkill_Inferred` | skill* EAX; button stack; `ret 4`; kind=1 |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008285a0_FUN_008285a0.md` (+ R11-026 append)
- Annotated: `docs/reconstruction/raw/aa_008285a0_FUN_008285a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_AssignItemObject_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_008285a0.cpp`

## Confidence

| Claim | Level |
|---|---|
| Function boundary + body size | **High** |
| ABI EAX-item + ESI-button + plain ret | **High** |
| payloadKind=2 item + slot page*10+col | **High** |
| SetQuickBarItem then SetQuickBarSkill(−1) | **High** (rel32) |
| Icon path via object FUN_0085d970 | **High** (disasm) |
| Product English method name | **Inferred** |
| `+0xa8` clonebase product type | **Probable** |
| Runtime / bit-exact | **Open** |

## Open questions

1. Product C++ method name on the slot-button class.
2. Exact type of EAX item object and `char+0xcd0`.
3. Full `FUN_0085d970` dual.
4. Whether wire `QuickBarUpdate` (C2S 0x2062) is sent by callers.
5. Runtime / differential.
