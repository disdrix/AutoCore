// =============================================================================
// FUN_009a00d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009a00d0
// Address:   0x009a00d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009a00d0 @ 0x009a00d0
// Stable ID: aa_009a00d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00448fc0, FUN_0044c150, FUN_0044c370, FUN_009a00d0, gfxIndexBufferImpl_Unserialize.
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

int FUN_009a00d0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  piVar3 = (int *)FUN_0044c150();

  if (piVar3 != (int *)0x0) {

    piVar3[1] = 0;

    piVar3[2] = 0;

    piVar3[3] = 0;

    *piVar3 = (int)&PTR_FUN_00aa213c;

    piVar3[4] = 0;

    piVar3[5] = 2;

    piVar3[6] = 0;

    piVar3[7] = 0;

    piVar3[8] = 0;

    piVar3[9] = 0;

    piVar3[1] = piVar3[1] + 1;

    if (piVar3[1] == 1) {

      (**(code **)(*piVar3 + 4))();

    }

    piVar2 = *(int **)(param_1 + 4);

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

    }

    *(int **)(param_1 + 4) = piVar3;

    iVar4 = gfxIndexBufferImpl_Unserialize(piVar3,param_2,param_3);

    if (iVar4 == -2) {

      uVar5 = FUN_0044c370(piVar3[2],piVar3[3]);

      FUN_00448fc0(uVar5);

      iVar4 = 0;

    }

    return iVar4;

  }

  return -1;

}
