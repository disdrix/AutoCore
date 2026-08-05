# Raw capture: FUN_005def00

| Field | Value |
|---|---|
| **Stable ID** | `aa_005def00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005def00` |
| **Canonical name** | `FUN_005def00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
bool __fastcall FUN_005def00(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x24))();
  param_1[2] = iVar1;
  return iVar1 == -1;
}
```
