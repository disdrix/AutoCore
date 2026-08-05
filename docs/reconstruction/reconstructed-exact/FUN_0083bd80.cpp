// =============================================================================
// FUN_0083bd80
// -----------------------------------------------------------------------------
// Stable ID: aa_0083bd80
// Address:   0x0083bd80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083bd80 @ 0x0083bd80
// Stable ID: aa_0083bd80
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, do×2, for×2, while×2.
//  - Notable callees: FUN_007a4480×4, FUN_00415720, FUN_0083b830, FUN_0083bd80.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 3.

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

void FUN_0083bd80(void)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int *piVar5;

  int unaff_EDI;

  

  if (*(int *)(unaff_EDI + 0x538) == 0) {

    return;

  }

  do {

    iVar2 = FUN_00415720();

    iVar1 = *(int *)(unaff_EDI + 0x538);

    iVar4 = 0;

    if (*(char *)(iVar1 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar1 + 0x1d) = 1;

    do {

      iVar1 = *(int *)(unaff_EDI + 0x538);

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

        piVar5 = (int *)0x0;

      }

      else {

        piVar5 = *(int **)(iVar4 + 8);

      }

      if (piVar5 == (int *)0x0) {

        *(uint8_t *)(*(int *)(unaff_EDI + 0x538) + 0x1d) = 0;

        return;

      }

    } while (piVar5[0x44] <= iVar2);

    iVar1 = *piVar5;

    uVar3 = FUN_0083b830();

    (**(code **)(iVar1 + 0x110))(uVar3);

    *(uint *)(unaff_EDI + 0x544) =

         *(uint *)(unaff_EDI + 0x544) & ~(1 << ((byte)piVar5[0x44] & 0x1f));

    piVar5[0x44] = iVar2;

    *(uint *)(unaff_EDI + 0x544) = *(uint *)(unaff_EDI + 0x544) | 1 << ((byte)iVar2 & 0x1f);

    *(uint8_t *)(*(int *)(unaff_EDI + 0x538) + 0x1d) = 0;

    if (*(int *)(unaff_EDI + 0x538) == 0) {

      return;

    }

  } while( true );

}
