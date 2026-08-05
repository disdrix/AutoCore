// =============================================================================
// FUN_00687150
// -----------------------------------------------------------------------------
// Stable ID: aa_00687150
// Address:   0x00687150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00687150 @ 0x00687150
// Stable ID: aa_00687150
// Embedded strings (evidence for future rename):
//   - "SetLodLevel() expects a value in the range of 0.0 to 1.0"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00687150, SetLodLevel.
//  - Strings: "SetLodLevel() expects a value in the range of 0.0 to 1.0".
//  - Return sites: 3.

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

void __thiscall FUN_00687150(int *param_1,float param_2)



{

  if ((g_flZero <= param_2) && (param_2 < g_flOne != (param_2 == g_flOne))) {

    if (param_1[0xd] != 0) {

      *(float *)(param_1[0xd] + 0x10) = param_2;

      return;

    }

    *(float *)(*param_1 + 0x14) = param_2;

    return;

  }

                    /* WARNING: Could not recover jumptable at 0x0068719c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             &DAT_00d08e78,"SetLodLevel() expects a value in the range of 0.0 to 1.0");

  return;

}
