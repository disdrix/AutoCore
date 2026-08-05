// =============================================================================
// FUN_0092c890
// -----------------------------------------------------------------------------
// Stable ID: aa_0092c890
// Address:   0x0092c890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092c890 @ 0x0092c890
// Stable ID: aa_0092c890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0092c890.
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

void FUN_0092c890(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ local_8 [2];

  

  local_8[0] = 0x20ae;

  if (*(int *)(in_EAX + 0xc78) != 0) {

    (**(code **)(**(int **)(in_EAX + 0xc78) + 0x18))(0xffffffff,local_8,8,0);

  }

  return;

}
