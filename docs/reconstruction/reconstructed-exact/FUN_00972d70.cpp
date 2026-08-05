// =============================================================================
// FUN_00972d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00972d70
// Address:   0x00972d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00972d70 @ 0x00972d70
// Stable ID: aa_00972d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~8 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076e3c0, FUN_00972d70.
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

void __thiscall FUN_00972d70(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int extraout_ECX;

  

  FUN_0076e3c0(param_1 + 0x80,param_2,param_3,param_4);

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0xbc) = 0xffffffff;

  *(int *)(extraout_ECX + 0xb4) = *(int *)(extraout_ECX + 0xb4) + 1;

  return;

}
