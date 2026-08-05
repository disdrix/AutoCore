// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume_00819060
// -----------------------------------------------------------------------------
// Stable ID: aa_00819060
// Callee of Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume
// Address:   0x00819060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008176d0, FUN_00817840, FUN_00818be0, FUN_00819060.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Named_CalleeOf_Named_CalleeOf_Drive_Player_Vehicle_Sound_Volume_00819060(void)



{

  void *pvVar1;

  int *piVar2;

  int unaff_ESI;

  int unaff_EDI;

  uint32_t /* width from decompiler */ unaff_retaddr;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb54b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar1 = operator_new(0x820);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    piVar2 = (int *)FUN_00818be0(pvVar1);

  }

  local_4 = 0xffffffff;

  if (unaff_ESI == 0) {

    (**(code **)(*piVar2 + 0x28))(unaff_EDI + 0x858);

  }

  else {

    (**(code **)(*piVar2 + 0x28))();

  }

  FUN_00817840(unaff_retaddr);

  FUN_008176d0(piVar2);

  ExceptionList = pvVar1;

  return piVar2;

}
