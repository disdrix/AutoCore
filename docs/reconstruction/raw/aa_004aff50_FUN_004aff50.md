# Raw capture: FUN_004aff50

| Field | Value |
|---|---|
| **Stable ID** | `aa_004aff50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004aff50` |
| **Canonical name** | `FUN_004aff50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004aff50(undefined4 *param_1,undefined4 *param_2,code *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 *puVar4;
  
  puVar2 = param_1;
  if (param_1 != param_2) {
    while (puVar2 = puVar2 + 2, puVar2 != param_2) {
      cVar3 = (*param_3)(*puVar2,puVar2[1],*param_1,param_1[1]);
      if (cVar3 == '\0') {
        cVar3 = (*param_3)(*puVar2,puVar2[1],puVar2[-2],puVar2[-1]);
        puVar1 = puVar2;
        if (cVar3 != '\0') {
          do {
            puVar4 = puVar1 + -2;
            cVar3 = (*param_3)(*puVar2,puVar2[1],puVar1[-4],puVar1[-3]);
            puVar1 = puVar4;
          } while (cVar3 != '\0');
          if ((puVar4 != puVar2) && (puVar2 != puVar2 + 2)) {
            FUN_0044d320(puVar4,puVar2,puVar2 + 2,0,0);
          }
        }
      }
      else if ((param_1 != puVar2) && (puVar2 != puVar2 + 2)) {
        FUN_0044d320(param_1,puVar2,puVar2 + 2,0,0);
      }
    }
  }
  return;
}
```
