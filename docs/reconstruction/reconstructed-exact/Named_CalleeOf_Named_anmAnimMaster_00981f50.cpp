// =============================================================================
// Named_CalleeOf_Named_anmAnimMaster_00981f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00981f50
// Callee of Named_anmAnimMaster
// Address:   0x00981f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_anmAnimMaster: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0046ce80, FUN_00981ee0, FUN_00981f50, NDResourceCache_LookupOrCreate, NDResource_AcquireInnerObject.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_anmAnimMaster
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

uint Named_CalleeOf_Named_anmAnimMaster_00981f50(uint32_t /* width from decompiler */ param_1)



{

  char cVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int iVar4;

  

  uVar2 = FUN_0046ce80();

  piVar3 = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050,param_1,uVar2,0,0);

  *(int **)(in_EAX + 4) = piVar3;

  if (piVar3 != (int *)0x0) {

    cVar1 = (**(code **)(*piVar3 + 4))();

    iVar4 = NDResource_AcquireInnerObject();

    if ((iVar4 != 0) && (iVar4 = FUN_00981ee0(), -1 < iVar4)) {

      return (uint)(cVar1 != '\0');

    }

  }

  return 0xffffffff;

}
