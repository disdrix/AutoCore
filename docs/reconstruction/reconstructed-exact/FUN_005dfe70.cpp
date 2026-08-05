// =============================================================================
// FUN_005dfe70
// -----------------------------------------------------------------------------
// Stable ID: aa_005dfe70
// Address:   0x005dfe70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dfe70 @ 0x005dfe70
// Stable ID: aa_005dfe70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00518ec0, FUN_005dfe70.
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

void __fastcall FUN_005dfe70(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_009dbbfc;

  if ((void *)param_1[0x65] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x65]);

  }

  param_1[0x65] = 0;

  param_1[0x66] = 0;

  param_1[0x67] = 0;

  FUN_00518ec0();

  return;

}
