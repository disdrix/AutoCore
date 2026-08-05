// =============================================================================
// FUN_0062a840
// -----------------------------------------------------------------------------
// Stable ID: aa_0062a840
// Address:   0x0062a840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062a840 @ 0x0062a840
// Stable ID: aa_0062a840
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_0055dfb0, FUN_005fff20, FUN_0062a840.
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

void FUN_0062a840(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = *(int *)(param_1 + 0x88);

  while (iVar1 = iVar1 + -1, -1 < iVar1) {

    piVar2 = *(int **)(*(int *)(param_1 + 0x84) + iVar1 * 4);

    if (piVar2 != (int *)0x0) {

      (**(code **)(*piVar2 + 4))(param_1,param_2);

    }

  }

  FUN_005fff20();

  piVar2 = (int *)FUN_0055dfb0();

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 4))(param_1,param_2);

  }

  return;

}
