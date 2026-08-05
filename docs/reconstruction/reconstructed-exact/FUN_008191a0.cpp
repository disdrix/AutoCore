// =============================================================================
// FUN_008191a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008191a0
// Address:   0x008191a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008191a0 @ 0x008191a0
// Stable ID: aa_008191a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_008176d0, FUN_00818cb0, FUN_008191a0.
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

int * FUN_008191a0(void)



{

  void *pvVar1;

  int *piVar2;

  int unaff_EBX;

  int unaff_EDI;

  uint32_t /* width from decompiler */ unaff_retaddr;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb575;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar1 = operator_new(0x70c);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_00818cb0(pvVar1);

  }

  local_4 = 0xffffffff;

  if (unaff_EDI == 0) {

    (**(code **)(*piVar2 + 0x28))(unaff_EBX + 0x650);

  }

  else {

    (**(code **)(*piVar2 + 0x28))();

  }

  FUN_008176d0(piVar2);

  if (piVar2[0x1c2] != 0) {

    (**(code **)(*(int *)piVar2[0x1c2] + 0x3c8))(unaff_retaddr,1);

  }

  ExceptionList = pvVar1;

  return piVar2;

}
