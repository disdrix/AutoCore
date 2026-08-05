// =============================================================================
// Named_Random_number_generator_not_initialised
// -----------------------------------------------------------------------------
// Stable ID: aa_006a35e0
// Address:   0x006a35e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Random_number_generator_not_initialised @ 0x006a35e0
// Stable ID: aa_006a35e0
// Embedded strings (evidence for future rename):
//   - "Random number generator not initialised"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_006a34d0×2, FUN_00401aa0, Named_Random_number_generator_not_initialised, FUN_006a3db0, _CxxThrowException.
//  - Strings: "Random number generator not initialised".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Random number generator not initialised"
 * Domain alias of FUN_006a35e0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



float10 Named_Random_number_generator_not_initialised(void)



{

  float fVar1;

  int iVar2;

  float10 fVar3;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_50 [28];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab3e9;

  local_c = ExceptionList;

  if (_DAT_00d091d0 == _DAT_00aaa608) {

    ExceptionList = &local_c;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

              (local_50,"Random number generator not initialised");

    local_4 = 0;

    FUN_00401aa0(local_50);

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(local_34,(ThrowInfo *)&DAT_00acc18c);

  }

  ExceptionList = &local_c;

  FUN_006a34d0();

  iVar2 = FUN_006a3db0();

  fVar1 = (float)(&DAT_00d08fc8)[iVar2];

  fVar3 = (float10)FUN_006a34d0();

  (&DAT_00d08fc8)[iVar2] = (float)fVar3;

  ExceptionList = local_c;

  return (float10)fVar1;

}
