# Raw capture: FUN_007dec20

| Field | Value |
|---|---|
| **Stable ID** | `aa_007dec20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007dec20` |
| **Canonical name** | `FUN_007dec20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_007dec20(char *param_1,byte *param_2)

{
  IUnknown *This;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  ULONG UVar4;
  BSTR pOVar5;
  uint uVar6;
  int *unaff_EBX;
  int *unaff_EBP;
  IUnknown *This_00;
  int *unaff_EDI;
  undefined4 *puVar7;
  undefined4 auStackY_258 [29];
  undefined4 uStackY_1e4;
  uint *puStackY_1e0;
  undefined1 **ppuStackY_1dc;
  undefined1 **ppuVar8;
  int local_1ac;
  int *local_1a8;
  undefined1 *local_1a0;
  IUnknown *local_19c;
  IUnknown *local_198;
  uint local_194;
  int iStack_190;
  uint local_18c [2];
  int *local_184;
  undefined4 local_180;
  int local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  int **local_16c;
  undefined4 local_168;
  undefined4 local_164;
  BSTR local_160;
  uint local_15c;
  BSTR local_158;
  IUnknown **ppIStack_154;
  int iStack_14c;
  wchar_t awStack_130 [68];
  undefined4 auStack_a8 [37];
  void *pvStack_14;
  int *local_c;
  int *piStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  piStack_8 = (int *)&LAB_009aeed6;
  local_c = ExceptionList;
  if (DAT_00d1793c != '\0') {
    ExceptionList = &local_c;
    local_158 = SysAllocString(L"//vHeadBody_Character/row[@bitIsHead=\'Tr\']");
    if (local_158 != (BSTR)0x0) {
      local_198 = (IUnknown *)0x0;
      local_1a0 = &stack0xfffffe40;
      local_4._0_1_ = 4;
      local_4._1_3_ = 0;
      FUN_00419ca0();
      local_4._0_1_ = 5;
      if (DAT_00d1e56c == 0) {
        _com_issue_error(-0x7fffbffd);
      }
      local_4 = CONCAT31(local_4._1_3_,4);
      puVar3 = (undefined4 *)FUN_00419ed0();
      This = (IUnknown *)*puVar3;
      This_00 = (IUnknown *)0x0;
      if (This != (IUnknown *)0x0) {
        local_198 = This;
        (*This->lpVtbl->AddRef)(This);
        This_00 = This;
      }
      if (local_1a8 != (int *)0x0) {
        (**(code **)(*local_1a8 + 8))();
      }
      iVar1 = 0;
      while( true ) {
        if (This_00 == (IUnknown *)0x0) {
          _com_issue_error(-0x7fffbffd);
        }
        ppuVar8 = &local_1a0;
        local_1a0 = (undefined1 *)0x0;
        UVar4 = (*This_00->lpVtbl[2].Release)(This_00);
        if ((int)UVar4 < 0) {
          _com_issue_errorex(UVar4,This_00,(_GUID *)&DAT_00a86118);
        }
        if (-1 < iVar1) break;
        if (unaff_EBX != (int *)0x0) {
          (**(code **)(*unaff_EBX + 8))();
        }
        (*This_00->lpVtbl[2].AddRef)(This_00);
        if (ppuVar8 != (undefined1 **)0x0) {
          ppuStackY_1dc = (undefined1 **)0x7df11f;
          pOVar5 = SysAllocString(L"IDClass");
          ppuStackY_1dc = ppuVar8;
          if (pOVar5 == (BSTR)0x0) goto LAB_007df023;
          ppuVar8 = ppuStackY_1dc;
          if (ppuStackY_1dc != (undefined1 **)0x0) {
            puStackY_1e0 = (uint *)0x7df144;
            (**(code **)(*ppuStackY_1dc + 4))();
            ppuVar8 = ppuStackY_1dc;
          }
          ppuStackY_1dc = (undefined1 **)0x7df149;
          uVar6 = FUN_007b8a60();
          unaff_EDI = (int *)&stack0xfffffe28;
          if (*(byte *)((int)local_c + 9) == uVar6) {
            ppuStackY_1dc = (undefined1 **)0x7df16d;
            pOVar5 = SysAllocString(L"IDRace");
            ppuStackY_1dc = ppuVar8;
            if (pOVar5 == (BSTR)0x0) goto LAB_007df023;
            ppuVar8 = ppuStackY_1dc;
            if (ppuStackY_1dc != (undefined1 **)0x0) {
              puStackY_1e0 = (uint *)0x7df192;
              (**(code **)(*ppuStackY_1dc + 4))();
              ppuVar8 = ppuStackY_1dc;
            }
            ppuStackY_1dc = (undefined1 **)0x7df197;
            uVar6 = FUN_007b8a60();
            unaff_EDI = (int *)&stack0xfffffe28;
            if (*(byte *)((int)local_c + 10) == uVar6) {
              ppuStackY_1dc = (undefined1 **)0x7df1b7;
              pOVar5 = SysAllocString(L"bitIsMale");
              ppuStackY_1dc = ppuVar8;
              if (pOVar5 == (BSTR)0x0) goto LAB_007df023;
              if (ppuStackY_1dc != (undefined1 **)0x0) {
                puStackY_1e0 = (uint *)0x7df1dc;
                (**(code **)(*ppuStackY_1dc + 4))();
              }
              ppuStackY_1dc = (undefined1 **)0x7df1e1;
              iVar2 = FUN_007b8910();
              unaff_EDI = (int *)&stack0xfffffe28;
              if (*local_c == iVar2) {
                unaff_EDI = (int *)&stack0xfffffe28;
              }
            }
          }
        }
        iVar1 = iVar1 + 1;
        This_00 = local_198;
      }
      puVar3 = auStack_a8;
      for (iVar1 = 0x26; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      puVar3 = auStack_a8;
      puVar7 = auStackY_258;
      for (iVar1 = 0x26; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar7 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar7 = puVar7 + 1;
      }
      FUN_0041c2d0();
      iVar1 = *(int *)(param_2 + 4);
      while( true ) {
        do {
          do {
            do {
              do {
                UVar4 = (*local_19c->lpVtbl[2].Release)(local_19c);
                if ((int)UVar4 < 0) {
                  _com_issue_errorex(UVar4,local_19c,(_GUID *)&DAT_00a86118);
                }
                if ((int)unaff_EBX <= iVar1) {
                  local_c._0_1_ = 3;
                  if (unaff_EBP != (int *)0x0) {
                    (**(code **)(*unaff_EBP + 8))();
                  }
                  local_c = (int *)CONCAT31(local_c._1_3_,2);
                  (*local_19c->lpVtbl->Release)(local_19c);
                  SysFreeString(local_160);
                  ExceptionList = pvStack_14;
                  return 0;
                }
                if (unaff_EBP != (int *)0x0) {
                  (**(code **)(*unaff_EBP + 8))();
                }
                unaff_EBP = (int *)0x0;
                (*local_19c->lpVtbl[2].AddRef)(local_19c);
              } while (unaff_EDI == (int *)0x0);
              pOVar5 = SysAllocString(L"IDClass");
              if (pOVar5 == (BSTR)0x0) goto LAB_007df023;
              if (unaff_EDI != (int *)0x0) {
                ppuStackY_1dc = (undefined1 **)0x7df2d8;
                (**(code **)(*unaff_EDI + 4))();
              }
              uVar6 = FUN_007b8a60();
            } while (*(byte *)((int)piStack_8 + 9) != uVar6);
            pOVar5 = SysAllocString(L"IDRace");
            if (pOVar5 == (BSTR)0x0) goto LAB_007df023;
            if (unaff_EDI != (int *)0x0) {
              ppuStackY_1dc = (undefined1 **)0x7df326;
              (**(code **)(*unaff_EDI + 4))();
            }
            uVar6 = FUN_007b8a60();
          } while (*(byte *)((int)piStack_8 + 10) != uVar6);
          pOVar5 = SysAllocString(L"bitIsMale");
          if (pOVar5 == (BSTR)0x0) goto LAB_007df023;
          if (unaff_EDI != (int *)0x0) {
            ppuStackY_1dc = (undefined1 **)0x7df374;
            (**(code **)(*unaff_EDI + 4))();
          }
          iVar2 = FUN_007b8910();
        } while (*piStack_8 != iVar2);
        pOVar5 = SysAllocString(L"IDHeadBody");
        if (pOVar5 == (BSTR)0x0) break;
        if (unaff_EDI != (int *)0x0) {
          ppuStackY_1dc = (undefined1 **)0x7df3be;
          (**(code **)(*unaff_EDI + 4))();
        }
        _DAT_00000000 = FUN_007b8a60();
        ppuStackY_1dc = (undefined1 **)0x7df3de;
        pOVar5 = SysAllocString(L"strFilename");
        if (pOVar5 == (BSTR)0x0) break;
        if (unaff_EDI != (int *)0x0) {
          puStackY_1e0 = (uint *)0x7df403;
          ppuStackY_1dc = (undefined1 **)unaff_EDI;
          (**(code **)(*unaff_EDI + 4))();
        }
        ppuStackY_1dc = (undefined1 **)0x7df408;
        FUN_007b8de0();
        unaff_EBP = (int *)0x98;
      }
    }
LAB_007df023:
                    /* WARNING: Subroutine does not return */
    ppuStackY_1dc = (undefined1 **)0x7df02d;
    FUN_004048e0();
  }
  if (*param_1 == '\0') {
    ExceptionList = pvStack_14;
    return 0x80004004;
  }
  local_19c = (IUnknown *)(uint)param_2[9];
  local_18c[0] = (uint)param_2[10];
  local_194 = (uint)(*param_2 & 1);
  local_16c = &local_184;
  local_184 = (int *)0x0;
  local_180 = 0;
  local_17c = 0;
  local_178 = 0;
  local_174 = 0;
  local_170 = 0;
  local_164 = 0;
  local_168 = 0;
  local_160 = (BSTR)0x0;
  local_15c = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004230d0();
  iVar1 = FUN_00422fb0();
  if (((-1 < iVar1) && (iVar1 = FUN_00422fb0(), -1 < iVar1)) && (iVar1 = FUN_00422fb0(), -1 < iVar1)
     ) {
    ppuStackY_1dc = (undefined1 **)(param_1 + 0x28);
    puStackY_1e0 = local_18c;
    uStackY_1e4 = 0x7ded3e;
    iVar1 = FUN_0041a810();
  }
  local_184 = &iStack_190;
  if (((iVar1 < 0) || (iVar1 = FUN_004231d0(), iVar1 < 0)) || (local_17c == 0)) {
    FUN_00423170();
    FUN_007a4480();
  }
  else {
    iVar1 = FUN_0041a9b0();
    if (iVar1 == 0) {
      local_1ac = iStack_190;
    }
    if (local_17c != 0) {
      FUN_00422de0();
      FUN_0041bf70();
    }
    FUN_00423170();
    if (iVar1 != 0) {
      FUN_007a4480();
      local_c = (int *)0xffffffff;
      FUN_0041a3e0();
      ExceptionList = pvStack_14;
      return 0;
    }
    FUN_0041aad0();
    puVar3 = *(undefined4 **)(param_1 + 4);
    FUN_0041a3b0();
    local_c = (int *)CONCAT31(local_c._1_3_,1);
    FUN_004230d0();
    iVar1 = FUN_00422fb0();
    if (((-1 < iVar1) && (iVar1 = FUN_00422fb0(), -1 < iVar1)) &&
       (iVar1 = FUN_00422fb0(), -1 < iVar1)) {
      ppuStackY_1dc = (undefined1 **)(local_4 + 0x28);
      puStackY_1e0 = &local_15c;
      uStackY_1e4 = 0x7deebd;
      iVar1 = FUN_0041a810();
    }
    ppIStack_154 = &local_198;
    if ((((-1 < iVar1) && (iVar1 = FUN_004231d0(), -1 < iVar1)) &&
        (iVar1 = FUN_004231d0(), -1 < iVar1)) && (iStack_14c != 0)) {
      iVar1 = 0;
      if (0 < local_1ac) {
        do {
          iVar2 = FUN_0041c000();
          if (iVar2 != 0) break;
          *puVar3 = local_198;
          wcscpy((wchar_t *)(puVar3 + 4),awStack_130);
          iVar1 = iVar1 + 1;
          puVar3 = puVar3 + 0x26;
        } while (iVar1 < local_1ac);
      }
      if (iStack_14c != 0) {
        FUN_00422de0();
        FUN_0041bf70();
      }
      FUN_00423170();
      local_c = (int *)((uint)local_c & 0xffffff00);
      FUN_0041a3e0();
      local_c = (int *)0xffffffff;
      FUN_0041a3e0();
      ExceptionList = pvStack_14;
      return 0;
    }
    FUN_00423170();
    FUN_007a4480();
    local_c = (int *)((uint)local_c & 0xffffff00);
    FUN_0041a3e0();
  }
  local_c = (int *)0xffffffff;
  FUN_0041a3e0();
  ExceptionList = pvStack_14;
  return 0;
}
```
