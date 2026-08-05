// =============================================================================
// FUN_00445170
// -----------------------------------------------------------------------------
// Stable ID: aa_00445170
// Address:   0x00445170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00445170 @ 0x00445170
// Stable ID: aa_00445170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00435df0, FUN_00445170.
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

uint32_t /* width from decompiler */ __thiscall FUN_00445170(int param_1,uint8_t *param_2)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x18) + 1) {

    iVar1 = FUN_00435df0(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18));

    if ((iVar1 < 0) || (*(int *)(param_1 + 0x20) < 1)) {

      return 0xffffffff;

    }

  }

  *param_2 = *(uint8_t *)(*(int *)(param_1 + 0x18) + param_1 + 0x2c);

  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;

  return 0;

}
