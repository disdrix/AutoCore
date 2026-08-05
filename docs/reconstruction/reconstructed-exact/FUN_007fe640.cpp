// =============================================================================
// FUN_007fe640
// -----------------------------------------------------------------------------
// Stable ID: aa_007fe640
// Address:   0x007fe640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fe640 @ 0x007fe640
// Stable ID: aa_007fe640
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×8, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_004195d0, FUN_007fe640.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
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

void FUN_007fe640(int param_1)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  

  iVar1 = *(int *)(param_1 + 0x3084);

  iVar4 = 0;

  if (iVar1 != 0) {

    if (*(char *)(iVar1 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar1 + 0x1d) = 1;

    while( true ) {

      iVar1 = *(int *)(param_1 + 0x3084);

      if (*(char *)(iVar1 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar4 == 0) {

        iVar4 = *(int *)(iVar1 + 0x14);

      }

      else {

        iVar4 = *(int *)(iVar4 + 0x20);

      }

      if (iVar4 == 0) {

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(iVar4 + 0xc);

      }

      if (piVar3 == (int *)0x0) break;

      cVar2 = (**(code **)(*piVar3 + 0x3d8))();

      if (cVar2 != '\0') {

        (**(code **)(*piVar3 + 0x440))();

      }

      if (piVar3[0xac] != 0) {

        (**(code **)(*(int *)piVar3[0xac] + 0xb0))(piVar3);

      }

    }

    *(uint8_t *)(*(int *)(param_1 + 0x3084) + 0x1d) = 0;

    FUN_004195d0();

  }

  return;

}
