# Annotated low-level: FUN_007ff9c0

| Field | Value |
|---|---|
| Stable ID | `aa_007ff9c0` |
| VA | `0x007ff9c0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007ff9c0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_007ff9c0(undefined4 param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int unaff_ESI;
  int unaff_EDI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b32b5;
  pvStack_c = ExceptionList;
  iVar1 = *(int *)(unaff_ESI + 0x1148);
  ExceptionList = &pvStack_c;
  if (((iVar1 != 0) && (ExceptionList = &pvStack_c, *(int *)(iVar1 + 0x2b0) != 0)) &&
     (ExceptionList = &pvStack_c, *(int **)(unaff_ESI + 0xf38) != (int *)0x0)) {
    ExceptionList = &pvStack_c;
    (**(code **)(**(int **)(unaff_ESI + 0xf38) + 0xb0))(iVar1,param_1);
  }
  if (*(int *)(unaff_ESI + 0x1148) == 0) {
    pvVar2 = operator_new(0x488);
    uStack_4 = 0;
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_007b5dd0(pvVar2,0);
    }
    uStack_4 = 0xffffffff;
    *(int **)(unaff_ESI + 0x1148) = piVar3;
    (**(code **)(*piVar3 + 0x28))("i_g_2d_wnd_screen_cover.xml",pvVar2);
  }
  if (**(int **)(unaff_ESI + 0xf40) != 0) {
    (**(code **)(*(int *)**(int **)(unaff_ESI + 0xf40) + 0xa8))(*(undefined4 *)(unaff_ESI + 0x1148))
    ;
  }
  if (unaff_EDI != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x1148) + 0x154))(0);
    (**(code **)(**(int **)(unaff_ESI + 0x1148) + 0x34c))();
  }
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
