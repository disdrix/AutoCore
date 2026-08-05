# Annotated low-level: FUN_007fef20

| Field | Value |
|---|---|
| Stable ID | `aa_007fef20` |
| VA | `0x007fef20` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_007fef20`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall FUN_007fef20(int param_1,int param_2,char param_3,char param_4)

{
  char *pcVar1;
  char cVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int *unaff_EBX;
  int iVar7;
  char *pcVar8;
  int *piVar9;
  char *pcVar10;
  int **ppiStack_1ac;
  int *local_1a8 [31];
  char cStack_129;
  char acStack_128 [2];
  undefined4 auStack_126 [66];
  void *pvStack_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009b1565;
  local_14 = ExceptionList;
  if (0x3a < param_2) {
    return;
  }
  ExceptionList = &local_14;
  FUN_007fbfb0(param_2);
  piVar9 = *(int **)(param_1 + 0x1030 + param_2 * 4);
  local_1a8[0] = piVar9;
  if (piVar9 == (int *)0x0) {
    FUN_007a4480(1,"Attempting to open null dialog %i.",param_2);
    ExceptionList = local_14;
    return;
  }
  cVar2 = (**(code **)(*piVar9 + 0x3d8))();
  if ((cVar2 != '\0') && (param_3 == '\0')) {
    FUN_007fca10();
    if (*(int *)(param_1 + 0xf38) == 0) {
      ExceptionList = local_14;
      return;
    }
    local_1a8[0] = (int *)(param_1 + 0x1030);
    iVar7 = 0;
    while ((((iVar7 == 0x16 || (piVar9 = (int *)*local_1a8[0], piVar9 == (int *)0x0)) ||
            (cVar2 = (**(code **)(*piVar9 + 0x3d8))(), cVar2 == '\0')) || (piVar9[0x140] != 1))) {
      local_1a8[0] = local_1a8[0] + 1;
      iVar7 = iVar7 + 1;
      if (0x39 < iVar7) {
        (**(code **)(**(int **)(param_1 + 0xf38) + 0x3c4))
                  (*(undefined1 *)((int)*(int **)(param_1 + 0xf38) + 0x493));
        ExceptionList = pvStack_18;
        return;
      }
    }
    ExceptionList = local_14;
    return;
  }
  cVar2 = (**(code **)(*piVar9 + 0x3d8))();
  if (cVar2 != '\0') {
    ExceptionList = local_14;
    return;
  }
  if ((((param_2 != 0x29) && (piVar9[0x140] == 1)) &&
      ((*(int *)(param_1 + 0xe98) != 0 &&
       ((iVar7 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250), iVar7 != 0 &&
        (cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0x194))(),
        cVar2 != '\0')))))) && (param_4 == '\0')) {
    ExceptionList = local_14;
    return;
  }
  if ((((*(int *)(param_1 + 0x1084) != 0) &&
       (cVar2 = (**(code **)(**(int **)(param_1 + 0x1084) + 0x3d8))(), cVar2 != '\0')) &&
      (piVar9[0x13f] == *(int *)(*(int *)(param_1 + 0x1084) + 0x4fc))) &&
     (piVar9[0x140] == *(int *)(*(int *)(param_1 + 0x1084) + 0x500))) {
    FUN_007fca10();
    FUN_007fef20(0x1d,1,0);
  }
  if (((param_2 == 0x16) || (param_2 == 0x22)) &&
     (*(char *)(*(int *)(param_1 + 0xe04) + 0xf6) == '\x01')) {
    ExceptionList = local_14;
    return;
  }
  if ((param_2 == 0x34) && (*(int *)(*(int *)(param_1 + 0xe98) + 0xd6c) != 1)) {
    FUN_007fca10();
  }
  if ((DAT_00afa140 == '\0') && (piVar9[0x13f] != 0)) {
    FUN_007fcaf0(param_1,piVar9[0x140]);
  }
  (**(code **)(*(int *)**(undefined4 **)(param_1 + 0xf40) + 0xa8))(piVar9);
  (**(code **)(*piVar9 + 0x174))(param_1 + 0xf48 + param_2 * 4);
  (**(code **)(*piVar9 + 0x43c))();
  cVar2 = (**(code **)(*piVar9 + 0x3d8))();
  if (cVar2 == '\0') goto LAB_007ff341;
  cVar2 = (**(code **)(*piVar9 + 0xd0))();
  if (cVar2 == '\0') {
    (**(code **)(*piVar9 + 0xcc))(1);
  }
  if (param_2 == 0x15) {
    iVar7 = *(int *)(param_1 + 0xe04);
    if ((iVar7 != 0) && (*(int *)(iVar7 + 0xe4f8) != 0)) {
      FUN_00402d50(*(int *)(iVar7 + 0xe4f8) + 0x124);
      local_14 = (void *)0x0;
      FUN_00899710();
LAB_007ff1ce:
      local_14 = (void *)0xffffffff;
      if (ppiStack_1ac != local_1a8) {
        free(ppiStack_1ac);
      }
    }
  }
  else if (param_2 == 0x1d) {
    iVar7 = *(int *)(param_1 + 0xe04);
    if ((iVar7 != 0) && (*(int *)(iVar7 + 0xe4f8) != 0)) {
      FUN_00402d50(*(int *)(iVar7 + 0xe4f8) + 0x124);
      local_14 = (void *)0x1;
      if (piVar9[0x146] != 0) {
        FUN_00857ee0(piVar9[0x146]);
      }
      goto LAB_007ff1ce;
    }
  }
  else if (((param_2 == 0x1e) && (iVar7 = *(int *)(param_1 + 0xe04), iVar7 != 0)) &&
          (*(int *)(iVar7 + 0xe4f8) != 0)) {
    acStack_128[0] = '\0';
    acStack_128[1] = '\0';
    puVar3 = auStack_126;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *(undefined2 *)puVar3 = 0;
    puVar3 = (undefined4 *)FUN_00402d50(*(int *)(iVar7 + 0xe4f8) + 0x124);
    local_14 = (void *)0x2;
    pcVar1 = (char *)*puVar3;
    pcVar4 = pcVar1;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    pcVar10 = &cStack_129;
    do {
      pcVar8 = pcVar10 + 1;
      pcVar10 = pcVar10 + 1;
    } while (*pcVar8 != '\0');
    pcVar8 = pcVar1;
    for (uVar6 = (uint)((int)pcVar4 - (int)pcVar1) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar6 = (int)pcVar4 - (int)pcVar1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar10 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar10 = pcVar10 + 1;
    }
    local_14 = (void *)0xffffffff;
    if (ppiStack_1ac != local_1a8) {
      free(ppiStack_1ac);
    }
    piVar9 = unaff_EBX;
    if (unaff_EBX[0x14e] != 0) {
      FUN_00857ee0(unaff_EBX[0x14e]);
    }
  }
  iVar7 = *(int *)(param_1 + 0x10b0);
  if ((iVar7 != 0) && (*(int *)(iVar7 + 0x664) != 0)) {
    (**(code **)(**(int **)(iVar7 + 0x664) + 0x47c))();
  }
LAB_007ff341:
  if ((*(int *)(param_1 + 0x1138) == 0) ||
     (cVar2 = (**(code **)(**(int **)(param_1 + 0x1138) + 0x3d8))(), cVar2 == '\0')) {
    (**(code **)(*(int *)**(undefined4 **)(param_1 + 0xf40) + 0x3bc))(piVar9);
  }
  if (*(int *)(param_1 + 0xf38) != 0) {
    (**(code **)(**(int **)(param_1 + 0xf38) + 0x3c4))(1);
  }
  FUN_0092f000();
  ExceptionList = pvStack_1c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
