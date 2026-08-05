# Raw capture: FUN_0053ada0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053ada0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0053ada0` |
| **Canonical name** | `FUN_0053ada0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0053ada0(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *local_4;
  
  if (((int *)*param_1 == (int *)0x0) || (*(int *)*param_1 == 0)) {
    local_4 = param_1;
    piVar2 = _aligned_malloc(700,0x10);
    iVar4 = param_1[2];
    if ((iVar4 == 0) || ((uint)(param_1[4] - iVar4 >> 2) <= (uint)(param_1[3] - iVar4 >> 2))) {
      local_4 = piVar2;
      FUN_004073a0(param_1[3],1,&local_4);
    }
    else {
      puVar1 = (undefined4 *)param_1[3];
      *puVar1 = piVar2;
      param_1[3] = (int)(puVar1 + 1);
    }
    *param_1 = (int)piVar2;
    iVar4 = 0x18;
    piVar3 = piVar2;
    do {
      iVar4 = iVar4 + -1;
      *piVar3 = (int)(piVar3 + 7);
      piVar3 = piVar3 + 7;
    } while (iVar4 != 0);
    piVar2[0xa8] = 0;
  }
  *param_1 = *(int *)*param_1;
  return;
}
```
