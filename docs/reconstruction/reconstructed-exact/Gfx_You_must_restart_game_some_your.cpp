// =============================================================================
// Gfx_You_must_restart_game_some_your
// -----------------------------------------------------------------------------
// Stable ID: aa_00819f20
// Address:   0x00819f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_You_must_restart_game_some_your @ 0x00819f20
// Stable ID: aa_00819f20
// Embedded strings (evidence for future rename):
//   - "You must restart the game for some of your changes to take effect."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~477 non-empty decompiler lines.
//  - Control keywords: if×92, return×6, goto×6, while×3, switch×1, do×1, for×1.
//  - Notable callees: FUN_00417f40×6, FUN_00816c50×5, CONCAT31×4, FUN_0075e830×3, FUN_00817050×3, FUN_007fca10×2, FUN_007ff3d0×2, FUN_00816b90×2.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "You must restart the game for some of your changes to take effect."
 * Domain alias of FUN_00819f20 (FUN_* retained)
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



uint32_t /* width from decompiler */ __thiscall Gfx_You_must_restart_game_some_your(int param_1,int param_2,uint param_3)



{

  bool bVar1;

  bool bVar2;

  char cVar3;

  char cVar4;

  int iVar5;

  uint uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint uVar9;

  int *piVar10;

  uint uVar11;

  bool bVar12;

  float10 fVar13;

  float fVar14;

  float fVar15;

  uint32_t /* width from decompiler */ in_stack_ffffffe0;

  

  uVar9 = param_3;

  switch(param_3) {

  case 40000:

    if (param_2 == 8) {

      FUN_007fca10();

      return 1;

    }

    break;

  case 0x9c41:

    if (param_2 != 8) break;

    param_3 = param_3 & 0xffffff00;

    bVar2 = false;

    bVar1 = false;

    if (*(int *)(param_1 + 0xe8c) != 0) {

      iVar5 = FUN_00816b90();

      iVar7 = *(int *)(param_1 + 0xf0c);

      uVar11 = 0;

      while( true ) {

        if ((iVar7 == 0) || ((uint)(*(int *)(param_1 + 0xf10) - iVar7 >> 2) <= uVar11))

        goto LAB_00819ff7;

        if ((*(int *)(*(int *)(param_1 + 0xf0c) + uVar11 * 4) == iVar5) &&

           (uVar6 = FUN_00417fe0(), uVar11 < uVar6)) break;

        uVar11 = uVar11 + 1;

      }

      piVar10 = (int *)(*(int *)(param_1 + 0xefc) + uVar11 * 8);

      if ((*piVar10 != DAT_00d1b258) || (piVar10[1] != DAT_00d1b25c)) {

        DAT_00d1b258 = *piVar10;

        DAT_00d1b25c = *(int *)(*(int *)(param_1 + 0xefc) + uVar11 * 8 + 4);

        bVar1 = true;

      }

    }

LAB_00819ff7:

    if ((*(int *)(param_1 + 0xe90) != 0) && (cVar3 = FUN_00417f40(), DAT_00d1b201 == cVar3)) {

      cVar3 = FUN_00417f40();

      DAT_00d1b201 = cVar3 == '\0';

      bVar1 = true;

    }

    if ((*(int *)(param_1 + 0xe94) != 0) && (cVar3 = FUN_00417f40(), DAT_00d1b202 != cVar3)) {

      DAT_00d1b202 = FUN_00417f40();

      bVar1 = true;

    }

    bVar12 = false;

    if ((*(int *)(param_1 + 0xe98) == 0) || (cVar3 = FUN_00417f40(), cVar3 == DAT_00d1b264)) {

LAB_0081a0aa:

      if (DAT_00d1b264 != '\0') goto LAB_0081a0b3;

    }

    else {

      uVar8 = 0x81a079;

      DAT_00d1b264 = FUN_00417f40();

      param_3._1_3_ = SUB43(uVar9,1);

      param_3 = CONCAT31(param_3._1_3_,1);

      bVar2 = true;

      bVar12 = true;

      if (DAT_00d1b264 == '\0') {

        FUN_007aa3e0();

        FUN_007ff3d0(in_stack_ffffffe0,uVar8);

        bVar12 = true;

        goto LAB_0081a0aa;

      }

LAB_0081a0b3:

      if ((*(int *)(param_1 + 0xe9c) != 0) &&

         ((fVar13 = (float10)FUN_00816c50(), (float10)DAT_00d1b260 != fVar13 || (bVar12)))) {

        param_3 = CONCAT31(param_3._1_3_,1);

        bVar2 = true;

        uVar8 = 0x81a0e6;

        fVar13 = (float10)FUN_00816c50();

        DAT_00d1b260 = (float)fVar13;

        if ((DAT_00d1b780 != (int *)0x0) && (*DAT_00d1b780 == DAT_00d1b778)) {

          FUN_007fcc80(1);

          FUN_007ff3d0(in_stack_ffffffe0,uVar8);

        }

      }

    }

    if (*(int *)(param_1 + 0xea0) != 0) {

      iVar7 = FUN_00816b90();

      uVar9 = 0;

      while( true ) {

        iVar5 = *(int *)(param_1 + 0xf28);

        if ((iVar5 == 0) || ((uint)(*(int *)(param_1 + 0xf2c) - iVar5 >> 2) <= uVar9))

        goto LAB_0081a1a0;

        if ((*(int *)(iVar5 + uVar9 * 4) == iVar7) &&

           ((iVar5 != 0 && (uVar9 < (uint)(*(int *)(param_1 + 0xf2c) - iVar5 >> 2))))) break;

        uVar9 = uVar9 + 1;

      }

      if (DAT_00afa2dc != uVar9) {

        if (DAT_00d1b644 != 0) {

          if (uVar9 == 0) {

            *(uint8_t *)(*(int *)(DAT_00d1b644 + 0xe894) + 0x78) = 0;

          }

          else {

            *(uint8_t *)(*(int *)(DAT_00d1b644 + 0xe894) + 0x78) = 1;

          }

        }

        bVar1 = true;

        DAT_00afa2dc = uVar9;

      }

    }

LAB_0081a1a0:

    iVar7 = *(int *)(param_1 + 0xea4);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        cVar3 = '\0';

      }

      else {

        cVar3 = (**(code **)(**(int **)(iVar7 + 0x708) + 0x3bc))();

      }

      if (DAT_00aefa54 != cVar3) {

        if (*(int *)(*(int *)(param_1 + 0xea4) + 0x708) == 0) {

          DAT_00aefa54 = '\0';

        }

        else {

          DAT_00aefa54 = (**(code **)(**(int **)(*(int *)(param_1 + 0xea4) + 0x708) + 0x3bc))();

        }

        param_3 = CONCAT31(param_3._1_3_,1);

        bVar2 = true;

      }

    }

    iVar7 = *(int *)(param_1 + 0xea8);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        cVar3 = '\0';

      }

      else {

        cVar3 = (**(code **)(**(int **)(iVar7 + 0x708) + 0x3bc))();

      }

      if (DAT_00aef950 != cVar3) {

        if (*(int *)(*(int *)(param_1 + 0xea8) + 0x708) == 0) {

          DAT_00aef950 = '\0';

        }

        else {

          DAT_00aef950 = (**(code **)(**(int **)(*(int *)(param_1 + 0xea8) + 0x708) + 0x3bc))();

        }

        bVar1 = true;

      }

    }

    iVar7 = *(int *)(param_1 + 0xec8);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        cVar3 = '\0';

      }

      else {

        cVar3 = (**(code **)(**(int **)(iVar7 + 0x708) + 0x3bc))();

      }

      if (DAT_00d1b20e != cVar3) {

        if (*(int *)(*(int *)(param_1 + 0xec8) + 0x708) == 0) {

          DAT_00d1b20e = '\0';

        }

        else {

          DAT_00d1b20e = (**(code **)(**(int **)(*(int *)(param_1 + 0xec8) + 0x708) + 0x3bc))();

        }

        param_3 = CONCAT31(param_3._1_3_,DAT_00d1b20e);

        FUN_0092f190(param_3);

        bVar2 = true;

      }

    }

    cVar3 = DAT_00d1b210;

    iVar7 = *(int *)(param_1 + 0xecc);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        cVar4 = '\0';

      }

      else {

        cVar4 = (**(code **)(**(int **)(iVar7 + 0x708) + 0x3bc))();

      }

      if (cVar3 != cVar4) {

        if (*(int *)(*(int *)(param_1 + 0xecc) + 0x708) != 0) {

          (**(code **)(**(int **)(*(int *)(param_1 + 0xecc) + 0x708) + 0x3bc))();

        }

        FUN_0092dd80();

        bVar2 = true;

      }

    }

    iVar7 = *(int *)(param_1 + 0xed4);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        cVar3 = '\0';

      }

      else {

        cVar3 = (**(code **)(**(int **)(iVar7 + 0x708) + 0x3bc))();

      }

      if (DAT_00d1b206 != cVar3) {

        if (*(int *)(*(int *)(param_1 + 0xed4) + 0x708) == 0) {

          DAT_00d1b206 = '\0';

        }

        else {

          DAT_00d1b206 = (**(code **)(**(int **)(*(int *)(param_1 + 0xed4) + 0x708) + 0x3bc))();

        }

        bVar1 = true;

      }

    }

    iVar7 = *(int *)(param_1 + 0xed0);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        cVar3 = '\0';

      }

      else {

        cVar3 = (**(code **)(**(int **)(iVar7 + 0x708) + 0x3bc))();

      }

      if (DAT_00d1b21e != cVar3) {

        if (*(int *)(*(int *)(param_1 + 0xed0) + 0x708) == 0) {

          DAT_00d1b21e = '\0';

        }

        else {

          DAT_00d1b21e = (**(code **)(**(int **)(*(int *)(param_1 + 0xed0) + 0x708) + 0x3bc))();

        }

        DAT_00b035c8 = DAT_00d1b21e == '\0';

        bVar2 = true;

      }

    }

    iVar7 = *(int *)(param_1 + 0xee4);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        iVar7 = -1;

      }

      else {

        iVar7 = (**(code **)(**(int **)(iVar7 + 0x708) + 0x464))();

      }

      bVar12 = DAT_00d1a851 != '\0';

      uVar9 = 3;

      if (bVar12) {

        uVar9 = 2;

      }

      uVar11 = 0;

      if (uVar9 != 0) {

        piVar10 = (int *)(param_1 + 0xf18);

        do {

          if (*piVar10 == iVar7) {

            if ((uint)DAT_00d1b24d - (uint)bVar12 != uVar11) {

              DAT_00d1b24d = bVar12 + (char)uVar11;

              bVar1 = true;

              if ((DAT_00d1a851 != '\0') && (DAT_00d1b24d == 0)) {

                DAT_00d1b24d = 1;

              }

              if ((DAT_00d1b780 == (int *)0x0) ||

                 (DAT_00d1a8f5 = DAT_00d1b24d, *DAT_00d1b780 != DAT_00d1b778)) {

                DAT_00d1a8f5 = DAT_00d1a851 != '\0';

              }

            }

            break;

          }

          uVar11 = uVar11 + 1;

          piVar10 = piVar10 + 1;

        } while (uVar11 < uVar9);

      }

    }

    iVar7 = *(int *)(param_1 + 0xee8);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        fVar14 = 0.0;

      }

      else {

        fVar13 = (float10)(**(code **)(**(int **)(iVar7 + 0x708) + 0x458))();

        fVar14 = (float)fVar13;

      }

      fVar14 = fVar14 * DAT_00aaa68c + DAT_00a0f298;

      if (DAT_00d1b268 != fVar14) {

        DAT_00d1b268 = fVar14;

        FUN_0075e830(*(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x28));

        bVar2 = true;

      }

    }

    iVar7 = *(int *)(param_1 + 0xeec);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        fVar14 = 0.0;

      }

      else {

        fVar13 = (float10)(**(code **)(**(int **)(iVar7 + 0x708) + 0x458))();

        fVar14 = (float)fVar13;

      }

      if (*(float *)(param_1 + 0xf34) != fVar14) {

        if (*(int *)(*(int *)(param_1 + 0xeec) + 0x708) == 0) {

          DAT_00b036ac = 0.0;

        }

        else {

          fVar13 = (float10)(**(code **)(**(int **)(*(int *)(param_1 + 0xeec) + 0x708) + 0x458))();

          DAT_00b036ac = (float)fVar13;

        }

        bVar2 = true;

      }

    }

    iVar7 = *(int *)(param_1 + 0xef4);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        fVar14 = 0.0;

      }

      else {

        fVar13 = (float10)(**(code **)(**(int **)(iVar7 + 0x708) + 0x458))();

        fVar14 = (float)fVar13;

      }

      if (*(float *)(param_1 + 0xf3c) != fVar14) {

        if (*(int *)(*(int *)(param_1 + 0xef4) + 0x708) == 0) {

          DAT_00af06e0 = 0.0;

        }

        else {

          fVar13 = (float10)(**(code **)(**(int **)(*(int *)(param_1 + 0xef4) + 0x708) + 0x458))();

          DAT_00af06e0 = (float)fVar13;

        }

        bVar2 = true;

      }

    }

    iVar7 = *(int *)(param_1 + 0xed8);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        cVar3 = '\0';

      }

      else {

        cVar3 = (**(code **)(**(int **)(iVar7 + 0x708) + 0x3bc))();

      }

      if (DAT_00d1a8f2 != cVar3) {

        if (*(int *)(*(int *)(param_1 + 0xed8) + 0x708) != 0) {

          (**(code **)(**(int **)(*(int *)(param_1 + 0xed8) + 0x708) + 0x3bc))();

        }

        FUN_00934420();

        bVar2 = true;

      }

    }

    iVar7 = *(int *)(param_1 + 0xedc);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        cVar3 = '\0';

      }

      else {

        cVar3 = (**(code **)(**(int **)(iVar7 + 0x708) + 0x3bc))();

      }

      if (DAT_00d1b215 != cVar3) {

        if (*(int *)(*(int *)(param_1 + 0xedc) + 0x708) == 0) {

          DAT_00d1b215 = '\0';

        }

        else {

          DAT_00d1b215 = (**(code **)(**(int **)(*(int *)(param_1 + 0xedc) + 0x708) + 0x3bc))();

        }

        if (DAT_00d1b215 == '\0') {

          FUN_009339a0();

        }

        else {

          FUN_00933a10();

        }

        bVar2 = true;

      }

    }

    iVar7 = *(int *)(param_1 + 0xee0);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        cVar3 = '\0';

      }

      else {

        cVar3 = (**(code **)(**(int **)(iVar7 + 0x708) + 0x3bc))();

      }

      if (DAT_00d1b220 != cVar3) {

        if (*(int *)(*(int *)(param_1 + 0xee0) + 0x708) == 0) {

          DAT_00d1b220 = '\0';

        }

        else {

          DAT_00d1b220 = (**(code **)(**(int **)(*(int *)(param_1 + 0xee0) + 0x708) + 0x3bc))();

        }

        bVar2 = true;

      }

    }

    iVar7 = *(int *)(param_1 + 0xeac);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        fVar14 = 0.0;

      }

      else {

        fVar13 = (float10)(**(code **)(**(int **)(iVar7 + 0x708) + 0x458))();

        fVar14 = (float)fVar13;

      }

      fVar14 = (*(float *)(param_1 + 0xeb4) - *(float *)(param_1 + 0xeb0)) * fVar14 +

               *(float *)(param_1 + 0xeb0);

      if (DAT_00afa2e0 != fVar14) {

        _DAT_00afa2e4 = DAT_00b01a9c + fVar14;

        bVar2 = true;

        DAT_00afa2e0 = fVar14;

      }

    }

    iVar7 = *(int *)(param_1 + 0xeb8);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        fVar14 = 0.0;

      }

      else {

        fVar13 = (float10)(**(code **)(**(int **)(iVar7 + 0x708) + 0x458))();

        fVar14 = (float)fVar13;

      }

      fVar14 = (*(float *)(param_1 + 0xec0) - *(float *)(param_1 + 0xebc)) * fVar14 +

               *(float *)(param_1 + 0xebc);

      if (DAT_00d1a540 != fVar14) {

        bVar2 = true;

        DAT_00d1a540 = fVar14;

      }

    }

    fVar14 = DAT_00afa2ec;

    iVar7 = *(int *)(param_1 + 0xec4);

    if (iVar7 != 0) {

      if (*(int *)(iVar7 + 0x708) == 0) {

        fVar15 = 0.0;

      }

      else {

        fVar13 = (float10)(**(code **)(**(int **)(iVar7 + 0x708) + 0x458))();

        fVar15 = (float)fVar13;

      }

      if (fVar14 != fVar15) {

        if (*(int *)(*(int *)(param_1 + 0xec4) + 0x708) == 0) {

LAB_0081a882:

          DAT_00afa2ec = g_flMsToSeconds_Inferred;

        }

        else {

          fVar13 = (float10)(**(code **)(**(int **)(*(int *)(param_1 + 0xec4) + 0x708) + 0x458))();

          DAT_00afa2ec = (float)fVar13;

          if ((float)fVar13 == g_flZero) goto LAB_0081a882;

        }

        bVar2 = true;

      }

    }

    if (((bVar1) || (bVar2)) && (FUN_0095c5a0(), bVar1)) {

      FUN_007fdfb0(&DAT_00d1a840,

                   "You must restart the game for some of your changes to take effect.",0xffffffff,1

                   ,0);

      return 1;

    }

LAB_0081a9d7:

    FUN_007fca10();

    FUN_007fef20(0x29,1,0);

    return 1;

  case 0x9c42:

    if (param_2 != 8) break;

    FUN_0075e830(*(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x28));

    if (*(float *)(param_1 + 0xf34) != DAT_00b036ac) {

      DAT_00b036ac = *(float *)(param_1 + 0xf34);

    }

    DAT_00af06e0 = *(float *)(param_1 + 0xf3c);

    goto LAB_0081a9d7;

  case 0x9c43:

    if ((param_2 == 0x1a) && (*(int *)(param_1 + 0xee8) != 0)) {

      FUN_00816c50();

      FUN_0075e830(*(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x28));

    }

    break;

  case 0x9c44:

    if ((param_2 == 0x1a) && (*(int *)(param_1 + 0xeec) != 0)) {

      fVar13 = (float10)FUN_00816c50();

      DAT_00b036ac = (float)fVar13;

      uVar8 = FUN_00817050(0x1a,param_3);

      return uVar8;

    }

    break;

  case 0x9c4c:

    if ((param_2 == 0x1a) && (*(int *)(param_1 + 0xef4) != 0)) {

      fVar13 = (float10)FUN_00816c50();

      DAT_00af06e0 = (float)fVar13;

      uVar8 = FUN_00817050(0x1a,param_3);

      return uVar8;

    }

  }

  uVar8 = FUN_00817050(param_2,param_3);

  return uVar8;

}
