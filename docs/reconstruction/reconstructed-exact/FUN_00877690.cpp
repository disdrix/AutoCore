// =============================================================================
// FUN_00877690
// -----------------------------------------------------------------------------
// Stable ID: aa_00877690
// Address:   0x00877690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00877690 @ 0x00877690
// Stable ID: aa_00877690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00877690.
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

void FUN_00877690(uint32_t /* width from decompiler */ param_1)



{

  int unaff_EDI;

  

  (**(code **)(**(int **)(unaff_EDI + 0x504) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x54c) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x550) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x554) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x558) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x56c) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x570) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x574) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x578) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x580) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x584) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x588) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x55c) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x560) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x564) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x568) + 4))(param_1);

  (**(code **)(**(int **)(unaff_EDI + 0x57c) + 4))(param_1);

  return;

}
