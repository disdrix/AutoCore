# Raw capture: Experience_EnsureQuestXpTableLoaded_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_005127f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005127f0` |
| **Canonical name** | `Experience_EnsureQuestXpTableLoaded_INFERRED` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Experience_EnsureQuestXpTableLoaded_INFERRED
   
   INFERRED lazy loader for tQuestXPLookup map. */

void Experience_EnsureQuestXpTableLoaded_INFERRED(void)

{
  int iVar1;
  
  FUN_007e1d80();
  iVar1 = FUN_007cc0d0(&g_pQuestXpLookupMap_INFERRED);
  FUN_007b7df0();
  if (iVar1 < 0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  return;
}
```
