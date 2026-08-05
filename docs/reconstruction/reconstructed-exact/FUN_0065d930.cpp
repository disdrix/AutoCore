// =============================================================================
// FUN_0065d930
// -----------------------------------------------------------------------------
// Stable ID: aa_0065d930
// Address:   0x0065d930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065d930 @ 0x0065d930
// Stable ID: aa_0065d930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~191 non-empty decompiler lines.
//  - Control keywords: if×16, do×7, while×7, for×1, return×1.
//  - Notable callees: FUN_005b3300, FUN_0065d930.
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

void __thiscall FUN_0065d930(int param_1,int *param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint uVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  

  piVar2 = param_2;

  iVar9 = param_2[1];

  piVar1 = (int *)(param_1 + 0x34);

  *(int *)(param_1 + 0xc) = iVar9;

  iVar4 = *(int *)(param_1 + 0x38);

  if (iVar4 < iVar9) {

    uVar8 = *(uint *)(param_1 + 0x3c) & 0x7fffffff;

    if ((int)uVar8 < iVar9) {

      iVar3 = uVar8 * 2;

      if (iVar3 <= iVar9) {

        iVar3 = iVar9;

      }

      FUN_005b3300(piVar1,iVar3,4);

    }

    if (3 < iVar9 - iVar4) {

      do {

        *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(*piVar1 + 4 + iVar4 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(*piVar1 + 8 + iVar4 * 4) = 0;

        *(uint32_t /* width from decompiler */ *)(*piVar1 + 0xc + iVar4 * 4) = 0;

        iVar4 = iVar4 + 4;

      } while (iVar4 < iVar9 + -3);

    }

    for (; iVar4 < iVar9; iVar4 = iVar4 + 1) {

      *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar4 * 4) = 0;

    }

  }

  *(int *)(param_1 + 0x38) = iVar9;

  uVar8 = *(uint *)(param_1 + 0x18) & 0x7fffffff;

  if ((int)uVar8 < param_2[1]) {

    if (-1 < (int)*(uint *)(param_1 + 0x18)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),uVar8 << 4,0x12);

    }

    uVar5 = (**(code **)(*DAT_00b05060 + 0x10))(param_2[1] << 4,0x12);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = uVar5;

    *(int *)(param_1 + 0x18) = param_2[1];

  }

  iVar9 = *(int *)(param_1 + 0x10);

  *(int *)(param_1 + 0x14) = param_2[1];

  iVar4 = param_2[1];

  iVar3 = *param_2;

  param_2 = (int *)0x0;

  if (3 < iVar4) {

    puVar7 = (uint32_t /* width from decompiler */ *)(iVar3 + 0x1c);

    iVar10 = (iVar4 - 4U >> 2) + 1;

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar9 + 0x14);

    param_2 = (int *)(iVar10 * 4);

    do {

      puVar6[-5] = puVar7[-7];

      puVar6[-4] = puVar7[-6];

      puVar6[-3] = puVar7[-5];

      puVar6[-2] = puVar7[-4];

      puVar6[-1] = puVar7[-3];

      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar3 - iVar9));

      puVar6[1] = puVar7[-1];

      puVar6[2] = *puVar7;

      puVar6[3] = puVar7[1];

      puVar6[4] = puVar7[2];

      puVar6[5] = puVar7[3];

      puVar6[6] = puVar7[4];

      puVar6[7] = puVar7[5];

      puVar6[8] = puVar7[6];

      puVar6[9] = puVar7[7];

      puVar6[10] = puVar7[8];

      puVar7 = puVar7 + 0x10;

      puVar6 = puVar6 + 0x10;

      iVar10 = iVar10 + -1;

    } while (iVar10 != 0);

  }

  if ((int)param_2 < iVar4) {

    puVar7 = (uint32_t /* width from decompiler */ *)((int)param_2 * 0x10 + 0xc + iVar3);

    iVar4 = iVar4 - (int)param_2;

    puVar6 = (uint32_t /* width from decompiler */ *)((int)param_2 * 0x10 + 4 + iVar9);

    do {

      puVar6[-1] = puVar7[-3];

      *puVar6 = *(uint32_t /* width from decompiler */ *)((iVar3 - iVar9) + (int)puVar6);

      puVar6[1] = puVar7[-1];

      puVar6[2] = *puVar7;

      puVar7 = puVar7 + 4;

      puVar6 = puVar6 + 4;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  uVar8 = *(uint *)(param_1 + 0x24) & 0x7fffffff;

  if ((int)uVar8 < piVar2[4]) {

    if (-1 < (int)*(uint *)(param_1 + 0x24)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c),uVar8 << 4,0x12);

    }

    uVar5 = (**(code **)(*DAT_00b05060 + 0x10))(piVar2[4] << 4,0x12);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = uVar5;

    *(int *)(param_1 + 0x24) = piVar2[4];

  }

  iVar9 = *(int *)(param_1 + 0x1c);

  *(int *)(param_1 + 0x20) = piVar2[4];

  iVar4 = piVar2[4];

  iVar3 = piVar2[3];

  param_2 = (int *)0x0;

  if (3 < iVar4) {

    puVar7 = (uint32_t /* width from decompiler */ *)(iVar3 + 0x1c);

    iVar10 = (iVar4 - 4U >> 2) + 1;

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar9 + 0x14);

    param_2 = (int *)(iVar10 * 4);

    do {

      puVar6[-5] = puVar7[-7];

      puVar6[-4] = puVar7[-6];

      puVar6[-3] = puVar7[-5];

      puVar6[-2] = puVar7[-4];

      puVar6[-1] = puVar7[-3];

      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar3 - iVar9));

      puVar6[1] = puVar7[-1];

      puVar6[2] = *puVar7;

      puVar6[3] = puVar7[1];

      puVar6[4] = puVar7[2];

      puVar6[5] = puVar7[3];

      puVar6[6] = puVar7[4];

      puVar6[7] = puVar7[5];

      puVar6[8] = puVar7[6];

      puVar6[9] = puVar7[7];

      puVar6[10] = puVar7[8];

      puVar7 = puVar7 + 0x10;

      puVar6 = puVar6 + 0x10;

      iVar10 = iVar10 + -1;

    } while (iVar10 != 0);

  }

  if ((int)param_2 < iVar4) {

    puVar7 = (uint32_t /* width from decompiler */ *)((int)param_2 * 0x10 + 0xc + iVar3);

    iVar4 = iVar4 - (int)param_2;

    puVar6 = (uint32_t /* width from decompiler */ *)((int)param_2 * 0x10 + 4 + iVar9);

    do {

      puVar6[-1] = puVar7[-3];

      *puVar6 = *(uint32_t /* width from decompiler */ *)((iVar3 - iVar9) + (int)puVar6);

      puVar6[1] = puVar7[-1];

      puVar6[2] = *puVar7;

      puVar7 = puVar7 + 4;

      puVar6 = puVar6 + 4;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  uVar8 = *(uint *)(param_1 + 0x30) & 0x7fffffff;

  if ((int)uVar8 < piVar2[7]) {

    if (-1 < (int)*(uint *)(param_1 + 0x30)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x28),uVar8 * 4,0x12);

    }

    uVar5 = (**(code **)(*DAT_00b05060 + 0x10))(piVar2[7] * 4,0x12);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = uVar5;

    *(int *)(param_1 + 0x30) = piVar2[7];

  }

  *(int *)(param_1 + 0x2c) = piVar2[7];

  iVar4 = piVar2[7];

  iVar3 = piVar2[6];

  iVar10 = *(int *)(param_1 + 0x28);

  iVar9 = 0;

  if (3 < iVar4) {

    iVar11 = (iVar4 - 4U >> 2) + 1;

    puVar7 = (uint32_t /* width from decompiler */ *)(iVar3 + 0xc);

    iVar9 = iVar11 * 4;

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar10 + 4);

    do {

      puVar6[-1] = puVar7[-3];

      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar3 - iVar10));

      puVar6[1] = puVar7[-1];

      puVar6[2] = *puVar7;

      puVar6 = puVar6 + 4;

      puVar7 = puVar7 + 4;

      iVar11 = iVar11 + -1;

    } while (iVar11 != 0);

  }

  if (iVar9 < iVar4) {

    puVar7 = (uint32_t /* width from decompiler */ *)(iVar10 + iVar9 * 4);

    iVar4 = iVar4 - iVar9;

    do {

      *puVar7 = *(uint32_t /* width from decompiler */ *)((int)puVar7 + (iVar3 - iVar10));

      puVar7 = puVar7 + 1;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  return;

}
