// =============================================================================
// FUN_00435170
// -----------------------------------------------------------------------------
// Stable ID: aa_00435170
// Address:   0x00435170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00435170 @ 0x00435170
// Stable ID: aa_00435170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CONCAT31, FUN_00435170, FUN_004351f0.
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

uint __thiscall FUN_00435170(int param_1,uint8_t param_2)



{

  int iVar1;

  uint in_EAX;

  

  if (*(int *)(param_1 + 4) == 0) {

    return in_EAX & 0xffffff00;

  }

  if (*(int *)(param_1 + 0x14) < *(int *)(param_1 + 0x10) + 1) {

    FUN_004351f0();

  }

  *(uint8_t *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 4)) = param_2;

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;

  iVar1 = *(int *)(param_1 + 0x10);

  if (*(int *)(param_1 + 8) < iVar1) {

    *(int *)(param_1 + 8) = iVar1;

  }

  return CONCAT31((int3)((uint)iVar1 >> 8),1);

}
