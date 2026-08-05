# Raw capture: FUN_005ca5e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ca5e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ca5e0` |
| **Canonical name** | `FUN_005ca5e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_005ca5e0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x80))();
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      iVar3 = FUN_005c9a60();
      iVar1 = *(int *)(iVar3 + 4);
      if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 8) - iVar1 >> 2) <= uVar4)) {
LAB_005ca678:
                    /* WARNING: Subroutine does not return */
        FUN_004ccf30();
      }
      *(undefined4 *)(iVar1 + uVar4 * 4) = *(undefined4 *)(param_2 + uVar4 * 4);
      iVar3 = FUN_005c9a60();
      iVar1 = *(int *)(iVar3 + 4);
      if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 8) - iVar1 >> 2) <= uVar4)) goto LAB_005ca678;
      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x68))
                (*(undefined2 *)(iVar1 + uVar4 * 4),param_3);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  return 1;
}
```
