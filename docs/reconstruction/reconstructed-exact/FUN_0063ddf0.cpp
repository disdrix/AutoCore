// =============================================================================
// FUN_0063ddf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0063ddf0
// Address:   0x0063ddf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063ddf0 @ 0x0063ddf0
// Stable ID: aa_0063ddf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0063d7d0, FUN_0063ddf0.
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

void __thiscall FUN_0063ddf0(int param_1,float *param_2,float *param_3)



{

  int extraout_ECX;

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  fVar3 = *param_2;

  fVar1 = *(float *)(param_1 + 0x2c) * fVar3;

  *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0xf0) * fVar1 + *(float *)(param_1 + 0x40);

  *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0xf4) * fVar1 + *(float *)(param_1 + 0x44);

  *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0xf8) * fVar1 + *(float *)(param_1 + 0x48);

  *(float *)(param_1 + 0x4c) = *(float *)(param_1 + 0xfc) * fVar1 + *(float *)(param_1 + 0x4c);

  fVar1 = g_flOne;

  fVar4 = 0.0;

  *(float *)(param_1 + 0x40) = *param_3 * fVar3 + *(float *)(param_1 + 0x40);

  *(float *)(param_1 + 0x44) = param_3[1] * fVar3 + *(float *)(param_1 + 0x44);

  *(float *)(param_1 + 0x48) = param_3[2] * fVar3 + *(float *)(param_1 + 0x48);

  *(float *)(param_1 + 0x4c) = param_3[3] * fVar3 + *(float *)(param_1 + 0x4c);

  fVar2 = fVar1 - *(float *)(param_1 + 0x14) * fVar3;

  if (fVar2 < 0.0) {

    fVar2 = 0.0;

  }

  *(float *)(param_1 + 0x40) = fVar2 * *(float *)(param_1 + 0x40);

  *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0x44) * fVar2;

  *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x48) * fVar2;

  *(float *)(param_1 + 0x4c) = *(float *)(param_1 + 0x4c) * fVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf0) = 0;

  if (*(float *)(param_1 + 0x10c) != 0.0) {

    local_14 = *param_2;

    local_20 = *(float *)(param_1 + 0x100) * local_14;

    local_1c = *(float *)(param_1 + 0x104) * local_14;

    local_18 = *(float *)(param_1 + 0x108) * local_14;

    local_14 = *(float *)(param_1 + 0x10c) * local_14;

    FUN_0063d7d0(&local_20);

    fVar1 = g_flOne;

    *(float *)(extraout_ECX + 0x10c) = fVar4;

    *(float *)(extraout_ECX + 0x108) = fVar4;

    *(float *)(extraout_ECX + 0x104) = fVar4;

    *(float *)(extraout_ECX + 0x100) = fVar4;

    param_1 = extraout_ECX;

  }

  fVar1 = fVar1 - *(float *)(param_1 + 0x18) * fVar3;

  if (fVar1 < fVar4) {

    fVar1 = fVar4;

  }

  *(float *)(param_1 + 0x50) = *(float *)(param_1 + 0x50) * fVar1;

  *(float *)(param_1 + 0x54) = *(float *)(param_1 + 0x54) * fVar1;

  *(float *)(param_1 + 0x58) = *(float *)(param_1 + 0x58) * fVar1;

  *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x5c) * fVar1;

  return;

}
