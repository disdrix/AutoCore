# Raw capture: FUN_0068ddc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068ddc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0068ddc0` |
| **Canonical name** | `FUN_0068ddc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_0068ddc0(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  if (param_1 == param_2) {
    return param_1;
  }
  iVar5 = *(int *)(param_2 + 4);
  if (iVar5 != 0) {
    uVar3 = *(int *)(param_2 + 8) - iVar5 >> 4;
    if (uVar3 != 0) {
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(int *)(param_1 + 8) - iVar1 >> 4;
      }
      if (uVar3 <= uVar6) {
        uVar4 = FUN_0068c330(iVar5,*(int *)(param_2 + 8),iVar1,param_2);
        FUN_0068cfe0(uVar4,*(undefined4 *)(param_1 + 8),param_1,param_2);
        if (*(int *)(param_2 + 4) == 0) {
          *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
          return param_1;
        }
        *(int *)(param_1 + 8) =
             (*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 4) * 0x10 + *(int *)(param_1 + 4);
        return param_1;
      }
      if (iVar1 == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(int *)(param_1 + 0xc) - iVar1 >> 4;
      }
      if (uVar6 < uVar3) {
        if (iVar1 != 0) {
          FUN_00693ae0(iVar1,*(undefined4 *)(param_1 + 8));
                    /* WARNING: Subroutine does not return */
          operator_delete(*(void **)(param_1 + 4));
        }
        if (*(int *)(param_2 + 4) == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 4;
        }
        cVar2 = FUN_0068b700(iVar5);
        if (cVar2 == '\0') {
          return param_1;
        }
        uVar4 = FUN_0068d160(*(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 8),
                             *(undefined4 *)(param_1 + 4));
        *(undefined4 *)(param_1 + 8) = uVar4;
        return param_1;
      }
      if (iVar1 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1 + 8) - iVar1 >> 4;
      }
      iVar5 = iVar5 * 0x10 + *(int *)(param_2 + 4);
      FUN_0068c330(*(int *)(param_2 + 4),iVar5,iVar1,param_2);
      uVar4 = FUN_0068cf50(iVar5,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_1 + 8),param_1,
                           param_2);
      *(undefined4 *)(param_1 + 8) = uVar4;
      return param_1;
    }
  }
  FUN_0068d180();
  return param_1;
}
```
