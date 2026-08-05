// =============================================================================
// FUN_00877bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00877bf0
// Address:   0x00877bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00877bf0 @ 0x00877bf0
// Stable ID: aa_00877bf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00877bf0.
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

void FUN_00877bf0(uint32_t /* width from decompiler */ param_1)



{

  int unaff_ESI;

  

  (**(code **)(**(int **)(unaff_ESI + 0x58c) + 4))(param_1);

  (**(code **)(**(int **)(unaff_ESI + 0x590) + 4))(param_1);

  if ((*(char *)(DAT_00d1b644 + 0xf6) != '\0') && (DAT_00d1b20d != '\0')) {

                    /* WARNING: Could not recover jumptable at 0x00877c35. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(unaff_ESI + 0x594) + 4))(0);

    return;

  }

  (**(code **)(**(int **)(unaff_ESI + 0x594) + 4))(param_1);

  return;

}
