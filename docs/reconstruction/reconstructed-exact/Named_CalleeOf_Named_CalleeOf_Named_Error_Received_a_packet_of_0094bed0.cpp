// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_0094bed0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094bed0
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x0094bed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004bc180, FUN_00512160, FUN_00575440, FUN_0094bed0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
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

int * Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_0094bed0(void)



{

  void *pvVar1;

  int iVar2;

  int *piVar3;

  int unaff_EDI;

  void *pvVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab618;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar1 = operator_new(0x210);

  piVar3 = (int *)0x0;

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    piVar3 = (int *)FUN_00575440();

  }

  local_4 = 0xffffffff;

  pvVar1 = *(void **)(unaff_EDI + 0xe04);

  pvVar4 = DAT_00af30f4;

  (**(code **)(*piVar3 + 8))(DAT_00af30f4,pvVar1,1);

  FUN_00512160(puStack_8,local_4,1);

  (**(code **)(*piVar3 + 0x218))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xe04));

  iVar2 = FUN_004bc180(piVar3);

  if (iVar2 < 0) {

    (**(code **)*piVar3)(1);

    ExceptionList = pvVar4;

    return (int *)0x0;

  }

  ExceptionList = pvVar1;

  return piVar3;

}
