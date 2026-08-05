// =============================================================================
// FUN_00804fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00804fe0
// Address:   0x00804fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00804fe0 @ 0x00804fe0
// Stable ID: aa_00804fe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0048a259, FUN_00804ca0, FUN_00804d90, FUN_00804fe0.
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

uint32_t /* width from decompiler */ __fastcall FUN_00804fe0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(int *)(param_1 + 0x70) == 0) {

    uVar2 = 0;

  }

  else {

    (**(code **)(**(int **)(param_1 + 0x70) + 0x6c))();

    uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c);

  }

  iVar1 = FUN_00804ca0();

  if ((iVar1 != 0) && (*(int *)(param_1 + 0x88) != -1)) {

    FUN_0048a259(*(int *)(param_1 + 0x88),iVar1,uVar2);

    FUN_00804d90();

  }

  return 0;

}
