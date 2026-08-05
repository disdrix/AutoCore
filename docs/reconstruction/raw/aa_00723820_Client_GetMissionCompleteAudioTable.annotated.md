# Annotated low-level: Client_GetMissionCompleteAudioTable

| Field | Value |
|---|---|
| Stable ID | `aa_00723820` |
| VA | `0x00723820` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00723820`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* Client_GetMissionCompleteAudioTable
   
   One-time init of mission-complete audio/UI table at DAT_00d20210.
   Called with names mission_complete_3 / mission_complete_5 from CVOGReaction_CompleteObjective. */

undefined * Client_GetMissionCompleteAudioTable(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009ac7a0;
  local_c = ExceptionList;
  if ((DAT_00d20630 & 1) == 0) {
    DAT_00d20630 = DAT_00d20630 | 1;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_00723510(&DAT_00d20210);
    _atexit((_func_4879 *)&LAB_009c3700);
  }
  ExceptionList = local_c;
  return &DAT_00d20210;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
