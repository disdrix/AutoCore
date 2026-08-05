// =============================================================================
// Named_CalleeOf_Named_gfxFontImpl_00443750
// -----------------------------------------------------------------------------
// Stable ID: aa_00443750
// Callee of Named_gfxFontImpl
// Address:   0x00443750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxFontImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00443750, FUN_00443a10.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxFontImpl
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

void Named_CalleeOf_Named_gfxFontImpl_00443750(void)



{

  uint32_t /* width from decompiler */ local_28 [2];

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint8_t *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009be908;

  local_c = ExceptionList;

  local_10 = (uint8_t *)local_28;

  local_28[0] = 0;

  local_20 = 0;

  local_1c = 0;

  local_18 = 0;

  local_4 = 0xffffffff;

  ExceptionList = &local_c;

  FUN_00443a10();

  ExceptionList = local_c;

  return;

}
