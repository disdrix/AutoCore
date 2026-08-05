# Raw capture: FUN_008db1e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008db1e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008db1e0` |
| **Canonical name** | `FUN_008db1e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008db1e0(void)

{
  int unaff_ESI;
  char local_20 [32];
  
  if (*(char *)(unaff_ESI + 0x518) == '\0') {
    if (*(int *)(unaff_ESI + 0x5a4) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 4))(0);
    }
  }
  else if (*(int *)(unaff_ESI + 0x5a4) != 0) {
    if (*(int *)(unaff_ESI + 0x544) != 0) {
      sprintf(local_20,"%d",*(int *)(unaff_ESI + 0x544) + 1);
      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0x1d8))(local_20,1,1);
      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0xcc))(1);
      (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 0x34c))();
      return;
    }
    (**(code **)(**(int **)(unaff_ESI + 0x5a4) + 4))(0);
    return;
  }
  return;
}
```
