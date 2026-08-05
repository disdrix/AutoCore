# Annotated low-level: FUN_0055aec0

| Field | Value |
|---|---|
| Stable ID | `aa_0055aec0` |
| VA | `0x0055aec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0055aec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0055aec0(char *param_1,int param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uStack_150;
  undefined1 auStack_14c [12];
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  undefined4 uStack_129;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0xffffffff;
  puStack_18 = &LAB_009a48d6;
  local_1c = ExceptionList;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2[(int)&uStack_129 + (1 - (int)param_1)] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  puVar8 = &uStack_129;
  do {
    pcVar2 = (char *)((int)puVar8 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  } while (*pcVar2 != '\0');
  iVar4 = (int)&uStack_129 + 1;
  *puVar8 = DAT_009cb318;
  ExceptionList = &local_1c;
  FUN_007b6a20(iVar4);
  piVar3 = (int *)FUN_007b7420(iVar4);
  if (piVar3 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar3 + 0x1c))();
    if (iVar4 == 0) {
      (**(code **)*piVar3)(1);
      FUN_007a4480(1,"Rigid body of object \'%s\' is zero length",param_1);
    }
    else {
      fStack_140 = g_flOne;
      fStack_13c = g_flOne;
      fStack_138 = g_flOne;
      fStack_134 = g_flOne;
      iVar4 = piVar3[1];
      uVar5 = (**(code **)(*piVar3 + 0x1c))();
      FUN_005f3120(iVar4,uVar5);
      uStack_14 = 0;
      uVar5 = 0x55afa1;
      piVar6 = (int *)FUN_005f3740(auStack_14c,&fStack_140);
      uVar10 = 1;
      uVar9 = 0x55afae;
      (**(code **)*piVar3)(1);
      if ((piVar6 != (int *)0x0) && (0 < piVar6[1])) {
        FUN_0055c7a0(piVar6[1],uVar5,uVar9,uVar10);
        uStack_150 = 0;
        if (piVar6[1] != 0) {
          iVar7 = 0;
          iVar4 = 0;
          do {
            *(undefined4 *)(iVar4 + *(int *)(param_2 + 4)) = *(undefined4 *)(iVar7 + *piVar6);
            *(undefined4 *)(iVar4 + 4 + *(int *)(param_2 + 4)) =
                 *(undefined4 *)(*piVar6 + 4 + iVar7);
            *(undefined4 *)(iVar4 + 8 + *(int *)(param_2 + 4)) =
                 *(undefined4 *)(*piVar6 + 8 + iVar7);
            uStack_150 = uStack_150 + 1;
            iVar4 = iVar4 + 0xc;
            iVar7 = iVar7 + 0x10;
          } while (uStack_150 < (uint)piVar6[1]);
        }
        FUN_004367f0(piVar6[4] * 3,0);
        uStack_150 = 0;
        if (piVar6[4] != 0) {
          iVar7 = 0;
          iVar4 = 0;
          do {
            *(undefined4 *)(iVar4 + *(int *)(param_3 + 4)) = *(undefined4 *)(iVar7 + piVar6[3]);
            *(undefined4 *)(iVar4 + 4 + *(int *)(param_3 + 4)) =
                 *(undefined4 *)(piVar6[3] + 4 + iVar7);
            *(undefined4 *)(iVar4 + 8 + *(int *)(param_3 + 4)) =
                 *(undefined4 *)(piVar6[3] + 8 + iVar7);
            uStack_150 = uStack_150 + 1;
            iVar4 = iVar4 + 0xc;
            iVar7 = iVar7 + 0xc;
          } while (uStack_150 < (uint)piVar6[4]);
        }
        uStack_14 = 0xffffffff;
        FUN_005f3160();
        ExceptionList = local_1c;
        return 1;
      }
      uStack_14 = 0xffffffff;
      FUN_005f3160();
    }
  }
  ExceptionList = local_1c;
  return 0;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
