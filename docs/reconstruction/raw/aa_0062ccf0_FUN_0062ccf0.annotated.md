# Annotated low-level: FUN_0062ccf0

| Field | Value |
|---|---|
| Stable ID | `aa_0062ccf0` |
| VA | `0x0062ccf0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0062ccf0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_0062ccf0(int *param_1,int param_2,int param_3,int *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  
  puVar5 = (uint *)*param_1;
  puVar1 = puVar5 + param_1[1] * 2;
  iVar6 = 0;
  puVar3 = puVar5;
  for (; puVar5 < puVar1; puVar5 = puVar5 + 2) {
    uVar2 = *(uint *)(*param_4 + puVar5[1] * 4);
    if (-1 < (int)uVar2) {
      *puVar3 = *puVar5;
      puVar3[1] = puVar5[1];
      puVar3[1] = uVar2;
      *(int *)(*(int *)(&DAT_00af4e30 + ((*puVar3 & 1) + param_3 * 2) * 4) + uVar2 * 0x1c + param_2)
           = iVar6;
      puVar3 = puVar3 + 2;
      iVar6 = iVar6 + 1;
    }
  }
  if ((int)(param_1[2] & 0x7fffffffU) < iVar6) {
    iVar4 = (param_1[2] & 0x7fffffffU) * 2;
    if (iVar4 <= iVar6) {
      iVar4 = iVar6;
    }
    FUN_005b3300(param_1,iVar4,8);
  }
  param_1[1] = iVar6;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
