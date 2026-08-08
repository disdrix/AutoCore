// =============================================================================
// RETIRED SCAFFOLD (R10-014 2026-08-05) — do not use as product name
// Canonical: Mission_FormatDialogTokenValue_Inferred
//   docs/reconstruction/reconstructed-exact/Mission_FormatDialogTokenValue_Inferred.cpp
// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_005792d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005792d0
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_no_choices_fro
// Address:   0x005792d0  (autoassault.exe, image base 0x400000)
// System:    missions-progression (was unknown)
// Generated: 2026-07-23 from raw capture; RETIRED by R10-014 dual
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_no_choices_fro: mission/objective helper. Evidence string: "!Non-Character Faction not implemented yet!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "!Non-Character Faction not implemented yet!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: return×11, if×9, do×8, while×8, switch×1.
//  - Notable callees: FUN_007a6de0×7, FUN_00521800×2, FUN_00521900×2, CVOGMap_LookupVariable, FUN_005792d0, FUN_007a69d0, TFID_EqualsObjectId, sprintf.
//  - Strings: "!Non-Character Faction not implemented yet!".
//  - Return sites: 11.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_no_choices_fro
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

uint32_t /* width from decompiler */ __thiscall

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_005792d0(int param_1,char *param_2,char *param_3,uint8_t *param_4,float param_5,int *param_6)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  char *unaff_EBX;

  char *unaff_retaddr;

  uint32_t /* width from decompiler */ uVar6;

  

  FUN_007a69d0();

  piVar1 = param_6;

  switch(*param_4) {

  case 0:

    param_5 = 0.0;

    if ((param_6 == (int *)0x0) ||

       (iVar3 = TFID_EqualsObjectId(param_6 + 0x58,(void *)(param_1 + 0x30)), (char)iVar3 == '\0'))

    {

      cVar2 = CVOGMap_LookupVariable(*(uint32_t /* width from decompiler */ *)(param_4 + 4),&param_5,piVar1);

      if (cVar2 == '\0') {

        return 0;

      }

    }

    else {

      param_5 = *(float *)(param_4 + 8);

    }

    sprintf(param_2,param_3,(double)param_5);

    return 1;

  case 1:

    if (param_5 != 0.0) {

      pcVar5 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)((int)param_5 + 4) + 4) + 4 +

                                            (int)param_5) + 0x160))();

      do {

        cVar2 = *pcVar5;

        *param_2 = cVar2;

        pcVar5 = pcVar5 + 1;

        param_2 = param_2 + 1;

      } while (cVar2 != '\0');

      return 1;

    }

    break;

  case 2:

    if (param_5 != 0.0) {

      uVar6 = 0xffffffff;

      uVar4 = FUN_00521900();

      pcVar5 = (char *)FUN_007a6de0(uVar4,uVar6);

      do {

        cVar2 = *pcVar5;

        *param_2 = cVar2;

        pcVar5 = pcVar5 + 1;

        param_2 = param_2 + 1;

      } while (cVar2 != '\0');

      return 1;

    }

    break;

  case 3:

    if (param_5 != 0.0) {

      uVar6 = 0xffffffff;

      uVar4 = FUN_00521800();

      pcVar5 = (char *)FUN_007a6de0(uVar4,uVar6);

      do {

        cVar2 = *pcVar5;

        *param_2 = cVar2;

        pcVar5 = pcVar5 + 1;

        param_2 = param_2 + 1;

      } while (cVar2 != '\0');

      return 1;

    }

    break;

  case 4:

    if ((param_6 != (int *)0x0) && (iVar3 = (**(code **)(*param_6 + 0x210))(), iVar3 != 0)) {

      (**(code **)(*piVar1 + 0x210))(0,0xffffffff);

      uVar4 = FUN_00521800();

      pcVar5 = (char *)FUN_007a6de0(uVar4);

      do {

        cVar2 = *pcVar5;

        *unaff_retaddr = cVar2;

        pcVar5 = pcVar5 + 1;

        unaff_retaddr = unaff_retaddr + 1;

      } while (cVar2 != '\0');

      return 1;

    }

    pcVar5 = (char *)FUN_007a6de0("!Non-Character Faction not implemented yet!",0xffffffff);

    do {

      cVar2 = *pcVar5;

      *param_2 = cVar2;

      pcVar5 = pcVar5 + 1;

      param_2 = param_2 + 1;

    } while (cVar2 != '\0');

    return 1;

  case 5:

    if (param_6 != (int *)0x0) {

      iVar3 = (**(code **)(*param_6 + 0x210))();

      if (iVar3 != 0) {

        iVar3 = (**(code **)(*piVar1 + 0x210))(0);

        uVar6 = 0xffffffff;

        uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x160))

                          (0xffffffff);

        pcVar5 = (char *)FUN_007a6de0(uVar4,uVar6);

        do {

          cVar2 = *pcVar5;

          *unaff_EBX = cVar2;

          pcVar5 = pcVar5 + 1;

          unaff_EBX = unaff_EBX + 1;

        } while (cVar2 != '\0');

        return 1;

      }

      pcVar5 = (char *)FUN_007a6de0(piVar1[0x2a] + 0x40,0xffffffff);

      do {

        cVar2 = *pcVar5;

        *unaff_retaddr = cVar2;

        pcVar5 = pcVar5 + 1;

        unaff_retaddr = unaff_retaddr + 1;

      } while (cVar2 != '\0');

      return 1;

    }

    break;

  case 6:

    if ((param_6 != (int *)0x0) && (iVar3 = (**(code **)(*param_6 + 0x210))(), iVar3 != 0)) {

      (**(code **)(*piVar1 + 0x210))(0,0xffffffff);

      uVar4 = FUN_00521900();

      pcVar5 = (char *)FUN_007a6de0(uVar4);

      do {

        cVar2 = *pcVar5;

        *unaff_retaddr = cVar2;

        pcVar5 = pcVar5 + 1;

        unaff_retaddr = unaff_retaddr + 1;

      } while (cVar2 != '\0');

      return 0;

    }

    *param_2 = '\0';

  }

  return 0;

}
