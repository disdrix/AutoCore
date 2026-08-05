// =============================================================================
// FUN_005a60d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a60d0
// Address:   0x005a60d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a60d0 @ 0x005a60d0
// Stable ID: aa_005a60d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_005a60d0.
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

void __fastcall FUN_005a60d0(int *param_1)



{

  if ((char)param_1[0x4f] != '\0') {

    (**(code **)(*param_1 + 0x4c))();

                    /* WARNING: Could not recover jumptable at 0x005a60e6. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x48))();

    return;

  }

  (**(code **)(*param_1 + 0x78))();

  if (DAT_00b05068 < DAT_00af3ce8) {

                    /* WARNING: Could not recover jumptable at 0x005a60ff. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x48))();

    return;

  }

  if (DAT_00b03514 < DAT_00b05078[3] + 0x1e) {

    DAT_00af3ce8 = DAT_00af3ce8 + 1;

                    /* WARNING: Could not recover jumptable at 0x005a6122. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x48))();

    return;

  }

  (**(code **)(*DAT_00b05078 + 0x54))();

                    /* WARNING: Could not recover jumptable at 0x005a612f. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x48))();

  return;

}
