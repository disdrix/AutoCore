// =============================================================================
// FUN_00471d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00471d70
// Address:   0x00471d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00471d70 @ 0x00471d70
// Stable ID: aa_00471d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×11, do×5, while×5, return×4, switch×1.
//  - Notable callees: FUN_00471d70.
//  - Return sites: 4.

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

byte * __thiscall FUN_00471d70(int *param_1,byte *param_2,byte *param_3)



{

  bool bVar1;

  byte bVar2;

  ushort uVar3;

  uint uVar4;

  byte *pbVar5;

  byte bVar6;

  int iVar7;

  uint uVar8;

  uint uVar9;

  uint uVar10;

  int iVar11;

  int local_10 [4];

  

  bVar2 = *(byte *)(param_1 + 2);

  pbVar5 = (byte *)(uint)bVar2;

  if (bVar2 != 3) {

    iVar11 = *param_1;

    bVar1 = false;

    if ((bVar2 & 2) == 0) {

      iVar7 = (uint)*(byte *)((int)param_1 + 9) - (uint)param_3[3];

      uVar4 = 1;

    }

    else {

      uVar4 = (uint)*(byte *)((int)param_1 + 9);

      iVar7 = uVar4 - *param_3;

      local_10[1] = uVar4 - param_3[1];

      local_10[2] = uVar4 - param_3[2];

      uVar4 = 3;

    }

    local_10[0] = iVar7;

    if ((*(byte *)(param_1 + 2) & 4) != 0) {

      local_10[uVar4] = (uint)*(byte *)((int)param_1 + 9) - (uint)param_3[4];

      uVar4 = uVar4 + 1;

    }

    pbVar5 = (byte *)0x0;

    if (uVar4 != 0) {

      do {

        if (local_10[(int)pbVar5] < 1) {

          local_10[(int)pbVar5] = 0;

          iVar7 = local_10[0];

        }

        else {

          bVar1 = true;

        }

        pbVar5 = pbVar5 + 1;

      } while ((int)pbVar5 < (int)uVar4);

      if (bVar1) {

        bVar2 = *(byte *)((int)param_1 + 9);

        pbVar5 = (byte *)(bVar2 - 2);

        if (pbVar5 < (byte *)0xf) {

          pbVar5 = (byte *)(uint)*(byte *)((int)&PTR_caseD_3_00471f38 + bVar2 + 2);

          switch(bVar2) {

          case 2:

            iVar11 = param_1[1];

            pbVar5 = param_2;

            if (iVar11 != 0) {

              do {

                *param_2 = *param_2 >> 1 & 0x55;

                param_2 = param_2 + 1;

                iVar11 = iVar11 + -1;

              } while (iVar11 != 0);

              return param_2;

            }

            break;

          case 4:

            iVar11 = param_1[1];

            bVar6 = (byte)iVar7;

            bVar2 = (byte)(0xf0 >> (bVar6 & 0x1f)) & 0xf0 | (byte)(0xf >> (bVar6 & 0x1f));

            pbVar5 = (byte *)(uint)bVar2;

            if (iVar11 != 0) {

              do {

                iVar11 = iVar11 + -1;

                *param_2 = *param_2 >> (bVar6 & 0x1f) & bVar2;

                param_2 = param_2 + 1;

              } while (iVar11 != 0);

              return (byte *)(uint)bVar2;

            }

            break;

          case 8:

            uVar9 = iVar11 * uVar4;

            uVar10 = 0;

            if (uVar9 != 0) {

              do {

                pbVar5 = (byte *)(uVar10 / uVar4);

                uVar8 = uVar10 % uVar4;

                uVar10 = uVar10 + 1;

                *param_2 = *param_2 >> (*(byte *)(local_10 + uVar8) & 0x1f);

                param_2 = param_2 + 1;

              } while (uVar10 < uVar9);

              return pbVar5;

            }

            break;

          case 0x10:

            uVar9 = iVar11 * uVar4;

            if (uVar9 != 0) {

              uVar10 = 0;

              do {

                uVar8 = uVar10 % uVar4;

                uVar10 = uVar10 + 1;

                uVar3 = (ushort)((ushort)*param_2 * 0x100 + (ushort)param_2[1]) >>

                        ((byte)(short)local_10[uVar8] & 0x1f);

                *param_2 = (byte)(uVar3 >> 8);

                param_2[1] = (byte)uVar3;

                pbVar5 = (byte *)(uint)uVar3;

                param_2 = param_2 + 2;

              } while (uVar10 < uVar9);

            }

          }

        }

      }

    }

  }

  return pbVar5;

}
