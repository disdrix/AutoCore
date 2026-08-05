// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_004138d0, FUN_0085fd80.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_0085fd80
// -----------------------------------------------------------------------------
// Stable ID: aa_0085fd80
// Address:   0x0085fd80  (autoassault.exe, image base 0x400000)
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

void Named_VOG_DEBUG_STOP_0085fd80(void)



{

  int iVar1;

  int iVar2;

  int *unaff_EDI;

  

  iVar1 = unaff_EDI[0x15c];

  if (iVar1 != 0) {

    iVar2 = 0;

    if (*(char *)(iVar1 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar1 + 0x1d) = 1;

    while( true ) {

      iVar1 = unaff_EDI[0x15c];

      if (*(char *)(iVar1 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar2 == 0) {

        iVar2 = *(int *)(iVar1 + 0x14);

      }

      else {

        iVar2 = *(int *)(iVar2 + 0x20);

      }

      if (iVar2 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(iVar2 + 0xc);

      }

      if (iVar1 == 0) break;

      (**(code **)(*unaff_EDI + 0xbc))(iVar1);

      unaff_EDI[0x140] = unaff_EDI[0x140] + -1;

    }

    *(uint8_t *)(unaff_EDI[0x15c] + 0x1d) = 0;

    (**(code **)(*(int *)unaff_EDI[0x15c] + 4))();

    FUN_004138d0();

  }

  return;

}
