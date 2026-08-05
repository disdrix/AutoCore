// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00821570
// -----------------------------------------------------------------------------
// Stable ID: aa_00821570
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x00821570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0066e8a0, FUN_0066e9c0, FUN_0066e9d0, FUN_00821570.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00821570(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,char *param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_60 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab603;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  cVar1 = FUN_0066e9c0();

  if (cVar1 != '\0') {

    cVar1 = FUN_0066e9d0();

    if (cVar1 == '\0') {

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_60,param_3)

      ;

      local_4 = 0;

      uVar2 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (local_28,"");

      local_4._0_1_ = 1;

      uVar3 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (local_44,"");

      local_4._0_1_ = 2;

      FUN_0066e8a0(param_2,param_1,param_4,uVar3,*(uint8_t *)(unaff_ESI + 0xc),0,uVar2,local_60);

      local_4._0_1_ = 1;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_44);

      local_4 = (uint)local_4._1_3_ << 8;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

      local_4 = 0xffffffff;

      std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

      ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_60);

    }

  }

  ExceptionList = local_c;

  return;

}
