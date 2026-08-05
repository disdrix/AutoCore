// =============================================================================
// FUN_00755970
// -----------------------------------------------------------------------------
// Stable ID: aa_00755970
// Address:   0x00755970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00755970 @ 0x00755970
// Stable ID: aa_00755970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: DeleteObject×2, CONCAT31, DeleteDC, FUN_004439d0, FUN_00443b00, FUN_00755970.
//  - Return sites: 2.

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

void FUN_00755970(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b12ff;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a9f584;

  local_4 = 3;

  DeleteObject((HGDIOBJ)param_1[0x28]);

  DeleteObject((HGDIOBJ)param_1[0x29]);

  DeleteDC((HDC)param_1[0x2a]);

  FUN_00443b00();

  local_4 = CONCAT31(local_4._1_3_,2);

  if ((void *)param_1[0x16] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x16]);

  }

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x18] = 0;

  FUN_004439d0();

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x13]);

}
