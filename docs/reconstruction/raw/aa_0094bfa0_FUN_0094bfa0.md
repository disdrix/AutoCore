# Raw capture: FUN_0094bfa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094bfa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0094bfa0` |
| **Canonical name** | `FUN_0094bfa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0094bfa0(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 0x10a0);
  if ((iVar1 != 0) && (DAT_00d1775e = (undefined1)param_1, *(int *)(iVar1 + 0x5b4) != 0)) {
    (**(code **)(**(int **)(iVar1 + 0x5b4) + 0x3c8))(param_1,1);
  }
  return;
}
```
