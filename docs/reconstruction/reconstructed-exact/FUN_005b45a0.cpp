// =============================================================================
// FUN_005b45a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b45a0
// Address:   0x005b45a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b45a0 @ 0x005b45a0
// Stable ID: aa_005b45a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_005b44f0, FUN_005b45a0.
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

void __thiscall FUN_005b45a0(int param_1,uint param_2)



{

  uint uVar1;

  int *piVar2;

  

  uVar1 = *(uint *)(param_1 + 8);

  if (uVar1 < param_2) {

    FUN_005b44f0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2 - uVar1,&stack0x00000008);

    return;

  }

  while( true ) {

    if (uVar1 <= param_2) {

      return;

    }

    piVar2 = (int *)(*(int **)(param_1 + 4))[1];

    if (piVar2 != *(int **)(param_1 + 4)) break;

    uVar1 = *(uint *)(param_1 + 8);

  }

  *(int *)piVar2[1] = *piVar2;

  *(int *)(*piVar2 + 4) = piVar2[1];

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar2);

}
