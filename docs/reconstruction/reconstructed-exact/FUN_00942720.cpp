// =============================================================================
// FUN_00942720
// -----------------------------------------------------------------------------
// Stable ID: aa_00942720
// Address:   0x00942720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00942720 @ 0x00942720
// Stable ID: aa_00942720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: while×4, do×3, for×2, if×2, return×1.
//  - Notable callees: fgets×2, FUN_00941fb0, FUN_00942720, fclose, fopen.
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

void FUN_00942720(char *param_1)



{

  char cVar1;

  char *pcVar2;

  FILE *_File;

  int iVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ unaff_EBX;

  char *pcVar5;

  char *pcVar6;

  char local_504 [4];

  char local_500 [4];

  char local_4fc [4];

  char local_4f8;

  char local_400 [1024];

  

  local_504 = (char  [4])s____commands__00a2c574._0_4_;

  local_4f8 = s____commands__00a2c574[0xc];

  local_4fc = (char  [4])s____commands__00a2c574._8_4_;

  local_500 = (char  [4])s____commands__00a2c574._4_4_;

  pcVar2 = param_1;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  pcVar6 = &stack0xfffffafb;

  do {

    pcVar5 = pcVar6 + 1;

    pcVar6 = pcVar6 + 1;

  } while (*pcVar5 != '\0');

  pcVar5 = param_1;

  for (uVar4 = (uint)((int)pcVar2 - (int)param_1) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar6 = *(uint32_t /* width from decompiler */ *)pcVar5;

    pcVar5 = pcVar5 + 4;

    pcVar6 = pcVar6 + 4;

  }

  for (uVar4 = (int)pcVar2 - (int)param_1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

    *pcVar6 = *pcVar5;

    pcVar5 = pcVar5 + 1;

    pcVar6 = pcVar6 + 1;

  }

  _File = fopen(local_504,"r");

  if (_File != (FILE *)0x0) {

    pcVar2 = fgets(local_400,0x3ff,_File);

    while (pcVar2 != (char *)0x0) {

      pcVar2 = local_400;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      iVar3 = (int)pcVar2 - (int)(local_400 + 1);

      if ((0 < iVar3) && (local_400[iVar3 + -1] == '\n')) {

        local_400[iVar3 + -1] = '\0';

      }

      FUN_00941fb0(unaff_EBX,5,1);

      pcVar2 = fgets(local_400,0x3ff,_File);

    }

    fclose(_File);

  }

  return;

}
