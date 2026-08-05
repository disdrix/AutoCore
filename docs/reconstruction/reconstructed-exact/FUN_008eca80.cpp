// =============================================================================
// FUN_008eca80
// -----------------------------------------------------------------------------
// Stable ID: aa_008eca80
// Address:   0x008eca80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008eca80 @ 0x008eca80
// Stable ID: aa_008eca80
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, return×2, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_00402dd0, FUN_0040fb90, FUN_00415e90, FUN_008ec750, FUN_008eca80.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ FUN_008eca80(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  uint8_t auStack_18 [4];

  void *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af077;

  local_c = ExceptionList;

  if ((param_1 != 0) && (param_2 != -1)) {

    iVar2 = 0;

    ExceptionList = &local_c;

    local_14 = (void *)FUN_0040fb90();

    local_10 = 0;

    local_4 = 0;

    if (*(char *)(param_1 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(param_1 + 0x1d) = 1;

    while( true ) {

      if (*(char *)(param_1 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar2 == 0) {

        iVar2 = *(int *)(param_1 + 0x14);

      }

      else {

        iVar2 = *(int *)(iVar2 + 0x14);

      }

      if (iVar2 == 0) {

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(iVar2 + 8);

      }

      if (piVar3 == (int *)0x0) break;

      if ((((piVar3[0x3f] == param_2) && ((short)piVar3[0x3e] == 0)) && (piVar3[0x22] != -1)) &&

         (((*piVar3 < 0xdfd || (0xe02 < *piVar3)) ||

          ((DAT_00d1b6d8 == 0 ||

           (iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                         DAT_00d1b6d8) + 0x27c))(), 4 < iVar1)))))) {

        FUN_00402dd0(0);

        FUN_008ec750(piVar3,auStack_18);

      }

    }

    *(uint8_t *)(param_1 + 0x1d) = 0;

    local_4 = 0xffffffff;

    FUN_00415e90();

                    /* WARNING: Subroutine does not return */

    operator_delete(local_14);

  }

  return 0;

}
