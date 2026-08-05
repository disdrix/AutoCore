// =============================================================================
// FUN_00649e70
// -----------------------------------------------------------------------------
// Stable ID: aa_00649e70
// Address:   0x00649e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00649e70 @ 0x00649e70
// Stable ID: aa_00649e70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00649e70.
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

void __fastcall FUN_00649e70(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  uVar5 = DAT_00aaab08;

  uVar4 = DAT_00aaaad0;

  uVar3 = DAT_00aaa690;

  uVar2 = DAT_00a0f718;

  fVar1 = g_flOne;

  param_1[0xc] = 0;

  param_1[0xd] = uVar4;

  param_1[0xe] = uVar5;

  param_1[0xf] = 0;

  param_1[0x13] = 0;

  param_1[0x12] = 0;

  param_1[0x11] = 0;

  param_1[0x10] = 0;

  param_1[0x14] = fVar1;

  param_1[0x15] = 0;

  param_1[0x16] = uVar2;

  param_1[0x17] = uVar3;

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

  *param_1 = 0;

  param_1[1] = fVar1;

  param_1[8] = 0;

  param_1[9] = fVar1;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = fVar1;

  param_1[7] = 0;

  return;

}
