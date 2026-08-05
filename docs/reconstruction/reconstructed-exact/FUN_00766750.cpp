// =============================================================================
// FUN_00766750
// -----------------------------------------------------------------------------
// Stable ID: aa_00766750
// Address:   0x00766750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00766750 @ 0x00766750
// Stable ID: aa_00766750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, goto×1, return×1.
//  - Notable callees: CloseHandle, FUN_00766750.
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

void __fastcall FUN_00766750(int *param_1)



{

  char cVar1;

  BOOL BVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009ab8c7;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = (int)&PTR_FUN_00a9d84c;

  local_4 = 0;

  if ((void *)param_1[3] != (void *)0x0) {

    operator_delete__((void *)param_1[3]);

  }

  cVar1 = (**(code **)(*param_1 + 0x20))();

  if (cVar1 != '\0') {

    BVar2 = CloseHandle((HANDLE)param_1[2]);

    if (BVar2 == 0) goto LAB_007667ab;

  }

  param_1[2] = -1;

LAB_007667ab:

  *param_1 = (int)&PTR_LAB_00a9d774;

  ExceptionList = local_c;

  return;

}
