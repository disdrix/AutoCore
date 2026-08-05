// =============================================================================
// FUN_0048a0b2
// -----------------------------------------------------------------------------
// Stable ID: aa_0048a0b2
// Address:   0x0048a0b2  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048a0b2 @ 0x0048a0b2
// Stable ID: aa_0048a0b2
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×1.
//  - Notable callees: FUN_0048a0b2, FUN_0048a14a, GetProcAddress, LoadLibraryA, RegCloseKey, RegOpenKeyExA, RegQueryValueExA.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



bool FUN_0048a0b2(void)



{

  LSTATUS LVar1;

  bool bVar2;

  DWORD local_10 [2];

  HKEY local_8;

  

  bVar2 = false;

  LVar1 = RegOpenKeyExA((HKEY)0x80000002,PTR_s_SOFTWARE_Classes_CLSID__FE750200_00aef86c,0,0x20019,

                        &local_8);

  if (LVar1 != 0) {

    return false;

  }

  local_10[1] = 0x104;

  LVar1 = RegQueryValueExA(local_8,(LPCSTR)0x0,(LPDWORD)0x0,local_10,&DAT_00b032e4,local_10 + 1);

  if ((LVar1 == 0) && (DAT_00b032dc = LoadLibraryA(&DAT_00b032e4), DAT_00b032dc != (HMODULE)0x0)) {

    _DAT_00b032e0 = GetProcAddress(DAT_00b032dc,s_GetInterface_00aef8bc);

    if (_DAT_00b032e0 != (FARPROC)0x0) {

      DAT_00d21a0c = (*_DAT_00b032e0)(1);

      bVar2 = DAT_00d21a0c != 0;

      if (bVar2) goto LAB_0048a13b;

    }

    FUN_0048a14a();

  }

LAB_0048a13b:

  RegCloseKey(local_8);

  return bVar2;

}
