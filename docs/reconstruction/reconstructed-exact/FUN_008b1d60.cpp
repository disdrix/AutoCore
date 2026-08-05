// =============================================================================
// FUN_008b1d60
// -----------------------------------------------------------------------------
// Stable ID: aa_008b1d60
// Address:   0x008b1d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b1d60 @ 0x008b1d60
// Stable ID: aa_008b1d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, switch×1.
//  - Notable callees: FUN_007fca10, FUN_00857a60, FUN_00857af0, FUN_008b1780, FUN_008b1d60, FUN_00937470.
//  - Return sites: 5.

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

uint32_t /* width from decompiler */ __thiscall FUN_008b1d60(int *param_1,int param_2,int param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  switch(param_3 + -40000) {

  case 0:

    if (param_2 == 8) {

      FUN_007fca10();

      return 1;

    }

    break;

  case 1:

    if (param_2 == 8) {

      FUN_008b1780();

      return 1;

    }

    break;

  case 2:

    if ((param_2 == 8) && (param_1[0x14e] != 0)) {

      FUN_00857af0();

    }

    break;

  case 3:

    if ((param_2 == 8) && (param_1[0x14e] != 0)) {

      FUN_00857a60();

    }

    break;

  case 4:

    if (param_2 == 8) {

      FUN_00937470();

    }

    break;

  case 6:

    if (param_2 == 7) {

      return 1;

    }

  }

  cVar1 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar1 != '\0') && (param_1[0xac] != 0)) {

    uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar2;

  }

  return 0;

}
