// =============================================================================
// FUN_005753c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005753c0
// Address:   0x005753c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005753c0 @ 0x005753c0
// Stable ID: aa_005753c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005750e0, FUN_005753c0.
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

void FUN_005753c0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  FUN_005750e0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + param_1),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1));

  return;

}
