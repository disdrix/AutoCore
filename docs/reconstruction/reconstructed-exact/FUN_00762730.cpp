// =============================================================================
// FUN_00762730
// -----------------------------------------------------------------------------
// Stable ID: aa_00762730
// Address:   0x00762730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00762730 @ 0x00762730
// Stable ID: aa_00762730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×12, do×3, while×3, return×2, for×2.
//  - Notable callees: FUN_0043a1d0×4, memmove×4, FUN_00456780×2, FUN_00456960×2, FUN_007649c0×2, FUN_00762730.
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

void __thiscall FUN_00762730(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  void *pvVar6;

  int local_28;

  int *local_20;

  uint8_t local_1c [4];

  void *local_18;

  int *local_14;

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b318e;

  pvStack_c = ExceptionList;

  pvVar6 = (void *)0x0;

  local_18 = (void *)0x0;

  local_14 = (int *)0x0;

  local_10 = 0;

  local_4 = 0;

  local_28 = 0;

  ExceptionList = &pvStack_c;

  do {

    iVar2 = 0;

    if (*(int *)(param_1 + 0xc) != 0) {

      iVar2 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28;

    }

    if (iVar2 <= local_28) {

      if (pvVar6 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar6);

      }

      ExceptionList = pvStack_c;

      return;

    }

    iVar2 = *(int *)(param_1 + 0xc) + local_28 * 0x28;

    FUN_00456780(0);

    piVar5 = *(int **)(iVar2 + 4);

    if (piVar5 != *(int **)(iVar2 + 8)) {

      local_20 = piVar5 + 1;

      do {

        piVar1 = (int *)*piVar5;

        iVar3 = (**(code **)(*piVar1 + 4))();

        if ((iVar3 == 0x47504345) && (piVar1[0x16] == param_2)) {

          memmove(piVar5,local_20,(*(int *)(iVar2 + 8) - (int)local_20 >> 2) * 4);

          *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -4;

          iVar3 = *(int *)(param_1 + 4);

          for (puVar4 = *(uint32_t /* width from decompiler */ **)(iVar3 + 0xc0); puVar4 != *(uint32_t /* width from decompiler */ **)(iVar3 + 0xc4);

              puVar4 = puVar4 + 1) {

            if ((int *)*puVar4 == piVar1) {

              memmove(puVar4,puVar4 + 1,(*(int *)(iVar3 + 0xc4) - (int)(puVar4 + 1) >> 2) * 4);

              *(int *)(iVar3 + 0xc4) = *(int *)(iVar3 + 0xc4) + -4;

              break;

            }

          }

          if ((local_18 == (void *)0x0) ||

             ((uint)(local_10 - (int)local_18 >> 2) <= (uint)((int)local_14 - (int)local_18 >> 2)))

          {

            FUN_00456960(local_14);

          }

          else {

            *local_14 = (int)piVar1;

            local_14 = local_14 + 1;

          }

        }

        else {

          piVar5 = piVar5 + 1;

          local_20 = local_20 + 1;

        }

      } while (piVar5 != *(int **)(iVar2 + 8));

    }

    FUN_007649c0(local_1c,&LAB_00437a50,param_3);

    piVar5 = local_14;

    pvVar6 = local_18;

    FUN_0043a1d0(*(uint32_t /* width from decompiler */ *)(iVar2 + 8),local_18,local_14,param_2);

    FUN_0043a1d0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 0xc4),pvVar6,piVar5,param_2);

    if (local_28 == 0) {

      FUN_00456780(0);

      piVar5 = *(int **)(iVar2 + 0x14);

      if (piVar5 != *(int **)(iVar2 + 0x18)) {

        local_20 = piVar5 + 1;

        do {

          piVar1 = (int *)*piVar5;

          iVar3 = (**(code **)(*piVar1 + 4))();

          if ((iVar3 == 0x47504345) && (piVar1[0x16] == param_2)) {

            memmove(piVar5,local_20,(*(int *)(iVar2 + 0x18) - (int)local_20 >> 2) * 4);

            *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + -4;

            iVar3 = *(int *)(param_1 + 4);

            for (puVar4 = *(uint32_t /* width from decompiler */ **)(iVar3 + 0xd0); puVar4 != *(uint32_t /* width from decompiler */ **)(iVar3 + 0xd4);

                puVar4 = puVar4 + 1) {

              if ((int *)*puVar4 == piVar1) {

                memmove(puVar4,puVar4 + 1,(*(int *)(iVar3 + 0xd4) - (int)(puVar4 + 1) >> 2) * 4);

                *(int *)(iVar3 + 0xd4) = *(int *)(iVar3 + 0xd4) + -4;

                break;

              }

            }

            if ((local_18 == (void *)0x0) ||

               ((uint)(local_10 - (int)local_18 >> 2) <= (uint)((int)local_14 - (int)local_18 >> 2))

               ) {

              FUN_00456960(local_14);

            }

            else {

              *local_14 = (int)piVar1;

              local_14 = local_14 + 1;

            }

          }

          else {

            piVar5 = piVar5 + 1;

            local_20 = local_20 + 1;

          }

        } while (piVar5 != *(int **)(iVar2 + 0x18));

      }

      FUN_007649c0(local_1c,&LAB_00437a50,param_3);

      piVar5 = local_14;

      pvVar6 = local_18;

      FUN_0043a1d0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x18),local_18,local_14,param_2);

      FUN_0043a1d0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + 0xd4),pvVar6,piVar5,param_2);

    }

    local_28 = local_28 + 1;

  } while( true );

}
