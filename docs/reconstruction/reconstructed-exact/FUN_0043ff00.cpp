// =============================================================================
// FUN_0043ff00
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ff00
// Address:   0x0043ff00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043ff00 @ 0x0043ff00
// Stable ID: aa_0043ff00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_0043ff00, block.
//  - Return sites: 4.

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

/* WARNING: Removing unreachable block (ram,0x0043ff44) */



void __fastcall FUN_0043ff00(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_00a9f174;

  if ((void *)param_1[3] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[3]);

  }

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  if ((void *)param_1[7] == (void *)0x0) {

    param_1[7] = 0;

    param_1[8] = 0;

    param_1[9] = 0;

    param_1[7] = 0;

    param_1[8] = 0;

    param_1[9] = 0;

    if ((void *)param_1[3] == (void *)0x0) {

      param_1[3] = 0;

      param_1[4] = 0;

      param_1[5] = 0;

      *param_1 = &PTR_LAB_00a9dce8;

      return;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[3]);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[7]);

}
