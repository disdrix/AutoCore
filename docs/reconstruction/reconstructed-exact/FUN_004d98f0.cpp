// =============================================================================
// FUN_004d98f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d98f0
// Address:   0x004d98f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d98f0 @ 0x004d98f0
// Stable ID: aa_004d98f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×7, while×6, do×3, return×2.
//  - Notable callees: CONCAT31×2, FUN_004bae00×2, FUN_00406040, FUN_00407d70, FUN_00408a30, FUN_0040fb90, FUN_004bbeb0, FUN_004d98f0.
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

void FUN_004d98f0(void)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  uint local_64;

  uint32_t /* width from decompiler */ local_60;

  int local_5c;

  uint8_t local_58 [4];

  uint8_t auStack_54 [8];

  uint8_t local_4c [4];

  int *local_48;

  uint32_t /* width from decompiler */ local_44;

  int *local_3c;

  uint32_t /* width from decompiler */ local_38;

  int aiStack_30 [2];

  uint32_t /* width from decompiler */ uStack_28;

  int *piStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009a223a;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  local_48 = (int *)FUN_0040fb90();

  local_44 = 0;

  local_c = 0;

  piVar5 = (int *)FUN_00408a30();

  *(uint8_t *)((int)piVar5 + 0x29) = 1;

  piVar5[1] = (int)piVar5;

  *piVar5 = (int)piVar5;

  piVar5[2] = (int)piVar5;

  local_38 = 0;

  local_c = CONCAT31(local_c._1_3_,1);

  local_64 = local_64 & 0xffffff00;

  local_5c = 2;

  local_3c = piVar5;

  do {

    local_60 = 0;

    piVar6 = (int *)FUN_004bae00(local_64,&local_60);

    while (piVar6 != (int *)0x0) {

      (**(code **)(*piVar6 + 0x2b0))(local_4c);

      piVar6 = (int *)*local_48;

      if (piVar6 != local_48) {

        do {

          iVar2 = piVar6[2];

          uStack_20 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x160);

          uStack_1c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164);

          uStack_28 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0xa8) + 0x34);

          aiStack_30[0] = piVar6[2];

          piStack_24 = piVar5;

          FUN_00406040(auStack_54,aiStack_30);

          piVar6 = (int *)*piVar6;

        } while (piVar6 != local_48);

      }

      piVar6 = (int *)*local_48;

      *local_48 = (int)local_48;

      local_48[1] = (int)local_48;

      local_44 = 0;

      if (piVar6 != local_48) {

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar6);

      }

      piVar6 = (int *)FUN_004bae00(local_64,&local_60);

    }

    local_5c = local_5c + -1;

    local_64 = CONCAT31(local_64._1_3_,(char)local_64 == '\0');

    if (local_5c == 0) {

      FUN_004bbeb0();

      piVar5 = (int *)*local_3c;

      piVar6 = local_3c;

      if (piVar5 != local_3c) {

        do {

          if ((uint32_t /* width from decompiler */ *)piVar5[4] != (uint32_t /* width from decompiler */ *)0x0) {

            (*(code *)**(uint32_t /* width from decompiler */ **)piVar5[4])(1);

            piVar6 = local_3c;

          }

          if (*(char *)((int)piVar5 + 0x29) == '\0') {

            piVar3 = (int *)piVar5[2];

            if (*(char *)((int)piVar3 + 0x29) == '\0') {

              cVar1 = *(char *)(*piVar3 + 0x29);

              piVar5 = piVar3;

              piVar3 = (int *)*piVar3;

              while (cVar1 == '\0') {

                cVar1 = *(char *)(*piVar3 + 0x29);

                piVar5 = piVar3;

                piVar3 = (int *)*piVar3;

              }

            }

            else {

              cVar1 = *(char *)(piVar5[1] + 0x29);

              piVar4 = (int *)piVar5[1];

              piVar3 = piVar5;

              while ((piVar5 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar5[2]))) {

                cVar1 = *(char *)(piVar5[1] + 0x29);

                piVar4 = (int *)piVar5[1];

                piVar3 = piVar5;

              }

            }

          }

        } while (piVar5 != piVar6);

      }

      local_c = local_c & 0xffffff00;

      FUN_00407d70(local_58,*piVar6,piVar6);

                    /* WARNING: Subroutine does not return */

      operator_delete(local_3c);

    }

  } while( true );

}
