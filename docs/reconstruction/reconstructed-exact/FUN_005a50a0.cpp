// =============================================================================
// FUN_005a50a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a50a0
// Address:   0x005a50a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a50a0 @ 0x005a50a0
// Stable ID: aa_005a50a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_005a50a0.
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

void __thiscall FUN_005a50a0(uint32_t /* width from decompiler */ *param_1,float param_2)



{

  bool bVar1;

  

  if (*(char *)(param_1 + 6) != '\0') {

    param_1[4] = 0;

    param_1[3] = 0;

    *param_1 = 0;

    param_1[1] = 0;

    *(uint8_t *)((int)param_1 + 0x1b) = 1;

    return;

  }

  param_2 = (float)param_1[3] + param_2;

  param_1[3] = param_2;

  if (*(char *)(param_1 + 5) == '\0') {

    param_1[4] = param_2;

    if (*(char *)(param_1 + 7) == '\0') {

      bVar1 = (float)param_1[2] < param_2;

    }

    else {

      bVar1 = param_2 < (float)param_1[2];

    }

  }

  else {

    bVar1 = param_2 < (float)param_1[2];

    param_1[4] = (float)param_1[2] - param_2;

  }

  if (!bVar1) {

    *(uint8_t *)(param_1 + 6) = 1;

  }

  return;

}
