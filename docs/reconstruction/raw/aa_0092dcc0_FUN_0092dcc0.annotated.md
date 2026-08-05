# Annotated low-level: FUN_0092dcc0

| Field | Value |
|---|---|
| Stable ID | `aa_0092dcc0` |
| VA | `0x0092dcc0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0092dcc0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0092dcc0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char unaff_BL;
  int iVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar2 = param_1;
  *(char *)(param_1 + 0xa0e) = unaff_BL;
  iVar4 = 0;
  do {
    if (iVar4 == 0) {
      piVar1 = *(int **)(iVar2 + 0xc78);
      if (piVar1 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 0x48))();
LAB_0092dcfa:
        if ((iVar3 != 0) && ((*(byte *)(iVar3 + 0xb4) & 0xc) == 0)) {
          FUN_0059e290(&uStack_4,&uStack_8,&param_1,&uStack_c);
          if (unaff_BL == '\x01') {
            param_1 = 10000;
            uStack_c = 10000;
          }
          else if (unaff_BL == '\x02') {
            param_1 = 5000;
            uStack_c = 5000;
          }
          else {
            param_1 = 20000;
            uStack_c = 20000;
          }
          FUN_00426120(uStack_4,uStack_8,param_1,uStack_c);
        }
      }
    }
    else {
      piVar1 = *(int **)(iVar2 + 0xc7c);
      if (piVar1 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 0x48))();
        goto LAB_0092dcfa;
      }
    }
    iVar4 = iVar4 + 1;
    if (1 < iVar4) {
      return;
    }
  } while( true );
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
