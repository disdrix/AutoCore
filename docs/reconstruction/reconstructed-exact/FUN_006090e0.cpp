// =============================================================================
// FUN_006090e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006090e0
// Address:   0x006090e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006090e0 @ 0x006090e0
// Stable ID: aa_006090e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005cb520, FUN_006090e0.
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

void __thiscall FUN_006090e0(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  FUN_005cb520(param_2,param_3,param_4);

  if ((param_2 != 0) && (param_3 == 2)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x20) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xd8);

    *(uint32_t /* width from decompiler */ *)(param_1 + -0x1c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xdc);

  }

  return;

}
