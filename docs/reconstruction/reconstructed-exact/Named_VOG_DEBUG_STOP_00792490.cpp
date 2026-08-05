// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×14, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_0074e260, FUN_00792490.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00792490
// -----------------------------------------------------------------------------
// Stable ID: aa_00792490
// Address:   0x00792490  (autoassault.exe, image base 0x400000)
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

void __fastcall Named_VOG_DEBUG_STOP_00792490(int *param_1)



{

  int *piVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar3 != '\0') {

    (**(code **)(*param_1 + 0x330))(8);

    *(uint8_t *)(param_1 + 0x23) = 0;

    *(uint8_t *)(param_1 + 0x32) = 0;

    *(uint8_t *)((int)param_1 + 0x492) = 0;

    if (param_1[0xab] != 0) {

      if (param_1[0xaa] != 0) {

        iVar4 = *(int *)(param_1[0xaa] + 4);

        piVar2 = *(int **)(iVar4 + 0x3c);

        if (piVar2 != (int *)0x0) {

          piVar1 = piVar2 + 1;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 == 0) {

            (**(code **)(*piVar2 + 8))();

          }

        }

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x3c) = 0;

        FUN_0074e260(*(uint32_t /* width from decompiler */ *)(param_1[0xab] + 0x8c));

      }

      if ((uint32_t /* width from decompiler */ *)param_1[0xab] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xab])(1);

      }

      param_1[0xab] = 0;

    }

    (**(code **)(*param_1 + 0x58))();

    iVar4 = param_1[0x136];

    iVar5 = 0;

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    while( true ) {

      iVar4 = param_1[0x136];

      if (*(char *)(iVar4 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar5 == 0) {

        iVar5 = *(int *)(iVar4 + 0x14);

      }

      else {

        iVar5 = *(int *)(iVar5 + 0x14);

      }

      if (iVar5 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(iVar5 + 8);

      }

      if (iVar4 == 0) break;

      (**(code **)(*param_1 + 0xb0))(iVar4);

    }

    *(uint8_t *)(param_1[0x136] + 0x1d) = 0;

    (**(code **)(*param_1 + 0x3b4))();

    cVar3 = (**(code **)(*param_1 + 0x1c0))();

    if (cVar3 != '\0') {

      if ((uint32_t /* width from decompiler */ *)param_1[0xaa] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xaa])(1);

      }

      param_1[0xaa] = 0;

    }

    if ((uint32_t /* width from decompiler */ *)param_1[0x130] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x130])(1);

    }

    param_1[0x130] = 0;

    param_1[0x12e] = 0;

    param_1[0x12f] = 0;

    param_1[0x12d] = 0;

  }

  return;

}
