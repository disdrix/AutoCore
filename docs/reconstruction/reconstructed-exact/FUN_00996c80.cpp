// =============================================================================
// FUN_00996c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00996c80
// Address:   0x00996c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00996c80 @ 0x00996c80
// Stable ID: aa_00996c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, return×5, do×2, while×2.
//  - Notable callees: FUN_00989aa0×2, strncpy×2, FUN_00436b00, FUN_00436df0, FUN_00996c80.
//  - Return sites: 5.

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

char * FUN_00996c80(char *param_1)



{

  char cVar1;

  char *_Source;

  int in_EAX;

  char *pcVar2;

  char *pcVar3;

  char *_Dest;

  int local_8 [2];

  

  _Source = param_1;

  if (*(char *)(in_EAX + 0x50) == '\0') {

    pcVar2 = param_1 + 1;

    pcVar3 = param_1;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    if (pcVar3 + (1 - (int)pcVar2) < (char *)0x2) {

      return (char *)0x0;

    }

    _Dest = (char *)FUN_00989aa0();

    if (_Dest != (char *)0x0) {

      strncpy(_Dest,_Source,(size_t)(pcVar3 + (1 - (int)pcVar2)));

    }

    return _Dest;

  }

  FUN_00436df0(in_EAX + 0x28,local_8);

  if (local_8[0] != *(int *)(in_EAX + 0x30)) {

    return *(char **)(local_8[0] + 8);

  }

  pcVar2 = _Source;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  if (pcVar2 + (1 - (int)(_Source + 1)) < (char *)0x2) {

    return (char *)0x0;

  }

  pcVar3 = (char *)FUN_00989aa0();

  if (pcVar3 != (char *)0x0) {

    param_1 = pcVar3;

    strncpy(pcVar3,_Source,(size_t)(pcVar2 + (1 - (int)(_Source + 1))));

    FUN_00436b00(local_8,&param_1);

  }

  return pcVar3;

}
