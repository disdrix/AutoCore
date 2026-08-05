// =============================================================================
// FUN_0096dc80
// -----------------------------------------------------------------------------
// Stable ID: aa_0096dc80
// Address:   0x0096dc80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096dc80 @ 0x0096dc80
// Stable ID: aa_0096dc80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0040d4b0×2, FUN_0044af00×2, FUN_00439a80, FUN_004406e0, FUN_0044adc0, FUN_0074c9c0, FUN_0096dc80.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_0096dc80(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  if (((param_2 != -1) && (iVar2 = FUN_0040d4b0(param_2), iVar2 == 0)) ||

     ((param_4 != -1 && (iVar2 = FUN_0040d4b0(param_4), iVar2 == 0)))) {

    return 0xffffffff;

  }

  puVar3 = operator_new(0x10);

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar3 = 0;

    puVar3[1] = 0;

    puVar3[2] = 0;

    puVar3[3] = 0;

  }

  FUN_004406e0();

  pvVar1 = *(void **)(param_1[0x1c] + -4);

  iVar2 = FUN_0044af00();

  iVar4 = FUN_0044af00();

  if ((iVar2 == 0) && (iVar4 == 0)) {

    (**(code **)(*param_1 + 0x30))(3);

    (**(code **)(*param_1 + 0x34))();

    FUN_00439a80();

    uVar5 = (**(code **)(_DAT_00000000 + 0xc))();

    uVar6 = (**(code **)(_DAT_00000000 + 0x48))();

    uVar7 = (**(code **)(*param_1 + 0xc))(uVar6,uVar5);

    FUN_0074c9c0(uVar7,uVar6,uVar5);

    return 0;

  }

  *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8) = 0;

  FUN_0044adc0(pvVar1);

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
