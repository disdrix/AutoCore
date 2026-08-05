# Annotated low-level: Experience_EnsureQuestXpTableLoaded_INFERRED

| Field | Value |
|---|---|
| Stable ID | `aa_005127f0` |
| VA | `0x005127f0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005127f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
