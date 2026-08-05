// =============================================================================
// FUN_00589e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00589e60
// Address:   0x00589e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00589e60 @ 0x00589e60
// Stable ID: aa_00589e60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: ABS, CONCAT22, FUN_00589e60.
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



void FUN_00589e60(int *param_1,int param_2,float param_3)



{

  int *piVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  bool bVar9;

  int *piVar10;

  int iVar11;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t uVar12;

  float unaff_ESI;

  float unaff_EDI;

  float fVar13;

  

  if (param_1 != (int *)0x0) {

    piVar10 = (int *)(**(code **)(*param_1 + 0x214))();

    fVar13 = *(float *)(param_2 + 0x4c);

    fVar2 = *(float *)(param_2 + 0x48);

    fVar3 = *(float *)(param_2 + 0x44);

    fVar4 = *(float *)(param_2 + 0xc0);

    fVar5 = *(float *)(param_2 + 0xf8);

    fVar6 = *(float *)(param_2 + 0x100);

    fVar7 = *(float *)(param_2 + 300);

    fVar8 = *(float *)(param_2 + 0x130);

    iVar11 = (**(code **)(*param_1 + 0x19c))();

    if ((((iVar11 != 0) &&

         (piVar1 = (int *)(*(int *)(*(int *)(iVar11 + 4) + 4) + 4 + iVar11), piVar1 != (int *)0x0))

        && (iVar11 = piVar1[0x29], iVar11 != 0)) &&

       ((*(char *)(iVar11 + 0x7e) != '\0' || (*(char *)(iVar11 + 0xf5) != '\0')))) {

      if ((fVar13 < DAT_00aaa668) || (g_flOne < fVar13)) {

        (**(code **)(*piVar1 + 0x2a0))((int)(fVar13 * param_3));

      }

      else {

        (**(code **)(*piVar1 + 0x29c))(fVar13 * param_3);

      }

    }

    if (piVar10 != (int *)0x0) {

      bVar9 = fVar8 != g_flZero;

      piVar10[0x7b] = (int)(fVar7 * param_3 + (float)piVar10[0x7b]);

      fVar13 = g_flOne;

      if ((bVar9) && (fVar13 = fVar8, param_3 != g_flOne)) {

        fVar13 = g_flOne / fVar8;

      }

      fVar13 = (float)piVar10[0x7a] * fVar13;

      piVar10[0x7a] = (int)fVar13;

      if (ABS(fVar13 - g_flOne) < (float)_DAT_00aaaaa8) {

        piVar10[0x7a] = (int)g_flOne;

      }

      (**(code **)(*piVar10 + 0x8c))(1,fVar4 * param_3);

      (**(code **)(*piVar10 + 0x8c))(0,fVar8 * fVar13);

      (**(code **)(*piVar10 + 0x90))(1,fVar7 * fVar3);

      (**(code **)(*piVar10 + 0x90))(0,unaff_EDI * fVar6);

      if ((unaff_ESI < DAT_00aaa668) || (g_flOne < unaff_ESI)) {

        (**(code **)(*piVar10 + 0xb8))((int)(unaff_ESI * fVar5));

        uVar12 = extraout_var_00;

      }

      else {

        (**(code **)(*piVar10 + 0xb4))(unaff_ESI * fVar5);

        uVar12 = extraout_var;

      }

      if (*(short *)((int)piVar10 + 0x12e) < (short)piVar10[0x4b]) {

        (**(code **)(*piVar10 + 0xac))(CONCAT22(uVar12,*(short *)((int)piVar10 + 0x12e)));

      }

      piVar10[0x98] = (int)(unaff_ESI * fVar2 + (float)piVar10[0x98]);

      piVar10[0x97] = (int)(unaff_EDI * fVar2 + (float)piVar10[0x97]);

      piVar10[0x99] = (int)(fVar7 * fVar2 + (float)piVar10[0x99]);

      piVar10[0x9a] = (int)(fVar8 * fVar2 + (float)piVar10[0x9a]);

      piVar10[0x4c] = (int)(fVar4 * fVar2 + (float)piVar10[0x4c]);

    }

  }

  return;

}
