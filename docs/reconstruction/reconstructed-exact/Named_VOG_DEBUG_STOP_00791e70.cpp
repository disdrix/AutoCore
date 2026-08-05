// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×8, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_00791e70.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00791e70
// -----------------------------------------------------------------------------
// Stable ID: aa_00791e70
// Address:   0x00791e70  (autoassault.exe, image base 0x400000)
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

void __fastcall Named_VOG_DEBUG_STOP_00791e70(int *param_1)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar2 != '\0') {

    if ((char)param_1[0x33] != '\0') {

      (**(code **)(*param_1 + 0x180))();

    }

    iVar1 = param_1[0x130];

    if (iVar1 != 0) {

      iVar4 = 0;

      if (*(char *)(iVar1 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      *(uint8_t *)(iVar1 + 0x1d) = 1;

      while( true ) {

        iVar1 = param_1[0x130];

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

        (**(code **)(*piVar3 + 0x340))();

      }

      *(uint8_t *)(param_1[0x130] + 0x1d) = 0;

    }

  }

  return;

}
