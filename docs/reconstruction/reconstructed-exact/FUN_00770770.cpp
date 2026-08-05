// =============================================================================
// FUN_00770770
// -----------------------------------------------------------------------------
// Stable ID: aa_00770770
// Address:   0x00770770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00770770 @ 0x00770770
// Stable ID: aa_00770770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00770770.
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

int __fastcall FUN_00770770(uint param_1)



{

  int *in_EAX;

  

  if (in_EAX[2] == 1) {

    return -1;

  }

  if ((*in_EAX < 2) && (*(uint *)in_EAX[3] <= param_1)) {

    return -(uint)(*(uint *)in_EAX[3] < param_1);

  }

  return 1;

}
