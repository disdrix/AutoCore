# Raw capture: FUN_007eaf20

| Field | Value |
|---|---|
| **Stable ID** | `aa_007eaf20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007eaf20` |
| **Canonical name** | `FUN_007eaf20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x007ec60a) */
/* WARNING: Removing unreachable block (ram,0x007ec386) */
/* WARNING: Removing unreachable block (ram,0x007ec39e) */
/* WARNING: Removing unreachable block (ram,0x007ec541) */
/* WARNING: Removing unreachable block (ram,0x007ec436) */
/* WARNING: Removing unreachable block (ram,0x007ec360) */
/* WARNING: Removing unreachable block (ram,0x007ec1bd) */
/* WARNING: Removing unreachable block (ram,0x007ec14f) */
/* WARNING: Removing unreachable block (ram,0x007ec0e3) */
/* WARNING: Removing unreachable block (ram,0x007ec069) */
/* WARNING: Removing unreachable block (ram,0x007ebffd) */
/* WARNING: Removing unreachable block (ram,0x007ebf8f) */
/* WARNING: Removing unreachable block (ram,0x007ebf21) */
/* WARNING: Removing unreachable block (ram,0x007ebeb3) */
/* WARNING: Removing unreachable block (ram,0x007ebe44) */
/* WARNING: Removing unreachable block (ram,0x007ebdd6) */
/* WARNING: Removing unreachable block (ram,0x007ebd6a) */
/* WARNING: Removing unreachable block (ram,0x007ebcfc) */
/* WARNING: Removing unreachable block (ram,0x007ebc8c) */
/* WARNING: Removing unreachable block (ram,0x007ebc1c) */
/* WARNING: Removing unreachable block (ram,0x007ebbd3) */
/* WARNING: Removing unreachable block (ram,0x007ebbf3) */
/* WARNING: Removing unreachable block (ram,0x007ebc22) */
/* WARNING: Removing unreachable block (ram,0x007ebc54) */
/* WARNING: Removing unreachable block (ram,0x007ebc5a) */
/* WARNING: Removing unreachable block (ram,0x007ebc92) */
/* WARNING: Removing unreachable block (ram,0x007ebcc4) */
/* WARNING: Removing unreachable block (ram,0x007ebcca) */
/* WARNING: Removing unreachable block (ram,0x007ebd02) */
/* WARNING: Removing unreachable block (ram,0x007ebd34) */
/* WARNING: Removing unreachable block (ram,0x007ebd3a) */
/* WARNING: Removing unreachable block (ram,0x007ebd70) */
/* WARNING: Removing unreachable block (ram,0x007ebda0) */
/* WARNING: Removing unreachable block (ram,0x007ebda6) */
/* WARNING: Removing unreachable block (ram,0x007ebddc) */
/* WARNING: Removing unreachable block (ram,0x007ebe0e) */
/* WARNING: Removing unreachable block (ram,0x007ebe14) */
/* WARNING: Removing unreachable block (ram,0x007ebe4a) */
/* WARNING: Removing unreachable block (ram,0x007ebe7c) */
/* WARNING: Removing unreachable block (ram,0x007ebe82) */
/* WARNING: Removing unreachable block (ram,0x007ebeb9) */
/* WARNING: Removing unreachable block (ram,0x007ebeea) */
/* WARNING: Removing unreachable block (ram,0x007ebef0) */
/* WARNING: Removing unreachable block (ram,0x007ebf27) */
/* WARNING: Removing unreachable block (ram,0x007ebf58) */
/* WARNING: Removing unreachable block (ram,0x007ebf5e) */
/* WARNING: Removing unreachable block (ram,0x007ebf95) */
/* WARNING: Removing unreachable block (ram,0x007ebfc6) */
/* WARNING: Removing unreachable block (ram,0x007ebfcc) */
/* WARNING: Removing unreachable block (ram,0x007ec003) */
/* WARNING: Removing unreachable block (ram,0x007ec033) */
/* WARNING: Removing unreachable block (ram,0x007ec039) */
/* WARNING: Removing unreachable block (ram,0x007ec06f) */
/* WARNING: Removing unreachable block (ram,0x007ec0ad) */
/* WARNING: Removing unreachable block (ram,0x007ec0b3) */
/* WARNING: Removing unreachable block (ram,0x007ec0e9) */
/* WARNING: Removing unreachable block (ram,0x007ec119) */
/* WARNING: Removing unreachable block (ram,0x007ec11f) */
/* WARNING: Removing unreachable block (ram,0x007ec155) */
/* WARNING: Removing unreachable block (ram,0x007ec186) */
/* WARNING: Removing unreachable block (ram,0x007ec18c) */
/* WARNING: Removing unreachable block (ram,0x007ec1c3) */
/* WARNING: Removing unreachable block (ram,0x007ec1fc) */
/* WARNING: Removing unreachable block (ram,0x007ec202) */
/* WARNING: Removing unreachable block (ram,0x007ec221) */
/* WARNING: Removing unreachable block (ram,0x007ec3b3) */
/* WARNING: Removing unreachable block (ram,0x007ec3b9) */
/* WARNING: Removing unreachable block (ram,0x007ec3df) */
/* WARNING: Removing unreachable block (ram,0x007ec3f4) */
/* WARNING: Removing unreachable block (ram,0x007ec3fa) */
/* WARNING: Removing unreachable block (ram,0x007ec421) */
/* WARNING: Removing unreachable block (ram,0x007ec43c) */
/* WARNING: Removing unreachable block (ram,0x007ec462) */
/* WARNING: Removing unreachable block (ram,0x007ec477) */
/* WARNING: Removing unreachable block (ram,0x007ec47d) */
/* WARNING: Removing unreachable block (ram,0x007ec4a4) */
/* WARNING: Removing unreachable block (ram,0x007ec4b9) */
/* WARNING: Removing unreachable block (ram,0x007ec4bf) */
/* WARNING: Removing unreachable block (ram,0x007ec4e6) */
/* WARNING: Removing unreachable block (ram,0x007ec4fb) */
/* WARNING: Removing unreachable block (ram,0x007ec501) */
/* WARNING: Removing unreachable block (ram,0x007ec52c) */
/* WARNING: Removing unreachable block (ram,0x007ec547) */
/* WARNING: Removing unreachable block (ram,0x007ec56f) */
/* WARNING: Removing unreachable block (ram,0x007ec5c7) */
/* WARNING: Removing unreachable block (ram,0x007ec584) */
/* WARNING: Removing unreachable block (ram,0x007ec58a) */
/* WARNING: Removing unreachable block (ram,0x007ec5b2) */
/* WARNING: Removing unreachable block (ram,0x007ec5cd) */
/* WARNING: Removing unreachable block (ram,0x007ec7d5) */
/* WARNING: Removing unreachable block (ram,0x007ec5f5) */
/* WARNING: Removing unreachable block (ram,0x007ec610) */
/* WARNING: Removing unreachable block (ram,0x007ec650) */
/* WARNING: Removing unreachable block (ram,0x007ec6f4) */
/* WARNING: Removing unreachable block (ram,0x007ec6fd) */
/* WARNING: Removing unreachable block (ram,0x007ec71d) */
/* WARNING: Removing unreachable block (ram,0x007ec726) */
/* WARNING: Removing unreachable block (ram,0x007ec74e) */
/* WARNING: Removing unreachable block (ram,0x007ec757) */
/* WARNING: Removing unreachable block (ram,0x007ec63b) */
/* WARNING: Removing unreachable block (ram,0x007ec76c) */
/* WARNING: Removing unreachable block (ram,0x007ec791) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffc6c : 0x007ec30b */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int __thiscall FUN_007eaf20(char *param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  size_t sVar4;
  wchar_t *_Dest;
  undefined4 *puVar5;
  char *unaff_EDI;
  float fVar6;
  int in_stack_fffffc6c;
  undefined1 uStack_375;
  int *piStack_370;
  BSTR pOStack_36c;
  undefined1 uStack_365;
  undefined1 uStack_364;
  undefined1 uStack_363;
  byte bStack_362;
  undefined1 uStack_361;
  undefined4 uStack_360;
  undefined4 uStack_35c;
  undefined4 *puStack_358;
  undefined4 uStack_354;
  int iStack_350;
  undefined4 uStack_34c;
  undefined4 *puStack_348;
  undefined4 uStack_344;
  undefined4 uStack_340;
  undefined4 uStack_33c;
  undefined4 uStack_338;
  int iStack_334;
  int iStack_330;
  undefined1 *puStack_32c;
  undefined2 uStack_328;
  undefined2 uStack_324;
  undefined2 uStack_320;
  undefined2 uStack_31c;
  undefined2 uStack_318;
  undefined2 uStack_314;
  char *local_310;
  undefined2 uStack_30c;
  undefined2 uStack_308;
  undefined2 uStack_304;
  undefined2 uStack_300;
  short sStack_2fc;
  short sStack_2f8;
  undefined2 uStack_2f4;
  undefined2 uStack_2f0;
  undefined4 uStack_2e8;
  undefined4 uStack_2e4;
  undefined4 uStack_2e0;
  undefined4 uStack_2dc;
  undefined2 uStack_2d8;
  undefined2 uStack_2d6;
  undefined2 uStack_2d4;
  byte bStack_2d2;
  undefined1 uStack_2d1;
  undefined4 uStack_2d0;
  undefined4 uStack_2c4;
  undefined4 uStack_2c0;
  undefined1 auStack_2bc [8];
  undefined4 *puStack_2b4;
  int iStack_2ac;
  undefined1 uStack_290;
  undefined1 uStack_27c;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 uStack_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  wchar_t awStack_234 [20];
  wchar_t awStack_20c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009b0d00;
  local_c = ExceptionList;
  if (*param_1 == '\0') {
    return -0x7fffbffc;
  }
  ExceptionList = &local_c;
  local_310 = param_1;
  iVar3 = FUN_007e59d0();
  if (iVar3 < 0) {
    ExceptionList = local_c;
    return iVar3;
  }
  iStack_334 = *param_2;
  if (DAT_00d1793c != '\0') {
    FUN_00423670();
    uStack_4 = 5;
    _itow(iStack_334,awStack_234,10);
    FUN_00422eb0();
    lstrlenW(L"\']");
    iVar3 = FUN_00422ee0();
    if (iVar3 < 0) {
                    /* WARNING: Subroutine does not return */
      FUN_004048e0();
    }
    FUN_00419ca0();
    uStack_4._0_1_ = 6;
    if (DAT_00d1e56c == 0) {
      _com_issue_error(-0x7fffbffd);
    }
    uStack_4._0_1_ = 5;
    FUN_00419ed0();
    uStack_4 = CONCAT31(uStack_4._1_3_,8);
    if (piStack_370 == (int *)0x0) {
      _com_issue_error(-0x7fffbffd);
    }
    iVar3 = FUN_00419ff0();
    if (0 < iVar3) {
      if (piStack_370 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      (**(code **)(*piStack_370 + 0x1c))();
    }
    FUN_004235b0();
    _itow(iStack_334,awStack_234,10);
    FUN_00422eb0();
    lstrlenW(L"\']");
    iVar3 = FUN_00422ee0();
    if (-1 < iVar3) {
      puStack_32c = &stack0xfffffc6c;
      FUN_00419ca0();
      uStack_4._0_1_ = 9;
      if (DAT_00d1e56c == 0) {
        _com_issue_error(-0x7fffbffd);
      }
      uStack_4 = CONCAT31(uStack_4._1_3_,8);
      puVar5 = (undefined4 *)FUN_00419ed0();
      piVar1 = (int *)*puVar5;
      piVar2 = piStack_370;
      if (piStack_370 != piVar1) {
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))();
        }
        piVar2 = piVar1;
        if (piStack_370 != (int *)0x0) {
          (**(code **)(*piStack_370 + 8))();
        }
      }
      piStack_370 = piVar2;
      if (&stack0x00000000 != (undefined1 *)0x394) {
        (**(code **)(in_stack_fffffc6c + 8))();
      }
      if (piStack_370 == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
      }
      puStack_32c = (undefined1 *)FUN_00419ff0();
      iStack_330 = 0;
      if (0 < (int)puStack_32c) {
        do {
          if (piStack_370 == (int *)0x0) {
            _com_issue_error(-0x7fffbffd);
          }
          (**(code **)(*piStack_370 + 0x1c))();
          iStack_330 = iStack_330 + 1;
        } while (iStack_330 < (int)puStack_32c);
      }
      uStack_4 = CONCAT31(uStack_4._1_3_,5);
      if (piStack_370 != (int *)0x0) {
        (**(code **)(*piStack_370 + 8))();
      }
      SysFreeString(pOStack_36c);
      ExceptionList = local_c;
      return 0;
    }
                    /* WARNING: Subroutine does not return */
    FUN_004048e0();
  }
  puStack_348 = &uStack_360;
  uStack_360 = 0;
  uStack_35c = 0;
  puStack_358 = (undefined4 *)0x0;
  uStack_354 = 0;
  iStack_350 = 0;
  uStack_34c = 0;
  uStack_340 = 0;
  uStack_344 = 0;
  uStack_33c = 0;
  uStack_338 = 0;
  uStack_4 = 0;
  FUN_004230d0();
  iVar3 = FUN_00422fb0();
  if (-1 < iVar3) {
    iVar3 = FUN_0041a810(&uStack_360,param_1 + 0x28,0,0);
  }
  puStack_358 = &uStack_2c4;
  if ((((((iVar3 < 0) || (iVar3 = FUN_004231d0(), iVar3 < 0)) || (iVar3 = FUN_004231d0(), iVar3 < 0)
        ) || (((((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
                ((iVar3 = FUN_004231d0(), iVar3 < 0 ||
                 ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))))) ||
               (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
              ((((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
                (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
               ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))))))) ||
      ((((iVar3 = FUN_004231d0(), iVar3 < 0 ||
         ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))) ||
        ((iVar3 = FUN_004231d0(), iVar3 < 0 ||
         ((((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
           (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
          ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))))))) ||
       ((iVar3 = FUN_004231d0(), iVar3 < 0 ||
        ((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)))))))) ||
     ((iVar3 = FUN_004231d0(), iVar3 < 0 ||
      (((iVar3 = FUN_004231d0(), iVar3 < 0 || (iVar3 = FUN_004231d0(), iVar3 < 0)) ||
       (iStack_350 == 0)))))) {
    FUN_00423170();
    FUN_007a4480(1);
LAB_007ebac7:
    uStack_4 = 0xffffffff;
    FUN_0041a3e0();
  }
  else {
    iVar3 = FUN_0041a9b0();
    if (iVar3 == 0) {
      param_4[7] = uStack_254;
      param_4[8] = (uint)(sStack_2f8 == -1);
      param_4[9] = (uint)(sStack_2f8 == -1);
      *param_4 = uStack_2c4;
      *(undefined2 *)(param_4 + 0xc) = uStack_2f0;
      param_4[10] = (uint)(sStack_2fc == -1);
      *(undefined2 *)((int)param_4 + 0x2e) = uStack_30c;
      param_4[1] = uStack_244;
      *(undefined2 *)((int)param_4 + 0x32) = uStack_324;
      param_4[2] = uStack_258;
      *(undefined2 *)((int)param_4 + 0x36) = uStack_318;
      *(undefined2 *)(param_4 + 0xd) = uStack_320;
      param_4[3] = uStack_268;
      *(undefined1 *)((int)param_4 + 0x39) = uStack_363;
      param_4[4] = uStack_248;
      *(undefined2 *)((int)param_4 + 0x3a) = uStack_300;
      *(undefined2 *)(param_4 + 0xb) = uStack_308;
      param_4[5] = uStack_240;
      param_4[0x11] = uStack_260;
      *(undefined1 *)(param_4 + 0xf) = uStack_361;
      param_4[6] = uStack_250;
      fVar6 = (float)bStack_362 * DAT_00a0f718;
      param_4[0x12] = uStack_264;
      *(undefined2 *)(param_4 + 0x14) = uStack_328;
      param_4[0x13] = uStack_25c;
      *(undefined1 *)(param_4 + 0xe) = 0;
      param_4[0x10] = fVar6;
      *(undefined2 *)((int)param_4 + 0x52) = uStack_304;
      param_4[0x15] = uStack_24c;
      param_4[0x16] = 0;
      sVar4 = wcslen(awStack_20c);
      if (sVar4 != 0) {
        sVar4 = wcslen(awStack_20c);
        _Dest = operator_new__(sVar4 * 2 + 2);
        param_4[0x16] = _Dest;
        wcscpy(_Dest,awStack_20c);
      }
      FUN_0041a990();
      FUN_00423170();
      FUN_0041a3b0();
      uStack_4 = CONCAT31(uStack_4._1_3_,1);
      FUN_004230d0();
      iVar3 = FUN_00422fb0();
      if (-1 < iVar3) {
        iVar3 = FUN_0041a810(auStack_2bc,local_310 + 0x28,0,0);
      }
      puStack_2b4 = &uStack_2c0;
      if ((((-1 < iVar3) && (iVar3 = FUN_004231d0(), -1 < iVar3)) &&
          ((iVar3 = FUN_004231d0(), -1 < iVar3 &&
           ((iVar3 = FUN_004231d0(), -1 < iVar3 && (iVar3 = FUN_004231d0(), -1 < iVar3)))))) &&
         ((iVar3 = FUN_004231d0(), -1 < iVar3 &&
          (((((iVar3 = FUN_004231d0(), -1 < iVar3 && (iVar3 = FUN_004231d0(), -1 < iVar3)) &&
             (iVar3 = FUN_004231d0(), -1 < iVar3)) &&
            ((iVar3 = FUN_004231d0(), -1 < iVar3 && (iVar3 = FUN_004231d0(), -1 < iVar3)))) &&
           (iStack_2ac != 0)))))) {
        iVar3 = FUN_0041c000();
        if (iVar3 == 0) {
          do {
            uStack_2d1 = uStack_364;
            uStack_2d8 = uStack_31c;
            uStack_2dc = uStack_2c0;
            bStack_2d2 = (byte)iStack_330 & 1;
            uStack_2d6 = uStack_2f4;
            uStack_2d4 = uStack_314;
            uStack_2d0 = puStack_32c;
            Map_LowerBoundFindByCharKey(param_4 + 0x17,&local_310,&uStack_365,unaff_EDI);
            if (local_310 == (char *)param_4[0x18]) {
              uStack_2e8 = 0;
              uStack_2e4 = 0;
              uStack_2e0 = 0;
              uStack_4._0_1_ = 2;
              FUN_0041aa40();
              uStack_27c = uStack_375;
              FUN_0041c140();
              uStack_4._0_1_ = 3;
              uStack_290 = uStack_27c;
              FUN_0041c140();
              uStack_4._0_1_ = 4;
              FUN_0041a570();
              FUN_0068a4a0();
              FUN_0068a4a0();
              uStack_4 = CONCAT31(uStack_4._1_3_,1);
              FUN_00691630();
            }
            else {
              FUN_0041aa40();
            }
            iVar3 = FUN_0041c000();
          } while (iVar3 == 0);
        }
        FUN_0041a990();
        FUN_00423170();
        uStack_4 = uStack_4 & 0xffffff00;
        FUN_0041a3e0();
        goto LAB_007ebac7;
      }
      FUN_00423170();
      FUN_007a4480(1);
      uStack_4 = uStack_4 & 0xffffff00;
      FUN_0041a3e0();
    }
    else {
      FUN_0041a990();
      FUN_00423170();
      FUN_007a4480(1);
    }
    uStack_4 = 0xffffffff;
    FUN_0041a3e0();
  }
  ExceptionList = local_c;
  return 0;
}
```
