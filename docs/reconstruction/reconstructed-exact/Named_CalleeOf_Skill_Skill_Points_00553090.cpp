// =============================================================================
// Named_CalleeOf_Skill_Skill_Points_00553090
// -----------------------------------------------------------------------------
// Stable ID: aa_00553090
// Callee of Skill_Skill_Points
// Address:   0x00553090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_Points: skill/cast helper. Evidence string: "(+%d)". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "(+%d)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: sprintf×2, FUN_00552f50, FUN_00553090, FUN_007a69d0, FUN_007a6de0, d.
//  - Strings: "(+%d)"; "%s %d%s/%d (Max: %d)\n".
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

void __thiscall Named_CalleeOf_Skill_Skill_Points_00553090(int param_1,char *param_2,int param_3)



{

  short sVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  undefined *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  char local_40;

  uint32_t /* width from decompiler */ local_3f;

  

  local_40 = '\0';

  puVar5 = &local_3f;

  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  *(uint8_t *)((int)puVar5 + 2) = 0;

  if (param_3 != 0) {

    if (*(short *)(param_1 + 0x174) != 0) {

      sprintf(&local_40,"(+%d)",(int)*(short *)(param_1 + 0x174));

    }

    sVar1 = *(short *)(param_1 + 0x5f6);

    uVar4 = (uint)*(byte *)(param_1 + 0x5f4);

    uVar2 = FUN_00552f50(param_3);

    uVar7 = 0xffffffff;

    puVar6 = &DAT_00a6b1cc;

    FUN_007a69d0(&DAT_00a6b1cc,0xffffffff,(int)sVar1,&local_40,uVar2,uVar4);

    uVar2 = FUN_007a6de0(puVar6,uVar7);

    sprintf(param_2,"%s %d%s/%d (Max: %d)\n",uVar2);

  }

  return;

}
