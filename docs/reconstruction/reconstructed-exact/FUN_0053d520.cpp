// =============================================================================
// FUN_0053d520
// -----------------------------------------------------------------------------
// Stable ID: aa_0053d520
// Address:   0x0053d520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053d520 @ 0x0053d520
// Stable ID: aa_0053d520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005070b0, FUN_005070d0, FUN_00513290, FUN_0053d520.
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

void __thiscall FUN_0053d520(int param_1,float *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  float *pfVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  

  if (*(int *)(param_1 + -0x48) == 0) {

    FUN_00513290(param_2);

  }

  else {

    iVar3 = *(int *)(*(int *)(param_1 + -0x48) + 0x3c);

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x34 + param_1);

    *puVar1 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xb0);

    puVar1[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xb4);

    puVar1[2] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xb8);

    puVar1[3] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0xbc);

    iVar3 = *(int *)(*(int *)(param_1 + -0x4c) + 4);

    pfVar2 = (float *)(iVar3 + 0x34 + param_1);

    *pfVar2 = *(float *)(iVar3 + 0x34 + param_1) - *param_2;

    pfVar2[1] = pfVar2[1] - param_2[1];

    pfVar2[2] = pfVar2[2] - param_2[2];

    pfVar2[3] = pfVar2[3] - param_2[3];

    iVar3 = *(int *)(*(int *)(param_1 + -0x4c) + 4);

    iVar4 = *(int *)(param_1 + -0x48);

    pcVar5 = (char *)FUN_005070b0(&param_2);

    if ((*pcVar5 == '\0') && (*(int *)(iVar4 + 0x44) != 0)) {

      FUN_005070d0();

    }

    if ((*(char *)(iVar4 + 0x40) == '\0') || (*(int *)(iVar4 + 8) == 0)) {

      (**(code **)(**(int **)(iVar4 + 0x3c) + 0x40))(iVar3 + 0x34 + param_1);

    }

  }

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x4c + param_1) + 0x144))();

  return;

}
