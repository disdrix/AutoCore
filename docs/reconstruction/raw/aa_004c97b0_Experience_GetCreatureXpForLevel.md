# Raw capture: Experience_GetCreatureXpForLevel

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c97b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c97b0` |
| **Canonical name** | `Experience_GetCreatureXpForLevel` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Experience_GetCreatureXpForLevel — tCreatureExperienceLevel lookup
   
   Parameters: nCreatureLevel
   Returns: uint XP at map entry +0x10, or 0 if missing
   Lazy-inits via Experience_EnsureCreatureXpTableLoaded_INFERRED
   Map entry type: CreatureXpMapEntry_INFERRED */

uint __cdecl Experience_GetCreatureXpForLevel(int nCreatureLevel)

{
  void *pvVar1;
  int *extraout_EAX;
  int *unaff_EDI;
  undefined1 abScratch [4];
  
  if (g_nCreatureXpTableReady == 0) {
    Experience_EnsureCreatureXpTableLoaded_INFERRED();
  }
  Map_LowerBoundFindByIntKey(&DAT_00b04270,abScratch,&nCreatureLevel,unaff_EDI);
  pvVar1 = (void *)*extraout_EAX;
  if (g_nCreatureXpTableReady == 0) {
    Experience_EnsureCreatureXpTableLoaded_INFERRED();
  }
  if (pvVar1 != g_pCreatureXpMapEnd) {
    return *(uint *)((int)pvVar1 + 0x10);
  }
  return 0;
}
```
