// =============================================================================
// FUN_006e1250
// -----------------------------------------------------------------------------
// Stable ID: aa_006e1250
// Address:   0x006e1250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e1250 @ 0x006e1250
// Stable ID: aa_006e1250
// Embedded strings (evidence for future rename):
//   - "TtSphereBox"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×11, goto×2, return×1.
//  - Notable callees: ABS×3, rdtsc×2, FUN_005d69a0, FUN_006e1250, SQRT.
//  - Strings: "TtSphereBox".
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

void FUN_006e1250(int *param_1,int *param_2,int param_3,int *param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint64_t uVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  int iVar9;

  float local_60;

  float local_5c;

  float local_58;

  float local_50 [4];

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  int *local_20;

  int *local_1c;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtSphereBox";

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar1 = param_1[2];

  local_20 = param_1;

  local_1c = param_2;

  FUN_005d69a0(param_2[2] + 0x20,(float *)(iVar1 + 0x50));

  iVar2 = *param_2;

  fVar6 = ABS(local_50[0]);

  iVar3 = *param_1;

  fVar7 = ABS(local_50[1]);

  fVar8 = ABS(local_50[2]);

  local_60 = fVar6;

  if (*(float *)(iVar2 + 0x10) <= fVar6) {

    local_60 = *(float *)(iVar2 + 0x10);

  }

  local_5c = fVar7;

  if (*(float *)(iVar2 + 0x14) <= fVar7) {

    local_5c = *(float *)(iVar2 + 0x14);

  }

  local_58 = fVar8;

  if (*(float *)(iVar2 + 0x18) <= fVar8) {

    local_58 = *(float *)(iVar2 + 0x18);

  }

  local_60 = local_60 - fVar6;

  local_5c = local_5c - fVar7;

  local_58 = local_58 - fVar8;

  if ((g_flZero <= local_58 && g_flZero <= local_5c) && g_flZero <= local_60) {

    iVar2 = *param_2;

    fVar6 = fVar6 - *(float *)(iVar2 + 0x10);

    fVar7 = fVar7 - *(float *)(iVar2 + 0x14);

    fVar8 = fVar8 - *(float *)(iVar2 + 0x18);

    if (fVar6 <= fVar7) {

      if (fVar7 <= fVar8) goto LAB_006e1579;

      iVar9 = param_2[2];

      local_30 = *(float *)(iVar9 + 0x30);

      local_2c = *(float *)(iVar9 + 0x34);

      local_28 = *(float *)(iVar9 + 0x38);

      local_24 = *(float *)(iVar9 + 0x3c);

      iVar9 = 1;

    }

    else if (fVar6 <= fVar8) {

LAB_006e1579:

      iVar9 = param_2[2];

      local_30 = *(float *)(iVar9 + 0x40);

      local_2c = *(float *)(iVar9 + 0x44);

      local_28 = *(float *)(iVar9 + 0x48);

      local_24 = *(float *)(iVar9 + 0x4c);

      iVar9 = 2;

      fVar7 = fVar8;

    }

    else {

      iVar4 = param_2[2];

      local_30 = *(float *)(iVar4 + 0x20);

      iVar9 = 0;

      local_2c = *(float *)(iVar4 + 0x24);

      local_28 = *(float *)(iVar4 + 0x28);

      local_24 = *(float *)(iVar4 + 0x2c);

      fVar7 = fVar6;

    }

    if (local_50[iVar9] < g_flZero) {

      local_30 = -local_30;

      local_2c = -local_2c;

      local_28 = -local_28;

      local_24 = -local_24;

    }

    local_34 = (fVar7 - *(float *)(iVar2 + 0xc)) - *(float *)(iVar3 + 0xc);

  }

  else {

    local_34 = SQRT(local_60 * local_60 + local_5c * local_5c + local_58 * local_58);

    fVar6 = g_flOne / local_34;

    local_34 = local_34 - (*(float *)(*param_2 + 0xc) + *(float *)(iVar3 + 0xc));

    if (*(float *)(param_3 + 8) < local_34) goto LAB_006e163f;

    fVar7 = -(float)((uint)(local_60 * fVar6) ^ (uint)local_50[0] & 0x80000000);

    fVar8 = -(float)((uint)(local_5c * fVar6) ^ (uint)local_50[1] & 0x80000000);

    iVar2 = param_2[2];

    fVar6 = -(float)((uint)(local_58 * fVar6) ^ (uint)local_50[2] & 0x80000000);

    local_30 = fVar7 * *(float *)(iVar2 + 0x20) +

               fVar8 * *(float *)(iVar2 + 0x30) + fVar6 * *(float *)(iVar2 + 0x40);

    local_2c = fVar7 * *(float *)(iVar2 + 0x24) +

               fVar8 * *(float *)(iVar2 + 0x34) + fVar6 * *(float *)(iVar2 + 0x44);

    local_24 = 0.0;

    local_28 = fVar7 * *(float *)(iVar2 + 0x28) +

               fVar8 * *(float *)(iVar2 + 0x38) + fVar6 * *(float *)(iVar2 + 0x48);

  }

  fVar6 = -local_34 - *(float *)(iVar3 + 0xc);

  local_40 = local_30 * fVar6 + *(float *)(iVar1 + 0x50);

  local_3c = local_2c * fVar6 + *(float *)(iVar1 + 0x54);

  local_38 = local_28 * fVar6 + *(float *)(iVar1 + 0x58);

  (**(code **)(*param_4 + 4))(&local_40);

LAB_006e163f:

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
