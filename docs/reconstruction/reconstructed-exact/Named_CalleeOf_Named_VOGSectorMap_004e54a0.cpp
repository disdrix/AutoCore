// =============================================================================
// Named_CalleeOf_Named_VOGSectorMap_004e54a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e54a0
// Callee of Named_VOGSectorMap (+1 other named callers)
// Address:   0x004e54a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOGSectorMap: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOGSectorMap (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004e39d0, FUN_004e54a0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOGSectorMap (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_VOGSectorMap_004e54a0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(param_1 + 8) - iVar1 >> 2) < (uint)(*(int *)(param_1 + 0xc) - iVar1 >> 2))) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

    *puVar2 = *param_2;

    *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar2 + 1;

    return;

  }

  FUN_004e39d0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),1,param_2);

  return;

}
