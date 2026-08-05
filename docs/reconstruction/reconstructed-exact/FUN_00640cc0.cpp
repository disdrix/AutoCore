// =============================================================================
// FUN_00640cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00640cc0
// Address:   0x00640cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00640cc0 @ 0x00640cc0
// Stable ID: aa_00640cc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00640c30, FUN_00640cc0, FUN_00641680, FUN_006416b0, FUN_00641860, FUN_006418e0, FUN_00641900, FUN_00641960.
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

uint32_t /* width from decompiler */ __thiscall FUN_00640cc0(uint param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  

  FUN_00641960(param_1 + 8,param_1 & 0xffffff00);

  FUN_006416b0(0xc0);

  FUN_00641900(param_4);

  if (0xffff < param_3) {

    param_3 = 0xffff;

  }

  FUN_006418e0(param_3);

  FUN_00641860(param_2,param_3);

  uVar1 = FUN_00640c30();

  FUN_00641680();

  return uVar1;

}
