// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×9, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_004133c0, FUN_004281d0, FUN_00756be0, FUN_007917c0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_007917c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007917c0
// Address:   0x007917c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_VOG_DEBUG_STOP_007917c0(int *param_1)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  

  if (param_1[0x130] != 0) {

    (**(code **)(*param_1 + 0x3c0))(0);

    if (param_1[0x12e] != 0) {

      (**(code **)(*param_1 + 0x318))();

      param_1[0x12e] = 0;

    }

    iVar2 = param_1[0x130];

    iVar5 = 0;

    if (*(char *)(iVar2 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar2 + 0x1d) = 1;

    while( true ) {

      iVar2 = param_1[0x130];

      if (*(char *)(iVar2 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar5 == 0) {

        iVar5 = *(int *)(iVar2 + 0x14);

      }

      else {

        iVar5 = *(int *)(iVar5 + 0x14);

      }

      if (iVar5 == 0) {

        piVar4 = (int *)0x0;

      }

      else {

        piVar4 = *(int **)(iVar5 + 8);

      }

      if (piVar4 == (int *)0x0) break;

      iVar2 = (**(code **)(*piVar4 + 0x34))();

      if (iVar2 != 0) {

        piVar3 = (int *)(**(code **)(*piVar4 + 0x34))();

        cVar1 = (**(code **)(*piVar3 + 0x3d8))();

        if (cVar1 != '\0') {

          piVar3 = (int *)(**(code **)(*piVar4 + 0x34))();

          (**(code **)(*piVar3 + 0x440))();

        }

      }

      (**(code **)(*piVar4 + 0x334))(0);

      piVar4[0xac] = 0;

      FUN_00756be0(piVar4);

    }

    *(uint8_t *)(param_1[0x130] + 0x1d) = 0;

    FUN_004133c0(0);

    FUN_004281d0();

    param_1[0x131] = 1;

  }

  return;

}
