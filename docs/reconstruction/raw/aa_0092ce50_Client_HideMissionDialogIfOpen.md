# Raw capture: Client_HideMissionDialogIfOpen

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092ce50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0092ce50` |
| **Canonical name** | `Client_HideMissionDialogIfOpen` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_HideMissionDialogIfOpen
   
   If mission dialog root at game+0x107c is visible (vtable+0x3d8), hide it (+0x448)
   and refresh layout (+0x34c). */

void Client_HideMissionDialogIfOpen(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x107c) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x107c) + 0x3d8))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(unaff_ESI + 0x107c) + 0x448))();
                    /* WARNING: Could not recover jumptable at 0x0092ce81. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(unaff_ESI + 0x107c) + 0x34c))();
      return;
    }
  }
  return;
}
```
