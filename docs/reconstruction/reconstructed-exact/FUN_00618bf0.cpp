// =============================================================================
// FUN_00618bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00618bf0
// Address:   0x00618bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00618bf0 @ 0x00618bf0
// Stable ID: aa_00618bf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×6, return×5.
//  - Notable callees: FUN_00627ec0×2, CVOGHBBase_GetRemainingSeconds, FUN_00618bf0.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ FUN_00618bf0(uint32_t /* width from decompiler */ param_1,int param_2,CVOGHBBase *param_3)



{

  int iVar1;

  int iVar2;

  float fVar3;

  

  if (param_3 == (CVOGHBBase *)0x0) {

    return 0;

  }

  if (*(int *)(param_2 + 0x5fc) == param_3[0x27].nPeriodMs) {

    iVar1 = FUN_00627ec0();

    iVar2 = FUN_00627ec0();

    if (iVar1 < iVar2) {

      return 2;

    }

    if (iVar2 == iVar1) {

      fVar3 = CVOGHBBase_GetRemainingSeconds(param_3);

      iVar1 = *(int *)(param_2 + 0x18);

      if (iVar1 == 0) {

        iVar1 = 1;

      }

      if (fVar3 < (float)(*(int *)(param_2 + 0x1c) * iVar1) * g_flMsToSeconds_Inferred) {

        return 2;

      }

    }

    return 1;

  }

  return 0;

}
