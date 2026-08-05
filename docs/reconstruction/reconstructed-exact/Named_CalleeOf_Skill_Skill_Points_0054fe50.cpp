// =============================================================================
// Named_CalleeOf_Skill_Skill_Points_0054fe50
// -----------------------------------------------------------------------------
// Stable ID: aa_0054fe50
// Callee of Skill_Skill_Points
// Address:   0x0054fe50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_Points: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0054fe50, ROUND, ceil.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_Points
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

uint __fastcall Named_CalleeOf_Skill_Skill_Points_0054fe50(int param_1)



{

  uint uVar1;

  double dVar2;

  

  uVar1 = (uint)*(byte *)(param_1 + 0x5fb);

  if (g_flZero < *(float *)(param_1 + 4)) {

    dVar2 = ceil((double)((float)(int)*(short *)(param_1 + 0x5f6) / *(float *)(param_1 + 4)));

    uVar1 = uVar1 + (int)ROUND(dVar2);

  }

  return uVar1;

}
