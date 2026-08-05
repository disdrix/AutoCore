// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00513bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00513bc0
// Callee of Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to
// Address:   0x00513bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×5, goto×2, return×2.
//  - Notable callees: CONCAT31, FUN_00513bc0.
//  - Return sites: 2.

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

uint __thiscall Named_CalleeOf_Named_CalleeOf_Skill_You_do_not_possess_the_Tink_00513bc0(int param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  

  uVar2 = 0;

  if (param_2 == 0) goto LAB_00513c02;

  iVar1 = *(int *)(param_1 + 0xa8);

  uVar3 = *(uint *)(param_2 + 0xb4);

  if (uVar3 != *(uint *)(iVar1 + 0x38)) {

    if (uVar3 == 0x44) {

      uVar2 = 0;

      uVar3 = 0;

      if (*(short *)(*(int *)(iVar1 + 0x3c) + 0x3f4) != 10) goto LAB_00513c02;

    }

    else {

      uVar2 = uVar3 - 0x46;

      if ((uVar2 != 0) ||

         (uVar2 = *(uint *)(iVar1 + 0x3c), uVar3 = uVar2, *(short *)(uVar2 + 0x3f4) != 0xb)) {

LAB_00513c02:

        return uVar2 & 0xffffff00;

      }

    }

  }

  return CONCAT31((int3)(uVar3 >> 8),1);

}
