// =============================================================================
// FUN_00579da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00579da0
// Address:   0x00579da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00579da0 @ 0x00579da0
// Stable ID: aa_00579da0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×10, do×5, while×5, return×1.
//  - Notable callees: fwrite×12, FUN_00579da0.
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

void __thiscall FUN_00579da0(void *param_1,FILE *param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  FILE *_File;

  char *pcVar4;

  char *pcVar5;

  int iVar6;

  int local_14;

  int local_10;

  int local_c;

  size_t local_8;

  size_t local_4;

  

  _File = param_2;

  fwrite(param_1,1,1,param_2);

  fwrite((void *)((int)param_1 + 1),1,1,param_2);

  pcVar4 = *(char **)((int)param_1 + 4);

  iVar6 = 0;

  local_8 = 0;

  if (pcVar4 != (char *)0x0) {

    pcVar5 = pcVar4 + 1;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    local_8 = (int)pcVar4 - (int)pcVar5;

  }

  fwrite(&local_8,4,1,param_2);

  if (0 < (int)local_8) {

    fwrite(*(void **)((int)param_1 + 4),1,local_8,param_2);

  }

  if (*(int *)((int)param_1 + 0xc) == 0) {

    local_14 = 0;

  }

  else {

    local_14 = *(int *)((int)param_1 + 0x10) - *(int *)((int)param_1 + 0xc) >> 2;

  }

  fwrite(&local_14,4,1,param_2);

  if (0 < local_14) {

    do {

      fwrite(*(void **)(*(int *)((int)param_1 + 0xc) + iVar6 * 4),0xc,1,param_2);

      iVar6 = iVar6 + 1;

    } while (iVar6 < local_14);

  }

  if (*(int *)((int)param_1 + 0x1c) == 0) {

    local_c = 0;

  }

  else {

    local_c = *(int *)((int)param_1 + 0x20) - *(int *)((int)param_1 + 0x1c) >> 2;

  }

  fwrite(&local_c,4,1,param_2);

  param_2 = (FILE *)0x0;

  if (0 < local_c) {

    do {

      fwrite(*(void **)(*(int *)((int)param_1 + 0x1c) + (int)param_2 * 4),8,1,_File);

      local_4 = 0;

      iVar6 = *(int *)((int)param_2 * 4 + *(int *)((int)param_1 + 0x1c));

      if (*(int *)(iVar6 + 8) != 0) {

        pcVar5 = *(char **)(iVar6 + 8);

        pcVar4 = pcVar5 + 1;

        do {

          cVar1 = *pcVar5;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

        local_4 = (int)pcVar5 - (int)pcVar4;

      }

      fwrite(&local_4,4,1,_File);

      iVar6 = 0;

      if (0 < (int)local_4) {

        fwrite(*(void **)(*(int *)(*(int *)((int)param_1 + 0x1c) + (int)param_2 * 4) + 8),1,local_4,

               _File);

      }

      iVar2 = *(int *)(*(int *)((int)param_1 + 0x1c) + (int)param_2 * 4);

      iVar3 = *(int *)(iVar2 + 0x10);

      if (iVar3 == 0) {

        local_10 = 0;

      }

      else {

        local_10 = *(int *)(iVar2 + 0x14) - iVar3 >> 2;

      }

      fwrite(&local_10,4,1,_File);

      if (0 < local_10) {

        do {

          fwrite((void *)(*(int *)(*(int *)(*(int *)((int)param_1 + 0x1c) + (int)param_2 * 4) + 0x10

                                  ) + iVar6 * 4),4,1,_File);

          iVar6 = iVar6 + 1;

        } while (iVar6 < local_10);

      }

      param_2 = (FILE *)((int)param_2 + 1);

    } while ((int)param_2 < local_c);

  }

  return;

}
