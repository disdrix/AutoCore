// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0062d960
// -----------------------------------------------------------------------------
// Stable ID: aa_0062d960
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0062d960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0062d960.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
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

int * __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0062d960(int *param_1,uint param_2)



{

  int *piVar1;

  int *piVar2;

  uint uVar3;

  int iVar4;

  

  uVar3 = param_2 * 8 + 0xf & 0xfffffff0;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = -0x80000000;

  piVar2 = DAT_00b05060;

  piVar1 = DAT_00b05060 + 3;

  if (*piVar1 < (int)uVar3) {

    iVar4 = (**(code **)(*DAT_00b05060 + 0x24))(uVar3);

  }

  else {

    iVar4 = DAT_00b05060[2];

    DAT_00b05060[2] = iVar4 + uVar3;

    piVar2[3] = *piVar1 - uVar3;

  }

  *param_1 = iVar4;

  param_1[3] = iVar4;

  param_1[4] = param_2;

  param_1[2] = param_2 | 0x80000000;

  return param_1;

}
