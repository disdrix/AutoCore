// =============================================================================
// FUN_00507420
// -----------------------------------------------------------------------------
// Stable ID: aa_00507420
// Address:   0x00507420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00507420 @ 0x00507420
// Stable ID: aa_00507420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00507420, FUN_005f5760.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00507420(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint8_t uVar1;

  uint16_t uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  FUN_005f5760(param_2);

  uVar3 = DAT_00a0f298;

  *param_1 = &PTR_FUN_009cd9b0;

  param_1[0x13] = uVar3;

  param_1[0x14] = DAT_00a0f720;

  param_1[0x1a] = 0x80000001;

  param_1[0x18] = param_1 + 0x1b;

  param_1[0x19] = 0;

  param_1[0x1c] = 0;

  param_1[0x1d] = 0;

  param_1[0x1e] = 0x80000000;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  param_1[0x21] = 0x80000000;

  param_1[0x22] = 0;

  param_1[0x23] = 0;

  param_1[0x24] = 0x80000000;

  param_1[0x25] = 0;

  param_1[0x26] = 0;

  param_1[0x27] = 0x80000000;

  param_1[0xb] = param_1;

  uVar1 = *(uint8_t *)(param_2 + 0x18);

  param_1[0x11] = 0;

  *(uint8_t *)(param_1 + 0x10) = 0;

  *(uint8_t *)(param_1 + 0x12) = uVar1;

  uVar2 = *(uint16_t *)(param_2 + 0x1a);

  param_1[0x15] = 0;

  *(uint16_t *)(param_1 + 0x17) = uVar2;

  param_1[0x16] = 0xffffffff;

  return param_1;

}
