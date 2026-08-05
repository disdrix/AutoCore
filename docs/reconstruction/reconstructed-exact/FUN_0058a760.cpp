// =============================================================================
// FUN_0058a760
// -----------------------------------------------------------------------------
// Stable ID: aa_0058a760
// Address:   0x0058a760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058a760 @ 0x0058a760
// Stable ID: aa_0058a760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0058a760.
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

uint32_t /* width from decompiler */ FUN_0058a760(int *param_1,float param_2)



{

  int iVar1;

  

  if (param_1 != (int *)0x0) {

    iVar1 = (**(code **)(*param_1 + 0x210))(0);

    if (iVar1 != 0) {

      *(float *)(iVar1 + 0xc68) = (float)param_1[0x49] * param_2 + *(float *)(iVar1 + 0xc68);

      *(float *)(iVar1 + 0xc6c) = (float)param_1[0x4a] * param_2 + *(float *)(iVar1 + 0xc6c);

      return 1;

    }

  }

  return 0;

}
