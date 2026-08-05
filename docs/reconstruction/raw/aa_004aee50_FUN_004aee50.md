# Raw capture: FUN_004aee50

| Field | Value |
|---|---|
| **Stable ID** | `aa_004aee50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004aee50` |
| **Canonical name** | `FUN_004aee50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004aee50(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,code *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  
  cVar3 = (*param_4)(*param_2,param_2[1],*param_1,param_1[1]);
  if (cVar3 != '\0') {
    uVar1 = *param_2;
    uVar2 = param_2[1];
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    *param_1 = uVar1;
    param_1[1] = uVar2;
  }
  cVar3 = (*param_4)(*param_3,param_3[1],*param_2,param_2[1]);
  if (cVar3 != '\0') {
    uVar1 = *param_3;
    uVar2 = param_3[1];
    *param_3 = *param_2;
    param_3[1] = param_2[1];
    *param_2 = uVar1;
    param_2[1] = uVar2;
  }
  cVar3 = (*param_4)(*param_2,param_2[1],*param_1,param_1[1]);
  if (cVar3 != '\0') {
    uVar1 = *param_2;
    uVar2 = param_2[1];
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    *param_1 = uVar1;
    param_1[1] = uVar2;
  }
  return;
}
```
