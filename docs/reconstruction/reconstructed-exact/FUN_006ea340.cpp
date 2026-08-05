// =============================================================================
// FUN_006ea340
// -----------------------------------------------------------------------------
// Stable ID: aa_006ea340
// Address:   0x006ea340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ea340 @ 0x006ea340
// Stable ID: aa_006ea340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063a3f0, FUN_006ea340.
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

void FUN_006ea340(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  uint8_t local_50 [76];

  

  FUN_0063a3f0(*(int *)(param_2 + 8) + 0x20,param_1[2] + 0x20);

  (**(code **)(*(int *)*param_1 + 0x18))(local_50,*(uint32_t /* width from decompiler */ *)(param_3 + 8),param_4);

  return;

}
