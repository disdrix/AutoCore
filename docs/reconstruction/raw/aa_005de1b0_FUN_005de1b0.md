# Raw capture: FUN_005de1b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005de1b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005de1b0` |
| **Canonical name** | `FUN_005de1b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005de1b0(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(int *)(param_1 + 8) - iVar4 >> 4;
  }
  if (uVar3 < param_2) {
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(param_1 + 8) - iVar4 >> 4;
    }
    FUN_004cbfc0(*(undefined4 *)(param_1 + 8),param_2 - iVar4,&stack0x00000008);
    return;
  }
  if (((iVar4 != 0) && (iVar1 = *(int *)(param_1 + 8), param_2 < (uint)(iVar1 - iVar4 >> 4))) &&
     (iVar4 = param_2 * 0x10 + iVar4, iVar4 != iVar1)) {
    uVar2 = FUN_0043fb00(iVar1,iVar1,iVar4,param_2);
    *(undefined4 *)(param_1 + 8) = uVar2;
  }
  return;
}
```
