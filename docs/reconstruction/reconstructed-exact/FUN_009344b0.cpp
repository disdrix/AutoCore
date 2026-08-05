// =============================================================================
// FUN_009344b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009344b0
// Address:   0x009344b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009344b0 @ 0x009344b0
// Stable ID: aa_009344b0
// Embedded strings (evidence for future rename):
//   - "HashError:TraverseToNext, not locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×17, goto×6, return×5, while×5, do×1, for×1.
//  - Notable callees: FUN_00411900×7, FUN_0059dc50×5, FUN_00402c40×2, FUN_007a4480×2, FUN_0092fd00, FUN_009344b0.
//  - Strings: "HashError:TraverseToNext, not locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 5.

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

void FUN_009344b0(uint32_t /* width from decompiler */ param_1,char param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if (*(int *)(DAT_00d1b6d8 + 0x548) == 0) {

    return;

  }

  iVar2 = *(int *)(*(int *)(DAT_00d1b6d8 + 0x548) + 0xc);

  iVar3 = -1;

  if (param_2 == '\0') {

    if (iVar2 < 2) {

      return;

    }

    _param_2 = 0;

    FUN_00402c40();

    iVar4 = FUN_00411900(&param_2);

    iVar2 = 0;

    while (iVar4 != 0) {

      cVar1 = FUN_0059dc50(DAT_00d1b6d8);

      iVar5 = iVar2;

      if ((cVar1 != '\0') &&

         (iVar5 = iVar4, *(int *)(iVar4 + 0x10) == *(int *)(DAT_00d1ad10 + 0x10))) {

        if (iVar2 != 0) goto LAB_009346b7;

        iVar4 = FUN_00411900(&param_2);

        if (iVar4 != 0) {

          do {

            cVar1 = FUN_0059dc50(DAT_00d1b6d8);

            if (cVar1 != '\0') {

              iVar2 = iVar4;

            }

            iVar4 = FUN_00411900(&param_2);

          } while (iVar4 != 0);

          if (iVar2 != 0) {

LAB_009346b7:

            iVar3 = *(int *)(iVar2 + 0x10);

          }

        }

        break;

      }

      iVar4 = FUN_00411900(&param_2);

      iVar2 = iVar5;

    }

  }

  else {

    if (iVar2 < 2) {

      return;

    }

    _param_2 = 0;

    FUN_00402c40();

    iVar2 = FUN_00411900(&param_2);

    while (iVar2 != 0) {

      cVar1 = FUN_0059dc50(DAT_00d1b6d8);

      if ((cVar1 != '\0') && (*(int *)(iVar2 + 0x10) == *(int *)(DAT_00d1ad10 + 0x10)))

      goto LAB_00934551;

      iVar2 = FUN_00411900(&param_2);

    }

  }

  goto LAB_009346ba;

  while (cVar1 = FUN_0059dc50(DAT_00d1b6d8), cVar1 == '\0') {

LAB_00934551:

    iVar2 = FUN_00411900(&param_2);

    if (iVar2 == 0) {

      iVar2 = 0;

      goto LAB_00934590;

    }

  }

  iVar3 = *(int *)(iVar2 + 0x10);

  goto LAB_009346ba;

  while (cVar1 = FUN_0059dc50(DAT_00d1b6d8), cVar1 == '\0') {

LAB_00934590:

    iVar4 = *(int *)(DAT_00d1b6d8 + 0x548);

    if (*(char *)(iVar4 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar2 == 0) {

      iVar2 = *(int *)(iVar4 + 0x14);

    }

    else {

      iVar2 = *(int *)(iVar2 + 0x14);

    }

    if (iVar2 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(iVar2 + 8);

    }

    if (iVar4 == 0) goto LAB_009346ba;

  }

  iVar3 = *(int *)(iVar4 + 0x10);

LAB_009346ba:

  *(uint8_t *)(*(int *)(DAT_00d1b6d8 + 0x548) + 0x1d) = 0;

  if (iVar3 != -1) {

    FUN_0092fd00();

  }

  return;

}
