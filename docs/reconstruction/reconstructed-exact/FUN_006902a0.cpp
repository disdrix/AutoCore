// =============================================================================
// FUN_006902a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006902a0
// Address:   0x006902a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006902a0 @ 0x006902a0
// Stable ID: aa_006902a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31, FUN_006902a0, FUN_00699f00, FUN_006a1a30.
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

uint32_t /* width from decompiler */ FUN_006902a0(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009aa635;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x5c);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_00699f00(local_28);

    local_4 = CONCAT31(local_4._1_3_,1);

    uVar2 = FUN_006a1a30(uVar2);

  }

  local_4 = 0xffffffff;

  if (pvVar1 != (void *)0x0) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

  ExceptionList = local_c;

  return uVar2;

}
