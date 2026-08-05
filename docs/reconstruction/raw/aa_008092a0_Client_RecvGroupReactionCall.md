# Raw capture: Client_RecvGroupReactionCall

| Field | Value |
|---|---|
| **Stable ID** | `aa_008092a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008092a0` |
| **Canonical name** | `Client_RecvGroupReactionCall` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_RecvGroupReactionCall  (opcode 0x206C)
   
   Apply packed LogicStateChange entries: fire reaction on resolved object (vtable+0x2c0)
   or CVOGMap_SetVariable for variable entries.
   Server soft-pedals this packet ~500ms after dialog turn-in to avoid stacking UI/FX loads. */

void Client_RecvGroupReactionCall(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  byte bVar5;
  
  bVar5 = 0;
  if (*(char *)(param_2 + 4) != '\0') {
    do {
      iVar1 = param_2 + (uint)bVar5 * 0x28;
      if (*(char *)(param_2 + 0xc + (uint)bVar5 * 0x28) == '\0') {
        if (*(char *)(iVar1 + 0x28) == '\0') {
LAB_0080934b:
          piVar3 = (int *)FUN_004bb160(0,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14)
                                      );
          if (piVar3 != (int *)0x0) {
            pvVar4 = Object_ResolveFromTFID((TFID_16 *)(iVar1 + 0x18));
            (**(code **)(*piVar3 + 0x2c0))(pvVar4);
          }
        }
        else if (*(int *)(param_1 + 0xe98) != 0) {
          iVar2 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);
          if (iVar2 == 0) {
            pvVar4 = (void *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 0x164 +
                             *(int *)(param_1 + 0xe98));
          }
          else {
            iVar2 = TFID_NotEquals((void *)(iVar1 + 0x18),
                                   (void *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2));
            if ((char)iVar2 == '\0') goto LAB_0080934b;
            pvVar4 = (void *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 0x164 +
                             *(int *)(param_1 + 0xe98));
          }
          iVar2 = TFID_NotEquals((void *)(iVar1 + 0x18),pvVar4);
          if ((char)iVar2 == '\0') goto LAB_0080934b;
        }
      }
      else {
        CVOGMap_SetVariable(*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),0);
      }
      bVar5 = bVar5 + 1;
    } while (bVar5 < *(byte *)(param_2 + 4));
  }
  return;
}
```
