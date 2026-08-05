// =============================================================================
// FUN_00942530
// -----------------------------------------------------------------------------
// Stable ID: aa_00942530
// Address:   0x00942530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00942530 @ 0x00942530
// Stable ID: aa_00942530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×14, return×8, goto×2, do×1, while×1.
//  - Notable callees: Client_SendSectorPacket, FUN_0040fb90, FUN_00513770, FUN_00572060, FUN_00942530.
//  - Return sites: 8.

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

void FUN_00942530(void)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  int unaff_EDI;

  uint8_t local_58 [4];

  int *local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ auStack_4c [6];

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  int iStack_28;

  uint8_t uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009bb985;

  local_c = ExceptionList;

  if (*(char *)(unaff_EDI + 0xb6) == '\0') {

    if (*(int *)(unaff_EDI + 0x3108) == 1) {

      if (*(int *)(unaff_EDI + 0xe98) == 0) {

        return;

      }

      iVar3 = *(int *)(*(int *)(unaff_EDI + 0xe98) + 0x250);

      if (iVar3 == 0) {

        return;

      }

      iVar3 = *(int *)(iVar3 + 0x2b0);

    }

    else {

      if (*(int *)(unaff_EDI + 0x3108) != 3) {

        return;

      }

      if (*(int *)(unaff_EDI + 0xe98) == 0) {

        return;

      }

      if (*(char *)(*(int *)(unaff_EDI + 0xe04) + 0xf5) == '\0') {

        return;

      }

      iVar3 = *(int *)(*(int *)(unaff_EDI + 0xe98) + 0xcbc);

    }

    if (iVar3 != 0) {

      ExceptionList = &local_c;

      local_54 = (int *)FUN_0040fb90();

      local_50 = 0;

      local_4 = 0;

      FUN_00572060(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x310c),local_58);

      piVar5 = (int *)*local_54;

      if (piVar5 != local_54) {

        do {

          piVar1 = (int *)piVar5[2];

          if ((piVar1 != (int *)0x0) && (cVar2 = FUN_00513770(), cVar2 != '\0')) {

            iVar3 = (**(code **)(*piVar1 + 0x1e0))();

            if (iVar3 == 0) {

LAB_00942639:

              iVar3 = (**(code **)(*piVar1 + 0x1e0))();

              if ((iVar3 != 0) ||

                 (*(short *)(*(int *)(piVar1[0x2a] + 0x3c) + 0x3f4) !=

                  *(short *)(unaff_EDI + 0x3110))) goto LAB_009426b1;

            }

            else {

              piVar4 = (int *)(**(code **)(*piVar1 + 0x1e0))();

              iVar3 = (**(code **)(*piVar4 + 0x60))();

              if (iVar3 != *(short *)(unaff_EDI + 0x3110)) goto LAB_00942639;

            }

            auStack_4c[0] = 0x2027;

            uStack_14 = 0;

            uStack_10 = (**(code **)(*piVar1 + 0x25c))();

            iStack_34 = piVar1[0x58];

            iStack_30 = piVar1[0x59];

            iStack_2c = piVar1[0x5a];

            iStack_28 = piVar1[0x5b];

            Client_SendSectorPacket(&DAT_00d1a840,0x40,auStack_4c);

          }

LAB_009426b1:

          piVar5 = (int *)*piVar5;

        } while (piVar5 != local_54);

      }

      local_4 = 0xffffffff;

      piVar5 = (int *)*local_54;

      *local_54 = (int)local_54;

      local_54[1] = (int)local_54;

      local_50 = 0;

      if (piVar5 != local_54) {

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar5);

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(local_54);

    }

  }

  return;

}
