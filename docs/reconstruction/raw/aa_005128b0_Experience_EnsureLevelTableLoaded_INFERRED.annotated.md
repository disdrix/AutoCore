# Annotated low-level: Experience_EnsureLevelTableLoaded_INFERRED

| Field | Value |
|---|---|
| Stable ID | `aa_005128b0` |
| VA | `0x005128b0` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005128b0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
