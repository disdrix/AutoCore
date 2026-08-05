// =============================================================================
// FUN_00817e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00817e20
// Address:   0x00817e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00817e20 @ 0x00817e20
// Stable ID: aa_00817e20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00816570, FUN_008176d0, FUN_00817e20.
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

int * FUN_00817e20(uint32_t /* width from decompiler */ param_1)



{

  void *pvVar1;

  int *piVar2;

  int unaff_EBX;

  int unaff_EDI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8104;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar1 = operator_new(0x820);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_00816570(pvVar1,param_1);

  }

  local_4 = 0xffffffff;

  if (unaff_EDI == 0) {

    (**(code **)(*piVar2 + 0x28))(unaff_EBX + 0xa60);

  }

  else {

    (**(code **)(*piVar2 + 0x28))();

  }

  FUN_008176d0(piVar2);

  ExceptionList = pvVar1;

  return piVar2;

}
