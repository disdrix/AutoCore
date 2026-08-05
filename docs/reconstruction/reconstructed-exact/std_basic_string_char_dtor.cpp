// =============================================================================
// std_basic_string_char_dtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00690450
// Address:   0x00690450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this)

{
                    /* WARNING: Could not recover jumptable at 0x00690450. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(this);
  return;
}
