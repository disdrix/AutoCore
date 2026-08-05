// =============================================================================
// FUN_005ca540
// -----------------------------------------------------------------------------
// Stable ID: aa_005ca540
// Address:   0x005ca540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ca540 @ 0x005ca540
// Stable ID: aa_005ca540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, goto×1, while×1.
//  - Notable callees: FUN_005c9a00×2, FUN_004ccf30, FUN_005ca540.
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

uint32_t /* width from decompiler */ __thiscall FUN_005ca540(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  

  if (param_2 == 0) {

    return 0;

  }

  uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x60))();

  uVar4 = 0;

  if (uVar2 != 0) {

    do {

      iVar3 = FUN_005c9a00();

      iVar1 = *(int *)(iVar3 + 4);

      if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 8) - iVar1 >> 2) <= uVar4)) {

LAB_005ca5d8:

                    /* WARNING: Subroutine does not return */

        FUN_004ccf30();

      }

      *(uint32_t /* width from decompiler */ *)(iVar1 + uVar4 * 4) = *(uint32_t /* width from decompiler */ *)(param_2 + uVar4 * 4);

      iVar3 = FUN_005c9a00();

      iVar1 = *(int *)(iVar3 + 4);

      if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 8) - iVar1 >> 2) <= uVar4)) goto LAB_005ca5d8;

      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x6c))

                (*(uint16_t *)(iVar1 + uVar4 * 4),param_3);

      uVar4 = uVar4 + 1;

    } while (uVar4 < uVar2);

  }

  return 1;

}
