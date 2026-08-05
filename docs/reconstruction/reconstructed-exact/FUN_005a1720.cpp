// =============================================================================
// FUN_005a1720
// -----------------------------------------------------------------------------
// Stable ID: aa_005a1720
// Address:   0x005a1720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a1720 @ 0x005a1720
// Stable ID: aa_005a1720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_005a1720, FUN_005a43c0, FUN_007808b0.
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

void __fastcall FUN_005a1720(uint32_t /* width from decompiler */ *param_1)



{

  uint8_t local_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a618b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_LAB_009d7f1c;

  local_4 = 4;

  FUN_007808b0();

  local_4 = CONCAT31(local_4._1_3_,3);

  FUN_005a43c0(local_10,*(uint32_t /* width from decompiler */ *)param_1[0xa5],(uint32_t /* width from decompiler */ *)param_1[0xa5]);

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0xa5]);

}
