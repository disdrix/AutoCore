# Raw capture: FUN_004fd2b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fd2b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004fd2b0` |
| **Canonical name** | `FUN_004fd2b0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_004fd2b0(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  puVar3 = param_2;
  uStack_4 = 0xffffffff;
  puStack_8 = &DAT_009a2d4f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CreateSimpleObject_SerializeVariant2(param_2,param_3,param_4);
  if (puVar3 == (undefined4 *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  *puVar3 = 0x201d;
  puVar3[0x41] = *(undefined4 *)(param_1 + -0x4c8);
  puVar3[0x42] = *(undefined4 *)(param_1 + -0x4c4);
  strncpy((char *)(puVar3 + 0x355),(char *)(param_1 + -0x4c0),0x20);
  uVar2 = param_3;
  puVar3[0x352] = *(undefined4 *)(param_1 + -0x428);
  puVar3[0x353] = *(undefined4 *)(param_1 + -0x424);
  puVar3[0x354] = *(undefined4 *)(param_1 + -0x420);
  *(undefined2 *)(puVar3 + 0x43) = *(undefined2 *)(param_1 + -0x498);
  puVar3[0x44] = *(undefined4 *)(param_1 + -0x494);
  puVar3[0x45] = *(undefined4 *)(param_1 + -0x490);
  *(undefined2 *)(puVar3 + 0x46) = *(undefined2 *)(param_1 + -0x48c);
  puVar3[0x47] = *(undefined4 *)(param_1 + -0x488);
  puVar3[0x48] = *(undefined4 *)(param_1 + -0x484);
  puVar3[0x49] = *(undefined4 *)(param_1 + -0x480);
  puVar3[0x4a] = *(undefined4 *)(param_1 + -0x47c);
  puVar3[0x4b] = *(undefined4 *)(param_1 + -0x478);
  *(undefined2 *)((int)puVar3 + 0x11a) = *(undefined2 *)(param_1 + -0x48a);
  puVar3[0x4c] = *(undefined4 *)(param_1 + -0x474);
  puVar3[0x4d] = *(undefined4 *)(param_1 + -0x470);
  puVar3[0x4e] = *(undefined4 *)(param_1 + -0x46c);
  puVar3[0x4f] = *(undefined4 *)(param_1 + -0x468);
  puVar3[0x50] = *(undefined4 *)(param_1 + -0x464);
  puVar3[0x51] = *(undefined4 *)(param_1 + -0x460);
  puVar3[0x52] = *(undefined4 *)(param_1 + -0x45c);
  *(undefined1 *)((int)puVar3 + 0x153) = *(undefined1 *)(param_1 + -1000);
  *(undefined1 *)((int)puVar3 + 0x151) = *(undefined1 *)(param_1 + -0x3c4);
  *(undefined1 *)((int)puVar3 + 0x152) = *(undefined1 *)(param_1 + -0x55c);
  puVar3[0x34a] = *(undefined4 *)(*(int *)(param_1 + -0x578) + 0x40);
  puVar3[0x34b] = *(undefined4 *)(*(int *)(param_1 + -0x578) + 0x48);
  *(undefined1 *)(puVar3 + 0x34d) = *(undefined1 *)(*(int *)(param_1 + -0x578) + 0x51);
  puVar3[0x34c] = *(undefined4 *)(*(int *)(param_1 + -0x578) + 0x4c);
  cVar1 = *(char *)(*(int *)(param_1 + -0x578) + 0x50);
  *(undefined1 *)(puVar3 + 0x28) = 0;
  *(bool *)((int)puVar3 + 0xd35) = cVar1 != '\0';
  puVar3[0x34e] = *(undefined4 *)(param_1 + -0x524);
  if (*(int *)(param_1 + -0x3f0) == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = *(undefined4 *)
             (*(int *)(*(int *)(*(int *)(param_1 + -0x3f0) + 4) + 4) + 0x164 +
             *(int *)(param_1 + -0x3f0));
  }
  puVar3[0x38] = uVar4;
  puVar3[0x53] = *(undefined4 *)(param_1 + -0x53c);
  puVar3[0x350] = 0xffffffff;
  puVar3[0x351] = 0xffffffff;
  puVar8 = (undefined4 *)(param_1 + -0x3e4);
  puVar9 = puVar3 + 0x39;
  for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  iVar7 = *(int *)(param_1 + -0x408);
  if (iVar7 == 0) {
    puVar3[0xc3] = 0xffffffff;
  }
  else {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0xbc))
              (puVar3 + 0xc2,param_3,0);
    *(undefined1 *)(puVar3 + 0xea) = 1;
  }
  iVar7 = *(int *)(param_1 + -0x404);
  if (iVar7 == 0) {
    puVar3[0x57] = 0xffffffff;
  }
  else {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0xbc))
              (puVar3 + 0x56,uVar2,0);
    *(undefined1 *)(puVar3 + 0x7e) = 1;
  }
  iVar7 = *(int *)(param_1 + -0x400);
  if (iVar7 == 0) {
    puVar3[0x8d] = 0xffffffff;
  }
  else {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0xbc))
              (puVar3 + 0x8c,uVar2,0);
    *(undefined1 *)(puVar3 + 0xb4) = 1;
  }
  iVar7 = *(int *)(param_1 + -0x418);
  if (iVar7 == 0) {
    puVar3[0x117] = 0xffffffff;
  }
  else {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0xbc))
              (puVar3 + 0x116,uVar2,0);
    *(undefined1 *)(puVar3 + 0x13e) = 1;
  }
  if (*(int *)(param_1 + -0x41c) == 0) {
    puVar3[0x16d] = 0xffffffff;
  }
  else {
    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x41c) + 4) + 4) + 4 +
                         *(int *)(param_1 + -0x41c)) + 0xbc))(puVar3 + 0x16c,uVar2,0);
    *(undefined1 *)(puVar3 + 0x194) = 1;
  }
  param_3 = 0;
  puVar8 = puVar3 + 0x24c;
  do {
    iVar7 = *(int *)(param_3 + *(int *)(param_1 + -0x410));
    if (iVar7 == 0) {
      puVar8[-0x27] = 0xffffffff;
    }
    else {
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0xbc))
                (puVar8 + -0x28,uVar2,0);
      *(undefined1 *)puVar8 = 1;
    }
    param_3 = param_3 + 4;
    puVar8 = puVar8 + 0x62;
  } while (param_3 < 0xc);
  iVar7 = *(int *)(param_1 + -0x40c);
  if (iVar7 == 0) {
    puVar3[0x1c3] = 0xffffffff;
  }
  else {
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 4) + 4 + iVar7) + 0xbc))
              (puVar3 + 0x1c2,uVar2,0);
    *(undefined1 *)(puVar3 + 0x1ea) = 1;
  }
  iVar7 = *(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c0 + param_1);
  if (iVar7 == 0) {
    puVar3[0x36] = 0xffffffff;
    puVar3[0x37] = 0xffffffff;
  }
  else {
    uVar2 = *(undefined4 *)(iVar7 + 0x164);
    puVar3[0x36] = *(undefined4 *)(iVar7 + 0x160);
    puVar3[0x37] = uVar2;
  }
  *(bool *)(puVar3 + 0x54) = *(int *)(param_1 + -0x3f8) != 0;
  if ((char)param_4 == '\0') {
    ExceptionList = local_c;
    return 0xd78;
  }
  *puVar3 = 0x201e;
  *(undefined2 *)((int)puVar3 + 0xd7a) = 0;
  if (*(int *)(param_1 + -0x3c0) == 0) {
    *(undefined2 *)(puVar3 + 0x35e) = 0;
  }
  else {
    *(short *)(puVar3 + 0x35e) = (short)*(undefined4 *)(*(int *)(param_1 + -0x3c0) + 0x14);
  }
  if ((*(int *)(param_1 + -0x3c0) == 0) ||
     ((iVar7 = *(int *)(*(int *)(*(int *)(param_1 + -0x66c) + 4) + -0x5c8 + param_1), iVar7 != 0 &&
      (*(char *)(iVar7 + 0xf6) != '\0')))) {
    ExceptionList = local_c;
    return (uint)*(ushort *)((int)puVar3 + 0xd7a) * 8 + 0xd80;
  }
  piVar5 = (int *)FUN_0040fb90();
  iVar10 = 0;
  uStack_4 = 0;
  param_2 = (undefined4 *)0x0;
  FUN_004294f0();
  iVar7 = FUN_004022a0(&param_2,&param_3);
  if (iVar7 == 0) {
    param_4 = puVar3 + 0x360;
    do {
      if (0x1ff < iVar10) break;
      if (*(int *)(*(int *)(param_3 + 0xa8) + 0x38) == 4) {
        iVar7 = FUN_00418700(piVar5,piVar5[1],&param_3);
        FUN_00404840(1);
        piVar5[1] = iVar7;
        **(int **)(iVar7 + 4) = iVar7;
      }
      else {
        iVar7 = *(int *)(*(int *)(param_3 + 0xa8) + 0x3c);
        if ((*(char *)(iVar7 + 0x406) != '\0') && (*(char *)(iVar7 + 0x407) != '\0')) {
          *param_4 = *(undefined4 *)(param_3 + 0x160);
          param_4[1] = *(undefined4 *)(param_3 + 0x164);
          iVar10 = iVar10 + 1;
          param_4 = param_4 + 2;
        }
      }
      iVar7 = FUN_004022a0(&param_2,&param_3);
    } while (iVar7 == 0);
  }
  iVar7 = *(int *)(param_1 + -0x3c0);
  if (*(char *)(iVar7 + 0x54) != '\0') {
    *(undefined1 *)(iVar7 + 0x54) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar7 + 0x30));
  }
  piVar6 = (int *)*piVar5;
  if (piVar6 != piVar5) {
    puVar8 = puVar3 + iVar10 * 2 + 0x360;
    do {
      if (0x1ff < iVar10) break;
      iVar7 = piVar6[2];
      *puVar8 = *(undefined4 *)(iVar7 + 0x160);
      puVar8[1] = *(undefined4 *)(iVar7 + 0x164);
      piVar6 = (int *)*piVar6;
      iVar10 = iVar10 + 1;
      puVar8 = puVar8 + 2;
    } while (piVar6 != piVar5);
  }
  *(short *)((int)puVar3 + 0xd7a) = (short)iVar10;
  piVar6 = (int *)*piVar5;
  *piVar5 = (int)piVar5;
  piVar5[1] = (int)piVar5;
  if (piVar6 == piVar5) {
                    /* WARNING: Subroutine does not return */
    operator_delete(piVar5);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(piVar6);
}
```
