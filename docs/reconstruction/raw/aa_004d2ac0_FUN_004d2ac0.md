# Raw capture: FUN_004d2ac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d2ac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004d2ac0` |
| **Canonical name** | `FUN_004d2ac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
bool __thiscall FUN_004d2ac0(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  void *pvVar1;
  
  if (*(char *)(param_1 + 0x83) != '\0') {
    return true;
  }
  pvVar1 = CNDHash_LookupByKey(*(void **)(param_2 + 0x534),param_4);
  return pvVar1 != (void *)0x0;
}
```
