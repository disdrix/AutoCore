// =============================================================================
// FUN_008d2a70
// -----------------------------------------------------------------------------
// Stable ID: aa_008d2a70
// Address:   0x008d2a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d2a70 @ 0x008d2a70
// Stable ID: aa_008d2a70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_008d2840, FUN_008d2a70.
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

void __fastcall FUN_008d2a70(uint32_t /* width from decompiler */ param_1)



{

  int in_EAX;

  

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x5a4) = param_1;

  FUN_008d2840(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x5a8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x5ac),param_1);

  return;

}
