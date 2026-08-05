# Raw capture: FUN_004dc1c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dc1c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004dc1c0` |
| **Canonical name** | `FUN_004dc1c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004dc1c0(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int *piStack_248;
  undefined4 uStack_244;
  int iStack_234;
  int iStack_230;
  int aiStack_22c [130];
  undefined1 uStack_24;
  void *pvStack_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009a2375;
  pvStack_14 = ExceptionList;
  uStack_244 = "ReadRoadData";
  piStack_248 = (int *)0x4dc1f4;
  ExceptionList = &pvStack_14;
  FUN_007a4400();
  local_c = 0;
  uStack_244 = (char *)0x4dc20c;
  (**(code **)(*(int *)(param_1 + 0xe558) + 4))();
  uStack_244 = (char *)0x4;
  piStack_248 = aiStack_22c;
  *(undefined4 *)(param_1 + 0xe7cc) = 0;
  (**(code **)(*param_2 + 0x14))();
  FUN_004924c0();
  FUN_00493f40();
  FUN_00493f40();
  iStack_230 = 0;
  if (0 < iStack_234) {
    do {
      cVar4 = '\0';
      (**(code **)(*param_2 + 0x14))();
      (**(code **)(*param_2 + 0x14))((int)&uStack_244 + 3,1);
      if (cVar4 == '\0') {
        piStack_248 = operator_new(0x170);
        uStack_24 = 1;
        if (piStack_248 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = (int *)FUN_005e7600(param_1);
        }
        iVar3 = *(int *)(param_1 + 0xe53c);
        uStack_24 = 0;
        if ((iVar3 == 0) ||
           ((uint)(*(int *)(param_1 + 0xe544) - iVar3 >> 2) <=
            (uint)(*(int *)(param_1 + 0xe540) - iVar3 >> 2))) {
          iVar3 = param_1 + 0xe538;
LAB_004dc310:
          uStack_24 = 0;
          piStack_248 = piVar2;
          FUN_00493830(*(undefined4 *)(iVar3 + 8),1,&piStack_248);
        }
        else {
          piVar1 = *(int **)(param_1 + 0xe540);
          *piVar1 = (int)piVar2;
          *(int **)(param_1 + 0xe540) = piVar1 + 1;
          piStack_248 = piVar2;
        }
      }
      else if (cVar4 == '\x01') {
        piStack_248 = operator_new(0x1ac);
        uStack_24 = 2;
        if (piStack_248 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = (int *)FUN_005e63e0(param_1);
        }
        iVar3 = *(int *)(param_1 + 0xe52c);
        uStack_24 = 0;
        if ((iVar3 == 0) ||
           ((uint)(*(int *)(param_1 + 0xe534) - iVar3 >> 2) <=
            (uint)(*(int *)(param_1 + 0xe530) - iVar3 >> 2))) {
          iVar3 = param_1 + 0xe528;
          goto LAB_004dc310;
        }
        piVar1 = *(int **)(param_1 + 0xe530);
        *piVar1 = (int)piVar2;
        *(int **)(param_1 + 0xe530) = piVar1 + 1;
        piStack_248 = piVar2;
      }
      else {
        piStack_248 = operator_new(0x194);
        uStack_24 = 3;
        if (piStack_248 == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = (int *)FUN_005e2110(param_1);
        }
        uStack_24 = 0;
      }
      (**(code **)(*piVar2 + 8))(param_2,param_3);
      iVar3 = _isnan((double)(float)piVar2[0x50]);
      if (((iVar3 == 0) && (iVar3 = _isnan((double)(float)piVar2[0x51]), iVar3 == 0)) &&
         (iVar3 = _isnan((double)(float)piVar2[0x52]), iVar3 == 0)) {
        FUN_004e76d0(piVar2[0x4d],piVar2,0);
        if (*(int *)(param_1 + 0xe7cc) <= piVar2[0x4d]) {
          *(int *)(param_1 + 0xe7cc) = piVar2[0x4d] + 1;
        }
        FUN_004d5820();
        (**(code **)(*piVar2 + 0x98))();
      }
      else {
        FUN_007a4480(1,"Dropped bad road: %d ");
      }
      iStack_230 = iStack_230 + 1;
    } while (iStack_230 < iStack_234);
  }
  FUN_004d01c0();
  if ((*(char *)(param_1 + 0x7d) == '\0') && (*(char *)(param_1 + 0xf5) == '\0')) {
    FUN_004db500();
  }
  if (*(int *)(param_1 + 0x8c) < 0x1c) {
    FUN_004d22a0();
  }
  pvStack_14 = (void *)0xffffffff;
  FUN_007a4390();
  ExceptionList = pvStack_1c;
  return;
}
```
