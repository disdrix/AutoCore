// =============================================================================
// FUN_00989c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00989c10
// Address:   0x00989c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00989c10 @ 0x00989c10
// Stable ID: aa_00989c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: CONCAT31, DeleteCriticalSection, EnterCriticalSection, FUN_00415e90, FUN_00449a90, FUN_009899a0, FUN_00989c10, FUN_00996b00.
//  - Return sites: 3.

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

void FUN_00989c10(int param_1)



{

  LPCRITICAL_SECTION lpCriticalSection;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009acddd;

  pvStack_c = ExceptionList;

  local_4 = 0;

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x68);

  ExceptionList = &pvStack_c;

  if (*(char *)(param_1 + 0x80) != '\0') {

    ExceptionList = &pvStack_c;

    EnterCriticalSection(lpCriticalSection);

  }

  local_4 = CONCAT31(local_4._1_3_,3);

  if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  FUN_00415e90();

  FUN_00449a90(9);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 1;

  FUN_009899a0();

  if (*(char *)(param_1 + 0x80) != '\0') {

    LeaveCriticalSection(lpCriticalSection);

  }

  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x68));

  *(uint8_t *)(param_1 + 0x80) = 0;

  local_4 = local_4 & 0xffffff00;

  FUN_00996b00(param_1 + 0x14);

  if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  ExceptionList = lpCriticalSection;

  return;

}
