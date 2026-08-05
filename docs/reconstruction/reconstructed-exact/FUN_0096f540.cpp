// =============================================================================
// FUN_0096f540
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f540
// Address:   0x0096f540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096f540 @ 0x0096f540
// Stable ID: aa_0096f540
// Embedded strings (evidence for future rename):
//   - "Opaque"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00746210, FUN_0096f540.
//  - Strings: "Opaque".
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

uint8_t __fastcall FUN_0096f540(int *param_1)



{

  bool bVar1;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac22d;

  local_c = ExceptionList;

  if (*(char *)((int)param_1 + 6) == '\0') {

    ExceptionList = &local_c;

    FUN_00746210(local_28,*(uint32_t /* width from decompiler */ *)(*param_1 + 0x1c));

    local_4 = 0;

    bVar1 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (local_28,"Opaque");

    *(bool *)((int)param_1 + 5) = bVar1;

    *(uint8_t *)((int)param_1 + 6) = 1;

    local_4 = 0xffffffff;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

  ExceptionList = local_c;

  return *(uint8_t *)((int)param_1 + 5);

}
