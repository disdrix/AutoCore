// =============================================================================
// FUN_00719890
// -----------------------------------------------------------------------------
// Stable ID: aa_00719890
// Address:   0x00719890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00719890 @ 0x00719890
// Stable ID: aa_00719890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, return×2.
//  - Notable callees: CloseHandle×2, FUN_00766750×2, FUN_00719890, free.
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

void FUN_00719890(int *param_1)



{

  char cVar1;

  BOOL BVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009abd78;

  pvStack_c = ExceptionList;

  local_4 = 2;

  ExceptionList = &pvStack_c;

  cVar1 = (**(code **)(*param_1 + 0x20))();

  if (cVar1 == '\0') {

LAB_007198cf:

    param_1[2] = -1;

  }

  else {

    BVar2 = CloseHandle((HANDLE)param_1[2]);

    if (BVar2 != 0) goto LAB_007198cf;

  }

  cVar1 = (**(code **)(param_1[5] + 0x20))();

  if (cVar1 != '\0') {

    BVar2 = CloseHandle((HANDLE)param_1[7]);

    if (BVar2 == 0) goto LAB_007198f6;

  }

  param_1[7] = -1;

LAB_007198f6:

  if ((void *)param_1[10] != (void *)0x0) {

    free((void *)param_1[10]);

  }

  if ((void *)param_1[0xd] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xd]);

  }

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  local_4 = local_4 & 0xffffff00;

  FUN_00766750();

  local_4 = 0xffffffff;

  FUN_00766750();

  ExceptionList = pvStack_c;

  return;

}
