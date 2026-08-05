// =============================================================================
// FUN_004b70c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b70c0
// Address:   0x004b70c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b70c0 @ 0x004b70c0
// Stable ID: aa_004b70c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_004b70c0, FUN_0058e3a0.
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

void __fastcall FUN_004b70c0(int param_1)



{

  int *piVar1;

  

  piVar1 = (int *)**(int **)(param_1 + 0x204);

  if (piVar1 != *(int **)(param_1 + 0x204)) {

    do {

      FUN_0058e3a0(&stack0x00000004);

      piVar1 = (int *)*piVar1;

    } while (piVar1 != (int *)*(int *)(param_1 + 0x204));

  }

  return;

}
