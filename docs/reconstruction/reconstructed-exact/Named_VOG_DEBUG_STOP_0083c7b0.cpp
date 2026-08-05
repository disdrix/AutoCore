// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×14, for×4, while×2, return×1.
//  - Notable callees: FUN_007a4480×8, FUN_00415870×2, FUN_0083c7b0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_0083c7b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083c7b0
// Address:   0x0083c7b0  (autoassault.exe, image base 0x400000)
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

void Named_VOG_DEBUG_STOP_0083c7b0(int *param_1)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  

  iVar1 = param_1[0x14e];

  param_1[0x150] = 0;

  param_1[0x151] = 0;

  if (iVar1 != 0) {

    iVar4 = 0;

    if (*(char *)(iVar1 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar1 + 0x1d) = 1;

    while( true ) {

      iVar1 = param_1[0x14e];

      if (*(char *)(iVar1 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar4 == 0) {

        iVar4 = *(int *)(iVar1 + 0x14);

      }

      else {

        iVar4 = *(int *)(iVar4 + 0x14);

      }

      if (iVar4 == 0) {

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(iVar4 + 8);

      }

      if (piVar3 == (int *)0x0) break;

      cVar2 = (**(code **)(*piVar3 + 0x3d8))();

      if (cVar2 != '\0') {

        (**(code **)(*piVar3 + 0x440))();

      }

      (**(code **)(*param_1 + 0xbc))(piVar3);

    }

    *(uint8_t *)(param_1[0x14e] + 0x1d) = 0;

    FUN_00415870();

  }

  iVar1 = param_1[0x14f];

  if (iVar1 != 0) {

    iVar4 = 0;

    if (*(char *)(iVar1 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar1 + 0x1d) = 1;

    while( true ) {

      iVar1 = param_1[0x14f];

      if (*(char *)(iVar1 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar4 == 0) {

        iVar4 = *(int *)(iVar1 + 0x14);

      }

      else {

        iVar4 = *(int *)(iVar4 + 0x14);

      }

      if (iVar4 == 0) {

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(iVar4 + 8);

      }

      if (piVar3 == (int *)0x0) break;

      cVar2 = (**(code **)(*piVar3 + 0x3d8))();

      if (cVar2 != '\0') {

        (**(code **)(*piVar3 + 0x440))();

      }

      (**(code **)(*param_1 + 0xbc))(piVar3);

    }

    *(uint8_t *)(param_1[0x14f] + 0x1d) = 0;

    FUN_00415870();

  }

  return;

}
