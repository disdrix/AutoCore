// =============================================================================
// FUN_0060ec80
// -----------------------------------------------------------------------------
// Stable ID: aa_0060ec80
// Address:   0x0060ec80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060ec80 @ 0x0060ec80
// Stable ID: aa_0060ec80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0060eb90, FUN_0060ec80.
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

float10 __thiscall FUN_0060ec80(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  float10 fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  if ((*(char *)(param_1 + 0x15) == '\0') && (*(int *)(param_1 + 0x10) != 0)) {

    fVar1 = (float10)FUN_0060eb90(param_2,param_3);

    fVar2 = (float)fVar1 / (float)*(int *)(param_1 + 0x10);

    fVar4 = fVar2;

    if (fVar2 <= 0.0) {

      fVar4 = 0.0;

    }

    fVar3 = g_flOne;

    if (g_flOne - fVar4 < g_flOne) {

      if (fVar2 <= 0.0) {

        fVar2 = 0.0;

      }

      fVar3 = g_flOne - fVar2;

    }

    return (float10)fVar3;

  }

  return (float10)g_flOne;

}
