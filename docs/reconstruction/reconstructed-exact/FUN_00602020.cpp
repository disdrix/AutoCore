// =============================================================================
// FUN_00602020
// -----------------------------------------------------------------------------
// Stable ID: aa_00602020
// Address:   0x00602020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00602020 @ 0x00602020
// Stable ID: aa_00602020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×16, return×4, goto×1.
//  - Notable callees: CONCAT31×4, CONCAT21×2, NAN×2, FUN_00602020.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_00602020(int param_1,int param_2,char param_3,char param_4)



{

  short sVar1;

  short sVar2;

  uint16_t extraout_var;

  uint16_t uVar5;

  int iVar3;

  short *psVar4;

  uint16_t extraout_var_00;

  short sVar6;

  short sVar7;

  float fVar8;

  float fVar9;

  short unaff_retaddr;

  

  fVar8 = g_flOne;

  if (param_3 == '\0') {

    iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

    fVar9 = (float)*(int *)(iVar3 + 200 + param_2) * *(float *)(param_1 + 0xc);

  }

  else {

    if (*(float *)(param_1 + 0xc) == 0.0) goto LAB_00602095;

    iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

    fVar9 = (g_flOne / *(float *)(param_1 + 0xc)) * (float)*(int *)(iVar3 + 200 + param_2);

  }

  *(int *)(iVar3 + param_2 + 200) = (int)fVar9;

LAB_00602095:

  iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x3c);

  sVar7 = *(short *)(iVar3 + 0x402);

  sVar6 = *(short *)(iVar3 + 0x3fe);

  sVar1 = *(short *)(iVar3 + 0x400);

  sVar2 = *(short *)(iVar3 + 0x404);

  if (param_3 == '\0') {

    (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x184))

              (*(uint32_t /* width from decompiler */ *)(param_1 + 4));

    param_3 = (char)sVar7;

    uVar5 = extraout_var_00;

    if (param_3 == '\0') {

      iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

      psVar4 = (short *)(iVar3 + 0xec + param_2);

      *psVar4 = *psVar4 + *(short *)(param_1 + 0x84);

      uVar5 = (uint16_t)((uint)(iVar3 + 0xec + param_2) >> 0x10);

    }

    fVar8 = *(float *)(param_1 + 0x88);

    iVar3 = (uint)CONCAT21(uVar5,(fVar8 == 0.0) << 6 | NAN(fVar8) << 2 | 2U | fVar8 < 0.0) << 8;

    if (fVar8 != 0.0) {

      fVar8 = (float)(int)sVar6;

      psVar4 = (short *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xf0 + param_2);

      if (fVar8 == 0.0) {

        sVar7 = *(short *)(param_1 + 0x8c);

      }

      else {

        sVar7 = (short)(int)(fVar8 * *(float *)(param_1 + 0x88));

      }

      *psVar4 = *psVar4 + sVar7;

      fVar8 = (float)(int)sVar1;

      if (fVar8 == 0.0) {

        iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

        sVar7 = *(short *)(param_1 + 0x8e);

      }

      else {

        iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

        sVar7 = (short)(int)(fVar8 * *(float *)(param_1 + 0x88));

      }

      psVar4 = (short *)(iVar3 + 0xf2 + param_2);

      *psVar4 = *psVar4 + sVar7;

      fVar8 = (float)(int)sVar2;

      psVar4 = (short *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xf4 + param_2);

      if (fVar8 == 0.0) {

        sVar7 = *(short *)(param_1 + 0x90);

      }

      else {

        sVar7 = (short)(int)(fVar8 * *(float *)(param_1 + 0x88));

      }

      *psVar4 = *psVar4 + sVar7;

      if ((float)(int)unaff_retaddr != 0.0) {

        psVar4 = (short *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xf6 + param_2);

        *psVar4 = *psVar4 + (short)(int)((float)(int)unaff_retaddr * *(float *)(param_1 + 0x88));

        return CONCAT31((int3)((uint)psVar4 >> 8),1);

      }

      iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

      psVar4 = (short *)(iVar3 + 0xf6 + param_2);

      *psVar4 = *psVar4 + *(short *)(param_1 + 0x92);

      iVar3 = iVar3 + 0xf6 + param_2;

    }

  }

  else {

    uVar5 = (uint16_t)((uint)iVar3 >> 0x10);

    if (*(float *)(param_1 + 4) != 0.0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x184))

                (fVar8 / *(float *)(param_1 + 4));

      uVar5 = extraout_var;

    }

    if (param_4 == '\0') {

      iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

      psVar4 = (short *)(iVar3 + 0xec + param_2);

      *psVar4 = *psVar4 - *(short *)(param_1 + 0x84);

      uVar5 = (uint16_t)((uint)(iVar3 + 0xec + param_2) >> 0x10);

    }

    fVar8 = *(float *)(param_1 + 0x88);

    iVar3 = (uint)CONCAT21(uVar5,(fVar8 == 0.0) << 6 | NAN(fVar8) << 2 | 2U | fVar8 < 0.0) << 8;

    if (fVar8 != 0.0) {

      fVar8 = (float)(int)sVar6;

      psVar4 = (short *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xf0 + param_2);

      if (fVar8 == 0.0) {

        sVar6 = *(short *)(param_1 + 0x8c);

      }

      else {

        sVar6 = (short)(int)(fVar8 * *(float *)(param_1 + 0x88));

      }

      *psVar4 = *psVar4 - sVar6;

      fVar8 = (float)(int)sVar1;

      if (fVar8 == 0.0) {

        iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

        sVar6 = *(short *)(param_1 + 0x8e);

      }

      else {

        iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

        sVar6 = (short)(int)(fVar8 * *(float *)(param_1 + 0x88));

      }

      psVar4 = (short *)(iVar3 + 0xf2 + param_2);

      *psVar4 = *psVar4 - sVar6;

      fVar8 = (float)(int)sVar7;

      psVar4 = (short *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xf4 + param_2);

      if (fVar8 == 0.0) {

        sVar7 = *(short *)(param_1 + 0x90);

      }

      else {

        sVar7 = (short)(int)(fVar8 * *(float *)(param_1 + 0x88));

      }

      *psVar4 = *psVar4 - sVar7;

      fVar8 = (float)(int)sVar2;

      if (fVar8 != 0.0) {

        psVar4 = (short *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xf6 + param_2);

        *psVar4 = *psVar4 - (short)(int)(fVar8 * *(float *)(param_1 + 0x88));

        return CONCAT31((int3)((uint)psVar4 >> 8),1);

      }

      iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

      psVar4 = (short *)(iVar3 + 0xf6 + param_2);

      *psVar4 = *psVar4 - *(short *)(param_1 + 0x92);

      return CONCAT31((int3)((uint)(iVar3 + 0xf6 + param_2) >> 8),1);

    }

  }

  return CONCAT31((int3)((uint)iVar3 >> 8),1);

}
