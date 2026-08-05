// =============================================================================
// FUN_008a2670
// -----------------------------------------------------------------------------
// Stable ID: aa_008a2670
// Address:   0x008a2670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a2670 @ 0x008a2670
// Stable ID: aa_008a2670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, return×1, for×1, goto×1, while×1.
//  - Notable callees: FUN_0059db80, FUN_008a2670.
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

void FUN_008a2670(void)



{

  int iVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  uint uVar5;

  int unaff_ESI;

  uint uVar6;

  

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x520) = 0;

  uVar5 = 0;

  do {

    iVar1 = *(int *)(unaff_ESI + 0x5b4);

    if ((iVar1 == 0) || ((uint)(*(int *)(unaff_ESI + 0x5b8) - iVar1 >> 2) <= uVar5)) {

      if (0 < *(int *)(unaff_ESI + 0x520)) {

        (**(code **)(**(int **)(unaff_ESI + 0x568) + 0x460))

                  (g_flOne / (float)*(int *)(unaff_ESI + 0x520));

      }

      return;

    }

    iVar1 = *(int *)(iVar1 + uVar5 * 4);

    if (iVar1 != 0) {

      *(int *)(unaff_ESI + 0x520) = *(int *)(unaff_ESI + 0x520) + 1;

      for (uVar6 = 0;

          (iVar2 = *(int *)(unaff_ESI + 0x5a4), iVar2 != 0 &&

          (uVar6 < (uint)(*(int *)(unaff_ESI + 0x5a8) - iVar2 >> 2))); uVar6 = uVar6 + 1) {

        iVar2 = *(int *)(iVar2 + uVar6 * 4);

        if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x504), iVar2 != 0)) {

          if (*(int *)(unaff_ESI + 0x50c) == 0) {

            if (DAT_00d1b6d8 != 0) {

              iVar4 = FUN_0059db80(DAT_00d1b6d8);

LAB_008a272a:

              if ((iVar4 == *(int *)(iVar1 + 0x110)) && (*(int *)(iVar1 + 0x528) != 0)) {

                cVar3 = (**(code **)(**(int **)(iVar1 + 0x528) + 0x3bc))();

                if (cVar3 != '\0') {

                  *(int *)(unaff_ESI + 0x520) = *(int *)(unaff_ESI + 0x520) + 1;

                }

              }

            }

          }

          else {

            iVar4 = *(int *)(iVar2 + 0x120);

            if ((iVar4 != -1) ||

               ((*(int *)(iVar2 + 0x14c) != 0 &&

                (iVar4 = *(int *)(*(int *)(iVar2 + 0x14c) + 0xfc), iVar4 != -1))))

            goto LAB_008a272a;

          }

        }

      }

    }

    uVar5 = uVar5 + 1;

  } while( true );

}
