// =============================================================================
// FUN_00621500
// -----------------------------------------------------------------------------
// Stable ID: aa_00621500
// Address:   0x00621500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00621500 @ 0x00621500
// Stable ID: aa_00621500
// Embedded strings (evidence for future rename):
//   - "Increased Damage Per Hit: %g%%\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, for×2, return×1.
//  - Notable callees: FUN_00578550, FUN_00621500, sprintf.
//  - Strings: "Increased Damage Per Hit: %g%%\n".
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

int FUN_00621500(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  char *pcVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  char *pcVar7;

  float fVar8;

  char local_100 [256];

  

  iVar6 = 0;

  if (*(float *)(param_3 + 0xe0) != 0.0) {

    fVar8 = (g_flOne - *(float *)(param_3 + 0xe0)) * DAT_00a0f520;

    if (0.0 <= fVar8) {

      fVar8 = fVar8 + g_flMissionXpRoundBias;

    }

    else {

      fVar8 = fVar8 - g_flMissionXpRoundBias;

    }

    sprintf(local_100,"Increased Damage Per Hit: %g%%\n",

            (double)((float)(int)fVar8 * g_flMultiKillCountBlend));

    pcVar2 = local_100;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    uVar3 = (int)pcVar2 - (int)local_100;

    pcVar2 = (char *)(param_1 + -1);

    do {

      pcVar7 = pcVar2 + 1;

      pcVar2 = pcVar2 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = local_100;

    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar2 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar2 = pcVar2 + 4;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar2 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar2 = pcVar2 + 1;

    }

    iVar6 = 1;

  }

  iVar4 = FUN_00578550(param_1,param_2,param_3,param_4);

  return iVar4 + iVar6;

}
