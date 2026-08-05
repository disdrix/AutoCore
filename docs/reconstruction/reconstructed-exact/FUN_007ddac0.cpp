// =============================================================================
// FUN_007ddac0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ddac0
// Address:   0x007ddac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ddac0 @ 0x007ddac0
// Stable ID: aa_007ddac0
// Embedded strings (evidence for future rename):
//   - "//tHeadDetail/row[@lIDCloneBase=\'"
//   - "\xf88bכּ䉼ŪɪŪ䒍✤ᆹ"
//   - "\xf88bכּ୼尹㰤䙵ֿ@趀⑴\xe850哃ￄh꤈圀豨ꢎ樀\xe801柁￼쒃贐⑔刬蓆堤\x01Ȁ೨쏇웿⒄Ŕ"
//   - "tinType"
//   - "\xe9e8ﶩ菿ࣄ䐸ᬤյ䒃ᰤ茁Ǉ叩\xffff㏿㧿⑜縜譞㰭鱦脀铆"
//   - "咋․吻ᐤ贏｢\xffff䒋ဤ쌻ٴࢋｐࡑ䲋․䒍ဤ児岉ᠤᚋｖ᱒尹ဤ萏Ŋ"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~405 non-empty decompiler lines.
//  - Control keywords: if×51, goto×12, return×5, for×3, while×3, do×2.
//  - Notable callees: FUN_0041a3e0×5, FUN_004231d0×5, block×5, CONCAT31×4, FUN_00422fb0×4, FUN_00423170×4, FUN_007b8a60×4, FUN_004048e0×3.
//  - Strings: "//tHeadDetail/row[@lIDCloneBase=\'"; "\xf88bכּ䉼ŪɪŪ䒍✤ᆹ"; "\xf88bכּ୼尹㰤䙵ֿ@趀⑴\xe850哃ￄh꤈圀豨ꢎ樀\xe801柁￼쒃贐⑔刬蓆堤\x01Ȁ೨쏇웿⒄Ŕ"; "tinType".
//  - Return sites: 5.

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

/* WARNING: Removing unreachable block (ram,0x007de2e1) */

/* WARNING: Removing unreachable block (ram,0x007de21f) */

/* WARNING: Removing unreachable block (ram,0x007de264) */

/* WARNING: Removing unreachable block (ram,0x007de2a4) */

/* WARNING: Heritage AFTER dead removal. Example location: s0xfffffe94 : 0x007de326 */

/* WARNING: Removing unreachable block (ram,0x007ddbb0) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

/* WARNING: Exceeded maximum restarts with more pending */



uint32_t /* width from decompiler */ FUN_007ddac0(int param_1)



{

  int *piVar1;

  char cVar2;

  wchar_t *lpString;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  BSTR pOVar5;

  int iVar6;

  ULONG UVar7;

  _func_5021 *p_Var8;

  IUnknownVtbl *pIVar9;

  IUnknown *unaff_EBX;

  IUnknown unaff_EBP;

  code *pcVar10;

  IUnknown *unaff_ESI;

  uint *puVar11;

  IUnknown *pIVar12;

  uint32_t /* width from decompiler */ *puVar13;

  int *piVar14;

  int unaff_retaddr;

  uint32_t /* width from decompiler */ auStack_1f8 [29];

  uint32_t /* width from decompiler */ uStack_184;

  IUnknown **ppIStack_180;

  int *piStack_17c;

  uint32_t /* width from decompiler */ uStack_178;

  wchar_t *pwStack_174;

  IUnknown *in_stack_fffffe94;

  int **ppiVar15;

  uint32_t /* width from decompiler */ local_148;

  int *local_144;

  uint32_t /* width from decompiler */ uStack_140;

  IUnknown *local_13c;

  IUnknown *local_138;

  BSTR local_134;

  IUnknown *local_130;

  uint32_t /* width from decompiler */ local_12c;

  int local_128;

  uint32_t /* width from decompiler */ local_124;

  uint32_t /* width from decompiler */ local_120;

  BSTR *local_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ *local_114;

  uint32_t /* width from decompiler */ local_110;

  uint32_t /* width from decompiler */ local_10c;

  uint32_t /* width from decompiler */ local_108;

  uint local_104;

  int *local_100;

  IUnknown IStack_fc;

  uint32_t /* width from decompiler */ local_f8;

  wchar_t local_cc [16];

  uint32_t /* width from decompiler */ auStack_ac [37];

  void *pvStack_18;

  uint8_t uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aee36;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_134 = SysAllocString(L"//tHeadDetail/row[@lIDCloneBase=\'");

  if (local_134 == (BSTR)0x0) {

LAB_007ddaf8:

                    /* WARNING: Subroutine does not return */

    FUN_004048e0();

  }

  local_130 = (IUnknown *)0x0;

  local_148 = (IUnknownVtbl *)0x0;

  local_4._0_1_ = 2;

  local_4._1_3_ = 0;

  lpString = _itow(*(int *)(param_1 + 8),local_cc,10);

  lstrlenW(lpString);

  iVar3 = FUN_00422ee0();

  if (iVar3 < 0) {

                    /* WARNING: Subroutine does not return */

    FUN_004048e0();

  }

  lstrlenW(L"\']");

  iVar3 = FUN_00422ee0();

  if (iVar3 < 0) {

                    /* WARNING: Subroutine does not return */

    FUN_004048e0();

  }

  local_100 = *(int **)(param_1 + 8);

  uStack_140 = (BSTR)CONCAT13(*(uint8_t *)(param_1 + 0x8e),(undefined3)uStack_140);

  local_f8 = 0;

  if (DAT_00d1793c == '\0') {

    if (*(char *)&local_138->lpVtbl == '\0') {

      local_4 = CONCAT31(local_4._1_3_,1);

      local_f8 = 0;

      SysFreeString(local_134);

      ExceptionList = pvStack_18;

      return 0x80004004;

    }

    local_114 = &local_12c;

    local_12c = 0;

    local_128 = 0;

    local_124 = 0;

    local_120 = 0;

    local_11c = (BSTR *)0x0;

    local_118 = 0;

    local_10c = 0;

    local_110 = 0;

    local_108 = 0;

    local_104 = 0;

    ppiVar15 = &local_100;

    local_4 = CONCAT31(local_4._1_3_,3);

    FUN_004230d0();

    pwStack_174 = L"\xf88bכּ䉼ŪɪŪ䒍✤ᆹ";

    iVar3 = FUN_00422fb0();

    if (-1 < iVar3) {

      pwStack_174 = (wchar_t *)0x7ddc46;

      iVar3 = FUN_00422fb0();

      if (-1 < iVar3) {

        pwStack_174 = (wchar_t *)0x0;

        uStack_178 = 0;

        piStack_17c = local_144 + 10;

        ppIStack_180 = &local_138;

        uStack_184 = 0x7ddc6c;

        iVar3 = FUN_0041a810();

      }

    }

    local_130 = (IUnknown *)&stack0xfffffeb0;

    if (-1 < iVar3) {

      pwStack_174 = 

      L"\xf88bכּ୼尹㰤䙵ֿ@趀⑴\xe850哃ￄh꤈圀豨ꢎ樀\xe801柁￼쒃贐⑔刬蓆堤\x01Ȁ೨쏇웿⒄Ŕ"

      ;

      iVar3 = FUN_004231d0();

      if ((-1 < iVar3) && (local_128 != 0)) {

        iVar3 = FUN_0041a9b0();

        if (iVar3 == 0) {

          local_148 = unaff_EBP.lpVtbl;

        }

        if (local_128 != 0) {

          FUN_00422de0();

          FUN_0041bf70();

        }

        FUN_00423170();

        if (iVar3 == 0) {

          uStack_10 = 2;

          in_stack_fffffe94 = (IUnknown *)0x7ddd78;

          FUN_0041a3e0();

          pcVar10 = SysAllocString_exref;

          goto LAB_007ddd7e;

        }

        pwStack_174 = (wchar_t *)0x1;

        uStack_178 = 0x7ddd35;

        FUN_007a4480();

        uStack_10 = 2;

        FUN_0041a3e0();

        uStack_10 = 1;

        if (unaff_ESI == (IUnknown *)0x0) goto LAB_007de154;

        pIVar9 = unaff_ESI->lpVtbl;

        pIVar12 = unaff_ESI;

LAB_007de14c:

        (*pIVar9->Release)(pIVar12);

        goto LAB_007de154;

      }

    }

    FUN_00423170();

    pwStack_174 = (wchar_t *)0x1;

    uStack_178 = 0x7ddcbf;

    FUN_007a4480();

    uStack_10 = 2;

    FUN_0041a3e0();

    uStack_10 = 1;

  }

  else {

    local_13c = (IUnknown *)&stack0xfffffea4;

    FUN_00419ca0();

    local_4._0_1_ = 4;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4 = CONCAT31(local_4._1_3_,2);

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

    pIVar12 = (IUnknown *)*puVar4;

    if (pIVar12 != (IUnknown *)0x0) {

      local_130 = pIVar12;

      (*pIVar12->lpVtbl->AddRef)(pIVar12);

    }

    if (local_144 != (int *)0x0) {

      (**(code **)(*local_144 + 8))();

    }

    pcVar10 = SysAllocString_exref;

    local_13c = (IUnknown *)0x0;

    iVar3 = 0;

    while( true ) {

      pIVar12 = local_130;

      if (local_130 == (IUnknown *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      ppiVar15 = &local_144;

      local_144 = (int *)0x0;

      UVar7 = (*pIVar12->lpVtbl[2].Release)(pIVar12);

      if ((int)UVar7 < 0) {

        in_stack_fffffe94 = (IUnknown *)0x7de011;

        _com_issue_errorex(UVar7,pIVar12,(_GUID *)&DAT_00a86118);

      }

      if ((int)local_148 <= iVar3) break;

      if (unaff_EBX != (IUnknown *)0x0) {

        (*unaff_EBX->lpVtbl->Release)(unaff_EBX);

      }

      unaff_EBX = (IUnknown *)0x0;

      in_stack_fffffe94 = (IUnknown *)0x7de039;

      (*pIVar12->lpVtbl[2].AddRef)(pIVar12);

      if (unaff_ESI != (IUnknown *)0x0) {

        pOVar5 = SysAllocString(L"tinType");

        if (pOVar5 == (BSTR)0x0) goto LAB_007ddaf8;

        in_stack_fffffe94 = unaff_ESI;

        if (unaff_ESI != (IUnknown *)0x0) {

          pwStack_174 = L"\xe9e8ﶩ菿ࣄ䐸ᬤյ䒃ᰤ茁Ǉ叩\xffff㏿㧿⑜縜譞㰭鱦脀铆";

          (*unaff_ESI->lpVtbl->AddRef)();

        }

        cVar2 = FUN_007b8a60();

        unaff_EBP.lpVtbl = (IUnknownVtbl *)&stack0xfffffe94;

        if (cVar2 == '\0') {

          local_148 = (IUnknownVtbl *)((int)&local_148->QueryInterface + 1);

          unaff_EBP.lpVtbl = (IUnknownVtbl *)&stack0xfffffe94;

        }

      }

      iVar3 = iVar3 + 1;

    }

LAB_007ddd7e:

    piVar1 = local_144;

    puVar4 = auStack_ac;

    for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    puVar4 = auStack_ac;

    puVar13 = auStack_1f8;

    for (iVar3 = 0x26; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar13 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar13 = puVar13 + 1;

    }

    FUN_0041c370(piVar1);

    piVar1 = *(int **)(unaff_retaddr + 4);

    if (DAT_00d1793c != '\0') {

      uStack_140 = (BSTR)0x0;

      piVar14 = piVar1 + 0x25;

      local_144 = piVar1;

      do {

        if (local_138 == (IUnknown *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        pIVar12 = local_138;

        UVar7 = (*local_138->lpVtbl[2].Release)(local_138);

        if ((int)UVar7 < 0) {

          pwStack_174 = 

          L"咋․吻ᐤ贏｢\xffff䒋ဤ쌻ٴࢋｐࡑ䲋․䒍ဤ児岉ᠤᚋｖ᱒尹ဤ萏Ŋ";

          _com_issue_errorex(UVar7,pIVar12,(_GUID *)&DAT_00a86118);

        }

        if ((int)unaff_EBP.lpVtbl <= (int)local_144) goto LAB_007de128;

        if (unaff_ESI != (IUnknown *)0x0) {

          (*unaff_ESI->lpVtbl->Release)(unaff_ESI);

        }

        unaff_ESI = (IUnknown *)0x0;

        pwStack_174 = L"尹ဤ萏Ŋ";

        (*pIVar12->lpVtbl[2].AddRef)(pIVar12);

        if (ppiVar15 != (int **)0x0) {

          pwStack_174 = L"tinType";

          uStack_178 = 0x7de200;

          iVar3 = (*pcVar10)();

          if (iVar3 == 0) goto LAB_007ddaf8;

          unaff_EBP.lpVtbl = (IUnknownVtbl *)&stack0xfffffe98;

          cVar2 = FUN_007b8a60();

          if (local_148._3_1_ == cVar2) {

            iVar3 = (*pcVar10)();

            if (iVar3 == 0) goto LAB_007ddaf8;

            p_Var8 = (_func_5021 *)FUN_007b8a60();

            local_148->QueryInterface = p_Var8;

            iVar3 = (*pcVar10)();

            if (iVar3 == 0) goto LAB_007ddaf8;

            iVar3 = FUN_007b8a60();

            piVar14[-1] = iVar3;

            iVar3 = (*pcVar10)();

            if (iVar3 == 0) goto LAB_007ddaf8;

            unaff_EBP.lpVtbl = (IUnknownVtbl *)&stack0xfffffe94;

            iVar3 = FUN_007b8910();

            *piVar14 = iVar3;

            pwStack_174 = (wchar_t *)0x7de307;

            iVar3 = (*pcVar10)();

            if (iVar3 == 0) goto LAB_007ddaf8;

            if (&stack0x00000000 != (uint8_t *)0x16c) {

              pwStack_174 = L"꿨ﶪ菿ೄ䒁ᰤ\x98";

              (*(code *)in_stack_fffffe94[1].lpVtbl)();

            }

            FUN_007b8de0();

            local_144 = local_144 + 0x26;

          }

        }

        uStack_140 = (BSTR)((int)uStack_140 + 1);

        piVar14 = piVar14 + 0x26;

      } while( true );

    }

    local_11c = &local_134;

    local_134 = (BSTR)0x0;

    local_130 = (IUnknown *)0x0;

    local_12c = 0;

    local_128 = 0;

    local_124 = 0;

    local_120 = 0;

    local_114 = (uint32_t /* width from decompiler */ *)0x0;

    local_118 = 0;

    local_110 = 0;

    local_10c = 0;

    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);

    FUN_004230d0();

    pwStack_174 = L"\xf88bכּ䉼ŪɪŪ䒍✤ᆹ";

    iVar3 = FUN_00422fb0();

    if (-1 < iVar3) {

      pwStack_174 = (wchar_t *)0x7dde41;

      iVar3 = FUN_00422fb0();

      if (-1 < iVar3) {

        pwStack_174 = (wchar_t *)0x0;

        uStack_178 = 0;

        piStack_17c = local_144 + 10;

        ppIStack_180 = &local_138;

        uStack_184 = 0x7dde67;

        iVar3 = FUN_0041a810();

      }

    }

    local_130 = &IStack_fc;

    if (-1 < iVar3) {

      pwStack_174 = L"\xf88bכּ瑼咋㰤Ѫɪ䲍㐤赑⑄륰\x03";

      iVar3 = FUN_004231d0();

      if (-1 < iVar3) {

        pwStack_174 = L"\xf88bכּ卼Ѫͪ咍㐤譒⑔赈⑄륬\x03";

        iVar3 = FUN_004231d0();

        if (-1 < iVar3) {

          pwStack_174 = L"\xf88bכּ㉼咋㰤ɪѪ䒍㐤赐⑄륨\x02";

          iVar3 = FUN_004231d0();

          if (-1 < iVar3) {

            pwStack_174 = L"\xf88bכּᅼ䒋㰤쌻蔏Ƅ";

            iVar3 = FUN_004231d0();

            if ((-1 < iVar3) && (local_128 != 0)) {

              iVar3 = 0;

              if (0 < (int)local_148) {

                puVar11 = (uint *)(piVar1 + 0x25);

                do {

                  iVar6 = FUN_0041c000();

                  if (iVar6 != 0) break;

                  puVar11[-0x25] = (uint)local_100;

                  puVar11[-1] = local_104;

                  *puVar11 = (uint)((short)local_108 == -1);

                  wcscpy((wchar_t *)(puVar11 + -0x22),(wchar_t *)&IStack_fc);

                  iVar3 = iVar3 + 1;

                  puVar11 = puVar11 + 0x26;

                } while (iVar3 < (int)local_148);

              }

              if (local_128 != 0) {

                FUN_00422de0();

                FUN_0041bf70();

              }

              FUN_00423170();

              uStack_10 = 2;

              FUN_0041a3e0();

              pIVar12 = local_13c;

LAB_007de128:

              uStack_10 = 1;

              if (unaff_ESI != (IUnknown *)0x0) {

                (*unaff_ESI->lpVtbl->Release)(unaff_ESI);

              }

              uStack_10 = 0;

              if (pIVar12 == (IUnknown *)0x0) goto LAB_007de154;

              pIVar9 = pIVar12->lpVtbl;

              goto LAB_007de14c;

            }

          }

        }

      }

    }

    FUN_00423170();

    pwStack_174 = (wchar_t *)0x1;

    uStack_178 = 0x7ddf29;

    FUN_007a4480();

    uStack_10 = 2;

    FUN_0041a3e0();

    uStack_10 = 1;

    if (unaff_ESI != (IUnknown *)0x0) {

      (*unaff_ESI->lpVtbl->Release)(unaff_ESI);

    }

    uStack_10 = 0;

    unaff_ESI = local_13c;

  }

  if (unaff_ESI != (IUnknown *)0x0) {

    (*unaff_ESI->lpVtbl->Release)(unaff_ESI);

  }

LAB_007de154:

  SysFreeString(uStack_140);

  ExceptionList = pvStack_18;

  return 0;

}
