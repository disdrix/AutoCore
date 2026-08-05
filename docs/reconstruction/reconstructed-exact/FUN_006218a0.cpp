// =============================================================================
// FUN_006218a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006218a0
// Address:   0x006218a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006218a0 @ 0x006218a0
// Stable ID: aa_006218a0
// Embedded strings (evidence for future rename):
//   - "num_targets] (max charges stored)\n"
//   - "op_scalar_2] (percent discharged)\n"
//   - "op_scalar_3] (charge conversion percent)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005781b0×3, FUN_0058b640, FUN_00621600, FUN_006218a0.
//  - Strings: "num_targets] (max charges stored)\n"; "op_scalar_2] (percent discharged)\n"; "op_scalar_3] (charge conversion percent)\n".
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

void FUN_006218a0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  FUN_005781b0(param_3,param_2,"num_targets] (max charges stored)\n",1);

  FUN_005781b0(param_3,param_2,"op_scalar_2] (percent discharged)\n",1);

  FUN_005781b0(param_3,param_2,"op_scalar_3] (charge conversion percent)\n",1);

  FUN_0058b640(param_1,param_2,param_3);

  FUN_00621600(param_1,param_2,param_3);

  return;

}
