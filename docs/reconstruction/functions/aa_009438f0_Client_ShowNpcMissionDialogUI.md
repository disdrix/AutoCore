# Function record: Client_ShowNpcMissionDialogUI

| Field | Value |
|---|---|
| **Stable ID** | `aa_009438f0` |
| **Canonical name** | `Client_ShowNpcMissionDialogUI` |
| **Address** | `0x009438f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Human-refined clean** + dual A/B strengthen 2026-07-29 (EAX 4/4 + `+0x64c` byte store); runtime open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Present / reconfigure NPC mission dialog UI. Multi-active + EAX key −1 → journal via `Client_UpdateMissionJournal`. Otherwise lookup mission def, set chrome mode at `dialog+0x510` (1 = active/turn-in, 2 = offer), stamp prepared response opcode **0x206E**, set turn-in flag `dialog+0x64c` via `FUN_008aa760`, finalize present.

## Signature

```c
void Client_ShowNpcMissionDialogUI(int clientUi, int npcObj, char mode);
// mission key in EAX (caller-framed; not a stack formal):
//   RecvNpcMissionDialog:     mode=1, EAX=-1 (always)
//   Unmapped site 0x00924608:  mode=1, EAX=-1 (if char+0x510 != EBX)
//   HandleButton state 3:      mode=0, EAX=dialog[+0x518+idx*8]
//   FUN_008aec40 list:         mode=0, EAX=*(entry+0x500)
```

## Callers

| Caller | Site | mode | EAX | Confidence |
|---|---|---|---|---|
| `Client_RecvNpcMissionDialog` | `0x0081518c` | 1 | **−1** | **High** |
| Unmapped code block | `0x00924608` | 1 | **−1** | **High** framing; product name **Open** |
| `Client_MissionDialogHandleButton` (state 3) | `0x008ae93a` | 0 | slot mission id | **High** |
| `FUN_008aec40` (list click) | `0x008aecca` | 0 | entry `+0x500` | **High** |

## Key fields (dialog at `client+0x1058`)

| Offset | Role | Writer in this unit |
|---|---|---|
| `+0x510` | Chrome mode: 2=offer, 1=active/turn-in | **Yes** (`int*[0x144]`) |
| `+0x644` | NPC object (already-active compare) | Compared |
| `+0x64c` | Turn-in / claim flag (byte) | **Indirect** via `FUN_008aa760` first store |
| `+0x648` | HandleButton router 0/1/2/3 | **No** |
| `+0x650` | Prepared opcode (0x206E) | **Indirect** via Prepare |
| `+0x670` | Mission def* | Compared |
| `+0x514` | Reward icon count (cleared/set in aa760) | Via helper |
| `+0x578/57c` | Selected reward COID pair (cleared in aa760) | Via helper |

## `+0x64c` dual residual (sealed)

```
FUN_0052b420(def, npc) → turnInReady (0/1)
  → uVar9 = turnInReady
  → FUN_008aa760(FUN_0052dac0(*def,0), 4, uVar9)
       first store: *(byte*)(dialog+0x64c) = uVar9
       raw: MOV [EDI+0x64c], AL
```

| Consumer | Effect |
|---|---|
| `FUN_008aa760` captions | offer vs claim reward wording |
| `HandleButton` state 1 | GiveMission vs CompleteObjective |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Guards + journal shortcut | **High** | CF sealed |
| EAX mission-key framing | **High** | Asm at four call sites (2026-07-29 strengthen) |
| State `+0x510` 1 vs 2 | **High** | Explicit stores; index sealed |
| Turn-in probe → `+0x64c` | **High** | Helper + raw byte store + dual consumers |
| Prepare 0x206E | **High** | Chain sealed |
| `FUN_0052dac0` → `state+0x18` | **High** (CF) | Product name Tentative |
| Chrome FUN_* product names | **Tentative** | Unnamed helpers |
| Overall | **High (static)** | Runtime open |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_009438f0_Client_ShowNpcMissionDialogUI.md` |
| Annotated | `raw/aa_009438f0_Client_ShowNpcMissionDialogUI.annotated.md` |
| Clean | `reconstructed-exact/Client_ShowNpcMissionDialogUI.cpp` |
| Dual A | `reviews/A_aa_009438f0_Client_ShowNpcMissionDialogUI.md` |
| Dual B | `reviews/B_aa_009438f0_Client_ShowNpcMissionDialogUI.md` |
| Chain | `reviews/CHAIN_2026-07-29_c2s_206e_seal.md` |
| Scratch | `tmp/a_009438f0.md` |
