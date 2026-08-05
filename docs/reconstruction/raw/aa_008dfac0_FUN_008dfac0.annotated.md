# Annotated low-level: FUN_008dfac0

| Field | Value |
|---|---|
| Stable ID | `aa_008dfac0` |
| VA | `0x008dfac0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008dfac0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_008dfac0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int unaff_ESI;
  int iStack_6c;
  undefined1 *puStack_68;
  undefined4 uStack_64;
  undefined1 *puStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  char *pcStack_54;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  int iStack_30;
  int *piStack_2c;
  undefined4 uStack_20;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b3a0f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar2 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar2 != '\0') {
    iVar1 = param_1[0x146];
    iStack_30 = ((param_3 * 2 + 1) * param_1[0x147]) / 2 + param_1[0x145];
    iVar8 = param_1[0x144];
    pcStack_54 = (char *)0x8dfb32;
    pcStack_54 = operator_new(0x488);
    uStack_4 = 0;
    if (pcStack_54 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      iStack_58 = 0x8dfb4d;
      piVar3 = (int *)FUN_007b5dd0();
    }
    uStack_4 = 0xffffffff;
    pcStack_54 = (char *)0x8dfb6a;
    (**(code **)(*param_1 + 0xa8))();
    pcStack_54 = "i_d_dt_2d_wnd_tree_cap.xml";
    iStack_58 = 0x8dfb76;
    (**(code **)(*piVar3 + 0x28))();
    iStack_58 = 0;
    uStack_5c = 1;
    puStack_60 = auStack_34;
    uStack_64 = 0x8dfb89;
    iVar4 = (**(code **)(*piVar3 + 0x120))();
    uStack_64 = 1;
    puStack_68 = auStack_38;
    iStack_6c = 0x8dfb9c;
    iVar5 = (**(code **)(*piVar3 + 0x140))();
    iVar5 = *(int *)(iVar5 + 4);
    iVar4 = *(int *)(iVar4 + 4);
    iStack_6c = 1;
    uStack_20 = (**(code **)(*piVar3 + 0x140))(auStack_38);
    piVar6 = (int *)(**(code **)(*piVar3 + 0x120))(auStack_38,1,0);
    iStack_6c = (*piVar6 - *piStack_2c / 2) + ((param_2 * 2 + 1) * iVar1) / 2 + iVar8;
    puStack_68 = (undefined1 *)((iVar4 - iVar5 / 2) + unaff_ESI);
    (**(code **)(*piVar3 + 0x110))(&iStack_6c);
    iVar1 = *piVar3;
    uVar7 = FUN_008df5a0();
    (**(code **)(iVar1 + 0x15c))(0,uVar7);
    iVar1 = param_1[0x1af];
    pcStack_54 = *(char **)(iVar1 + 4);
    uStack_5c = 0x8dfc34;
    iStack_58 = iVar1;
    iVar8 = FUN_00418700();
    FUN_00418790();
    *(int *)(iVar1 + 4) = iVar8;
    **(int **)(iVar8 + 4) = iVar8;
  }
  ExceptionList = pvStack_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
