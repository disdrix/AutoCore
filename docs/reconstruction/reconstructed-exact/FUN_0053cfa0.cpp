// =============================================================================
// FUN_0053cfa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0053cfa0
// Address:   0x0053cfa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053cfa0 @ 0x0053cfa0
// Stable ID: aa_0053cfa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00517680, FUN_0053cfa0, FUN_00785ca0.
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

uint __fastcall FUN_0053cfa0(int param_1)



{

  uint uVar1;

  

  uVar1 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + -0x48));

  if ((char)uVar1 != '\0') {

    return uVar1 & 0xffffff00;

  }

  uVar1 = FUN_00517680();

  return uVar1;

}
