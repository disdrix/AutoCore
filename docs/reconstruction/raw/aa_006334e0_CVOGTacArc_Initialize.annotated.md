# Annotated low-level: CVOGTacArc_Initialize

| Field | Value |
|---|---|
| Stable ID | `aa_006334e0` |
| VA | `0x006334e0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006334e0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall CVOGTacArc_Initialize(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float local_18 [3];
  float local_c [3];
  
  if (param_2 == 0) {
    return -1;
  }
  *(int *)(param_1 + 0x20) = param_2;
  CVOGTacArc_SetStateColor(param_3);
  iVar1 = CVOGTacArc_InitializeMesh();
  if (-1 < iVar1) {
    if (*(int **)(param_1 + 0x18) != (int *)0x0) {
      local_18[0] = *(float *)(*(int *)(param_1 + 0x20) + 0xe8);
      local_c[0] = 0.0 - local_18[0];
      pfVar3 = local_18;
      local_c[2] = 0.0 - local_18[0];
      pfVar2 = local_c;
      local_18[1] = 0.0;
      local_c[1] = 0.0;
      local_18[2] = local_18[0];
      (**(code **)(**(int **)(param_1 + 0x18) + 0x4c))(pfVar2,pfVar3);
      FUN_0074b8f0(pfVar2,pfVar3);
    }
    iVar1 = CVOGTacArc_UpdateMesh(0);
  }
  return iVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
