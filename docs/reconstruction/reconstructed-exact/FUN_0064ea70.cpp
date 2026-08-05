// =============================================================================
// FUN_0064ea70
// -----------------------------------------------------------------------------
// Stable ID: aa_0064ea70
// Address:   0x0064ea70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064ea70 @ 0x0064ea70
// Stable ID: aa_0064ea70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×11, do×5, while×5, return×2.
//  - Notable callees: FUN_0064ea70, FUN_0065e1d0.
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

void __thiscall FUN_0064ea70(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t *puVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  

  FUN_0065e1d0(param_2);

  uVar3 = *(uint *)(param_2 + 0xc) & 0x7fffffff;

  if ((int)uVar3 < *(int *)(param_1 + 0x2c)) {

    if (-1 < (int)*(uint *)(param_2 + 0xc)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_2 + 4),uVar3 * 4,0x12);

    }

    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_1 + 0x2c) * 4,0x12);

    *(uint32_t /* width from decompiler */ *)(param_2 + 4) = uVar4;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

  }

  *(uint32_t /* width from decompiler */ *)(param_2 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

  iVar10 = *(int *)(param_1 + 0x2c);

  iVar1 = *(int *)(param_1 + 0x28);

  iVar2 = *(int *)(param_2 + 4);

  iVar8 = 0;

  if (3 < iVar10) {

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xc);

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);

    iVar9 = (iVar10 - 4U >> 2) + 1;

    iVar8 = iVar9 * 4;

    do {

      puVar5[-1] = puVar6[-3];

      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar1 - iVar2));

      puVar5[1] = puVar6[-1];

      puVar5[2] = *puVar6;

      puVar5 = puVar5 + 4;

      puVar6 = puVar6 + 4;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  if (iVar8 < iVar10) {

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar8 * 4);

    iVar10 = iVar10 - iVar8;

    do {

      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar1 - iVar2));

      puVar6 = puVar6 + 1;

      iVar10 = iVar10 + -1;

    } while (iVar10 != 0);

  }

  uVar3 = *(uint *)(param_2 + 0x18) & 0x7fffffff;

  if ((int)uVar3 < *(int *)(param_1 + 0x38)) {

    if (-1 < (int)*(uint *)(param_2 + 0x18)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x10),uVar3 * 4,0x12);

    }

    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_1 + 0x38) * 4,0x12);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = uVar4;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x38);

  }

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x38);

  iVar10 = *(int *)(param_1 + 0x38);

  iVar1 = *(int *)(param_1 + 0x34);

  iVar2 = *(int *)(param_2 + 0x10);

  iVar8 = 0;

  if (3 < iVar10) {

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xc);

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);

    iVar9 = (iVar10 - 4U >> 2) + 1;

    iVar8 = iVar9 * 4;

    do {

      puVar5[-1] = puVar6[-3];

      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar1 - iVar2));

      puVar5[1] = puVar6[-1];

      puVar5[2] = *puVar6;

      puVar5 = puVar5 + 4;

      puVar6 = puVar6 + 4;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  if (iVar8 < iVar10) {

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar8 * 4);

    iVar10 = iVar10 - iVar8;

    do {

      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar1 - iVar2));

      puVar6 = puVar6 + 1;

      iVar10 = iVar10 + -1;

    } while (iVar10 != 0);

  }

  uVar3 = *(uint *)(param_2 + 0x28) & 0x7fffffff;

  if ((int)uVar3 < *(int *)(param_1 + 0x44)) {

    if (-1 < (int)*(uint *)(param_2 + 0x28)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x20),uVar3,0x12);

    }

    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x44),0x12);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x20) = uVar4;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);

  }

  puVar7 = *(uint8_t **)(param_2 + 0x20);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);

  iVar8 = *(int *)(param_1 + 0x44);

  if (iVar8 < 1) {

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c);

    return;

  }

  iVar10 = *(int *)(param_1 + 0x40) - (int)puVar7;

  do {

    *puVar7 = puVar7[iVar10];

    puVar7 = puVar7 + 1;

    iVar8 = iVar8 + -1;

  } while (iVar8 != 0);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c);

  return;

}
