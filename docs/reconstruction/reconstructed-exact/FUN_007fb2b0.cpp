// =============================================================================
// FUN_007fb2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb2b0
// Address:   0x007fb2b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fb2b0 @ 0x007fb2b0
// Stable ID: aa_007fb2b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×13, return×2.
//  - Notable callees: FUN_007fb2b0.
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

void FUN_007fb2b0(uint param_1,uint param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  char cVar4;

  int in_EAX;

  

  piVar1 = *(int **)(in_EAX + 0x110c);

  piVar2 = *(int **)(in_EAX + 0x1110);

  piVar3 = *(int **)(in_EAX + 0x1108);

  if ((param_1 & param_2) == 0xffffffff) {

    if (piVar2 != (int *)0x0) {

      cVar4 = (**(code **)(*piVar2 + 0x3d8))();

      if (cVar4 != '\0') {

        (**(code **)(*piVar2 + 0x450))(0xffffffff,0xffffffff);

      }

    }

    if (piVar3 != (int *)0x0) {

      cVar4 = (**(code **)(*piVar3 + 0x3d8))();

      if (cVar4 != '\0') {

        (**(code **)(*piVar3 + 0x450))(0xffffffff,0xffffffff);

      }

    }

    if (piVar1 != (int *)0x0) {

      cVar4 = (**(code **)(*piVar1 + 0x3d8))();

      if (cVar4 != '\0') {

        (**(code **)(*piVar1 + 0x450))(0xffffffff,0xffffffff);

        return;

      }

    }

  }

  else {

    if (piVar2 != (int *)0x0) {

      cVar4 = (**(code **)(*piVar2 + 0x3d8))();

      if (cVar4 != '\0') {

        (**(code **)(*piVar2 + 0x450))(param_1,param_2);

      }

    }

    if (piVar3 != (int *)0x0) {

      cVar4 = (**(code **)(*piVar3 + 0x3d8))();

      if (cVar4 != '\0') {

        (**(code **)(*piVar3 + 0x450))(param_1,param_2);

      }

    }

    if (piVar1 != (int *)0x0) {

      cVar4 = (**(code **)(*piVar1 + 0x3d8))();

      if (cVar4 != '\0') {

        (**(code **)(*piVar1 + 0x450))(param_1,param_2);

      }

    }

  }

  return;

}
