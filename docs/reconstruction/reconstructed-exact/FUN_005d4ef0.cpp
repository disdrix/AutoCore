// =============================================================================
// FUN_005d4ef0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4ef0
// Address:   0x005d4ef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d4ef0 @ 0x005d4ef0
// Stable ID: aa_005d4ef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, for×1, return×1.
//  - Notable callees: FUN_00513f70, FUN_005d4ef0.
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

void __thiscall FUN_005d4ef0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  FUN_00513f70(param_2);

  if (*(int *)(param_1 + -0x24) == 1) {

    iVar2 = *(int *)(param_1 + -0xdc);

    if ((*(uint *)(*(int *)(iVar2 + 4) + 0xa0 + param_1) >> 3 & 1) != 0) goto LAB_005d4f67;

    uVar4 = 1;

  }

  else {

    if ((*(int *)(param_1 + -0x24) != 2) ||

       (iVar2 = *(int *)(param_1 + -0xdc),

       (*(uint *)(*(int *)(iVar2 + 4) + 0xa0 + param_1) >> 3 & 1) == 0)) goto LAB_005d4f67;

    uVar4 = 0;

  }

  (**(code **)(*(int *)(*(int *)(iVar2 + 4) + -0xdc + param_1) + 0x1b4))(uVar4);

LAB_005d4f67:

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x24) = 0;

  if (*(int *)(param_1 + -0x20) != 0) {

    if (*(int *)(param_1 + -0xd8) != 0) {

      *(int *)(*(int *)(param_1 + -0xd8) + 0x28) = *(int *)(param_1 + -0x20);

    }

    if (*(int *)(param_1 + -0xd4) != 0) {

      for (uVar3 = 0; uVar1 = (**(code **)(**(int **)(param_1 + -0xd4) + 0x4c))(), uVar3 < uVar1;

          uVar3 = uVar3 + 1) {

        iVar2 = (**(code **)(**(int **)(param_1 + -0xd4) + 0x50))();

        (**(code **)(**(int **)(iVar2 + uVar3 * 4) + 8))(4);

      }

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x20) = 0;

  }

  return;

}
