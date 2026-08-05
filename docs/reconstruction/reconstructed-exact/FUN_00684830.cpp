// =============================================================================
// FUN_00684830
// -----------------------------------------------------------------------------
// Stable ID: aa_00684830
// Address:   0x00684830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00684830 @ 0x00684830
// Stable ID: aa_00684830
// Embedded strings (evidence for future rename):
//   - "%d.%d.%d.%d%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: sprintf×2, FUN_00684830.
//  - Strings: ":%d"; "%d.%d.%d.%d%s".
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

basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

FUN_00684830(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,

            uint param_2,ushort param_3)



{

  char local_114 [12];

  uint32_t /* width from decompiler */ local_108;

  char local_104 [260];

  

  local_108 = 0;

  if (param_3 == 0) {

    local_114[0] = '\0';

  }

  else {

    sprintf(local_114,":%d",(uint)param_3);

  }

  sprintf(local_104,"%d.%d.%d.%d%s",param_2 >> 0x18,param_2 >> 0x10 & 0xff,param_2 >> 8 & 0xff,

          param_2 & 0xff,local_114);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(param_1,local_104);

  return param_1;

}
