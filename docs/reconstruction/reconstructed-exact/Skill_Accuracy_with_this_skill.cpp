// READABILITY (auto CF):
//  - Body size: ~405 non-empty decompiler lines.
//  - Control keywords: do×24, while×24, for×24, if×19, return×2.
//  - Notable callees: FUN_007a6de0×15, sprintf×13, SUB84×5, Def×2, FUN_00412c60, FUN_0058ae10, FUN_007a69d0.
//  - Strings: "Max HP"; "%s: %+d\n"; "%s: %+d%%\n"; "Power Cost".
//  - Return sites: 2.

// =============================================================================
// Skill_Accuracy_with_this_skill
// -----------------------------------------------------------------------------
// Stable ID: aa_0058ae10
// Address:   0x0058ae10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Accuracy with this skill"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

char Skill_Accuracy_with_this_skill(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,float param_4)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint uVar5;

  char *pcVar6;

  float10 fVar7;

  float fVar8;

  char *pcVar9;

  double dVar10;

  char local_405;

  char local_400 [1024];

  

  FUN_007a69d0();

  local_405 = '\0';

  if (*(float *)(param_3 + 0x4c) != 0.0) {

    if ((g_flOne < *(float *)(param_3 + 0x4c)) || (*(float *)(param_3 + 0x4c) < DAT_00aaa668)) {

      iVar2 = (int)(*(float *)(param_3 + 0x4c) * param_4);

      uVar3 = FUN_007a6de0("Max HP",0xffffffff);

      pcVar9 = "%s: %+d\n";

    }

    else {

      iVar2 = (int)(*(float *)(param_3 + 0x4c) * param_4 * DAT_00aaa7ac);

      uVar3 = FUN_007a6de0("Max HP",0xffffffff);

      pcVar9 = "%s: %+d%%\n";

    }

    sprintf(local_400,pcVar9,uVar3,iVar2);

    pcVar9 = local_400;

    do {

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar9 - (int)local_400;

    pcVar9 = (char *)(param_1 + -1);

    do {

      pcVar6 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_400;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar9 = pcVar9 + 4;

    }

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar9 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    }

    local_405 = '\x01';

  }

  if (*(float *)(param_3 + 0x44) != 0.0) {

    iVar2 = (int)(*(float *)(param_3 + 0x44) * param_4 * DAT_00aaa7ac);

    uVar3 = FUN_007a6de0("Power Cost",0xffffffff);

    sprintf(local_400,"%s: %+d%%\n",uVar3,iVar2);

    pcVar9 = local_400;

    do {

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar9 - (int)local_400;

    pcVar9 = (char *)(param_1 + -1);

    do {

      pcVar6 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_400;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar9 = pcVar9 + 4;

    }

    local_405 = local_405 + '\x01';

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar9 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    }

  }

  if (*(float *)(param_3 + 0x48) != 0.0) {

    if ((g_flOne < *(float *)(param_3 + 0x48)) || (*(float *)(param_3 + 0x48) < DAT_00aaa668)) {

      iVar2 = (int)(*(float *)(param_3 + 0x48) * param_4);

      uVar3 = FUN_007a6de0("Max Power",0xffffffff);

      pcVar9 = "%s: %+d\n";

    }

    else {

      iVar2 = (int)(*(float *)(param_3 + 0x48) * param_4 * DAT_00aaa7ac);

      uVar3 = FUN_007a6de0("Max Power",0xffffffff);

      pcVar9 = "%s: %+d%%\n";

    }

    sprintf(local_400,pcVar9,uVar3,iVar2);

    pcVar9 = local_400;

    do {

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar9 - (int)local_400;

    pcVar9 = (char *)(param_1 + -1);

    do {

      pcVar6 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_400;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar9 = pcVar9 + 4;

    }

    local_405 = local_405 + '\x01';

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar9 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    }

  }

  if (*(float *)(param_3 + 0xc0) != 0.0) {

    fVar8 = *(float *)(param_3 + 0xc0) * param_4 * DAT_00a0f520;

    if (0.0 <= fVar8) {

      fVar8 = fVar8 + g_flMissionXpRoundBias;

    }

    else {

      fVar8 = fVar8 - g_flMissionXpRoundBias;

    }

    dVar10 = (double)((float)(int)fVar8 * g_flMultiKillCountBlend);

    uVar3 = FUN_007a6de0("Criticals vs Vehicles",0xffffffff);

    sprintf(local_400,"%s: %+g%%\n",uVar3,SUB84(dVar10,0),(int)((ulonglong)dVar10 >> 0x20));

    pcVar9 = local_400;

    do {

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar9 - (int)local_400;

    pcVar9 = (char *)(param_1 + -1);

    do {

      pcVar6 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_400;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar9 = pcVar9 + 4;

    }

    local_405 = local_405 + '\x01';

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar9 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    }

  }

  if (*(float *)(param_3 + 0xc4) != 0.0) {

    fVar8 = param_4 * *(float *)(param_3 + 0xc4) * DAT_00a0f520;

    if (0.0 <= fVar8) {

      fVar8 = fVar8 + g_flMissionXpRoundBias;

    }

    else {

      fVar8 = fVar8 - g_flMissionXpRoundBias;

    }

    dVar10 = (double)((float)(int)fVar8 * g_flMultiKillCountBlend);

    uVar3 = FUN_007a6de0("Criticals vs Creatures",0xffffffff);

    sprintf(local_400,"%s: %+g%%\n",uVar3,SUB84(dVar10,0),(int)((ulonglong)dVar10 >> 0x20));

    pcVar9 = local_400;

    do {

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar9 - (int)local_400;

    pcVar9 = (char *)(param_1 + -1);

    do {

      pcVar6 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_400;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar9 = pcVar9 + 4;

    }

    local_405 = local_405 + '\x01';

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar9 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    }

  }

  if (*(float *)(param_3 + 200) != 0.0) {

    fVar8 = *(float *)(param_3 + 200) * param_4 * DAT_00a0f520;

    if (0.0 <= fVar8) {

      fVar8 = fVar8 + g_flMissionXpRoundBias;

    }

    else {

      fVar8 = fVar8 - g_flMissionXpRoundBias;

    }

    dVar10 = (double)((float)(int)fVar8 * g_flMultiKillCountBlend);

    uVar3 = FUN_007a6de0("Critical Def (Vehicles)",0xffffffff);

    sprintf(local_400,"%s: %+g%%\n",uVar3,SUB84(dVar10,0),(int)((ulonglong)dVar10 >> 0x20));

    pcVar9 = local_400;

    do {

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar9 - (int)local_400;

    pcVar9 = (char *)(param_1 + -1);

    do {

      pcVar6 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_400;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar9 = pcVar9 + 4;

    }

    local_405 = local_405 + '\x01';

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar9 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    }

  }

  if (*(float *)(param_3 + 0xcc) != 0.0) {

    fVar8 = *(float *)(param_3 + 0xcc) * param_4 * DAT_00a0f520;

    if (0.0 <= fVar8) {

      fVar8 = fVar8 + g_flMissionXpRoundBias;

    }

    else {

      fVar8 = fVar8 - g_flMissionXpRoundBias;

    }

    dVar10 = (double)((float)(int)fVar8 * g_flMultiKillCountBlend);

    uVar3 = FUN_007a6de0("Critical Def (Creatures)",0xffffffff);

    sprintf(local_400,"%s: %+g%%\n",uVar3,SUB84(dVar10,0),(int)((ulonglong)dVar10 >> 0x20));

    pcVar9 = local_400;

    do {

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar9 - (int)local_400;

    pcVar9 = (char *)(param_1 + -1);

    do {

      pcVar6 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_400;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar9 = pcVar9 + 4;

    }

    local_405 = local_405 + '\x01';

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar9 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    }

  }

  if (*(float *)(param_3 + 0xf8) != 0.0) {

    iVar2 = (int)(*(float *)(param_3 + 0xf8) * param_4);

    uVar3 = FUN_007a6de0("Accuracy Bonus",0xffffffff);

    sprintf(local_400,"%s: %+d\n",uVar3,iVar2);

    pcVar9 = local_400;

    do {

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar9 - (int)local_400;

    pcVar9 = (char *)(param_1 + -1);

    do {

      pcVar6 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_400;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar9 = pcVar9 + 4;

    }

    local_405 = local_405 + '\x01';

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar9 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    }

  }

  if (*(float *)(param_3 + 0xfc) != 0.0) {

    iVar2 = (int)(*(float *)(param_3 + 0xfc) * param_4);

    uVar3 = FUN_007a6de0("Defensive Bonus",0xffffffff);

    sprintf(local_400,"%s: %+d\n",uVar3,iVar2);

    pcVar9 = local_400;

    do {

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar9 - (int)local_400;

    pcVar9 = (char *)(param_1 + -1);

    do {

      pcVar6 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_400;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar9 = pcVar9 + 4;

    }

    local_405 = local_405 + '\x01';

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar9 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    }

  }

  if (*(float *)(param_3 + 0x100) != 0.0) {

    iVar2 = (int)(*(float *)(param_3 + 0x100) * param_4);

    uVar3 = FUN_007a6de0("Penetration Bonus",0xffffffff);

    sprintf(local_400,"%s: %+d\n",uVar3,iVar2);

    pcVar9 = local_400;

    do {

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar9 - (int)local_400;

    pcVar9 = (char *)(param_1 + -1);

    do {

      pcVar6 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_400;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar9 = pcVar9 + 4;

    }

    local_405 = local_405 + '\x01';

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar9 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    }

  }

  if (*(float *)(param_3 + 0x104) != 0.0) {

    iVar2 = (int)(*(float *)(param_3 + 0x104) * param_4);

    uVar3 = FUN_007a6de0("Deflection Bonus",0xffffffff);

    sprintf(local_400,"%s: %+d\n",uVar3,iVar2);

    pcVar9 = local_400;

    do {

      cVar1 = *pcVar9;

      pcVar9 = pcVar9 + 1;

    } while (cVar1 != '\0');

    uVar4 = (int)pcVar9 - (int)local_400;

    pcVar9 = (char *)(param_1 + -1);

    do {

      pcVar6 = pcVar9 + 1;

      pcVar9 = pcVar9 + 1;

    } while (*pcVar6 != '\0');

    pcVar6 = local_400;

    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

      pcVar6 = pcVar6 + 4;

      pcVar9 = pcVar9 + 4;

    }

    local_405 = local_405 + '\x01';

    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *pcVar9 = *pcVar6;

      pcVar6 = pcVar6 + 1;

      pcVar9 = pcVar9 + 1;

    }

  }

  if (*(float *)(param_3 + 0x24) == 0.0) {

    return local_405;

  }

  if (*(float *)(param_3 + 0x24) == DAT_00aaa668) {

    pcVar9 = (char *)FUN_007a6de0("Always Hits\n",0xffffffff);

    sprintf(local_400,pcVar9);

  }

  else {

    fVar8 = *(float *)(param_3 + 0x24);

    uVar3 = FUN_007a6de0("Accuracy with this skill",0xffffffff);

    fVar7 = (float10)FUN_00412c60(fVar8 * param_4 * DAT_00aaa7ac,uVar3);

    sprintf(local_400,"%+g%% %s\n",SUB84((double)fVar7,0),(int)((ulonglong)(double)fVar7 >> 0x20));

  }

  pcVar9 = local_400;

  do {

    cVar1 = *pcVar9;

    pcVar9 = pcVar9 + 1;

  } while (cVar1 != '\0');

  uVar4 = (int)pcVar9 - (int)local_400;

  pcVar9 = (char *)(param_1 + -1);

  do {

    pcVar6 = pcVar9 + 1;

    pcVar9 = pcVar9 + 1;

  } while (*pcVar6 != '\0');

  pcVar6 = local_400;

  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar6;

    pcVar6 = pcVar6 + 4;

    pcVar9 = pcVar9 + 4;

  }

  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

    *pcVar9 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    pcVar9 = pcVar9 + 1;

  }

  return local_405 + '\x01';

}
