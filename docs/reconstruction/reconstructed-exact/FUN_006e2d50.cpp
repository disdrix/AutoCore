// =============================================================================
// FUN_006e2d50
// -----------------------------------------------------------------------------
// Stable ID: aa_006e2d50
// Address:   0x006e2d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e2d50 @ 0x006e2d50
// Stable ID: aa_006e2d50
// Embedded strings (evidence for future rename):
//   - "TtSphereCapsule"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~137 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: ABS×3, SQRT×2, rdtsc×2, FUN_006e2d50, FUN_006f71e0.
//  - Strings: "TtSphereCapsule".
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

void FUN_006e2d50(int *param_1,int *param_2,int param_3,int *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  bool bVar8;

  uint64_t uVar9;

  uint uVar10;

  uint uVar11;

  float *pfVar12;

  float local_80 [4];

  float local_70;

  float local_6c;

  float local_68;

  float local_64;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30 [4];

  int *local_20;

  int *local_1c;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtSphereCapsule";

    uVar9 = rdtsc();

    DAT_00bc5644[1] = (int)uVar9;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar4 = *param_2;

  iVar5 = param_1[2];

  iVar6 = *param_1;

  local_20 = param_1;

  iVar7 = param_2[2];

  local_1c = param_2;

  fVar1 = *(float *)(iVar4 + 0x10);

  fVar2 = *(float *)(iVar4 + 0x14);

  pfVar12 = (float *)(iVar5 + 0x50);

  fVar3 = *(float *)(iVar4 + 0x18);

  local_60 = fVar2 * *(float *)(iVar7 + 0x30) +

             fVar3 * *(float *)(iVar7 + 0x40) + fVar1 * *(float *)(iVar7 + 0x20) +

             *(float *)(iVar7 + 0x50);

  local_5c = fVar2 * *(float *)(iVar7 + 0x34) +

             fVar3 * *(float *)(iVar7 + 0x44) + fVar1 * *(float *)(iVar7 + 0x24) +

             *(float *)(iVar7 + 0x54);

  local_58 = fVar2 * *(float *)(iVar7 + 0x38) +

             fVar3 * *(float *)(iVar7 + 0x48) + fVar1 * *(float *)(iVar7 + 0x28) +

             *(float *)(iVar7 + 0x58);

  local_54 = 0.0;

  fVar1 = *(float *)(iVar4 + 0x20);

  fVar2 = *(float *)(iVar4 + 0x24);

  fVar3 = *(float *)(iVar4 + 0x28);

  local_50 = fVar2 * *(float *)(iVar7 + 0x30) +

             fVar3 * *(float *)(iVar7 + 0x40) + fVar1 * *(float *)(iVar7 + 0x20) +

             *(float *)(iVar7 + 0x50);

  local_4c = fVar2 * *(float *)(iVar7 + 0x34) +

             fVar3 * *(float *)(iVar7 + 0x44) + fVar1 * *(float *)(iVar7 + 0x24) +

             *(float *)(iVar7 + 0x54);

  local_48 = fVar2 * *(float *)(iVar7 + 0x38) +

             fVar3 * *(float *)(iVar7 + 0x48) + fVar1 * *(float *)(iVar7 + 0x28) +

             *(float *)(iVar7 + 0x58);

  local_44 = 0.0;

  FUN_006f71e0(pfVar12,&local_60,&local_50,&local_70);

  local_80[0] = *pfVar12 - local_70;

  local_80[1] = *(float *)(iVar5 + 0x54) - local_6c;

  local_80[2] = *(float *)(iVar5 + 0x58) - local_68;

  local_80[3] = *(float *)(iVar5 + 0x5c) - local_64;

  fVar2 = *(float *)(iVar6 + 0xc) + *(float *)(iVar4 + 0xc);

  fVar3 = fVar2 + *(float *)(param_3 + 8);

  fVar1 = local_80[0] * local_80[0] + local_80[1] * local_80[1] + local_80[2] * local_80[2];

  if (fVar1 < fVar3 * fVar3) {

    if (fVar1 <= g_flZero) {

      local_80[0] = local_50 - local_60;

      local_80[1] = local_4c - local_5c;

      local_80[2] = local_48 - local_58;

      local_80[3] = local_44 - local_54;

      fVar1 = ABS(local_50 - local_60);

      fVar3 = ABS(local_4c - local_5c);

      bVar8 = fVar1 <= fVar3;

      if (!bVar8) {

        fVar1 = fVar3;

      }

      uVar10 = (uint)!bVar8;

      uVar11 = 2;

      if (ABS(local_48 - local_58) < fVar1) {

        uVar10 = 2;

        uVar11 = (uint)!bVar8;

      }

      fVar1 = local_80[bVar8];

      fVar3 = local_80[uVar11];

      local_30[uVar10] = 0.0;

      local_30[bVar8] = fVar3;

      local_30[uVar11] = -fVar1;

      local_34 = g_flZero;

    }

    else {

      local_30[3] = local_80[3];

      local_30[0] = local_80[0];

      local_30[1] = local_80[1];

      local_30[2] = local_80[2];

      local_34 = SQRT(fVar1);

    }

    fVar3 = local_30[0] * local_30[0] + local_30[1] * local_30[1] + local_30[2] * local_30[2];

    fVar1 = g_flZero;

    if (fVar3 != g_flZero) {

      fVar1 = g_flOne / SQRT(fVar3);

    }

    local_30[0] = local_30[0] * fVar1;

    local_30[1] = local_30[1] * fVar1;

    local_30[2] = local_30[2] * fVar1;

    local_30[3] = local_30[3] * fVar1;

    fVar1 = *(float *)(iVar4 + 0xc) - local_34;

    local_40 = local_30[0] * fVar1 + *pfVar12;

    local_3c = local_30[1] * fVar1 + *(float *)(iVar5 + 0x54);

    local_38 = local_30[2] * fVar1 + *(float *)(iVar5 + 0x58);

    local_34 = local_34 - fVar2;

    (**(code **)(*param_4 + 4))(&local_40);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar9 = rdtsc();

    DAT_00bc5644[1] = (int)uVar9;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
