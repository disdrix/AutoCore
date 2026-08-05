// =============================================================================
// FUN_008b6430
// -----------------------------------------------------------------------------
// Stable ID: aa_008b6430
// Address:   0x008b6430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b6430 @ 0x008b6430
// Stable ID: aa_008b6430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007916e0, FUN_008b6430.
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

void __thiscall FUN_008b6430(int param_1,uint32_t /* width from decompiler */ param_2)



{

  FUN_007916e0(param_2);

  if (((((char)param_2 != '\0') && (*(int *)(param_1 + 0x538) != 0)) && (DAT_00d1ad2c != -4)) &&

     ((*(int *)(DAT_00d1ad2c + 8) != 0 &&

      (*(int *)(DAT_00d1ad2c + 0xc) - *(int *)(DAT_00d1ad2c + 8) >> 2 != 0)))) {

                    /* WARNING: Could not recover jumptable at 0x008b647e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(param_1 + 0x538) + 4))();

    return;

  }

  return;

}
