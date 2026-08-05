// =============================================================================
// FUN_006892b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006892b0
// Address:   0x006892b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006892b0 @ 0x006892b0
// Stable ID: aa_006892b0
// Embedded strings (evidence for future rename):
//   - "SetCamera() requires non-NULL position and direction values"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00688d50×2, FUN_00685e20, FUN_006892b0, FUN_0069f450, SetCamera.
//  - Strings: "SetCamera() requires non-NULL position and direction values".
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

void FUN_006892b0(float *param_1,uint32_t /* width from decompiler */ *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  char cVar4;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009aa092;

  local_10 = ExceptionList;

  local_14 = &stack0xffffff74;

  local_8 = 0;

  if ((param_1 == (float *)0x0) || (param_2 == (uint32_t /* width from decompiler */ *)0x0)) {

    ExceptionList = &local_10;

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::operator=

              ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)

               &DAT_00d08e78,"SetCamera() requires non-NULL position and direction values");

    ExceptionList = local_10;

    return;

  }

  fVar1 = param_1[1];

  local_1c = param_2[2];

  local_20 = param_2[1];

  local_24 = *param_2;

  fVar2 = param_1[2];

  fVar3 = *param_1;

  ExceptionList = &local_10;

  local_14 = &stack0xffffff74;

  if ((DAT_00d08eb0 == fVar3) &&

     (((ExceptionList = &local_10, local_14 = &stack0xffffff74, DAT_00d08eb4 == fVar1 &&

       (ExceptionList = &local_10, local_14 = &stack0xffffff74, DAT_00d08eb8 == fVar2)) &&

      (ExceptionList = &local_10, local_14 = &stack0xffffff74, cVar4 = FUN_00685e20(&local_24),

      cVar4 == '\0')))) {

    ExceptionList = local_10;

    return;

  }

  DAT_00af5598 = local_24;

  DAT_00af559c = local_20;

  DAT_00af55a0 = local_1c;

  DAT_00d08eb0 = fVar3;

  DAT_00d08eb4 = fVar1;

  DAT_00d08eb8 = fVar2;

  FUN_00688d50(1);

  FUN_0069f450(&local_24);

  FUN_00688d50(1);

  ExceptionList = local_10;

  return;

}
