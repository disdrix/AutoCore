// =============================================================================
// FUN_006eedd0
// -----------------------------------------------------------------------------
// Stable ID: aa_006eedd0
// Address:   0x006eedd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006eedd0 @ 0x006eedd0
// Stable ID: aa_006eedd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006cb4b0×12, FUN_006eedd0.
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

void FUN_006eedd0(void)



{

  FUN_006cb4b0(4,1);

  FUN_006cb4b0(5,1);

  FUN_006cb4b0(6,1);

  FUN_006cb4b0(7,1);

  FUN_006cb4b0(8,1);

  FUN_006cb4b0(0x17,1);

  FUN_006cb4b0(0xb,2);

  FUN_006cb4b0(10,2);

  FUN_006cb4b0(0x13,3);

  FUN_006cb4b0(1,0x10);

  FUN_006cb4b0(0x12,0xd);

  FUN_006cb4b0(0xe,0xd);

  return;

}
