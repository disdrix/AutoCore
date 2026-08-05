// =============================================================================
// Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_0058a1b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058a1b0
// Callee of Skill_Skill_d_had_invalid_creature_d (+1 other named callers)
// Address:   0x0058a1b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_d_had_invalid_creature_d: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Skill_Skill_d_had_invalid_creature_d (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00404c30, FUN_00404c60, FUN_00512160, FUN_0058a1b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_d_had_invalid_creature_d (+1 other named callers)
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

void Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_0058a1b0(int *param_1,int param_2,char param_3)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  

  if ((param_1 != (int *)0x0) && (param_2 != 0)) {

    iVar1 = (**(code **)(*param_1 + 0x214))();

    if (iVar1 == 0) {

      uVar2 = *(uint *)(param_2 + 0xe6e0);

      iVar3 = *(int *)(param_2 + 0xe6e4);

      *(uint *)(param_2 + 0xe6e0) = uVar2 + 1;

      *(uint *)(param_2 + 0xe6e4) = iVar3 + (uint)(0xfffffffe < uVar2);

    }

    else {

      uVar2 = *(uint *)(param_2 + 0xe6d8);

      iVar3 = *(int *)(param_2 + 0xe6dc);

      *(uint *)(param_2 + 0xe6d8) = uVar2 + 1;

      *(uint *)(param_2 + 0xe6dc) = iVar3 + (uint)(0xfffffffe < uVar2);

    }

    FUN_00512160(uVar2,iVar3,iVar1 == 0);

    (**(code **)(*param_1 + 0x218))(param_2);

    (**(code **)(*param_1 + 0x2a4))(*(uint32_t /* width from decompiler */ *)(param_2 + 0xe4e8));

    if ((param_3 != '\0') && (((uint)param_1[0x5f] >> 5 & 1) != 0)) {

      FUN_00404c60(param_1);

      FUN_00404c30(param_2);

    }

  }

  return;

}
