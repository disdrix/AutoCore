// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00436250, FUN_00769b70, FUN_0076a200, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Expected string but got \"%s\" in chunk \"%s\""; "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_stoChunk
// -----------------------------------------------------------------------------
// Stable ID: aa_0076a200
// Address:   0x0076a200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "stoChunk"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_stoChunk(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint8_t local_2c [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0b25;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = FUN_00769b70(unaff_EBX);

  if (-1 < iVar1) {

    ExceptionList = local_c;

    return 0;

  }

  iVar1 = FUN_00436250();

  local_4 = 0;

  if (*(uint *)(iVar1 + 0x18) < 0x10) {

    iVar1 = iVar1 + 4;

  }

  else {

    iVar1 = *(int *)(iVar1 + 4);

  }

  if (*(uint *)(param_1 + 0x18) < 0x10) {

    param_1 = param_1 + 4;

  }

  else {

    param_1 = *(int *)(param_1 + 4);

  }

  uVar2 = FUN_0076cec0(local_2c,"Expected string but got \"%s\" in chunk \"%s\"",param_1,iVar1);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x44a,3,uVar2);

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  ExceptionList = local_c;

  return 0xffffffff;

}
