// =============================================================================
// FUN_00454830
// -----------------------------------------------------------------------------
// Stable ID: aa_00454830
// Address:   0x00454830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00454830 @ 0x00454830
// Stable ID: aa_00454830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1, goto×1.
//  - Notable callees: CONCAT31×2, FUN_00454830, FUN_00454a80, FUN_00455950.
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

uint32_t /* width from decompiler */ * FUN_00454830(uint32_t /* width from decompiler */ *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  char cVar6;

  int unaff_EBX;

  float *unaff_ESI;

  uint32_t /* width from decompiler */ uVar7;

  

  puVar3 = param_1;

  puVar5 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(unaff_EBX + 4))[1];

  cVar1 = *(char *)((int)puVar5 + 0x49);

  cVar6 = '\x01';

  param_1 = (uint32_t /* width from decompiler */ *)CONCAT31(param_1._1_3_,1);

  puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 4);

  while (cVar1 == '\0') {

    if ((*unaff_ESI <= (float)puVar5[3] && (float)puVar5[3] != *unaff_ESI) ||

       ((*unaff_ESI < (float)puVar5[3] || *unaff_ESI == (float)puVar5[3] &&

        ((unaff_ESI[1] <= (float)puVar5[4] && (float)puVar5[4] != unaff_ESI[1] ||

         ((unaff_ESI[1] < (float)puVar5[4] || unaff_ESI[1] == (float)puVar5[4] &&

          ((unaff_ESI[2] <= (float)puVar5[5] && (float)puVar5[5] != unaff_ESI[2] ||

           ((unaff_ESI[2] < (float)puVar5[5] || unaff_ESI[2] == (float)puVar5[5] &&

            ((unaff_ESI[3] <= (float)puVar5[6] && (float)puVar5[6] != unaff_ESI[3] ||

             ((unaff_ESI[3] < (float)puVar5[6] || unaff_ESI[3] == (float)puVar5[6] &&

              ((unaff_ESI[4] <= (float)puVar5[7] && (float)puVar5[7] != unaff_ESI[4] ||

               ((unaff_ESI[4] < (float)puVar5[7] || unaff_ESI[4] == (float)puVar5[7] &&

                (unaff_ESI[5] <= (float)puVar5[8] && (float)puVar5[8] != unaff_ESI[5])))))))))))))))

         ))))) {

      puVar4 = (uint32_t /* width from decompiler */ *)*puVar5;

      cVar6 = '\x01';

    }

    else {

      puVar4 = (uint32_t /* width from decompiler */ *)puVar5[2];

      cVar6 = '\0';

    }

    cVar1 = *(char *)((int)puVar4 + 0x49);

    param_1._1_3_ = (undefined3)((uint)param_1 >> 8);

    param_1 = (uint32_t /* width from decompiler */ *)CONCAT31(param_1._1_3_,cVar6);

    puVar2 = puVar5;

    puVar5 = puVar4;

  }

  if (cVar6 != '\0') {

    if (puVar2 == (uint32_t /* width from decompiler */ *)**(int **)(unaff_EBX + 4)) {

      uVar7 = 1;

      goto LAB_00454989;

    }

    FUN_00455950();

  }

  uVar7 = param_1;

  if ((*unaff_ESI < (float)puVar2[3] || *unaff_ESI == (float)puVar2[3]) &&

     ((*unaff_ESI <= (float)puVar2[3] && (float)puVar2[3] != *unaff_ESI ||

      ((unaff_ESI[1] < (float)puVar2[4] || unaff_ESI[1] == (float)puVar2[4] &&

       ((unaff_ESI[1] <= (float)puVar2[4] && (float)puVar2[4] != unaff_ESI[1] ||

        ((unaff_ESI[2] < (float)puVar2[5] || unaff_ESI[2] == (float)puVar2[5] &&

         ((unaff_ESI[2] <= (float)puVar2[5] && (float)puVar2[5] != unaff_ESI[2] ||

          ((unaff_ESI[3] < (float)puVar2[6] || unaff_ESI[3] == (float)puVar2[6] &&

           ((unaff_ESI[3] <= (float)puVar2[6] && (float)puVar2[6] != unaff_ESI[3] ||

            ((unaff_ESI[4] < (float)puVar2[7] || unaff_ESI[4] == (float)puVar2[7] &&

             ((unaff_ESI[4] <= (float)puVar2[7] && (float)puVar2[7] != unaff_ESI[4] ||

              (unaff_ESI[5] < (float)puVar2[8] || unaff_ESI[5] == (float)puVar2[8]))))))))))))))))))

     )) {

    *puVar3 = puVar2;

    *(uint8_t *)(puVar3 + 1) = 0;

    return puVar3;

  }

LAB_00454989:

  puVar5 = (uint32_t /* width from decompiler */ *)FUN_00454a80(&param_1,uVar7,unaff_ESI);

  *puVar3 = *puVar5;

  *(uint8_t *)(puVar3 + 1) = 1;

  return puVar3;

}
