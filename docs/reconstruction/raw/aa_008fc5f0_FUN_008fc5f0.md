# Raw capture: FUN_008fc5f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008fc5f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008fc5f0` |
| **Canonical name** | `FUN_008fc5f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008fc5f0(char param_1)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x730) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x730) + 0xd0))();
    if (param_1 == '\0') {
      if (cVar1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x008fc63c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(unaff_ESI + 0x730) + 0xcc))();
        return;
      }
    }
    else if (cVar1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x008fc622. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(unaff_ESI + 0x730) + 0xcc))();
      return;
    }
  }
  return;
}
```
