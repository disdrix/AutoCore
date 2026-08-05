# Raw capture: FUN_004aeef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004aeef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004aeef0` |
| **Canonical name** | `FUN_004aeef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004aeef0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 code *param_6)

{
  char cVar1;
  int iVar2;
  
  while (param_3 < param_2) {
    iVar2 = (param_2 + -1) / 2;
    cVar1 = (*param_6)(*(undefined4 *)(param_1 + iVar2 * 8),*(undefined4 *)(param_1 + 4 + iVar2 * 8)
                       ,param_4,param_5);
    if (cVar1 == '\0') break;
    *(undefined4 *)(param_1 + param_2 * 8) = *(undefined4 *)(param_1 + iVar2 * 8);
    *(undefined4 *)(param_1 + 4 + param_2 * 8) = *(undefined4 *)(param_1 + 4 + iVar2 * 8);
    param_2 = iVar2;
  }
  *(undefined4 *)(param_1 + 4 + param_2 * 8) = param_5;
  *(undefined4 *)(param_1 + param_2 * 8) = param_4;
  return;
}
```
