// =============================================================================
// FUN_007332b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007332b0
// Address:   0x007332b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007332b0 @ 0x007332b0
// Stable ID: aa_007332b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, return×1.
//  - Notable callees: FUN_00456780×2, FUN_00456960×2, FUN_00469270×2, FUN_00729bb0×2, FUN_007332b0.
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

uint32_t /* width from decompiler */ __thiscall FUN_007332b0(int param_1,uint param_2)



{

  uint *puVar1;

  void *pvVar2;

  int iVar3;

  uint *puVar4;

  uint *puVar5;

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad5cb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar2 = operator_new(0x1c);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_00729bb0(pvVar2,*(uint32_t /* width from decompiler */ *)(param_1 + 4));

  }

  local_4 = 0xffffffff;

  *(uint *)(iVar3 + 0x18) = param_2;

  *(int *)(*(int *)(param_1 + 0xc) + *(int *)(param_2 + 0x1c) * 4) = iVar3;

  FUN_00456780(0);

  puVar5 = *(uint **)(param_1 + 0x10);

  for (puVar4 = *(uint **)(param_1 + 0xc); puVar4 != puVar5; puVar4 = puVar4 + 1) {

    pvVar2 = (void *)*puVar4;

    if (pvVar2 != (void *)0x0) {

      iVar3 = *(int *)(param_1 + 0x2c);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(param_1 + 0x34) - iVar3 >> 2) <=

          (uint)(*(int *)(param_1 + 0x30) - iVar3 >> 2))) {

        FUN_00456960(*(uint32_t /* width from decompiler */ *)(param_1 + 0x30));

      }

      else {

        puVar1 = *(uint **)(param_1 + 0x30);

        *puVar1 = (uint)pvVar2;

        *(uint **)(param_1 + 0x30) = puVar1 + 1;

      }

    }

  }

  local_10 = (uint)pvVar2 & 0xffffff00;

  FUN_00469270(*(int *)(param_1 + 0x2c),*(int *)(param_1 + 0x30),

               *(int *)(param_1 + 0x30) - *(int *)(param_1 + 0x2c) >> 2,local_10);

  if (*(int *)(param_1 + 0x58) != 0) {

    pvVar2 = operator_new(0x1c);

    local_4 = 1;

    if (pvVar2 == (void *)0x0) {

      iVar3 = 0;

    }

    else {

      iVar3 = FUN_00729bb0(pvVar2,*(uint32_t /* width from decompiler */ *)(param_1 + 4));

    }

    local_4 = 0xffffffff;

    *(uint *)(iVar3 + 0x18) = param_2;

    *(int *)(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c) * 4) = iVar3;

    FUN_00456780(0);

    puVar4 = *(uint **)(param_1 + 0x20);

    for (puVar5 = *(uint **)(param_1 + 0x1c); puVar5 != puVar4; puVar5 = puVar5 + 1) {

      param_2 = *puVar5;

      if (param_2 != 0) {

        iVar3 = *(int *)(param_1 + 0x3c);

        if ((iVar3 == 0) ||

           ((uint)(*(int *)(param_1 + 0x44) - iVar3 >> 2) <=

            (uint)(*(int *)(param_1 + 0x40) - iVar3 >> 2))) {

          FUN_00456960(*(uint32_t /* width from decompiler */ *)(param_1 + 0x40));

        }

        else {

          puVar1 = *(uint **)(param_1 + 0x40);

          *puVar1 = param_2;

          *(uint **)(param_1 + 0x40) = puVar1 + 1;

        }

      }

    }

    param_2 = param_2 & 0xffffff00;

    FUN_00469270(*(int *)(param_1 + 0x3c),*(int *)(param_1 + 0x40),

                 *(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x3c) >> 2,param_2);

  }

  ExceptionList = local_c;

  return 0;

}
