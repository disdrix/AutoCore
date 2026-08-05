// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_Combat_Fighting_and_driving_00755e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00755e80
// Callee of Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect
// Address:   0x00755e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00755e80×2, FUN_0074e260.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Skill_Combat_Fighting_and_driving_ability_Affect
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

void Named_CalleeOf_Named_CalleeOf_Skill_Combat_Fighting_and_driving_00755e80(int *param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = (**(code **)(*param_1 + 4))();

  if (iVar1 == 0x474c5442) {

    FUN_0074e260(param_1[0x23]);

  }

  if (param_1[0x1b] == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = param_1[0x1c] - param_1[0x1b] >> 2;

  }

  iVar2 = 0;

  if (0 < iVar1) {

    do {

      Named_CalleeOf_Named_CalleeOf_Skill_Combat_Fighting_and_driving_00755e80(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0x1b] + iVar2 * 4) + 8));

      iVar2 = iVar2 + 1;

    } while (iVar2 < iVar1);

  }

  return;

}
