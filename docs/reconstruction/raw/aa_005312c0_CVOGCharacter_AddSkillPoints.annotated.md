# Annotated low-level: CVOGCharacter_AddSkillPoints

| Field | Value |
|---|---|
| Stable ID | `aa_005312c0` |
| VA | `0x005312c0` |
| System | skills-abilities |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005312c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* CVOGCharacter_AddSkillPoints — add short skill points to character pool (mission
   advance/complete).
   
   Parameters: skill delta (short)
   Called from CVOGReaction_CompleteObjective on both advance and final branches. */

void __thiscall CVOGCharacter_AddSkillPoints(int param_1,short param_2)

{
  int iVar1;
  undefined1 local_138 [28];
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  
  if (*(short *)(param_1 + 0x6ce) < param_2) {
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);
    local_118 = *(undefined4 *)(iVar1 + 0x164 + param_1);
    local_114 = *(undefined4 *)(iVar1 + param_1 + 0x168);
    local_11c = 0x21;
    Client_SendLogicUiPacket(local_138);
  }
  *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x40;
  *(short *)(param_1 + 0x6ce) = param_2;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
