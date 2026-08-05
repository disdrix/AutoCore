// =============================================================================
// FUN_00611940
// -----------------------------------------------------------------------------
// Stable ID: aa_00611940
// Address:   0x00611940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00611940 @ 0x00611940
// Stable ID: aa_00611940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_005711c0×2, FUN_00611940.
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

float10 __thiscall FUN_00611940(int param_1,int param_2)



{

  int iVar1;

  float fVar2;

  

  if (*(int *)(param_1 + 0x14) == 0) {

    return (float10)g_flOne;

  }

  if ((*(int *)(param_2 + 0x250) != 0) && (*(int *)(*(int *)(param_2 + 0x250) + 0x2b0) != 0)) {

    iVar1 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),0);

    fVar2 = g_flOne;

    if ((float)iVar1 / (float)*(int *)(param_1 + 0x14) < g_flOne) {

      iVar1 = FUN_005711c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),0);

      fVar2 = (float)iVar1 / (float)*(int *)(param_1 + 0x14);

    }

    return (float10)fVar2;

  }

  return (float10)g_flZero;

}
