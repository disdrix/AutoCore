// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0059b110
// -----------------------------------------------------------------------------
// Stable ID: aa_0059b110
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0059b110  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0059b110, FUN_005ae270.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_0059b110(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a5bac;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009d5710;

  iVar1 = FUN_005ae270();

  param_1[0x148] = iVar1;

  *(uint8_t *)(iVar1 + 0x21) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1[0x148] + 4) = param_1[0x148];

  *(uint32_t /* width from decompiler */ *)param_1[0x148] = param_1[0x148];

  *(uint32_t /* width from decompiler */ *)(param_1[0x148] + 8) = param_1[0x148];

  param_1[0x149] = 0;

  param_1[0x146] = 0;

  ExceptionList = local_c;

  return param_1;

}
