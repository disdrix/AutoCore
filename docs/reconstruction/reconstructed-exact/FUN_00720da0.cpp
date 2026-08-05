// =============================================================================
// FUN_00720da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00720da0
// Address:   0x00720da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00720da0 @ 0x00720da0
// Stable ID: aa_00720da0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~131 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, for×2, return×1.
//  - Notable callees: SUB41×6, Client_GetMissionCompleteAudioTable×2, FUN_007204d0, FUN_00720da0, FUN_00722790, PathFileExistsA.
//  - Return sites: 1.

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

void FUN_00720da0(int param_1,char *param_2)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  BOOL BVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  char *pcVar8;

  char *pcVar9;

  char *pcVar10;

  char local_104 [4];

  char local_100 [4];

  char local_fc [4];

  char local_f8 [4];

  char local_f4 [4];

  char local_f0 [108];

  uint32_t /* width from decompiler */ local_84;

  uint32_t /* width from decompiler */ local_80;

  uint32_t /* width from decompiler */ local_7c;

  float local_78;

  float local_74;

  uint32_t /* width from decompiler */ local_6c;

  uint8_t local_5f;

  uint8_t local_5e;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  

  iVar2 = Client_GetMissionCompleteAudioTable();

  if (*(char *)(iVar2 + 0x308) == '\0') {

    local_104[0] = s_____sounds__music___00aa94ec[0];

    local_104[1] = s_____sounds__music___00aa94ec[1];

    local_104[2] = s_____sounds__music___00aa94ec[2];

    local_104[3] = s_____sounds__music___00aa94ec[3];

    local_100[0] = s_____sounds__music___00aa94ec[4];

    local_100[1] = s_____sounds__music___00aa94ec[5];

    local_100[2] = s_____sounds__music___00aa94ec[6];

    local_100[3] = s_____sounds__music___00aa94ec[7];

    local_fc[0] = s_____sounds__music___00aa94ec[8];

    local_fc[1] = s_____sounds__music___00aa94ec[9];

    local_fc[2] = s_____sounds__music___00aa94ec[10];

    local_fc[3] = s_____sounds__music___00aa94ec[0xb];

    uVar3 = s_____sounds__music___00aa94ec._12_4_;

    uVar6 = s_____sounds__music___00aa94ec._16_4_;

  }

  else {

    local_fc[0] = s_____sounds__music_low___00aa9500[8];

    local_fc[1] = s_____sounds__music_low___00aa9500[9];

    local_fc[2] = s_____sounds__music_low___00aa9500[10];

    local_fc[3] = s_____sounds__music_low___00aa9500[0xb];

    local_104[0] = s_____sounds__music_low___00aa9500[0];

    local_104[1] = s_____sounds__music_low___00aa9500[1];

    local_104[2] = s_____sounds__music_low___00aa9500[2];

    local_104[3] = s_____sounds__music_low___00aa9500[3];

    local_100[0] = s_____sounds__music_low___00aa9500[4];

    local_100[1] = s_____sounds__music_low___00aa9500[5];

    local_100[2] = s_____sounds__music_low___00aa9500[6];

    local_100[3] = s_____sounds__music_low___00aa9500[7];

    local_f0[0] = s_____sounds__music_low___00aa9500[0x14];

    local_f0[1] = s_____sounds__music_low___00aa9500[0x15];

    local_f0[2] = s_____sounds__music_low___00aa9500[0x16];

    local_f0[3] = s_____sounds__music_low___00aa9500[0x17];

    uVar3 = s_____sounds__music_low___00aa9500._12_4_;

    uVar6 = s_____sounds__music_low___00aa9500._16_4_;

  }

  local_f8[0] = (char)uVar3;

  local_f8[1] = SUB41(uVar3,1);

  local_f8[2] = SUB41(uVar3,2);

  local_f8[3] = SUB41(uVar3,3);

  local_f4[0] = (char)uVar6;

  local_f4[1] = SUB41(uVar6,1);

  local_f4[2] = SUB41(uVar6,2);

  local_f4[3] = SUB41(uVar6,3);

  pcVar4 = param_2;

  do {

    cVar1 = *pcVar4;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  pcVar9 = &stack0xfffffefb;

  do {

    pcVar8 = pcVar9 + 1;

    pcVar9 = pcVar9 + 1;

  } while (*pcVar8 != '\0');

  pcVar8 = param_2;

  for (uVar7 = (uint)((int)pcVar4 - (int)param_2) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar9 = *(uint32_t /* width from decompiler */ *)pcVar8;

    pcVar8 = pcVar8 + 4;

    pcVar9 = pcVar9 + 4;

  }

  pcVar10 = local_104;

  for (uVar7 = (int)pcVar4 - (int)param_2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

    *pcVar9 = *pcVar8;

    pcVar8 = pcVar8 + 1;

    pcVar9 = pcVar9 + 1;

  }

  Client_GetMissionCompleteAudioTable(pcVar10);

  FUN_00722790(pcVar10);

  BVar5 = PathFileExistsA(local_104);

  if ((BVar5 != 0) && (*(char *)(param_1 + 0x12) == '\0')) {

    local_104[0] = s_default_loading_00aa93e0[0];

    local_104[1] = s_default_loading_00aa93e0[1];

    local_104[2] = s_default_loading_00aa93e0[2];

    local_104[3] = s_default_loading_00aa93e0[3];

    local_5f = 1;

    local_5e = 1;

    local_100[0] = s_default_loading_00aa93e0[4];

    local_100[1] = s_default_loading_00aa93e0[5];

    local_100[2] = s_default_loading_00aa93e0[6];

    local_100[3] = s_default_loading_00aa93e0[7];

    local_78 = g_flOne;

    local_74 = g_flOne;

    local_fc[0] = s_default_loading_00aa93e0[8];

    local_fc[1] = s_default_loading_00aa93e0[9];

    local_fc[2] = s_default_loading_00aa93e0[10];

    local_fc[3] = s_default_loading_00aa93e0[0xb];

    local_4c = 3;

    local_6c = 0;

    local_54 = 0;

    local_50 = 0;

    local_f8[0] = s_default_loading_00aa93e0[0xc];

    local_f8[1] = s_default_loading_00aa93e0[0xd];

    local_f8[2] = s_default_loading_00aa93e0[0xe];

    local_f8[3] = s_default_loading_00aa93e0[0xf];

    local_84 = 0;

    local_80 = 0;

    local_7c = 0;

    FUN_007204d0(local_104);

  }

  return;

}
