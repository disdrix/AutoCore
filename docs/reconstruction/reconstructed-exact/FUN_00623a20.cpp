// =============================================================================
// FUN_00623a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00623a20
// Address:   0x00623a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00623a20 @ 0x00623a20
// Stable ID: aa_00623a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0052db50×3, FUN_006186c0, FUN_00623a20.
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

void __fastcall FUN_00623a20(int param_1)



{

  int iVar1;

  

  if ((*(int *)(param_1 + 0x18) != 0) &&

     (iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x210))(0), iVar1 != 0)) {

    if (*(int *)(param_1 + 0x178) != 0) {

      FUN_0052db50(*(int *)(param_1 + 0x178));

    }

    if (*(int *)(param_1 + 0x17c) != 0) {

      FUN_0052db50(*(int *)(param_1 + 0x17c));

    }

    if (*(int *)(param_1 + 0x180) != 0) {

      FUN_0052db50(*(int *)(param_1 + 0x180));

    }

  }

  FUN_006186c0();

  return;

}
