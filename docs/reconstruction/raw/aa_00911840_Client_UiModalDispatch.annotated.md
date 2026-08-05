# Annotated low-level: Client_UiModalDispatch — abandon confirm slice (`aa_00911840`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00911840` |
| **VA** | `0x00911840` |
| **Canonical name** | `Client_UiModalDispatch` |
| **System** | missions-progression |
| **Source raw** | `aa_00911840_Client_UiModalDispatch.md` |
| **Scope** | Cases `0x4e46` / `0x4e47` only — not the full ~10k modal switch |

This file is the **annotated** layer for the abandon modal path. Full-function scaffold remains under `aa_00911840_FUN_00911840*`.

---

## 1. Corrected signature (function-level)

```c
// Large UI modal dispatcher. Abandon path uses modal type in param_3.
// Exact this/owner type of param_1 is UI host / global chrome — not fully typed.
uint32_t __thiscall Client_UiModalDispatch(void* thisUi, int actionCode, uint32_t modalType);
```

| Name | Decompiler | Role | Confidence |
|---|---|---|---|
| `this` / `param_1` | `int *param_1` | UI host / dialog owner | Tentative type |
| `actionCode` / `param_2` | `int param_2` | **8** = primary confirm for these cases | High (gate) |
| `modalType` / `param_3` | `undefined4 param_3` | Modal case key (`0x4e46` / `0x4e47`) | High |
| return | `undefined4` | Common success/handled path ends near `LAB_00911a99` | Probable |

---

## 2. End-to-end abandon flow (client)

```text
Client_MissionDialogHandleButton (state==2, button context==1)
  ├─ DAT_00d1b4b4 = missionId from dialog+0x670 (or 0xFFFFFFFF if null)
  └─ Client_ShowModalPrompt: EAX=0x4e46 (Yes→+0x498), stack=0x4e47 (No→+0x49c)
       // decompiler often shows only FUN_007fdfb0(..., 0x4e47, 1, 0)

Client_UiModalDispatch
  ├─ case 0x4e47 + action==8  → FUN_007fc360() close only   [No / dismiss family]
  └─ case 0x4e46 + action==8  → build 0x20B2 + SendSector + FUN_007fc360()  [Yes]

Server: process FailMission / abandon
S2C 0x20B2 → Client_PacketDispatch → Client_RecvFailMission → CVOGReaction_FailMission
```

---

## 3. Case `0x4e46` (confirm) — control flow

```text
if actionCode != 8: fall through / break
if pendingAbandonMissionId (DAT_00d1b4b4) == 0xFFFFFFFF: close only
if local character (DAT_00d1b6d8) == 0: close only
missionTable = *FUN_0053fff0()
if table null: close only
defNode = CNDHash_LookupByKey(table, key=DAT_00d1b4b4 snapshotted at entry)
if defNode null: close only

packet.opcode     = 0x20B2
packet.charCoid   = character COID via (DAT_00d1b6d8 dual-base +0x164/+0x168)
packet.missionId  = *defNode   // payload at hash node (mission def id)
Client_SendSectorPacket(client, 0x18, packet)

optional:
  if DAT_00d1b898 UI controller live (vtbl+0x3d8):
    FUN_007fca10(); FUN_007fef20(0x13, 1, 0)   // mission UI refresh

FUN_007fc360()  // always close modal on action==8
```

| Guard | Effect if fail | Confidence |
|---|---|---|
| `param_2 == 8` | No work | High |
| `DAT_00d1b4b4 != -1` | Close without send | High |
| `DAT_00d1b6d8 != 0` | Close without send | High |
| Mission def table + hash hit | Close without send | High |
| UI refresh block | Send still happens | High |

**Note:** `key = DAT_00d1b4b4` is snapshotted at function **entry**, before the switch. Confirm arm uses that snapshot for lookup while still re-checking the global for the sentinel.

---

## 4. Case `0x4e47` (cancel / shared dismiss)

Fall-through group with several other modal codes. On `param_2 == 8`: only `FUN_007fc360()` (close modal). **No** FailMission packet. **No** mutation of mission hashes.

---

## 5. Globals

| Symbol | Role | Confidence |
|---|---|---|
| `DAT_00d1b4b4` | `pendingAbandonMissionId` — set by HandleButton state 2 | High |
| `DAT_00d1b6d8` | Local character / player object pointer | High (COID path) |
| `DAT_00d1a840` | Client/session root for sector send + modal host | High (shared) |
| `DAT_00d1b898` | Optional mission UI controller | Probable |
| `FUN_0053fff0` | Mission definition table accessor | High (mission batch) |
| `FUN_007fc360` | Close / dismiss modal | High |
| `FUN_007fef20(0x13,1,0)` | Mission UI refresh after abandon send | Probable |

---

## 6. Yes/No pairing — residual **SEALED High** (UF-009)

| Id | Role | How assigned at open | Dispatch body |
|---:|---|---|---|
| `0x4e46` | **Yes** | `MOV EAX,0x4e46` → host `+0x498` | C2S `0x20B2` size `0x18` then close |
| `0x4e47` | **No** | stack secondary → host `+0x49c` | close only (`FUN_007fc360`) |

Decompiler open call shows only `0x4e47` (third arg); live asm also loads EAX Yes id. Supersedes earlier **Probable** residual wording. See dual A/B + `aa_007fdfb0`.

---

## 7. Open questions

- ~~Exact Yes/No modal codes for abandon~~ **sealed High** (UF-009 + residual dual).
- Whether `*piVar8` is always the mission **def id** equal to `DAT_00d1b4b4` (lookup key) or a distinct payload field (same id in practice).
- Formal type of `DAT_00d1b6d8` vs game+`0xe98` character pointer used by S2C handler.
- Full identity of `FUN_007fef20` refresh code `0x13`.
- Named outer functions for CALL sites `0x009140fe` / `0x009257e9`.
- Runtime click capture.

---

## 8. Related chain units

| Unit | Address | Role |
|---|---:|---|
| `Client_MissionDialogHandleButton` | `0x008ae7c0` | Posts abandon modal; sets `DAT_00d1b4b4` |
| `Client_UiModalDispatch` (this) | `0x00911840` | Confirm → C2S `0x20B2` |
| `Client_RecvFailMission` | `0x0080b100` | S2C `0x20B2` → FailMission |
| `CVOGReaction_FailMission` | `0x0052da30` | Active-hash fail kernel |
