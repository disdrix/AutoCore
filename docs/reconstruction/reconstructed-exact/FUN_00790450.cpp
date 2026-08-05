// =============================================================================
// FUN_00790450
// -----------------------------------------------------------------------------
// Stable ID: aa_00790450
// Address:   0x00790450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00790450 @ 0x00790450
// Stable ID: aa_00790450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_007807b0, FUN_00790450.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall FUN_00790450(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  void *pvVar4;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ uStack_2c;

  uint8_t *puStack_28;

  uint32_t /* width from decompiler */ uStack_20;

  int iStack_1c;

  

  if ((int *)param_1[0xac] != (int *)0x0) {

    iStack_1c = 0x790477;

    uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x424))();

    return uVar2;

  }

  *(uint8_t *)((int)param_1 + 0x491) = 1;

  if (param_2 != (int *)0x0) {

    cVar1 = (**(code **)(*param_2 + 0x2f0))();

    if (cVar1 != '\0') {

      iStack_1c = param_4;

      uStack_20 = param_3;

      iVar3 = (**(code **)(*param_2 + 0x2ec))();

      if (iVar3 != 0) {

        puStack_28 = (uint8_t *)0x7904cf;

        pvVar4 = operator_new(0x24);

        if (pvVar4 == (void *)0x0) {

          iVar5 = 0;

        }

        else {

          iVar5 = FUN_007807b0();

        }

        param_1[0x12d] = iVar5;

        *(int **)(iVar5 + 0x14) = param_2;

        *(int *)(param_1[0x12d] + 0x18) = param_2[0xac];

        iVar5 = param_1[0x12d];

        *(uint32_t /* width from decompiler */ *)(iVar5 + 4) = param_3;

        *(int *)(iVar5 + 8) = param_4;

        *(int *)(param_1[0x12d] + 0x1c) = iVar3;

        puStack_28 = &stack0xfffffff0;

        uStack_2c = 0x790528;

        (**(code **)(**(int **)(param_1[0x12d] + 0x1c) + 0x140))();

        uStack_2c = 1;

        (**(code **)(**(int **)(param_1[0x12d] + 0x1c) + 0x140))(&stack0xffffffe8);

        piVar6 = (int *)(**(code **)(*param_1 + 0x120))(&uStack_20,1,1);

        iStack_1c = iStack_1c - *piVar6;

        (**(code **)(*param_1 + 0x120))(&uStack_2c,1,1);

        (**(code **)(**(int **)(param_1[0x12d] + 0x1c) + 0x11c))(&puStack_28);

        (**(code **)(*param_1 + 0xa8))(*(uint32_t /* width from decompiler */ *)(param_1[0x12d] + 0x1c));

        (**(code **)(**(int **)(param_1[0x12d] + 0x1c) + 0x34c))();

      }

      return 1;

    }

  }

  return 1;

}
