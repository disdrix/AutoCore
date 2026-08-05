// =============================================================================
// FUN_006c7d30
// -----------------------------------------------------------------------------
// Stable ID: aa_006c7d30
// Address:   0x006c7d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c7d30 @ 0x006c7d30
// Stable ID: aa_006c7d30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006c7d30, FUN_006cec60.
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

int __fastcall FUN_006c7d30(int param_1)



{

  FUN_006cec60();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0x3f800000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0xbf800000;

  return param_1;

}
