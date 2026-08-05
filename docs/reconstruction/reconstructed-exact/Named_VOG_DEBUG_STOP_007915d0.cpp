// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×10, goto×3, for×2, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_007915d0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_007915d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007915d0
// Address:   0x007915d0  (autoassault.exe, image base 0x400000)
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

void __thiscall Named_VOG_DEBUG_STOP_007915d0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar1 != '\0') && (param_1[0x130] != 0)) {

    cVar1 = (char)param_2;

    if (cVar1 == '\0') {

      (**(code **)(*param_1 + 0x330))(10);

    }

    *(char *)((int)param_1 + 0xca) = cVar1;

    if (cVar1 != '\0') {

      (**(code **)(*param_1 + 0x330))(9);

    }

    iVar2 = param_1[0x130];

    iVar5 = 0;

    if (*(char *)(iVar2 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar2 + 0x1d) = 1;

LAB_00791650:

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

    if (piVar4 != (int *)0x0) {

      iVar2 = (**(code **)(*piVar4 + 0x34))();

      if (iVar2 != 0) goto code_r0x0079169d;

      goto LAB_007916b2;

    }

    *(uint8_t *)(param_1[0x130] + 0x1d) = 0;

    (**(code **)(*param_1 + 0x34c))();

  }

  return;

code_r0x0079169d:

  piVar3 = (int *)(**(code **)(*piVar4 + 0x34))();

  cVar1 = (**(code **)(*piVar3 + 0x3d8))();

  if (cVar1 != '\0') {

LAB_007916b2:

    (**(code **)(*piVar4 + 0xd4))(param_2);

  }

  goto LAB_00791650;

}
