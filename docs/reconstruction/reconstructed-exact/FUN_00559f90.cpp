// =============================================================================
// FUN_00559f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00559f90
// Address:   0x00559f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00559f90 @ 0x00559f90
// Stable ID: aa_00559f90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: SQRT×6, FUN_00559f90.
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

void FUN_00559f90(float *param_1,int param_2)



{

  uint uVar1;

  float *pfVar2;

  int iVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float local_34;

  float local_30;

  float local_28;

  float local_24 [4];

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  

  local_24[0] = param_1[2] * DAT_00a0f734 - param_1[1] * DAT_00aaa7b8;

  local_24[1] = *param_1 * DAT_00aaa7b8 - param_1[2] * DAT_00a0f718;

  local_24[2] = param_1[1] * DAT_00a0f718 - *param_1 * DAT_00a0f734;

  local_34 = param_1[1] * local_24[2] - local_24[1] * param_1[2];

  fVar4 = SQRT(local_24[0] * local_24[0] + local_24[1] * local_24[1] + local_24[2] * local_24[2]);

  local_30 = local_24[0] * param_1[2] - *param_1 * local_24[2];

  fVar5 = *param_1 * local_24[1] - param_1[1] * local_24[0];

  if (fVar4 != g_flZero) {

    fVar4 = g_flOne / fVar4;

    local_24[0] = local_24[0] * fVar4;

    local_24[1] = local_24[1] * fVar4;

    local_24[2] = local_24[2] * fVar4;

  }

  fVar4 = SQRT(local_34 * local_34 + local_30 * local_30 + fVar5 * fVar5);

  local_24[3] = local_34;

  local_10 = fVar5;

  if (fVar4 != g_flZero) {

    fVar4 = g_flOne / fVar4;

    local_24[3] = fVar4 * local_34;

    local_30 = local_30 * fVar4;

    local_10 = fVar5 * fVar4;

  }

  fVar4 = param_1[2];

  local_c = *param_1;

  local_14 = local_30;

  fVar6 = fVar4 + local_30 + local_24[0];

  local_8 = param_1[1];

  if (fVar6 < g_flZero) {

    uVar1 = (uint)(local_24[0] < local_30);

    if (local_24[uVar1 * 4] <= fVar4 && fVar4 != local_24[uVar1 * 4]) {

      uVar1 = 2;

    }

    if (uVar1 == 0) {

      fVar4 = SQRT((local_24[0] - (fVar4 + local_30)) + g_flOne);

      local_34 = fVar4 * DAT_00a0f298;

      fVar4 = DAT_00a0f298 / fVar4;

      local_30 = (local_24[1] + local_24[3]) * fVar4;

      fVar5 = (local_c + local_24[2]) * fVar4;

      local_28 = (local_8 - local_10) * fVar4;

    }

    else if (uVar1 == 1) {

      fVar4 = SQRT((local_30 - (fVar4 + local_24[0])) + g_flOne);

      local_30 = fVar4 * DAT_00a0f298;

      fVar4 = DAT_00a0f298 / fVar4;

      fVar5 = (local_8 + local_10) * fVar4;

      local_34 = (local_24[1] + local_24[3]) * fVar4;

      local_28 = (local_24[2] - local_c) * fVar4;

    }

    else if (uVar1 == 2) {

      fVar4 = SQRT((fVar4 - (local_30 + local_24[0])) + g_flOne);

      fVar5 = fVar4 * DAT_00a0f298;

      fVar4 = DAT_00a0f298 / fVar4;

      local_34 = (local_c + local_24[2]) * fVar4;

      local_30 = (local_8 + local_10) * fVar4;

      local_28 = (local_24[3] - local_24[1]) * fVar4;

    }

  }

  else {

    fVar5 = SQRT(fVar6 + g_flOne);

    local_28 = fVar5 * DAT_00a0f298;

    fVar5 = DAT_00a0f298 / fVar5;

    local_34 = (local_8 - local_10) * fVar5;

    local_30 = (local_24[2] - local_c) * fVar5;

    fVar5 = (local_24[3] - local_24[1]) * fVar5;

  }

  iVar3 = *(int *)(param_2 + 4);

  if (iVar3 != *(int *)(param_2 + 8)) {

    pfVar2 = (float *)(iVar3 + 0x14);

    do {

      pfVar2[-2] = local_34;

      pfVar2[-1] = local_30;

      *pfVar2 = fVar5;

      pfVar2[1] = local_28;

      iVar3 = iVar3 + 0x1c;

      pfVar2 = pfVar2 + 7;

    } while (iVar3 != *(int *)(param_2 + 8));

  }

  return;

}
