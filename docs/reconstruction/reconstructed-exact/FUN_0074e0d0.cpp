// =============================================================================
// FUN_0074e0d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e0d0
// Address:   0x0074e0d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Scaffold twin for FUN_0074e0d0 @ 0x0074e0d0
// Stable ID: aa_0074e0d0
// Named plate (W37-AE): LightMgr_SetActiveSlot3c_Refcount_Inferred.cpp
// Dual-sealed 2026-08-04: thiscall host+0x3c refcount swap; RET 4.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0074e0d0.
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

void __thiscall FUN_0074e0d0(int param_1,int *param_2)



{

  int *piVar1;

  int *piVar2;

  

  if ((param_2 != (int *)0x0) && (param_2[1] = param_2[1] + 1, param_2[1] == 1)) {

    (**(code **)(*param_2 + 4))();

  }

  piVar2 = *(int **)(param_1 + 0x3c);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int **)(param_1 + 0x3c) = param_2;

  return;

}
