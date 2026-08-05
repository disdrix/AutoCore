// =============================================================================
// FUN_008c3ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_008c3ca0
// Address:   0x008c3ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008c3ca0 @ 0x008c3ca0
// Stable ID: aa_008c3ca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×12, return×9, switch×1.
//  - Notable callees: FUN_007fca10×2, FUN_008c3140×2, FUN_007fbbb0, FUN_0087b500, FUN_008c2f50, FUN_008c2fe0, FUN_008c3080, FUN_008c3ca0.
//  - Return sites: 9.

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

uint32_t /* width from decompiler */ __thiscall FUN_008c3ca0(int param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if ((0x9c46 < param_3) && (param_3 < 0x9c4f)) {

    if (param_2 == 5) {

      if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0xcd0) != 0)) {

        FUN_008c3140();

      }

      return 1;

    }

    if (param_2 == 8) {

      FUN_007fbbb0();

      FUN_008c3140();

      return 1;

    }

  }

  switch(param_3 + -40000) {

  case 0:

    if (param_2 == 8) {

      if (*(int *)(param_1 + 0x50c) == 1) {

        FUN_007fca10();

      }

      else if (*(int *)(param_1 + 0x50c) == 3) {

        FUN_007fca10();

        return 1;

      }

      return 1;

    }

    break;

  case 1:

    if (param_2 == 8) {

      return 1;

    }

    break;

  case 2:

    if (param_2 == 8) {

      *(uint8_t *)(param_1 + 0x521) = 0;

      *(bool *)(param_1 + 0x520) = *(char *)(param_1 + 0x520) == '\0';

      FUN_008c3080();

      return 1;

    }

    break;

  case 3:

    if (param_2 == 8) {

      *(uint8_t *)(param_1 + 0x520) = 0;

      *(bool *)(param_1 + 0x521) = *(char *)(param_1 + 0x521) == '\0';

      FUN_008c2fe0();

      return 1;

    }

    break;

  case 4:

    if (param_2 == 8) {

      FUN_008c2f50();

    }

    break;

  case 5:

    if (param_2 == 8) {

      FUN_0093bac0(&DAT_00d1a840,0);

      return 1;

    }

  }

  uVar1 = FUN_0087b500(param_2,param_3);

  return uVar1;

}
