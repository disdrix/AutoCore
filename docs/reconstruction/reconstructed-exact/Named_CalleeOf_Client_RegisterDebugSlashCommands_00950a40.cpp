// =============================================================================
// Named_CalleeOf_Client_RegisterDebugSlashCommands_00950a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00950a40
// Callee of Client_RegisterDebugSlashCommands
// Address:   0x00950a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RegisterDebugSlashCommands: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00402710, FUN_00402c70, FUN_00404400, FUN_00950a40, strncpy.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RegisterDebugSlashCommands
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

void __fastcall

Named_CalleeOf_Client_RegisterDebugSlashCommands_00950a40(uint32_t /* width from decompiler */ param_1,char *param_2,int param_3,char *param_4,uint32_t /* width from decompiler */ param_5)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_378 [28];

  uint32_t /* width from decompiler */ local_35c;

  char local_358 [260];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_254 [292];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_130 [292];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac6cc;

  local_c = ExceptionList;

  local_35c = param_5;

  ExceptionList = &local_c;

  strncpy(local_358,param_2,0x100);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_378,param_4);

  local_4 = 0;

  FUN_00402c70(local_130,local_378,&local_35c);

  local_4._0_1_ = 1;

  FUN_00404400(local_254);

  local_4._0_1_ = 2;

  FUN_00402710(param_3 + 4);

  local_4._0_1_ = 1;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_254);

  local_4 = (uint)local_4._1_3_ << 8;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_130);

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_378);

  ExceptionList = local_c;

  return;

}
