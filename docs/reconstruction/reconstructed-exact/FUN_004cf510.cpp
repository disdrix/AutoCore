// =============================================================================
// FUN_004cf510
// -----------------------------------------------------------------------------
// Stable ID: aa_004cf510
// Address:   0x004cf510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004cf510 @ 0x004cf510
// Stable ID: aa_004cf510
// Embedded strings (evidence for future rename):
//   - "Map:%s (%d) \r\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004cf510, _snprintf, s.
//  - Strings: "Map:%s (%d) \r\n".
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

void __thiscall

FUN_004cf510(int param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)



{

  char local_400 [1024];

  

  _snprintf(local_400,0x400,"Map:%s (%d) \r\n",param_1 + 0xb4,*(uint32_t /* width from decompiler */ *)(param_1 + 0xfc));

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_2,local_400);

  return;

}
