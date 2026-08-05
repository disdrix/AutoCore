// =============================================================================
// FUN_00491e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00491e80
// Address:   0x00491e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00491e80 @ 0x00491e80
// Stable ID: aa_00491e80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00491e80, FUN_00493410, FUN_006759b0.
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

uint32_t /* width from decompiler */ __thiscall FUN_00491e80(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  if (param_2 != 0) {

    iVar1 = *(int *)(param_1 + 0xf4);

    iVar2 = FUN_006759b0(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&param_2);

    FUN_00493410(1);

    *(int *)(iVar1 + 4) = iVar2;

    **(int **)(iVar2 + 4) = iVar2;

  }

  return *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0);

}
