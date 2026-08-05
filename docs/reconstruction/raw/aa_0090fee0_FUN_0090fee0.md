# Raw capture: FUN_0090fee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090fee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0090fee0` |
| **Canonical name** | `FUN_0090fee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0090fee0(int *param_1)

{
  int iVar1;
  int in_EAX;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_0090fe50();
  piVar2 = (int *)CVOGReaction_GiveItemByCbid(in_EAX);
  param_1[0x28a] = (int)piVar2;
  if (piVar2 == (int *)0x0) {
    FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer");
    return;
  }
  (**(code **)(*piVar2 + 8))();
  puVar3 = (undefined4 *)(**(code **)(*(int *)param_1[0x28a] + 0x1cc))();
  (**(code **)*puVar3)(1,0,0,0,0,0,0,g_flOne,0);
  DAT_00d09a68 = 0;
  iVar1 = puVar3[2];
  if (iVar1 != 0) {
    DAT_00d09a68 = iVar1;
    iVar4 = (**(code **)(*param_1 + 0x1a8))();
    if (iVar1 != 0) {
      *(undefined1 *)(iVar4 + 0x48) = 1;
      *(undefined4 *)(iVar4 + 0x44) = *(undefined4 *)(iVar4 + 0x40);
      FUN_0076c4d0();
      (**(code **)(**(int **)(iVar4 + 8) + 4))(iVar1);
      FUN_00755f10(iVar1);
    }
  }
  return;
}
```
