// =============================================================================
// FUN_00999140
// -----------------------------------------------------------------------------
// Stable ID: aa_00999140
// Address:   0x00999140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00999140 @ 0x00999140
// Stable ID: aa_00999140
// Embedded strings (evidence for future rename):
//   - "LineLengthMultiplier"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00442640, FUN_00999140, FUN_0099f810.
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

void __fastcall FUN_00999140(int param_1)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0xc0) == 0) {

    if (*(int *)(param_1 + 0xe0) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 0xe4) - *(int *)(param_1 + 0xe0) >> 2;

    }

    iVar1 = FUN_0099f810(param_1,iVar1);

    *(int *)(param_1 + 0xc0) = iVar1;

    if (iVar1 == 0) {

      return;

    }

  }

  FUN_00442640("LineLengthMultiplier",DAT_00d1f048 + 0x30);

                    /* WARNING: Could not recover jumptable at 0x0099919e. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(**(int **)(param_1 + 0xc0) + 0x3c))();

  return;

}
