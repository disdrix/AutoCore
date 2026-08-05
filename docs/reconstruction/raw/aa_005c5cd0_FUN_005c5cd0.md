# Raw capture: FUN_005c5cd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005c5cd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005c5cd0` |
| **Canonical name** | `FUN_005c5cd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005c5cd0(int param_1,undefined4 *param_2,float *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  cVar1 = *(char *)((int)puVar4 + 0x15);
  puVar2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    if (*param_3 < (float)puVar4[3] || *param_3 == (float)puVar4[3]) {
      puVar3 = (undefined4 *)*puVar4;
    }
    else {
      puVar3 = (undefined4 *)puVar4[2];
      puVar4 = puVar2;
    }
    puVar2 = puVar4;
    puVar4 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x15);
  }
  if ((puVar2 != *(undefined4 **)(param_1 + 4)) &&
     ((float)puVar2[3] < *param_3 || (float)puVar2[3] == *param_3)) {
    *param_2 = puVar2;
    return;
  }
  *param_2 = *(undefined4 **)(param_1 + 4);
  return;
}
```
