// =============================================================================
// Named_CalleeOf_Named_anmTrackMaster_inl_0045e280
// -----------------------------------------------------------------------------
// Stable ID: aa_0045e280
// Callee of Named_anmTrackMaster_inl
// Address:   0x0045e280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_anmTrackMaster_inl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00769e40×2, FUN_0045e280, stoChunkReader_EnterChunkScope, stoChunkReader_readF32Array.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_anmTrackMaster_inl
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_anmTrackMaster_inl_0045e280(void)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ unaff_EDI;

  char local_18;

  int local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bef98;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(unaff_EDI);

  local_4 = 0;

  if (local_14 == 0x4b455952) {

    uVar1 = stoChunkReader_readF32Array(unaff_EDI);

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return uVar1;

  }

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
