// =============================================================================
// FUN_006a3b30
// -----------------------------------------------------------------------------
// Stable ID: aa_006a3b30
// Address:   0x006a3b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a3b30 @ 0x006a3b30
// Stable ID: aa_006a3b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_006a3b30.
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

void __fastcall FUN_006a3b30(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_009eb6ac;

  DAT_00d091dc = DAT_00d091dc + -1;

  if (DAT_00d091dc != 0) {

    *(uint8_t *)(param_1 + 4) = 1;

  }

  *param_1 = &PTR_FUN_009eb658;

  if (*(char *)(param_1 + 4) == '\0') {

    operator_delete__((void *)param_1[2]);

    operator_delete__((void *)param_1[3]);

  }

  *param_1 = &PTR_LAB_009eb52c;

  return;

}
