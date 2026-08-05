// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00693020
// -----------------------------------------------------------------------------
// Stable ID: aa_00693020
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00693020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×9, do×3, while×3, return×2, goto×1.
//  - Notable callees: fpatan×4, FUN_00691940×3, FUN_0069fec0×2, FUN_00693020, SQRT, fcos, fsin.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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



void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00693020(int param_1,int param_2,int param_3)



{

  float fVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  float10 fVar9;

  float10 fVar10;

  float10 fVar11;

  float local_c;

  float local_8;

  float local_4;

  

  fVar9 = (float10)FUN_0069fec0(0);

  fVar1 = *(float *)(param_2 + 0x14);

  uVar7 = *(uint *)(param_1 + 0x34);

  uVar6 = 0;

  if (uVar7 != 0) {

    local_c = 0.0;

    do {

      fVar3 = (float)(int)uVar6;

      if ((int)uVar6 < 0) {

        fVar3 = fVar3 + _DAT_00aaa5dc;

      }

      fVar4 = (float)(int)uVar7;

      if ((int)uVar7 < 0) {

        fVar4 = fVar4 + _DAT_00aaa5dc;

      }

      fVar3 = g_flOne - fVar3 / (fVar4 - g_flOne);

      local_8 = -(fVar3 * *(float *)(param_2 + 0x14));

      fVar10 = (float10)FUN_0069fec0(fVar3);

      local_4 = (float)(fVar10 * (float10)*(float *)(param_2 + 0x14) -

                       (float10)(float)(fVar9 * (float10)fVar1));

      FUN_00691940(&local_c);

      uVar7 = *(uint *)(param_1 + 0x34);

      uVar6 = uVar6 + 1;

    } while (uVar6 < uVar7);

  }

  iVar5 = *(int *)(param_1 + 0x34) + -2;

  if (-1 < iVar5) {

    iVar5 = iVar5 * 0xc;

    iVar8 = *(int *)(param_1 + 0x34) + -1;

    do {

      iVar2 = *(int *)(param_3 + 4);

      local_c = *(float *)(iVar2 + iVar5);

      local_8 = *(float *)(iVar2 + 4 + iVar5) * DAT_00aaa668;

      local_4 = *(float *)(iVar2 + iVar5 + 8);

      FUN_00691940(&local_c);

      iVar5 = iVar5 + -0xc;

      iVar8 = iVar8 + -1;

    } while (iVar8 != 0);

  }

  uVar7 = 0;

  do {

    iVar5 = *(int *)(param_3 + 4);

    if (iVar5 == 0) {

      return;

    }

    uVar6 = (*(int *)(param_3 + 8) - iVar5) / 0xc;

    if (uVar6 <= uVar7) {

      return;

    }

    if (uVar7 == *(int *)(param_1 + 0x34) - 1U) {

      fVar9 = (float10)_DAT_00af5538;

    }

    else {

      if (uVar7 == 0) {

        fVar9 = (float10)fpatan((float10)*(float *)(iVar5 + 0x14) - (float10)*(float *)(iVar5 + 8),

                                (float10)*(float *)(iVar5 + 0x10) - (float10)*(float *)(iVar5 + 4));

      }

      else {

        if (uVar7 == uVar6 - 1) {

          iVar8 = iVar5 + uVar7 * 0xc;

          fVar9 = (float10)fpatan((float10)*(float *)(iVar5 + 8 + uVar7 * 0xc) -

                                  (float10)*(float *)(iVar8 + -4),

                                  (float10)*(float *)(iVar8 + 4) - (float10)*(float *)(iVar8 + -8));

          fVar9 = fVar9 + (float10)_DAT_00af553c;

          goto LAB_006931b3;

        }

        iVar8 = iVar5 + uVar7 * 0xc;

        fVar9 = (float10)fpatan((float10)*(float *)(iVar5 + 8 + uVar7 * 0xc) -

                                (float10)*(float *)(iVar8 + -4),

                                (float10)*(float *)(iVar8 + 4) - (float10)*(float *)(iVar8 + -8));

        fVar10 = (float10)fpatan((float10)*(float *)(iVar8 + 0x14) - (float10)*(float *)(iVar8 + 8),

                                 (float10)*(float *)(iVar8 + 0x10) - (float10)*(float *)(iVar8 + 4))

        ;

        fVar9 = (fVar10 + fVar9) * (float10)DAT_00a0f298;

      }

      fVar9 = fVar9 + (float10)_DAT_00af5538;

    }

LAB_006931b3:

    fVar10 = (float10)fcos(fVar9);

    fVar9 = (float10)fsin(fVar9);

    fVar11 = (float10)g_flOne / SQRT(fVar10 * fVar10 + fVar9 * (float10)(float)fVar9);

    local_4 = (float)fVar11;

    local_c = (float)(fVar11 * (float10)g_flZero);

    local_8 = (float)(fVar10 * (float10)local_4);

    local_4 = (float)fVar9 * local_4;

    FUN_00691940(&local_c);

    uVar7 = uVar7 + 1;

  } while( true );

}
