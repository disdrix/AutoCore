// =============================================================================
// FUN_00626400
// -----------------------------------------------------------------------------
// Stable ID: aa_00626400
// Address:   0x00626400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00626400 @ 0x00626400
// Stable ID: aa_00626400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00578390, FUN_00626400, FUN_007971b0.
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

uint32_t /* width from decompiler */ __thiscall FUN_00626400(int param_1,int param_2)



{

  *(uint8_t *)(param_2 + 0x21) = 0x1a;

  *(uint8_t *)(param_2 + 0x38) = *(uint8_t *)(param_1 + 0x6c8);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d0);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x40) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x44) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x6d8);

  FUN_007971b0(param_1 + 0x6e0);

  FUN_00578390(param_2);

  return 0x58;

}
