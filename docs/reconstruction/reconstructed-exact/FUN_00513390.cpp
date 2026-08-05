// =============================================================================
// FUN_00513390
// -----------------------------------------------------------------------------
// Stable ID: aa_00513390
// Address:   0x00513390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00513390 @ 0x00513390
// Stable ID: aa_00513390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_004bb970, FUN_00513390.
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

void __fastcall FUN_00513390(int param_1)



{

  FUN_004bb970(CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x164) >> 8),

                        *(uint8_t *)(param_1 + 0x168)),*(uint32_t /* width from decompiler */ *)(param_1 + 0x160),

               *(uint32_t /* width from decompiler */ *)(param_1 + 0x164));

  return;

}
