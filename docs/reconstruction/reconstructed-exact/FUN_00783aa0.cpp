// =============================================================================
// FUN_00783aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00783aa0
// Address:   0x00783aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00783aa0 @ 0x00783aa0
// Stable ID: aa_00783aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, return×2.
//  - Notable callees: OutputDebugStringA×2, FUN_00783aa0, _vsnprintf.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_00783aa0(char *param_1)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  int *piVar6;

  char local_1000 [4092];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x783aaa;

  pcVar5 = local_1000;

  pcVar4 = (char *)0x0;

  if (DAT_00d179a0 != 0) {

    pcVar4 = *(char **)(DAT_00d179a0 + 8);

    iVar3 = -(int)pcVar4;

    do {

      cVar2 = *pcVar4;

      pcVar4[(int)(local_1000 + iVar3)] = cVar2;

      pcVar4 = pcVar4 + 1;

    } while (cVar2 != '\0');

    pcVar4 = local_1000 + 1;

    do {

      cVar2 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    pcVar5[(int)(local_1000 + -(int)pcVar4)] = ':';

    pcVar5[(int)(local_1000 + (1 - (int)pcVar4))] = ' ';

    pcVar4 = pcVar5 + (2 - (int)pcVar4);

  }

  _vsnprintf(local_1000 + (int)pcVar4,0x1000 - (int)pcVar4,param_1,&stack0x00000008);

  piVar6 = DAT_00d17998;

  if (DAT_00d17998 == (int *)0x0) {

    OutputDebugStringA(local_1000);

    OutputDebugStringA("\n");

    return;

  }

  do {

    (**(code **)(*piVar6 + 4))(local_1000);

    piVar1 = piVar6 + 1;

    piVar6 = (int *)*piVar1;

  } while ((int *)*piVar1 != (int *)0x0);

  return;

}
