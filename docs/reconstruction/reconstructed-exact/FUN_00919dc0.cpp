// =============================================================================
// FUN_00919dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00919dc0
// Address:   0x00919dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00919dc0 @ 0x00919dc0
// Stable ID: aa_00919dc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, return×1, goto×1.
//  - Notable callees: FUN_0040b020×2, FUN_004c0440×2, FUN_004027f0, FUN_00418700, FUN_00418790, FUN_004c0080, FUN_00919dc0, FUN_0092a200.
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

void FUN_00919dc0(void)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int iStack_28;

  int iStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  float fStack_14;

  

  piVar3 = (int *)FUN_0040b020();

  do {

    if (piVar3 == (int *)0x0) {

      return;

    }

    (**(code **)(*piVar3 + 0x218))(DAT_00d1b644);

    if (*(int *)(piVar3[0x2a] + 0x38) == 0x12) {

      iStack_28 = (**(code **)(*piVar3 + 0x1d8))();

      iVar5 = DAT_00d1b74c;

      if ((*(uint *)(iStack_28 + 0x210) & *(uint *)(iStack_28 + 0x214)) == 0xffffffff) {

        iVar4 = FUN_00418700(DAT_00d1b74c,*(uint32_t /* width from decompiler */ *)(DAT_00d1b74c + 4),&iStack_28);

        FUN_00418790();

        *(int *)(iVar5 + 4) = iVar4;

        **(int **)(iVar4 + 4) = iVar4;

        goto LAB_00919e53;

      }

    }

    else {

LAB_00919e53:

      if ((((uint)piVar3[0x5f] >> 6 & 1) != 0) &&

         (iVar5 = (**(code **)(*piVar3 + 0x1cc))(), iStack_24 = iVar5, iVar5 != 0)) {

        if ((*(int *)(piVar3[0x2a] + 0x38) == 0xe) &&

           ((iVar4 = (**(code **)(*piVar3 + 0x1d4))(), iStack_28 = iVar4, iVar4 != 0 &&

            (*(char *)(iVar4 + 0x2ac) == '\0')))) {

          FUN_004027f0(&DAT_00d1b73c);

          iVar5 = *(int *)(iVar4 + 600);

          if (iVar5 != 0) {

            (**(code **)(*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5) + 0x218))

                      (DAT_00d1b644);

            FUN_004c0080(*(uint32_t /* width from decompiler */ *)(iVar4 + 600));

          }

          iVar5 = 0;

          iStack_28 = 3;

          do {

            if (*(int *)(iVar5 + *(int *)(iVar4 + 0x260)) != 0) {

              uStack_18 = 0;

              uStack_1c = 0;

              uStack_20 = 0;

              fStack_14 = g_flOne;

              FUN_004c0440(*(uint32_t /* width from decompiler */ *)(iVar5 + *(int *)(iVar4 + 0x260)),&DAT_00d1a640,&uStack_20

                          );

              iVar1 = *(int *)(iVar5 + *(int *)(iVar4 + 0x260));

              (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x218))

                        (DAT_00d1b644);

            }

            iVar5 = iVar5 + 4;

            iStack_28 = iStack_28 + -1;

          } while (iStack_28 != 0);

          iStack_28 = 0;

          iVar5 = iStack_24;

        }

        iVar4 = *(int *)(*(int *)(iVar5 + 4) + 4) + iVar5;

        FUN_004c0440(iVar5,iVar4 + 0x84,iVar4 + 0x94);

        iVar5 = DAT_00d1ad10;

        cVar2 = FUN_0092a200();

        if (cVar2 != '\0') {

          *(uint8_t *)(iVar5 + 4) = 1;

        }

      }

    }

    piVar3 = (int *)FUN_0040b020();

  } while( true );

}
