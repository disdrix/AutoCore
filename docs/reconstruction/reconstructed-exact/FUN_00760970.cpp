// =============================================================================
// FUN_00760970
// -----------------------------------------------------------------------------
// Stable ID: aa_00760970
// Address:   0x00760970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00760970 @ 0x00760970
// Stable ID: aa_00760970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×14, while×3, for×2, goto×2, do×1, return×1.
//  - Notable callees: FUN_00456960×2, FUN_00760830, FUN_00760970, block.
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

/* WARNING: Removing unreachable block (ram,0x00760c1a) */



uint32_t /* width from decompiler */ * __thiscall FUN_00760970(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint uVar7;

  int iVar8;

  int *piVar9;

  int *piVar10;

  uint32_t /* width from decompiler */ *local_28;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0a20;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_28 = operator_new(0x20);

  if (local_28 == (uint32_t /* width from decompiler */ *)0x0) {

    local_28 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_28[1] = param_2;

    uVar5 = DAT_00aaa688;

    *local_28 = &PTR_FUN_00a9dcf4;

    local_28[3] = 0;

    local_28[4] = 0;

    local_28[5] = 0;

    local_28[6] = 0;

    local_28[7] = uVar5;

  }

  local_4 = 0xffffffff;

  local_28[7] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  if (*(int *)(param_1 + 0xc) == 0) {

    iVar6 = 0;

  }

  else {

    iVar6 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28;

  }

  FUN_00760830(iVar6);

  iVar6 = *(int *)(param_1 + 0xc);

  iVar1 = *(int *)(param_1 + 0x10);

  if (iVar6 != iVar1) {

    piVar9 = (int *)(local_28[3] + 0x14);

    do {

      piVar9[3] = *(int *)(iVar6 + 0x20);

      piVar9[4] = *(int *)(iVar6 + 0x24);

      piVar2 = *(int **)(iVar6 + 8);

      for (piVar10 = *(int **)(iVar6 + 4); piVar10 != piVar2; piVar10 = piVar10 + 1) {

        iVar8 = *(int *)(*(int *)(param_1 + 4) + 0xc0);

        uVar7 = 0;

        while( true ) {

          if ((iVar8 == 0) || ((uint)(*(int *)(*(int *)(param_1 + 4) + 0xc4) - iVar8 >> 2) <= uVar7)

             ) goto LAB_00760ade;

          if (*(int *)(iVar8 + uVar7 * 4) == *piVar10) break;

          uVar7 = uVar7 + 1;

        }

        if ((uVar7 != 0xffffffff) &&

           (iVar8 = *(int *)(*(int *)(param_2 + 0xc0) + uVar7 * 4), iVar8 != 0)) {

          iVar3 = piVar9[-4];

          if ((iVar3 == 0) || ((uint)(piVar9[-2] - iVar3 >> 2) <= (uint)(piVar9[-3] - iVar3 >> 2)))

          {

            FUN_00456960(piVar9[-3]);

          }

          else {

            piVar4 = (int *)piVar9[-3];

            *piVar4 = iVar8;

            piVar9[-3] = (int)(piVar4 + 1);

          }

        }

LAB_00760ade:

      }

      piVar2 = *(int **)(iVar6 + 0x18);

      for (piVar10 = *(int **)(iVar6 + 0x14); piVar10 != piVar2; piVar10 = piVar10 + 1) {

        iVar8 = *(int *)(*(int *)(param_1 + 4) + 0xd0);

        uVar7 = 0;

        while( true ) {

          if ((iVar8 == 0) || ((uint)(*(int *)(*(int *)(param_1 + 4) + 0xd4) - iVar8 >> 2) <= uVar7)

             ) goto LAB_00760bc3;

          if (*(int *)(iVar8 + uVar7 * 4) == *piVar10) break;

          uVar7 = uVar7 + 1;

        }

        if (uVar7 != 0xffffffff) {

          if ((*(int *)(param_2 + 0xd0) == 0) ||

             (*(int *)(param_2 + 0xd4) - *(int *)(param_2 + 0xd0) >> 2 == 0)) {

            iVar8 = 0;

          }

          else {

            iVar8 = *(int *)(*(int *)(param_2 + 0xd0) + uVar7 * 4);

          }

          if (iVar8 != 0) {

            iVar3 = *piVar9;

            if ((iVar3 == 0) || ((uint)(piVar9[2] - iVar3 >> 2) <= (uint)(piVar9[1] - iVar3 >> 2)))

            {

              FUN_00456960(piVar9[1]);

            }

            else {

              piVar4 = (int *)piVar9[1];

              *piVar4 = iVar8;

              piVar9[1] = (int)(piVar4 + 1);

            }

          }

        }

LAB_00760bc3:

      }

      iVar6 = iVar6 + 0x28;

      piVar9 = piVar9 + 10;

    } while (iVar6 != iVar1);

  }

  if (local_28[3] == 0) {

    iVar6 = 0;

  }

  else {

    iVar6 = (int)(local_28[4] - local_28[3]) / 0x28;

  }

  local_28[6] = iVar6 + -1;

  ExceptionList = local_c;

  return local_28;

}
