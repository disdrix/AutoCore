// =============================================================================
// FUN_004b4100
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4100
// Address:   0x004b4100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b4100 @ 0x004b4100
// Stable ID: aa_004b4100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~111 non-empty decompiler lines.
//  - Control keywords: if×11, do×4, while×4, return×2, goto×1.
//  - Notable callees: FUN_004b1a60×2, ROUND×2, FUN_004b4100, floor.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ FUN_004b4100(uint *param_1)



{

  float fVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint *puVar6;

  int iVar7;

  uint *puVar8;

  uint uVar9;

  double dVar10;

  int local_34;

  uint local_30;

  uint *local_2c;

  uint local_28;

  float local_14 [4];

  float local_4;

  

  fVar1 = (float)DAT_00af06e4;

  if (DAT_00af06e4 < 0) {

    fVar1 = fVar1 + _DAT_00aaa5dc;

  }

  uVar2 = (param_1[0x1001] + param_1[0x3003] + param_1[0x2002] + param_1[0x4004] + *param_1) -

          (int)ROUND(fVar1 * DAT_00af06e0);

  if ((int)uVar2 < 1) {

    return 0;

  }

  local_14[0] = g_flOne - DAT_00af06e0;

  local_14[1] = local_14[0] * g_flInferredThreatScale;

  local_14[2] = local_14[0] * DAT_00a0f734;

  local_14[3] = local_14[0] * DAT_00aaa680;

  local_4 = local_14[0] * g_flZero;

  local_34 = 0;

  local_2c = (uint *)0x0;

  puVar8 = param_1;

  local_30 = uVar2;

  do {

    local_28 = uVar2;

    if (*puVar8 <= uVar2) {

      local_28 = *puVar8;

    }

    fVar1 = (float)(int)*puVar8;

    if ((int)*puVar8 < 0) {

      fVar1 = fVar1 + _DAT_00aaa5dc;

    }

    dVar10 = floor((double)(fVar1 / ((float)(int)local_28 * local_14[local_34])));

    uVar5 = (uint)ROUND((float)dVar10);

    if ((int)uVar5 < 1) {

      uVar9 = *puVar8;

    }

    else {

      uVar9 = 0;

    }

    local_28 = *puVar8;

    if (-1 < (int)(local_28 - 1)) {

      puVar6 = param_1 + (int)local_2c + (local_28 - 1) + 1;

      uVar3 = uVar5;

      do {

        if ((int)uVar9 < 1) {

          if (*(uint *)(*(int *)*puVar6 + 0xa28) < 2) {

            uVar3 = uVar3 - 1;

            goto LAB_004b4271;

          }

          local_30 = local_30 - 1;

          uVar4 = uVar5;

          uVar9 = uVar3;

        }

        else {

          uVar9 = uVar9 - 1;

LAB_004b4271:

          uVar4 = *puVar6;

          FUN_004b1a60();

          (**(code **)(uVar4 + 0xc))();

          uVar4 = uVar3;

        }

        puVar6 = puVar6 + -1;

        local_28 = local_28 - 1;

        uVar3 = uVar4;

      } while (local_28 != 0);

    }

    if ((int)local_30 < 1) break;

    local_2c = (uint *)((int)local_2c + 0x1001);

    local_34 = local_34 + 1;

    puVar8 = puVar8 + 0x1001;

  } while ((int)local_2c < 0x5005);

  local_34 = local_34 + 1;

  if (local_34 < 5) {

    iVar7 = local_34 * 0x1001;

    local_2c = param_1 + local_34 * 0x1001;

    do {

      uVar5 = *local_2c;

      if (-1 < (int)(uVar5 - 1)) {

        puVar8 = param_1 + (uVar5 - 1) + iVar7 + 1;

        do {

          uVar9 = *puVar8;

          FUN_004b1a60();

          (**(code **)(uVar9 + 0xc))();

          puVar8 = puVar8 + -1;

          uVar5 = uVar5 - 1;

        } while (uVar5 != 0);

      }

      local_2c = local_2c + 0x1001;

      iVar7 = iVar7 + 0x1001;

    } while (iVar7 < 0x5005);

  }

  iVar7 = DAT_00d17958;

  *(int *)(DAT_00d17958 + 0x140) = *(int *)(DAT_00d17958 + 0x140) + uVar2;

  *(int *)(iVar7 + 0x144) = *(int *)(iVar7 + 0x144) + local_30;

  return 1;

}
