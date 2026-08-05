# Annotated low-level: thunk_FUN_005fa9b0

| Field | Value |
|---|---|
| Stable ID | `aa_005fb690` |
| VA | `0x005fb690` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005fb690`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall thunk_FUN_005fa9b0(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iStack_dc;
  
  *(undefined4 *)(param_1 + 8) = *param_2;
  *(undefined4 *)(param_1 + 0xc) = param_2[5];
  uVar2 = FUN_005fa6e0();
  iStack_dc = *(int *)(param_1 + 0x84);
  iVar4 = *(int *)(param_1 + 0xc);
  if (iStack_dc < iVar4) {
    uVar3 = *(uint *)(param_1 + 0x88) & 0x7fffffff;
    if ((int)uVar3 < iVar4) {
      iVar7 = uVar3 * 2;
      if (iVar7 <= iVar4) {
        iVar7 = iVar4;
      }
      FUN_005b3300(param_1 + 0x80,iVar7,0xc0);
    }
    if (iStack_dc < iVar4) {
      iStack_dc = iVar4 - iStack_dc;
      do {
        FUN_005fa830(uVar2);
        iStack_dc = iStack_dc + -1;
      } while (iStack_dc != 0);
    }
  }
  *(int *)(param_1 + 0x84) = iVar4;
  uVar3 = *(uint *)(param_1 + 0x18) & 0x7fffffff;
  if ((int)uVar3 < (int)param_2[5]) {
    if (-1 < (int)*(uint *)(param_1 + 0x18)) {
      (**(code **)(*DAT_00b05060 + 0x14))(*(undefined4 *)(param_1 + 0x10),uVar3 * 4,0x12);
    }
    uVar2 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[5] * 4,0x12);
    *(undefined4 *)(param_1 + 0x10) = uVar2;
    *(undefined4 *)(param_1 + 0x18) = param_2[5];
  }
  iVar7 = *(int *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x14) = param_2[5];
  iVar10 = param_2[5];
  iVar1 = param_2[4];
  iVar4 = 0;
  if (3 < iVar10) {
    puVar6 = (undefined4 *)(iVar1 + 0xc);
    puVar5 = (undefined4 *)(iVar7 + 4);
    iVar9 = (iVar10 - 4U >> 2) + 1;
    iVar4 = iVar9 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(undefined4 *)((iVar1 - iVar7) + (int)puVar5);
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  if (iVar4 < iVar10) {
    puVar6 = (undefined4 *)(iVar7 + iVar4 * 4);
    iVar10 = iVar10 - iVar4;
    do {
      *puVar6 = *(undefined4 *)((int)puVar6 + (iVar1 - iVar7));
      puVar6 = puVar6 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  uVar3 = *(uint *)(param_1 + 0x24) & 0x7fffffff;
  if ((int)uVar3 < (int)param_2[8]) {
    if (-1 < (int)*(uint *)(param_1 + 0x24)) {
      (**(code **)(*DAT_00b05060 + 0x14))(*(undefined4 *)(param_1 + 0x1c),uVar3 * 4,0x12);
    }
    uVar2 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[8] * 4,0x12);
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
    *(undefined4 *)(param_1 + 0x24) = param_2[8];
  }
  iVar7 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = param_2[8];
  iVar10 = param_2[8];
  iVar1 = param_2[7];
  iVar4 = 0;
  if (3 < iVar10) {
    puVar6 = (undefined4 *)(iVar1 + 0xc);
    puVar5 = (undefined4 *)(iVar7 + 4);
    iVar9 = (iVar10 - 4U >> 2) + 1;
    iVar4 = iVar9 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(undefined4 *)((iVar1 - iVar7) + (int)puVar5);
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  if (iVar4 < iVar10) {
    puVar6 = (undefined4 *)(iVar7 + iVar4 * 4);
    iVar10 = iVar10 - iVar4;
    do {
      *puVar6 = *(undefined4 *)((int)puVar6 + (iVar1 - iVar7));
      puVar6 = puVar6 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  uVar3 = *(uint *)(param_1 + 0x30) & 0x7fffffff;
  if ((int)uVar3 < (int)param_2[0xb]) {
    if (-1 < (int)*(uint *)(param_1 + 0x30)) {
      (**(code **)(*DAT_00b05060 + 0x14))(*(undefined4 *)(param_1 + 0x28),uVar3 * 4,0x12);
    }
    uVar2 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[0xb] * 4,0x12);
    *(undefined4 *)(param_1 + 0x28) = uVar2;
    *(undefined4 *)(param_1 + 0x30) = param_2[0xb];
  }
  iVar7 = *(int *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x2c) = param_2[0xb];
  iVar10 = param_2[0xb];
  iVar1 = param_2[10];
  iVar4 = 0;
  if (3 < iVar10) {
    puVar6 = (undefined4 *)(iVar1 + 0xc);
    puVar5 = (undefined4 *)(iVar7 + 4);
    iVar9 = (iVar10 - 4U >> 2) + 1;
    iVar4 = iVar9 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(undefined4 *)((iVar1 - iVar7) + (int)puVar5);
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  if (iVar4 < iVar10) {
    puVar6 = (undefined4 *)(iVar7 + iVar4 * 4);
    iVar10 = iVar10 - iVar4;
    do {
      *puVar6 = *(undefined4 *)((int)puVar6 + (iVar1 - iVar7));
      puVar6 = puVar6 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  uVar3 = *(uint *)(param_1 + 0x3c) & 0x7fffffff;
  if ((int)uVar3 < (int)param_2[0xe]) {
    if (-1 < (int)*(uint *)(param_1 + 0x3c)) {
      (**(code **)(*DAT_00b05060 + 0x14))(*(undefined4 *)(param_1 + 0x34),uVar3 * 4,0x12);
    }
    uVar2 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[0xe] * 4,0x12);
    *(undefined4 *)(param_1 + 0x34) = uVar2;
    *(undefined4 *)(param_1 + 0x3c) = param_2[0xe];
  }
  iVar7 = *(int *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x38) = param_2[0xe];
  iVar10 = param_2[0xe];
  iVar1 = param_2[0xd];
  iVar4 = 0;
  if (3 < iVar10) {
    puVar6 = (undefined4 *)(iVar1 + 0xc);
    puVar5 = (undefined4 *)(iVar7 + 4);
    iVar9 = (iVar10 - 4U >> 2) + 1;
    iVar4 = iVar9 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(undefined4 *)((iVar1 - iVar7) + (int)puVar5);
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  if (iVar4 < iVar10) {
    puVar6 = (undefined4 *)(iVar7 + iVar4 * 4);
    iVar10 = iVar10 - iVar4;
    do {
      *puVar6 = *(undefined4 *)((iVar1 - iVar7) + (int)puVar6);
      puVar6 = puVar6 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  uVar3 = *(uint *)(param_1 + 0x48) & 0x7fffffff;
  if ((int)uVar3 < (int)param_2[0x11]) {
    if (-1 < (int)*(uint *)(param_1 + 0x48)) {
      (**(code **)(*DAT_00b05060 + 0x14))(*(undefined4 *)(param_1 + 0x40),uVar3 * 4,0x12);
    }
    uVar2 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[0x11] * 4,0x12);
    *(undefined4 *)(param_1 + 0x40) = uVar2;
    *(undefined4 *)(param_1 + 0x48) = param_2[0x11];
  }
  iVar7 = *(int *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x44) = param_2[0x11];
  iVar10 = param_2[0x11];
  iVar1 = param_2[0x10];
  iVar4 = 0;
  if (3 < iVar10) {
    puVar6 = (undefined4 *)(iVar1 + 0xc);
    puVar5 = (undefined4 *)(iVar7 + 4);
    iVar9 = (iVar10 - 4U >> 2) + 1;
    iVar4 = iVar9 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(undefined4 *)((iVar1 - iVar7) + (int)puVar5);
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  if (iVar4 < iVar10) {
    puVar6 = (undefined4 *)(iVar7 + iVar4 * 4);
    iVar10 = iVar10 - iVar4;
    do {
      *puVar6 = *(undefined4 *)((int)puVar6 + (iVar1 - iVar7));
      puVar6 = puVar6 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  uVar3 = *(uint *)(param_1 + 0x60) & 0x7fffffff;
  if ((int)uVar3 < (int)param_2[2]) {
    if (-1 < (int)*(uint *)(param_1 + 0x60)) {
      (**(code **)(*DAT_00b05060 + 0x14))(*(undefined4 *)(param_1 + 0x58),uVar3 * 4,0x12);
    }
    uVar2 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[2] * 4,0x12);
    *(undefined4 *)(param_1 + 0x58) = uVar2;
    *(undefined4 *)(param_1 + 0x60) = param_2[2];
  }
  puVar6 = *(undefined4 **)(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x5c) = param_2[2];
  iVar4 = param_2[2];
  if (0 < iVar4) {
    iVar7 = param_2[1] - (int)puVar6;
    do {
      *puVar6 = *(undefined4 *)(iVar7 + (int)puVar6);
      puVar6 = puVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  uVar3 = *(uint *)(param_1 + 0x54) & 0x7fffffff;
  if ((int)uVar3 < (int)param_2[0x14]) {
    if (-1 < (int)*(uint *)(param_1 + 0x54)) {
      (**(code **)(*DAT_00b05060 + 0x14))(*(undefined4 *)(param_1 + 0x4c),uVar3 * 4,0x12);
    }
    uVar2 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[0x14] * 4,0x12);
    *(undefined4 *)(param_1 + 0x4c) = uVar2;
    *(undefined4 *)(param_1 + 0x54) = param_2[0x14];
  }
  iVar7 = *(int *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0x50) = param_2[0x14];
  iVar10 = param_2[0x14];
  iVar1 = param_2[0x13];
  iVar4 = 0;
  if (3 < iVar10) {
    puVar6 = (undefined4 *)(iVar1 + 0xc);
    puVar5 = (undefined4 *)(iVar7 + 4);
    iVar9 = (iVar10 - 4U >> 2) + 1;
    iVar4 = iVar9 * 4;
    do {
      puVar5[-1] = puVar6[-3];
      *puVar5 = *(undefined4 *)((iVar1 - iVar7) + (int)puVar5);
      puVar5[1] = puVar6[-1];
      puVar5[2] = *puVar6;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  if (iVar4 < iVar10) {
    puVar6 = (undefined4 *)(iVar7 + iVar4 * 4);
    iVar10 = iVar10 - iVar4;
    do {
      *puVar6 = *(undefined4 *)((int)puVar6 + (iVar1 - iVar7));
      puVar6 = puVar6 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    iVar7 = 0;
    do {
      *(undefined4 *)(iVar7 + 0x84 + *(int *)(param_1 + 0x80)) =
           *(undefined4 *)(param_2[0x16] + iVar4 * 4);
      iVar4 = iVar4 + 1;
      iVar7 = iVar7 + 0xc0;
    } while (iVar4 < *(int *)(param_1 + 0xc));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x5c)) {
    piVar8 = *(int **)(param_1 + 0x58);
    iVar7 = *(int *)(param_1 + 0x5c);
    iVar4 = 0;
    do {
      if (iVar4 < *piVar8 + 1) {
        iVar4 = *piVar8 + 1;
      }
      piVar8 = piVar8 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if (*(int *)(param_1 + 0x6c) < iVar4) {
    uVar3 = *(uint *)(param_1 + 0x70) & 0x7fffffff;
    if ((int)uVar3 < iVar4) {
      iVar7 = uVar3 * 2;
      if (iVar7 <= iVar4) {
        iVar7 = iVar4;
      }
      FUN_005b3300(param_1 + 0x68,iVar7,4);
    }
    *(int *)(param_1 + 0x6c) = iVar4;
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x6c)) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x68) + iVar4 * 4) = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x6c));
  }
  iVar4 = 0;
  if (*(int *)(param_1 + 0x5c) < 1) {
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x6c);
    return;
  }
  do {
    piVar8 = (int *)(*(int *)(param_1 + 0x68) + *(int *)(*(int *)(param_1 + 0x58) + iVar4 * 4) * 4);
    *piVar8 = *piVar8 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < *(int *)(param_1 + 0x5c));
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x6c);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
