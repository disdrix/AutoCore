// =============================================================================
// FUN_0047c520
// -----------------------------------------------------------------------------
// Stable ID: aa_0047c520
// Address:   0x0047c520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047c520 @ 0x0047c520
// Stable ID: aa_0047c520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×8, return×8, while×1.
//  - Notable callees: FUN_00476d60×6, FUN_0047a480×3, FUN_00477710×2, strtod×2, FUN_00470450, FUN_00476cc0, FUN_00477740, FUN_0047a420.
//  - Return sites: 8.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_0047c520(int param_1,int param_2)



{

  char cVar1;

  int in_EAX;

  char *pcVar2;

  int iVar3;

  char *pcVar4;

  double dVar5;

  char *local_c;

  double local_8;

  

  if ((*(uint *)(param_1 + 0x68) & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0();

  }

  if ((*(uint *)(param_1 + 0x68) & 4) != 0) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if ((param_2 != 0) && ((*(byte *)(param_2 + 9) & 0x40) != 0)) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  pcVar2 = (char *)FUN_00477740();

  if (pcVar2 == (char *)0x0) {

    FUN_00476d60();

    return;

  }

  FUN_0047a420();

  iVar3 = FUN_0047a480();

  if (iVar3 == 0) {

    pcVar2[in_EAX] = '\0';

    local_8 = strtod(pcVar2 + 1,&local_c);

    if (*local_c != '\0') {

      FUN_00476d60();

      return;

    }

    cVar1 = *pcVar2;

    pcVar4 = pcVar2;

    while (cVar1 != '\0') {

      pcVar4 = pcVar4 + 1;

      cVar1 = *pcVar4;

    }

    dVar5 = strtod(pcVar4 + 1,&local_c);

    if (*local_c != '\0') {

      FUN_00476d60();

      return;

    }

    if (((pcVar4 + 1 <= pcVar2 + in_EAX) && (_DAT_00aaa608 < local_8)) && (_DAT_00aaa608 < dVar5)) {

      FUN_00470450(param_1,(int)*pcVar2,local_8,dVar5);

      FUN_00477710();

      return;

    }

    FUN_00476d60();

  }

  FUN_00477710();

  return;

}
