// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00797d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00797d70
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x00797d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004271c0, FUN_00797530, FUN_00797d70.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
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

void Named_CalleeOf_Named_VOG_DEBUG_STOP_00797d70(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009add5a;

  local_c = ExceptionList;

  local_4 = 2;

  ExceptionList = &local_c;

  *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0xa4) + *(float *)(param_1 + 0xa8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

  FUN_00797530(1);

  if (*(void **)(param_1 + 0x94) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x94));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = 0;

  local_4 = local_4 & 0xffffff00;

  FUN_004271c0();

  local_4 = 0xffffffff;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

  ~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

            ((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

              *)(param_1 + 0xc));

  ExceptionList = local_c;

  return;

}
