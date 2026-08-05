// =============================================================================
// FUN_00637fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00637fc0
// Address:   0x00637fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00637fc0 @ 0x00637fc0
// Stable ID: aa_00637fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, while×1.
//  - Notable callees: FUN_00637fc0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_00637fc0(int param_1,char *param_2)



{

  char cVar1;

  char cVar2;

  char cVar3;

  char cVar4;

  

  param_1 = param_1 - (int)param_2;

  while( true ) {

    cVar1 = param_2[param_1];

    if ((cVar1 == '\0') && (*param_2 == '\0')) {

      return 0;

    }

    cVar4 = cVar1;

    if (('@' < cVar1) && (cVar1 < '[')) {

      cVar4 = cVar1 + ' ';

    }

    cVar2 = *param_2;

    cVar3 = cVar2;

    if (('@' < cVar2) && (cVar2 < '[')) {

      cVar3 = cVar2 + ' ';

    }

    if (cVar4 < cVar3) break;

    if (('@' < cVar1) && (cVar1 < '[')) {

      cVar1 = cVar1 + ' ';

    }

    if (('@' < cVar2) && (cVar2 < '[')) {

      cVar2 = cVar2 + ' ';

    }

    if (cVar2 < cVar1) {

      return 1;

    }

    param_2 = param_2 + 1;

  }

  return 0xffffffff;

}
