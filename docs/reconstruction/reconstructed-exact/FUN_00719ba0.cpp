// =============================================================================
// FUN_00719ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_00719ba0
// Address:   0x00719ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00719ba0 @ 0x00719ba0
// Stable ID: aa_00719ba0
// Embedded strings (evidence for future rename):
//   - "Writing indexBegin <%d>."
//   - "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoPackOSFile.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~393 non-empty decompiler lines.
//  - Control keywords: if×27, while×9, goto×8, do×4, return×2, for×1.
//  - Notable callees: FUN_00767160×15, CONCAT22×2, CONCAT31×2, FUN_00481690×2, FUN_0044e060, FUN_00456960, FUN_00481330, FUN_005b2ba0.
//  - Strings: "Writing indexBegin <%d>."; "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoPackOSFile.cpp".
//  - Return sites: 2.

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

/* WARNING: Type propagation algorithm not settling */



void FUN_00719ba0(int *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  undefined ********ppppppppuVar5;

  undefined ***pppuVar6;

  undefined ********ppppppppuVar7;

  int iVar8;

  int iVar9;

  undefined *******pppppppuVar10;

  uint uVar11;

  undefined ******ppppppuVar12;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t uVar14;

  uint32_t /* width from decompiler */ uVar13;

  undefined *******pppppppuVar15;

  uint32_t /* width from decompiler */ unaff_EBP;

  undefined ********ppppppppuVar16;

  undefined ********ppppppppuVar17;

  undefined ********unaff_EDI;

  undefined ****ppppuVar18;

  int unaff_retaddr;

  undefined ********ppppppppuVar19;

  undefined *******pppppppuStack_88;

  undefined ********ppppppppuVar20;

  undefined ********ppppppppuStack_68;

  undefined *****pppppuStack_64;

  undefined ********ppppppppuStack_60;

  uint uStack_5c;

  undefined ********local_58;

  int *local_54;

  undefined ********ppppppppuStack_50;

  undefined **ppuStack_4c;

  undefined ********ppppppppuStack_48;

  undefined ***pppuStack_44;

  undefined ********ppppppppuStack_40;

  uint uStack_3c;

  undefined ********ppppppppuStack_38;

  uint uStack_34;

  undefined *******pppppppuStack_30;

  undefined ***pppuStack_2c;

  undefined *****pppppuStack_28;

  undefined ***pppuStack_24;

  undefined *****pppppuStack_20;

  undefined ***pppuStack_1c;

  undefined *****apppppuStack_18 [2];

  uint8_t auStack_10 [4];

  void *pvStack_c;

  undefined ********ppppppppuStack_8;

  int *local_4;

  

  local_4 = (int *)0xffffffff;

  ppppppppuStack_8 = (undefined ********)&LAB_009af107;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  local_58 = (undefined ********)FUN_0044e060();

  *(uint8_t *)((int)local_58 + 0x25) = 1;

  ((undefined *******)local_58)[1] = (undefined ******)local_58;

  *local_58 = (undefined *******)local_58;

  ((undefined *******)local_58)[2] = (undefined ******)local_58;

  local_54 = (int *)0x0;

  local_4 = (int *)0x0;

  iVar8 = (**(code **)(*param_1 + 4))();

  if (iVar8 != 0) {

    pvStack_c = (void *)0xffffffff;

    pppppppuStack_88 = *ppppppppuStack_60;

    FUN_00481690(&local_4);

                    /* WARNING: Subroutine does not return */

    pppppppuStack_88 = (undefined *******)&UNK_00719c25;

    operator_delete(ppppppppuStack_60);

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_retaddr + 8);

  ppppppppuVar20 = (undefined ********)0x0;

  ppppppppuVar17 = ppppppppuStack_60;

  for (puVar3 = (uint32_t /* width from decompiler */ *)*puVar2; ppppppppuStack_60 = ppppppppuVar17, puVar3 != puVar2;

      puVar3 = (uint32_t /* width from decompiler */ *)*puVar3) {

    if ((int *)puVar3[9] == param_1) {

      pppppppuStack_88 = (undefined *******)&pppppuStack_64;

      iVar9 = FUN_00481330();

      iVar8 = *(int *)(iVar9 + 8);

      if ((iVar8 == 0) ||

         ((uint)(*(int *)(iVar9 + 0x10) - iVar8 >> 2) <= (uint)(*(int *)(iVar9 + 0xc) - iVar8 >> 2))

         ) {

        pppppppuStack_88 = *(undefined ********)(iVar9 + 0xc);

        FUN_00456960();

        param_1 = local_4;

      }

      else {

        piVar4 = *(int **)(iVar9 + 0xc);

        *piVar4 = (int)(puVar3 + 3);

        *(int **)(iVar9 + 0xc) = piVar4 + 1;

        param_1 = local_4;

      }

    }

    ppppppppuVar17 = ppppppppuStack_60;

  }

  ppppppppuVar16 = (undefined ********)*ppppppppuVar17;

  piVar4 = local_4;

  while (local_4 = piVar4, ppppppppuVar16 != ppppppppuVar17) {

    pppppppuVar15 = ppppppppuVar16[3];

    if (ppppppppuVar16[3] == (undefined *******)0x0) {

      pppppppuVar15 = (undefined *******)PTR_DAT_00afa2bc;

    }

    pppppppuVar10 = pppppppuVar15;

    do {

      cVar1 = *(char *)pppppppuVar10;

      pppppppuVar10 = (undefined *******)((int)pppppppuVar10 + 1);

    } while (cVar1 != '\0');

    ppppppuVar12 = (undefined ******)((int)pppppppuVar10 + (1 - (int)((int)pppppppuVar15 + 1)));

    pppppppuStack_88 = (undefined *******)ppppppuVar12;

    (**(code **)(*piVar4 + 0x18))(pppppppuVar15);

    ppppppppuVar16[4] = (undefined *******)ppppppppuVar20;

    ppppppppuVar20 = (undefined ********)((int)ppppppppuVar20 + (int)ppppppuVar12);

    piVar4 = local_4;

    if (*(char *)((int)ppppppppuVar16 + 0x25) == '\0') {

      ppppppppuVar19 = (undefined ********)ppppppppuVar16[2];

      if (*(char *)((int)ppppppppuVar19 + 0x25) == '\0') {

        cVar1 = *(char *)((int)*ppppppppuVar19 + 0x25);

        ppppppppuVar16 = ppppppppuVar19;

        ppppppppuVar19 = (undefined ********)*ppppppppuVar19;

        while (cVar1 == '\0') {

          cVar1 = *(char *)((int)*ppppppppuVar19 + 0x25);

          ppppppppuVar16 = ppppppppuVar19;

          ppppppppuVar19 = (undefined ********)*ppppppppuVar19;

        }

      }

      else {

        cVar1 = *(char *)((int)ppppppppuVar16[1] + 0x25);

        ppppppppuVar5 = (undefined ********)ppppppppuVar16[1];

        ppppppppuVar19 = ppppppppuVar16;

        while ((ppppppppuVar16 = ppppppppuVar5, cVar1 == '\0' &&

               (ppppppppuVar19 == (undefined ********)ppppppppuVar16[2]))) {

          cVar1 = *(char *)((int)ppppppppuVar16[1] + 0x25);

          ppppppppuVar5 = (undefined ********)ppppppppuVar16[1];

          ppppppppuVar19 = ppppppppuVar16;

        }

      }

    }

  }

  pppppppuStack_88 = (undefined *******)0x719d97;

  ppuStack_4c = (undefined **)(**(code **)(*piVar4 + 0x30))();

  local_58 = (undefined ********)&PTR_FUN_00aa6034;

  ppppppppuStack_50 = (undefined ********)0x0;

  ppppppppuStack_48 = (undefined ********)CONCAT31(ppppppppuStack_48._1_3_,1);

  ppppppppuStack_40 = (undefined ********)0x0;

  uStack_3c = 0;

  ppppppppuStack_38 = (undefined ********)&local_58;

  uStack_34 = 0;

  pppuStack_2c = (undefined ***)0x0;

  pppppuStack_28 = (undefined *****)0x0;

  pppuStack_24 = (undefined ***)0x0;

  pppppuStack_20 = (undefined *****)0x0;

  pvStack_c._0_1_ = 2;

  pppuStack_1c = (undefined ***)0x0;

  apppppuStack_18[0] = (undefined *****)0x0;

  pppppppuStack_88 = (undefined *******)0x719dee;

  local_54 = piVar4;

  pppuStack_44 = (undefined ***)ppuStack_4c;

  FUN_007670a0();

  ppppppppuVar17 = ppppppppuStack_38;

  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);

  if (pppuStack_1c == (undefined ***)0x0) {

    pppppppuStack_88 = (undefined *******)0x4;

    uVar11 = (*(code *)(*ppppppppuStack_38)[6])(&stack0x00000000);

    uStack_3c = uStack_3c | uVar11;

LAB_00719e57:

    ppppppppuStack_8 = unaff_EDI;

    uVar11 = (*(code *)(*ppppppppuVar17)[6])(&ppppppppuStack_8,4);

    pppuStack_44 = (undefined ***)((uint)pppuStack_44 | uVar11);

  }

  else {

    pppppppuStack_88 = (undefined *******)piVar4[0xb];

    uVar11 = FUN_00767160(&DAT_00a37c64);

    ppppppppuVar17 = ppppppppuStack_38;

    uStack_34 = uStack_34 | uVar11;

    pppppppuStack_88 = (undefined *******)0x2;

    uVar11 = (*(code *)(*ppppppppuStack_38)[6])(&DAT_00a97b84);

    uStack_3c = uStack_3c | uVar11;

    pppppuStack_20 = (undefined *****)0x0;

    if (pppuStack_24 == (undefined ***)0x0) goto LAB_00719e57;

    uVar11 = FUN_00767160(&DAT_00a37c64,unaff_EDI);

    ppppppppuVar17 = ppppppppuStack_40;

    uStack_3c = uStack_3c | uVar11;

    uVar11 = (*(code *)(*ppppppppuStack_40)[6])(&DAT_00a97b84,2);

    pppuStack_44 = (undefined ***)((uint)pppuStack_44 | uVar11);

    pppppuStack_28 = (undefined *****)0x0;

    if (pppuStack_2c != (undefined ***)0x0) {

      uVar11 = FUN_00767160(&DAT_00a37c64,unaff_EBP);

      ppppppppuVar17 = ppppppppuStack_48;

      pppuStack_44 = (undefined ***)((uint)pppuStack_44 | uVar11);

      uVar11 = (*(code *)(*ppppppppuStack_48)[6])(&DAT_00a97b84,2);

      pppppppuStack_30 = (undefined *******)0x0;

      goto LAB_00719f01;

    }

  }

  uVar11 = (*(code *)(*ppppppppuVar17)[6])(auStack_10,4);

LAB_00719f01:

  ppuStack_4c = (undefined **)((uint)ppuStack_4c | uVar11);

  ppppppppuVar16 = (undefined ********)*unaff_EDI;

  ppppppppuVar19 = unaff_EDI;

  if (ppppppppuVar16 != unaff_EDI) {

    do {

      pppppppuVar15 = ppppppppuVar16[7];

      pppppppuVar10 = ppppppppuVar16[6];

      if (pppppppuVar10 != pppppppuVar15) {

        do {

          if (uStack_34 == 0) {

            apppppuStack_18[0] = **pppppppuVar10;

            uVar11 = (*(code *)(*ppppppppuVar17)[6])(apppppuStack_18,4);

          }

          else {

            uVar11 = FUN_00767160(&DAT_00a37c64,**pppppppuVar10);

            ppppppppuVar17 = ppppppppuStack_50;

            ppuStack_4c = (undefined **)((uint)ppuStack_4c | uVar11);

            uVar11 = (*(code *)(*ppppppppuStack_50)[6])(&DAT_00a97b84,2);

            ppppppppuStack_38 = (undefined ********)0x0;

          }

          local_54 = (int *)((uint)local_54 | uVar11);

          if (uStack_3c == 0) {

            pppppuStack_20 = (*pppppppuVar10)[1];

            uVar11 = (*(code *)(*ppppppppuVar17)[6])(&pppppuStack_20,4);

          }

          else {

            uVar11 = FUN_00767160(&DAT_00a37c64,(*pppppppuVar10)[1]);

            ppppppppuVar17 = local_58;

            local_54 = (int *)((uint)local_54 | uVar11);

            uVar11 = (*(code *)(*local_58)[6])(&DAT_00a97b84,2);

            ppppppppuStack_40 = (undefined ********)0x0;

          }

          uStack_5c = uStack_5c | uVar11;

          if (pppuStack_44 == (undefined ***)0x0) {

            pppppuStack_28 = (*pppppppuVar10)[2];

            uVar11 = (*(code *)(*ppppppppuVar17)[6])(&pppppuStack_28,4);

            pppppuStack_64 = (undefined *****)((uint)pppppuStack_64 | uVar11);

LAB_0071a03c:

            pppppppuStack_30 = ppppppppuVar16[4];

            (*(code *)(*ppppppppuVar17)[6])(&pppppppuStack_30,4);

          }

          else {

            uVar11 = FUN_00767160(&DAT_00a37c64,(*pppppppuVar10)[2]);

            ppppppppuVar17 = ppppppppuStack_60;

            uStack_5c = uStack_5c | uVar11;

            uVar11 = (*(code *)(*ppppppppuStack_60)[6])(&DAT_00a97b84,2);

            pppppuStack_64 = (undefined *****)((uint)pppppuStack_64 | uVar11);

            ppppppppuStack_48 = (undefined ********)0x0;

            if (ppuStack_4c == (undefined **)0x0) goto LAB_0071a03c;

            uVar11 = FUN_00767160(&DAT_00a37c64,ppppppppuVar16[4]);

            pppppuStack_64 = (undefined *****)((uint)pppppuStack_64 | uVar11);

            (*(code *)(*ppppppppuStack_68)[6])(&DAT_00a97b84,2);

            ppppppppuStack_50 = (undefined ********)0x0;

            ppppppppuVar17 = ppppppppuStack_68;

          }

          ppppppuVar12 = *pppppppuVar10 + 5;

          if (local_54 == (int *)0x0) {

            ppppppppuStack_38 =

                 (undefined ********)

                 CONCAT22((short)((uint)ppppppuVar12 >> 0x10),*(short *)ppppppuVar12);

            (*(code *)(*ppppppppuVar17)[6])(&ppppppppuStack_38,2);

          }

          else {

            FUN_00767160(&DAT_00a37c64,(int)*(short *)ppppppuVar12);

            (*(code *)(*ppppppppuVar20)[6])(&DAT_00a97b84,2);

            local_58 = (undefined ********)0x0;

            ppppppppuVar17 = ppppppppuVar20;

          }

          if (uStack_5c == 0) {

            ppppppppuStack_40 = (undefined ********)(*pppppppuVar10)[3];

            uVar11 = (*(code *)(*ppppppppuVar17)[6])(&ppppppppuStack_40,4);

          }

          else {

            FUN_00767160(&DAT_00a37c64,(*pppppppuVar10)[3]);

            uVar11 = (*(code *)(*unaff_EDI)[6])(&DAT_00a97b84,2);

            pppppppuStack_30 = (undefined *******)0x0;

            ppppppppuVar17 = unaff_EDI;

          }

          ppuStack_4c = (undefined **)((uint)ppuStack_4c | uVar11);

          pppppppuVar10 = pppppppuVar10 + 1;

        } while (pppppppuVar10 != pppppppuVar15);

      }

      if (*(char *)((int)ppppppppuVar16 + 0x25) == '\0') {

        ppppppppuVar5 = (undefined ********)ppppppppuVar16[2];

        if (*(char *)((int)ppppppppuVar5 + 0x25) == '\0') {

          cVar1 = *(char *)((int)*ppppppppuVar5 + 0x25);

          ppppppppuVar16 = ppppppppuVar5;

          ppppppppuVar5 = (undefined ********)*ppppppppuVar5;

          while (cVar1 == '\0') {

            cVar1 = *(char *)((int)*ppppppppuVar5 + 0x25);

            ppppppppuVar16 = ppppppppuVar5;

            ppppppppuVar5 = (undefined ********)*ppppppppuVar5;

          }

        }

        else {

          cVar1 = *(char *)((int)ppppppppuVar16[1] + 0x25);

          ppppppppuVar7 = (undefined ********)ppppppppuVar16[1];

          ppppppppuVar5 = ppppppppuVar16;

          while ((ppppppppuVar16 = ppppppppuVar7, cVar1 == '\0' &&

                 (ppppppppuVar5 == (undefined ********)ppppppppuVar16[2]))) {

            cVar1 = *(char *)((int)ppppppppuVar16[1] + 0x25);

            ppppppppuVar7 = (undefined ********)ppppppppuVar16[1];

            ppppppppuVar5 = ppppppppuVar16;

          }

        }

      }

    } while (ppppppppuVar16 != ppppppppuVar19);

  }

  pppuVar6 = pppuStack_1c;

  apppppuStack_18[0] = (undefined *****)pppuStack_1c[0xe];

  ppppuVar18 = (undefined ****)pppuStack_1c[0xd];

  if ((undefined *****)ppppuVar18 != apppppuStack_18[0]) {

    do {

      if (uStack_34 == 0) {

        pppuStack_1c = *ppppuVar18;

        uVar11 = (*(code *)(*ppppppppuVar17)[6])(&pppuStack_1c,4);

        local_54 = (int *)((uint)local_54 | uVar11);

LAB_0071a20c:

        pppuStack_24 = ppppuVar18[1];

        uVar11 = (*(code *)(*ppppppppuVar17)[6])(&pppuStack_24,4);

        uStack_5c = uStack_5c | uVar11;

LAB_0071a266:

        pppuStack_2c = ppppuVar18[2];

        uVar11 = (*(code *)(*ppppppppuVar17)[6])(&pppuStack_2c,4);

        pppppuStack_64 = (undefined *****)((uint)pppppuStack_64 | uVar11);

LAB_0071a2c0:

        uStack_34 = 0xffffffff;

        (*(code *)(*ppppppppuVar17)[6])(&uStack_34,4);

        uVar14 = extraout_var;

LAB_0071a319:

        uStack_3c = CONCAT22(uVar14,*(uint16_t *)(ppppuVar18 + 5));

        (*(code *)(*ppppppppuVar17)[6])(&uStack_3c,2);

LAB_0071a375:

        pppuStack_44 = ppppuVar18[3];

        uVar11 = (*(code *)(*ppppppppuVar17)[6])(&pppuStack_44,4);

      }

      else {

        uVar11 = FUN_00767160(&DAT_00a37c64,*ppppuVar18);

        ppppppppuVar17 = ppppppppuStack_50;

        ppuStack_4c = (undefined **)((uint)ppuStack_4c | uVar11);

        uVar11 = (*(code *)(*ppppppppuStack_50)[6])(&DAT_00a97b84,2);

        local_54 = (int *)((uint)local_54 | uVar11);

        ppppppppuStack_38 = (undefined ********)0x0;

        if (uStack_3c == 0) goto LAB_0071a20c;

        uVar11 = FUN_00767160(&DAT_00a37c64,ppppuVar18[1]);

        ppppppppuVar17 = local_58;

        local_54 = (int *)((uint)local_54 | uVar11);

        uVar11 = (*(code *)(*local_58)[6])(&DAT_00a97b84,2);

        uStack_5c = uStack_5c | uVar11;

        ppppppppuStack_40 = (undefined ********)0x0;

        if (pppuStack_44 == (undefined ***)0x0) goto LAB_0071a266;

        uVar11 = FUN_00767160(&DAT_00a37c64,ppppuVar18[2]);

        ppppppppuVar17 = ppppppppuStack_60;

        uStack_5c = uStack_5c | uVar11;

        uVar11 = (*(code *)(*ppppppppuStack_60)[6])(&DAT_00a97b84,2);

        pppppuStack_64 = (undefined *****)((uint)pppppuStack_64 | uVar11);

        ppppppppuStack_48 = (undefined ********)0x0;

        if (ppuStack_4c == (undefined **)0x0) goto LAB_0071a2c0;

        uVar11 = FUN_00767160(&DAT_00a37c64,0xffffffff);

        pppppuStack_64 = (undefined *****)((uint)pppppuStack_64 | uVar11);

        (*(code *)(*ppppppppuStack_68)[6])(&DAT_00a97b84,2);

        ppppppppuStack_50 = (undefined ********)0x0;

        ppppppppuVar17 = ppppppppuStack_68;

        uVar14 = extraout_var_00;

        if (local_54 == (int *)0x0) goto LAB_0071a319;

        FUN_00767160(&DAT_00a37c64,(int)*(short *)(ppppuVar18 + 5));

        (*(code *)(*ppppppppuVar20)[6])(&DAT_00a97b84,2);

        local_58 = (undefined ********)0x0;

        ppppppppuVar17 = ppppppppuVar20;

        if (uStack_5c == 0) goto LAB_0071a375;

        FUN_00767160(&DAT_00a37c64,ppppuVar18[3]);

        uVar11 = (*(code *)(*unaff_EDI)[6])(&DAT_00a97b84,2);

        pppppppuStack_30 = (undefined *******)0x0;

        ppppppppuVar17 = unaff_EDI;

      }

      ppuStack_4c = (undefined **)((uint)ppuStack_4c | uVar11);

      ppppuVar18 = ppppuVar18 + 7;

    } while ((undefined *****)ppppuVar18 != apppppuStack_18[0]);

  }

  uVar13 = FUN_0076cec0(&pppuStack_1c,"Writing indexBegin <%d>.",

                        (int)pppuVar6[0xb] + (int)pppppppuStack_88);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoPackOSFile.cpp",399,1,uVar13);

  (*(code *)(*pppuVar6)[1])(4,2);

  (*(code *)(*pppuVar6)[6])(&pppppppuStack_88,4);

  FUN_005b2ba0();

  if (ppppppppuStack_68 != (undefined ********)0x0) {

    operator_delete__(ppppppppuStack_68);

  }

  uStack_34 = 0xffffffff;

  FUN_00481690(&pppuStack_2c,*pppppppuStack_88,pppppppuStack_88);

                    /* WARNING: Subroutine does not return */

  operator_delete(pppppppuStack_88);

}
