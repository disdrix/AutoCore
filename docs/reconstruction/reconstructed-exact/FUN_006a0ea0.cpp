// =============================================================================
// FUN_006a0ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a0ea0
// Address:   0x006a0ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a0ea0 @ 0x006a0ea0
// Stable ID: aa_006a0ea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×2, goto×1, return×1.
//  - Notable callees: FUN_0069fcb0, FUN_006a08a0, FUN_006a0ea0.
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

int __thiscall

FUN_006a0ea0(int param_1,

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)



{

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;

  bool bVar2;

  int iVar3;

  int *piVar4;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_2c [28];

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pbVar1 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab0b8;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  iVar3 = FUN_0069fcb0(param_2);

  if (iVar3 != *(int *)(param_1 + 4)) {

    bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (pbVar1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                               *)(iVar3 + 0xc));

    if (!bVar2) goto LAB_006a0f1b;

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_2c,pbVar1);

  local_10 = 0;

  local_4 = 0;

  piVar4 = (int *)FUN_006a08a0(&param_2,iVar3,local_2c);

  iVar3 = *piVar4;

  local_4 = 0xffffffff;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_2c);

LAB_006a0f1b:

  ExceptionList = local_c;

  return iVar3 + 0x28;

}
