// =============================================================================
// FUN_0055df80
// -----------------------------------------------------------------------------
// Stable ID: aa_0055df80
// Address:   0x0055df80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055df80 @ 0x0055df80
// Stable ID: aa_0055df80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0055df80.
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

void __thiscall FUN_0055df80(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = *param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = param_2[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8) = param_2[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xec) = param_2[3];

  return;

}
