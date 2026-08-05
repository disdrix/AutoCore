// =============================================================================
// FUN_006c8c00
// -----------------------------------------------------------------------------
// Stable ID: aa_006c8c00
// Address:   0x006c8c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c8c00 @ 0x006c8c00
// Stable ID: aa_006c8c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~97 non-empty decompiler lines.
//  - Control keywords: if×7, do×3, while×3, return×1.
//  - Notable callees: FUN_005b3300, FUN_006c8c00, FUN_006cec70.
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

void __thiscall FUN_006c8c00(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int local_30;

  

  FUN_006cec70(param_2);

  uVar3 = *(uint *)(param_2 + 0x1c) & 0x7fffffff;

  if ((int)uVar3 < *(int *)(param_1 + 0xd8)) {

    if (-1 < (int)*(uint *)(param_2 + 0x1c)) {

      (**(code **)(*DAT_00b05060 + 0x14))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x14),uVar3 << 4,0x12);

    }

    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(*(int *)(param_1 + 0xd8) << 4,0x12);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = uVar4;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8);

  }

  iVar9 = *(int *)(param_2 + 0x14);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8);

  iVar8 = *(int *)(param_1 + 0xd8);

  iVar2 = *(int *)(param_1 + 0xd4);

  local_30 = 0;

  if (3 < iVar8) {

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x1c);

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar9 + 0x14);

    iVar7 = (iVar8 - 4U >> 2) + 1;

    local_30 = iVar7 * 4;

    do {

      puVar5[-5] = puVar6[-7];

      puVar5[-4] = puVar6[-6];

      puVar5[-3] = puVar6[-5];

      puVar5[-2] = puVar6[-4];

      puVar5[-1] = puVar6[-3];

      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar2 - iVar9));

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

      puVar6 = puVar6 + 0x10;

      puVar5 = puVar5 + 0x10;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  if (local_30 < iVar8) {

    puVar6 = (uint32_t /* width from decompiler */ *)(local_30 * 0x10 + 0xc + iVar2);

    puVar5 = (uint32_t /* width from decompiler */ *)(local_30 * 0x10 + 4 + iVar9);

    iVar8 = iVar8 - local_30;

    do {

      puVar5[-1] = puVar6[-3];

      *puVar5 = *(uint32_t /* width from decompiler */ *)((int)puVar5 + (iVar2 - iVar9));

      puVar5[1] = puVar6[-1];

      puVar5[2] = *puVar6;

      puVar6 = puVar6 + 4;

      puVar5 = puVar5 + 4;

      iVar8 = iVar8 + -1;

    } while (iVar8 != 0);

  }

  iVar9 = *(int *)(param_1 + 0xd0);

  uVar3 = *(uint *)(param_2 + 0x10) & 0x7fffffff;

  if ((int)uVar3 < iVar9) {

    iVar8 = uVar3 * 2;

    if (iVar8 <= iVar9) {

      iVar8 = iVar9;

    }

    FUN_005b3300((int *)(param_2 + 8),iVar8,0x10);

  }

  *(int *)(param_2 + 0xc) = iVar9;

  if (0 < *(int *)(param_1 + 0xd0)) {

    iVar9 = 0;

    uVar3 = 0;

    do {

      iVar8 = (uVar3 & 3) + ((int)(uVar3 + ((int)uVar3 >> 0x1f & 3U)) >> 2) * 0xc;

      iVar2 = *(int *)(param_1 + 0x30);

      uVar4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10 + iVar8 * 4);

      uVar1 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x20 + iVar8 * 4);

      puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 8) + iVar9);

      *puVar6 = *(uint32_t /* width from decompiler */ *)(iVar2 + iVar8 * 4);

      puVar6[2] = uVar1;

      puVar6[3] = 0;

      puVar6[1] = uVar4;

      uVar3 = uVar3 + 1;

      iVar9 = iVar9 + 0x10;

    } while ((int)uVar3 < *(int *)(param_1 + 0xd0));

  }

  return;

}
