# Annotated low-level: CVOGObjectiveRequirement_Patrol_Action

| Field | Value |
|---|---|
| Stable ID | `aa_0060e120` |
| VA | `0x0060e120` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0060e120`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
float10 __thiscall
CVOGObjectiveRequirement_Patrol_Action(int param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xd0) * *(int *)(param_1 + 0x24);
  if (iVar1 == 0) {
    return (float10)g_flOne;
  }
  param_3 = *(float *)((int)param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4) / (float)iVar1;
  if (g_flOne <= param_3) {
    param_3 = g_flOne;
  }
  return (float10)param_3;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
