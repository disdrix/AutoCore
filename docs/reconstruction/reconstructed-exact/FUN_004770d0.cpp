// =============================================================================
// FUN_004770d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004770d0
// Address:   0x004770d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004770d0 @ 0x004770d0
// Stable ID: aa_004770d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004770d0.
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

uint32_t /* width from decompiler */ __thiscall FUN_004770d0(int *param_1,int param_2)



{

  int in_EAX;

  

  if ((((param_2 != 0) && (in_EAX != 0)) && ((*(byte *)(in_EAX + 8) & 0x20) != 0)) &&

     (param_1 != (int *)0x0)) {

    *param_1 = in_EAX + 0x5a;

    return 0x20;

  }

  return 0;

}
