// =============================================================================
// FUN_00678470
// -----------------------------------------------------------------------------
// Stable ID: aa_00678470
// Address:   0x00678470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00678470 @ 0x00678470
// Stable ID: aa_00678470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00702910×2, FUN_00678470, FUN_00702f50, FUN_00702f70.
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

void __fastcall FUN_00678470(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_009e8684;

  if (param_1[1] == 0) {

    FUN_00702f50(param_1[0x1d]);

  }

  else if (param_1[1] == 1) {

    FUN_00702f70(param_1[0x1e]);

  }

  FUN_00702910(param_1 + 0xb);

  FUN_00702910(param_1 + 0x14);

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x1f]);

}
