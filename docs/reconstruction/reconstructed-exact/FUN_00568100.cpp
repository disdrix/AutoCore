// =============================================================================
// FUN_00568100
// -----------------------------------------------------------------------------
// Stable ID: aa_00568100
// Address:   0x00568100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00568100 @ 0x00568100
// Stable ID: aa_00568100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: ABS, FUN_00568100, FUN_005d68b0, SQRT.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00568100(float *param_1,uint8_t *param_2)



{

  float *local_4;

  

  local_4 = param_1;

  FUN_005d68b0(&local_4);

  if (((char)local_4 != '\0') &&

     (ABS(SQRT(param_1[3] * param_1[3] +

               param_1[2] * param_1[2] + param_1[1] * param_1[1] + *param_1 * *param_1) - g_flOne) <

      _DAT_009d2f1c)) {

    *param_2 = 1;

    return;

  }

  *param_2 = 0;

  return;

}
