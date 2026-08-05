// =============================================================================
// FUN_0092b020
// -----------------------------------------------------------------------------
// Stable ID: aa_0092b020
// Address:   0x0092b020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092b020 @ 0x0092b020
// Stable ID: aa_0092b020
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×10, return×3, while×2, for×2.
//  - Notable callees: FUN_007a4480×4, CONCAT31×2, FUN_00411900×2, FUN_00402c40, FUN_0059dc50, FUN_0092b020.
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

uint FUN_0092b020(void)



{

  char cVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  uint *unaff_ESI;

  int local_4;

  

  uVar3 = *unaff_ESI;

  if ((uVar3 != 0) && (*(int *)(uVar3 + 0xe98) != 0)) {

    *(uint8_t *)((int)unaff_ESI + 6) = 1;

    if ((unaff_ESI[4] == 0) && (unaff_ESI[3] != 0)) {

      local_4 = 0;

      FUN_00402c40();

      iVar2 = FUN_00411900(&local_4);

      while (iVar2 != 0) {

        if (**(uint **)(iVar2 + 0x14c) == unaff_ESI[3]) {

          unaff_ESI[4] = *(uint *)(iVar2 + 0x10);

          iVar2 = *(int *)(*(int *)(*unaff_ESI + 0xe98) + 0x548);

          *(uint8_t *)(iVar2 + 0x1d) = 0;

          return CONCAT31((int3)((uint)iVar2 >> 8),1);

        }

        iVar2 = FUN_00411900(&local_4);

      }

      *(uint8_t *)(*(int *)(*(int *)(*unaff_ESI + 0xe98) + 0x548) + 0x1d) = 0;

      unaff_ESI[3] = 0;

    }

    unaff_ESI[4] = 0;

    unaff_ESI[3] = 0;

    iVar2 = *(int *)(*(int *)(*unaff_ESI + 0xe98) + 0x548);

    iVar4 = 0;

    local_4 = 0;

    if (*(char *)(iVar2 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar2 + 0x1d) = 1;

    while( true ) {

      iVar2 = *(int *)(*(int *)(*unaff_ESI + 0xe98) + 0x548);

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

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(iVar4 + 8);

      }

      if (iVar2 == 0) break;

      cVar1 = FUN_0059dc50(*(uint32_t /* width from decompiler */ *)(*unaff_ESI + 0xe98));

      if (cVar1 != '\0') {

        local_4 = iVar2;

      }

    }

    *(uint8_t *)(*(int *)(*(int *)(*unaff_ESI + 0xe98) + 0x548) + 0x1d) = 0;

    uVar3 = 0;

    if (local_4 != 0) {

      unaff_ESI[4] = *(uint *)(local_4 + 0x10);

      uVar3 = **(uint **)(local_4 + 0x14c);

      unaff_ESI[3] = uVar3;

      return CONCAT31((int3)(uVar3 >> 8),1);

    }

  }

  return uVar3 & 0xffffff00;

}
