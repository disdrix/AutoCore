// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_0055f590
// -----------------------------------------------------------------------------
// Stable ID: aa_0055f590
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Set
// Address:   0x0055f590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Set: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0055f590.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Set
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_0055f590(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int iVar2;

  

  piVar1 = DAT_00b05060;

  iVar2 = param_1[4] * 0x10;

  if ((iVar2 == 0) || ((param_1[3] != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    DAT_00b05060[2] = DAT_00b05060[2] + param_1[4] * -0x10;

    piVar1[3] = piVar1[3] + iVar2;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(param_1[3],iVar2);

  }

  if (-1 < (int)param_1[2]) {

    (**(code **)(*DAT_00b05060 + 0x14))(*param_1,param_1[2] << 4,0x12);

  }

  return;

}
