// =============================================================================
// FUN_0057a460
// -----------------------------------------------------------------------------
// Stable ID: aa_0057a460
// Address:   0x0057a460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0057a460 @ 0x0057a460
// Stable ID: aa_0057a460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~162 non-empty decompiler lines.
//  - Control keywords: if×21, do×7, while×7, return×2.
//  - Notable callees: fwrite×27, CONCAT31×2, FUN_00512350×2, FUN_005168a0×2, FUN_00579da0, FUN_0057a460, FUN_005dc260.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_0057a460(int param_1,FILE *param_2)



{

  char *pcVar1;

  char cVar2;

  FILE *_File;

  char *pcVar3;

  int iVar4;

  int local_14;

  int local_10;

  size_t local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  _File = param_2;

  if (param_2 != (FILE *)0x0) {

    fwrite((void *)(param_1 + 400),0x41,1,param_2);

    fwrite((char *)(param_1 + 0x1d1),1,1,_File);

    fwrite((void *)(param_1 + 0x1f5),1,1,_File);

    fwrite((void *)(param_1 + 0x200),4,1,_File);

    fwrite((void *)(param_1 + 0x1f6),1,1,_File);

    fwrite((void *)(param_1 + 0x25c),4,1,_File);

    fwrite((void *)(param_1 + 0x260),4,1,_File);

    fwrite((void *)(param_1 + 0x264),4,1,_File);

    if (*(char *)(param_1 + 0x1d1) == '\n') {

      param_2 = (FILE *)CONCAT31(param_2._1_3_,*(uint8_t *)(param_1 + 0x1f8));

      fwrite(&param_2,1,1,_File);

      fwrite((void *)(param_1 + 0x1fc),4,1,_File);

    }

    else {

      FUN_005168a0(param_1 + 0x1d4,0xffffffff);

      if (*(int *)(param_1 + 0x1d8) == 0) {

        local_14 = 0;

      }

      else {

        local_14 = *(int *)(param_1 + 0x1dc) - *(int *)(param_1 + 0x1d8) >> 3;

      }

      fwrite(&local_14,4,1,_File);

      iVar4 = 0;

      if (0 < local_14) {

        do {

          local_8 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1d8) + iVar4 * 8);

          local_4 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1d8) + iVar4 * 8 + 4);

          FUN_00512350(_File,&local_8);

          iVar4 = iVar4 + 1;

        } while (iVar4 < local_14);

      }

    }

    FUN_005168a0(param_1 + 0x1e4,0x3a);

    if (*(int *)(param_1 + 0x1e8) == 0) {

      local_14 = 0;

    }

    else {

      local_14 = *(int *)(param_1 + 0x1ec) - *(int *)(param_1 + 0x1e8) >> 3;

    }

    fwrite(&local_14,4,1,_File);

    iVar4 = 0;

    if (0 < local_14) {

      do {

        local_8 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1e8) + iVar4 * 8);

        local_4 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1e8) + iVar4 * 8 + 4);

        FUN_00512350(_File,&local_8);

        iVar4 = iVar4 + 1;

      } while (iVar4 < local_14);

    }

    if (*(char *)(param_1 + 0x1d1) == '\x12') {

      if (*(int *)(param_1 + 600) == 0) {

        param_2 = (FILE *)((uint)param_2._1_3_ << 8);

        fwrite(&param_2,1,1,_File);

      }

      else {

        param_2 = (FILE *)CONCAT31(param_2._1_3_,1);

        fwrite(&param_2,1,1,_File);

        FUN_00579da0(_File);

      }

    }

    fwrite((void *)(param_1 + 0x206),1,1,_File);

    FUN_005dc260(param_1 + 0x208,*(uint32_t /* width from decompiler */ *)(param_1 + 0xa4));

    if (*(int *)(param_1 + 0x20c) == 0) {

      local_10 = 0;

    }

    else {

      local_10 = (*(int *)(param_1 + 0x210) - *(int *)(param_1 + 0x20c)) / 0xc;

    }

    fwrite(&local_10,4,1,_File);

    iVar4 = 0;

    if (0 < local_10) {

      param_2 = (FILE *)0x0;

      do {

        fwrite((void *)((int)param_2 + *(int *)(param_1 + 0x20c)),0xc,1,_File);

        param_2 = (FILE *)((int)param_2 + 0xc);

        iVar4 = iVar4 + 1;

      } while (iVar4 < local_10);

    }

    fwrite((void *)(param_1 + 500),1,1,_File);

    cVar2 = *(char *)(param_1 + 0x1d1);

    local_c = 0;

    if ((((cVar2 == '.') || (cVar2 == '/')) || (cVar2 == 'L')) || (cVar2 == 'M')) {

      pcVar3 = *(char **)(param_1 + 0x22c);

      if (pcVar3 != (char *)0x0) {

        pcVar1 = pcVar3 + 1;

        do {

          cVar2 = *pcVar3;

          pcVar3 = pcVar3 + 1;

        } while (cVar2 != '\0');

        local_c = (int)pcVar3 - (int)pcVar1;

      }

      fwrite(&local_c,4,1,_File);

      if (0 < (int)local_c) {

        fwrite(*(void **)(param_1 + 0x22c),1,local_c,_File);

      }

    }

    cVar2 = *(char *)(param_1 + 0x1d1);

    if ((cVar2 == '#') || (('?' < cVar2 && (cVar2 < 'B')))) {

      param_2 = (FILE *)0x0;

      fwrite((void *)(param_1 + 0x254),4,1,_File);

      pcVar3 = *(char **)(param_1 + 0x250);

      if (pcVar3 != (char *)0x0) {

        pcVar1 = pcVar3 + 1;

        do {

          cVar2 = *pcVar3;

          pcVar3 = pcVar3 + 1;

        } while (cVar2 != '\0');

        param_2 = (FILE *)((int)pcVar3 - (int)pcVar1);

      }

      fwrite(&param_2,4,1,_File);

      if (0 < (int)param_2) {

        fwrite(*(void **)(param_1 + 0x250),1,(size_t)param_2,_File);

      }

    }

    iVar4 = 0;

    if (*(char *)(param_1 + 0x1d1) == '%') {

      if (*(int *)(param_1 + 0x234) == 0) {

        param_2 = (FILE *)0x0;

      }

      else {

        param_2 = (FILE *)(*(int *)(param_1 + 0x238) - *(int *)(param_1 + 0x234) >> 2);

      }

      fwrite(&param_2,4,1,_File);

      if (0 < (int)param_2) {

        do {

          fwrite((void *)(*(int *)(param_1 + 0x234) + iVar4 * 4),4,1,_File);

          iVar4 = iVar4 + 1;

        } while (iVar4 < (int)param_2);

      }

      if (*(int *)(param_1 + 0x244) == 0) {

        param_2 = (FILE *)0x0;

      }

      else {

        param_2 = (FILE *)(*(int *)(param_1 + 0x248) - *(int *)(param_1 + 0x244) >> 2);

      }

      fwrite(&param_2,4,1,_File);

      iVar4 = 0;

      if (0 < (int)param_2) {

        do {

          fwrite((void *)(*(int *)(param_1 + 0x244) + iVar4 * 4),4,1,_File);

          iVar4 = iVar4 + 1;

        } while (iVar4 < (int)param_2);

      }

    }

    return 1;

  }

  return 0;

}
