// =============================================================================
// FUN_004a8390
// -----------------------------------------------------------------------------
// Stable ID: aa_004a8390
// Address:   0x004a8390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a8390 @ 0x004a8390
// Stable ID: aa_004a8390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: fwrite×14, FUN_004a8390.
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

void __thiscall FUN_004a8390(int param_1,FILE *param_2)



{

  char *pcVar1;

  char cVar2;

  FILE *_File;

  char *pcVar3;

  

  _File = param_2;

  if (param_2 != (FILE *)0x0) {

    fwrite(&DAT_009ca240,4,1,param_2);

    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;

    fwrite((void *)(param_1 + 4),4,1,_File);

    fwrite((void *)(param_1 + 0x10),4,1,_File);

    fwrite((void *)(param_1 + 0x14),4,1,_File);

    fwrite((void *)(param_1 + 0x18),4,1,_File);

    fwrite((void *)(param_1 + 0x1c),1,1,_File);

    fwrite((void *)(param_1 + 0x1d),1,1,_File);

    fwrite((void *)(param_1 + 0x32e),2,3,_File);

    fwrite((void *)(param_1 + 0x338),1,1,_File);

    fwrite((void *)(param_1 + 0x339),1,1,_File);

    pcVar3 = *(char **)(param_1 + 0x334);

    param_2 = (FILE *)0x0;

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

      fwrite(*(void **)(param_1 + 0x334),1,(size_t)param_2,_File);

    }

    fwrite((void *)(param_1 + 0x33c),4,1,_File);

    fwrite((void *)(param_1 + 8),4,1,_File);

  }

  return;

}
