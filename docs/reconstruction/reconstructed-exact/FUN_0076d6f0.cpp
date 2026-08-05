// =============================================================================
// FUN_0076d6f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d6f0
// Address:   0x0076d6f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076d6f0 @ 0x0076d6f0
// Stable ID: aa_0076d6f0
// Embedded strings (evidence for future rename):
//   - "dbghelp.dll"
//   - "imagehlp.dll"
//   - "SymGetOptions"
//   - "SymSetOptions"
//   - "SymInitialize"
//   - "SymCleanup"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, do×1, while×1.
//  - Notable callees: GetProcAddress×11, LoadLibraryA×2, CloseHandle, CreateFileA, FUN_0076d6f0, GetCurrentProcess, GetModuleFileNameA, strrchr.
//  - Strings: "dbghelp.dll"; "imagehlp.dll"; "SymGetOptions"; "SymSetOptions".
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

uint32_t /* width from decompiler */ FUN_0076d6f0(void)



{

  HMODULE pHVar1;

  DWORD DVar2;

  int iVar3;

  char *pcVar4;

  HANDLE pvVar5;

  uint8_t *unaff_ESI;

  char acStack_108 [264];

  

  pHVar1 = LoadLibraryA("dbghelp.dll");

  *(HMODULE *)(unaff_ESI + 8) = pHVar1;

  if (pHVar1 == (HMODULE)0x0) {

    pHVar1 = LoadLibraryA("imagehlp.dll");

    *(HMODULE *)(unaff_ESI + 8) = pHVar1;

  }

  if (*(HMODULE *)(unaff_ESI + 8) != (HMODULE)0x0) {

    DAT_00d0dfcc = GetProcAddress(*(HMODULE *)(unaff_ESI + 8),"SymGetOptions");

    DAT_00d0dfa8 = GetProcAddress(*(HMODULE *)(unaff_ESI + 8),"SymSetOptions");

    DAT_00d0dfc8 = GetProcAddress(*(HMODULE *)(unaff_ESI + 8),"SymInitialize");

    DAT_00d0dfc4 = GetProcAddress(*(HMODULE *)(unaff_ESI + 8),"SymCleanup");

    DAT_00d0dfb8 = GetProcAddress(*(HMODULE *)(unaff_ESI + 8),"SymLoadModule64");

    DAT_00d0dfac = GetProcAddress(*(HMODULE *)(unaff_ESI + 8),"SymFunctionTableAccess64");

    DAT_00d0dfc0 = GetProcAddress(*(HMODULE *)(unaff_ESI + 8),"SymGetModuleBase64");

    DAT_00d0dfb4 = GetProcAddress(*(HMODULE *)(unaff_ESI + 8),"SymGetModuleInfo");

    DAT_00d0dfbc = GetProcAddress(*(HMODULE *)(unaff_ESI + 8),"SymGetSymFromAddr");

    DAT_00d0dfb0 = GetProcAddress(*(HMODULE *)(unaff_ESI + 8),"SymGetLineFromAddr");

    DAT_00d0dfd0 = GetProcAddress(*(HMODULE *)(unaff_ESI + 8),"StackWalk64");

    (*DAT_00d0dfcc)();

    (*DAT_00d0dfa8)();

    DVar2 = GetModuleFileNameA((HMODULE)0x0,&stack0xfffffdf4,0x104);

    if (DVar2 != 0) {

      iVar3 = 0;

      do {

        pcVar4 = &stack0xfffffdf4 + iVar3;

        acStack_108[iVar3] = *pcVar4;

        iVar3 = iVar3 + 1;

      } while (*pcVar4 != '\0');

      pcVar4 = strrchr(acStack_108,0x5c);

      if (pcVar4 != (char *)0x0) {

        *pcVar4 = '\0';

      }

      pvVar5 = GetCurrentProcess();

      *(HANDLE *)(unaff_ESI + 4) = pvVar5;

      iVar3 = (*DAT_00d0dfc8)(pvVar5);

      if (iVar3 != 0) {

        pvVar5 = CreateFileA(&stack0xfffffde8,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,

                             (HANDLE)0x0);

        if (pvVar5 != (HANDLE)0xffffffff) {

          iVar3 = (*DAT_00d0dfb8)(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 4),pvVar5,&stack0xfffffde8,0,0,0,0);

          CloseHandle(pvVar5);

          if (iVar3 != 0) {

            *unaff_ESI = 1;

            return 1;

          }

        }

      }

    }

  }

  return 0;

}
