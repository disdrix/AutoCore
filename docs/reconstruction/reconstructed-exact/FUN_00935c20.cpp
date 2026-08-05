// =============================================================================
// FUN_00935c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00935c20
// Address:   0x00935c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00935c20 @ 0x00935c20
// Stable ID: aa_00935c20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: CONCAT31, CryptDestroyKey, CryptReleaseContext, DeleteCriticalSection, FUN_00415e90, FUN_00933b70, FUN_00935c20.
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

void FUN_00935c20(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &DAT_009b06a0;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a2c2dc;

  local_4 = 0x20;

  if (*(char *)((int)param_1 + 0x13) != '\0') {

    *(uint8_t *)((int)param_1 + 0x13) = 0;

  }

  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00d0a394);

  CryptDestroyKey(DAT_00d0a3b4);

  CryptReleaseContext(DAT_00d0a3b0,0);

  FUN_00933b70();

  local_4 = CONCAT31(local_4._1_3_,0x1f);

  FUN_00415e90();

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0xf02]);

}
