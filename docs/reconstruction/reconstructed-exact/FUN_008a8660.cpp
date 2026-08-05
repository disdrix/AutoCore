// =============================================================================
// FUN_008a8660
// -----------------------------------------------------------------------------
// Stable ID: aa_008a8660
// Address:   0x008a8660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a8660 @ 0x008a8660
// Stable ID: aa_008a8660
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, return×2, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_0059dc50, FUN_008a8660, FUN_0092fd00.
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

uint FUN_008a8660(void)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  if ((DAT_00d1b6d8 != 0) && (iVar3 = *(int *)(DAT_00d1b6d8 + 0x548), iVar3 != 0)) {

    iVar2 = 0;

    iVar4 = 0;

    if (*(char *)(iVar3 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar3 + 0x1d) = 1;

    while( true ) {

      iVar3 = *(int *)(DAT_00d1b6d8 + 0x548);

      if (*(char *)(iVar3 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar4 == 0) {

        iVar4 = *(int *)(iVar3 + 0x14);

      }

      else {

        iVar4 = *(int *)(iVar4 + 0x14);

      }

      if (iVar4 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(iVar4 + 8);

      }

      if (iVar3 == 0) break;

      cVar1 = FUN_0059dc50(DAT_00d1b6d8);

      if (cVar1 != '\0') {

        iVar2 = *(int *)(iVar3 + 0x10);

      }

    }

    *(uint8_t *)(*(int *)(DAT_00d1b6d8 + 0x548) + 0x1d) = 0;

    FUN_0092fd00();

    return (uint)(iVar2 != 0);

  }

  return DAT_00d1b6d8 & 0xffffff00;

}
