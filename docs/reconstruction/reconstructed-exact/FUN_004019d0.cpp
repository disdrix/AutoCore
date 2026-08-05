// =============================================================================
// FUN_004019d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004019d0
// Address:   0x004019d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004019d0 @ 0x004019d0
// Stable ID: aa_004019d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004019d0, exception::exception.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x004019d0; evidence only — no invented semantics):
//  - Entry: `exception * __thiscall FUN_004019d0(exception *param_1,exception *param_2)`.
//  - Returns (1 site(s)): `param_1`.
//  - Assign `local_4 = 0xffffffff`.
//  - Assign `local_c = ExceptionList`.
//  - Assign `local_4 = 0`.
//  - Assign `param_1 = &PTR_FUN_009c7628`.




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

exception * __thiscall FUN_004019d0(exception *param_1,exception *param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bc1d5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  exception::exception(param_1,param_2);

  local_4 = 0;

  *(undefined ***)param_1 = &PTR_FUN_009c7628;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_1 + 0xc),

             (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_2 + 0xc));

  ExceptionList = local_c;

  return param_1;

}
