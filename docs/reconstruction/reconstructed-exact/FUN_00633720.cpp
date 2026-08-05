// =============================================================================
// FUN_00633720
// -----------------------------------------------------------------------------
// Stable ID: aa_00633720
// Address:   0x00633720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00633720 @ 0x00633720
// Stable ID: aa_00633720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00633720, _vsnprintf.
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

void FUN_00633720(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  *param_1,char *param_2)



{

  char local_200 [512];

  

  _vsnprintf(local_200,0x200,param_2,&stack0x0000000c);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_1,local_200);

  return;

}
