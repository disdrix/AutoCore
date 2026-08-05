// =============================================================================
// FUN_0071aaf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071aaf0
// Address:   0x0071aaf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071aaf0 @ 0x0071aaf0
// Stable ID: aa_0071aaf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×3, switch×1.
//  - Notable callees: ROUND×2, FUN_0071aaf0.
//  - Return sites: 3.

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



int __thiscall FUN_0071aaf0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int local_8;

  

  switch(param_1) {

  case 0:

  case 3:

    break;

  case 1:

    local_8 = (int)(longlong)ROUND((double)param_2 * _DAT_00aaa5c8 + _DAT_00aaa5c0);

    return local_8;

  case 2:

    local_8 = (int)(longlong)ROUND((double)param_2 * _DAT_00aaa5b8 + _DAT_00aaa5b0);

    return local_8;

  default:

    param_2 = 0;

  }

  return param_2;

}
