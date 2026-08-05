// =============================================================================
// FUN_00711350
// -----------------------------------------------------------------------------
// Stable ID: aa_00711350
// Address:   0x00711350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00711350 @ 0x00711350
// Stable ID: aa_00711350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00711350, FUN_00712d70, FUN_00713390, FUN_007133f0, FUN_00713450, FUN_00713480, FUN_00713510.
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

void FUN_00711350(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  float10 fVar3;

  

  puVar1 = (uint32_t /* width from decompiler */ *)(param_3 + 0xc);

  uVar2 = FUN_00713480(*(uint32_t /* width from decompiler */ *)(param_2 + 0x38),*(uint32_t /* width from decompiler */ *)(param_3 + 4),

                       *(uint32_t /* width from decompiler */ *)(param_3 + 0xc));

  param_1[1] = uVar2;

  FUN_00713510(uVar2,*(uint32_t /* width from decompiler */ *)(param_2 + 0x38),param_3 + 4,puVar1);

  uVar2 = FUN_007133f0(*(uint32_t /* width from decompiler */ *)(param_3 + 8));

  param_1[2] = uVar2;

  fVar3 = (float10)FUN_00713450(uVar2);

  *(float *)(param_3 + 8) = (float)fVar3;

  uVar2 = FUN_00713390(*(uint32_t /* width from decompiler */ *)(param_3 + 0x10));

  *param_1 = uVar2;

  FUN_00712d70(param_3 + 0x14,param_1 + 3,0xc,*puVar1);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x38) = *puVar1;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_3 + 8);

  return;

}
