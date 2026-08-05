// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateTemplateVehi_005685e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005685e0
// Callee of Named_CalleeOf_CVOGSpawnPoint_CreateTemplateVehicle
// Address:   0x005685e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGSpawnPoint_CreateTemplateVehicle: vehicle helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_005684a0, FUN_00568530, FUN_005685e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGSpawnPoint_CreateTemplateVehicle
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

uint Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_CreateTemplateVehi_005685e0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  ushort uVar1;

  uint uVar2;

  int iVar3;

  

  uVar2 = FUN_005684a0(param_1);

  if ((int)uVar2 < 1) {

    return uVar2 & 0xffffff00;

  }

  iVar3 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar3 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(iVar3 + 0xc) * 2);

  *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + 1;

  uVar2 = FUN_00568530(param_1,(int)((longlong)(ulonglong)uVar1 % (longlong)(int)uVar2),param_2);

  return uVar2;

}
