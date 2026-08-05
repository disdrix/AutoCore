# Raw capture: FUN_007aec10

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aec10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007aec10` |
| **Canonical name** | `FUN_007aec10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_007aec10(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = (**(code **)(*param_1 + 0x328))();
  if (cVar1 == '\0') {
    param_1[0xa7] = 0;
  }
  else {
    iVar2 = (**(code **)(*param_1 + 0x5c))(param_1[0xa5]);
    param_1[0xa7] = iVar2;
  }
  if (param_1[0xa7] != 0) {
    iVar2 = FUN_007ae2a0(param_1[0xa7]);
    param_1[0xa8] = iVar2;
    return;
  }
  param_1[0xa8] = 0;
  return;
}
```
