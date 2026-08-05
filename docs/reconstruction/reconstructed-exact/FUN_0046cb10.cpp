// =============================================================================
// FUN_0046cb10
// -----------------------------------------------------------------------------
// Stable ID: aa_0046cb10
// Address:   0x0046cb10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046cb10 @ 0x0046cb10
// Stable ID: aa_0046cb10
// Embedded strings (evidence for future rename):
//   - "list<T> too long"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00401a40, FUN_0046cb10, _CxxThrowException.
//  - Strings: "list<T> too long".
//  - Return sites: 2.

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

void __fastcall FUN_0046cb10(uint param_1,int param_2)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bc919;

  local_c = ExceptionList;

  if (0xfffffffU - *(int *)(param_2 + 8) < param_1) {

    ExceptionList = &local_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_50,"list<T> too long");

    local_4 = 0;

    FUN_00401a40(local_50);

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_34,(ThrowInfo *)&DAT_00acc388);

  }

  *(uint *)(param_2 + 8) = *(int *)(param_2 + 8) + param_1;

  return;

}
