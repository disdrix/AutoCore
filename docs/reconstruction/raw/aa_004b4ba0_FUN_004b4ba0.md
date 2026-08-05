# Raw capture: FUN_004b4ba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b4ba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004b4ba0` |
| **Canonical name** | `FUN_004b4ba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004b4ba0(int param_1)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0xd8))(0);
    (**(code **)(*piVar1 + 0x24))(0);
    (**(code **)(*piVar1 + 0x1c))(0x3f000000);
    (**(code **)(*piVar1 + 0x14))(0x3f000000);
  }
  return;
}
```
