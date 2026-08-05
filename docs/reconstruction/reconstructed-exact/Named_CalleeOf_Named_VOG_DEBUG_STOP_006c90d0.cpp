// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_006c90d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c90d0
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x006c90d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_006c8e10, FUN_006c90d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_VOG_DEBUG_STOP_006c90d0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            int *param_5)



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

  

  iVar8 = 0;

  param_1[3] = DAT_00af58a0;

  *(uint16_t *)((int)param_1 + 6) = 1;

  param_1[2] = 0;

  *param_1 = &PTR_FUN_00a0d658;

  param_1[0xd] = 0;

  param_1[0xe] = 0x80000003;

  param_1[0xc] = param_1 + 0x10;

  param_1[0x35] = 0;

  param_1[0x36] = 0;

  param_1[0x37] = 0x80000000;

  uVar3 = param_1[0x37] & 0x7fffffff;

  if ((int)uVar3 < param_5[1]) {

    if (-1 < (int)param_1[0x37]) {

      (**(code **)(*DAT_00b05060 + 0x14))(0,uVar3 << 4,0x12);

    }

    uVar4 = (**(code **)(*DAT_00b05060 + 0x10))(param_5[1] << 4,0x12);

    param_1[0x35] = uVar4;

    param_1[0x37] = param_5[1];

  }

  iVar1 = param_1[0x35];

  param_1[0x36] = param_5[1];

  iVar9 = param_5[1];

  iVar2 = *param_5;

  if (3 < iVar9) {

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar1 + 0x14);

    iVar7 = (iVar9 - 4U >> 2) + 1;

    iVar8 = iVar7 * 4;

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x1c);

    do {

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

      puVar6 = puVar6 + 0x10;

      puVar5 = puVar5 + 0x10;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  if (iVar8 < iVar9) {

    puVar5 = (uint32_t /* width from decompiler */ *)(iVar8 * 0x10 + 0xc + iVar2);

    puVar6 = (uint32_t /* width from decompiler */ *)(iVar8 * 0x10 + 4 + iVar1);

    iVar9 = iVar9 - iVar8;

    do {

      puVar6[-1] = puVar5[-3];

      *puVar6 = *(uint32_t /* width from decompiler */ *)((iVar2 - iVar1) + (int)puVar6);

      puVar6[1] = puVar5[-1];

      puVar6[2] = *puVar5;

      puVar5 = puVar5 + 4;

      puVar6 = puVar6 + 4;

      iVar9 = iVar9 + -1;

    } while (iVar9 != 0);

  }

  FUN_006c8e10(param_2,param_4,param_3);

  return param_1;

}
