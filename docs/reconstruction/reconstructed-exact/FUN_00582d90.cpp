// =============================================================================
// FUN_00582d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00582d90
// Address:   0x00582d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00582d90 @ 0x00582d90
// Stable ID: aa_00582d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004e88e0, FUN_00513290, FUN_00582d90.
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

void __thiscall FUN_00582d90(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  float *pfVar2;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if (*(int *)(param_1 + -0x88) == 0) {

    FUN_00513290(param_2);

  }

  else {

    FUN_004e88e0(&local_18,param_2);

    if (*(int **)(param_1 + -0x88) == (int *)0x0) {

      pfVar2 = (float *)&DAT_00d1a6c0;

    }

    else {

      iVar1 = (**(code **)(**(int **)(param_1 + -0x88) + 0xc))();

      pfVar2 = (float *)(iVar1 + 0x90);

    }

    local_18 = *pfVar2 - local_18;

    local_14 = pfVar2[1] - local_14;

    local_10 = pfVar2[2] - local_10;

    local_c = local_18;

    local_8 = local_14;

    local_4 = local_10;

    iVar1 = (**(code **)(**(int **)(param_1 + -0x88) + 0x10))(3);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc) = 0xffffffff;

    *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;

    *(float *)(iVar1 + 0x90) = local_18;

    *(float *)(iVar1 + 0x94) = local_14;

    *(float *)(iVar1 + 0x98) = local_10;

  }

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) + 0x144))();

  return;

}
