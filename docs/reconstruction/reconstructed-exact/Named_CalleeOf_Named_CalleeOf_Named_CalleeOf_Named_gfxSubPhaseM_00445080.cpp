// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxSubPhaseM_00445080
// -----------------------------------------------------------------------------
// Stable ID: aa_00445080
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxSubPhaseMap
// Address:   0x00445080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxSubPhaseMap: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00445080, FUN_004450d0, NDResourceCache_LookupOrCreate.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxSubPhaseMap
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

uint Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxSubPhaseM_00445080(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  

  uVar2 = FUN_004450d0();

  piVar3 = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050,param_2,uVar2,param_3,param_4);

  *param_1 = piVar3;

  if (piVar3 == (int *)0x0) {

    return 0xffffffff;

  }

  cVar1 = (**(code **)(*piVar3 + 4))();

  return (uint)(cVar1 != '\0');

}
