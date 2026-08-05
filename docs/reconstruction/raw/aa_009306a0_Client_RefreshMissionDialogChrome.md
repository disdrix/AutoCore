# Raw capture: Client_RefreshMissionDialogChrome

| Field | Value |
|---|---|
| **Stable ID** | `aa_009306a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x009306a0` |
| **Canonical name** | `Client_RefreshMissionDialogChrome` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_RefreshMissionDialogChrome
   
   If dialog chrome at game+0x10b0 is open, call FUN_008a05a0 to refresh it. */

void Client_RefreshMissionDialogChrome(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x10b0) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x10b0) + 0x3d8))();
    if (cVar1 != '\0') {
      FUN_008a05a0();
    }
  }
  return;
}
```
