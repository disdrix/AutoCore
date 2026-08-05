// READABILITY (auto CF):
//  - Body size: ~234 non-empty decompiler lines.
//  - Control keywords: do×14, while×14, return×12, if×11, for×8, goto×2, switch×1.
//  - Notable callees: FUN_007a6de0×9, FUN_00807440×3, FUN_00418ca0, FUN_007a4480, FUN_007a69d0, FUN_007fdfb0, FUN_008073b0, FUN_008096c0.
//  - Strings: "You have been forced to quit due to multiple logins.\n"; "\nClick Accept to return to the login screen."; "Connection to global terminated:\n"; "You have been forced to quit due to GM action.\n".
//  - Return sites: 12.

// =============================================================================
// Auth_You_have_been_forced_to_quit_due_to_multiple_log_008096c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008096c0
// Address:   0x008096c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "You have been forced to quit due to multiple logins.
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Auth_You_have_been_forced_to_quit_due_to_multiple_log_008096c0(int param_1,char param_2,int param_3)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  char *pcVar4;

  undefined *puVar5;

  uint uVar6;

  uint uVar7;

  char *pcVar8;

  char *pcVar9;

  int *piVar10;

  char *pcVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ *puVar13;

  uint32_t /* width from decompiler */ local_468 [2];

  uint32_t /* width from decompiler */ local_460;

  uint32_t /* width from decompiler */ local_45c;

  uint32_t /* width from decompiler */ local_458;

  uint32_t /* width from decompiler */ local_450 [19];

  char cStack_401;

  char local_400 [1024];

  

  piVar10 = (int *)(param_1 + 4);

  piVar2 = piVar10;

  if (0xf < *(uint *)(param_1 + 0x18)) {

    piVar2 = (int *)*piVar10;

  }

  FUN_007a4480(0,"Got global connect succeed:%d reconnecting:%d coid:%I64d str:%s",param_2,

               *(uint8_t *)(param_3 + 0x854),*(uint32_t /* width from decompiler */ *)(param_3 + 0x508),

               *(uint32_t /* width from decompiler */ *)(param_3 + 0x50c),piVar2);

  if (param_2 != '\0') {

    if (*(char *)(param_3 + 0x854) == '\0') {

      if (*(char *)(param_3 + 0xa6) != '\0') {

        FUN_00821ac0(*(int *)(param_3 + 0xe0c) + 0x2d);

      }

      puVar13 = local_450;

      FUN_00821af0();

      uVar12 = 0x50;

    }

    else {

      local_460 = *(uint32_t /* width from decompiler */ *)(param_3 + 0x508);

      local_45c = *(uint32_t /* width from decompiler */ *)(param_3 + 0x50c);

      local_458 = *(uint32_t /* width from decompiler */ *)(param_3 + 0x134);

      puVar13 = local_468;

      *(uint8_t *)(param_3 + 0x854) = 0;

      local_468[0] = 0x8003;

      uVar12 = 0x18;

    }

    FUN_008073b0(uVar12,puVar13);

    FUN_0092dcc0(param_3);

    return;

  }

  FUN_007a69d0();

  *(uint8_t *)(param_3 + 0x854) = 0;

  if (0xf < *(uint *)(param_1 + 0x18)) {

    piVar10 = (int *)*piVar10;

  }

  iVar3 = FUN_00418ca0(piVar10);

  switch(iVar3) {

  case 3:

    cVar1 = FUN_00807440();

    if (cVar1 != '\0') {

      return;

    }

    pcVar4 = (char *)FUN_007a6de0("You have been forced to quit due to multiple logins.\n",

                                  0xffffffff);

    pcVar8 = local_400;

    do {

      cVar1 = *pcVar4;

      *pcVar8 = cVar1;

      pcVar4 = pcVar4 + 1;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    pcVar4 = (char *)FUN_007a6de0("\nClick Accept to return to the login screen.",0xffffffff);

    pcVar8 = pcVar4;

    do {

      cVar1 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    pcVar11 = &cStack_401;

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar4;

    for (uVar6 = (uint)((int)pcVar8 - (int)pcVar4) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar6 = (int)pcVar8 - (int)pcVar4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

    break;

  default:

    if ((*(int **)(param_3 + 0xc78) != (int *)0x0) &&

       (cVar1 = (**(code **)(**(int **)(param_3 + 0xc78) + 8))(), cVar1 != '\0')) {

      return;

    }

    pcVar4 = (char *)FUN_007a6de0("Connection to global terminated:\n",0xffffffff);

    pcVar8 = local_400;

    do {

      cVar1 = *pcVar4;

      *pcVar8 = cVar1;

      pcVar4 = pcVar4 + 1;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    puVar5 = PTR_s_unknown_00af3e00;

    if ((iVar3 < 0xd) && (-1 < iVar3)) {

      puVar5 = (&PTR_s_unknown_00af3e00)[iVar3];

    }

    pcVar4 = (char *)FUN_007a6de0(puVar5,0xffffffff);

    pcVar8 = pcVar4;

    do {

      cVar1 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    pcVar11 = &cStack_401;

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar4;

    for (uVar6 = (uint)((int)pcVar8 - (int)pcVar4) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar6 = (int)pcVar8 - (int)pcVar4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

    pcVar4 = (char *)FUN_007a6de0("\nClick Accept to return to the login screen.",0xffffffff);

    pcVar8 = pcVar4;

    do {

      cVar1 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    uVar6 = (int)pcVar8 - (int)pcVar4;

    pcVar8 = &cStack_401;

    do {

      pcVar11 = pcVar8 + 1;

      pcVar8 = pcVar8 + 1;

    } while (*pcVar11 != '\0');

    goto LAB_00809a6e;

  case 8:

    Sleep(0x5dc);

    if (*(int **)(param_3 + 0xc7c) == (int *)0x0) {

      return;

    }

    (**(code **)(**(int **)(param_3 + 0xc7c) + 4))();

    return;

  case 9:

    goto switchD_008097ed_caseD_9;

  case 0xb:

    cVar1 = FUN_00807440();

    if (cVar1 != '\0') {

      return;

    }

    pcVar4 = (char *)FUN_007a6de0("You have been forced to quit due to GM action.\n",0xffffffff);

    pcVar8 = local_400;

    do {

      cVar1 = *pcVar4;

      *pcVar8 = cVar1;

      pcVar4 = pcVar4 + 1;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    pcVar4 = (char *)FUN_007a6de0("\nClick Accept to return to the login screen.",0xffffffff);

    pcVar8 = pcVar4;

    do {

      cVar1 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    uVar6 = (int)pcVar8 - (int)pcVar4;

    pcVar8 = &cStack_401;

    do {

      pcVar11 = pcVar8 + 1;

      pcVar8 = pcVar8 + 1;

    } while (*pcVar11 != '\0');

LAB_00809a6e:

    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar4;

      pcVar4 = pcVar4 + 4;

      pcVar8 = pcVar8 + 4;

    }

    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

      *pcVar8 = *pcVar4;

      pcVar4 = pcVar4 + 1;

      pcVar8 = pcVar8 + 1;

    }

    break;

  case 0xc:

    cVar1 = FUN_00807440();

    if (cVar1 != '\0') {

      return;

    }

    pcVar4 = (char *)FUN_007a6de0("You have been banned due to GM action.\n",0xffffffff);

    pcVar8 = local_400;

    do {

      cVar1 = *pcVar4;

      *pcVar8 = cVar1;

      pcVar4 = pcVar4 + 1;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    pcVar4 = (char *)FUN_007a6de0("\nClick Accept to return to the login screen.",0xffffffff);

    pcVar8 = pcVar4;

    do {

      cVar1 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    pcVar11 = &cStack_401;

    do {

      pcVar9 = pcVar11 + 1;

      pcVar11 = pcVar11 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar4;

    for (uVar6 = (uint)((int)pcVar8 - (int)pcVar4) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar11 = pcVar11 + 4;

    }

    for (uVar6 = (int)pcVar8 - (int)pcVar4 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

      *pcVar11 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar11 = pcVar11 + 1;

    }

  }

  FUN_007fdfb0(param_3,local_400,0xffffffff,1,0);

switchD_008097ed_caseD_9:

  return;

}
