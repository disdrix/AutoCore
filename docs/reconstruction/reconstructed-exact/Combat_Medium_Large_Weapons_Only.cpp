// =============================================================================
// Combat_Medium_Large_Weapons_Only
// -----------------------------------------------------------------------------
// Stable ID: aa_0087d810
// Address:   0x0087d810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Combat_Medium_Large_Weapons_Only @ 0x0087d810
// Stable ID: aa_0087d810
// Embedded strings (evidence for future rename):
//   - "(Small Weapons Only)"
//   - "(Medium & Large Weapons Only)"
//   - "%s\n"
//   - "%s: %g\n%s: %g"
//   - "Class Bonus"
//   - "Weapon Base"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~975 non-empty decompiler lines.
//  - Control keywords: if×73, return×6, do×5, while×5, goto×2, switch×1.
//  - Notable callees: FUN_007a6de0×85, sprintf×37, FUN_0056b340×12, FUN_00514050×10, FUN_00569dc0×9, FUN_0040dab0×8, FUN_00412cd0×8, FUN_0056a680×8.
//  - Strings: "(Small Weapons Only)"; "(Medium & Large Weapons Only)"; "%s\n"; "%s: %g\n%s: %g".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "(Medium & Large Weapons Only)"
 * Domain alias of FUN_0087d810 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Combat_Medium_Large_Weapons_Only(int param_1)



{

  char cVar1;

  int iVar2;

  float *pfVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  float fVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  int iVar9;

  uint32_t /* width from decompiler */ uVar10;

  char *pcVar11;

  short *psVar12;

  int *piVar13;

  float unaff_EBX;

  int unaff_EBP;

  int *unaff_ESI;

  code *pcVar14;

  float10 fVar15;

  float10 fVar16;

  float10 fVar17;

  float fVar18;

  double dVar19;

  double dVar20;

  double dVar21;

  uint8_t *puVar22;

  int *piVar23;

  float fVar24;

  float fVar25;

  uint64_t uVar26;

  uint16_t *puVar27;

  uint64_t uVar28;

  float fStack_140;

  float fStack_13c;

  char *pcStack_138;

  char acStack_134 [3];

  uint8_t uStack_131;

  float fStack_130;

  float fStack_12c;

  float fStack_128;

  float fStack_124;

  float fStack_120;

  int iStack_11c;

  int iStack_118;

  int iStack_114;

  float fStack_110;

  float fStack_10c;

  float afStack_108 [2];

  char acStack_100 [256];

  

  FUN_007a69d0();

  pcVar14 = sprintf_exref;

  if (DAT_00d1b644 == 0) {

    return;

  }

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if (*(int *)(param_1 + 0x514) == 0) {

    if (*(int *)(param_1 + 0x55c) != 0) {

      iVar4 = **(int **)(param_1 + 0x55c);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x1d8))();

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x560) != 0) {

      iVar4 = **(int **)(param_1 + 0x560);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x1d8))();

      (**(code **)(**(int **)(param_1 + 0x560) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x564) != 0) {

      iVar4 = **(int **)(param_1 + 0x564);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x1d8))();

      (**(code **)(**(int **)(param_1 + 0x564) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x568) != 0) {

      iVar4 = **(int **)(param_1 + 0x568);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x1d8))();

      (**(code **)(**(int **)(param_1 + 0x568) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x56c) != 0) {

      iVar4 = **(int **)(param_1 + 0x56c);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x1d8))();

      (**(code **)(**(int **)(param_1 + 0x56c) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x570) != 0) {

      iVar4 = **(int **)(param_1 + 0x570);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x1d8))();

      (**(code **)(**(int **)(param_1 + 0x570) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x574) != 0) {

      iVar4 = **(int **)(param_1 + 0x574);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x1d8))();

      (**(code **)(**(int **)(param_1 + 0x574) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x578) != 0) {

      iVar4 = **(int **)(param_1 + 0x578);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x1d8))();

      (**(code **)(**(int **)(param_1 + 0x578) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x57c) != 0) {

      iVar4 = **(int **)(param_1 + 0x57c);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x1d8))();

      (**(code **)(**(int **)(param_1 + 0x57c) + 0x34c))();

    }

    if (*(int *)(param_1 + 0x580) == 0) {

      return;

    }

    iVar4 = **(int **)(param_1 + 0x580);

    FUN_007a6de0();

    (**(code **)(iVar4 + 0x1d8))();

    (**(code **)(**(int **)(param_1 + 0x580) + 0x34c))();

    return;

  }

  if (*(int *)(param_1 + 0x55c) != 0) {

    (**(code **)(**(int **)(param_1 + 0x55c) + 0x268))();

    iVar4 = **(int **)(*(int *)(param_1 + 0x514) + 0x260);

    if (iVar4 == 0) {

      pcVar11 = (char *)FUN_007a6de0();

      sprintf(acStack_100,pcVar11);

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x224))();

      iVar4 = *(int *)(param_1 + 0x514);

      if ((iVar4 != 0) &&

         (*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c) != 0)) {

        (**(code **)(**(int **)(param_1 + 0x55c) + 0x250))(&DAT_00a15104);

        cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x514) + 4) + 4) +

                                            0xac + *(int *)(param_1 + 0x514)) + 0x3c) + 0x714);

        uVar5 = 0xffbbbbbb;

        if (cVar1 == '\x01') {

          iVar4 = **(int **)(param_1 + 0x55c);

          uVar7 = FUN_007a6de0("(Small Weapons Only)",0xffffffff);

        }

        else if (cVar1 == '\x02') {

          iVar4 = **(int **)(param_1 + 0x55c);

          uVar7 = FUN_007a6de0("(Medium & Large Weapons Only)",0xffffffff);

        }

        else {

          iVar4 = **(int **)(param_1 + 0x55c);

          if (cVar1 == '\x03') {

            uVar7 = FUN_007a6de0("(Medium & Large Weapons Only)",0xffffffff);

          }

          else {

            uVar7 = FUN_007a6de0("(Medium & Large Weapons Only)",0xffffffff);

          }

        }

        (**(code **)(iVar4 + 0x224))(uVar7,uVar5);

      }

    }

    else {

      fStack_13c = *(float *)(DAT_00d1b644 + 0xe83c);

      FUN_00412cd0();

      fStack_13c = (float)FUN_0040dab0();

      iVar2 = FUN_0056b340();

      fStack_110 = (float)((int)fStack_13c + iVar2);

      fStack_13c = *(float *)(DAT_00d1b644 + 0xe83c);

      FUN_00412cd0();

      fStack_13c = (float)FUN_0040dab0();

      iStack_11c = FUN_0056b340();

      iStack_11c = (int)fStack_13c + iStack_11c;

      uStack_131 = *(uint8_t *)

                    (*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                      DAT_00d1b6d8) + 0x3c) + 0x531);

      fStack_13c = (float)*(uint32_t /* width from decompiler */ *)(DAT_00d1b644 + 0xe83c);

      FUN_00412cd0();

      fStack_13c = (float)FUN_0040dab0();

      iStack_114 = FUN_0056b340();

      iStack_114 = (int)fStack_13c + iStack_114;

      uStack_131 = *(uint8_t *)

                    (*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                      DAT_00d1b6d8) + 0x3c) + 0x531);

      fStack_13c = (float)*(uint32_t /* width from decompiler */ *)(DAT_00d1b644 + 0xe83c);

      FUN_00412cd0();

      fStack_13c = (float)FUN_0040dab0();

      iStack_118 = FUN_0056b340();

      iStack_118 = (int)fStack_13c + iStack_118;

      fStack_12c = 0.0;

      fStack_128 = 0.0;

      fStack_124 = 0.0;

      pcStack_138 = (char *)0x17c;

      do {

        fStack_12c = (float)((int)fStack_12c +

                            (int)*(short *)((int)pcStack_138 + 0x18 + DAT_00d1b6d8));

        fStack_128 = (float)((int)fStack_128 + (int)*(short *)((int)pcStack_138 + DAT_00d1b6d8));

        iVar2 = FUN_0056add0();

        if ((float)iVar2 == fStack_124) {

          fStack_12c = (float)((int)fStack_12c +

                              (int)*(short *)((int)pcStack_138 + 0x24 + DAT_00d1b6d8));

          fStack_128 = (float)((int)fStack_128 +

                              (int)*(short *)((int)pcStack_138 + 0xc + DAT_00d1b6d8));

        }

        fStack_124 = (float)((int)fStack_124 + 1);

        pcStack_138 = (char *)((int)pcStack_138 + 2);

      } while ((int)pcStack_138 < 0x188);

      if (((int)fStack_128 < 1) && ((int)fStack_12c < 1)) {

        if (((int)fStack_128 < 0) || ((int)fStack_12c < 0)) {

          fStack_124 = -NAN;

        }

        else {

          fStack_124 = -NAN;

        }

      }

      else {

        fStack_124 = -2.1400116e+38;

      }

      fVar15 = (float10)FUN_004c4cf0();

      fStack_13c = (float)fVar15;

      fVar15 = (float10)FUN_00569dc0();

      fStack_120 = *(float *)(DAT_00d1b6d8 + 0x260);

      fStack_130 = (float)(fVar15 * (float10)fStack_13c);

      iVar2 = FUN_0056b280();

      fStack_13c = (float)iVar2;

      fVar16 = (float10)FUN_00569dc0();

      fVar15 = (float10)fStack_13c;

      pcStack_138 = (char *)((int)fStack_128 + (int)fStack_12c);

      fStack_13c = (float)((int)pcStack_138 + iStack_11c + (int)fStack_110) * DAT_00a0f298;

      afStack_108[0] = (float)(fVar16 + fVar15 + (float10)fStack_120 + (float10)fStack_130);

      iVar2 = FUN_0056a680();

      fStack_140 = fStack_13c / ((float)iVar2 * g_flMsToSeconds_Inferred);

      fStack_13c = (float)(iStack_118 + iStack_114) * DAT_00a0f298;

      iVar2 = FUN_0056a680();

      fStack_10c = fStack_13c / ((float)iVar2 * g_flMsToSeconds_Inferred);

      fStack_13c = (float)(iStack_11c + (int)fStack_110) * DAT_00a0f298;

      iVar2 = FUN_0056a680();

      fStack_120 = fStack_13c / ((float)iVar2 * g_flMsToSeconds_Inferred);

      fStack_13c = (float)((int)pcStack_138 + iStack_118 + iStack_114) * DAT_00a0f298;

      iVar2 = FUN_0056a680();

      pcStack_138 = (char *)(fStack_13c / ((float)iVar2 * g_flMsToSeconds_Inferred));

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x15c))();

      FUN_007a6de0();

      sprintf(acStack_100,"%s\n");

      pfVar3 = (float *)FUN_00514050();

      fVar25 = *pfVar3;

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x22c))();

      FUN_00412c60();

      FUN_007a6de0();

      iVar4 = FUN_0056b280();

      fVar24 = (float)iVar4;

      FUN_00569dc0();

      FUN_00412c60();

      FUN_007a6de0();

      sprintf((char *)afStack_108,"%s: %g\n%s: %g");

      pfVar3 = afStack_108;

      fVar18 = 0.0;

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x260))();

      piVar13 = *(int **)(param_1 + 0x55c);

      iVar4 = *piVar13;

      uVar7 = 0xffbbbbbb;

      uVar5 = FUN_007a6de0();

      uVar28 = CONCAT44(uVar7,uVar5);

      (**(code **)(iVar4 + 0x224))();

      sprintf((char *)&fStack_128,"%g",(double)fStack_130);

      fVar15 = (float10)FUN_00412c60();

      if ((float)(fVar15 + (float10)fVar25) == g_flZero) {

        fVar6 = -NAN;

      }

      else {

        fVar6 = -2.1400116e+38;

        if ((float)(fVar15 + (float10)fVar25) <= g_flZero) {

          fVar6 = -NAN;

        }

      }

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x224))(&fStack_128);

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x264))();

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x250))(&DAT_00a15104);

      if (DAT_00aaa664 <=

          ABS(*(float *)(&DAT_00a1e3f0 +

                        (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) +

                                                          0xac + DAT_00d1b6d8) + 0x3c) + 0x531) * 4)

              - g_flOne)) {

        uVar5 = FUN_007a6de0();

        uVar26 = CONCAT44(unaff_EBP - (int)unaff_ESI,(int)unaff_EBX - (int)fVar24);

        uVar7 = FUN_007a6de0("Class Bonus",0xffffffff);

        piVar23 = unaff_ESI;

        uVar8 = FUN_007a6de0("Weapon Base",0xffffffff);

        sprintf(acStack_134,"%s: %d-%d\n%s: %d-%d\n%s: %d-%d",uVar8,fVar24,piVar23,uVar7,uVar26,

                uVar5,pfVar3,piVar13);

      }

      else {

        uVar5 = FUN_007a6de0();

        uVar26 = CONCAT44(unaff_ESI,fVar24);

        uVar7 = FUN_007a6de0("Weapon Base",0xffffffff);

        sprintf(acStack_134,"%s: %d-%d\n%s: %d-%d",uVar7,uVar26,uVar5,pfVar3,piVar13);

      }

      fVar24 = 0.0;

      fVar25 = 5.60519e-45;

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x260))(4,0,0,0,0,acStack_134);

      iVar4 = **(int **)(param_1 + 0x55c);

      uVar7 = 0xffbbbbbb;

      uVar5 = FUN_007a6de0("Total Dmg: ",0xffffffff);

      (**(code **)(iVar4 + 0x224))(uVar5);

      sprintf(&stack0xfffffeac,"%d-%d",fVar6,(int)uVar28 + (int)fVar18);

      puVar22 = &stack0xfffffeac;

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x224))(puVar22,(int)((ulonglong)uVar28 >> 0x20));

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x264))();

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x250))(&DAT_00a15104);

      if (DAT_00aaa664 <=

          ABS(*(float *)(&DAT_00a1e3f0 +

                        (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) +

                                                          0xac + DAT_00d1b6d8) + 0x3c) + 0x531) * 4)

              - g_flOne)) {

        dVar21 = (double)(fVar24 - fVar18);

        uVar5 = FUN_007a6de0();

        dVar20 = (double)(fVar24 - fVar25);

        uVar8 = FUN_007a6de0();

        dVar19 = (double)fVar6;

        uVar10 = FUN_007a6de0("Weapon Base",0xffffffff);

        sprintf(&stack0xfffffea0,"%s: %0.2f\n%s: %+0.2f\n%s: %+0.2f",uVar10,dVar19,uVar8,dVar20,

                uVar5,dVar21);

      }

      else {

        dVar21 = (double)(fVar24 - fVar18);

        uVar5 = FUN_007a6de0();

        dVar20 = (double)fVar6;

        uVar8 = FUN_007a6de0();

        sprintf(&stack0xfffffea0,"%s: %0.2f\n%s: %+0.2f",uVar8,dVar20,uVar5,dVar21);

      }

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x260))(4,0,0,0,0);

      sprintf(&stack0xfffffe88,"%0.2f",(double)(float)puVar22);

      iVar4 = **(int **)(param_1 + 0x55c);

      uVar5 = FUN_007a6de0("DPS: ",0xffffffff);

      (**(code **)(iVar4 + 0x224))(uVar5);

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x224))(&stack0xfffffe80,uVar7);

      (**(code **)(**(int **)(param_1 + 0x55c) + 0x264))();

    }

    (**(code **)(**(int **)(param_1 + 0x55c) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x560) != 0) {

    (**(code **)(**(int **)(param_1 + 0x560) + 0x268))();

    iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0x514) + 0x260) + 4);

    if (iVar4 == 0) {

      pcVar11 = (char *)FUN_007a6de0();

      sprintf(acStack_100,pcVar11);

      (**(code **)(**(int **)(param_1 + 0x560) + 0x224))();

      iVar4 = *(int *)(param_1 + 0x514);

      if ((iVar4 != 0) &&

         (*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c) != 0)) {

        (**(code **)(**(int **)(param_1 + 0x560) + 0x250))(&DAT_00a15104);

        cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x514) + 4) + 4) +

                                            0xac + *(int *)(param_1 + 0x514)) + 0x3c) + 0x714);

        if (cVar1 == '\x01') {

          iVar4 = **(int **)(param_1 + 0x560);

          uVar7 = 0xffbbbbbb;

          uVar5 = FUN_007a6de0("(Small Weapons Only)",0xffffffff);

        }

        else if (cVar1 == '\x02') {

          iVar4 = **(int **)(param_1 + 0x560);

          uVar7 = 0xffbbbbbb;

          uVar5 = FUN_007a6de0("(Medium Weapons Only)",0xffffffff);

        }

        else {

          if (cVar1 != '\x03') goto LAB_0087eb8c;

          iVar4 = **(int **)(param_1 + 0x560);

          uVar7 = 0xffbbbbbb;

          uVar5 = FUN_007a6de0("(Large Weapons Only)",0xffffffff);

        }

        (**(code **)(iVar4 + 0x224))(uVar5,uVar7);

      }

    }

    else {

      fStack_140 = *(float *)(DAT_00d1b644 + 0xe83c);

      FUN_00412cd0();

      fStack_140 = (float)FUN_0040dab0();

      iVar2 = FUN_0056b340();

      fStack_124 = (float)((int)fStack_140 + iVar2);

      fStack_140 = *(float *)(DAT_00d1b644 + 0xe83c);

      FUN_00412cd0();

      fStack_140 = (float)FUN_0040dab0();

      iStack_11c = FUN_0056b340();

      iStack_11c = (int)fStack_140 + iStack_11c;

      uStack_131 = *(uint8_t *)

                    (*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                      DAT_00d1b6d8) + 0x3c) + 0x531);

      fStack_140 = *(float *)(DAT_00d1b644 + 0xe83c);

      FUN_00412cd0();

      fStack_140 = (float)FUN_0040dab0();

      iStack_118 = FUN_0056b340();

      iStack_118 = (int)fStack_140 + iStack_118;

      uStack_131 = *(uint8_t *)

                    (*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                      DAT_00d1b6d8) + 0x3c) + 0x531);

      fStack_140 = *(float *)(DAT_00d1b644 + 0xe83c);

      FUN_00412cd0();

      fStack_140 = (float)FUN_0040dab0();

      iStack_114 = FUN_0056b340();

      iStack_114 = (int)fStack_140 + iStack_114;

      fStack_128 = 0.0;

      fStack_12c = 0.0;

      fStack_130 = 0.0;

      pcStack_138 = (char *)0x17c;

      do {

        fStack_128 = (float)((int)fStack_128 +

                            (int)*(short *)((int)pcStack_138 + 0x18 + DAT_00d1b6d8));

        fStack_12c = (float)((int)fStack_12c + (int)*(short *)((int)pcStack_138 + DAT_00d1b6d8));

        fVar25 = (float)FUN_0056add0();

        if (fVar25 == fStack_130) {

          fStack_128 = (float)((int)fStack_128 +

                              (int)*(short *)((int)pcStack_138 + 0x24 + DAT_00d1b6d8));

          fStack_12c = (float)((int)fStack_12c +

                              (int)*(short *)((int)pcStack_138 + 0xc + DAT_00d1b6d8));

        }

        fStack_130 = (float)((int)fStack_130 + 1);

        pcStack_138 = (char *)((int)pcStack_138 + 2);

      } while ((int)pcStack_138 < 0x188);

      if (((int)fStack_12c < 1) && ((int)fStack_128 < 1)) {

        if (((int)fStack_12c < 0) || ((int)fStack_128 < 0)) {

          pcStack_138 = (char *)0xffff2020;

        }

        else {

          pcStack_138 = (char *)0xffffffff;

        }

      }

      else {

        pcStack_138 = (char *)0xff20ff20;

      }

      fVar15 = (float10)FUN_004c4cf0();

      fStack_140 = (float)fVar15;

      fVar15 = (float10)FUN_00569dc0();

      afStack_108[0] = *(float *)(DAT_00d1b6d8 + 0x260);

      fStack_130 = (float)(fVar15 * (float10)fStack_140);

      iVar2 = FUN_0056b280();

      fStack_140 = (float)iVar2;

      fVar17 = (float10)FUN_00569dc0();

      fVar15 = (float10)fStack_140;

      fVar16 = (float10)afStack_108[0];

      afStack_108[0] = (float)((int)fStack_12c + (int)fStack_128);

      fStack_140 = (float)((int)afStack_108[0] + iStack_11c + (int)fStack_124) * DAT_00a0f298;

      fStack_120 = (float)(fVar17 + fVar15 + fVar16 + (float10)fStack_130);

      FUN_0056a680();

      fStack_140 = (float)(iStack_114 + iStack_118) * DAT_00a0f298;

      iVar2 = FUN_0056a680();

      fStack_10c = fStack_140 / ((float)iVar2 * g_flMsToSeconds_Inferred);

      fStack_140 = (float)(iStack_11c + (int)fStack_124) * DAT_00a0f298;

      iVar2 = FUN_0056a680();

      fStack_13c = fStack_140 / ((float)iVar2 * g_flMsToSeconds_Inferred);

      fStack_140 = (float)((int)afStack_108[0] + iStack_114 + iStack_118) * DAT_00a0f298;

      iVar2 = FUN_0056a680();

      fStack_110 = fStack_140 / ((float)iVar2 * g_flMsToSeconds_Inferred);

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x15c))();

      FUN_007a6de0();

      sprintf(acStack_100,"%s\n");

      pfVar3 = (float *)FUN_00514050();

      fVar25 = *pfVar3;

      pcVar11 = acStack_100;

      (**(code **)(**(int **)(param_1 + 0x560) + 0x22c))();

      FUN_00412c60();

      FUN_007a6de0();

      iVar2 = FUN_0056b280();

      FUN_00569dc0();

      FUN_00412c60();

      FUN_007a6de0();

      sprintf((char *)afStack_108,"%s: %g\n%s: %g");

      uVar28 = 0;

      (**(code **)(**(int **)(param_1 + 0x560) + 0x260))();

      piVar13 = *(int **)(param_1 + 0x560);

      iVar4 = *piVar13;

      iVar9 = FUN_007a6de0();

      (**(code **)(iVar4 + 0x224))();

      sprintf((char *)&fStack_128,"%g",(double)iVar2);

      fVar15 = (float10)FUN_00412c60();

      unaff_EBX = (float)(fVar15 + (float10)fVar25);

      if (unaff_EBX == g_flZero) {

        uVar5 = 0xffffffff;

      }

      else {

        uVar5 = 0xff20ff20;

        if (unaff_EBX <= g_flZero) {

          uVar5 = 0xffff2020;

        }

      }

      (**(code **)(**(int **)(param_1 + 0x560) + 0x224))(&fStack_128);

      (**(code **)(**(int **)(param_1 + 0x560) + 0x264))();

      puVar27 = &DAT_00a15104;

      (**(code **)(**(int **)(param_1 + 0x560) + 0x250))(&DAT_00a15104);

      if (DAT_00aaa664 <=

          ABS(*(float *)(&DAT_00a1e3f0 +

                        (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) +

                                                          0xac + DAT_00d1b6d8) + 0x3c) + 0x531) * 4)

              - g_flOne)) {

        uVar7 = FUN_007a6de0();

        uVar26 = CONCAT44((int)unaff_EBX - (int)unaff_ESI,unaff_EBP - (int)fVar25);

        uVar8 = FUN_007a6de0("Class Bonus",0xffffffff);

        piVar23 = unaff_ESI;

        uVar10 = FUN_007a6de0("Weapon Base",0xffffffff);

        sprintf(acStack_134,"%s: %d-%d\n%s: %d-%d\n%s: %d-%d",uVar10,fVar25,piVar23,uVar8,uVar26,

                uVar7,pcVar11,piVar13);

      }

      else {

        uVar7 = FUN_007a6de0();

        uVar26 = CONCAT44(unaff_ESI,fVar25);

        uVar8 = FUN_007a6de0("Weapon Base",0xffffffff);

        sprintf(acStack_134,"%s: %d-%d\n%s: %d-%d",uVar8,uVar26,uVar7,pcVar11,piVar13);

      }

      fVar18 = 0.0;

      (**(code **)(**(int **)(param_1 + 0x560) + 0x260))(4,0,0,0,0,acStack_134);

      piVar13 = *(int **)(param_1 + 0x560);

      iVar4 = *piVar13;

      fVar24 = -NAN;

      uVar7 = FUN_007a6de0("Total Dmg: ",0xffffffff);

      (**(code **)(iVar4 + 0x224))(uVar7);

      sprintf(&stack0xfffffeac,"%d-%d",iVar9 + (int)((ulonglong)uVar28 >> 0x20),uVar5);

      (**(code **)(**(int **)(param_1 + 0x560) + 0x224))(&stack0xfffffeac,piVar13);

      (**(code **)(**(int **)(param_1 + 0x560) + 0x264))();

      (**(code **)(**(int **)(param_1 + 0x560) + 0x250))(&DAT_00a15104);

      fVar25 = (float)uVar28 - (float)((ulonglong)uVar28 >> 0x20);

      if (DAT_00aaa664 <=

          ABS(*(float *)(&DAT_00a1e3f0 +

                        (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) +

                                                          0xac + DAT_00d1b6d8) + 0x3c) + 0x531) * 4)

              - g_flOne)) {

        dVar21 = (double)fVar25;

        uVar5 = FUN_007a6de0();

        dVar20 = (double)((float)uVar28 - fVar24);

        uVar7 = FUN_007a6de0();

        dVar19 = (double)fVar18;

        uVar8 = FUN_007a6de0("Weapon Base",0xffffffff);

        sprintf(&stack0xfffffea0,"%s: %0.2f\n%s: %+0.2f\n%s: %+0.2f",uVar8,dVar19,uVar7,dVar20,uVar5

                ,dVar21);

      }

      else {

        dVar21 = (double)fVar25;

        uVar5 = FUN_007a6de0();

        dVar20 = (double)fVar18;

        uVar7 = FUN_007a6de0();

        sprintf(&stack0xfffffea0,"%s: %0.2f\n%s: %+0.2f",uVar7,dVar20,uVar5,dVar21);

      }

      puVar22 = &stack0xfffffea0;

      (**(code **)(**(int **)(param_1 + 0x560) + 0x260))(4,0,0,0,0);

      sprintf(&stack0xfffffe88,"%0.2f",(double)(float)puVar27);

      iVar4 = **(int **)(param_1 + 0x560);

      uVar5 = FUN_007a6de0("DPS: ",0xffffffff);

      (**(code **)(iVar4 + 0x224))(uVar5);

      (**(code **)(**(int **)(param_1 + 0x560) + 0x224))(&stack0xfffffe80,puVar22);

      (**(code **)(**(int **)(param_1 + 0x560) + 0x264))();

    }

LAB_0087eb8c:

    (**(code **)(**(int **)(param_1 + 0x560) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x564) != 0) {

    (**(code **)(**(int **)(param_1 + 0x564) + 0x268))();

    iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0x514) + 0x260) + 8);

    if (iVar4 == 0) {

      pcVar11 = (char *)FUN_007a6de0();

      sprintf(acStack_100,pcVar11);

      (**(code **)(**(int **)(param_1 + 0x564) + 0x224))();

    }

    else {

      fStack_13c = (float)((int)*(short *)(iVar4 + 0x12e) + (int)*(short *)(iVar4 + 0x12a) +

                           (int)*(short *)(iVar4 + 0x128) + (int)*(short *)(iVar4 + 0x124) +

                           (int)*(short *)(iVar4 + 0x126) + (int)*(short *)(iVar4 + 300)) *

                   *(float *)(DAT_00d1b644 + 0xe83c);

      if (0.0 <= fStack_13c) {

        fStack_13c = fStack_13c + g_flMissionXpRoundBias;

      }

      else {

        fStack_13c = fStack_13c - g_flMissionXpRoundBias;

      }

      iStack_114 = FUN_0056b340();

      iStack_114 = iStack_114 + (int)fStack_13c;

      fStack_13c = (float)((int)*(short *)(iVar4 + 0x132) + (int)*(short *)(iVar4 + 0x138) +

                           (int)*(short *)(iVar4 + 0x130) + (int)*(short *)(iVar4 + 0x13a) +

                           (int)*(short *)(iVar4 + 0x136) + (int)*(short *)(iVar4 + 0x134)) *

                   *(float *)(DAT_00d1b644 + 0xe83c);

      if (0.0 <= fStack_13c) {

        fStack_13c = fStack_13c + g_flMissionXpRoundBias;

      }

      else {

        fStack_13c = fStack_13c - g_flMissionXpRoundBias;

      }

      iVar2 = FUN_0056b340();

      fStack_10c = (float)(iVar2 + (int)fStack_13c);

      fStack_13c = *(float *)(&DAT_00a1e3f0 +

                             (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) +

                                                                       4) + 0xac + DAT_00d1b6d8) +

                                                     0x3c) + 0x531) * 4) *

                   *(float *)(DAT_00d1b644 + 0xe83c) *

                   (float)((int)*(short *)(iVar4 + 0x12e) + (int)*(short *)(iVar4 + 0x12a) +

                           (int)*(short *)(iVar4 + 0x128) + (int)*(short *)(iVar4 + 0x124) +

                           (int)*(short *)(iVar4 + 0x126) + (int)*(short *)(iVar4 + 300));

      if (0.0 <= fStack_13c) {

        fStack_13c = fStack_13c + g_flMissionXpRoundBias;

      }

      else {

        fStack_13c = fStack_13c - g_flMissionXpRoundBias;

      }

      iStack_11c = FUN_0056b340();

      iStack_11c = iStack_11c + (int)fStack_13c;

      fStack_13c = *(float *)(&DAT_00a1e3f0 +

                             (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) +

                                                                       4) + 0xac + DAT_00d1b6d8) +

                                                     0x3c) + 0x531) * 4) *

                   *(float *)(DAT_00d1b644 + 0xe83c) *

                   (float)((int)*(short *)(iVar4 + 0x132) + (int)*(short *)(iVar4 + 0x138) +

                           (int)*(short *)(iVar4 + 0x130) + (int)*(short *)(iVar4 + 0x13a) +

                           (int)*(short *)(iVar4 + 0x136) + (int)*(short *)(iVar4 + 0x134));

      if (0.0 <= fStack_13c) {

        fStack_13c = fStack_13c + g_flMissionXpRoundBias;

      }

      else {

        fStack_13c = fStack_13c - g_flMissionXpRoundBias;

      }

      iVar2 = FUN_0056b340();

      fStack_110 = (float)(iVar2 + (int)fStack_13c);

      fStack_128 = 0.0;

      fStack_12c = 0.0;

      fStack_130 = 0.0;

      pcStack_138 = (char *)0x17c;

      do {

        fStack_128 = (float)((int)fStack_128 +

                            (int)*(short *)((int)pcStack_138 + 0x18 + DAT_00d1b6d8));

        fStack_12c = (float)((int)fStack_12c + (int)*(short *)((int)pcStack_138 + DAT_00d1b6d8));

        fVar25 = (float)FUN_0056add0();

        if (fVar25 == fStack_130) {

          fStack_128 = (float)((int)fStack_128 +

                              (int)*(short *)((int)pcStack_138 + 0x24 + DAT_00d1b6d8));

          fStack_12c = (float)((int)fStack_12c +

                              (int)*(short *)((int)pcStack_138 + 0xc + DAT_00d1b6d8));

        }

        fStack_130 = (float)((int)fStack_130 + 1);

        pcStack_138 = (char *)((int)pcStack_138 + 2);

      } while ((int)pcStack_138 < 0x188);

      if (((int)fStack_12c < 1) && ((int)fStack_128 < 1)) {

        if (((int)fStack_12c < 0) || ((int)fStack_128 < 0)) {

          iStack_118 = -0xdfe0;

        }

        else {

          iStack_118 = -1;

        }

      }

      else {

        iStack_118 = -0xdf00e0;

      }

      fVar15 = (float10)FUN_004c4cf0();

      fVar16 = (float10)FUN_00569dc0();

      fStack_140 = *(float *)(DAT_00d1b6d8 + 0x260);

      fStack_124 = (float)(fVar16 * (float10)(float)fVar15);

      iVar2 = FUN_0056b280();

      fVar15 = (float10)FUN_00569dc0();

      fStack_140 = (float)(fVar15 + (float10)iVar2 + (float10)fStack_140 + (float10)fStack_124);

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x15c))();

      FUN_007a6de0();

      sprintf(acStack_100,"%s\n");

      FUN_00514050();

      pcVar11 = acStack_100;

      (**(code **)(**(int **)(param_1 + 0x564) + 0x22c))();

      fVar25 = (*(float *)(DAT_00d1b6d8 + 0x260) + fStack_12c) * DAT_00a110d8;

      if (0.0 <= fVar25) {

        fVar25 = fVar25 + g_flMissionXpRoundBias;

      }

      else {

        fVar25 = fVar25 - g_flMissionXpRoundBias;

      }

      iVar4 = FUN_0056b280();

      fVar15 = (float10)FUN_00569dc0();

      fVar15 = (fVar15 + (float10)iVar4) * (float10)DAT_00a110d8;

      pcStack_138 = (char *)(float)fVar15;

      if ((float10)g_flZero <= fVar15) {

        fStack_128 = (float)pcStack_138 + g_flMissionXpRoundBias;

      }

      else {

        fStack_128 = (float)pcStack_138 - g_flMissionXpRoundBias;

      }

      FUN_007a6de0();

      fVar24 = (float)(int)fStack_128;

      FUN_007a6de0();

      sprintf((char *)afStack_108,"%s: %g\n%s: %g");

      pfVar3 = afStack_108;

      uVar28 = 0;

      (**(code **)(**(int **)(param_1 + 0x564) + 0x260))();

      piVar13 = *(int **)(param_1 + 0x564);

      iVar4 = *piVar13;

      iVar2 = FUN_007a6de0();

      (**(code **)(iVar4 + 0x224))();

      sprintf((char *)&fStack_128,"%g",0);

      fVar18 = (*(float *)(DAT_00d1b6d8 + 0x260) -

               (float)(int)*(short *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) +

                                                        0xac + DAT_00d1b6d8) + 0x3c) + 0x510)) *

               DAT_00a110d8;

      if (0.0 <= fVar18) {

        fVar18 = fVar18 + g_flMissionXpRoundBias;

      }

      else {

        fVar18 = fVar18 - g_flMissionXpRoundBias;

      }

      fVar24 = (float)(int)fVar18 * g_flMultiKillCountBlend + fVar24;

      if (fVar24 == 0.0) {

        iVar4 = -1;

      }

      else {

        iVar4 = -0xdf00e0;

        if (fVar24 <= 0.0) {

          iVar4 = -0xdfe0;

        }

      }

      (**(code **)(**(int **)(param_1 + 0x564) + 0x224))(&fStack_128);

      (**(code **)(**(int **)(param_1 + 0x564) + 0x264))();

      (**(code **)(**(int **)(param_1 + 0x564) + 0x250))(&DAT_00a15104);

      if (DAT_00aaa664 <=

          ABS(*(float *)(&DAT_00a1e3f0 +

                        (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) +

                                                          0xac + DAT_00d1b6d8) + 0x3c) + 0x531) * 4)

              - g_flOne)) {

        uVar5 = FUN_007a6de0();

        fVar24 = fStack_140;

        uVar26 = CONCAT44((int)fVar25 - (int)fStack_140,(int)unaff_ESI - (int)unaff_EBX);

        uVar7 = FUN_007a6de0("Class Bonus",0xffffffff);

        uVar8 = FUN_007a6de0("Weapon Base",0xffffffff);

        sprintf(acStack_134,"%s: %d-%d\n%s: %d-%d\n%s: %d-%d",uVar8,unaff_EBX,fVar24,uVar7,uVar26,

                uVar5,pcVar11,pfVar3);

      }

      else {

        uVar5 = FUN_007a6de0();

        uVar26 = CONCAT44(fStack_140,unaff_EBX);

        uVar7 = FUN_007a6de0("Weapon Base",0xffffffff);

        sprintf(acStack_134,"%s: %d-%d\n%s: %d-%d",uVar7,uVar26,uVar5,pcVar11,pfVar3);

      }

      (**(code **)(**(int **)(param_1 + 0x564) + 0x260))(4,0,0,0,0,acStack_134);

      iVar9 = **(int **)(param_1 + 0x564);

      uVar7 = 0xffbbbbbb;

      uVar5 = FUN_007a6de0("Total Dmg: ",0xffffffff);

      (**(code **)(iVar9 + 0x224))(uVar5,uVar7);

      sprintf(&stack0xfffffeac,"%d-%d",iVar2 + (int)uVar28,iVar4 + (int)piVar13);

      (**(code **)(**(int **)(param_1 + 0x564) + 0x224))

                (&stack0xfffffeac,(int)((ulonglong)uVar28 >> 0x20));

      (**(code **)(**(int **)(param_1 + 0x564) + 0x264))();

    }

    (**(code **)(**(int **)(param_1 + 0x564) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x568) != 0) {

    (**(code **)(**(int **)(param_1 + 0x568) + 0x268))();

    iVar4 = *(int *)(*(int *)(param_1 + 0x514) + 0x270);

    if (iVar4 == 0) {

      iVar4 = **(int **)(param_1 + 0x568);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x224))();

    }

    else {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x15c))();

      FUN_007a6de0();

      sprintf(acStack_100,"%s");

      FUN_00514050();

      (**(code **)(**(int **)(param_1 + 0x568) + 0x22c))();

    }

    (**(code **)(**(int **)(param_1 + 0x568) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x56c) != 0) {

    (**(code **)(**(int **)(param_1 + 0x56c) + 0x268))();

    iVar4 = *(int *)(*(int *)(param_1 + 0x514) + 0x26c);

    if (iVar4 == 0) {

      iVar4 = **(int **)(param_1 + 0x56c);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x224))();

    }

    else {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x15c))();

      FUN_007a6de0();

      sprintf(acStack_100,"%s");

      FUN_00514050();

      (**(code **)(**(int **)(param_1 + 0x56c) + 0x22c))();

    }

    (**(code **)(**(int **)(param_1 + 0x56c) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x570) != 0) {

    (**(code **)(**(int **)(param_1 + 0x570) + 0x268))();

    iVar4 = *(int *)(*(int *)(param_1 + 0x514) + 0x264);

    if (iVar4 == 0) {

      iVar4 = **(int **)(param_1 + 0x570);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x224))();

    }

    else {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x15c))();

      FUN_007a6de0();

      sprintf(acStack_100,"%s");

      FUN_00514050();

      (**(code **)(**(int **)(param_1 + 0x570) + 0x22c))();

    }

    (**(code **)(**(int **)(param_1 + 0x570) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x574) != 0) {

    (**(code **)(**(int **)(param_1 + 0x574) + 0x268))();

    iVar4 = *(int *)(*(int *)(param_1 + 0x514) + 0x268);

    if (iVar4 == 0) {

      pcVar11 = (char *)FUN_007a6de0();

      sprintf(acStack_100,pcVar11);

      (**(code **)(**(int **)(param_1 + 0x574) + 0x224))();

    }

    else {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x15c))();

      FUN_007a6de0();

      sprintf(acStack_100,"%s\n");

      FUN_00514050();

      (**(code **)(**(int **)(param_1 + 0x574) + 0x22c))();

    }

    iVar4 = **(int **)(param_1 + 0x574);

    FUN_007a6de0();

    (**(code **)(iVar4 + 0x224))();

    sprintf((char *)&fStack_110,"%d");

    (**(code **)(**(int **)(param_1 + 0x574) + 0x224))();

    (**(code **)(**(int **)(param_1 + 0x574) + 0x224))();

    Vehicle_GetPowerRegenRate(*(VehicleCombatPools_Inferred **)(param_1 + 0x514));

    sprintf((char *)&fStack_120,"+%.02f");

    (**(code **)(**(int **)(param_1 + 0x574) + 0x224))();

    iVar4 = **(int **)(param_1 + 0x574);

    uVar5 = FUN_007a6de0(")\nHeat: ",0xffffffff);

    (**(code **)(iVar4 + 0x224))(uVar5);

    iVar4 = Vehicle_CalcHeatMaximum(*(RE_VehicleCombatPoolFields **)(param_1 + 0x514));

    sprintf((char *)&fStack_130,"%d",iVar4);

    (**(code **)(**(int **)(param_1 + 0x574) + 0x224))(&fStack_130,0xffffffff);

    (**(code **)(**(int **)(param_1 + 0x574) + 0x224))(&DAT_00a57be8,0xffbbbbbb);

    iVar4 = Vehicle_GetCoolRate(*(VehicleCombatPools_Inferred **)(param_1 + 0x514));

    sprintf((char *)&fStack_140,"+%.02f",(double)((float)iVar4 * g_flDisplayRateScaleOneThird));

    (**(code **)(**(int **)(param_1 + 0x574) + 0x224))(&fStack_140,0xffffffff);

    (**(code **)(**(int **)(param_1 + 0x574) + 0x224))(&DAT_00a15810,0xffbbbbbb);

    (**(code **)(**(int **)(param_1 + 0x574) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x578) != 0) {

    (**(code **)(**(int **)(param_1 + 0x578) + 0x268))();

    iVar4 = *(int *)(*(int *)(param_1 + 0x514) + 600);

    if ((iVar4 == 0) || (*(char *)(iVar4 + 0xcc) != '\0')) {

      iVar4 = **(int **)(param_1 + 0x578);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x224))();

    }

    else {

      fStack_120 = DAT_00aaa908;

      fStack_10c = DAT_00aaa904;

      fStack_130 = -NAN;

      fStack_124 = -NAN;

      fVar25 = 0.0;

      do {

        fVar15 = (float10)FUN_005a6f20();

        fStack_13c = (float)fVar15;

        if (fStack_120 < fStack_13c) {

          fStack_130 = fVar25;

          fStack_120 = fStack_13c;

        }

        if (fStack_13c < fStack_10c) {

          fStack_124 = fVar25;

          fStack_10c = fStack_13c;

        }

        fVar25 = (float)((int)fVar25 + 1);

      } while ((int)fVar25 < 6);

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x15c))();

      FUN_007a6de0();

      sprintf(acStack_100,"%s\n");

      FUN_00514050();

      (**(code **)(**(int **)(param_1 + 0x578) + 0x22c))();

      iVar4 = **(int **)(param_1 + 0x578);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x224))();

      unaff_ESI = (int *)**(int **)(param_1 + 0x578);

      FUN_0087d690();

      (*(code *)unaff_ESI[0x89])();

      iVar4 = **(int **)(param_1 + 0x578);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x224))();

      iVar4 = **(int **)(param_1 + 0x578);

      FUN_0087d690();

      (**(code **)(iVar4 + 0x224))();

      pcVar14 = sprintf_exref;

    }

    (**(code **)(**(int **)(param_1 + 0x578) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x57c) != 0) {

    (**(code **)(**(int **)(param_1 + 0x57c) + 0x268))();

    fStack_140 = *(float *)(*(int *)(param_1 + 0x514) + 0x254);

    if (fStack_140 == 0.0) {

      iVar4 = **(int **)(param_1 + 0x57c);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x224))();

    }

    else {

      (**(code **)(*(int *)(*(int *)(*(int *)((int)fStack_140 + 4) + 4) + 4 + (int)fStack_140) +

                  0x15c))();

      FUN_007a6de0();

      (*pcVar14)();

      FUN_00514050();

      (**(code **)(**(int **)(param_1 + 0x57c) + 0x22c))();

    }

    if (*(int *)(DAT_00d1b6d8 + 0x250) != 0) {

      iVar4 = **(int **)(param_1 + 0x57c);

      FUN_007a6de0();

      (**(code **)(iVar4 + 0x224))();

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 4) + 4) + 4 +

                           *(int *)(DAT_00d1b6d8 + 0x250)) + 0x1ac))();

      (*pcVar14)();

      (**(code **)(**(int **)(param_1 + 0x57c) + 0x224))();

    }

    iVar4 = **(int **)(param_1 + 0x57c);

    psVar12 = (short *)FUN_007a6de0();

    (**(code **)(iVar4 + 0x224))();

    (*pcVar14)();

    (**(code **)(**(int **)(param_1 + 0x57c) + 0x224))();

    if (unaff_ESI == (int *)0x0) {

      fStack_13c = 0.0;

    }

    else {

      fStack_13c = (float)(**(code **)(*unaff_ESI + 0x38))();

    }

    pcStack_138 = "Physical";

    do {

      if (pcStack_138 != "Ice-REMOVE") {

        FUN_007a6de0();

        FUN_007a6de0();

        (*pcVar14)();

        iVar9 = 0;

        iVar2 = 0;

        (**(code **)(**(int **)(param_1 + 0x57c) + 0x260))();

        iVar4 = **(int **)(param_1 + 0x57c);

        uVar7 = 0xffbbbbbb;

        uVar5 = FUN_007a6de0("Resist ",0xffffffff);

        (**(code **)(iVar4 + 0x224))(uVar5,uVar7);

        piVar13 = (int *)(**(code **)(**(int **)(param_1 + 0x57c) + 0x1b8))();

        fVar25 = *(float *)(*piVar13 + 0x7c);

        piVar13 = (int *)(**(code **)(**(int **)(param_1 + 0x57c) + 0x1b8))();

        fStack_140 = *(float *)(*piVar13 + 0x7c);

        fStack_13c = fVar25;

        FUN_00976e10();

        (**(code **)(**(int **)(param_1 + 0x57c) + 0x224))(&DAT_00a3ad3c,0xffbbbbbb);

        if (iVar9 == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = (int)*psVar12;

        }

        (*pcVar14)(&fStack_140,&DAT_00a37c64,*(short *)((int)psVar12 + DAT_00d1b6d8 + iVar2) + iVar4

                  );

        (**(code **)(**(int **)(param_1 + 0x57c) + 0x224))(&fStack_140);

        (**(code **)(**(int **)(param_1 + 0x57c) + 0x264))();

        (**(code **)(**(int **)(param_1 + 0x57c) + 0x250))(&DAT_00a15104);

      }

      fStack_13c = (float)((int)fStack_13c + 2);

      pcStack_138 = pcStack_138 + 0x10;

    } while ((int)pcStack_138 < 0xa1e460);

    (**(code **)(**(int **)(param_1 + 0x57c) + 0x34c))();

  }

  if (*(int *)(param_1 + 0x580) == 0) {

    return;

  }

  (**(code **)(**(int **)(param_1 + 0x580) + 0x268))();

  (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x514) + 4) + 4) + 4 +

                       *(int *)(param_1 + 0x514)) + 0x15c))();

  FUN_007a6de0();

  (*pcVar14)();

  FUN_00514050();

  (**(code **)(**(int **)(param_1 + 0x580) + 0x22c))();

  switch(*(uint8_t *)

          (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x514) + 4) + 4) + 0xac +

                            *(int *)(param_1 + 0x514)) + 0x3c) + 0x714)) {

  case 0:

    break;

  case 1:

    break;

  case 2:

    break;

  case 3:

    break;

  default:

    goto switchD_0087fe0b_default;

  }

  iVar4 = **(int **)(param_1 + 0x580);

  FUN_007a6de0();

  (**(code **)(iVar4 + 0x224))();

switchD_0087fe0b_default:

  (**(code **)(**(int **)(param_1 + 0x580) + 0x34c))();

  return;

}
