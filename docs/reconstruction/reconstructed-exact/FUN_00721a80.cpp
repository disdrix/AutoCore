// =============================================================================
// FUN_00721a80
// -----------------------------------------------------------------------------
// Stable ID: aa_00721a80
// Address:   0x00721a80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00721a80 @ 0x00721a80
// Stable ID: aa_00721a80
// Embedded strings (evidence for future rename):
//   - "Playing: %s\n"
//   - "PlayMusic::CreateStreamingMusic FAILED\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: if×11, do×4, while×4, return×4, for×2.
//  - Notable callees: SUB41×6, Client_GetMissionCompleteAudioTable×2, FUN_007a4480×2, FUN_0071f810, FUN_0071ffc0, FUN_007213d0, FUN_007214e0, FUN_00721a80.
//  - Strings: "Playing: %s\n"; "PlayMusic::CreateStreamingMusic FAILED\n".
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ FUN_00721a80(char *param_1,char param_2,char param_3)



{

  char cVar1;

  int in_EAX;

  char *pcVar2;

  int iVar3;

  BOOL BVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  int iVar9;

  char *pcVar10;

  int *piVar11;

  char *pcVar12;

  char *pcVar13;

  char local_184 [4];

  char local_180 [4];

  char local_17c [4];

  char local_178 [4];

  char local_174 [4];

  char local_170 [240];

  char local_80 [128];

  

  if (((*(char *)(in_EAX + 0x10) != '\0') && (*(char *)(in_EAX + 0x19) != '\0')) &&

     ((*(char *)(in_EAX + 0x12) == '\0' || (*(int *)(param_1 + 0xb8) == 3)))) {

    pcVar2 = param_1;

    do {

      cVar1 = *pcVar2;

      pcVar2[(int)(local_80 + -(int)param_1)] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    FUN_007a4480(0xffffffff,"Playing: %s\n",local_80);

    iVar8 = -1;

    iVar9 = 0;

    piVar11 = (int *)(in_EAX + 0x80);

    do {

      iVar3 = *piVar11;

      if ((iVar3 == 0) || (*(char *)(iVar3 + 0x1c5) == '\0')) {

        if (iVar8 == -1) {

          iVar8 = iVar9;

        }

      }

      else {

        if ((param_3 == '\0') && (iVar3 = _stricmp(local_80,(char *)(iVar3 + 0x48)), iVar3 == 0)) {

          return 0;

        }

        *(uint32_t /* width from decompiler */ *)(*piVar11 + 0x1b0) = 0;

        *(uint8_t *)(*piVar11 + 0x38) = 1;

      }

      iVar9 = iVar9 + 1;

      piVar11 = piVar11 + 1;

    } while (iVar9 < 2);

    iVar9 = Client_GetMissionCompleteAudioTable();

    if (*(char *)(iVar9 + 0x308) == '\0') {

      local_184[0] = s_____sounds__music___00aa94ec[0];

      local_184[1] = s_____sounds__music___00aa94ec[1];

      local_184[2] = s_____sounds__music___00aa94ec[2];

      local_184[3] = s_____sounds__music___00aa94ec[3];

      local_180[0] = s_____sounds__music___00aa94ec[4];

      local_180[1] = s_____sounds__music___00aa94ec[5];

      local_180[2] = s_____sounds__music___00aa94ec[6];

      local_180[3] = s_____sounds__music___00aa94ec[7];

      local_17c[0] = s_____sounds__music___00aa94ec[8];

      local_17c[1] = s_____sounds__music___00aa94ec[9];

      local_17c[2] = s_____sounds__music___00aa94ec[10];

      local_17c[3] = s_____sounds__music___00aa94ec[0xb];

      uVar5 = s_____sounds__music___00aa94ec._12_4_;

      uVar7 = s_____sounds__music___00aa94ec._16_4_;

    }

    else {

      local_17c[0] = s_____sounds__music_low___00aa9500[8];

      local_17c[1] = s_____sounds__music_low___00aa9500[9];

      local_17c[2] = s_____sounds__music_low___00aa9500[10];

      local_17c[3] = s_____sounds__music_low___00aa9500[0xb];

      local_184[0] = s_____sounds__music_low___00aa9500[0];

      local_184[1] = s_____sounds__music_low___00aa9500[1];

      local_184[2] = s_____sounds__music_low___00aa9500[2];

      local_184[3] = s_____sounds__music_low___00aa9500[3];

      local_180[0] = s_____sounds__music_low___00aa9500[4];

      local_180[1] = s_____sounds__music_low___00aa9500[5];

      local_180[2] = s_____sounds__music_low___00aa9500[6];

      local_180[3] = s_____sounds__music_low___00aa9500[7];

      local_170[0] = s_____sounds__music_low___00aa9500[0x14];

      local_170[1] = s_____sounds__music_low___00aa9500[0x15];

      local_170[2] = s_____sounds__music_low___00aa9500[0x16];

      local_170[3] = s_____sounds__music_low___00aa9500[0x17];

      uVar5 = s_____sounds__music_low___00aa9500._12_4_;

      uVar7 = s_____sounds__music_low___00aa9500._16_4_;

    }

    local_178[0] = (char)uVar5;

    local_178[1] = SUB41(uVar5,1);

    local_178[2] = SUB41(uVar5,2);

    local_178[3] = SUB41(uVar5,3);

    local_174[0] = (char)uVar7;

    local_174[1] = SUB41(uVar7,1);

    local_174[2] = SUB41(uVar7,2);

    local_174[3] = SUB41(uVar7,3);

    pcVar2 = param_1;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    pcVar12 = &stack0xfffffe7b;

    do {

      pcVar10 = pcVar12 + 1;

      pcVar12 = pcVar12 + 1;

    } while (*pcVar10 != '\0');

    pcVar10 = param_1;

    for (uVar6 = (uint)((int)pcVar2 - (int)param_1) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar12 = *(uint32_t /* width from decompiler */ *)pcVar10;

      pcVar10 = pcVar10 + 4;

      pcVar12 = pcVar12 + 4;

    }

    pcVar13 = local_184;

    for (uVar6 = (int)pcVar2 - (int)param_1 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

      *pcVar12 = *pcVar10;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    }

    Client_GetMissionCompleteAudioTable(pcVar13);

    FUN_00722790(pcVar13);

    piVar11 = (int *)(in_EAX + 0x80 + iVar8 * 4);

    if (*(int *)(in_EAX + 0x80 + iVar8 * 4) != 0) {

      FUN_0071f810();

      if ((uint32_t /* width from decompiler */ *)*piVar11 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar11)(1);

      }

      *piVar11 = 0;

    }

    BVar4 = PathFileExistsA(local_184);

    if (BVar4 == 0) {

      if ((uint32_t /* width from decompiler */ *)*piVar11 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar11)(1);

      }

      *piVar11 = 0;

      return 0x80004005;

    }

    iVar8 = FUN_007214e0(in_EAX,piVar11,(uint)(param_2 != '\0') * 4 + 0x84,DAT_00aa9110,DAT_00aa9114

                         ,DAT_00aa9118,DAT_00aa911c,150000);

    if (-1 < iVar8) {

      *(uint32_t /* width from decompiler */ *)(*piVar11 + 0x1a4) = 0;

      FUN_007213d0(in_EAX,param_1);

      return 0;

    }

    FUN_0071ffc0(param_1);

    if ((uint32_t /* width from decompiler */ *)*piVar11 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar11)(1);

    }

    *piVar11 = 0;

    FUN_007a4480(0,"PlayMusic::CreateStreamingMusic FAILED\n");

  }

  return 0;

}
