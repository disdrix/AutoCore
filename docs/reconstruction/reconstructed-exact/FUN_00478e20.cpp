// =============================================================================
// FUN_00478e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00478e20
// Address:   0x00478e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00478e20 @ 0x00478e20
// Stable ID: aa_00478e20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00478e20.
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

void FUN_00478e20(void)



{

  int in_EAX;

  

  *(undefined **)(in_EAX + 0x44) = &DAT_00a267e0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x4c) = 9;

  *(undefined **)(in_EAX + 0x48) = &DAT_00a26fe0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x50) = 5;

  return;

}
