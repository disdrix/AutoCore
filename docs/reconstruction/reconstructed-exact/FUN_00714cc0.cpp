// =============================================================================
// FUN_00714cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00714cc0
// Address:   0x00714cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00714cc0 @ 0x00714cc0
// Stable ID: aa_00714cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00714cc0.
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



float10 FUN_00714cc0(float param_1)



{

  float10 fVar1;

  float10 fVar2;

  

  fVar1 = (float10)g_flOne;

  fVar2 = (float10)param_1 + (float10)_DAT_00a0d164;

  if (fVar2 < (float10)g_flMultiKillCountBlend) {

    do {

      fVar2 = fVar2 * (float10)DAT_00a110d8;

      fVar1 = fVar1 * (float10)_DAT_00a110d4;

    } while (fVar2 < (float10)g_flMultiKillCountBlend);

  }

  return (((float10)_DAT_00a110cc - fVar2 * (float10)_DAT_00a110d0) * fVar2 + (float10)_DAT_00a110c8

         ) * fVar1;

}
