// =============================================================================
// FUN_007998d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007998d0
// Address:   0x007998d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007998d0 @ 0x007998d0
// Stable ID: aa_007998d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00799460, FUN_007998d0.
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

void FUN_007998d0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint16_t *param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  uint16_t local_4 [2];

  

  cVar1 = FUN_00799460(param_1,param_2,local_4,param_4);

  if (cVar1 != '\0') {

    *param_3 = local_4[0];

  }

  return;

}
