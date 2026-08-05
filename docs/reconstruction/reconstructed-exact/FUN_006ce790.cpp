// =============================================================================
// FUN_006ce790
// -----------------------------------------------------------------------------
// Stable ID: aa_006ce790
// Address:   0x006ce790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ce790 @ 0x006ce790
// Stable ID: aa_006ce790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006ce790, FUN_006cec60.
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

int __fastcall FUN_006ce790(int param_1)



{

  FUN_006cec60();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = 0x80000000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0x3d4ccccd;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0xc;

  return param_1;

}
