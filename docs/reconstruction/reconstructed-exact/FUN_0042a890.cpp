// =============================================================================
// FUN_0042a890
// -----------------------------------------------------------------------------
// Stable ID: aa_0042a890
// Address:   0x0042a890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042a890 @ 0x0042a890
// Stable ID: aa_0042a890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0042a890.
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

uint32_t /* width from decompiler */ * __thiscall

FUN_0042a890(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_1,

            uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint8_t param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bc231;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  puVar1 = operator_new(0x30);

  local_8 = 1;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1[1] = param_3;

    *puVar1 = param_2;

    puVar1[2] = param_4;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               (puVar1 + 3),param_1);

    puVar1[10] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

    *(uint8_t *)(puVar1 + 0xb) = param_5;

    *(uint8_t *)((int)puVar1 + 0x2d) = 0;

  }

  ExceptionList = local_10;

  return puVar1;

}
