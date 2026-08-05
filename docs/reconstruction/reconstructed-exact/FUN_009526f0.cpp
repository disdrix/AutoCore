// =============================================================================
// FUN_009526f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009526f0
// Address:   0x009526f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009526f0 @ 0x009526f0
// Stable ID: aa_009526f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~128 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, for×1, return×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar×3, Client_GetMissionCompleteAudioTable×3, FUN_004248c0×3, block×3, FUN_007258a0, FUN_009526f0, SQRT, strncpy.
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

/* WARNING: Removing unreachable block (ram,0x0095289a) */

/* WARNING: Removing unreachable block (ram,0x009527b0) */

/* WARNING: Removing unreachable block (ram,0x00952822) */



uint32_t /* width from decompiler */ __fastcall FUN_009526f0(int param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int iVar7;

  char *pcVar8;

  float *pfVar9;

  uint uVar10;

  char *pcVar11;

  float fVar12;

  int local_174;

  float local_160;

  float local_15c;

  float local_158;

  float local_154;

  uint local_14c;

  char local_148 [260];

  uint32_t /* width from decompiler */ local_44;

  uint8_t local_3d;

  float local_38;

  float local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint8_t local_20;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250);

  local_174 = 0x70;

  do {

    iVar7 = Client_GetMissionCompleteAudioTable();

    pcVar8 = *(char **)(local_174 + iVar7);

    pcVar11 = pcVar8 + 1;

    do {

      cVar1 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar1 != '\0');

    if (pcVar8 != pcVar11) {

      iVar7 = CVOGReaction_RandomUnitScalar();

      iVar7 = *(int *)(iVar7 + 0x14);

      if (*(int *)(iVar7 + 0x9c4) == 0) {

        FUN_004248c0();

      }

      *(int *)(iVar7 + 0x9c4) = *(int *)(iVar7 + 0x9c4) + -1;

      uVar10 = **(uint **)(iVar7 + 0x9c0);

      uVar10 = uVar10 ^ uVar10 >> 0xb;

      *(uint **)(iVar7 + 0x9c0) = *(uint **)(iVar7 + 0x9c0) + 1;

      uVar10 = uVar10 ^ (uVar10 & 0xff3a58ad) << 7;

      uVar10 = uVar10 ^ (uVar10 & 0xffffdf8c) << 0xf;

      fVar4 = (float)((uVar10 >> 0x12 ^ uVar10) % 0x32);

      iVar7 = CVOGReaction_RandomUnitScalar();

      iVar7 = *(int *)(iVar7 + 0x14);

      if (*(int *)(iVar7 + 0x9c4) == 0) {

        FUN_004248c0();

      }

      *(int *)(iVar7 + 0x9c4) = *(int *)(iVar7 + 0x9c4) + -1;

      uVar10 = **(uint **)(iVar7 + 0x9c0);

      uVar10 = uVar10 ^ uVar10 >> 0xb;

      *(uint **)(iVar7 + 0x9c0) = *(uint **)(iVar7 + 0x9c0) + 1;

      uVar10 = uVar10 ^ (uVar10 & 0xff3a58ad) << 7;

      uVar10 = uVar10 ^ (uVar10 & 0xffffdf8c) << 0xf;

      fVar5 = (float)((uVar10 >> 0x12 ^ uVar10) % 100) * DAT_00a0f718;

      iVar7 = CVOGReaction_RandomUnitScalar();

      iVar7 = *(int *)(iVar7 + 0x14);

      if (*(int *)(iVar7 + 0x9c4) == 0) {

        FUN_004248c0();

      }

      *(int *)(iVar7 + 0x9c4) = *(int *)(iVar7 + 0x9c4) + -1;

      uVar10 = **(uint **)(iVar7 + 0x9c0);

      uVar10 = uVar10 ^ uVar10 >> 0xb;

      *(uint **)(iVar7 + 0x9c0) = *(uint **)(iVar7 + 0x9c0) + 1;

      uVar10 = uVar10 ^ (uVar10 & 0xff3a58ad) << 7;

      uVar10 = uVar10 ^ (uVar10 & 0xffffdf8c) << 0xf;

      local_14c = (uVar10 >> 0x12 ^ uVar10) % 100;

      fVar6 = (float)local_14c * DAT_00a0f718;

      fVar12 = fVar6 * fVar6 + fVar5 * fVar5;

      if (fVar12 == 0.0) {

        fVar12 = 0.0;

      }

      else {

        fVar12 = g_flOne / SQRT(fVar12);

      }

      if (*(int *)(iVar2 + 8) == 0) {

        pfVar9 = (float *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x84 + iVar2);

      }

      else {

        pfVar9 = (float *)(*(int *)(*(int *)(iVar2 + 8) + 0x3c) + 0xb0);

      }

      local_160 = *pfVar9 + fVar12 * fVar5 * fVar4;

      local_15c = pfVar9[1] + fVar12 * 0.0 * fVar4;

      local_158 = pfVar9[2] + fVar12 * fVar6 * fVar4;

      local_154 = pfVar9[3] + fVar12 * 0.0 * fVar4;

      pcVar11 = local_148;

      for (iVar7 = 0x4e; iVar7 != 0; iVar7 = iVar7 + -1) {

        pcVar11[0] = '\0';

        pcVar11[1] = '\0';

        pcVar11[2] = '\0';

        pcVar11[3] = '\0';

        pcVar11 = pcVar11 + 4;

      }

      iVar7 = Client_GetMissionCompleteAudioTable();

      strncpy(local_148,*(char **)(local_174 + iVar7),0x104);

      iVar7 = *(int *)(param_1 + 0xe98);

      iVar3 = *(int *)(*(int *)(iVar7 + 4) + 4);

      local_28 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + iVar7);

      local_24 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + iVar7);

      pfVar9 = &local_160;

      pcVar11 = local_148;

      local_30 = 0;

      local_20 = 1;

      local_3d = 0;

      local_44 = 0;

      local_38 = g_flOne;

      local_2c = DAT_00aaa9f0;

      local_34 = g_flOne;

      Client_GetMissionCompleteAudioTable(pcVar11,pfVar9);

      FUN_007258a0(pcVar11,pfVar9);

    }

    local_174 = local_174 + 4;

  } while (local_174 < 0x200);

  return 1;

}
