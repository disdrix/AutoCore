# Raw capture: FUN_007ffcf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007ffcf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007ffcf0` |
| **Canonical name** | `FUN_007ffcf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007ffcf0(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  bool bVar6;
  char *pcVar7;
  char acStack_12c [300];
  
  bVar6 = (&DAT_00d1775c)[param_1] == '\0';
  if (bVar6) {
    (&DAT_00d1775c)[param_1] = 1;
  }
  iVar1 = *(int *)(in_EAX + 0x109c);
  if (iVar1 == 0) {
    if (!bVar6) {
      (&DAT_00d1775c)[param_1] = 0;
    }
  }
  else {
    FUN_007a69d0();
    iVar2 = *(int *)(in_EAX + 0xe0c);
    if (bVar6) {
      if (iVar2 == 0) {
        iVar2 = FUN_007a6de0("Unknown Account",0xffffffff);
      }
      else {
        iVar2 = iVar2 + 0xc;
      }
      if (*(int *)(in_EAX + 0xe98) == 0) {
        uVar3 = FUN_007a6de0("Player",0xffffffff);
      }
      else {
        uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +
                                     *(int *)(in_EAX + 0xe98)) + 0x160))();
      }
      uVar4 = FUN_007a6de0("Chat Logging Has Been Enabled For",0xffffffff);
      sprintf(acStack_12c,"%s %s [%s]",uVar4,uVar3,iVar2);
    }
    else {
      if (iVar2 == 0) {
        iVar2 = FUN_007a6de0("Unknown Account",0xffffffff);
      }
      else {
        iVar2 = iVar2 + 0xc;
      }
      if (*(int *)(in_EAX + 0xe98) == 0) {
        uVar3 = FUN_007a6de0("Player",0xffffffff);
      }
      else {
        uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0xe98) + 4) + 4) + 4 +
                                     *(int *)(in_EAX + 0xe98)) + 0x160))();
      }
      uVar4 = FUN_007a6de0("Chat Logging Has Been Disabled For",0xffffffff);
      sprintf(acStack_12c,"%s %s [%s]",uVar4,uVar3,iVar2);
    }
    cVar5 = (-(param_1 != 0) & 10U) + 6;
    if (bVar6) {
      FUN_008f8200(iVar1,cVar5,&DAT_00a1419b,&DAT_00a1419b,0);
    }
    uVar4 = 0;
    pcVar7 = "-------------------------------------------------";
    uVar3 = FUN_007a6de0("SYSTEM",0xffffffff);
    FUN_008f8200(iVar1,cVar5,uVar3,pcVar7,uVar4);
    uVar4 = 0;
    pcVar7 = acStack_12c;
    uVar3 = FUN_007a6de0("SYSTEM",0xffffffff);
    FUN_008f8200(iVar1,cVar5,uVar3,pcVar7,uVar4);
    uVar4 = 0;
    pcVar7 = "-------------------------------------------------";
    uVar3 = FUN_007a6de0("SYSTEM",0xffffffff);
    FUN_008f8200(iVar1,cVar5,uVar3,pcVar7,uVar4);
    if (!bVar6) {
      FUN_008f8200(iVar1,cVar5,&DAT_00a1419b,&DAT_00a1419b,0);
      (&DAT_00d1775c)[param_1] = 0;
      return;
    }
  }
  return;
}
```
