// =============================================================================
// FUN_007b4730
// -----------------------------------------------------------------------------
// Stable ID: aa_007b4730
// Address:   0x007b4730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b4730 @ 0x007b4730
// Stable ID: aa_007b4730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~166 non-empty decompiler lines.
//  - Control keywords: if×18, do×2, while×2, goto×1, return×1.
//  - Notable callees: CONCAT13, FUN_00403450, FUN_0040aeb0, FUN_00755890, FUN_00755a50, FUN_00758460, FUN_00759730, FUN_007b4730.
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

void FUN_007b4730(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,byte param_4,byte *param_5,int param_6,

                 int *param_7,uint param_8,uint param_9)



{

  byte bVar1;

  byte bVar2;

  ushort uVar3;

  char cVar4;

  int iVar5;

  int *piVar6;

  uint uVar7;

  int iVar8;

  int *extraout_ECX;

  int *piVar9;

  bool bVar10;

  int *local_ec;

  uint8_t *puStack_e8;

  uint uStack_e4;

  uint32_t /* width from decompiler */ uStack_e0;

  uint32_t /* width from decompiler */ uStack_dc;

  int *piStack_d8;

  uint32_t /* width from decompiler */ uStack_d4;

  uint32_t /* width from decompiler */ local_bc;

  int local_b8;

  int local_b4;

  int *local_b0;

  int local_ac;

  int local_a8;

  uint8_t *local_a4;

  int local_a0;

  int local_9c;

  uint8_t *local_90;

  uint8_t local_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b2902;

  local_c = ExceptionList;

  local_a8 = *(int *)(param_1 + 0x84);

  local_b0 = *(int **)(param_6 + 0x84);

  local_b4 = -1;

  local_ac = -99999;

  local_b8 = 0;

  if (local_b0 != *(int **)(param_6 + 0x88)) {

    piVar9 = local_b0 + 4;

    ExceptionList = &local_c;

    do {

      iVar5 = piVar9[-3];

      if (iVar5 == local_ac) {

LAB_007b47c3:

        bVar10 = param_2 == local_b4;

      }

      else {

        local_b4 = local_b4 + 1;

        bVar10 = false;

        local_ac = iVar5;

        if (param_2 == local_b4) {

          local_b8 = -iVar5;

          goto LAB_007b47c3;

        }

      }

      if (bVar10 || param_2 < local_b4) {

        uVar7 = piVar9[7];

        if (param_5 != (byte *)0x0) {

          bVar1 = param_5[3];

          bVar2 = *param_5;

          local_a4 = (uint8_t *)(((uint)param_5[1] * (uVar7 >> 8 & 0xff)) / 0xff);

          *(char *)((int)piVar9 + 0x1e) = (char)(((uint)param_5[2] * (uVar7 >> 0x10 & 0xff)) / 0xff)

          ;

          *(uint8_t *)((int)piVar9 + 0x1d) = local_a4._0_1_;

          *(char *)(piVar9 + 7) = (char)(((uint)bVar2 * (uVar7 & 0xff)) / 0xff);

          *(char *)((int)piVar9 + 0x1f) = (char)(((uint)bVar1 * (uVar7 >> 0x18)) / 0xff);

        }

        cVar4 = (char)(((uVar7 >> 0x18) * (uint)param_4) / 0xff);

        local_bc = CONCAT13(cVar4,(int3)uVar7);

        if (cVar4 != '\0') {

          if (piVar9[4] == 0) {

            if (((uint8_t *)piVar9[8] != (uint8_t *)0x0) &&

               ((local_b4 < 1 || (piVar9[10] + piVar9[-3] + local_b8 <= local_a8)))) {

              iVar8 = piVar9[0xb] + *param_7 + *local_b0;

              iVar5 = piVar9[0xc] + param_7[1] + piVar9[-3] + local_b8;

              uStack_d4 = 0;

              piStack_d8 = piVar9 + 0xd;

              uStack_dc = 1;

              uStack_e0 = local_bc;

              uStack_e4 = 0;

              local_ec = (int *)(float)(piVar9[10] + iVar5);

              puStack_e8 = (uint8_t *)piVar9[8];

              FUN_00758460((float)iVar8,(float)iVar5,(float)(piVar9[9] + iVar8));

            }

          }

          else if (((int *)piVar9[6] != (int *)0x0) &&

                  ((local_b4 < 1 ||

                   (*(int *)(*(int *)piVar9[6] + 0x7c) + piVar9[-3] + local_b8 <= local_a8)))) {

            if ((param_8 == 0) || (param_8 <= (uint)piVar9[4])) {

              local_9c = param_7[1] + piVar9[-3] + local_b8;

              local_a0 = *param_7 + *local_b0;

              uStack_d4 = param_3;

              piStack_d8 = (int *)0x1;

              uStack_dc = 0;

              uStack_e0 = 0;

              uStack_e4 = param_9;

              piVar6 = piVar9;

              if (7 < (uint)piVar9[5]) {

                piVar6 = (int *)*piVar9;

              }

              local_90 = local_8c;

              puStack_e8 = (uint8_t *)0x7b4a15;

              puStack_e8 = (uint8_t *)(*(code *)PTR_FUN_00af8c9c)();

              local_ec = piVar6;

              FUN_00403450();

              uStack_4 = 0;

              puStack_e8 = local_90 + param_8;

              local_a4 = (uint8_t *)&local_ec;

              local_ec = extraout_ECX;

              FUN_0040aeb0(&local_ec);

              FUN_00759730(param_1,&local_a0,&local_bc);

              uStack_4 = 0xffffffff;

              if (local_90 != local_8c) {

                uStack_d4 = 0x7b4a77;

                free(local_90);

              }

              if (param_9 != 0xffffffff) {

                uVar7 = piVar9[4] - param_8;

                if (param_9 <= piVar9[4] - param_8) {

                  uVar7 = param_9;

                }

                param_9 = param_9 - uVar7;

              }

              if (param_8 != 0) {

                iVar5 = 0;

                if (0 < (int)param_8) {

                  do {

                    piVar6 = piVar9;

                    if (7 < (uint)piVar9[5]) {

                      piVar6 = (int *)*piVar9;

                    }

                    uVar3 = *(ushort *)((int)piVar6 + iVar5 * 2);

                    if ((*(ushort *)(*(int *)piVar9[6] + 0x88) <= uVar3) &&

                       (uVar3 <= *(ushort *)(*(int *)piVar9[6] + 0x8a))) {

                      uStack_d4 = 0x7b4ace;

                      iVar8 = FUN_00755890();

                      *param_7 = *param_7 - *(int *)(iVar8 + 0x18);

                    }

                    iVar5 = iVar5 + 1;

                  } while (iVar5 < (int)param_8);

                }

                param_8 = 0;

              }

            }

            else {

              uStack_d4 = 0x7b49a4;

              piVar6 = (int *)FUN_00755a50();

              *param_7 = *param_7 - *piVar6;

              param_8 = param_8 - piVar9[4];

            }

          }

        }

      }

      local_b0 = local_b0 + 0x20;

      piVar9 = piVar9 + 0x20;

    } while (local_b0 != *(int **)(param_6 + 0x88));

  }

  ExceptionList = local_c;

  return;

}
