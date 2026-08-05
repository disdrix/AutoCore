// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006962e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006962e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006962e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31, FUN_006962e0, FUN_006a1a30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006962e0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009aa986;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 1;

  param_1[0xb] = 2;

  param_1[0xd] = 4;

  param_1[0xe] = 1;

  *(uint8_t *)(param_1 + 0xf) = 0;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  local_4._0_1_ = 2;

  local_4._1_3_ = 0;

  param_1[0x14] = 4;

  param_1[0x15] = 0x3f800000;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0x3d4ccccd;

  param_1[0x19] = 2;

  param_1[0x1a] = 1;

  pvVar1 = operator_new(0x5c);

  local_4._0_1_ = 3;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (local_28,

                       "BezierSpline 0.0 1.0 0.0 { 3 0 0.00138887 0.337009 0.941501 0.132767 0.493215 0.998903 1 0.00102074 0.23702 1 -6.24607e-008 0.307222 -0.951638 0.126974 }"

                      );

    local_4 = CONCAT31(local_4._1_3_,4);

    uVar2 = FUN_006a1a30(uVar2);

  }

  param_1[0xc] = uVar2;

  local_4 = 2;

  if (pvVar1 != (void *)0x0) {

    std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

    ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

  }

  ExceptionList = local_c;

  return param_1;

}
