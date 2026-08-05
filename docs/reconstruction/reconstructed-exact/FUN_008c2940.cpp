// =============================================================================
// FUN_008c2940
// -----------------------------------------------------------------------------
// Stable ID: aa_008c2940
// Address:   0x008c2940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c2940 @ 0x008c2940
// Stable ID: aa_008c2940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0085fcc0, FUN_008c2940.
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

void __fastcall FUN_008c2940(int param_1)



{

  int in_EAX;

  

  if ((*(int *)(param_1 + 0x580) != 0) && (in_EAX != 0)) {

    FUN_0085fcc0(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x160),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x164));

  }

  return;

}
