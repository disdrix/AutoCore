// =============================================================================
// FUN_005dfee0
// -----------------------------------------------------------------------------
// Stable ID: aa_005dfee0
// Address:   0x005dfee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dfee0 @ 0x005dfee0
// Stable ID: aa_005dfee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×1, while×1.
//  - Notable callees: FUN_005df640, FUN_005dfee0, FUN_005e0310.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_005dfee0(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  uint uVar4;

  int *piVar5;

  int aiStack_70 [5];

  uint32_t /* width from decompiler */ uStack_5c;

  undefined *puStack_58;

  int aiStack_40 [2];

  undefined *puStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_1c;

  

  if (param_2 == (int *)0x0) {

    return 0;

  }

  uStack_34 = 4;

  puStack_38 = &DAT_00bc56b0;

  aiStack_40[1] = 0x5dff0d;

  (**(code **)(*param_2 + 0x14))();

  aiStack_40[1] = 1;

  aiStack_40[0] = param_1 + 0x1a0;

  (**(code **)(*param_2 + 0x14))();

  (**(code **)(*param_2 + 0x14))();

  (**(code **)(*param_2 + 0x14))();

  if (*(void **)(param_1 + 0x194) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x194) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x198) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x19c) = 0;

    puStack_38 = (undefined *)0x0;

    aiStack_40[1] = 0;

    aiStack_40[0] = 0;

    piVar3 = aiStack_40;

    piVar5 = aiStack_70;

    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {

      *piVar5 = *piVar3;

      piVar3 = piVar3 + 1;

      piVar5 = piVar5 + 1;

    }

    FUN_005e0310(uStack_1c);

    uVar4 = 0;

    iVar2 = 0;

    while( true ) {

      if (*(int *)(param_1 + 0x194) == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(param_1 + 0x198) - *(int *)(param_1 + 0x194) >> 5;

      }

      if (iVar1 <= (int)uVar4) break;

      iVar1 = *(int *)(param_1 + 0x194);

      if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x198) - iVar1 >> 5) <= uVar4)) {

        FUN_005df640();

        return 1;

      }

      puStack_58 = (undefined *)(iVar2 + iVar1);

      uStack_5c = 0x5dffc9;

      (**(code **)(*param_2 + 0x14))();

      uVar4 = uVar4 + 1;

      iVar2 = iVar2 + 0x20;

    }

    return 1;

  }

                    /* WARNING: Subroutine does not return */

  puStack_58 = &UNK_005dff51;

  operator_delete(*(void **)(param_1 + 0x194));

}
