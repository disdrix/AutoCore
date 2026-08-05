// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00521eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00521eb0
// Callee of Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to
// Address:   0x00521eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×7, if×1, switch×1.
//  - Notable callees: FUN_00521eb0.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to
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

byte __fastcall Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00521eb0(int param_1)



{

  byte bVar1;

  

  bVar1 = *(byte *)(param_1 + 0x59b);

  if (bVar1 != 0) {

    switch(bVar1) {

    case 1:

    case 2:

      return 1;

    case 3:

    case 4:

      return 2;

    case 5:

    case 6:

      return 3;

    case 7:

    case 8:

      return 4;

    case 9:

      return 5;

    default:

      return -(9 < bVar1) & 5;

    }

  }

  return 0;

}
