// =============================================================================
// FUN_004d10d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d10d0
// Address:   0x004d10d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d10d0 @ 0x004d10d0
// Stable ID: aa_004d10d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005a58c0×3, FUN_0076f5f0×3, FUN_0043f210, FUN_004d10d0, FUN_0076e240.
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

float10 __thiscall FUN_004d10d0(int param_1,float *param_2,int param_3)



{

  float *pfVar1;

  float10 fVar2;

  uint32_t /* width from decompiler */ local_24;

  float local_20;

  uint32_t /* width from decompiler */ local_1c;

  float local_18;

  float local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  pfVar1 = param_2;

  if (*(int *)(param_1 + 0xe4e0) == 0) {

    param_2 = (float *)0x0;

  }

  else {

    fVar2 = (float10)FUN_005a58c0(*param_2,param_2[2]);

    param_2 = (float *)(float)fVar2;

  }

  if (*(int *)(param_1 + 0xe4e0) == 0) {

    local_14 = 0.0;

  }

  else {

    fVar2 = (float10)FUN_005a58c0(*pfVar1 + g_flOne,pfVar1[2]);

    local_14 = (float)fVar2;

  }

  local_14 = local_14 - (float)param_2;

  local_18 = g_flOne;

  local_10 = 0;

  FUN_0076f5f0(&local_18,&local_18);

  if (*(int *)(param_1 + 0xe4e0) == 0) {

    fVar2 = (float10)0.0;

  }

  else {

    fVar2 = (float10)FUN_005a58c0(*pfVar1,pfVar1[2] + g_flOne);

  }

  local_20 = (float)(fVar2 - (float10)(float)param_2);

  local_24 = 0;

  local_1c = 0x3f800000;

  FUN_0076f5f0(&local_24,&local_24);

  FUN_0076e240(&local_c,&local_24,&local_18);

  FUN_0076f5f0(&local_c,&local_c);

  FUN_0043f210(local_18,local_14,local_10,*(uint32_t /* width from decompiler */ *)(param_3 + 0xc),local_c,local_8,local_4,

               *(uint32_t /* width from decompiler */ *)(param_3 + 0x1c),local_24,local_20,local_1c,

               *(uint32_t /* width from decompiler */ *)(param_3 + 0x2c),*(uint32_t /* width from decompiler */ *)(param_3 + 0x30),

               *(uint32_t /* width from decompiler */ *)(param_3 + 0x34),*(uint32_t /* width from decompiler */ *)(param_3 + 0x38),

               *(uint32_t /* width from decompiler */ *)(param_3 + 0x3c));

  return (float10)(float)param_2;

}
