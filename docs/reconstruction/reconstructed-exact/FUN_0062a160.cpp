// =============================================================================
// FUN_0062a160
// -----------------------------------------------------------------------------
// Stable ID: aa_0062a160
// Address:   0x0062a160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062a160 @ 0x0062a160
// Stable ID: aa_0062a160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×16, do×5, while×5, goto×1, return×1.
//  - Notable callees: FUN_005b3300×3, FUN_0062a160.
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

void __thiscall FUN_0062a160(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int iVar3;

  uint8_t *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iStack_38;

  uint8_t *local_34;

  int local_30;

  int local_2c;

  uint8_t local_28 [40];

  

  piVar2 = param_2;

  param_2[1] = 0;

  puVar4 = local_28;

  local_30 = 0;

  local_2c = -0x7ffffff6;

  param_2 = (int *)0x0;

  local_34 = puVar4;

  if (0 < *(int *)(param_1 + 0x50)) {

    do {

      iVar7 = 0;

      local_30 = 0;

      (**(code **)(**(int **)(*(int *)(param_1 + 0x4c) + (int)param_2 * 4) + 0x18))(&local_34);

      iVar5 = -1;

      do {

        puVar4 = local_34;

        if (local_30 <= iVar7) goto LAB_0062a248;

        if (*(char *)(*(int *)(local_34 + iVar7 * 4) + 0x40) == '\0') {

          iVar5 = iVar7;

        }

        iVar7 = iVar7 + 1;

      } while (iVar5 == -1);

      iVar6 = local_30;

      if (iVar7 < local_30) {

        do {

          if (*(char *)(*(int *)(puVar4 + iVar7 * 4) + 0x40) == '\0') {

            iVar6 = piVar2[1] + 1;

            if ((int)(piVar2[2] & 0x7fffffffU) < iVar6) {

              iVar3 = (piVar2[2] & 0x7fffffffU) * 2;

              if (iVar3 <= iVar6) {

                iVar3 = iVar6;

              }

              FUN_005b3300(piVar2,iVar3,8);

              puVar4 = local_34;

            }

            piVar2[1] = iVar6;

            puVar1 = (uint32_t /* width from decompiler */ *)(*piVar2 + -8 + iVar6 * 8);

            *puVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(puVar4 + iVar5 * 4) + 0x58);

            puVar1[1] = *(uint32_t /* width from decompiler */ *)(*(int *)(local_34 + iVar7 * 4) + 0x58);

            iVar6 = local_30;

            puVar4 = local_34;

          }

          iVar7 = iVar7 + 1;

        } while (iVar7 < iVar6);

      }

LAB_0062a248:

      param_2 = (int *)((int)param_2 + 1);

    } while ((int)param_2 < *(int *)(param_1 + 0x50));

  }

  if (-1 < local_2c) {

    (**(code **)(*DAT_00b05060 + 0x14))(puVar4,local_2c * 4,0x12);

  }

  iVar5 = 0;

  if (0 < *(int *)(param_1 + 0x5c)) {

    do {

      iVar7 = *(int *)(*(int *)(param_1 + 0x58) + iVar5 * 4);

      if ((*(char *)(*(int *)(iVar7 + 0xc) + 0x40) == '\0') &&

         (*(char *)(*(int *)(iVar7 + 0x10) + 0x40) == '\0')) {

        iVar7 = piVar2[1] + 1;

        if ((int)(piVar2[2] & 0x7fffffffU) < iVar7) {

          iVar6 = (piVar2[2] & 0x7fffffffU) * 2;

          if (iVar6 <= iVar7) {

            iVar6 = iVar7;

          }

          FUN_005b3300(piVar2,iVar6,8);

        }

        piVar2[1] = iVar7;

        puVar1 = (uint32_t /* width from decompiler */ *)(*piVar2 + -8 + iVar7 * 8);

        *puVar1 = *(uint32_t /* width from decompiler */ *)

                   (*(int *)(*(int *)(*(int *)(param_1 + 0x58) + iVar5 * 4) + 0xc) + 0x58);

        puVar1[1] = *(uint32_t /* width from decompiler */ *)

                     (*(int *)(*(int *)(*(int *)(param_1 + 0x58) + iVar5 * 4) + 0x10) + 0x58);

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(param_1 + 0x5c));

  }

  param_2 = (int *)0x0;

  if (0 < *(int *)(param_1 + 0x6c)) {

    iStack_38 = 0;

    do {

      iVar5 = *(int *)(*(int *)(iStack_38 + *(int *)(param_1 + 0x68)) + 0x10);

      iVar7 = *(int *)(*(int *)(iStack_38 + *(int *)(param_1 + 0x68) + 4) + 0x10);

      if ((*(char *)(iVar5 + 0x40) == '\0') && (*(char *)(iVar7 + 0x40) == '\0')) {

        iVar6 = piVar2[1] + 1;

        if ((int)(piVar2[2] & 0x7fffffffU) < iVar6) {

          iVar3 = (piVar2[2] & 0x7fffffffU) * 2;

          if (iVar3 <= iVar6) {

            iVar3 = iVar6;

          }

          FUN_005b3300(piVar2,iVar3,8);

        }

        piVar2[1] = iVar6;

        puVar1 = (uint32_t /* width from decompiler */ *)(*piVar2 + -8 + iVar6 * 8);

        *puVar1 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x58);

        puVar1[1] = *(uint32_t /* width from decompiler */ *)(iVar7 + 0x58);

      }

      param_2 = (int *)((int)param_2 + 1);

      iStack_38 = iStack_38 + 0x10;

    } while ((int)param_2 < *(int *)(param_1 + 0x6c));

  }

  return;

}
