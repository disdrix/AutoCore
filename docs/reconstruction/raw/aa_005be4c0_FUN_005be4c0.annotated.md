# Annotated low-level: FUN_005be4c0

| Field | Value |
|---|---|
| Stable ID | `aa_005be4c0` |
| VA | `0x005be4c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005be4c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_005be4c0(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *local_4;
  
  if (((int *)*param_1 == (int *)0x0) || (*(int *)*param_1 == 0)) {
    local_4 = param_1;
    piVar2 = _aligned_malloc(58000,0x10);
    iVar4 = param_1[2];
    if ((iVar4 == 0) || ((uint)(param_1[4] - iVar4 >> 2) <= (uint)(param_1[3] - iVar4 >> 2))) {
      local_4 = piVar2;
      FUN_004073a0(param_1[3],1,&local_4);
    }
    else {
      puVar1 = (undefined4 *)param_1[3];
      *puVar1 = piVar2;
      param_1[3] = (int)(puVar1 + 1);
    }
    *param_1 = (int)piVar2;
    iVar4 = 99;
    piVar3 = piVar2;
    do {
      iVar4 = iVar4 + -1;
      *piVar3 = (int)(piVar3 + 0x91);
      piVar3 = piVar3 + 0x91;
    } while (iVar4 != 0);
    piVar2[0x3813] = 0;
  }
  *param_1 = *(int *)*param_1;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
