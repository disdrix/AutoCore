// =============================================================================
// FUN_00581480
// -----------------------------------------------------------------------------
// Stable ID: aa_00581480
// Address:   0x00581480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00581480 @ 0x00581480
// Stable ID: aa_00581480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×3, if×2, do×1, while×1.
//  - Notable callees: fwrite×3, FUN_00581480.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall FUN_00581480(int param_1,FILE *param_2)



{

  char *pcVar1;

  char cVar2;

  FILE *_File;

  char *pcVar3;

  

  _File = param_2;

  if (param_2 == (FILE *)0x0) {

    return 0;

  }

  pcVar3 = *(char **)(param_1 + 0x1c);

  if (pcVar3 != (char *)0x0) {

    pcVar1 = pcVar3 + 1;

    do {

      cVar2 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar2 != '\0');

    param_2 = (FILE *)((int)pcVar3 - (int)pcVar1);

    fwrite(&param_2,4,1,_File);

    fwrite(*(void **)(param_1 + 0x1c),1,(size_t)param_2,_File);

    return 1;

  }

  param_2 = (FILE *)0x0;

  fwrite(&param_2,4,1,_File);

  return 1;

}
