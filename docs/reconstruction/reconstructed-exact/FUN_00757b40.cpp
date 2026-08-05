// =============================================================================
// FUN_00757b40
// -----------------------------------------------------------------------------
// Stable ID: aa_00757b40
// Address:   0x00757b40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00757b40 @ 0x00757b40
// Stable ID: aa_00757b40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~208 non-empty decompiler lines.
//  - Control keywords: if×22, while×2, do×1, return×1, goto×1.
//  - Notable callees: FUN_00404d80, FUN_0040add0, FUN_004148e0, FUN_0043f740, FUN_00440230, FUN_00755890, FUN_00757050, FUN_00757660.
//  - Return sites: 1.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall

FUN_00757b40(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,int param_4,ushort *param_5,

            int param_6,float *param_7,float param_8,uint32_t /* width from decompiler */ param_9,float param_10)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  ushort uVar6;

  int iVar7;

  int *piVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  int iVar15;

  void **ppvVar16;

  int iVar17;

  int *piVar18;

  float10 fVar19;

  double dVar20;

  uint32_t /* width from decompiler */ uVar21;

  float local_b4;

  int *local_b0;

  float fStack_6c;

  float fStack_68;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  float fStack_54;

  float fStack_50;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  float fStack_3c;

  float fStack_38;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  float fStack_24;

  float fStack_20;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1bf8;

  if (*(char *)((int)param_3 + 3) != -1) {

    param_9 = 1;

  }

  iVar17 = *(int *)(param_4 + 0x10);

  iVar7 = *param_1;

  fVar10 = (float)(iVar17 * 2);

  if (iVar17 * 2 < 0) {

    fVar10 = fVar10 + _DAT_00aaa5dc;

  }

  fVar11 = (float)iVar17;

  if (iVar17 < 0) {

    fVar11 = fVar11 + _DAT_00aaa5dc;

  }

  fVar11 = fVar11 * param_10 + (float)param_1[1];

  local_b4 = 0.0;

  if (param_7 != (float *)0x0) {

    local_b4 = *param_7;

  }

  uVar6 = *param_5;

  piVar18 = (int *)0x0;

  local_b0 = (int *)0x0;

  ppvVar16 = &local_c;

  local_c = ExceptionList;

  do {

    ExceptionList = ppvVar16;

    if ((uVar6 == 0) || (param_6 == 0)) {

      if (param_7 != (float *)0x0) {

        *param_7 = local_b4;

      }

      ExceptionList = local_c;

      return 0;

    }

    param_5 = param_5 + 1;

    if (uVar6 == 9) {

      fVar19 = (float10)_CIfmod();

      local_b4 = (float)(((float10)local_b4 - fVar19) + (float10)(fVar10 * param_10));

    }

    else {

      if (((piVar18 == (int *)0x0) || (uVar6 < *(ushort *)(piVar18 + 1))) ||

         (*(ushort *)((int)piVar18 + 6) < uVar6)) {

        piVar18 = *(int **)(param_4 + 4);

        iVar17 = (int)*(int **)(param_4 + 8) - (int)piVar18 >> 3;

        while (iVar15 = iVar17, 0 < iVar15) {

          iVar17 = iVar15 / 2;

          if (*(ushort *)((int)piVar18 + iVar17 * 8 + 6) < uVar6) {

            piVar18 = piVar18 + iVar17 * 2 + 2;

            iVar17 = iVar15 + (-1 - iVar17);

          }

        }

        if (((piVar18 == *(int **)(param_4 + 8)) || (uVar6 < *(ushort *)(piVar18 + 1))) ||

           (local_b0 = piVar18, *(ushort *)((int)piVar18 + 6) < uVar6)) {

          local_b0 = (int *)0x0;

          piVar18 = (int *)0x0;

          goto LAB_00757fab;

        }

      }

      if (piVar18 != (int *)0x0) {

        piVar8 = (int *)*piVar18;

        if ((piVar8 != (int *)0x0) && (piVar8[1] = piVar8[1] + 1, piVar8[1] == 1)) {

          (**(code **)(*piVar8 + 4))();

        }

        piVar8 = (int *)*piVar18;

        local_4 = 0;

        if (piVar8 == (int *)0x0) {

          local_4 = 0xffffffff;

        }

        else if ((uVar6 < *(ushort *)(piVar8 + 0x22)) || (*(ushort *)((int)piVar8 + 0x8a) < uVar6))

        {

          piVar1 = piVar8 + 1;

          local_4 = 0xffffffff;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 == 0) {

            (**(code **)(*piVar8 + 8))();

          }

        }

        else {

          iVar17 = FUN_00755890();

          if (uVar6 == 0x20) {

            fVar9 = (float)*(int *)(iVar17 + 0x18);

            if (*(int *)(iVar17 + 0x18) < 0) {

              fVar9 = fVar9 + _DAT_00aaa5dc;

            }

            local_b4 = fVar9 * param_10 + local_b4 + param_8;

          }

          else if (*(int *)(iVar17 + 0x14) == 0) {

            fVar9 = (float)*(int *)(iVar17 + 0x18);

            if (*(int *)(iVar17 + 0x18) < 0) {

              fVar9 = fVar9 + _DAT_00aaa5dc;

            }

            local_b4 = fVar9 * param_10 + local_b4;

          }

          else {

            local_4._0_1_ = 1;

            FUN_004148e0();

            FUN_0043f740();

            dVar20 = floor((double)local_b4);

            fVar9 = (float)dVar20 + (float)*(int *)(iVar17 + 0x1c) + (float)iVar7;

            fVar12 = (float)*(int *)(iVar17 + 0x14);

            if (*(int *)(iVar17 + 0x14) < 0) {

              fVar12 = fVar12 + _DAT_00aaa5dc;

            }

            fVar12 = fVar12 * param_10 + fVar9;

            fVar13 = (float)piVar8[0x1c];

            if (piVar8[0x1c] < 0) {

              fVar13 = fVar13 + _DAT_00aaa5dc;

            }

            fVar13 = fVar11 - fVar13 * param_10;

            fVar14 = (float)*(int *)(iVar17 + 0x18);

            if (*(int *)(iVar17 + 0x18) < 0) {

              fVar14 = fVar14 + _DAT_00aaa5dc;

            }

            uVar2 = *(uint32_t /* width from decompiler */ *)(iVar17 + 4);

            uVar3 = *(uint32_t /* width from decompiler */ *)(iVar17 + 8);

            local_b4 = fVar14 * param_10 + local_b4;

            uVar4 = *(uint32_t /* width from decompiler */ *)(iVar17 + 0xc);

            uVar5 = *(uint32_t /* width from decompiler */ *)(iVar17 + 0x10);

            FUN_00404d80(&fStack_6c,0x18,4,&LAB_00413510);

            uStack_60 = *param_3;

            uVar21 = 4;

            fStack_6c = fVar9;

            fStack_68 = fVar13;

            uStack_5c = uVar2;

            uStack_58 = uVar3;

            fStack_54 = fVar12;

            fStack_50 = fVar13;

            uStack_48 = uStack_60;

            uStack_44 = uVar4;

            uStack_40 = uVar3;

            fStack_3c = fVar12;

            fStack_38 = fVar11;

            uStack_30 = uStack_60;

            uStack_2c = uVar4;

            uStack_28 = uVar5;

            fStack_24 = fVar9;

            fStack_20 = fVar11;

            uStack_18 = uStack_60;

            uStack_14 = uVar2;

            uStack_10 = uVar5;

            FUN_00757660(param_9);

            FUN_00757050(param_2,uVar21);

            local_4 = (uint)local_4._1_3_ << 8;

            FUN_00440230();

          }

          local_4 = 0xffffffff;

          FUN_0040add0();

          piVar18 = local_b0;

        }

      }

    }

LAB_00757fab:

    uVar6 = *param_5;

    ppvVar16 = ExceptionList;

    param_6 = param_6 + -1;

  } while( true );

}
