// =============================================================================
// FUN_006424f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006424f0
// Address:   0x006424f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006424f0 @ 0x006424f0
// Stable ID: aa_006424f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00641900×2, FUN_00638060, FUN_006416b0, FUN_00641860, FUN_006418e0, FUN_00641ad0, FUN_006424f0.
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

void FUN_006424f0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ unaff_retaddr;

  

  FUN_006416b0(9);

  iVar1 = FUN_00638060(param_1);

  if (0xffff < iVar1) {

    iVar1 = 0xffff;

  }

  FUN_006418e0(iVar1);

  FUN_00641860(param_1,iVar1);

  FUN_00641900(unaff_retaddr);

  FUN_00641900(param_1);

  FUN_00641ad0();

  return;

}
