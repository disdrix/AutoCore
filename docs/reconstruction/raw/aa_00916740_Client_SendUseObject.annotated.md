# Annotated low-level: Client_SendUseObject

| Field | Value |
|---|---|
| Stable ID | `aa_00916740` |
| VA | `0x00916740` |
| System | interaction-activation |
| Date | 2026-07-29 (residual seal: listing + call sites) |

## Machine-level notes

- Source: raw capture + Ghidra decompile ≡ raw body; **listing** seals ESP layout and globals.
- Prefer assembly when decompiler conflicts — here they agree; listing adds pad/trail/global VAs.
- **Entry:** ECX = client; EAX = target (sealed at all four CALL sites).
- **Packet** after `SUB ESP,0x20`:
  - `+0x00` opcode `0x2072`
  - `+0x04` pad **unwritten**
  - `+0x08..+0x17` TFID_16 bulk from `obj+0x160`
  - `+0x18` IDObjective
  - `+0x1c` trailer **unwritten**
- **FindObjective** this = `DAT_00d1b6d8` (not client); key = `*( *(target+0xa8)+0x34 )`.
- **Net:** `DAT_00d1b4b8` vtbl`+0x18` (contrast IfInteractable `client+0xc78`).
- Callers gate range / interact flags; **this function does not**.

## Listing map (authoritative offsets)

```
00916740  SUB ESP,0x20
00916743  MOV [ECX+0xd28],EAX              ; stash
00916749  LEA EDX,[EAX+0x160]              ; TFID base
0091674f..79  four dwords → [ESP+8..14]
0091676c  MOV ECX,[0x00d1b6d8]             ; character for FindObjective
00916772  MOV [ESP],0x2072                 ; opcode
0091677d  MOV EAX,[EAX+0x34]               ; key (EAX was clonebase*)
00916780  PUSH EAX
00916781  CALL 0x00525bd0
00916786..9b  [ESP+0x18] = def+0x10 or -1
0091679b  MOV ECX,[0x00d1b4b8]             ; sector net
009167a1  TEST ECX / JZ
009167a7..b2  PUSH 0; PUSH 0x20; LEA packet; PUSH -1; CALL [vtbl+0x18]
009167b5  ADD ESP,0x20
009167b8  RET
```

## Pseudocode (annotated)

```c
/* Client_SendUseObject C2S 0x2072 size 0x20:
   +0 opcode, +4 pad, +8 TFID16, +0x18 IDObjective (or -1), +0x1c trail.
   FindObjective this = DAT_00d1b6d8; net = DAT_00d1b4b8. */

void Client_SendUseObject(void) /* ECX=client, EAX=target */
{
  int client = ECX;
  int target = EAX;
  uint32_t packet[8]; /* 0x20 */

  *(int *)(client + 0xd28) = target;

  /* TFID_16 bulk — not field-wise Coid/Global stores */
  packet_tfid_dwords[0..3] = *(uint32_t *)(target + 0x160 + 4*i);

  packet_opcode = 0x2072;

  pObjDef = Client_FindObjectiveMatchingTarget(
      /*this=*/ *(DAT_00d1b6d8),
      *(uint32_t *)(*(int *)(target + 0xa8) + 0x34));
  packet_objective = (pObjDef == 0) ? 0xffffffff : *(uint32_t *)(pObjDef + 0x10);

  if (*(DAT_00d1b4b8) != 0) {
    (**(code **)(**(int **)DAT_00d1b4b8 + 0x18))
      (0xffffffff, &packet, 0x20, 0);
  }
}
```

## Callers (register setup)

| Site | Parent | ECX | EAX |
|---|---|---|---|
| `00924ee5` | InteractClickPickTarget | EBX | `[EBX+0x758]` |
| `00927be1` | PollBoundActions | EBX | EDI |
| `0081004c` / `008100fa` | RecvCompleteDynamicObjective | `[DAT_00d1b778]` | world object* |

## Open questions

- Pad `@+0x04` / trail `@+0x1c` live wire values.
- `DAT_00d1b4b8` equality to `client+0xc78`.
- C++ types of the three globals (roles sealed).
