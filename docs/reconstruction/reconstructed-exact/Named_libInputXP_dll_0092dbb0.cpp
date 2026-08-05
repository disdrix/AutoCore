// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: GetProcAddress×8, FUN_0092dbb0, FreeLibrary, GetVersionExA, LoadLibraryA.
//  - Strings: "libInput2k.dll"; "libInputXP.dll"; "joy_custom.ini".
//  - Return sites: 2.

// =============================================================================
// Named_libInputXP_dll_0092dbb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0092dbb0
// Address:   0x0092dbb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "libInputXP.dll"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_libInputXP_dll_0092dbb0(void)



{

  char *lpLibFileName;

  HMODULE hModule;

  FARPROC pFVar1;

  int unaff_ESI;

  _OSVERSIONINFOA local_94;

  

  local_94.dwOSVersionInfoSize = 0x94;

  GetVersionExA(&local_94);

  lpLibFileName = "libInput2k.dll";

  if (local_94.dwMinorVersion != 0) {

    lpLibFileName = "libInputXP.dll";

  }

  hModule = LoadLibraryA(lpLibFileName);

  *(HMODULE *)(unaff_ESI + 0xdc4) = hModule;

  if (hModule != (HMODULE)0x0) {

    pFVar1 = GetProcAddress(hModule,(LPCSTR)0x6);

    *(FARPROC *)(unaff_ESI + 0xdc8) = pFVar1;

    if (pFVar1 != (FARPROC)0x0) {

      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x8);

      *(FARPROC *)(unaff_ESI + 0xdcc) = pFVar1;

      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x2);

      *(FARPROC *)(unaff_ESI + 0xdd0) = pFVar1;

      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x7);

      *(FARPROC *)(unaff_ESI + 0xdd4) = pFVar1;

      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x1);

      *(FARPROC *)(unaff_ESI + 0xdd8) = pFVar1;

      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x3);

      *(FARPROC *)(unaff_ESI + 0xddc) = pFVar1;

      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x4);

      *(FARPROC *)(unaff_ESI + 0xde0) = pFVar1;

      pFVar1 = GetProcAddress(*(HMODULE *)(unaff_ESI + 0xdc4),(LPCSTR)0x5);

      *(FARPROC *)(unaff_ESI + 0xde4) = pFVar1;

      (**(code **)(unaff_ESI + 0xdc8))(unaff_ESI + 0x9cc,"joy_custom.ini");

      return;

    }

    FreeLibrary(*(HMODULE *)(unaff_ESI + 0xdc4));

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xdc4) = 0;

  }

  return;

}
