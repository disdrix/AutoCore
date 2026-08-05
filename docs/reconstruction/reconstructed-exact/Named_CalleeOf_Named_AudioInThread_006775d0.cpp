// =============================================================================
// Named_CalleeOf_Named_AudioInThread_006775d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006775d0
// Callee of Named_AudioInThread
// Address:   0x006775d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_AudioInThread: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_006775d0, FUN_00679960, FUN_0076c500.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_AudioInThread
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_AudioInThread_006775d0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9528;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00679960(param_2);

  local_4 = 0;

  *param_1 = &PTR_FUN_009e8510;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  FUN_0076c500(1000);

  if (param_1[1] == 0) {

    param_1[0xb] = 0;

    param_1[0xc] = 0;

    param_1[0xd] = 0;

    param_1[0xe] = 0;

    param_1[0xf] = 0;

    param_1[0x10] = 0;

  }

  else if (param_1[1] == 1) {

    param_1[0x11] = 0;

    param_1[0x12] = 0;

    param_1[0x13] = 0;

    param_1[0x14] = 0;

    param_1[0x15] = 0;

    param_1[0x16] = 0;

    ExceptionList = local_c;

    return param_1;

  }

  ExceptionList = local_c;

  return param_1;

}
