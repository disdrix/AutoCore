// =============================================================================
// FUN_0083c9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083c9b0
// Address:   0x0083c9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083c9b0 @ 0x0083c9b0
// Stable ID: aa_0083c9b0
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, do×2, for×2, while×2.
//  - Notable callees: FUN_007a4480×4, FUN_004158c0, FUN_0083bd80, FUN_0083c9b0.
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

void FUN_0083c9b0(int *param_1)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  

  iVar2 = param_1[0x14f];

  if (iVar2 == 0) {

    return;

  }

  do {

    iVar4 = 0;

    if (*(char *)(iVar2 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar2 + 0x1d) = 1;

    do {

      iVar2 = param_1[0x14f];

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

      if (piVar3 == (int *)0x0) {

        *(uint8_t *)(param_1[0x14f] + 0x1d) = 0;

        return;

      }

      cVar1 = (**(code **)(*piVar3 + 0xf8))();

    } while (cVar1 != '\0');

    *(uint8_t *)(param_1[0x14f] + 0x1d) = 0;

    iVar2 = FUN_004158c0();

    if (iVar2 == 0) {

      param_1[0x150] = param_1[0x150] + -1;

      param_1[0x151] = param_1[0x151] & ~(1 << ((byte)piVar3[0x44] & 0x1f));

      FUN_0083bd80();

      cVar1 = (**(code **)(*piVar3 + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(*piVar3 + 0x440))();

      }

      (**(code **)(*param_1 + 0xbc))(piVar3);

    }

    iVar2 = param_1[0x14f];

  } while( true );

}
