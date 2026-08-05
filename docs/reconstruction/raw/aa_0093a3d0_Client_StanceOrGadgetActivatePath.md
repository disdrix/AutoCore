# Raw capture: Client_StanceOrGadgetActivatePath

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093a3d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0093a3d0` |
| **Canonical name** | `Client_StanceOrGadgetActivatePath` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_StanceOrGadgetActivatePath (INFERRED)
   
   Related cast-again start for stance/gadget slot path (opcode 0x20bb nearby).
   Uses Skill_StartCastAgainHeartbeat when world+0x7e==0.
   
   INFERRED purpose from callees; not fully walked. */

void Client_StanceOrGadgetActivatePath(void)

{
  int in_EAX;
  void *pvVar1;
  int iVar2;
  char *pcVar3;
  void *pA;
  int unaff_EBX;
  int iVar4;
  int unaff_EDI;
  byte *pB;
  undefined4 local_118 [2];
  undefined4 local_110;
  undefined4 local_10c;
  undefined1 local_108;
  char acStack_100 [256];
  
  if (*(int *)(in_EAX + 0xe98) != 0) {
    if (unaff_EBX != -1) {
      if ((unaff_EBX < 0) || (2 < unaff_EBX)) {
        iVar4 = -1;
      }
      else {
        iVar4 = *(int *)(*(int *)(in_EAX + 0xe98) + 0xd58 + unaff_EBX * 4);
      }
      pvVar1 = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) +
                                             4 + *(int *)(in_EAX + 0xe98)) + 0x234))(iVar4);
      if ((pvVar1 != (void *)0x0) && (*(short *)((int)pvVar1 + 0x5f6) != 0)) {
        iVar2 = Skill_LocalCastValidate
                          ((void *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +
                                   *(int *)(in_EAX + 0xe98)),(void *)0x0,(char)pvVar1,(void *)0x0);
        if ((iVar2 != 0) &&
           ((*(int **)(in_EAX + 0xf40) != (int *)0x0 && (**(int **)(in_EAX + 0xf40) != 0)))) {
          if (*(int *)(in_EAX + 0xe98) == 0) {
            pvVar1 = (void *)0x0;
          }
          else {
            pvVar1 = (void *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +
                             *(int *)(in_EAX + 0xe98));
          }
          pcVar3 = Skill_FormatFailureMessage(iVar2,acStack_100,pvVar1);
          if (DAT_00d1b8dc == 0) {
            return;
          }
          FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,pcVar3,0);
          return;
        }
        if (*(char *)(*(int *)(in_EAX + 0xe04) + 0x7e) == '\0') {
          pB = g_abTfidInvalid_A15870;
          Skill_LookupActiveCastBinding(local_118,iVar4);
          iVar2 = TFID_EqualsObjectId(pA,pB);
          if (((char)iVar2 != '\0') &&
             (Skill_ClearActiveCastCounterAndQueueId(iVar4), *(char *)((int)pvVar1 + 0x61c) == '\0')
             ) {
            Skill_StartCastAgainHeartbeat
                      ((void *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +
                               *(int *)(in_EAX + 0xe98)),pvVar1,
                       (void *)(int)*(short *)((int)pvVar1 + 0x14),unaff_EDI);
          }
        }
        if (*(short *)((int)pvVar1 + 0x14) != 0) {
          (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +
                               *(int *)(in_EAX + 0xe98)) + 0x238))
                    (3,iVar4,(int)(short)(*(short *)((int)pvVar1 + 0x174) +
                                         *(short *)((int)pvVar1 + 0x5f6)),0,0,0,0,0);
        }
      }
    }
    local_118[0] = 0x20bb;
    local_108 = (undefined1)unaff_EBX;
    iVar4 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);
    local_110 = *(undefined4 *)(iVar4 + 0x164 + DAT_00d1b6d8);
    local_10c = *(undefined4 *)(iVar4 + 0x168 + DAT_00d1b6d8);
    if (*(int *)(in_EAX + 0xc78) != 0) {
      (**(code **)(**(int **)(in_EAX + 0xc78) + 0x18))(0xffffffff,local_118,0x18,0);
    }
  }
  return;
}
```
