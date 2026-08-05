# Annotated low-level: SkillSet_GetEntryCount

| Field | Value |
|---|---|
| Stable ID | `aa_00402d80` |
| VA | `0x00402d80` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00402d80`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* SkillSet_GetEntryCount(pSkillSet)
   
   Returns (end-begin)/0x18 for NPCSkillSetEntry vector at +0x4/+0x8. */

int __fastcall SkillSet_GetEntryCount(void *pSkillSet)

{
  if (*(int *)((int)pSkillSet + 4) == 0) {
    return 0;
  }
  return (*(int *)((int)pSkillSet + 8) - *(int *)((int)pSkillSet + 4)) / 0x18;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
