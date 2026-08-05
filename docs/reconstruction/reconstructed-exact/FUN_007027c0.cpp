// =============================================================================
// FUN_007027c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007027c0
// Address:   0x007027c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007027c0 @ 0x007027c0
// Stable ID: aa_007027c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007022b0, FUN_007025b0, FUN_007027c0.
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

uint32_t /* width from decompiler */ __thiscall

FUN_007027c0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *local_1a0;

  uint8_t *local_19c;

  uint32_t /* width from decompiler */ local_198;

  int local_194;

  uint8_t local_190 [400];

  

  iVar1 = *(int *)(param_1 + 0x2104);

  *(int *)(param_1 + 0x2104) = iVar1 + 1;

  local_1a0 = (uint32_t /* width from decompiler */ *)(iVar1 * 0x20 + *(int *)(param_1 + 0x2100));

  *local_1a0 = *param_4;

  local_1a0[1] = param_4[1];

  local_1a0[2] = param_4[2];

  local_1a0[3] = param_4[3];

  local_1a0[4] = 0;

  local_198 = 0;

  local_19c = local_190;

  local_194 = -0x7fffff9c;

  FUN_007022b0(&local_19c,param_2);

  uVar2 = FUN_007025b0(&local_19c,param_2,param_3,&local_1a0);

  if (-1 < local_194) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_19c,local_194 << 2,0x12);

  }

  return uVar2;

}
