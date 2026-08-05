// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×15, while×4, do×2, goto×2, return×2.
//  - Notable callees: FUN_004afd00×4, FUN_00567420×4, FUN_004b07d0×3, FUN_004ab300×2, FUN_004ae050, FUN_004b0a20, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_004ae050
// -----------------------------------------------------------------------------
// Stable ID: aa_004ae050
// Address:   0x004ae050  (autoassault.exe, image base 0x400000)
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

void Named_VOG_DEBUG_STOP_004ae050(void *param_1,int param_2)



{

  int iVar1;

  char cVar2;

  char cVar3;

  int iVar4;

  void *pvVar5;

  int iVar6;

  int iVar7;

  int local_2c;

  int local_28;

  int local_20;

  uint8_t local_1c [4];

  void *local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a134c;

  local_c = ExceptionList;

  iVar6 = *(int *)((int)param_1 + 4);

  if (iVar6 != 0) {

    iVar7 = *(int *)((int)param_1 + 8);

    local_20 = iVar7 - iVar6 >> 3;

    if (2 < local_20) {

      local_18 = (void *)0x0;

      local_14 = 0;

      local_10 = 0;

      local_4 = 0;

      ExceptionList = &local_c;

      FUN_004b0a20(iVar6,iVar7,iVar7 - iVar6 >> 3,&LAB_004a9300);

      FUN_004b07d0(*(uint32_t /* width from decompiler */ *)((int)param_1 + 4));

      FUN_004b07d0(*(int *)((int)param_1 + 4) + 8);

      FUN_004b07d0(*(int *)((int)param_1 + 4) + 0x10);

      iVar7 = 3;

      local_2c = 3;

      pvVar5 = local_18;

      iVar6 = local_14;

      if (1 < local_20 + -2) {

        local_20 = local_20 + -3;

        do {

          iVar4 = iVar7 + -1;

          cVar2 = '\x01';

          if (iVar4 < 1) {

LAB_004ae2f1:

            FUN_007a4480(0,"VOG_DEBUG_STOP");

          }

          else {

            do {

              if (cVar2 == '\0') goto LAB_004ae300;

              cVar3 = FUN_004ab300(*(int *)((int)param_1 + 4) + iVar7 * 8,

                                   iVar4 * 8 + *(int *)((int)param_1 + 4),local_1c);

              if (cVar3 == '\0') {

                iVar1 = iVar7 + -2;

                while ((-1 < iVar1 && (cVar2 != '\0'))) {

                  cVar3 = FUN_004ab300(*(int *)((int)param_1 + 4) + iVar7 * 8,

                                       iVar1 * 8 + *(int *)((int)param_1 + 4),local_1c);

                  if (cVar3 == '\0') {

                    iVar7 = *(int *)((int)param_1 + 4) + iVar7 * 8;

                    if ((pvVar5 == (void *)0x0) ||

                       ((uint)(local_10 - (int)pvVar5 >> 3) <= (uint)(iVar6 - (int)pvVar5 >> 3))) {

                      FUN_004afd00(iVar6,1,iVar7);

                      pvVar5 = local_18;

                    }

                    else {

                      FUN_00567420(iVar6,1,iVar7,local_1c,cVar2);

                      local_14 = iVar6 + 8;

                    }

                    iVar6 = local_14;

                    iVar7 = *(int *)((int)param_1 + 4) + iVar4 * 8;

                    if ((pvVar5 == (void *)0x0) ||

                       ((uint)(local_10 - (int)pvVar5 >> 3) <= (uint)(local_14 - (int)pvVar5 >> 3)))

                    {

                      FUN_004afd00(local_14,1,iVar7);

                      pvVar5 = local_18;

                    }

                    else {

                      FUN_00567420(local_14,1,iVar7,local_1c,cVar2);

                      local_14 = iVar6 + 8;

                    }

                    iVar6 = local_14;

                    iVar7 = *(int *)((int)param_1 + 4) + iVar1 * 8;

                    if ((pvVar5 == (void *)0x0) ||

                       ((uint)(local_10 - (int)pvVar5 >> 3) <= (uint)(local_14 - (int)pvVar5 >> 3)))

                    {

                      FUN_004afd00(local_14,1,iVar7);

                      pvVar5 = local_18;

                    }

                    else {

                      FUN_00567420(local_14,1,iVar7,local_1c,cVar2);

                      local_14 = iVar6 + 8;

                    }

                    local_2c = local_2c + 1;

                    cVar2 = '\0';

                    iVar6 = local_14;

                  }

                  iVar1 = iVar1 + -1;

                  iVar7 = local_2c;

                }

              }

              iVar4 = iVar4 + -1;

            } while (0 < iVar4);

            if (cVar2 != '\0') goto LAB_004ae2f1;

          }

LAB_004ae300:

          local_20 = local_20 + -1;

        } while (local_20 != 0);

      }

      local_28 = 0;

      param_1 = pvVar5;

      while( true ) {

        if (pvVar5 == (void *)0x0) {

          iVar7 = 0;

        }

        else {

          iVar7 = iVar6 - (int)pvVar5 >> 3;

        }

        if (iVar7 <= local_28) break;

        iVar7 = *(int *)(param_2 + 4);

        if ((iVar7 == 0) ||

           ((uint)(*(int *)(param_2 + 0xc) - iVar7 >> 3) <=

            (uint)(*(int *)(param_2 + 8) - iVar7 >> 3))) {

          FUN_004afd00(*(uint32_t /* width from decompiler */ *)(param_2 + 8),1,param_1);

          local_28 = local_28 + 1;

          param_1 = (void *)((int)param_1 + 8);

        }

        else {

          iVar7 = *(int *)(param_2 + 8);

          FUN_00567420(iVar7,1,param_1,param_2,param_1);

          local_28 = local_28 + 1;

          param_1 = (void *)((int)param_1 + 8);

          *(int *)(param_2 + 8) = iVar7 + 8;

        }

      }

      if (pvVar5 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar5);

      }

    }

  }

  ExceptionList = local_c;

  return;

}
