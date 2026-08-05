// =============================================================================
// Named_CalleeOf_Skill_Skill_Points_007fcb80
// -----------------------------------------------------------------------------
// Stable ID: aa_007fcb80
// Callee of Skill_Skill_Points (+1 other named callers)
// Address:   0x007fcb80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_Points: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Skill_Skill_Points (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_007fcb80.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_Points (+1 other named callers)
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

int Named_CalleeOf_Skill_Skill_Points_007fcb80(void)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  int unaff_ESI;

  

  if ((DAT_00d1b778 != (int *)0x0) &&

     (cVar3 = (**(code **)(*DAT_00d1b778 + 0x3d8))(), piVar2 = DAT_00d1d898, cVar3 != '\0')) {

    for (; piVar2 != DAT_00d1d89c; piVar2 = piVar2 + 1) {

      if (((*piVar2 != 0) && (iVar1 = *(int *)(*piVar2 + 0x534), iVar1 != 0)) &&

         (iVar1 == unaff_ESI)) {

        return *piVar2;

      }

    }

  }

  return 0;

}
