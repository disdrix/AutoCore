// =============================================================================
// Named_CalleeOf_CVOGReaction_SpawnObject_004cd4e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd4e0
// Callee of CVOGReaction_SpawnObject (+1 other named callers)
// Address:   0x004cd4e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_SpawnObject: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGReaction_SpawnObject (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004cd4e0, FUN_005dac00, __RTDynamicCast.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_SpawnObject (+1 other named callers)
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

uint32_t /* width from decompiler */ Named_CalleeOf_CVOGReaction_SpawnObject_004cd4e0(int *param_1,char *param_2)



{

  int iVar1;

  

  iVar1 = __RTDynamicCast(param_1,0,&CVOGHBBase::RTTI_Type_Descriptor,

                          &CVOGHBRecreateObject::RTTI_Type_Descriptor,0);

  if (iVar1 != 0) {

    if (*param_2 != '\0') {

      FUN_005dac00();

    }

    (**(code **)(*param_1 + 0x18))(1,0);

    param_2[1] = '\x01';

    *(uint8_t *)param_1 = 1;

    return 1;

  }

  return 0;

}
