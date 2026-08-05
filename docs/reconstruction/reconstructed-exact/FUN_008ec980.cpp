// =============================================================================
// FUN_008ec980
// -----------------------------------------------------------------------------
// Stable ID: aa_008ec980
// Address:   0x008ec980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ec980 @ 0x008ec980
// Stable ID: aa_008ec980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×10, return×2.
//  - Notable callees: FUN_008ec320, FUN_008ec980.
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

void FUN_008ec980(void)



{

  char cVar1;

  int unaff_ESI;

  float in_XMM0_Da;

  float fVar2;

  float fVar3;

  

  fVar3 = g_flOne;

  if (*(int *)(unaff_ESI + 0x50c) == 0) {

    fVar2 = in_XMM0_Da + *(float *)(unaff_ESI + 0x524);

    *(float *)(unaff_ESI + 0x524) = fVar2;

    if (fVar3 <= fVar2) {

      if (g_flLevelUpUiBase_Inferred < fVar2) {

        *(float *)(unaff_ESI + 0x524) = g_flLevelUpUiBase_Inferred;

      }

    }

    else {

      *(float *)(unaff_ESI + 0x524) = fVar3;

    }

    fVar2 = DAT_00a0f298 / *(float *)(unaff_ESI + 0x524);

    if (*(float *)(unaff_ESI + 0x528) <= fVar2 && fVar2 != *(float *)(unaff_ESI + 0x528)) {

      *(float *)(unaff_ESI + 0x528) = fVar2;

    }

    fVar3 = fVar3 - fVar2;

    if (fVar3 < *(float *)(unaff_ESI + 0x528)) {

      *(float *)(unaff_ESI + 0x528) = fVar3;

    }

    if (*(float *)(unaff_ESI + 0x52c) <= fVar2 && fVar2 != *(float *)(unaff_ESI + 0x52c)) {

      *(float *)(unaff_ESI + 0x52c) = fVar2;

    }

    if (fVar3 < *(float *)(unaff_ESI + 0x52c)) {

      *(float *)(unaff_ESI + 0x52c) = fVar3;

    }

    FUN_008ec320();

  }

  if (*(int **)(unaff_ESI + 0x574) != (int *)0x0) {

    (**(code **)(**(int **)(unaff_ESI + 0x574) + 0x34c))();

  }

  if (*(int **)(unaff_ESI + 0x5ac) != (int *)0x0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x5ac) + 0xd0))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0x5ac) + 0xcc))(0);

                    /* WARNING: Could not recover jumptable at 0x008eca70. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(unaff_ESI + 0x5ac) + 0x34c))();

      return;

    }

  }

  return;

}
