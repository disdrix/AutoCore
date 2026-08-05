# Annotated low-level: Client_MissionDialogHandleButton (`aa_008ae7c0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ae7c0` |
| **VA** | `0x008ae7c0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_008ae7c0_Client_MissionDialogHandleButton.md` (capture 2026-07-23) |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
char /* bool */ __cdecl Client_MissionDialogHandleButton(
    int* pDialogContext /* button / selection */,
    int iButtonIndex    /* may be unused / overloaded */);
// Decompiler also pulls dialog host from in_EAX / global client
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `pDialogContext` | pointer / int | overloaded | stack | Button id **or** selection; compared to `1` for abandon confirm |
| `iButtonIndex` | **s32** | signed | stack | Present in signature; little direct use in body |
| `in_EAX` | pointer | unsigned | `EAX` | Dialog host / client shell |
| return | **char** | 0/1 | `AL` | 0 = handled/cancel paths; 1 = success / fallthrough |

Global: `DAT_00d1b6d8` must be non-null (early `return 0`).

---

## 2. Dialog state machine (`host+0x648`)

| State | Value | Behavior |
|---:|---:|---|
| Accept request | **0** | Build C2S packet opcode **`0x206F`**, size `0x18`, send via `Client_SendSectorPacket` |
| Accept / claim | **1** | Offer accept (`GiveMission`) **or** deliver complete (`CompleteObjective`) if turn-in mode `+0x64c` |
| Abandon confirm | **2** | If button context `== 1`, stash `DAT_00d1b4b4`, show “Are you sure…?” dual-id modal: Yes **EAX `0x4e46`**, No stack **`0x4e47`** |
| Journal / re-show | **3** | `Client_ShowNpcMissionDialogUI(..., 0)` re-open NPC list |

State field width: **s32** at `host+0x648`.

### Important host offsets

| Offset | Width | Role |
|---|---|---|
| `+0x644` | ptr | NPC / target object |
| `+0x648` | s32 | Dialog state (0–3) |
| `+0x64c` | **u8** | Turn-in / claim mode (non-zero → complete path) |
| `+0x650..` | mixed | Prepared `MissionDialogResponse` / C2S fields (plate `0x206E`) |
| `+0x670` | ptr | Selected mission def / row |
| `+0x678/+0x67c` | u32×2 | Copied into accept packet `0x206F` |
| `+0x558/+0x55c` | u32 | Reward selection mask pair |
| `+0x578/+0x57c` | u32 | Reward object TFID pair |
| `+0x6e0` | ptr | Sub-UI; may block with vtable `+0x1f8/+0x1fc` |
| `+0x708 + ctx*4` | ptr | Gate: must be non-zero for handler body |

---

## 3. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| Packet `0x206f` | C2S accept-mission request | **High** |
| Reward gate message | Literal `"You need to select a reward first!"` | **Confirmed** |
| Inventory full message | Literal inventory space string | **Confirmed** |
| `FUN_005714e0` | Inventory space check for reward item | **Probable** |
| `CVOGReaction_ResolveObjectTarget` | Resolve reward world/item object | **Probable** |
| Turn-in toast `"Finished Mission"` | UI string before CompleteObjective | **Confirmed** |
| Accept path `GiveMission(*missionDefId)` | Local grant when button context null | **High** |
| Complete path | `CompleteObjective(objId, tfid_lo, tfid_hi, 0)` | **High** |
| `pDialogContext == 1` in state 2 | Gate to open abandon confirm modal | **High** |
| State-2 open shows only `0x4e47` in decompile | Image also `MOV EAX,0x4e46` (Yes); third arg is No | **High** (UF-009/UF-017) |

---

## 4. Control flow (state 1 detail)

```text
if DAT_00d1b6d8 == 0: return 0
// optional sub-UI busy → cancel callback, return 0
// require slot table entry non-null

switch state:
  2: abandon confirm UI if button==1; return 0
  0: send 0x206F sector packet; return 1
  3: ShowNpcMissionDialogUI; return 0
  1:
    if turn-in (+0x64c):
      enforce reward selection masks
      optional inventory space for reward TFID
      stash NPC COID into +0x660..
      "Finished Mission" toast + reward chat toast
      CompleteObjective(...); refresh/hide UI; return 1/0
    else: // accept offer
      if button context == 0: GiveMission; tips; hide dialog
return 1  // default fallthrough
```

| Branch | Return |
|---|---|
| Busy sub-UI / no global char | `0` |
| Need reward / inventory full | `0` + message box |
| CompleteObjective fails | `0` |
| Accept packet sent | `1` |
| Many UI-only paths | `0` |
| Default end | `1` |

---

## 5. Side-effect order (claim path)

1. Validate reward selection + inventory.
2. Copy NPC identity into dialog host fields.
3. Toast strings + `Client_ShowMissionRewardChatToast`.
4. `CVOGReaction_CompleteObjective`.
5. `Client_RefreshMissionDialogChrome` → hide → `Client_RefreshOpenMissionUiWindows`.

Accept path: `GiveMission` → optional `FUN_0092fd00` → hide dialog → first-time tip → `FUN_008ac7a0`.

---

## 6. Open questions

- ~~Full C2S `0x206E` response packing / send at `+0x650`~~ **Sealed 2026-07-29:** this body **fills** `+0x654..` only; **send** is `Client_MissionDialog_FlushPreparedResponse` @ `0x008ab8f0` (size 0x20). See `reviews/CHAIN_2026-07-29_c2s_206e_seal.md`.
- ~~Abandon modal “only `0x4e47`” / dual lag (UF-017).~~ **Sealed High:** open-site Yes **EAX `0x4e46`** + No stack **`0x4e47`**; static e2e → `reviews/CHAIN_2026-07-29_abandon_failmission.md`. **Residual: runtime only.**
- Exact reward mask bit layout (`+0x558/+0x55c` vs `+0x578/+0x57c`).
- When `FUN_0092fd00` runs after GiveMission (flag `DAT_00d1b216` / def fields).
- ~~Abandon confirm dialog result handler (who calls FailMission after `0x4e47`).~~ **Sealed 2026-07-29:** modal cancel case `0x4e47` closes only; confirm case **`0x4e46`** sends C2S `0x20B2` (`Client_UiModalDispatch`); S2C apply → `Client_RecvFailMission` → `CVOGReaction_FailMission`.
