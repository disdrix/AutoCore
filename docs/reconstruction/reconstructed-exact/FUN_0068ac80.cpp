// =============================================================================
// FUN_0068ac80
// -----------------------------------------------------------------------------
// Stable ID: aa_0068ac80
// Address:   0x0068ac80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068ac80 @ 0x0068ac80
// Stable ID: aa_0068ac80
// Embedded strings (evidence for future rename):
//   - "cannot MakeInstance() after calling DeleteTransientData()"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CONCAT31, DeleteTransientData, FUN_0068aa10, FUN_0068ac80, MakeInstance.
//  - Strings: "cannot MakeInstance() after calling DeleteTransientData()".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_0068ac80(int *param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009aa25d;

  local_10 = ExceptionList;

  local_8 = 0;

  if (*(char *)(*param_1 + 0x21) == '\0') {

    ExceptionList = &local_10;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00d08e78,"cannot MakeInstance() after calling DeleteTransientData()");

    ExceptionList = local_10;

    return 0;

  }

  ExceptionList = &local_10;

  pvVar1 = operator_new(0x9c);

  local_8 = CONCAT31(local_8._1_3_,1);

  if (pvVar1 != (void *)0x0) {

    uVar2 = FUN_0068aa10(param_1);

    ExceptionList = local_10;

    return uVar2;

  }

  ExceptionList = local_10;

  return 0;

}
