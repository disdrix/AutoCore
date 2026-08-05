// =============================================================================
// FUN_006c65d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c65d0
// Address:   0x006c65d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c65d0 @ 0x006c65d0
// Stable ID: aa_006c65d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×11, do×4, while×4, return×1.
//  - Notable callees: FUN_006c65d0.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006c65d0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint8_t *puVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  

  puVar4 = param_2;

  *param_1 = &PTR_FUN_009e5fdc;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = *param_2;

  *param_1 = &PTR_FUN_00a0d3c8;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0x80000000;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0x80000000;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0x80000000;

  param_1[3] = param_2[1];

  uVar3 = (int)param_2[3] / 3;

  iVar1 = param_2[2];

  uVar5 = param_1[9] & 0x7fffffff;

  if ((int)uVar5 < (int)uVar3) {

    if ((param_1[9] & 0x80000000) == 0) {

      (**(code **)(*DAT_00b05060 + 0x14))(param_1[7],uVar5 * 0xc,0x12);

    }

    uVar6 = (**(code **)(*DAT_00b05060 + 0x10))(uVar3 * 0xc,0x12);

    param_1[7] = uVar6;

    param_1[9] = uVar3;

  }

  puVar7 = (uint32_t /* width from decompiler */ *)param_1[7];

  param_1[8] = uVar3;

  if (0 < (int)uVar3) {

    iVar10 = iVar1 - (int)puVar7;

    param_2 = (uint32_t /* width from decompiler */ *)uVar3;

    do {

      puVar8 = (uint32_t /* width from decompiler */ *)(iVar10 + (int)puVar7);

      *puVar7 = *puVar8;

      puVar7[1] = puVar8[1];

      puVar7[2] = puVar8[2];

      puVar7 = puVar7 + 3;

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 - 1);

    } while (param_2 != (uint32_t /* width from decompiler */ *)0x0);

  }

  uVar5 = param_1[6] & 0x7fffffff;

  if ((int)uVar5 < (int)puVar4[6]) {

    if (-1 < (int)param_1[6]) {

      (**(code **)(*DAT_00b05060 + 0x14))(param_1[4],uVar5 << 4,0x12);

    }

    uVar6 = (**(code **)(*DAT_00b05060 + 0x10))(puVar4[6] << 4,0x12);

    param_1[4] = uVar6;

    param_1[6] = puVar4[6];

  }

  iVar10 = param_1[4];

  param_1[5] = puVar4[6];

  iVar12 = puVar4[6];

  iVar2 = puVar4[5];

  param_2 = (uint32_t /* width from decompiler */ *)0x0;

  if (3 < iVar12) {

    puVar7 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x1c);

    iVar11 = (iVar12 - 4U >> 2) + 1;

    puVar8 = (uint32_t /* width from decompiler */ *)(iVar10 + 0x14);

    param_2 = (uint32_t /* width from decompiler */ *)(iVar11 * 4);

    do {

      puVar8[-5] = puVar7[-7];

      puVar8[-4] = puVar7[-6];

      puVar8[-3] = puVar7[-5];

      puVar8[-2] = puVar7[-4];

      puVar8[-1] = puVar7[-3];

      *puVar8 = *(uint32_t /* width from decompiler */ *)((int)puVar8 + (iVar2 - iVar10));

      puVar8[1] = puVar7[-1];

      puVar8[2] = *puVar7;

      puVar8[3] = puVar7[1];

      puVar8[4] = puVar7[2];

      puVar8[5] = puVar7[3];

      puVar8[6] = puVar7[4];

      puVar8[7] = puVar7[5];

      puVar8[8] = puVar7[6];

      puVar8[9] = puVar7[7];

      puVar8[10] = puVar7[8];

      puVar7 = puVar7 + 0x10;

      puVar8 = puVar8 + 0x10;

      iVar11 = iVar11 + -1;

    } while (iVar11 != 0);

  }

  if ((int)param_2 < iVar12) {

    puVar7 = (uint32_t /* width from decompiler */ *)((int)param_2 * 0x10 + 0xc + iVar2);

    puVar8 = (uint32_t /* width from decompiler */ *)((int)param_2 * 0x10 + 4 + iVar10);

    iVar12 = iVar12 - (int)param_2;

    do {

      puVar8[-1] = puVar7[-3];

      *puVar8 = *(uint32_t /* width from decompiler */ *)((iVar2 - iVar10) + (int)puVar8);

      puVar8[1] = puVar7[-1];

      puVar8[2] = *puVar7;

      puVar7 = puVar7 + 4;

      puVar8 = puVar8 + 4;

      iVar12 = iVar12 + -1;

    } while (iVar12 != 0);

  }

  uVar5 = param_1[0xc] & 0x7fffffff;

  if ((int)uVar5 < (int)puVar4[9]) {

    if (-1 < (int)param_1[0xc]) {

      (**(code **)(*DAT_00b05060 + 0x14))(param_1[10],uVar5,0x12);

    }

    uVar6 = (**(code **)(*DAT_00b05060 + 0x10))(puVar4[9],0x12);

    param_1[10] = uVar6;

    param_1[0xc] = puVar4[9];

  }

  puVar9 = (uint8_t *)param_1[10];

  param_1[0xb] = puVar4[9];

  iVar10 = puVar4[9];

  if (0 < iVar10) {

    iVar12 = puVar4[8] - (int)puVar9;

    do {

      *puVar9 = puVar9[iVar12];

      puVar9 = puVar9 + 1;

      iVar10 = iVar10 + -1;

    } while (iVar10 != 0);

  }

  if (-1 < (int)(uVar3 | 0x80000000)) {

    (**(code **)(*DAT_00b05060 + 0x14))(iVar1,(uVar3 & 0x7fffffff) * 0xc,0x12);

  }

  return param_1;

}
