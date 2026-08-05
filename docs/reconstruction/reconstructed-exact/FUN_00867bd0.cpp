// =============================================================================
// FUN_00867bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00867bd0
// Address:   0x00867bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00867bd0 @ 0x00867bd0
// Stable ID: aa_00867bd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00867bd0.
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

void FUN_00867bd0(short param_1,int param_2,int param_3,char param_4)



{

  int *in_EAX;

  int unaff_ESI;

  

  if ((999 < param_1) && (param_4 == '\0')) {

    *in_EAX = param_2 * unaff_ESI;

    in_EAX[2] = param_2 * unaff_ESI + param_2;

    in_EAX[1] = param_3;

    in_EAX[3] = param_3 * 2;

    return;

  }

  *in_EAX = param_2 * unaff_ESI;

  in_EAX[2] = param_2 * unaff_ESI + param_2;

  in_EAX[1] = 0;

  in_EAX[3] = param_3;

  return;

}
