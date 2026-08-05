// =============================================================================
// FUN_00989d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00989d50
// Address:   0x00989d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00989d50 @ 0x00989d50
// Stable ID: aa_00989d50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: EnterCriticalSection, FUN_00415e90, FUN_00449a90, FUN_009899a0, FUN_00989d50, FUN_00996d70, LeaveCriticalSection.
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

void __fastcall FUN_00989d50(int param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009adccf;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (*(char *)(param_1 + 0x80) != '\0') {

    ExceptionList = &local_c;

    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x68));

  }

  local_4 = 0;

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

  FUN_00996d70(0);

  if (*(char *)(param_1 + 0x80) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x68));

  }

  ExceptionList = local_c;

  return;

}
