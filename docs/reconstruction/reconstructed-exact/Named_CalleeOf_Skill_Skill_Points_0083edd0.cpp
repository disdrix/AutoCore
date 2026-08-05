// =============================================================================
// Named_CalleeOf_Skill_Skill_Points_0083edd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083edd0
// Callee of Skill_Skill_Points
// Address:   0x0083edd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_Points: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, if×1, return×1.
//  - Notable callees: FUN_0083edd0.
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

void Named_CalleeOf_Skill_Skill_Points_0083edd0(void)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  char *unaff_ESI;

  

  pcVar2 = unaff_ESI;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  iVar3 = (int)pcVar2 - (int)(unaff_ESI + 1);

  if ((0 < iVar3) && (unaff_ESI[iVar3 + -1] == '\n')) {

    unaff_ESI[iVar3 + -1] = '\0';

  }

  return;

}
