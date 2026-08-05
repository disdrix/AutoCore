// =============================================================================
// FUN_00469600
// -----------------------------------------------------------------------------
// Stable ID: aa_00469600
// Address:   0x00469600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00469600 @ 0x00469600
// Stable ID: aa_00469600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×8, return×4.
//  - Notable callees: FUN_00469600.
//  - Return sites: 4.

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

int __thiscall FUN_00469600(int param_1,int param_2,int param_3)



{

  int iVar1;

  

  if (*(char *)(param_1 + 0x10) != '\0') {

    iVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x14),0);

    if (iVar1 < 0) {

      return -1;

    }

  }

  iVar1 = -1;

  if (param_3 == 0) {

    iVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))(*(int *)(param_1 + 0xc) + param_2,0);

    if (-1 < iVar1) {

      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0xc) + param_2;

    }

  }

  else if (param_3 == 1) {

    iVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))(param_2,1);

    if (-1 < iVar1) {

      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + param_2;

      return iVar1;

    }

  }

  else if (param_3 == 2) {

    iVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))

                      (*(int *)(param_1 + 8) + param_2 + *(int *)(param_1 + 0xc),0);

    if (-1 < iVar1) {

      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 8) + param_2 + *(int *)(param_1 + 0xc);

      return iVar1;

    }

  }

  return iVar1;

}
