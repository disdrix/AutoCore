# Raw capture: FUN_004af8a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004af8a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004af8a0` |
| **Canonical name** | `FUN_004af8a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004af8a0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_2 - param_1 >> 3;
  iVar4 = iVar3 - (param_2 - param_1 >> 0x1f) >> 1;
  if (0 < iVar4) {
    iVar5 = param_1 + iVar4 * 8;
    do {
      puVar1 = (undefined4 *)(iVar5 + -4);
      puVar2 = (undefined4 *)(iVar5 + -8);
      iVar5 = iVar5 + -8;
      iVar4 = iVar4 + -1;
      FUN_004af0b0(param_1,iVar4,iVar3,*puVar2,*puVar1,param_3);
    } while (0 < iVar4);
  }
  return;
}
```
