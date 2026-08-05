// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×9, goto×3, for×2, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_00792250, FUN_007ac1c0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00792250
// -----------------------------------------------------------------------------
// Stable ID: aa_00792250
// Address:   0x00792250  (autoassault.exe, image base 0x400000)
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

void __thiscall Named_VOG_DEBUG_STOP_00792250(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    FUN_007ac1c0(param_2,param_3);

    iVar2 = param_1[0x130];

    if (iVar2 != 0) {

      iVar5 = 0;

      if (*(char *)(iVar2 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      *(uint8_t *)(iVar2 + 0x1d) = 1;

LAB_007922b0:

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

        if (iVar2 != 0) goto code_r0x007922fd;

        goto LAB_00792312;

      }

      *(uint8_t *)(param_1[0x130] + 0x1d) = 0;

    }

  }

  return;

code_r0x007922fd:

  piVar3 = (int *)(**(code **)(*piVar4 + 0x34))();

  cVar1 = (**(code **)(*piVar3 + 0x3d8))();

  if (cVar1 != '\0') {

LAB_00792312:

    (**(code **)(*piVar4 + 0xfc))(param_2,param_3);

  }

  goto LAB_007922b0;

}
