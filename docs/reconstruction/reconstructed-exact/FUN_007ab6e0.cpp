// =============================================================================
// FUN_007ab6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ab6e0
// Address:   0x007ab6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ab6e0 @ 0x007ab6e0
// Stable ID: aa_007ab6e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007ab6e0.
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

void __fastcall FUN_007ab6e0(int *param_1)



{

  int unaff_ESI;

  int local_10;

  int iStack_c;

  int iStack_8;

  

  (**(code **)(*param_1 + 0x204))(&local_10);

  iStack_8 = param_1[0x5d] + local_10;

  iStack_c = param_1[0x5c] + unaff_ESI;

  (**(code **)(*param_1 + 8))(&iStack_c);

  return;

}
