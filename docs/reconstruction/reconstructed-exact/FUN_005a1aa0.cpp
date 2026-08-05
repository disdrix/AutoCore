// =============================================================================
// FUN_005a1aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a1aa0
// Address:   0x005a1aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a1aa0 @ 0x005a1aa0
// Stable ID: aa_005a1aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005a1aa0, FUN_005a4c30.
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

void __fastcall FUN_005a1aa0(uint32_t /* width from decompiler */ *param_1)



{

  uint8_t local_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009a620f;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009d7fcc;

  local_4 = 1;

  if ((int *)param_1[0x2c] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x2c] + 4))(1);

  }

  param_1[0x2c] = 0;

  local_4 = local_4 & 0xffffff00;

  FUN_005a4c30(local_10,*(uint32_t /* width from decompiler */ *)param_1[0x2f],(uint32_t /* width from decompiler */ *)param_1[0x2f]);

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x2f]);

}
