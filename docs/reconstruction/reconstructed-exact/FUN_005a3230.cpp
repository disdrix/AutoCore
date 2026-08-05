// =============================================================================
// FUN_005a3230
// -----------------------------------------------------------------------------
// Stable ID: aa_005a3230
// Address:   0x005a3230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a3230 @ 0x005a3230
// Stable ID: aa_005a3230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: BitStream_readBits×3, FUN_00424e30, FUN_005a3230, FUN_00996e70.
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

void __thiscall FUN_005a3230(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  

  uVar1 = param_2;

  FUN_00424e30(param_1 + 8);

  BitStream_readBits(0x10,&param_2);

  *(uint16_t *)(param_1 + 0xc) = (uint16_t)param_2;

  BitStream_readBits(0x10,&param_2);

  *(uint16_t *)(param_1 + 0xe) = (uint16_t)param_2;

  BitStream_readBits(0x10,&param_2);

  *(uint16_t *)(param_1 + 0x10) = (uint16_t)param_2;

  FUN_00996e70(uVar1,param_1 + 0x14);

  return;

}
