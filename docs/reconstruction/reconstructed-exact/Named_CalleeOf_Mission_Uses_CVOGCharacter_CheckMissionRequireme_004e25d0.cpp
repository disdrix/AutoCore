// =============================================================================
// Named_CalleeOf_Mission_Uses_CVOGCharacter_CheckMissionRequireme_004e25d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e25d0
// Callee of Mission_Uses_CVOGCharacter_CheckMissionRequirements
// Address:   0x004e25d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Uses_CVOGCharacter_CheckMissionRequireme: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004e0eb0, FUN_004e25d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Uses_CVOGCharacter_CheckMissionRequirements
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

int __thiscall Named_CalleeOf_Mission_Uses_CVOGCharacter_CheckMissionRequireme_004e25d0(int param_1,uint param_2)



{

  int extraout_EDX;

  int iVar1;

  uint unaff_ESI;

  

  iVar1 = *(int *)(param_1 + 4);

  if ((iVar1 == 0) || (unaff_ESI = param_2, (uint)(*(int *)(param_1 + 8) - iVar1 >> 3) <= param_2))

  {

    FUN_004e0eb0();

    iVar1 = extraout_EDX;

    param_2 = unaff_ESI;

  }

  return iVar1 + param_2 * 8;

}
