// =============================================================================
// FUN_0073f2f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073f2f0
// Address:   0x0073f2f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073f2f0 @ 0x0073f2f0
// Stable ID: aa_0073f2f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×7, goto×1, for×1, return×1.
//  - Notable callees: FUN_00456780×2, FUN_00450960, FUN_00456960, FUN_0073f2f0.
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

void __thiscall FUN_0073f2f0(int param_1,uint param_2)



{

  uint *puVar1;

  uint *puVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint *puVar6;

  

  if (*(int *)(param_1 + 0x14) == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 2;

  }

  if (iVar3 <= (int)param_2) {

    FUN_00456780(0);

  }

  if (-1 < (int)param_2) {

    iVar3 = *(int *)(DAT_00d1f620 + 4);

    if (iVar3 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(DAT_00d1f620 + 8) - iVar3 >> 2;

    }

    if ((int)param_2 < iVar4) {

      uVar5 = (**(code **)(**(int **)(iVar3 + param_2 * 4) + 0x10))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x30))

      ;

      goto LAB_0073f34e;

    }

  }

  uVar5 = 0;

LAB_0073f34e:

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + param_2 * 4) = uVar5;

  FUN_00456780(0);

  puVar1 = *(uint **)(param_1 + 0x18);

  for (puVar6 = *(uint **)(param_1 + 0x14); puVar6 != puVar1; puVar6 = puVar6 + 1) {

    param_2 = *puVar6;

    if (param_2 != 0) {

      iVar3 = *(int *)(param_1 + 0x24);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(param_1 + 0x2c) - iVar3 >> 2) <=

          (uint)(*(int *)(param_1 + 0x28) - iVar3 >> 2))) {

        FUN_00456960(*(uint32_t /* width from decompiler */ *)(param_1 + 0x28));

      }

      else {

        puVar2 = *(uint **)(param_1 + 0x28);

        *puVar2 = param_2;

        *(uint **)(param_1 + 0x28) = puVar2 + 1;

      }

    }

  }

  param_2 = param_2 & 0xffffff00;

  FUN_00450960(*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x28),

               *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 2,param_2);

  return;

}
