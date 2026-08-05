// =============================================================================
// FUN_008207d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008207d0
// Address:   0x008207d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008207d0 @ 0x008207d0
// Stable ID: aa_008207d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_008186f0, FUN_008207d0, _eh_vector_destructor_iterator_.
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

void __fastcall FUN_008207d0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b845b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a768c4;

  local_4 = 0;

  _eh_vector_destructor_iterator_(param_1 + 0x3b9,0x14,9,FUN_00417ee0);

  local_4 = 0xffffffff;

  FUN_008186f0();

  ExceptionList = pvStack_c;

  return;

}
