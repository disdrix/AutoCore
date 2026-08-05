// =============================================================================
// FUN_00686d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00686d30
// Address:   0x00686d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00686d30 @ 0x00686d30
// Stable ID: aa_00686d30
// Embedded strings (evidence for future rename):
//   - "SetWindStrength() expects new wind strength >= 0.0"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_00686d30, FUN_0068ed90, FUN_00699800, SetWindStrength.
//  - Strings: "SetWindStrength() expects new wind strength >= 0.0".
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

float10 __thiscall FUN_00686d30(int param_1,float param_2,float param_3,float param_4)



{

  float10 fVar1;

  float local_18;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009a9e42;

  local_10 = ExceptionList;

  local_18 = 0.0;

  local_8 = 0;

  if (param_2 < g_flZero) {

    ExceptionList = &local_10;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00d08e78,"SetWindStrength() expects new wind strength >= 0.0");

  }

  else {

    if (param_3 == DAT_00aaa668) {

      param_3 = *(float *)(*(int *)(param_1 + 0x10) + 4);

    }

    if (param_4 == DAT_00aaa668) {

      param_4 = **(float **)(param_1 + 0x10);

    }

    ExceptionList = &local_10;

    fVar1 = (float10)FUN_00699800(param_2,param_3,param_4);

    local_18 = (float)fVar1;

    if ((*(int *)(*(int *)(param_1 + 0x10) + 8) == 1) && (*(int *)(param_1 + 4) != 0)) {

      *(uint8_t *)(*(int *)(param_1 + 4) + 0x12) = 0;

    }

    if ((*(int *)(*(int *)(param_1 + 0x10) + 0xc) == 1) && (*(int *)(param_1 + 0x5c) != 0)) {

      *(uint8_t *)(*(int *)(param_1 + 0x5c) + 0x12) = 0;

    }

    if ((*(int *)(*(int *)(param_1 + 0x10) + 0x10) == 1) ||

       (*(char *)(*(int *)(param_1 + 0x10) + 0x14) != '\0')) {

      FUN_0068ed90();

    }

  }

  ExceptionList = local_10;

  return (float10)local_18;

}
