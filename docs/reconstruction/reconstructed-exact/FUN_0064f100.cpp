// =============================================================================
// FUN_0064f100
// -----------------------------------------------------------------------------
// Stable ID: aa_0064f100
// Address:   0x0064f100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064f100 @ 0x0064f100
// Stable ID: aa_0064f100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×8, do×4, while×4, return×1.
//  - Notable callees: FUN_0064f100.
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

void __thiscall FUN_0064f100(int param_1,int param_2)



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

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

  uVar3 = *(uint *)(param_1 + 0x48) & 0x7fffffff;

  if ((int)uVar3 < *(int *)(param_2 + 0x1c)) {

    if (-1 < (int)*(uint *)(param_1 + 0x48)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),uVar3 * 4,0x12);

    }

    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_2 + 0x1c) * 4,0x12);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = uVar4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

  iVar9 = *(int *)(param_2 + 0x1c);

  iVar1 = *(int *)(param_2 + 0x18);

  iVar2 = *(int *)(param_1 + 0x40);

  iVar7 = 0;

  if (3 < iVar9) {

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xc);

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);

    iVar8 = (iVar9 - 4U >> 2) + 1;

    iVar7 = iVar8 * 4;

    do {

      puVar5[-1] = puVar6[-3];

      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar1 - iVar2));

      puVar5[1] = puVar6[-1];

      puVar5[2] = *puVar6;

      puVar5 = puVar5 + 4;

      puVar6 = puVar6 + 4;

      iVar8 = iVar8 + -1;

    } while (iVar8 != 0);

  }

  if (iVar7 < iVar9) {

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar7 * 4);

    iVar9 = iVar9 - iVar7;

    do {

      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar1 - iVar2));

      puVar6 = puVar6 + 1;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  uVar3 = *(uint *)(param_1 + 0x54) & 0x7fffffff;

  if ((int)uVar3 < *(int *)(param_2 + 0x28)) {

    if (-1 < (int)*(uint *)(param_1 + 0x54)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x4c),uVar3 * 4,0x12);

    }

    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_2 + 0x28) * 4,0x12);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = uVar4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x28);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x28);

  iVar9 = *(int *)(param_2 + 0x28);

  iVar1 = *(int *)(param_2 + 0x24);

  iVar2 = *(int *)(param_1 + 0x4c);

  iVar7 = 0;

  if (3 < iVar9) {

    iVar8 = (iVar9 - 4U >> 2) + 1;

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar1 + 0xc);

    iVar7 = iVar8 * 4;

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);

    do {

      puVar5[-1] = puVar6[-3];

      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar1 - iVar2));

      puVar5[1] = puVar6[-1];

      puVar5[2] = *puVar6;

      puVar5 = puVar5 + 4;

      puVar6 = puVar6 + 4;

      iVar8 = iVar8 + -1;

    } while (iVar8 != 0);

  }

  if (iVar7 < iVar9) {

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + iVar7 * 4);

    iVar9 = iVar9 - iVar7;

    do {

      *puVar6 = *(uint32_t /* width from decompiler */ *)((int)puVar6 + (iVar1 - iVar2));

      puVar6 = puVar6 + 1;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  return;

}
