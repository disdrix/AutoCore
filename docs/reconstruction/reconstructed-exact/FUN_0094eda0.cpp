// =============================================================================
// FUN_0094eda0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094eda0
// Address:   0x0094eda0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094eda0 @ 0x0094eda0
// Stable ID: aa_0094eda0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: strtok×2, FUN_0094eda0, atof.
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

uint32_t /* width from decompiler */ FUN_0094eda0(uint32_t /* width from decompiler */ param_1,char *param_2)



{

  char *_String;

  int iVar1;

  double dVar2;

  float local_8 [2];

  

  _String = strtok((char *)0x0,param_2);

  if (_String != (char *)0x0) {

    iVar1 = 0;

    do {

      dVar2 = atof(_String);

      local_8[iVar1] = (float)dVar2;

      iVar1 = iVar1 + 1;

      _String = strtok((char *)0x0,param_2);

    } while (_String != (char *)0x0);

    if (iVar1 == 2) {

      DAT_00aefa5c = local_8[0];

      DAT_00aefa58 = local_8[1];

    }

  }

  return 1;

}
