// =============================================================================
// FUN_00698550
// -----------------------------------------------------------------------------
// Stable ID: aa_00698550
// Address:   0x00698550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00698550 @ 0x00698550
// Stable ID: aa_00698550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0056f570, FUN_00698550, FUN_0069a010, FUN_0069ee30.
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

void __fastcall FUN_00698550(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009aac14;

  local_c = ExceptionList;

  local_4 = 4;

  ExceptionList = &local_c;

  FUN_0069ee30();

  if (*(void **)(param_1 + 0x78) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x78));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = 0;

  if (*(void **)(param_1 + 100) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 100));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  local_4._0_1_ = 1;

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

             (param_1 + 0x24));

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0056f570();

  local_4 = 0xffffffff;

  FUN_0069a010();

  ExceptionList = local_c;

  return;

}
