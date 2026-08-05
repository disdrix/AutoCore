// =============================================================================
// FUN_007afcf0
// -----------------------------------------------------------------------------
// Stable ID: aa_007afcf0
// Address:   0x007afcf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007afcf0 @ 0x007afcf0
// Stable ID: aa_007afcf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0076f5f0×2, FUN_0040d1a0, FUN_0076df50, FUN_007afcf0, fcos, fsin.
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

void __fastcall FUN_007afcf0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ extraout_EDX;

  float10 fVar2;

  float10 fVar3;

  uint32_t /* width from decompiler */ uVar4;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if ((*(int *)(param_1 + 0x298) != 0) && (*(float *)(param_1 + 0x13c) != g_flZero)) {

    FUN_0076f5f0(param_1 + 0x240,param_1 + 0x240);

    FUN_0076f5f0(&local_1c,extraout_EDX);

    fVar2 = (float10)*(float *)(param_1 + 0x13c) * (float10)DAT_00a0f298;

    fVar3 = (float10)fsin(fVar2);

    uVar4 = 3;

    local_10 = (float)((float10)local_1c * fVar3);

    local_c = (float)((float10)local_18 * fVar3);

    local_8 = (float)((float10)local_14 * fVar3);

    fVar2 = (float10)fcos(fVar2);

    local_4 = (float)fVar2;

    (**(code **)(**(int **)(param_1 + 0x298) + 0x10))(3,&local_10);

    FUN_0040d1a0(uVar4);

    iVar1 = (**(code **)(**(int **)(param_1 + 0x298) + 0x10))(3);

    FUN_0076df50(iVar1 + 0x80,iVar1 + 0x80,&local_18);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc) = 0xffffffff;

    *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;

  }

  return;

}
