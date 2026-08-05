// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk_00496f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00496f70
// Callee of Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window
// Address:   0x00496f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00457c60, FUN_00496f70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Could_not_get_Palantir_desktop_window
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_Could_not_get_Palantir_desk_00496f70(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  uint8_t uVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a0d1e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009c7a1c;

  param_1[1] = 0x40;

  param_1[2] = 0x40;

  uVar2 = FUN_00457c60();

  param_1[4] = uVar2;

  param_1[5] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  uVar2 = DAT_00aaa8a8;

  *(uint8_t *)((int)param_1 + 0x4d) = 0;

  *(uint8_t *)(param_1 + 0x13) = 1;

  *(uint8_t *)((int)param_1 + 0x4e) = 1;

  *(uint8_t *)((int)param_1 + 0x4f) = 1;

  *(uint8_t *)(param_1 + 0x14) = 1;

  uVar1 = *(uint8_t *)(param_2 + 0x7d);

  param_1[0x15] = uVar2;

  param_1[0x16] = DAT_00aaa6fc;

  *(uint8_t *)((int)param_1 + 0x51) = uVar1;

  *(uint8_t *)((int)param_1 + 0x52) = 0;

  *(uint8_t *)((int)param_1 + 0x53) = 1;

  param_1[0x17] = 3;

  param_1[0x18] = 0;

  param_1[0x19] = 0;

  param_1[0x1a] = 0;

  param_1[0x1b] = 0;

  param_1[0x1c] = 0;

  param_1[0x1d] = 0;

  param_1[0x1e] = 0;

  param_1[0x1f] = 0;

  param_1[0x20] = 0;

  param_1[0x21] = 0;

  param_1[0x22] = 0;

  param_1[0x23] = 0;

  param_1[0x24] = 0;

  param_1[0x25] = 0;

  param_1[0x27] = 0;

  param_1[0x28] = 0;

  param_1[0x29] = 0;

  param_1[0x2b] = 0;

  param_1[0x2c] = 0;

  param_1[0x2d] = 0;

  param_1[0x2f] = 0;

  param_1[0x30] = 0;

  param_1[0x31] = 0;

  ExceptionList = local_c;

  return param_1;

}
