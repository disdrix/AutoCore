// =============================================================================
// Named_CalleeOf_Named_gfxSubPhaseMap_0073e1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073e1e0
// Callee of Named_gfxSubPhaseMap (+1 other named callers)
// Address:   0x0073e1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxSubPhaseMap: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxSubPhaseMap (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00457040, FUN_0073d830, FUN_0073e1e0, FUN_007533e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxSubPhaseMap (+1 other named callers)
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_gfxSubPhaseMap_0073e1e0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_00457040();

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar1[1] = 0;

    puVar1[2] = 0;

    *puVar1 = &PTR_FUN_00a9f9c4;

    puVar1[3] = 0;

    puVar1[4] = 0;

    puVar1[5] = 0;

    puVar1[6] = 0;

    *(uint16_t *)(puVar1 + 7) = 0xffff;

    *(uint16_t *)((int)puVar1 + 0x1e) = 0xffff;

    puVar1[8] = 0;

  }

  iVar2 = FUN_007533e0(puVar1,0);

  *param_3 = iVar2;

  if (iVar2 < 0) {

    if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar1)(1);

    }

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  FUN_0073d830(puVar1);

  return puVar1;

}
