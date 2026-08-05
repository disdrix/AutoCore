// =============================================================================
// FUN_004b4e10
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4e10
// Address:   0x004b4e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b4e10 @ 0x004b4e10
// Stable ID: aa_004b4e10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00498ae0, FUN_004b4e10, FUN_005c5460.
//  - Return sites: 3.

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

void __fastcall FUN_004b4e10(int *param_1)



{

  void *pvVar1;

  

  if ((*param_1 != 0) && (param_1[1] != 0)) {

    pvVar1 = (void *)param_1[4];

    if (pvVar1 != (void *)0x0) {

      FUN_00498ae0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    pvVar1 = (void *)param_1[3];

    param_1[4] = 0;

    if (pvVar1 != (void *)0x0) {

      FUN_005c5460();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    param_1[3] = 0;

    (**(code **)(*(int *)*param_1 + 0x14))(param_1[1]);

    param_1[1] = 0;

  }

  return;

}
