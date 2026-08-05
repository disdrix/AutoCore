// =============================================================================
// FUN_00888aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00888aa0
// Address:   0x00888aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00888aa0 @ 0x00888aa0
// Stable ID: aa_00888aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_00888aa0.
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

void __fastcall FUN_00888aa0(int param_1)



{

  char cVar1;

  

  if (*(int *)(param_1 + 0x510) != 0) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x510) + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(param_1 + 0x510) + 0x448))();

    }

  }

  if (*(int *)(param_1 + 0x514) != 0) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x514) + 0x3d8))();

    if (cVar1 != '\0') {

                    /* WARNING: Could not recover jumptable at 0x00888af0. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(param_1 + 0x514) + 0x448))();

      return;

    }

  }

  return;

}
