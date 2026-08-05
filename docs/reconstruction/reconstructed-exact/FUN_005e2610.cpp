// =============================================================================
// FUN_005e2610
// -----------------------------------------------------------------------------
// Stable ID: aa_005e2610
// Address:   0x005e2610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e2610 @ 0x005e2610
// Stable ID: aa_005e2610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×6, return×6, while×1.
//  - Notable callees: FUN_005e2610.
//  - Return sites: 6.

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

int __fastcall FUN_005e2610(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  

  if (**(int **)(param_1 + 0x14) == 0) {

    return param_1;

  }

  uVar4 = 0;

  iVar3 = param_1;

  if (**(int **)(param_1 + 0x14) != 0) {

    while (iVar2 = (**(code **)(**(int **)(*(int *)(iVar3 + 0x14) + uVar4 * 4) + 0x24))(),

          iVar2 != 0) {

      if (iVar2 == param_1) {

        return param_1;

      }

      piVar1 = *(int **)(iVar2 + 0x14);

      if (*piVar1 == 0) {

        return iVar2;

      }

      if (piVar1[1] == 0) {

        return iVar2;

      }

      uVar4 = (uint)(*piVar1 == iVar3);

      iVar3 = iVar2;

      if (piVar1[uVar4] == 0) {

        return iVar2;

      }

    }

  }

  return iVar3;

}
