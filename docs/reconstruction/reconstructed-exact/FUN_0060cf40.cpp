// =============================================================================
// FUN_0060cf40
// -----------------------------------------------------------------------------
// Stable ID: aa_0060cf40
// Address:   0x0060cf40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060cf40 @ 0x0060cf40
// Stable ID: aa_0060cf40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0060cf40, FUN_00637dc0.
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

void __fastcall FUN_0060cf40(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_009dfc1c;

  if ((void *)param_1[8] != (void *)0x0) {

    operator_delete__((void *)param_1[8]);

  }

  param_1[8] = 0;

  if ((void *)param_1[0xe] != (void *)0x0) {

    operator_delete__((void *)param_1[0xe]);

  }

  param_1[0xe] = 0;

  if ((void *)param_1[0x10] != (void *)0x0) {

    operator_delete__((void *)param_1[0x10]);

  }

  param_1[0x10] = 0;

  if ((void *)param_1[0x11] != (void *)0x0) {

    operator_delete__((void *)param_1[0x11]);

  }

  param_1[0x11] = 0;

  FUN_00637dc0();

  return;

}
