// =============================================================================
// FUN_005b3b30
// -----------------------------------------------------------------------------
// Stable ID: aa_005b3b30
// Address:   0x005b3b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b3b30 @ 0x005b3b30
// Stable ID: aa_005b3b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004baf50, FUN_005b3b30.
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

void __thiscall FUN_005b3b30(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,float param_4)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uStack_c;

  float fStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if ((*(float *)(param_1 + 0x24) != param_4) &&

     (piVar3 = (int *)**(int **)(param_1 + 0x14), piVar3 != *(int **)(param_1 + 0x14))) {

    do {

      iVar2 = FUN_004baf50(piVar3 + 8);

      if ((iVar2 != 0) && (piVar1 = *(int **)(iVar2 + 8), piVar1 != (int *)0x0)) {

        iVar2 = (**(code **)(*piVar1 + 0xc))();

        uStack_c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x90);

        uStack_4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x98);

        fStack_8 = param_4;

        (**(code **)(*piVar1 + 0x18))(&uStack_c);

      }

      piVar3 = (int *)*piVar3;

    } while (piVar3 != (int *)*(int *)(param_1 + 0x14));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = param_2;

  *(float *)(param_1 + 0x24) = param_4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  return;

}
