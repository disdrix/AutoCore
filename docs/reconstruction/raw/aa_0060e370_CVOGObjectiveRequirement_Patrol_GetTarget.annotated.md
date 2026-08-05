# Annotated low-level: CVOGObjectiveRequirement_Patrol_GetTarget

| Field | Value |
|---|---|
| Stable ID | `aa_0060e370` |
| VA | `0x0060e370` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0060e370`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall
CVOGObjectiveRequirement_Patrol_GetTarget(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    return 0;
  }
  iVar1 = (int)*(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4);
  if (*(int *)(param_1 + 0x24) * *(int *)(param_1 + 0xd0) <= iVar1) {
    return 0;
  }
  iVar1 = iVar1 % *(int *)(param_1 + 0xd0);
  param_2[2] = *(undefined4 *)(param_1 + 0x30 + iVar1 * 8);
  param_2[3] = *(undefined4 *)(param_1 + 0x34 + iVar1 * 8);
  *(undefined1 *)((int)param_2 + 0xea) = *(undefined1 *)(param_1 + 0x10);
  param_2[0x3b] = *(undefined4 *)(param_1 + 0x14);
  *param_2 = *(undefined4 *)(param_1 + 0x28);
  return 1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
