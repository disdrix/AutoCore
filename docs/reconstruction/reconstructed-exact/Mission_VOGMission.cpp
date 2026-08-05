// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×10, for×2, return×2, do×1, while×1.
//  - Notable callees: fprintf×14, FUN_005468c0, FUN_00546ad0, FUN_0076cec0, _snprintf, fclose, fopen, vog_LogMessage.
//  - Strings: "%s%S.xml"; "..\\missions\\"; ");

  if (_File != (FILE *)0x0) {

    fprintf(_File,"; "1.0\" encoding=\"iso-8859-1\" ?>\r\n".
//  - Return sites: 2.

// =============================================================================
// Mission_VOGMission
// -----------------------------------------------------------------------------
// Stable ID: aa_00546ad0
// Address:   0x00546ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOGMission"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Mission_VOGMission(uint32_t /* width from decompiler */ *param_1)



{

  FILE *_File;

  uint32_t /* width from decompiler */ uVar1;

  uint8_t *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t local_114 [4];

  char local_110 [2];

  uint32_t /* width from decompiler */ local_10e [66];

  

  local_110[0] = '\0';

  local_110[1] = '\0';

  puVar4 = local_10e;

  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  _snprintf(local_110,0x104,"%s%S.xml","..\\missions\\",param_1 + 1);

  _File = fopen(local_110,"wb");

  if (_File != (FILE *)0x0) {

    fprintf(_File,"<?xml version=\"1.0\" encoding=\"iso-8859-1\" ?>\r\n");

    fprintf(_File,"<Mission name=\"%S\" ID=\"%d\"> <!-- don\'t ever edit this -->\r\n",param_1 + 1,

            *param_1);

    puVar2 = (uint8_t *)param_1[0x53];

    if (puVar2 == (uint8_t *)0x0) {

      puVar2 = &DAT_00a1419b;

    }

    fprintf(_File,"\t<Title>%s</Title>\r\n",puVar2);

    puVar2 = (uint8_t *)param_1[0x52];

    if (puVar2 == (uint8_t *)0x0) {

      puVar2 = &DAT_00a1419b;

    }

    fprintf(_File,"\t<Internal>%s</Internal>\r\n",puVar2);

    puVar2 = (uint8_t *)param_1[0x54];

    if (puVar2 == (uint8_t *)0x0) {

      puVar2 = &DAT_00a1419b;

    }

    fprintf(_File,"\t<Description>%s</Description>\r\n",puVar2);

    puVar2 = (uint8_t *)param_1[0x55];

    if (puVar2 == (uint8_t *)0x0) {

      puVar2 = &DAT_00a1419b;

    }

    fprintf(_File,"\t<OneLineAccept>%s</OneLineAccept>\r\n",puVar2);

    puVar2 = (uint8_t *)param_1[0x56];

    if (puVar2 == (uint8_t *)0x0) {

      puVar2 = &DAT_00a1419b;

    }

    fprintf(_File,"\t<OneLineReject>%s</OneLineReject>\r\n",puVar2);

    puVar2 = (uint8_t *)param_1[0x57];

    if (puVar2 == (uint8_t *)0x0) {

      puVar2 = &DAT_00a1419b;

    }

    fprintf(_File,"\t<NotCompleteText>%s</NotCompleteText>\r\n",puVar2);

    puVar2 = (uint8_t *)param_1[0x58];

    if (puVar2 == (uint8_t *)0x0) {

      puVar2 = &DAT_00a1419b;

    }

    fprintf(_File,"\t<CompleteText>%s</CompleteText>\r\n",puVar2);

    puVar2 = (uint8_t *)param_1[0x59];

    if (puVar2 == (uint8_t *)0x0) {

      puVar2 = &DAT_00a1419b;

    }

    fprintf(_File,"\t<FailText>%s</FailText>\r\n",puVar2);

    fprintf(_File,"\t<RequirementOred>%i</RequirementOred>\r\n",(uint)(param_1[0x48] != 0));

    fprintf(_File,"\t<RequirementNegative>%i</RequirementNegative>\r\n",(uint)(param_1[0x49] != 0));

    fprintf(_File,"\t<CoreMission>%i</CoreMission>\r\n",

            (uint)(*(char *)((int)param_1 + 0x169) != '\0'));

    iVar3 = 0;

    if (*(char *)(param_1 + 0x4c) != '\0') {

      do {

        FUN_005468c0(*(uint32_t /* width from decompiler */ *)(param_1[0x4f] + iVar3 * 4),_File);

        iVar3 = iVar3 + 1;

      } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x4c));

    }

    fprintf(_File,"</Mission>\r\n");

    fclose(_File);

    return;

  }

  uVar1 = FUN_0076cec0(local_114,"Couldn\'t open %s for writing, failing mission xml save.",

                       local_110);

  vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGMission.cpp",0x324,3,uVar1);

  return;

}
