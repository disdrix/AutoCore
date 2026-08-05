// =============================================================================
// FUN_00752a80
// -----------------------------------------------------------------------------
// Stable ID: aa_00752a80
// Address:   0x00752a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00752a80 @ 0x00752a80
// Stable ID: aa_00752a80
// Embedded strings (evidence for future rename):
//   - "Opaque"
//   - "AlphaTestEnable"
//   - "Alpha_Test"
//   - "Translucent"
//   - "UseRealAlpha"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, goto×1.
//  - Notable callees: FUN_00752370×2, FUN_00746210, FUN_007522a0, FUN_007524b0, FUN_00752a00, FUN_00752a80.
//  - Strings: "Opaque"; "AlphaTestEnable"; "Alpha_Test"; "Translucent".
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

void __fastcall FUN_00752a80(int param_1)



{

  bool bVar1;

  int local_30;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009acbfa;

  local_c = ExceptionList;

  if (*(short *)(param_1 + 0x1c) < 0) {

    return;

  }

  ExceptionList = &local_c;

  FUN_00746210(local_28,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c));

  local_4 = 0;

  bVar1 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                    (local_28,"Opaque");

  if (bVar1) {

    local_30 = 0;

    FUN_00752370(&local_2c,"AlphaTestEnable");

    if ((-1 < local_2c) && (FUN_007524b0(local_2c,&local_30), local_30 != 0)) {

      FUN_007522a0("Alpha_Test");

    }

  }

  bVar1 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                    (local_28,"Translucent");

  if (bVar1) {

    local_30 = 1;

  }

  else {

    bVar1 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (local_28,"Opaque");

    if (!bVar1) goto LAB_00752b7b;

    local_30 = 0;

  }

  FUN_00752370(&local_2c,"UseRealAlpha");

  if (-1 < local_2c) {

    FUN_00752a00(local_2c,&local_30);

  }

LAB_00752b7b:

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  ExceptionList = local_c;

  return;

}
