# Raw capture: FUN_005dfee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dfee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005dfee0` |
| **Canonical name** | `FUN_005dfee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_005dfee0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int aiStack_70 [5];
  undefined4 uStack_5c;
  undefined *puStack_58;
  int aiStack_40 [2];
  undefined *puStack_38;
  undefined4 uStack_34;
  undefined4 uStack_1c;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  uStack_34 = 4;
  puStack_38 = &DAT_00bc56b0;
  aiStack_40[1] = 0x5dff0d;
  (**(code **)(*param_2 + 0x14))();
  aiStack_40[1] = 1;
  aiStack_40[0] = param_1 + 0x1a0;
  (**(code **)(*param_2 + 0x14))();
  (**(code **)(*param_2 + 0x14))();
  (**(code **)(*param_2 + 0x14))();
  if (*(void **)(param_1 + 0x194) == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x194) = 0;
    *(undefined4 *)(param_1 + 0x198) = 0;
    *(undefined4 *)(param_1 + 0x19c) = 0;
    puStack_38 = (undefined *)0x0;
    aiStack_40[1] = 0;
    aiStack_40[0] = 0;
    piVar3 = aiStack_40;
    piVar5 = aiStack_70;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar5 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar5 = piVar5 + 1;
    }
    FUN_005e0310(uStack_1c);
    uVar4 = 0;
    iVar2 = 0;
    while( true ) {
      if (*(int *)(param_1 + 0x194) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(param_1 + 0x198) - *(int *)(param_1 + 0x194) >> 5;
      }
      if (iVar1 <= (int)uVar4) break;
      iVar1 = *(int *)(param_1 + 0x194);
      if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x198) - iVar1 >> 5) <= uVar4)) {
        FUN_005df640();
        return 1;
      }
      puStack_58 = (undefined *)(iVar2 + iVar1);
      uStack_5c = 0x5dffc9;
      (**(code **)(*param_2 + 0x14))();
      uVar4 = uVar4 + 1;
      iVar2 = iVar2 + 0x20;
    }
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  puStack_58 = &UNK_005dff51;
  operator_delete(*(void **)(param_1 + 0x194));
}
```
