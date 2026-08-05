# Annotated low-level: Experience_GetCreatureXpForLevel

| Field | Value |
|---|---|
| Stable ID | `aa_004c97b0` |
| VA | `0x004c97b0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_004c97b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
