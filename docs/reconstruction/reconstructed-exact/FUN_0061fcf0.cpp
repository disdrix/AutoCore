// =============================================================================
// FUN_0061fcf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0061fcf0
// Address:   0x0061fcf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0061fcf0 @ 0x0061fcf0
// Stable ID: aa_0061fcf0
// Embedded strings (evidence for future rename):
//   - "virus decays)\n"
//   - "op_scalar_2] (max virus jumps)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005781b0×2, FUN_0061a370, FUN_0061fcf0.
//  - Strings: "virus decays)\n"; "op_scalar_2] (max virus jumps)\n".
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

void FUN_0061fcf0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  if (*(float *)(param_1 + 0x160) != g_flZero) {

    FUN_005781b0(param_3,param_2,"virus decays)\n",0);

  }

  if (*(float *)(param_1 + 0x164) != g_flZero) {

    FUN_005781b0(param_3,param_2,"op_scalar_2] (max virus jumps)\n",1);

  }

  FUN_0061a370(param_1,param_2,param_3);

  return;

}
