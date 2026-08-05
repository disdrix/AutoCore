// =============================================================================
// FUN_00673b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00673b30
// Address:   0x00673b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00673b30 @ 0x00673b30
// Stable ID: aa_00673b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00673670, FUN_00673b30.
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

void __fastcall FUN_00673b30(int param_1)



{

  uint8_t local_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a92e4;

  pvStack_c = ExceptionList;

  local_4 = 4;

  ExceptionList = &pvStack_c;

  FUN_00673670(local_10,**(uint32_t /* width from decompiler */ **)(param_1 + 0x8c),*(uint32_t /* width from decompiler */ **)(param_1 + 0x8c));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x8c));

}
