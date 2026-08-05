// =============================================================================
// FUN_00976410
// -----------------------------------------------------------------------------
// Stable ID: aa_00976410
// Address:   0x00976410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00976410 @ 0x00976410
// Stable ID: aa_00976410
// Embedded strings (evidence for future rename):
//   - "%d\n"
//   - "%d , %f %f %f , %f %f %f %f , %d\n"
//   - "%s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×3, do×3, while×3, for×1, return×1.
//  - Notable callees: fwrite×3, sprintf×3, FUN_00976410, fclose, fopen.
//  - Strings: "%d\n"; "%d , %f %f %f , %f %f %f %f , %d\n"; "%s\n".
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

void FUN_00976410(void)



{

  char cVar1;

  char *in_EAX;

  FILE *_File;

  char *pcVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint8_t *puVar5;

  int iVar6;

  int unaff_EDI;

  uint local_80c;

  char local_808 [1024];

  char local_408 [1028];

  

  _File = fopen(in_EAX,"w");

  if (_File != (FILE *)0x0) {

    iVar6 = 0;

    if (*(int *)(unaff_EDI + 0x6c) != 0) {

      iVar6 = (*(int *)(unaff_EDI + 0x70) - *(int *)(unaff_EDI + 0x6c)) / 0x28;

    }

    sprintf(local_808,"%d\n",iVar6);

    pcVar2 = local_808;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    fwrite(local_808,(int)pcVar2 - (int)(local_808 + 1),1,_File);

    iVar6 = 0;

    for (local_80c = 0;

        (*(int *)(unaff_EDI + 0x6c) != 0 &&

        (local_80c < (uint)((*(int *)(unaff_EDI + 0x70) - *(int *)(unaff_EDI + 0x6c)) / 0x28)));

        local_80c = local_80c + 1) {

      iVar4 = *(int *)(unaff_EDI + 0x6c);

      puVar3 = (uint32_t /* width from decompiler */ *)(iVar4 + iVar6);

      sprintf(local_808,"%d , %f %f %f , %f %f %f %f , %d\n",*puVar3,(double)(float)puVar3[1],

              (double)(float)puVar3[2],(double)(float)puVar3[3],(double)(float)puVar3[4],

              (double)(float)puVar3[5],(double)(float)puVar3[6],

              (double)*(float *)(iVar4 + 0x1c + iVar6),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x20 + iVar6));

      pcVar2 = local_808;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      fwrite(local_808,(int)pcVar2 - (int)(local_808 + 1),1,_File);

      iVar4 = *(int *)(unaff_EDI + 0x6c) + iVar6;

      if (*(int *)(iVar4 + 0x24) == 0) {

        puVar5 = &DAT_00a1419b;

      }

      else {

        puVar5 = *(uint8_t **)(iVar4 + 0x24);

      }

      sprintf(local_408,"%s\n",puVar5);

      pcVar2 = local_408;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      fwrite(local_408,(int)pcVar2 - (int)(local_408 + 1),1,_File);

      iVar6 = iVar6 + 0x28;

    }

    fclose(_File);

  }

  return;

}
