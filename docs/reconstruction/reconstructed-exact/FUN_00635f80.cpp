// =============================================================================
// FUN_00635f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00635f80
// Address:   0x00635f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00635f80 @ 0x00635f80
// Stable ID: aa_00635f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_00635f80.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00635f80(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  

  param_1[2] = param_2;

  *param_1 = &PTR_FUN_009e39f0;

  *(uint16_t *)((int)param_1 + 6) = 1;

  iVar8 = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0x80000000;

  *(short *)(param_1[2] + 6) = *(short *)(param_1[2] + 6) + 1;

  uVar3 = param_1[5] & 0x7fffffff;

  if ((int)uVar3 < param_3[1]) {

    if (-1 < (int)param_1[5]) {

      (**(code **)(*DAT_00b05060 + 0x14))(param_1[3],uVar3 << 5,0x12);

    }

    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(param_3[1] << 5,0x12);

    param_1[3] = uVar4;

    param_1[5] = param_3[1];

  }

  iVar1 = param_1[3];

  param_1[4] = param_3[1];

  iVar9 = param_3[1];

  iVar2 = *param_3;

  if (3 < iVar9) {

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    iVar7 = (iVar9 - 4U >> 2) + 1;

    iVar8 = iVar7 * 4;

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x3c);

    do {

      puVar5[-0xd] = puVar6[-0xf];

      puVar5[-0xc] = puVar6[-0xe];

      puVar5[-0xb] = puVar6[-0xd];

      puVar5[-10] = puVar6[-0xc];

      puVar5[-9] = puVar6[-0xb];

      puVar5[-8] = puVar6[-10];

      puVar5[-7] = puVar6[-9];

      puVar5[-6] = puVar6[-8];

      puVar5[-5] = puVar6[-7];

      puVar5[-4] = puVar6[-6];

      puVar5[-3] = puVar6[-5];

      puVar5[-2] = puVar6[-4];

      puVar5[-1] = puVar6[-3];

      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar2 - iVar1));

      puVar5[1] = puVar6[-1];

      puVar5[2] = *puVar6;

      puVar5[3] = puVar6[1];

      puVar5[4] = puVar6[2];

      puVar5[5] = puVar6[3];

      puVar5[6] = puVar6[4];

      puVar5[7] = puVar6[5];

      puVar5[8] = puVar6[6];

      puVar5[9] = puVar6[7];

      puVar5[10] = puVar6[8];

      puVar5[0xb] = puVar6[9];

      puVar5[0xc] = puVar6[10];

      puVar5[0xd] = puVar6[0xb];

      puVar5[0xe] = puVar6[0xc];

      puVar5[0xf] = puVar6[0xd];

      puVar5[0x10] = puVar6[0xe];

      puVar5[0x11] = puVar6[0xf];

      puVar5[0x12] = puVar6[0x10];

      puVar6 = puVar6 + 0x20;

      puVar5 = puVar5 + 0x20;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  if (iVar8 < iVar9) {

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar8 * 0x20 + 0x1c + iVar2);

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar8 * 0x20 + 0x14 + iVar1);

    iVar9 = iVar9 - iVar8;

    do {

      puVar6[-5] = puVar5[-7];

      puVar6[-4] = puVar5[-6];

      puVar6[-3] = puVar5[-5];

      puVar6[-2] = puVar5[-4];

      puVar6[-1] = puVar5[-3];

      *puVar6 = *(uint32_t /* width from decompiler */ *)((iVar2 - iVar1) + (int)puVar6);

      puVar6[1] = puVar5[-1];

      puVar6[2] = *puVar5;

      puVar5 = puVar5 + 8;

      puVar6 = puVar6 + 8;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  return param_1;

}
