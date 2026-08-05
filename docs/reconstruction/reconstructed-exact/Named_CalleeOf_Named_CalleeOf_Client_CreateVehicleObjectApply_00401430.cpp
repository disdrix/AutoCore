// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_CreateVehicleObjectApply_00401430
// -----------------------------------------------------------------------------
// Stable ID: aa_00401430
// Callee of Named_CalleeOf_Client_CreateVehicleObjectApply
// Address:   0x00401430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_CreateVehicleObjectApply: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00401430, FUN_004017b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_CreateVehicleObjectApply
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

void Named_CalleeOf_Named_CalleeOf_Client_CreateVehicleObjectApply_00401430(void)



{

  int in_EAX;

  int iVar1;

  int *unaff_EBX;

  uint *unaff_EDI;

  

  iVar1 = FUN_004017b0();

  if (iVar1 != *(int *)(in_EAX + 4)) {

    if ((*(int *)(iVar1 + 0x14) <= (int)unaff_EDI[1]) &&

       ((*(int *)(iVar1 + 0x14) < (int)unaff_EDI[1] || (*(uint *)(iVar1 + 0x10) <= *unaff_EDI)))) {

      *unaff_EBX = iVar1;

      return;

    }

  }

  *unaff_EBX = *(int *)(in_EAX + 4);

  return;

}
