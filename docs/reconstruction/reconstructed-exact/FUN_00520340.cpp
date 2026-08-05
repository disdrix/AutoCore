// =============================================================================
// FUN_00520340
// -----------------------------------------------------------------------------
// Stable ID: aa_00520340
// Address:   0x00520340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00520340 @ 0x00520340
// Stable ID: aa_00520340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×6, switch×1.
//  - Notable callees: ROUND×5, floor×5, FUN_00520340.
//  - Return sites: 6.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int __thiscall FUN_00520340(int param_1,uint32_t /* width from decompiler */ param_2)



{

  double dVar1;

  

  switch(param_2) {

  case 1:

    dVar1 = floor((double)((float)*(byte *)(param_1 + 0x599) * _DAT_009da8a4));

    return (int)ROUND(dVar1);

  case 2:

    dVar1 = floor((double)((float)*(byte *)(param_1 + 0x599) * _DAT_00aaaa3c));

    return (int)ROUND(dVar1);

  case 3:

    dVar1 = floor((double)((float)*(byte *)(param_1 + 0x599) * _DAT_009cefc0));

    return (int)ROUND(dVar1);

  case 4:

    dVar1 = floor((double)((float)*(byte *)(param_1 + 0x599) * _DAT_009cefbc));

    return (int)ROUND(dVar1);

  case 5:

    dVar1 = floor((double)((float)*(byte *)(param_1 + 0x599) * DAT_00a0f710));

    return (int)ROUND(dVar1);

  default:

    return 0;

  }

}
