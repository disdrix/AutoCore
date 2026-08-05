// =============================================================================
// FUN_00986de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00986de0
// Address:   0x00986de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00986de0 @ 0x00986de0
// Stable ID: aa_00986de0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CONCAT31, FUN_0045fcc0, FUN_00986760, FUN_00986de0.
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

void FUN_00986de0(int param_1)



{

  uint8_t local_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b20fb;

  pvStack_c = ExceptionList;

  local_4 = 2;

  ExceptionList = &pvStack_c;

  FUN_00986760(param_1);

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_0045fcc0(local_10,**(uint32_t /* width from decompiler */ **)(param_1 + 0x14),*(uint32_t /* width from decompiler */ **)(param_1 + 0x14));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x14));

}
