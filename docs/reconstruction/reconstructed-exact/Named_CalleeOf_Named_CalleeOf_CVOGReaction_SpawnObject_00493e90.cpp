// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_00493e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00493e90
// Callee of Named_CalleeOf_CVOGReaction_SpawnObject
// Address:   0x00493e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_SpawnObject: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004507a0, FUN_00493e90.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_SpawnObject
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_00493e90(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  iVar1 = *(int *)(param_1 + 0xac);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(param_1 + 0xb0) - iVar1 >> 2) < (uint)(*(int *)(param_1 + 0xb4) - iVar1 >> 2))

     ) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xb0);

    *puVar2 = param_2;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0xb0) = puVar2 + 1;

    return;

  }

  FUN_004507a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb0),1,&param_2);

  return;

}
