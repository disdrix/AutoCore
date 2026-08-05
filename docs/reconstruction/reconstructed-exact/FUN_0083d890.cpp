// =============================================================================
// FUN_0083d890
// -----------------------------------------------------------------------------
// Stable ID: aa_0083d890
// Address:   0x0083d890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083d890 @ 0x0083d890
// Stable ID: aa_0083d890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, return×6, switch×1.
//  - Notable callees: __RTDynamicCast×2, Client_CastSkillFromQuickBarSlot, FUN_007fc970, FUN_007fd3d0, FUN_0083d890.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall FUN_0083d890(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  char cVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint8_t auStack_10 [16];

  

  if (49999 < param_3) {

    switch(param_2) {

    case 5:

      if ((param_1[0x14e] != 0) && (param_1[0x12e] != 0)) {

        piVar2 = (int *)__RTDynamicCast(param_1[0x12e],0,&CNDUIWindow::RTTI_Type_Descriptor,

                                        &CBtnSkill::RTTI_Type_Descriptor,0);

        if ((piVar2 != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 0xd8))(), cVar1 != '\0')) {

          uVar5 = 1;

          uVar4 = 1;

          (**(code **)(*piVar2 + 0x120))(auStack_10,1,1);

          puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar2 + 0x140))(&stack0xffffffec,1);

          FUN_007fd3d0(uVar4,uVar5,*puVar3,puVar3[1]);

        }

        return 1;

      }

      break;

    case 6:

      FUN_007fc970();

      return 1;

    case 7:

      if ((param_1[0x14e] != 0) && (param_1[0x12e] != 0)) {

        piVar2 = (int *)__RTDynamicCast(param_1[0x12e],0,&CNDUIWindow::RTTI_Type_Descriptor,

                                        &CBtnSkill::RTTI_Type_Descriptor,0);

        if ((piVar2 != (int *)0x0) &&

           (((piVar2[0x182] != 0 && (cVar1 = (**(code **)(*piVar2 + 0xd8))(), cVar1 != '\0')) &&

            ((*(byte *)(piVar2[0x182] + 0x639) & 2) != 0)))) {

          Client_CastSkillFromQuickBarSlot(*(uint32_t /* width from decompiler */ *)(piVar2[0x182] + 0x620));

        }

        return 1;

      }

      break;

    case 0x12:

      return 1;

    }

  }

  cVar1 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar1 != '\0') && (param_1[0xac] != 0)) {

    uVar4 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar4;

  }

  return 0;

}
