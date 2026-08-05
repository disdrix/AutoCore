# Raw capture: FUN_004f4eb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f4eb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f4eb0` |
| **Canonical name** | `FUN_004f4eb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004f4eb0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)(iVar1 + *(int *)(param_1 + 0x260)) != 0) {
      FUN_0056a260(0);
      FUN_0056b400(0);
      (**(code **)(**(int **)(iVar1 + *(int *)(param_1 + 0x260)) + 0x18))(0);
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0xc);
  return;
}
```
