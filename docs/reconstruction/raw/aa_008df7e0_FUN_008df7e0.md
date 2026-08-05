# Raw capture: FUN_008df7e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008df7e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008df7e0` |
| **Canonical name** | `FUN_008df7e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_008df7e0(int *param_1,float param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if ((cVar1 != '\0') && (DAT_00d1b6d8 != 0)) {
    param_1[0x143] = (int)((float)param_1[0x143] + param_2);
    FUN_00791f30(param_2);
  }
  return;
}
```
