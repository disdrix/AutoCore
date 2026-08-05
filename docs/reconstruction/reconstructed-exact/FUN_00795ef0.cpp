// =============================================================================
// FUN_00795ef0
// -----------------------------------------------------------------------------
// Stable ID: aa_00795ef0
// Address:   0x00795ef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00795ef0 @ 0x00795ef0
// Stable ID: aa_00795ef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00795ef0, FUN_007b5be0.
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

void __fastcall FUN_00795ef0(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_00a98b1c;

  if ((void *)param_1[0x126] != (void *)0x0) {

    operator_delete__((void *)param_1[0x126]);

  }

  param_1[0x126] = 0;

  FUN_007b5be0();

  return;

}
