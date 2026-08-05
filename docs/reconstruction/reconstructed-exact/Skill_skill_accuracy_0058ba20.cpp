// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×15, return×13, goto×3, switch×1.
//  - Notable callees: strncmp×12, sprintf×9, FUN_00412c60×5, FUN_0058ba20, tolower.
//  - Strings: "accuracy_bonus"; "%+d"; "criticals_vs_vehicles"; "criticals_vs_creatures".
//  - Return sites: 13.

// =============================================================================
// Skill_skill_accuracy_0058ba20
// -----------------------------------------------------------------------------
// Stable ID: aa_0058ba20
// Address:   0x0058ba20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "skill_accuracy"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Skill_skill_accuracy_0058ba20(int param_1,char *param_2,char *param_3)



{

  int iVar1;

  float10 fVar2;

  

  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {

    return 0;

  }

  iVar1 = tolower((int)*param_2);

  switch(iVar1) {

  case 0x61:

    iVar1 = strncmp(param_2,"accuracy_bonus",0xe);

    if (iVar1 == 0) {

      sprintf(param_3,"%+d");

      return 1;

    }

    break;

  case 99:

    iVar1 = strncmp(param_2,"criticals_vs_vehicles",0x15);

    if (iVar1 != 0) {

      iVar1 = strncmp(param_2,"criticals_vs_creatures",0x16);

      if (iVar1 == 0) {

        fVar2 = (float10)FUN_00412c60();

        sprintf(param_3,"%+g%%",(double)fVar2);

        return 1;

      }

      iVar1 = strncmp(param_2,"criticals_def_vehicles",0x16);

      if (iVar1 == 0) {

        fVar2 = (float10)FUN_00412c60();

        sprintf(param_3,"%+g%%",(double)fVar2);

        return 1;

      }

      iVar1 = strncmp(param_2,"criticals_def_creatures",0x17);

      if (iVar1 != 0) {

        return 0;

      }

    }

    fVar2 = (float10)FUN_00412c60();

    sprintf(param_3,"%+g%%",(double)fVar2);

    return 1;

  case 100:

    iVar1 = strncmp(param_2,"defense_bonus",0xd);

    if ((iVar1 == 0) || (iVar1 = strncmp(param_2,"deflection_bonus",0x10), iVar1 == 0))

    goto LAB_0058bc1b;

    break;

  case 0x6d:

    iVar1 = strncmp(param_2,"max_hp",6);

    if (iVar1 == 0) {

      if ((*(float *)(param_1 + 0x4c) <= g_flOne) && (DAT_00aaa668 <= *(float *)(param_1 + 0x4c))) {

LAB_0058bdb2:

        fVar2 = (float10)FUN_00412c60();

        sprintf(param_3,"%+g%%",(double)fVar2);

        return 1;

      }

    }

    else {

      iVar1 = strncmp(param_2,"max_power",9);

      if (iVar1 != 0) {

        return 0;

      }

      if ((*(float *)(param_1 + 0x48) <= g_flOne) && (DAT_00aaa668 <= *(float *)(param_1 + 0x48)))

      goto LAB_0058bdb2;

    }

LAB_0058bc1b:

    sprintf(param_3,"%+d");

    return 1;

  case 0x70:

    iVar1 = strncmp(param_2,"penetration_bonus",0x11);

    if (iVar1 == 0) {

      sprintf(param_3,"%+d");

      return 1;

    }

    iVar1 = strncmp(param_2,"power_cost",10);

    if (iVar1 == 0) {

      fVar2 = (float10)FUN_00412c60();

      sprintf(param_3,"%+g%%",(double)fVar2);

      return 1;

    }

    break;

  case 0x73:

    iVar1 = strncmp(param_2,"skill_accuracy",0xe);

    if (iVar1 == 0) {

      if (*(float *)(param_1 + 0x24) == DAT_00aaa668) {

        sprintf(param_3,"100%%");

        return 1;

      }

      goto LAB_0058bdb2;

    }

  }

  return 0;

}
