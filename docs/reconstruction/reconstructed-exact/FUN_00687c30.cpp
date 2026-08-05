// =============================================================================
// FUN_00687c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00687c30
// Address:   0x00687c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00687c30 @ 0x00687c30
// Stable ID: aa_00687c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00687c30.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00687c30(float *param_1,float param_2,float param_3)



{

  float fVar1;

  

  if (*(char *)(param_1 + 0xc) == '\0') {

    *param_1 = _DAT_00af5810 * param_2;

    param_1[1] = _DAT_00af5814 * param_3;

    param_1[2] = _DAT_00af5818 * param_2;

    param_1[3] = _DAT_00af581c * param_2;

    param_1[4] = _DAT_00af5820 * param_3;

    param_1[5] = _DAT_00af5824 * param_2;

    param_1[6] = _DAT_00af5828 * param_2;

    param_1[7] = _DAT_00af582c * param_3;

    param_1[8] = _DAT_00af5830 * param_2;

    param_1[9] = _DAT_00af5834 * param_2;

    param_1[10] = _DAT_00af5838 * param_3;

    fVar1 = _DAT_00af583c;

    *(uint8_t *)(param_1 + 0xc) = 1;

    param_1[0xb] = fVar1 * param_2;

  }

  return;

}
