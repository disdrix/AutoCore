# Raw capture: Experience_EnsureLevelTableLoaded_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_005128b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005128b0` |
| **Canonical name** | `Experience_EnsureLevelTableLoaded_INFERRED` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Experience_EnsureLevelTableLoaded_INFERRED
   
   INFERRED lazy loader for tExperienceLevel map (g_nExperienceLevelTableReady).
   Called when ready flag is 0 before threshold lookups. */

void Experience_EnsureLevelTableLoaded_INFERRED(void)

{
  int iVar1;
  
  FUN_007e1d80();
  iVar1 = FUN_007cbbb0(&g_pExperienceLevelMap_INFERRED);
  FUN_007b7df0();
  if (iVar1 < 0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  return;
}
```
