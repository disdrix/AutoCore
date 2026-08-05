# Raw capture: FUN_005e6be0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e6be0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005e6be0` |
| **Canonical name** | `FUN_005e6be0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005e6be0(int *param_1)

{
  char cVar1;
  void *pvVar2;
  
  if ((void *)param_1[0x5b] != (void *)0x0) {
    operator_delete__((void *)param_1[0x5b]);
  }
  param_1[0x5b] = 0;
  pvVar2 = operator_new__(0x20);
  param_1[0x5b] = (int)pvVar2;
  cVar1 = (**(code **)(*param_1 + 0xa0))(pvVar2);
  if (cVar1 == '\0') {
    if ((void *)param_1[0x5b] != (void *)0x0) {
      operator_delete__((void *)param_1[0x5b]);
    }
    param_1[0x5b] = 0;
  }
  return;
}
```
