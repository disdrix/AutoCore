// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00588450
// -----------------------------------------------------------------------------
// Stable ID: aa_00588450
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostC
// Address:   0x00588450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostC: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00588290, FUN_00588450, __RTDynamicCast.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGCreature_PostC
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00588450(int param_1,int *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (param_1 != 0) {

    iVar1 = __RTDynamicCast(param_1,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                            &CVOGStore::RTTI_Type_Descriptor,0);

    if (iVar1 != 0) {

      uVar2 = (**(code **)(*param_2 + 0x25c))();

      FUN_00588290(param_2,uVar2);

      return 1;

    }

  }

  return 0;

}
