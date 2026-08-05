// =============================================================================
// FUN_00614a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00614a90
// Address:   0x00614a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00614a90 @ 0x00614a90
// Stable ID: aa_00614a90
// Embedded strings (evidence for future rename):
//   - "conversion_percent] (improvement %%)\n"
//   - "op_scalar_1] (max applications))\n"
//   - "op_scalar_2] (max duration)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_005781b0×3, FUN_00578190, FUN_0058b6d0, FUN_00614a90.
//  - Strings: "conversion_percent] (improvement %%)\n"; "op_scalar_1] (max applications))\n"; "op_scalar_2] (max duration)\n".
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

void FUN_00614a90(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  if (*(float *)(param_1 + 0xe0) != g_flZero) {

    FUN_005781b0(param_3,param_2,"conversion_percent] (improvement %%)\n",1);

  }

  if (*(float *)(param_1 + 0x160) != g_flZero) {

    FUN_005781b0(param_3,param_2,"op_scalar_1] (max applications))\n",1);

  }

  if (*(float *)(param_1 + 0x164) != g_flZero) {

    FUN_005781b0(param_3,param_2,"op_scalar_2] (max duration)\n",1);

  }

  if ((*(byte *)(param_1 + 0x625) & 4) != 0) {

    FUN_0058b6d0(param_1,param_2,param_3);

  }

  FUN_00578190(param_1,param_2,param_3);

  return;

}
