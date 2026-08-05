// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_0055efd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055efd0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles (+1 other named callers)
// Address:   0x0055efd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0055efd0, FUN_005b3300.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_SkyBoxPartic_0055efd0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  

  piVar1 = (int *)(param_1 + 0x20);

  iVar4 = *(int *)(param_1 + 0x24) + 1;

  uVar2 = *(uint *)(param_1 + 0x28) & 0x7fffffff;

  if ((int)uVar2 < iVar4) {

    iVar3 = uVar2 * 2;

    if (iVar3 <= iVar4) {

      iVar3 = iVar4;

    }

    FUN_005b3300(piVar1,iVar3,8);

  }

  *(int *)(param_1 + 0x24) = iVar4;

  *(uint32_t /* width from decompiler */ *)(*piVar1 + -8 + *(int *)(param_1 + 0x24) * 8) = param_2;

  *(uint32_t /* width from decompiler */ *)(*piVar1 + -4 + *(int *)(param_1 + 0x24) * 8) = param_3;

  return;

}
