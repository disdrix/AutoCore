# Raw capture: Client_RecvCraftFromAssemblyKitResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080b640` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0080b640` |
| **Canonical name** | `Client_RecvCraftFromAssemblyKitResponse` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Client_RecvCraftFromAssemblyKitResponse(int param_1)

{
  undefined4 uVar1;
  undefined4 unaff_ESI;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  size_t _Count;
  undefined4 uVar5;
  char local_98 [128];
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_007a69d0();
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0:
    _Count = 0x80;
    local_18 = 0xffffffff;
    local_98[0] = '\0';
    pcVar2 = (char *)FUN_007a6de0("Item Created!",0xffffffff);
    strncpy(local_98,pcVar2,_Count);
    local_14 = g_flLevelUpUiBase_Inferred;
    local_c = 0;
    local_10 = DAT_00aaa68c;
    local_18 = 0xffeee3d8;
    local_8 = 0xffffffff;
    local_4 = 0xffffffff;
    FUN_0040c5c0(local_98);
    return;
  case 1:
    pcVar2 = "Failed Crafting: Object not a kit.";
    break;
  case 2:
    pcVar2 = "Failed Crafting: Invalid ingredient list.";
    break;
  case 3:
    pcVar2 = "Experimentation Failed.";
    break;
  case 4:
    pcVar2 = "Not enough skill to attempt this.";
    break;
  case 5:
    pcVar2 = "You are not near a valid crafting station.";
    break;
  default:
    return;
  }
  uVar5 = 0;
  uVar4 = 1;
  uVar3 = 0xffffffff;
  uVar1 = FUN_007a6de0(pcVar2,0xffffffff);
  FUN_007fdfb0(unaff_ESI,uVar1,uVar3,uVar4,uVar5);
  return;
}
```
