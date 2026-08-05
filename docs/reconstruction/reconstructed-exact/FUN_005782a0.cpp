// =============================================================================
// FUN_005782a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005782a0
// Address:   0x005782a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005782a0 @ 0x005782a0
// Stable ID: aa_005782a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CONCAT31, FUN_005782a0.
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

void __fastcall FUN_005782a0(int param_1)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  

  piVar1 = (int *)CVOGReaction_ResolveObjectTarget

                            (CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x65c) >> 8),

                                      *(uint8_t *)(param_1 + 0x660)),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 0x658),*(uint32_t /* width from decompiler */ *)(param_1 + 0x65c));

  if (*(int *)(param_1 + 0x18) != 0) {

    (**(code **)(**(int **)(param_1 + 0x18) + 0x238))

              (2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x620),

               (int)(short)(*(short *)(param_1 + 0x61a) + *(short *)(param_1 + 0x198)),0,piVar1,0,0,

               0);

  }

  if (piVar1 != (int *)0x0) {

    iVar2 = (**(code **)(*piVar1 + 0x19c))();

    if ((iVar2 != 0) &&

       (piVar3 = (int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2), piVar3 != (int *)0x0)) {

      piVar1 = piVar3;

    }

    piVar3 = (int *)0x0;

    if (*(int *)(param_1 + 0x18) != 0) {

      iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x19c))();

      if ((iVar2 == 0) ||

         (piVar3 = (int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2), piVar3 == (int *)0x0)) {

        piVar3 = *(int **)(param_1 + 0x18);

      }

    }

    if ((piVar1 != (int *)0x0) && (piVar1 != piVar3)) {

      (**(code **)(*piVar1 + 0x238))

                (0x13,*(uint32_t /* width from decompiler */ *)(param_1 + 0x620),

                 (int)(short)(*(short *)(param_1 + 0x61a) + *(short *)(param_1 + 0x198)),0,piVar3,0,

                 0,0);

    }

  }

  return;

}
