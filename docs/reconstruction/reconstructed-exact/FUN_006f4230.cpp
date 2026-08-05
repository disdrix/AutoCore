// =============================================================================
// FUN_006f4230
// -----------------------------------------------------------------------------
// Stable ID: aa_006f4230
// Address:   0x006f4230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f4230 @ 0x006f4230
// Stable ID: aa_006f4230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_006f4230.
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



void __thiscall FUN_006f4230(int param_1,int param_2,uint *param_3,uint32_t /* width from decompiler */ *param_4)



{

  float fVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  uint uVar7;

  uint uVar8;

  uint uVar9;

  float local_c [3];

  

  if (param_2 != 0) {

    iVar3 = *(int *)(param_1 + 0x34);

    local_c[0] = *(float *)(param_2 + 0x10) - *(float *)(param_2 + 0xc);

    iVar4 = *(int *)(param_2 + 0xb8);

    if (iVar4 == iVar3) {

      local_c[0] = local_c[0] * _DAT_00aaa684;

    }

    fVar1 = g_flZero;

    if (g_flZero < local_c[0]) {

      fVar1 = local_c[0];

    }

    local_c[1] = *(float *)(param_2 + 0x18) - *(float *)(param_2 + 0x14);

    if (iVar4 == iVar3 + 0x20) {

      local_c[1] = local_c[1] * _DAT_00aaa684;

    }

    fVar5 = fVar1;

    if (fVar1 < local_c[1]) {

      fVar5 = local_c[1];

    }

    uVar9 = (uint)(fVar1 < local_c[1]);

    local_c[2] = *(float *)(param_2 + 0x20) - *(float *)(param_2 + 0x1c);

    if (iVar4 == iVar3 + 0x40) {

      local_c[2] = local_c[2] * _DAT_00aaa684;

    }

    if (fVar5 < local_c[2]) {

      uVar9 = 2;

      fVar5 = local_c[2];

    }

    uVar7 = (uVar9 + 1) % 3;

    fVar1 = local_c[uVar7];

    uVar8 = (uVar9 + 2) % 3;

    fVar2 = local_c[uVar8];

    fVar6 = g_flOne / fVar5;

    *param_3 = uVar9;

    *param_4 = 0;

    if (fVar2 <= fVar1) {

      fVar1 = local_c[uVar7];

      param_3[1] = uVar7;

      fVar1 = (fVar5 - fVar1) * fVar6;

      param_4[1] = fVar1 * fVar1 * fVar1 * DAT_00a0f6d0 * DAT_00a10e78;

      param_3[2] = uVar8;

      fVar1 = local_c[uVar8];

    }

    else {

      fVar1 = local_c[uVar8];

      param_3[1] = uVar8;

      fVar1 = (fVar5 - fVar1) * fVar6;

      param_4[1] = fVar1 * fVar1 * fVar1 * DAT_00a0f6d0 * DAT_00a10e78;

      param_3[2] = uVar7;

      fVar1 = local_c[uVar7];

    }

    fVar6 = (fVar5 - fVar1) * fVar6;

    param_4[2] = fVar6 * fVar6 * fVar6 * DAT_00a0f6d0 * DAT_00a10e78;

    return;

  }

  *param_3 = 0;

  param_3[1] = 1;

  param_3[2] = 2;

  *param_4 = 0;

  param_4[1] = 0;

  param_4[2] = 0;

  return;

}
