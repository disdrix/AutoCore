// =============================================================================
// FUN_006bc6d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006bc6d0
// Address:   0x006bc6d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bc6d0 @ 0x006bc6d0
// Stable ID: aa_006bc6d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×16, while×4, do×3, goto×2, return×2.
//  - Notable callees: FUN_005b3370×2, FUN_006bc6d0.
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

void FUN_006bc6d0(float *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int *param_4,int *param_5)



{

  short *psVar1;

  short *psVar2;

  float fVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint uVar7;

  float local_1c;

  int local_18;

  

  puVar4 = param_2;

  if (param_3[1] == 0) {

    local_1c = *(float *)(*param_4 + 4);

  }

  else if (param_4[1] == 0) {

    local_1c = *(float *)(*param_3 + 4);

  }

  else {

    local_1c = *(float *)(*param_4 + 4);

    if (*(float *)(*param_3 + 4) < local_1c) {

      local_1c = *(float *)(*param_3 + 4);

    }

  }

  psVar1 = (short *)param_2[1];

  local_18 = 0;

  if (0 < param_3[1]) {

    do {

      fVar3 = *(float *)(*param_3 + 4 + local_18 * 8) - local_1c;

      if (*param_1 < fVar3) break;

      psVar2 = *(short **)(*param_3 + local_18 * 8);

      fVar3 = fVar3 + (float)param_2[4];

      uVar7 = (uint)*(ushort *)*param_2;

      if (0 < param_5[1]) {

        puVar5 = (uint32_t /* width from decompiler */ *)*param_5;

        iVar6 = 0;

        do {

          if (((*(short *)*puVar5 == *psVar2) && (*(short *)puVar5[1] == *psVar1)) &&

             (puVar5[3] == uVar7)) {

            puVar5 = (uint32_t /* width from decompiler */ *)(*param_5 + iVar6 * 0x14);

            if (*(float *)(*param_5 + 0x10 + iVar6 * 0x14) < fVar3) {

              *puVar5 = psVar2;

              puVar5[1] = psVar1;

              puVar5[2] = param_2;

              puVar5[3] = uVar7;

              puVar5[4] = fVar3;

            }

            goto LAB_006bc805;

          }

          iVar6 = iVar6 + 1;

          puVar5 = puVar5 + 5;

        } while (iVar6 < param_5[1]);

      }

      if (param_5[1] == (param_5[2] & 0x7fffffffU)) {

        FUN_005b3370(param_5,0x14);

      }

      puVar5 = (uint32_t /* width from decompiler */ *)(*param_5 + param_5[1] * 0x14);

      *puVar5 = psVar2;

      puVar5[1] = psVar1;

      puVar5[2] = param_2;

      puVar5[3] = uVar7;

      puVar5[4] = fVar3;

      param_5[1] = param_5[1] + 1;

LAB_006bc805:

      local_18 = local_18 + 1;

    } while (local_18 < param_3[1]);

  }

  psVar1 = (short *)*param_2;

  param_2 = (uint32_t /* width from decompiler */ *)0x0;

  if (0 < param_4[1]) {

    while( true ) {

      fVar3 = *(float *)(*param_4 + 4 + (int)param_2 * 8) - local_1c;

      if (*param_1 < fVar3) break;

      fVar3 = fVar3 + (float)puVar4[4];

      psVar2 = *(short **)(*param_4 + (int)param_2 * 8);

      uVar7 = (uint)*(ushort *)puVar4[1];

      iVar6 = 0;

      if (0 < param_5[1]) {

        puVar5 = (uint32_t /* width from decompiler */ *)*param_5;

        do {

          if (((*(short *)*puVar5 == *psVar1) && (*(short *)puVar5[1] == *psVar2)) &&

             (puVar5[3] == uVar7)) {

            puVar5 = (uint32_t /* width from decompiler */ *)(*param_5 + iVar6 * 0x14);

            if (*(float *)(*param_5 + 0x10 + iVar6 * 0x14) < fVar3) {

              *puVar5 = psVar1;

              puVar5[1] = psVar2;

              puVar5[2] = puVar4;

              puVar5[3] = uVar7;

              puVar5[4] = fVar3;

            }

            goto LAB_006bc8f4;

          }

          iVar6 = iVar6 + 1;

          puVar5 = puVar5 + 5;

        } while (iVar6 < param_5[1]);

      }

      if (param_5[1] == (param_5[2] & 0x7fffffffU)) {

        FUN_005b3370(param_5,0x14);

      }

      puVar5 = (uint32_t /* width from decompiler */ *)(*param_5 + param_5[1] * 0x14);

      *puVar5 = psVar1;

      puVar5[1] = psVar2;

      puVar5[2] = puVar4;

      puVar5[3] = uVar7;

      puVar5[4] = fVar3;

      param_5[1] = param_5[1] + 1;

LAB_006bc8f4:

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

      if (param_4[1] <= (int)param_2) {

        return;

      }

    }

  }

  return;

}
