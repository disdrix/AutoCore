// =============================================================================
// FUN_008467e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008467e0
// Address:   0x008467e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008467e0 @ 0x008467e0
// Stable ID: aa_008467e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_008467e0.
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

uint FUN_008467e0(void)



{

  int in_EAX;

  uint uVar1;

  

  uVar1 = 0;

  if (((in_EAX != 0) && (uVar1 = *(uint *)(*(int *)(in_EAX + 0xa8) + 0x3c), uVar1 != 0)) &&

     ((*(int *)(uVar1 + 0x3bc) != -1 ||

      ((*(int *)(uVar1 + 0x3c0) != -1 || (*(int *)(uVar1 + 0x3c4) != -1)))))) {

    return CONCAT31((int3)(uVar1 >> 8),1);

  }

  return uVar1 & 0xffffff00;

}
