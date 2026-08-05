// =============================================================================
// FUN_0040df00
// -----------------------------------------------------------------------------
// Stable ID: aa_0040df00
// Address:   0x0040df00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040df00 @ 0x0040df00
// Stable ID: aa_0040df00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0040df00, FUN_00418130.
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

uint32_t /* width from decompiler */ __thiscall FUN_0040df00(int param_1,uint param_2)



{

  void *pvVar1;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  if (param_2 == 0) {

    return 0;

  }

  if (0x3fffffff < param_2) {

    param_2 = FUN_00418130();

  }

  pvVar1 = operator_new(param_2 * 4);

  *(void **)(param_1 + 0xc) = (void *)(param_2 * 4 + (int)pvVar1);

  *(void **)(param_1 + 4) = pvVar1;

  *(void **)(param_1 + 8) = pvVar1;

  return 1;

}
