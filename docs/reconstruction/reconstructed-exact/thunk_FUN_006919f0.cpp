// =============================================================================
// thunk_FUN_006919f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006933b0
// Address:   0x006933b0  (autoassault.exe, image base 0x400000)
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

void __fastcall thunk_FUN_006919f0(int param_1)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;
  
  this = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
          (param_1 + 4);
  if (this == (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)0x0) {
    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;
    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;
    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;
    return;
  }
  pbVar1 = *(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> **)
            (param_1 + 8);
  for (; this != pbVar1; this = this + 0x2c) {
    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(this);
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(*(void **)(param_1 + 4));
}
