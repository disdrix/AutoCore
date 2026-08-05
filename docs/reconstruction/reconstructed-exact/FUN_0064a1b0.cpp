// =============================================================================
// FUN_0064a1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0064a1b0
// Address:   0x0064a1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064a1b0 @ 0x0064a1b0
// Stable ID: aa_0064a1b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00649f50, FUN_0064a1b0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0064a1b0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ extraout_ECX;

  

  uVar5 = DAT_00aaab08;

  uVar4 = DAT_00aaaad0;

  uVar3 = DAT_00aaa690;

  uVar2 = DAT_00a0f718;

  fVar1 = g_flOne;

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_LAB_009e4944;

  param_1[0x18] = 0;

  param_1[0x19] = uVar4;

  param_1[0x1a] = uVar5;

  param_1[0x1b] = 0;

  param_1[0x1f] = 0;

  param_1[0x1e] = 0;

  param_1[0x1d] = 0;

  param_1[0x1c] = 0;

  param_1[0x20] = fVar1;

  param_1[0x21] = 0;

  param_1[0x22] = uVar2;

  param_1[0x23] = uVar3;

  param_1[0x24] = 0;

  param_1[0x25] = uVar4;

  param_1[0x26] = uVar5;

  param_1[0x27] = 0;

  param_1[0x2b] = 0;

  param_1[0x2a] = 0;

  param_1[0x29] = 0;

  param_1[0x28] = 0;

  param_1[0x2c] = fVar1;

  param_1[0x2d] = 0;

  param_1[0x2e] = uVar2;

  param_1[0x2f] = uVar3;

  FUN_00649f50(param_2);

  return extraout_ECX;

}
