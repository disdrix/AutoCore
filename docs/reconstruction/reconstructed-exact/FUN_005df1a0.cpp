// =============================================================================
// FUN_005df1a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005df1a0
// Address:   0x005df1a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005df1a0 @ 0x005df1a0
// Stable ID: aa_005df1a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: OutputDebugStringA×2, printf×2, FUN_005df1a0.
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

int FUN_005df1a0(LPCSTR param_1,int param_2)



{

  uint uVar1;

  LPCSTR lpOutputString;

  LPCSTR pCVar2;

  int iVar3;

  

  if (param_2 == 0) {

    return 0;

  }

  if (param_1[param_2 + -1] == '\0') {

    OutputDebugStringA(param_1);

    printf("%s",param_1);

    return param_2;

  }

  uVar1 = param_2 + 1;

  lpOutputString = (LPCSTR)(**(code **)(*DAT_00b05060 + 0x10))(uVar1,0x12);

  if (0 < param_2) {

    pCVar2 = lpOutputString;

    iVar3 = param_2;

    do {

      *pCVar2 = pCVar2[(int)param_1 - (int)lpOutputString];

      pCVar2 = pCVar2 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  lpOutputString[param_2] = '\0';

  OutputDebugStringA(lpOutputString);

  printf("%s",lpOutputString);

  if (-1 < (int)uVar1) {

    (**(code **)(*DAT_00b05060 + 0x14))(lpOutputString,uVar1 & 0x7fffffff,0x12);

  }

  return param_2;

}
