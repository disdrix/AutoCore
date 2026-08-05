// =============================================================================
// FUN_009251d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009251d0
// Address:   0x009251d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009251d0 @ 0x009251d0
// Stable ID: aa_009251d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×10, return×9.
//  - Notable callees: Client_InteractClickPickTarget×2, CVOGHBBase_Start, FUN_007fb990, FUN_00914be0, FUN_009251d0, FUN_0093bac0.
//  - Return sites: 9.

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

uint32_t /* width from decompiler */ __thiscall FUN_009251d0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ unaff_EBX;

  

  if (((param_1[0x331] == 6) && (*(char *)((int)param_1 + 0x493) == '\0')) &&

     (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) {

    return 0;

  }

  (**(code **)(*param_1 + 0x3bc))(param_1[0x12e]);

  (**(code **)(*param_1 + 0x42c))

            (param_1[0x12e],(int)(short)param_3,(int)(short)((uint)param_3 >> 0x10));

  if (((int *)param_1[0x12e] != (int *)0x0) &&

     (cVar1 = (**(code **)(*(int *)param_1[0x12e] + 0x378))(unaff_EBX,param_3), cVar1 != '\0')) {

    return 1;

  }

  if (DAT_00d1d900 != -1) {

    FUN_0093bac0(&DAT_00d1a840,0);

    FUN_007fb990();

    return 1;

  }

  if (DAT_00d1b6d8 == 0) {

    return 0;

  }

  cVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) + 0x194

                      ))();

  if (cVar1 != '\0') {

    return 0;

  }

  cVar1 = (**(code **)(*DAT_00d1b958 + 0x3d8))();

  if (cVar1 != '\0') {

    return 0;

  }

  cVar1 = (**(code **)(*DAT_00d1b95c + 0x3d8))();

  if (cVar1 != '\0') {

    return 0;

  }

  cVar1 = FUN_00914be0();

  if ((((((cVar1 == '\0') || (*(int *)(DAT_00d1b6d8 + 0xcd0) != 0)) ||

        ((DAT_00d1b898 != (int *)0x0 &&

         (cVar2 = (**(code **)(*DAT_00d1b898 + 0x3d8))(), cVar2 != '\0')))) ||

       ((DAT_00d1b89c != (int *)0x0 &&

        (cVar2 = (**(code **)(*DAT_00d1b89c + 0x3d8))(), cVar2 != '\0')))) ||

      ((DAT_00d1b894 != (int *)0x0 &&

       (cVar2 = (**(code **)(*DAT_00d1b894 + 0x3d8))(), cVar2 != '\0')))) ||

     (((DAT_00d1b888 != (int *)0x0 &&

       (cVar2 = (**(code **)(*DAT_00d1b888 + 0x3d8))(), cVar2 != '\0')) ||

      ((DAT_00d1b88c != (int *)0x0 &&

       (cVar2 = (**(code **)(*DAT_00d1b88c + 0x3d8))(), cVar2 != '\0')))))) {

    DAT_00d1a859 = 0;

  }

  else {

    DAT_00d1a859 = 1;

  }

  if (DAT_00d1a860 != '\0') {

    Client_InteractClickPickTarget(unaff_EBX,param_3,0,DAT_00d1b205);

    if (((CVOGHBBase *)param_1[0x31c] != (CVOGHBBase *)0x0) && (cVar1 != '\0')) {

      *(uint8_t *)((int)param_1 + 0xa35) = 1;

      CVOGHBBase_Start((CVOGHBBase *)param_1[0x31c]);

    }

    return 0;

  }

  uVar3 = Client_InteractClickPickTarget(unaff_EBX,param_3,1,DAT_00d1b205);

  return uVar3;

}
