# Raw capture: Experience_EnsureCreatureXpTableLoaded_INFERRED

| Field | Value |
|---|---|
| **Stable ID** | `aa_005128f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005128f0` |
| **Canonical name** | `Experience_EnsureCreatureXpTableLoaded_INFERRED` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Experience_EnsureCreatureXpTableLoaded_INFERRED
   
   INFERRED lazy loader for tCreatureExperienceLevel map. */

void Experience_EnsureCreatureXpTableLoaded_INFERRED(void)

{
  int iVar1;
  
  FUN_007e1d80();
  iVar1 = FUN_007cd150(&DAT_00b04270);
  FUN_007b7df0();
  if (iVar1 < 0) {
    FUN_007a4480(0,"VOG_DEBUG_STOP");
  }
  return;
}
```
