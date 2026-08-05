// =============================================================================
// FUN_0078dd90
// -----------------------------------------------------------------------------
// Stable ID: aa_0078dd90
// Address:   0x0078dd90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078dd90 @ 0x0078dd90
// Stable ID: aa_0078dd90
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, return×2, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_0078dd90, FUN_00792250, FUN_007ac1c0.
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

void __thiscall FUN_0078dd90(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  

  cVar1 = (**(code **)(*param_1 + 0x490))();

  if ((cVar1 == '\0') && (iVar2 = param_1[0x130], iVar2 != 0)) {

    iVar4 = 0;

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

      if (iVar4 == 0) {

        iVar4 = *(int *)(iVar2 + 0x14);

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

      iVar2 = (**(code **)(*piVar3 + 0x78))();

      if (iVar2 < 0x68) {

        (**(code **)(*piVar3 + 0xfc))(param_2,param_3);

      }

    }

    *(uint8_t *)(param_1[0x130] + 0x1d) = 0;

    FUN_007ac1c0(param_2,param_3);

    return;

  }

  FUN_00792250(param_2,param_3);

  return;

}
