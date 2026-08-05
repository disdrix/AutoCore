// =============================================================================
// FUN_00793a70
// -----------------------------------------------------------------------------
// Stable ID: aa_00793a70
// Address:   0x00793a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00793a70 @ 0x00793a70
// Stable ID: aa_00793a70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00793a70.
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

void __fastcall FUN_00793a70(short *param_1,int param_2)



{

  short *psVar1;

  short sVar2;

  short *in_EAX;

  

  psVar1 = in_EAX + param_2 + -1;

  sVar2 = *param_1;

  for (; (sVar2 != 0 && (in_EAX < psVar1)); in_EAX = in_EAX + 1) {

    param_1 = param_1 + 1;

    *in_EAX = sVar2;

    sVar2 = *param_1;

  }

  *in_EAX = 0;

  return;

}
