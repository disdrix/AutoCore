// =============================================================================
// FUN_004018f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004018f0
// Address:   0x004018f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004018f0 @ 0x004018f0
// Stable ID: aa_004018f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004018f0, exception.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x004018f0; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_004018f0(exception *param_1)`.
//  - Returns (1 site(s)): `void`.
//  - Assign `local_c = ExceptionList`.
//  - Assign `param_1 = &PTR_FUN_009c7628`.
//  - Assign `local_4 = 0`.
//  - Assign `local_4 = 0xffffffff`.




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

void __fastcall FUN_004018f0(exception *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bc1d5;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(undefined ***)param_1 = &PTR_FUN_009c7628;

  local_4 = 0;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_1 + 0xc));

  local_4 = 0xffffffff;

  exception::~exception(param_1);

  ExceptionList = local_c;

  return;

}
