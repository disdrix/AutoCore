// =============================================================================
// FUN_0073f400
// -----------------------------------------------------------------------------
// Stable ID: aa_0073f400
// Address:   0x0073f400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073f400 @ 0x0073f400
// Stable ID: aa_0073f400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, for×2, return×1.
//  - Notable callees: FUN_0073f400, memmove.
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

void FUN_0073f400(int param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  void *_Src;

  void *pvVar5;

  int *piVar6;

  

  piVar2 = *(int **)(param_1 + 0x18);

  for (piVar6 = *(int **)(param_1 + 0x14); piVar6 != piVar2; piVar6 = piVar6 + 1) {

    if ((int *)*piVar6 != (int *)0x0) {

      (**(code **)(*(int *)*piVar6 + 0xc))();

    }

  }

  piVar2 = *(int **)(param_1 + 8);

  for (piVar6 = *(int **)(param_1 + 4); piVar6 != piVar2; piVar6 = piVar6 + 1) {

    piVar3 = (int *)*piVar6;

    piVar4 = (int *)piVar3[1];

    if (piVar4 != (int *)0x0) {

      piVar1 = piVar4 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar4 + 8))();

      }

    }

    *piVar3 = (int)DAT_00d21984;

    DAT_00d21984 = piVar3;

  }

  pvVar5 = *(void **)(param_1 + 4);

  if (((pvVar5 != (void *)0x0) &&

      (_Src = *(void **)(param_1 + 8), (int)_Src - (int)pvVar5 >> 2 != 0)) && (pvVar5 != _Src)) {

    pvVar5 = memmove(pvVar5,_Src,0);

    *(void **)(param_1 + 8) = pvVar5;

  }

  return;

}
