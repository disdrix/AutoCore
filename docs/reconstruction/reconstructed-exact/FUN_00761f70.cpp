// =============================================================================
// FUN_00761f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00761f70
// Address:   0x00761f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00761f70 @ 0x00761f70
// Stable ID: aa_00761f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×7, for×3, while×1, return×1.
//  - Notable callees: block×4, FUN_00456960×3, FUN_00760830×2, FUN_00761e70, FUN_00761f70.
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

/* WARNING: Removing unreachable block (ram,0x0076214a) */

/* WARNING: Removing unreachable block (ram,0x00762160) */

/* WARNING: Removing unreachable block (ram,0x007621b6) */

/* WARNING: Removing unreachable block (ram,0x007621a0) */



void __thiscall FUN_00761f70(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  void **ppvVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int local_28;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2742;

  puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 0xc4);

  ppvVar5 = &local_c;

  local_c = ExceptionList;

  for (puVar8 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 0xc0); ExceptionList = ppvVar5,

      puVar8 != puVar1; puVar8 = puVar8 + 1) {

    uVar2 = *puVar8;

    if ((*(int *)(param_1 + 0xc) == 0) ||

       ((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28 == 0)) {

      FUN_00760830(1);

    }

    iVar7 = *(int *)(param_1 + 0xc);

    iVar3 = *(int *)(iVar7 + 4);

    if ((iVar3 == 0) ||

       ((uint)(*(int *)(iVar7 + 0xc) - iVar3 >> 2) <= (uint)(*(int *)(iVar7 + 8) - iVar3 >> 2))) {

      FUN_00456960(*(uint32_t /* width from decompiler */ *)(iVar7 + 8));

    }

    else {

      puVar4 = *(uint32_t /* width from decompiler */ **)(iVar7 + 8);

      *puVar4 = uVar2;

      *(uint32_t /* width from decompiler */ **)(iVar7 + 8) = puVar4 + 1;

    }

    ppvVar5 = ExceptionList;

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 0xd4);

  for (puVar8 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + 0xd0); puVar8 != puVar1;

      puVar8 = puVar8 + 1) {

    uVar2 = *puVar8;

    if ((*(int *)(param_1 + 0xc) == 0) ||

       ((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28 == 0)) {

      FUN_00760830(1);

    }

    iVar7 = *(int *)(param_1 + 0xc);

    iVar3 = *(int *)(iVar7 + 0x14);

    if ((iVar3 == 0) ||

       ((uint)(*(int *)(iVar7 + 0x1c) - iVar3 >> 2) <= (uint)(*(int *)(iVar7 + 0x18) - iVar3 >> 2)))

    {

      FUN_00456960(*(uint32_t /* width from decompiler */ *)(iVar7 + 0x18));

    }

    else {

      puVar4 = *(uint32_t /* width from decompiler */ **)(iVar7 + 0x18);

      *puVar4 = uVar2;

      *(uint32_t /* width from decompiler */ **)(iVar7 + 0x18) = puVar4 + 1;

    }

  }

  local_4 = 0;

  local_28 = 1;

  while( true ) {

    iVar7 = 0;

    if (*(int *)(param_1 + 0xc) != 0) {

      iVar7 = (*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) / 0x28;

    }

    if (iVar7 <= local_28) break;

    iVar3 = *(int *)(*(int *)(param_1 + 4) + 0xc4);

    for (iVar7 = *(int *)(*(int *)(param_1 + 4) + 0xc0); iVar7 != iVar3; iVar7 = iVar7 + 4) {

      iVar6 = FUN_00761e70(param_1,local_28,param_2,param_3,param_4,0);

      if (iVar6 != 0) {

        FUN_00456960(0);

      }

    }

    local_28 = local_28 + 1;

  }

  ExceptionList = local_c;

  return;

}
