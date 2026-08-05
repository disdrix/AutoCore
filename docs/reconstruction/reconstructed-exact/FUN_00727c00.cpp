// =============================================================================
// FUN_00727c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00727c00
// Address:   0x00727c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00727c00 @ 0x00727c00
// Stable ID: aa_00727c00
// Embedded strings (evidence for future rename):
//   - "Sending: %s -> %s(%s)"
//   - "../../..\\infrastruct/Auth/authNetLib/authMessageTrace.h"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0067b1b0, FUN_00727c00, FUN_0076cec0, s, vog_LogMessage.
//  - Strings: "Sending: %s -> %s(%s)"; "../../..\\infrastruct/Auth/authNetLib/authMessageTrace.h".
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

void FUN_00727c00(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t local_2c [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad41f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar1 = FUN_0067b1b0(local_28);

  local_4 = 0;

  if (*(uint *)(iVar1 + 0x18) < 0x10) {

    iVar1 = iVar1 + 4;

  }

  else {

    iVar1 = *(int *)(iVar1 + 4);

  }

  uVar2 = FUN_0076cec0(local_2c,"Sending: %s -> %s(%s)",param_1,param_2,iVar1);

  vog_LogMessage("../../..\\infrastruct/Auth/authNetLib/authMessageTrace.h",0xd,1,uVar2);

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  ExceptionList = local_c;

  return;

}
