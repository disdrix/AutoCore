// =============================================================================
// FUN_0088d670
// -----------------------------------------------------------------------------
// Stable ID: aa_0088d670
// Address:   0x0088d670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0088d670 @ 0x0088d670
// Stable ID: aa_0088d670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0040cf90, FUN_0040d1a0, FUN_0076e5e0, FUN_00833390, FUN_00833490, FUN_00833a90, FUN_0088d670.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_0088d670(int param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  float fStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if (((*(int *)(param_1 + 0x5cc) != 0) &&

      (piVar1 = *(int **)(*(int *)(param_1 + 0x5cc) + 0x508), piVar1 != (int *)0x0)) &&

     ((int *)piVar1[0x12] != (int *)0x0)) {

    iVar2 = (**(code **)(*(int *)piVar1[0x12] + 0x48))();

    FUN_00833a90(*(float *)(iVar2 + 0xc) * _DAT_00aaaa0c);

    iVar2 = (**(code **)(**(int **)(param_1 + 0x5cc) + 0x1a0))();

    iVar2 = *(int *)(iVar2 + 8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x534) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x90);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x538) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x94);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x53c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x98);

    uStack_10 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x534);

    uStack_c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x538);

    fStack_8 = *(float *)(param_1 + 0x53c);

    iVar2 = (**(code **)(*(int *)piVar1[0x12] + 0x48))();

    fStack_8 = fStack_8 - *(float *)(iVar2 + 0xc) * DAT_00a110d8;

    (**(code **)(**(int **)(param_1 + 0x5cc) + 0x1a0))();

    FUN_0040cf90(&uStack_10);

    uStack_10 = DAT_00aaaa08;

    uStack_c = DAT_00aaaa04;

    fStack_8 = (float)DAT_00aaaa00;

    uStack_4 = DAT_00aaa9fc;

    FUN_0076e5e0(&uStack_10,&uStack_10);

    FUN_0040d1a0(&uStack_10);

    FUN_00833490();

    (**(code **)(*piVar1 + 0x44))();

    FUN_00833390();

  }

  return;

}
