# Raw capture: FUN_004cac30

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cac30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cac30` |
| **Canonical name** | `FUN_004cac30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004cac30(int param_1)

{
  char cVar1;
  ushort uVar2;
  char *_Memory;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined1 auStack_198 [4];
  char acStack_194 [4];
  undefined1 auStack_190 [256];
  char *local_90;
  char local_8c [128];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a1e07;
  pvStack_c = ExceptionList;
  iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x3c) + 4) + 0x6c + param_1) + 0x3c);
  local_90 = local_8c;
  ExceptionList = &pvStack_c;
  uVar3 = (*(code *)PTR_FUN_00af8c9c)();
  FUN_00403450(iVar6 + 0x10,uVar3);
  _Memory = local_90;
  iVar6 = -(int)local_90;
  pcVar4 = local_90;
  do {
    cVar1 = *pcVar4;
    pcVar4[(int)(acStack_194 + iVar6)] = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (_Memory != local_8c) {
    free(_Memory);
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    piVar7 = (int *)(param_1 + 0x2c);
    iVar6 = 0x13;
    do {
      if (*piVar7 != 0) {
        (**(code **)(**(int **)(param_1 + 0x24) + 0x10))(*piVar7);
        FUN_0074eb20();
      }
      piVar7 = piVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (*(undefined4 **)(param_1 + 0x28) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x28))(1);
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    if (*(undefined4 **)(param_1 + 0x24) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x24))(1);
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  if (*(int *)(param_1 + 8) != 0) {
    auStack_198 = (undefined1  [4])operator_new(0x5c);
    uStack_4 = 0;
    if (auStack_198 == (undefined1  [4])0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_0074d750();
    }
    uStack_4 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x24) = uVar3;
    puVar5 = operator_new(0x14);
    uStack_4 = 1;
    auStack_198 = (undefined1  [4])puVar5;
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_009c7938;
      iVar6 = FUN_0040bfc0();
      puVar5[2] = iVar6;
      *(undefined1 *)(iVar6 + 0x19) = 1;
      *(undefined4 *)(puVar5[2] + 4) = puVar5[2];
      *(undefined4 *)puVar5[2] = puVar5[2];
      *(undefined4 *)(puVar5[2] + 8) = puVar5[2];
      puVar5[3] = 0;
      *puVar5 = &PTR_FUN_009c7948;
      puVar5[4] = 0;
    }
    uStack_4 = 0xffffffff;
    *(undefined4 **)(param_1 + 0x28) = puVar5;
    FUN_0074d420(*(undefined4 *)(param_1 + 8));
    (**(code **)(**(int **)(param_1 + 0x24) + 4))(*(undefined4 *)(param_1 + 0x28),0);
    piVar7 = (int *)(param_1 + 0x2c);
    FUN_004c50c0(0,1,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    if (*piVar7 != 0) {
      iVar6 = CVOGReaction_RandomUnitScalar();
      if (0xfffff < *(int *)(iVar6 + 0xc)) {
        *(undefined4 *)(iVar6 + 0xc) = 0;
      }
      uVar2 = *(ushort *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);
      *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
      FUN_0074e6c0((float)uVar2 * _DAT_009cbf5c + DAT_00a0f698);
    }
    FUN_004c50c0(2,1,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(1,1,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(3,0,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(4,0,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(0x10,0,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(0x11,0,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(5,0,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(6,0,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(7,0,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(8,0,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(9,1,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(10,1,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(0xb,1,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(0xc,1,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(0xd,0,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(0xe,1,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(0xf,0,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    FUN_004c50c0(0x12,0,acStack_194,*(undefined4 *)(param_1 + 0x24),piVar7);
    if (*(int *)(param_1 + 0x244) != 0) {
      auStack_198 = (undefined1  [4])operator_new(0x5c);
      uStack_4 = 2;
      if (auStack_198 == (undefined1  [4])0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_0074d750();
      }
      uStack_4 = 0xffffffff;
      *(undefined4 *)(param_1 + 0x248) = uVar3;
      auStack_198 = (undefined1  [4])operator_new(0x14);
      uStack_4 = 3;
      if (auStack_198 == (undefined1  [4])0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_0040d4f0();
      }
      uStack_4 = 0xffffffff;
      *(undefined4 *)(param_1 + 0x24c) = uVar3;
      FUN_0074d420(*(undefined4 *)(param_1 + 0x244));
      (**(code **)(**(int **)(param_1 + 0x248) + 4))(*(undefined4 *)(param_1 + 0x24c),0);
      puVar5 = (undefined4 *)(auStack_198 + 3);
      do {
        puVar8 = puVar5;
        puVar5 = (undefined4 *)((int)puVar8 + 1);
      } while (*(char *)((int)puVar8 + 1) != '\0');
      uVar3 = *(undefined4 *)(param_1 + 0x248);
      *(undefined4 *)((int)puVar8 + 1) = DAT_009cbf54;
      *(undefined1 *)((int)puVar8 + 5) = DAT_009cbf58;
      iVar6 = param_1 + 0x250;
      FUN_004c50c0(3,0,acStack_194,uVar3,iVar6);
      FUN_004c50c0(4,0,acStack_194,*(undefined4 *)(param_1 + 0x248),iVar6);
      FUN_004c50c0(0x10,0,acStack_194,*(undefined4 *)(param_1 + 0x248),iVar6);
      FUN_004c50c0(0x11,0,acStack_194,*(undefined4 *)(param_1 + 0x248),iVar6);
      FUN_004c50c0(2,1,acStack_194,*(undefined4 *)(param_1 + 0x248),iVar6);
      FUN_004c50c0(1,1,acStack_194,*(undefined4 *)(param_1 + 0x248),iVar6);
      FUN_004c50c0(0,1,acStack_194,*(undefined4 *)(param_1 + 0x248),iVar6);
      FUN_004c50c0(5,0,acStack_194,*(undefined4 *)(param_1 + 0x248),iVar6);
      FUN_004c50c0(6,0,acStack_194,*(undefined4 *)(param_1 + 0x248),iVar6);
      FUN_004c50c0(7,0,acStack_194,*(undefined4 *)(param_1 + 0x248),iVar6);
    }
    iVar6 = *(int *)(param_1 + 0x78);
    if ((*(int *)(param_1 + 0x250 + iVar6 * 4) != 0) || (*(int *)(param_1 + 0x2c + iVar6 * 4) != 0))
    {
      (**(code **)(*(int *)(param_1 + -0x40) + 100))(iVar6,0x3f800000,1,0xbf800000);
      *(undefined1 *)(param_1 + 0xc) = 1;
      ExceptionList = pvStack_c;
      return 1;
    }
    *(undefined4 *)(param_1 + 0x78) = 0xffffffff;
  }
  ExceptionList = pvStack_c;
  return 0;
}
```
