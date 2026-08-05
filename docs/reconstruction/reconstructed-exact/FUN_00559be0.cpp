// =============================================================================
// FUN_00559be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00559be0
// Address:   0x00559be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00559be0 @ 0x00559be0
// Stable ID: aa_00559be0
// Embedded strings (evidence for future rename):
//   - "%s_%s_%s.ved"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00559be0, _snprintf.
//  - Strings: "%s_%s_%s.ved".
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

void FUN_00559be0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,

                 basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                 *param_4)



{

  char local_104 [259];

  uint8_t local_1;

  

  _snprintf(local_104,0x103,"%s_%s_%s.ved",param_1,param_2,param_3);

  local_1 = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::assign

            (param_4,local_104);

  return;

}
