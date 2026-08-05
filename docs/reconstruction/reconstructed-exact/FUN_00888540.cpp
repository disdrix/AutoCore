// =============================================================================
// FUN_00888540
// -----------------------------------------------------------------------------
// Stable ID: aa_00888540
// Address:   0x00888540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00888540 @ 0x00888540
// Stable ID: aa_00888540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00792490, FUN_00888540.
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

void __fastcall FUN_00888540(int *param_1)



{

  char cVar1;

  

  if (param_1[0x143] != 0) {

    cVar1 = (**(code **)(*(int *)param_1[0x143] + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(*(int *)param_1[0x143] + 0x440))();

    }

  }

  (**(code **)(*param_1 + 0xb0))(param_1[0x143]);

  if (param_1[0x144] != 0) {

    cVar1 = (**(code **)(*(int *)param_1[0x144] + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(*(int *)param_1[0x144] + 0x440))();

    }

  }

  (**(code **)(*param_1 + 0xb0))(param_1[0x144]);

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  return;

}
