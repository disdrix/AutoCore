// =============================================================================
// FUN_005a32a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a32a0
// Address:   0x005a32a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a32a0 @ 0x005a32a0
// Stable ID: aa_005a32a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: BitStream_writeBits×3, CONCAT22×3, FUN_00424e10, FUN_005a32a0, FUN_00996f40.
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

void __thiscall FUN_005a32a0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t extraout_var_01;

  

  uVar1 = param_2;

  FUN_00424e10(*(uint32_t /* width from decompiler */ *)(param_1 + 8));

  param_2 = CONCAT22(extraout_var_00,*(uint16_t *)(param_1 + 0xc));

  BitStream_writeBits(0x10,&param_2);

  param_2 = CONCAT22(extraout_var,*(uint16_t *)(param_1 + 0xe));

  BitStream_writeBits(0x10,&param_2);

  param_2 = CONCAT22(extraout_var_01,*(uint16_t *)(param_1 + 0x10));

  BitStream_writeBits(0x10,&param_2);

  FUN_00996f40(uVar1,param_1 + 0x14);

  return;

}
