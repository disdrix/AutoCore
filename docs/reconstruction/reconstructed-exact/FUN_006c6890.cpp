// =============================================================================
// FUN_006c6890
// -----------------------------------------------------------------------------
// Stable ID: aa_006c6890
// Address:   0x006c6890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c6890 @ 0x006c6890
// Stable ID: aa_006c6890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~122 non-empty decompiler lines.
//  - Control keywords: if×11, do×4, while×4, return×1.
//  - Notable callees: FUN_006c6890, FUN_006cde50.
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

void __thiscall FUN_006c6890(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint8_t *puVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  uint uVar13;

  int iVar14;

  

  iVar11 = param_2;

  FUN_006cde50(param_2);

  *(uint32_t /* width from decompiler */ *)(param_2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  iVar1 = *(int *)(param_1 + 0x20);

  iVar2 = *(int *)(param_1 + 0x1c);

  uVar13 = iVar1 * 3;

  uVar4 = uVar13 | 0x80000000;

  uVar5 = *(uint *)(param_2 + 0x10) & 0x7fffffff;

  if ((int)uVar5 < (int)uVar13) {

    if (-1 < (int)*(uint *)(param_2 + 0x10)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_2 + 8),uVar5 << 2,0x12);

    }

    uVar6 = (**(code **)(*DAT_00b05060 + 0x10))(iVar1 * 0xc,0x12);

    *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar6;

    *(uint *)(param_2 + 0x10) = uVar13;

  }

  puVar7 = *(uint32_t /* width from decompiler */ **)(param_2 + 8);

  *(uint *)(param_2 + 0xc) = uVar13;

  if (0 < (int)uVar13) {

    iVar10 = iVar2 - (int)puVar7;

    do {

      *puVar7 = *(uint32_t /* width from decompiler */ *)(iVar10 + (int)puVar7);

      puVar7 = puVar7 + 1;

      uVar13 = uVar13 - 1;

    } while (uVar13 != 0);

  }

  uVar13 = *(uint *)(param_2 + 0x1c) & 0x7fffffff;

  if ((int)uVar13 < *(int *)(param_1 + 0x14)) {

    if (-1 < (int)*(uint *)(param_2 + 0x1c)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x14),uVar13 << 4,0x12);

    }

    uVar6 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_1 + 0x14) << 4,0x12);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = uVar6;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  }

  iVar10 = *(int *)(param_2 + 0x14);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  iVar14 = *(int *)(param_1 + 0x14);

  iVar3 = *(int *)(param_1 + 0x10);

  param_2 = 0;

  if (3 < iVar14) {

    puVar7 = (uint32_t /* width from decompiler */ *)(iVar3 + 0x1c);

    iVar12 = (iVar14 - 4U >> 2) + 1;

    puVar8 = (uint32_t /* width from decompiler */ *)(iVar10 + 0x14);

    param_2 = iVar12 * 4;

    do {

      puVar8[-5] = puVar7[-7];

      puVar8[-4] = puVar7[-6];

      puVar8[-3] = puVar7[-5];

      puVar8[-2] = puVar7[-4];

      puVar8[-1] = puVar7[-3];

      *puVar8 = *(uint32_t /* width from decompiler */ *)((int)puVar8 + (iVar3 - iVar10));

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

      iVar12 = iVar12 + -1;

    } while (iVar12 != 0);

  }

  if (param_2 < iVar14) {

    puVar7 = (uint32_t /* width from decompiler */ *)(param_2 * 0x10 + 0xc + iVar3);

    puVar8 = (uint32_t /* width from decompiler */ *)(param_2 * 0x10 + 4 + iVar10);

    iVar14 = iVar14 - param_2;

    do {

      puVar8[-1] = puVar7[-3];

      *puVar8 = *(uint32_t /* width from decompiler */ *)((iVar3 - iVar10) + (int)puVar8);

      puVar8[1] = puVar7[-1];

      puVar8[2] = *puVar7;

      puVar7 = puVar7 + 4;

      puVar8 = puVar8 + 4;

      iVar14 = iVar14 + -1;

    } while (iVar14 != 0);

  }

  uVar13 = *(uint *)(iVar11 + 0x28) & 0x7fffffff;

  if ((int)uVar13 < *(int *)(param_1 + 0x2c)) {

    if (-1 < (int)*(uint *)(iVar11 + 0x28)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(iVar11 + 0x20),uVar13,0x12);

    }

    uVar6 = (**(code **)(*DAT_00b05060 + 0x10))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),0x12);

    *(uint32_t /* width from decompiler */ *)(iVar11 + 0x20) = uVar6;

    *(uint32_t /* width from decompiler */ *)(iVar11 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

  }

  *(uint32_t /* width from decompiler */ *)(iVar11 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

  iVar10 = *(int *)(param_1 + 0x2c);

  puVar9 = *(uint8_t **)(iVar11 + 0x20);

  if (0 < iVar10) {

    iVar11 = *(int *)(param_1 + 0x28) - (int)puVar9;

    do {

      *puVar9 = puVar9[iVar11];

      puVar9 = puVar9 + 1;

      iVar10 = iVar10 + -1;

    } while (iVar10 != 0);

  }

  if (-1 < (int)uVar4) {

    (**(code **)(*DAT_00b05060 + 0x14))(iVar2,iVar1 * 0xc,0x12);

  }

  return;

}
