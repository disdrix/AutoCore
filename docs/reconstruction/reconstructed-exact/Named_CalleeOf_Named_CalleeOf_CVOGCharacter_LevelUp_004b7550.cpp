// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGCharacter_LevelUp_004b7550
// -----------------------------------------------------------------------------
// Stable ID: aa_004b7550
// Callee of Named_CalleeOf_CVOGCharacter_LevelUp (+1 other named callers)
// Address:   0x004b7550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGCharacter_LevelUp: progression/economy helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_CVOGCharacter_LevelUp (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004b7550, Map_LowerBoundFindByIntKey.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGCharacter_LevelUp (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGCharacter_LevelUp_004b7550(int param_1,float *param_2)



{

  float *pfVar1;

  int iVar2;

  int *unaff_ESI;

  int local_4;

  

  local_4 = param_1;

  Map_LowerBoundFindByIntKey((void *)(param_1 + 0x224),&local_4,&stack0x00000008,unaff_ESI);

  if (local_4 != *(int *)(param_1 + 0x228)) {

    iVar2 = *(int *)(local_4 + 0x10);

    pfVar1 = (float *)(iVar2 + 0x14);

    *pfVar1 = *param_2;

    *(float *)(iVar2 + 0x18) = param_2[1];

    *(float *)(iVar2 + 0x1c) = param_2[2];

    *pfVar1 = *pfVar1 * *(float *)(iVar2 + 8);

    *(float *)(iVar2 + 0x18) = *(float *)(iVar2 + 0xc) * *(float *)(iVar2 + 0x18);

    *(float *)(iVar2 + 0x1c) = *(float *)(iVar2 + 0x10) * *(float *)(iVar2 + 0x1c);

    *(uint8_t *)(iVar2 + 0x20) = 0;

  }

  return;

}
