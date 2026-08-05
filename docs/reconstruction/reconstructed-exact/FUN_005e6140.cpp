// =============================================================================
// FUN_005e6140
// -----------------------------------------------------------------------------
// Stable ID: aa_005e6140
// Address:   0x005e6140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e6140 @ 0x005e6140
// Stable ID: aa_005e6140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×12, while×2, goto×2, return×1.
//  - Notable callees: FUN_0075c960×3, FUN_00493e90×2, CONCAT31, FUN_004507a0, FUN_005e6140.
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

uint32_t /* width from decompiler */ __fastcall FUN_005e6140(int param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  uint8_t local_5;

  uint32_t /* width from decompiler */ uStack_4;

  

  local_5 = 0;

  if (*(int *)(param_1 + 0x14c) != 0) {

    piVar1 = *(int **)(param_1 + 0x14c);

    uVar4 = (**(code **)(*piVar1 + 0xc))();

    uVar5 = (**(code **)(*piVar1 + 0x48))(uVar4);

    iVar6 = FUN_0075c960(uVar5,uVar4);

    if (iVar6 != -1) {

      FUN_00493e90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x14c));

      local_5 = 1;

    }

  }

  iVar6 = 0;

  while( true ) {

    if (*(int *)(param_1 + 0x14) == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 2;

    }

    if (iVar7 <= iVar6) break;

    if ((*(int *)(*(int *)(param_1 + 0x14) + iVar6 * 4) != 0) &&

       (piVar1 = *(int **)(*(int *)(param_1 + 0x198) + iVar6 * 4), piVar1 != (int *)0x0)) {

      uVar4 = (**(code **)(*piVar1 + 0xc))();

      uVar5 = (**(code **)(*piVar1 + 0x48))(uVar4);

      iVar7 = FUN_0075c960(uVar5,uVar4);

      if (iVar7 != -1) {

        FUN_00493e90(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x198) + iVar6 * 4));

        local_5 = 1;

      }

    }

    iVar6 = iVar6 + 1;

  }

  iVar6 = *(int *)(param_1 + 0x138);

  if (*(char *)(iVar6 + 0x7d) != '\0') {

    iVar7 = 0;

    while( true ) {

      if (*(int *)(param_1 + 0x154) == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 0x158) - *(int *)(param_1 + 0x154) >> 2;

      }

      if (iVar6 <= iVar7) break;

      piVar1 = *(int **)(*(int *)(param_1 + 0x154) + iVar7 * 4);

      if (piVar1 == (int *)0x0) {

LAB_005e62f7:

        iVar7 = iVar7 + 1;

      }

      else {

        uVar4 = (**(code **)(*piVar1 + 0xc))();

        uVar5 = (**(code **)(*piVar1 + 0x48))(uVar4);

        iVar6 = FUN_0075c960(uVar5,uVar4);

        if (iVar6 == -1) goto LAB_005e62f7;

        iVar6 = *(int *)(*(int *)(param_1 + 0x138) + 0xe898);

        uStack_4 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x154) + iVar7 * 4);

        iVar2 = *(int *)(iVar6 + 0xac);

        if ((iVar2 == 0) ||

           ((uint)(*(int *)(iVar6 + 0xb4) - iVar2 >> 2) <=

            (uint)(*(int *)(iVar6 + 0xb0) - iVar2 >> 2))) {

          FUN_004507a0(*(uint32_t /* width from decompiler */ *)(iVar6 + 0xb0),1,&uStack_4);

          local_5 = 1;

          goto LAB_005e62f7;

        }

        puVar3 = *(uint32_t /* width from decompiler */ **)(iVar6 + 0xb0);

        *puVar3 = uStack_4;

        *(uint32_t /* width from decompiler */ **)(iVar6 + 0xb0) = puVar3 + 1;

        local_5 = 1;

        iVar7 = iVar7 + 1;

      }

    }

  }

  return CONCAT31((int3)((uint)iVar6 >> 8),local_5);

}
