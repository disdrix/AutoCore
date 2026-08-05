# Annotated low-level: FUN_005ec4c0

| Field | Value |
|---|---|
| Stable ID | `aa_005ec4c0` |
| VA | `0x005ec4c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ec4c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_005ec4c0(int *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((char)param_1[2] == '\0') {
    iVar7 = **(int **)(param_3 + 0x10);
    iVar5 = *param_1;
    iVar6 = param_1[1];
  }
  else {
    iVar5 = param_1[1];
    iVar7 = **(int **)(param_3 + 0x10);
    iVar6 = *param_1;
  }
  fVar1 = *(float *)(iVar7 + 4 + iVar6 * 0xc);
  fVar2 = *(float *)(iVar7 + 8 + iVar6 * 0xc);
  fVar3 = *(float *)(iVar7 + 4 + iVar5 * 0xc);
  fVar4 = *(float *)(iVar7 + 8 + iVar5 * 0xc);
  *param_2 = *(float *)(iVar7 + iVar6 * 0xc) - *(float *)(iVar7 + iVar5 * 0xc);
  param_2[1] = fVar1 - fVar3;
  param_2[2] = fVar2 - fVar4;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
