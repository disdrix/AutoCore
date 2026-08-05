// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_008923a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008923a0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
// Address:   0x008923a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00411500, FUN_00892190, FUN_008923a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
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

int * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_008923a0(void)



{

  char cVar1;

  void *pvVar2;

  int *piVar3;

  int *unaff_EDI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b9601;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar2 = operator_new(0x5b8);

  piVar3 = (int *)0x0;

  local_4 = 0;

  if (pvVar2 != (void *)0x0) {

    piVar3 = (int *)FUN_00892190(pvVar2);

  }

  local_4 = 0xffffffff;

  (**(code **)(*piVar3 + 0x74))(0x9c41);

  FUN_00411500(unaff_EDI + 0x143,piVar3);

  cVar1 = (**(code **)(*unaff_EDI + 0x3d8))();

  if (cVar1 != '\0') {

    (**(code **)(*unaff_EDI + 0xa8))(piVar3);

  }

  ExceptionList = pvVar2;

  return piVar3;

}
