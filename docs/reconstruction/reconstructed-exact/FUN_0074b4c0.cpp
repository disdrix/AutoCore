// =============================================================================
// FUN_0074b4c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074b4c0
// Address:   0x0074b4c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074b4c0 @ 0x0074b4c0
// Stable ID: aa_0074b4c0
// Embedded strings (evidence for future rename):
//   - "LineLengthMultiplier"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00442640, FUN_0074b4c0, FUN_0099f810.
//  - Strings: "LineLengthMultiplier".
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

void __fastcall FUN_0074b4c0(int param_1)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0xc0) == 0) {

    iVar1 = FUN_0099f810(param_1,0);

    *(int *)(param_1 + 0xc0) = iVar1;

    if (iVar1 == 0) {

      return;

    }

  }

  FUN_00442640("LineLengthMultiplier",DAT_00d1f048 + 0x30);

                    /* WARNING: Could not recover jumptable at 0x0074b506. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(**(int **)(param_1 + 0xc0) + 0x3c))();

  return;

}
