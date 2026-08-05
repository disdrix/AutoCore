# Raw capture: Client_SendUseObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00916740` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00916740` |
| **Canonical name** | `Client_SendUseObject` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_SendUseObject C2S 0x2072 size 0x20:

   +0 opcode, +4 pad, +8 TFID16, +0x18 IDObjective (or -1).

   Server UseObjectPacket after opcode strip: pad4 + TFID + ObjectiveId.

   NpcInteractHandler: range 30f, deliver dialog 0x206D, response 0x206E. */



void __fastcall Client_SendUseObject(int param_1)



{

  int in_EAX;

  int iVar1;

  undefined4 local_20 [2];

  undefined4 local_18;

  undefined4 local_14;

  undefined4 local_10;

  undefined4 local_c;

  undefined4 local_8;

  

  *(int *)(param_1 + 0xd28) = in_EAX;

  local_18 = *(undefined4 *)(in_EAX + 0x160);

  local_14 = *(undefined4 *)(in_EAX + 0x164);

  local_10 = *(undefined4 *)(in_EAX + 0x168);

  local_c = *(undefined4 *)(in_EAX + 0x16c);

  local_20[0] = 0x2072;

  iVar1 = Client_FindObjectiveMatchingTarget(*(undefined4 *)(*(int *)(in_EAX + 0xa8) + 0x34));

  if (iVar1 == 0) {

    local_8 = 0xffffffff;

  }

  else {

    local_8 = *(undefined4 *)(iVar1 + 0x10);

  }

  if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

    (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,local_20,0x20,0);

  }

  return;

}
```

---

## Version: 2026-07-29 re-decompile check

| Field | Value |
|---|---|
| Tool | Ghidra MCP `batch_decompile` `0x00916740` program `autoassault.exe` |
| Result | Body **byte-identical** to 2026-07-23 raw pseudocode above |
| Callers | `Client_Input_PollBoundActions` `0x00925d60`; `Client_InteractClickPickTarget` `0x009247b0`; `Client_RecvCompleteDynamicObjective` `0x0080ff00` |
| Callees | `Client_FindObjectiveMatchingTarget` `0x00525bd0` |
| System assignment | `interaction-activation` (was unknown) |

---

## Version: 2026-07-29 residual seal (listing + callers)

| Field | Value |
|---|---|
| Tool | Ghidra `disassemble_function` `0x00916740`; `read_memory` length 128; `get_assembly_context` on 4 xrefs; `get_function_callers` |
| Decompile | Re-checked — still ≡ 2026-07-23 body |
| Opcode | `MOV [ESP],0x2072` @ `00916772`; size `PUSH 0x20` @ `009167a9` |
| Layout | `+0` opcode; `+4` unwritten; `+8..+14` TFID dwords; `+18` objective; `+1c` unwritten |
| TFID | `LEA EDX,[EAX+0x160]` then 4 dwords → `[ESP+8..14]` |
| FindObjective this | `MOV ECX,[0x00d1b6d8]` before `CALL 0x00525bd0` |
| Net global | `MOV ECX,[0x00d1b4b8]` before vtbl`+0x18` |
| Call sites | `00924ee5` (EAX=`[EBX+758]`, ECX=EBX); `00927be1` (EAX=EDI, ECX=EBX); `0081004c`/`008100fa` (ECX=`[DAT_00d1b778]`) |
| Entry | First stores prove ECX=client, EAX=target (`MOV [ECX+0xd28],EAX`) |

### Full listing (body)

```
00916740: SUB ESP,0x20
00916743: MOV dword ptr [ECX + 0xd28],EAX
00916749: LEA EDX,[EAX + 0x160]
0091674f: MOV ECX,dword ptr [EDX]
00916751: MOV EAX,dword ptr [EAX + 0xa8]
00916757: MOV dword ptr [ESP + 0x8],ECX
0091675b: MOV ECX,dword ptr [EDX + 0x4]
0091675e: MOV dword ptr [ESP + 0xc],ECX
00916762: MOV ECX,dword ptr [EDX + 0x8]
00916765: MOV EDX,dword ptr [EDX + 0xc]
00916768: MOV dword ptr [ESP + 0x10],ECX
0091676c: MOV ECX,dword ptr [0x00d1b6d8]
00916772: MOV dword ptr [ESP],0x2072
00916779: MOV dword ptr [ESP + 0x14],EDX
0091677d: MOV EAX,dword ptr [EAX + 0x34]
00916780: PUSH EAX
00916781: CALL 0x00525bd0
00916786: TEST EAX,EAX
00916788: JZ 0x00916793
0091678a: MOV ECX,dword ptr [EAX + 0x10]
0091678d: MOV dword ptr [ESP + 0x18],ECX
00916791: JMP 0x0091679b
00916793: MOV dword ptr [ESP + 0x18],0xffffffff
0091679b: MOV ECX,dword ptr [0x00d1b4b8]
009167a1: TEST ECX,ECX
009167a3: JZ 0x009167b5
009167a5: MOV EDX,dword ptr [ECX]
009167a7: PUSH 0x0
009167a9: PUSH 0x20
009167ab: LEA EAX,[ESP + 0x8]
009167af: PUSH EAX
009167b0: PUSH -0x1
009167b2: CALL dword ptr [EDX + 0x18]
009167b5: ADD ESP,0x20
009167b8: RET
```
