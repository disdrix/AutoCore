// =============================================================================
// FUN_0090e300
// -----------------------------------------------------------------------------
// Stable ID: aa_0090e300
// Address:   0x0090e300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090e300 @ 0x0090e300
// Stable ID: aa_0090e300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007fd090, FUN_007fd1c0, FUN_0090e300.
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

void __thiscall FUN_0090e300(int param_1,int param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint8_t auStack_8 [8];

  

  if (*(int *)(param_1 + 0x4b8) != 0) {

    iVar1 = (**(code **)(**(int **)(param_1 + 0x4b8) + 0x310))();

    if (iVar1 == 1) {

      iVar1 = 0;

      iVar3 = 0;

      if (DAT_00d1b9a8 != (int *)0x0) {

        piVar2 = (int *)(**(code **)(*DAT_00d1b9a8 + 0x140))(auStack_8,1);

        iVar1 = *piVar2;

        iVar3 = piVar2[1];

      }

      (**(code **)(**(int **)(param_1 + 0x4b8) + 0x30c))();

      FUN_007fd1c0(param_2 + -5,param_3 + -5,iVar1 + 10,iVar3 + 10);

      return;

    }

    (**(code **)(**(int **)(param_1 + 0x4b8) + 0x30c))();

    FUN_007fd090(param_2,param_3);

  }

  return;

}
