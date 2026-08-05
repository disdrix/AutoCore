# Raw capture: FUN_004dbbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dbbb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004dbbb0` |
| **Canonical name** | `FUN_004dbbb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004dbbb0(int param_1,undefined4 param_2,uint param_3)

{
  void *pvVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe5c8) + 0x10) +
                           (*(uint *)(*(int *)(param_1 + 0xe5c8) + 8) & param_3) * 4) + 4);
  if (iVar2 == 0) {
LAB_004dbbe4:
    iVar2 = 0;
  }
  else {
    do {
      if (param_3 == *(uint *)(iVar2 + 0x10)) {
        if (iVar2 == 0) goto LAB_004dbbe4;
        iVar2 = *(int *)(iVar2 + 8);
        goto LAB_004dbbeb;
      }
      iVar2 = *(int *)(iVar2 + 0xc);
    } while (iVar2 != 0);
    iVar2 = 0;
  }
LAB_004dbbeb:
  if ((iVar2 != 0) &&
     (pvVar1 = CNDHash_LookupByKey(*(void **)(param_1 + 0xe5cc),param_3), pvVar1 == (void *)0x0)) {
    FUN_004e7c30(param_3,iVar2,0);
  }
  return;
}
```
