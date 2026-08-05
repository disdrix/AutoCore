// =============================================================================
// FUN_00791bd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00791bd0
// Address:   0x00791bd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00791bd0 @ 0x00791bd0
// Stable ID: aa_00791bd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_00428340, FUN_00756be0, FUN_00791bd0.
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

int * __thiscall FUN_00791bd0(int *param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = (int)param_2;

  if (param_1[0x130] == 0) {

    return (int *)0x0;

  }

  if (param_2 != (int *)0x0) {

    if (param_2 == (int *)param_1[0x12f]) {

      (**(code **)(*param_1 + 0x3c0))(0);

    }

    if (iVar1 == param_1[0x12e]) {

      (**(code **)(*param_1 + 0x318))();

      param_1[0x12e] = 0;

    }

    param_2 = (int *)0x0;

    FUN_00428340(&param_2);

    piVar2 = param_2;

    if (param_2 != (int *)0x0) {

      (**(code **)(*param_1 + 0x3b0))(param_2);

      (**(code **)(*piVar2 + 0x334))(0);

      FUN_00756be0(piVar2);

      piVar2[0xac] = 0;

      piVar2[0x37] = -1;

      (**(code **)(*piVar2 + 0x174))(0);

    }

    return piVar2;

  }

  return (int *)0x0;

}
