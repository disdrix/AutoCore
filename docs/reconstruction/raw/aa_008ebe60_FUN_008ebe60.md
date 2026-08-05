# Raw capture: FUN_008ebe60

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ebe60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008ebe60` |
| **Canonical name** | `FUN_008ebe60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008ebe60(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x5ac) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5ac) + 0xd0))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(unaff_ESI + 0x5ac) + 0xcc))(0);
                    /* WARNING: Could not recover jumptable at 0x008ebe93. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(unaff_ESI + 0x5ac) + 0x34c))();
      return;
    }
  }
  return;
}
```
