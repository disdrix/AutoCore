// =============================================================================
// FUN_00558a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00558a30
// Address:   0x00558a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00558a30 @ 0x00558a30
// Stable ID: aa_00558a30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b2ba0×2, CONCAT31, FUN_00558440, FUN_00558a30, FUN_00559b10.
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

void __fastcall FUN_00558a30(uint32_t /* width from decompiler */ *param_1)



{

  uint8_t auStack_10 [4];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a4762;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009d267c;

  local_4 = 5;

  FUN_00558440();

  local_4._0_1_ = 4;

  if (-1 < (int)param_1[0x74]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x72],(param_1[0x74] & 0x7fffffff) * 0xac,0x12);

  }

  FUN_005b2ba0();

  FUN_005b2ba0();

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_00559b10(auStack_10,*(uint32_t /* width from decompiler */ *)param_1[0x5d],(uint32_t /* width from decompiler */ *)param_1[0x5d]);

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x5d]);

}
