// =============================================================================
// Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00513400
// -----------------------------------------------------------------------------
// Stable ID: aa_00513400
// Callee of Skill_You_do_not_possess_the_Tinkering_skill_to_work_o
// Address:   0x00513400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_You_do_not_possess_the_Tinkering_skill_to: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, goto×2, do×1, while×1.
//  - Notable callees: FUN_00513400.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Skill_You_do_not_possess_the_Tinkering_skill_to_work_o
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00513400(int *param_1,int param_2)



{

  int iVar1;

  short sVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  

  iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x3c) +

                  0x4c4);

  iVar1 = param_1[0x2a];

  if (iVar3 != *(int *)(iVar1 + 0x38)) {

    if (iVar3 == 0x44) {

      if (*(short *)(*(int *)(iVar1 + 0x3c) + 0x3f4) == 10) goto LAB_00513457;

    }

    else if ((iVar3 == 0x46) && (*(short *)(*(int *)(iVar1 + 0x3c) + 0x3f4) == 0xb))

    goto LAB_00513457;

    return 2;

  }

LAB_00513457:

  sVar2 = (**(code **)(*param_1 + 0x8c))();

  iVar3 = (**(code **)(*param_1 + 0x80))();

  if (sVar2 == iVar3) {

    return 1;

  }

  uVar6 = 0;

  iVar3 = (**(code **)(*param_1 + 0x80))();

  if (iVar3 != 0) {

    do {

      uVar5 = *(uint *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x34);

      uVar4 = (**(code **)(*param_1 + 0x7c))(uVar6);

      if ((uVar4 & 0xffff) == uVar5) {

        return 3;

      }

      uVar6 = uVar6 + 1;

      uVar5 = (**(code **)(*param_1 + 0x80))();

    } while (uVar6 < uVar5);

  }

  return 0;

}
