// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvBroadca_00797e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00797e20
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast
// Address:   0x00797e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~343 non-empty decompiler lines.
//  - Control keywords: if×44, return×12, while×6, do×5, goto×4.
//  - Notable callees: begin×6, FUN_00797440×4, FUN_00426f80×3, FUN_00427150×3, FUN_00797530×3, end×3, push_back×3, CONCAT31×2.
//  - Return sites: 12.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvBroadca_00797e20(int param_1,uint param_2)



{

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_> *this;

  bool bVar1;

  void *pvVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  wchar_t wVar7;

  int iVar8;

  short *psVar9;

  int iVar10;

  wchar_t *pwVar11;

  uint uVar12;

  float fVar13;

  int local_c4;

  int local_c0;

  int local_bc;

  int *local_b8;

  float local_b4;

  int local_b0;

  uint8_t local_ac [8];

  void *local_a4;

  int local_a0;

  uint32_t /* width from decompiler */ local_9c;

  int local_98;

  uint8_t local_94 [8];

  uint8_t local_8c [4];

  float local_88;

  int local_84;

  uint32_t /* width from decompiler */ local_78;

  basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

  local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pvVar2 = ExceptionList;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b13d2;

  local_c = ExceptionList;

  bVar1 = false;

  if (((short)param_2 == 0x5c) && (*(char *)(param_1 + 0xb6) != '\0')) {

    if (*(char *)(param_1 + 0xb5) == '\0') {

      *(uint8_t *)(param_1 + 0xb5) = 1;

      return;

    }

LAB_00797e7b:

    if ((param_2 & 0xffff) == 0x6e) {

      param_2 = 10;

    }

    else if ((param_2 & 0xffff) == 0x74) {

      param_2 = 9;

    }

    ExceptionList = &local_c;

    *(uint8_t *)(param_1 + 0xb5) = 0;

  }

  else {

    ExceptionList = &local_c;

    if (*(char *)(param_1 + 0xb5) != '\0') goto LAB_00797e7b;

  }

  wVar7 = (wchar_t)param_2;

  if ((*(char *)(param_1 + 0xb4) != '\0') && (wVar7 == L' ')) {

    ExceptionList = pvVar2;

    return;

  }

  if (wVar7 == L'\n') {

    *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0xa8) + *(float *)(param_1 + 0xa4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

    FUN_00797530(0);

    *(uint8_t *)(param_1 + 0xb4) = 0;

    FUN_00797440();

    ExceptionList = local_c;

    return;

  }

  if (*(char *)(param_1 + 0xb4) != '\0') {

    *(uint8_t *)(param_1 + 0xb4) = 0;

    FUN_00797440();

  }

  if (wVar7 == L' ') {

    *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0xa8) + *(float *)(param_1 + 0xa4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

  }

  if (*(int *)(param_1 + 0xc0) == 0) {

    if (*(int *)(param_1 + 200) == 0) {

      ExceptionList = local_c;

      return;

    }

    FUN_00427c10(*(uint32_t /* width from decompiler */ *)(param_1 + 200),local_94,param_2);

    local_4 = 0;

    bVar1 = true;

  }

  FUN_0040aeb0(&local_b8);

  local_4 = 2;

  if (bVar1) {

    FUN_0040add0();

  }

  if (local_b8 == (int *)0x0) {

LAB_00798528:

    local_4 = 0xffffffff;

    FUN_0040add0();

    ExceptionList = local_c;

    return;

  }

  iVar3 = local_b8[0x1f];

  fVar13 = (float)local_b8[0x1f];

  if (iVar3 < 0) {

    fVar13 = fVar13 + _DAT_00aaa5dc;

  }

  if (*(float *)(param_1 + 0xac) < fVar13 * *(float *)(param_1 + 0xb8)) {

    fVar13 = (float)iVar3;

    if (iVar3 < 0) {

      fVar13 = fVar13 + _DAT_00aaa5dc;

    }

    *(float *)(param_1 + 0xac) = fVar13 * *(float *)(param_1 + 0xb8);

    local_c0 = iVar3;

  }

  if (((ushort)wVar7 < (ushort)*(wchar_t *)(local_b8 + 0x22)) ||

     ((ushort)*(wchar_t *)((int)local_b8 + 0x8a) < (ushort)wVar7)) goto LAB_00798528;

  iVar3 = FUN_00755890(param_2);

  local_c0 = *(int *)(iVar3 + 0x18);

  local_b4 = (float)local_c0;

  if (local_c0 < 0) {

    local_b4 = local_b4 + _DAT_00aaa5dc;

  }

  local_b4 = local_b4 * *(float *)(param_1 + 0xb8);

  if (*(float *)(param_1 + 0xa0) < local_b4) {

    *(float *)(param_1 + 0xa0) = local_b4;

  }

  fVar13 = *(float *)(param_1 + 0xa8) + local_b4;

  if (fVar13 < *(float *)(param_1 + 0xa0) || fVar13 == *(float *)(param_1 + 0xa0)) {

    fVar13 = *(float *)(param_1 + 0xa8) + local_b4 + *(float *)(param_1 + 0xa4);

    if (fVar13 < *(float *)(param_1 + 0xa0) || fVar13 == *(float *)(param_1 + 0xa0))

    goto LAB_0079807f;

    if (g_flZero < *(float *)(param_1 + 0xa8)) {

      std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

      basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                (local_28);

      local_a4 = (void *)0x0;

      local_a0 = 0;

      local_9c = 0;

      local_4 = CONCAT31(local_4._1_3_,4);

      iVar3 = FUN_004270b0();

      this = (basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

              *)(param_1 + 0xc);

      iVar8 = iVar3 + -1;

      local_bc = 0;

      bVar1 = true;

      piVar4 = (int *)std::

                      basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                      ::end(this);

      psVar9 = (short *)(*piVar4 + -2);

      piVar4 = (int *)std::

                      basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                      ::begin(this);

      if (psVar9 != (short *)*piVar4) {

        do {

          if (*psVar9 == 0x20) break;

          local_bc = local_bc + 1;

          psVar9 = psVar9 + -1;

          piVar4 = (int *)std::

                          basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                          ::begin(this);

        } while (psVar9 != (short *)*piVar4);

      }

      if (-1 < iVar8) {

        iVar10 = *(int *)(param_1 + 0x94);

        iVar5 = iVar8 * 0x60;

        iVar6 = iVar8;

        do {

          if ((*(int *)(iVar5 + 0x10 + iVar10) != 0) || (*(char *)(iVar5 + 0x40 + iVar10) != '\0'))

          {

            iVar10 = *(int *)(param_1 + 0x20) - *(int *)(iVar6 * 0x60 + 4 + iVar10);

            if (iVar10 < local_bc) {

              local_bc = iVar10;

            }

            break;

          }

          iVar6 = iVar6 + -1;

          iVar5 = iVar5 + -0x60;

        } while (-1 < iVar6);

      }

      iVar10 = *(int *)(param_1 + 0x20) - local_bc;

      local_98 = iVar10;

      if (*(int *)(*(int *)(param_1 + 0x94) + 4 + iVar8 * 0x60) == *(int *)(param_1 + 0x20)) {

        FUN_00426f80();

        local_88 = local_88 - *(float *)(param_1 + 0xa4);

        if (iVar10 < local_84) {

          local_84 = local_84 - iVar10;

        }

        else {

          local_84 = 0;

        }

        FUN_00427150(&local_c0,0,&local_88);

        iVar8 = iVar3 + -2;

      }

      piVar4 = (int *)std::

                      basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                      ::end((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                             *)(param_1 + 0xc));

      pwVar11 = (wchar_t *)(*piVar4 + -2);

      local_c4 = 0;

      piVar4 = (int *)std::

                      basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                      ::begin((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                               *)(param_1 + 0xc));

      if (pwVar11 != (wchar_t *)*piVar4) {

        local_b0 = iVar8 * 0x60;

        do {

          if (local_bc <= local_c4) break;

          bVar1 = true;

          std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

          ::push_back(local_28,*pwVar11);

          std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

          ::erase((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                   *)(param_1 + 0xc),local_8c,pwVar11);

          if (-1 < iVar8) {

            iVar3 = iVar8;

            iVar10 = local_b0;

            do {

              if (*(int *)(iVar10 + 4 + *(int *)(param_1 + 0x94)) == *(int *)(param_1 + 0x20)) {

                FUN_00426f80();

                local_88 = local_88 - *(float *)(param_1 + 0xa4);

                if (local_98 < local_84) {

                  local_84 = local_84 - local_98;

                }

                else {

                  local_84 = 0;

                }

                FUN_00427150(local_ac,local_a4,&local_88);

                iVar8 = iVar8 + -1;

                local_b0 = local_b0 + -0x60;

                bVar1 = false;

                break;

              }

              iVar3 = iVar3 + -1;

              iVar10 = iVar10 + -0x60;

            } while (-1 < iVar3);

          }

          local_c4 = local_c4 + 1;

          pwVar11 = pwVar11 + -1;

          piVar4 = (int *)std::

                          basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                          ::begin((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                                   *)(param_1 + 0xc));

        } while (pwVar11 != (wchar_t *)*piVar4);

      }

      if ((-1 < iVar8) && (bVar1)) {

        FUN_00426f80();

        local_84 = 0;

        local_78 = 0;

        local_88 = 0.0;

        FUN_00427150(local_ac,local_a4,&local_88);

      }

      FUN_00797530(0);

      *(uint8_t *)(param_1 + 0xb4) = 0;

      FUN_00797440();

      FUN_00427210(0);

      piVar4 = (int *)std::

                      basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                      ::end(local_28);

      pwVar11 = (wchar_t *)(*piVar4 + -2);

      piVar4 = (int *)std::

                      basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                      ::begin(local_28);

      if (pwVar11 != (wchar_t *)(*piVar4 + -2)) {

        do {

          std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

          ::push_back((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                       *)(param_1 + 0xc),*pwVar11);

          pwVar11 = pwVar11 + -1;

          piVar4 = (int *)std::

                          basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                          ::begin(local_28);

        } while (pwVar11 != (wchar_t *)(*piVar4 + -2));

      }

      pvVar2 = local_a4;

      uVar12 = 0;

      while (pvVar2 != (void *)0x0) {

        if ((uint)((local_a0 - (int)pvVar2) / 0x60) <= uVar12) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar2);

        }

        FUN_004270d0();

        uVar12 = uVar12 + 1;

      }

      local_4 = CONCAT31(local_4._1_3_,2);

      std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

      ~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

                (local_28);

      goto LAB_0079807f;

    }

  }

  else {

    *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0xa8) + *(float *)(param_1 + 0xa4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

  }

  FUN_00797530(0);

LAB_0079807f:

  if (*(char *)(param_1 + 0xb4) != '\0') {

    if (wVar7 == L' ') {

      local_4 = 0xffffffff;

      if (local_b8 == (int *)0x0) {

        ExceptionList = local_c;

        return;

      }

      local_b8[1] = local_b8[1] + -1;

      if (local_b8[1] != 0) {

        ExceptionList = local_c;

        return;

      }

      (**(code **)(*local_b8 + 8))();

      ExceptionList = local_c;

      return;

    }

    *(uint8_t *)(param_1 + 0xb4) = 0;

    FUN_00797440();

  }

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  push_back((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_> *

            )(param_1 + 0xc),wVar7);

  fVar13 = *(float *)(param_1 + 0xa8) + local_b4;

  *(float *)(param_1 + 0xa8) = fVar13;

  if (wVar7 == L' ') {

    *(int *)(param_1 + 0xb0) = *(int *)(param_1 + 0xb0) + 1;

    *(float *)(param_1 + 0xa4) = fVar13 + *(float *)(param_1 + 0xa4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

  }

  local_4 = 0xffffffff;

  if (local_b8 == (int *)0x0) {

    ExceptionList = local_c;

    return;

  }

  local_b8[1] = local_b8[1] + -1;

  if (local_b8[1] != 0) {

    ExceptionList = local_c;

    return;

  }

  (**(code **)(*local_b8 + 8))();

  ExceptionList = local_c;

  return;

}
