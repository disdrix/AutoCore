// =============================================================================
// FUN_0056b860
// -----------------------------------------------------------------------------
// Stable ID: aa_0056b860
// Address:   0x0056b860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056b860 @ 0x0056b860
// Stable ID: aa_0056b860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: ABS, FUN_0056b6b0, FUN_0056b860, _CIacos, _CIpow.
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

float10 __fastcall FUN_0056b860(int param_1)



{

  float10 fVar1;

  float10 fVar2;

  float local_8;

  

  if (ABS(*(float *)(param_1 + 0xdc)) < g_flOne) {

    fVar1 = (float10)_CIacos();

    local_8 = (float)fVar1;

  }

  else {

    local_8 = 0.0;

    if (*(float *)(param_1 + 0xdc) <= 0.0) {

      local_8 = DAT_009d2f78;

    }

  }

  fVar1 = (float10)FUN_0056b6b0();

  fVar1 = fVar1 * (float10)local_8 * (float10)*(float *)(param_1 + 0xe8) *

          (float10)*(float *)(param_1 + 0xe8);

  if ((*(byte *)(param_1 + 0xc4) & 1) != 0) {

    fVar2 = (float10)_CIpow();

    fVar1 = fVar2 * (float10)(float)fVar1;

  }

  return fVar1 * (float10)g_flMultiKillCountBlend;

}
