// =============================================================================
// FUN_005bdcf0
// -----------------------------------------------------------------------------
// Stable ID: aa_005bdcf0
// Address:   0x005bdcf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005bdcf0 @ 0x005bdcf0
// Stable ID: aa_005bdcf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0049a120, FUN_004b92b0, FUN_005b8230, FUN_005bdcf0, FUN_005bdf00, FUN_005be460.
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

uint32_t /* width from decompiler */ __thiscall FUN_005bdcf0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  

  if (*(char *)(DAT_00b037f0 + 0x15) != '\0') {

    return 0;

  }

  uVar1 = FUN_005be460(param_2);

  FUN_005bdf00(param_1);

  if (*param_1 != 0) {

    iVar2 = FUN_0049a120();

    if (iVar2 != 0) {

      FUN_004b92b0(iVar2);

      FUN_005b8230(iVar2);

    }

  }

  return uVar1;

}
