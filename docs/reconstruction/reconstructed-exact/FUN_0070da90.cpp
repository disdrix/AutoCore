// =============================================================================
// FUN_0070da90
// -----------------------------------------------------------------------------
// Stable ID: aa_0070da90
// Address:   0x0070da90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0070da90 @ 0x0070da90
// Stable ID: aa_0070da90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×11, do×5, while×5, for×2, return×2.
//  - Notable callees: FUN_00702bb0×4, FUN_0070c8f0, FUN_0070cea0, FUN_0070da90.
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

int FUN_0070da90(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ *param_6,int param_7,int param_8,int param_9,

                uint32_t /* width from decompiler */ param_10,uint32_t /* width from decompiler */ param_11,int param_12,uint32_t /* width from decompiler */ param_13,

                int param_14,uint32_t /* width from decompiler */ param_15,uint32_t /* width from decompiler */ param_16,int param_17,

                uint32_t /* width from decompiler */ param_18)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float10 fVar9;

  float local_1c;

  int local_18;

  int local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_4;

  

  local_18 = 0;

  local_c = 0;

  local_10 = 0;

  local_1c = -1.0;

  if (10 < param_17) {

    param_17 = 10;

  }

  param_14 = param_14 + (-param_14 & 3U) + param_17 * 4;

  iVar6 = param_14 + (-param_14 & 3U) + param_17 * 4;

  iVar4 = param_14 + param_17 * -4;

  iVar5 = param_17 * -4;

  if ((param_17 != 0) && (param_8 <= param_9)) {

    iVar7 = iVar6 + (-iVar6 & 3U) + param_12 * 4;

    iVar8 = iVar7 + param_12 * -4;

    iVar1 = (param_9 - param_8) + 1;

    if (iVar1 < param_17) {

      param_17 = iVar1;

    }

    FUN_0070c8f0(param_2,param_8,param_9,param_12,iVar4,iVar6 + iVar5,param_17,iVar7);

    param_14 = 0;

    if (0 < param_17) {

      do {

        local_18 = *(int *)(iVar4 + param_14 * 4);

        iVar5 = param_12;

        puVar2 = param_6;

        if (0 < param_12) {

          for (; iVar5 != 0; iVar5 = iVar5 + -1) {

            *puVar2 = 0;

            puVar2 = puVar2 + 1;

          }

        }

        fVar9 = (float10)FUN_0070cea0(param_1,param_3,param_4,param_5,param_6,local_18,param_11,

                                      iVar7,param_15,param_16,&local_4,param_18);

        if ((fVar9 < (float10)local_1c) || (local_1c < g_flZero)) {

          iVar5 = 0;

          if (3 < param_12) {

            iVar6 = (param_12 - 4U >> 2) + 1;

            puVar2 = (uint32_t /* width from decompiler */ *)(iVar8 + 4);

            iVar5 = iVar6 * 4;

            puVar3 = param_6 + 3;

            do {

              puVar2[-1] = puVar3[-3];

              *puVar2 = *(uint32_t /* width from decompiler */ *)(((int)param_6 - iVar8) + (int)puVar2);

              puVar2[1] = puVar3[-1];

              puVar2[2] = *puVar3;

              puVar2 = puVar2 + 4;

              puVar3 = puVar3 + 4;

              iVar6 = iVar6 + -1;

            } while (iVar6 != 0);

          }

          if (iVar5 < param_12) {

            puVar2 = (uint32_t /* width from decompiler */ *)(iVar8 + iVar5 * 4);

            iVar5 = param_12 - iVar5;

            do {

              *puVar2 = *(uint32_t /* width from decompiler */ *)((int)puVar2 + ((int)param_6 - iVar8));

              puVar2 = puVar2 + 1;

              iVar5 = iVar5 + -1;

            } while (iVar5 != 0);

          }

          local_1c = (float)fVar9;

          local_c = local_4;

          local_10 = local_18;

        }

        param_14 = param_14 + 1;

      } while (param_14 < param_17);

    }

    FUN_00702bb0(param_13,local_10 - param_8,*(uint32_t /* width from decompiler */ *)(param_7 + 8));

    FUN_00702bb0(param_13,local_c,*(uint32_t /* width from decompiler */ *)(param_7 + 4));

    iVar5 = 0;

    if (3 < param_12) {

      iVar4 = (param_12 - 4U >> 2) + 1;

      iVar5 = iVar4 * 4;

      puVar2 = (uint32_t /* width from decompiler */ *)(iVar8 + 0xc);

      puVar3 = param_6 + 1;

      do {

        puVar3[-1] = puVar2[-3];

        *puVar3 = *(uint32_t /* width from decompiler */ *)((int)puVar3 + (iVar8 - (int)param_6));

        puVar3[1] = puVar2[-1];

        puVar3[2] = *puVar2;

        puVar3 = puVar3 + 4;

        puVar2 = puVar2 + 4;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

    }

    if (iVar5 < param_12) {

      puVar2 = param_6 + iVar5;

      param_12 = param_12 - iVar5;

      do {

        *puVar2 = *(uint32_t /* width from decompiler */ *)((int)puVar2 + (iVar8 - (int)param_6));

        puVar2 = puVar2 + 1;

        param_12 = param_12 + -1;

      } while (param_12 != 0);

    }

    return local_18;

  }

  FUN_00702bb0(param_13,0,*(uint32_t /* width from decompiler */ *)(param_7 + 8));

  FUN_00702bb0(param_13,0,*(uint32_t /* width from decompiler */ *)(param_7 + 4));

  if (0 < param_12) {

    for (; param_12 != 0; param_12 = param_12 + -1) {

      *param_6 = 0;

      param_6 = param_6 + 1;

    }

  }

  return param_8;

}
