// =============================================================================
// FUN_00717ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00717ac0
// Address:   0x00717ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00717ac0 @ 0x00717ac0
// Stable ID: aa_00717ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_00717ac0, ftol.
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



void FUN_00717ac0(float param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,int param_5,

                 int param_6,int param_7,int param_8,float *param_9,int param_10,float param_11)



{

  int iVar1;

  int iVar2;

  int iVar3;

  float *pfVar4;

  float10 extraout_ST0;

  float10 fVar5;

  float10 fVar6;

  

  iVar2 = param_6;

  *(uint32_t /* width from decompiler */ *)(param_6 + 0x908) = *(uint32_t /* width from decompiler */ *)(param_6 + 0x904);

  *(uint32_t /* width from decompiler */ *)(param_6 + 0xa0c) = *(uint32_t /* width from decompiler */ *)(param_6 + 0xa08);

  if (0 < param_4) {

    param_6 = param_4;

    pfVar4 = param_9;

    do {

      iVar3 = ftol();

      iVar1 = iVar3 * 4;

      fVar5 = extraout_ST0 - (float10)iVar3;

      iVar3 = iVar3 * 4;

      fVar6 = ((float10)*(float *)(iVar1 + 4 + param_8) - (float10)*(float *)(iVar3 + param_8)) *

              fVar5 + (float10)*(float *)(iVar3 + param_8);

      *(float *)((param_7 - (int)param_9) + -4 + (int)(pfVar4 + 1)) =

           (float)(((((float10)*(float *)(iVar1 + 0x80c + iVar2) -

                     (float10)*(float *)(iVar3 + 0x808 + iVar2)) * fVar5 +

                    (float10)*(float *)(iVar3 + 0x808 + iVar2)) - fVar6) * (float10)param_11 + fVar6

                  );

      fVar6 = ((float10)*(float *)(iVar1 + 4 + param_10) - (float10)*(float *)(iVar3 + param_10)) *

              fVar5 + (float10)*(float *)(iVar3 + param_10);

      param_6 = param_6 + -1;

      *pfVar4 = (float)(((((float10)*(float *)(iVar1 + 0x910 + iVar2) -

                          (float10)*(float *)(iVar3 + 0x90c + iVar2)) * fVar5 +

                         (float10)*(float *)(iVar3 + 0x90c + iVar2)) - fVar6) * (float10)param_11 +

                       fVar6);

      pfVar4 = pfVar4 + 1;

    } while (param_6 != 0);

  }

  if (param_5 < param_4) {

    param_4 = param_4 - param_5;

    pfVar4 = (float *)(param_7 + param_5 * 4);

    do {

      param_4 = param_4 + -1;

      *pfVar4 = param_1 + *pfVar4;

      pfVar4 = pfVar4 + 1;

    } while (param_4 != 0);

  }

  return;

}
