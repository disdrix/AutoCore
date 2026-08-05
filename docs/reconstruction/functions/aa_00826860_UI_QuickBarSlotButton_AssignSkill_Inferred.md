# Function record: UI_QuickBarSlotButton_AssignSkill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00826860` |
| **Canonical name** | `UI_QuickBarSlotButton_AssignSkill_Inferred` |
| **Address** | `0x00826860` |
| **Body range** | `0x00826860` – `0x00826ad9` (0x27A bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / quickbar / skills-abilities |
| **Calling convention** | skill in **EAX**; button on stack; **`ret 4`**; returns `0`/`1` |
| **Completion status** | **Dual A/B sealed** — CF + ABI + layout + rel32; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00826860_UI_QuickBarSlotButton_AssignSkill_Inferred.md` |
| **Dual B** | `reviews/B_aa_00826860_UI_QuickBarSlotButton_AssignSkill_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W23-D) |

## Alias

- Ghidra: `FUN_00826860`
- Prior auto: `Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_00826860`

## Purpose

Assign a **skill object** to one QuickBar **slot-button**:

1. Reject null skill (return 0).
2. Detect same-bind (`kind==1 && pSkill==skill`) to skip re-clear of selection.
3. Cache skill id (`skill+0x5fc`) and pointer on the button; set `payloadKind=1`.
4. Compute flat slot `page*10+column`.
5. On local character (`DAT_00d1b6d8`): **clear item** COID (`SetQuickBarItem` −1/−1) then **set skill** (`SetQuickBarSkill`).
6. If binding changed and selected: `SetSelected(0)`.
7. Rebuild icon path `i_d_s_2d_wnd_icon_` + skill stem (`+0x5a6`) + `-on.dds`/`-off.dds`; refresh chrome; return 1.

## Signature

```c
uint32_t UI_QuickBarSlotButton_AssignSkill_Inferred(
    /*EAX*/ void* skill,
    /*stack*/ UI_QuickBarSlotButton* button);
/* ret 4 */
```

## Layout (button)

| Offset | Type | Role |
|---:|---|---|
| `+0x4fc` | byte | `fSelected` |
| `+0x4fe` | byte | icon-state (cleared; drives on/off suffix) |
| `+0x500` | int | column |
| `+0x504` | int | page |
| `+0x548` | int | payloadKind (**1** = skill) |
| `+0x550` | int64 | skill id (cdq from `skill+0x5fc`) |
| `+0x558` | ptr | skill object* |
| `+0x55c` | int | flat slot |
| `+0x564` | ptr | icon widget |
| `+0x574`/`+0x578` | ptr | chrome widgets |
| `+0x57c` | ptr | owned child (destroy) |

## Machine seal (`read_memory` 2026-07-29)

| Call site | Target | Symbol |
|---:|---:|---|
| `0x008268f1` | `0x00520890` | `CVOGCharacter_SetQuickBarItem` |
| `0x00826914` | `0x005208c0` | `CVOGCharacter_SetQuickBarSkill` |
| `0x0082692a` | `0x00826780` | `UI_QuickBarSlotButton_SetSelected` |

Strings: `i_d_s_2d_wnd_icon_` @ `0x00a540d0`; `-off.dds` @ `0x00a74e8c`; `-on.dds` @ `0x00a74e98`.

## Callers

| Caller | Site | Role |
|---|---:|---|
| `FUN_008a0e10` (page rebind) | `0x008a0eaf` | kind==1 skill column rebind |
| (unnamed UI) | `0x00828c6d`, `0x00828daf`, `0x00828e38`, `0x00828fbc` | assign/drag paths |

## Callees

| VA | Name |
|---:|---|
| `0x00520890` | `CVOGCharacter_SetQuickBarItem` |
| `0x005208c0` | `CVOGCharacter_SetQuickBarSkill` |
| `0x00826780` | `UI_QuickBarSlotButton_SetSelected` |
| (virtuals) | icon/chrome vtbl slots |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00826860_FUN_00826860.md` (+ W23-D append)
- Annotated: `docs/reconstruction/raw/aa_00826860_UI_QuickBarSlotButton_AssignSkill.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_AssignSkill_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00826860.cpp`

## Confidence

| Claim | Level |
|---|---|
| Function boundary + body size | **High** |
| ABI EAX-skill + stack-button + ret 4 | **High** |
| payloadKind=1 skill + slot page*10+col | **High** |
| SetQuickBarItem then SetQuickBarSkill order | **High** (rel32) |
| Icon path family | **High** (strings) |
| Product English method name | **Inferred** |
| Widget vtbl English | **Inferred** |
| Runtime / bit-exact | **Open** |

## Open questions

1. Product C++ method name on the slot-button class.
2. Exact vtbl English for icon set-texture / chrome refresh.
3. Whether wire `QuickBarUpdate` (C2S 0x2062) is sent by callers of this unit (not this body).
4. Runtime / differential.
