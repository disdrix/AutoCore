// =============================================================================
// FUN_007de350
// -----------------------------------------------------------------------------
// Stable ID: aa_007de350
// Address:   0x007de350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007de350 @ 0x007de350
// Stable ID: aa_007de350
// Embedded strings (evidence for future rename):
//   - "//vHeadBody_Character/row[@bitIsHead=\'Fa\']"
//   - "IDClass"
//   - "IDRace"
//   - "bitIsMale"
//   - "IDHeadBody"
//   - "strFilename"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~349 non-empty decompiler lines.
//  - Control keywords: if×49, return×6, for×3, while×3, goto×3, do×2.
//  - Notable callees: SysAllocString×10, FUN_00422fb0×6, FUN_007b8a60×6, FUN_0041a3e0×5, FUN_00423170×4, FUN_004231d0×4, CONCAT31×3, FUN_007a4480×3.
//  - Strings: "//vHeadBody_Character/row[@bitIsHead=\'Fa\']"; "IDClass"; "IDRace"; "bitIsMale".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */



uint32_t /* width from decompiler */ __thiscall FUN_007de350(_func_5023 *param_1,byte *param_2)



{

  IUnknown *This;

  _func_5021 *This_00;

  _func_5022 *This_01;

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  ULONG UVar4;

  BSTR pOVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ uVar7;

  int *unaff_EBX;

  int *unaff_EBP;

  wchar_t *_Dest;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ *puVar8;

  int unaff_retaddr;

  uint32_t /* width from decompiler */ auStackY_258 [29];

  uint32_t /* width from decompiler */ uStackY_1e4;

  uint32_t /* width from decompiler */ *puStackY_1e0;

  IUnknownVtbl *pIStackY_1dc;

  IUnknown IVar9;

  int *local_1ac;

  int *local_1a8;

  uint32_t /* width from decompiler */ *puStack_1a4;

  IUnknownVtbl local_1a0;

  uint local_194;

  uint32_t /* width from decompiler */ uStack_190;

  uint local_18c;

  uint32_t /* width from decompiler */ local_188;

  uint local_184;

  int **local_180;

  uint32_t /* width from decompiler */ local_17c;

  int local_178;

  uint32_t /* width from decompiler */ local_174;

  uint32_t /* width from decompiler */ local_170;

  uint32_t /* width from decompiler */ local_16c;

  int ***local_168;

  uint32_t /* width from decompiler */ local_164;

  uint32_t /* width from decompiler */ local_160;

  uint32_t /* width from decompiler */ local_15c;

  uint32_t /* width from decompiler */ local_158;

  _func_5023 **pp_Stack_154;

  int iStack_14c;

  wchar_t awStack_130 [68];

  uint32_t /* width from decompiler */ auStack_a8 [37];

  void *pvStack_14;

  int iStack_10;

  int *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aee86;

  local_c = ExceptionList;

  local_188 = 0;

  local_1a0.Release = param_1;

  if (DAT_00d1793c != '\0') {

    ExceptionList = &local_c;

    local_1a0.Release =

         (_func_5023 *)SysAllocString(L"//vHeadBody_Character/row[@bitIsHead=\'Fa\']");

    if (local_1a0.Release != (_func_5023 *)0x0) {

      local_1a0.AddRef = (_func_5022 *)0x0;

      local_1a0.QueryInterface = (_func_5021 *)&stack0xfffffe40;

      local_4._0_1_ = 4;

      local_4._1_3_ = 0;

      FUN_00419ca0();

      local_4._0_1_ = 5;

      if (DAT_00d1e56c == 0) {

        _com_issue_error(-0x7fffbffd);

      }

      local_4 = CONCAT31(local_4._1_3_,4);

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

      This = (IUnknown *)*puVar3;

      if (This != (IUnknown *)0x0) {

        local_1a0.AddRef = (_func_5022 *)This;

        (*This->lpVtbl->AddRef)(This);

      }

      This_01 = local_1a0.AddRef;

      if (local_1a8 != (int *)0x0) {

        (**(code **)(*local_1a8 + 8))();

      }

      puStack_1a4 = (uint32_t /* width from decompiler */ *)0x0;

      iVar1 = 0;

      while( true ) {

        if ((IUnknown *)This_01 == (IUnknown *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        IVar9.lpVtbl = &local_1a0;

        local_1a0.QueryInterface = (_func_5021 *)0x0;

        UVar4 = (*(*(IUnknownVtbl **)This_01)[2].Release)((IUnknown *)This_01);

        if ((int)UVar4 < 0) {

          _com_issue_errorex(UVar4,(IUnknown *)This_01,(_GUID *)&DAT_00a86118);

        }

        if ((int)puStack_1a4 <= iVar1) break;

        if (unaff_EBX != (int *)0x0) {

          (**(code **)(*unaff_EBX + 8))();

        }

        (*(*(IUnknownVtbl **)This_01)[2].AddRef)((IUnknown *)This_01);

        if (IVar9.lpVtbl != (IUnknownVtbl *)0x0) {

          pIStackY_1dc = (IUnknownVtbl *)0x7de881;

          pOVar5 = SysAllocString(L"IDClass");

          pIStackY_1dc = IVar9.lpVtbl;

          if (pOVar5 == (BSTR)0x0) goto LAB_007de784;

          IVar9.lpVtbl = pIStackY_1dc;

          if (pIStackY_1dc != (IUnknownVtbl *)0x0) {

            puStackY_1e0 = (uint32_t /* width from decompiler */ *)0x7de8a6;

            (**(code **)(pIStackY_1dc->QueryInterface + 4))();

            IVar9.lpVtbl = pIStackY_1dc;

          }

          pIStackY_1dc = (IUnknownVtbl *)0x7de8ab;

          uVar6 = FUN_007b8a60();

          if (*(byte *)(iStack_10 + 9) == uVar6) {

            pIStackY_1dc = (IUnknownVtbl *)0x7de8cf;

            pOVar5 = SysAllocString(L"IDRace");

            pIStackY_1dc = IVar9.lpVtbl;

            if (pOVar5 == (BSTR)0x0) goto LAB_007de784;

            IVar9.lpVtbl = pIStackY_1dc;

            if (pIStackY_1dc != (IUnknownVtbl *)0x0) {

              puStackY_1e0 = (uint32_t /* width from decompiler */ *)0x7de8f4;

              (**(code **)(pIStackY_1dc->QueryInterface + 4))();

              IVar9.lpVtbl = pIStackY_1dc;

            }

            pIStackY_1dc = (IUnknownVtbl *)0x7de8f9;

            uVar6 = FUN_007b8a60();

            if (*(byte *)(iStack_10 + 10) == uVar6) {

              pIStackY_1dc = (IUnknownVtbl *)0x7de919;

              pOVar5 = SysAllocString(L"bitIsMale");

              pIStackY_1dc = IVar9.lpVtbl;

              if (pOVar5 == (BSTR)0x0) goto LAB_007de784;

              if (pIStackY_1dc != (IUnknownVtbl *)0x0) {

                puStackY_1e0 = (uint32_t /* width from decompiler */ *)0x7de93e;

                (**(code **)(pIStackY_1dc->QueryInterface + 4))();

              }

              pIStackY_1dc = (IUnknownVtbl *)0x7de943;

              FUN_007b8910();

            }

          }

          unaff_EDI = (int *)&stack0xfffffe28;

        }

        iVar1 = iVar1 + 1;

      }

      puVar3 = auStack_a8;

      for (iVar1 = 0x26; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      puVar3 = auStack_a8;

      puVar8 = auStackY_258;

      for (iVar1 = 0x26; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar8 = *puVar3;

        puVar3 = puVar3 + 1;

        puVar8 = puVar8 + 1;

      }

      FUN_0041c2d0();

      puVar3 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

      puStack_1a4 = puVar3 + 0x25;

      local_1a8 = (int *)0x0;

      do {

        This_00 = local_1a0.QueryInterface;

        UVar4 = (*(*(IUnknownVtbl **)local_1a0.QueryInterface)[2].Release)

                          ((IUnknown *)local_1a0.QueryInterface);

        if ((int)UVar4 < 0) {

          _com_issue_errorex(UVar4,(IUnknown *)This_00,(_GUID *)&DAT_00a86118);

        }

        if ((int)unaff_EBX < 1) {

          local_c._0_1_ = 3;

          if (unaff_EBP != (int *)0x0) {

            (**(code **)(*unaff_EBP + 8))();

          }

          local_c = (int *)CONCAT31(local_c._1_3_,2);

          (*(*(IUnknownVtbl **)This_00)->Release)((IUnknown *)This_00);

          SysFreeString((BSTR)local_1a0.QueryInterface);

          ExceptionList = pvStack_14;

          return 0;

        }

        if (unaff_EBP != (int *)0x0) {

          (**(code **)(*unaff_EBP + 8))();

        }

        unaff_EBP = (int *)0x0;

        (*(*(IUnknownVtbl **)This_00)[2].AddRef)((IUnknown *)This_00);

        if (unaff_EDI != (int *)0x0) {

          pOVar5 = SysAllocString(L"IDClass");

          if (pOVar5 == (BSTR)0x0) break;

          if (unaff_EDI != (int *)0x0) {

            pIStackY_1dc = (IUnknownVtbl *)0x7dea40;

            (**(code **)(*unaff_EDI + 4))();

          }

          uVar6 = FUN_007b8a60();

          if (*(byte *)((int)local_c + 9) == uVar6) {

            pOVar5 = SysAllocString(L"IDRace");

            if (pOVar5 == (BSTR)0x0) break;

            if (unaff_EDI != (int *)0x0) {

              pIStackY_1dc = (IUnknownVtbl *)0x7dea8e;

              (**(code **)(*unaff_EDI + 4))();

            }

            uVar6 = FUN_007b8a60();

            if (*(byte *)((int)local_c + 10) == uVar6) {

              pOVar5 = SysAllocString(L"bitIsMale");

              if (pOVar5 == (BSTR)0x0) break;

              if (unaff_EDI != (int *)0x0) {

                pIStackY_1dc = (IUnknownVtbl *)0x7deadc;

                (**(code **)(*unaff_EDI + 4))();

              }

              iVar1 = FUN_007b8910();

              if (*local_c == iVar1) {

                pOVar5 = SysAllocString(L"IDHeadBody");

                if (pOVar5 == (BSTR)0x0) break;

                if (unaff_EDI != (int *)0x0) {

                  pIStackY_1dc = (IUnknownVtbl *)0x7deb26;

                  (**(code **)(*unaff_EDI + 4))();

                }

                uVar7 = FUN_007b8a60();

                *puVar3 = uVar7;

                pIStackY_1dc = (IUnknownVtbl *)0x7deb42;

                pOVar5 = SysAllocString(L"strFilename");

                if (pOVar5 == (BSTR)0x0) break;

                if (unaff_EDI != (int *)0x0) {

                  puStackY_1e0 = (uint32_t /* width from decompiler */ *)0x7deb67;

                  pIStackY_1dc = (IUnknownVtbl *)unaff_EDI;

                  (**(code **)(*unaff_EDI + 4))();

                }

                pIStackY_1dc = (IUnknownVtbl *)0x7deb6c;

                FUN_007b8de0();

                pOVar5 = SysAllocString(L"intNumTextures");

                if (pOVar5 == (BSTR)0x0) break;

                if (unaff_EDI != (int *)0x0) {

                  pIStackY_1dc = (IUnknownVtbl *)0x7deba1;

                  (**(code **)(*unaff_EDI + 4))();

                }

                iVar1 = FUN_007b8a60();

                *unaff_EBX = iVar1;

                puVar3 = puVar3 + 0x26;

              }

            }

          }

        }

        local_1a8 = (int *)((int)local_1a8 + 1);

        puStack_1a4 = puStack_1a4 + 0x26;

      } while( true );

    }

LAB_007de784:

                    /* WARNING: Subroutine does not return */

    pIStackY_1dc = (IUnknownVtbl *)0x7de78e;

    FUN_004048e0();

  }

  if (*param_1 == (_func_5023)0x0) {

    ExceptionList = pvStack_14;

    return 0x80004004;

  }

  local_194 = (uint)param_2[9];

  local_184 = (uint)param_2[10];

  local_18c = (uint)(*param_2 & 1);

  local_168 = &local_180;

  local_180 = (int **)0x0;

  local_17c = 0;

  local_178 = 0;

  local_174 = 0;

  local_170 = 0;

  local_16c = 0;

  local_160 = 0;

  local_164 = 0;

  local_15c = 0;

  local_158 = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_004230d0();

  iVar1 = FUN_00422fb0();

  if (((-1 < iVar1) && (iVar1 = FUN_00422fb0(), -1 < iVar1)) && (iVar1 = FUN_00422fb0(), -1 < iVar1)

     ) {

    pIStackY_1dc = (IUnknownVtbl *)(param_1 + 0x28);

    puStackY_1e0 = &local_188;

    uStackY_1e4 = 0x7de474;

    iVar1 = FUN_0041a810();

  }

  local_180 = &local_1a8;

  if (((iVar1 < 0) || (iVar1 = FUN_004231d0(), iVar1 < 0)) || (local_178 == 0)) {

    FUN_00423170();

    FUN_007a4480();

  }

  else {

    iVar1 = FUN_0041a9b0();

    if (iVar1 == 0) {

      local_1ac = local_1a8;

    }

    if (local_178 != 0) {

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

    iVar1 = *(int *)(unaff_retaddr + 4);

    FUN_0041a3b0();

    local_c = (int *)CONCAT31(local_c._1_3_,1);

    FUN_004230d0();

    iVar2 = FUN_00422fb0();

    if (((-1 < iVar2) && (iVar2 = FUN_00422fb0(), -1 < iVar2)) &&

       (iVar2 = FUN_00422fb0(), -1 < iVar2)) {

      pIStackY_1dc = (IUnknownVtbl *)((int)local_1a0.QueryInterface + 0x28);

      puStackY_1e0 = &local_15c;

      uStackY_1e4 = 0x7de607;

      iVar2 = FUN_0041a810();

    }

    pp_Stack_154 = &local_1a0.Release;

    if ((((iVar2 < 0) || (iVar2 = FUN_004231d0(), iVar2 < 0)) || (iVar2 = FUN_004231d0(), iVar2 < 0)

        ) || ((iVar2 = FUN_004231d0(), iVar2 < 0 || (iStack_14c == 0)))) {

      FUN_00423170();

      FUN_007a4480();

      local_c = (int *)((uint)local_c & 0xffffff00);

      FUN_0041a3e0();

      local_c = (int *)0xffffffff;

      FUN_0041a3e0();

      ExceptionList = pvStack_14;

      return 0;

    }

    iVar2 = 0;

    if (0 < (int)local_1ac) {

      _Dest = (wchar_t *)(iVar1 + 0x10);

      do {

        iVar1 = FUN_0041c000();

        if (iVar1 != 0) break;

        *(_func_5023 **)(_Dest + -8) = local_1a0.Release;

        *(uint32_t /* width from decompiler */ *)(_Dest + 0x42) = uStack_190;

        wcscpy(_Dest,awStack_130);

        iVar2 = iVar2 + 1;

        _Dest = _Dest + 0x4c;

      } while (iVar2 < (int)local_1ac);

    }

    if (iStack_14c != 0) {

      FUN_00422de0();

      FUN_0041bf70();

    }

    FUN_00423170();

    local_c = (int *)((uint)local_c & 0xffffff00);

    FUN_0041a3e0();

  }

  local_c = (int *)0xffffffff;

  FUN_0041a3e0();

  ExceptionList = pvStack_14;

  return 0;

}
