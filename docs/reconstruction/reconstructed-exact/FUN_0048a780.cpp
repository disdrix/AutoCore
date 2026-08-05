// =============================================================================
// FUN_0048a780
// -----------------------------------------------------------------------------
// Stable ID: aa_0048a780
// Address:   0x0048a780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048a780 @ 0x0048a780
// Stable ID: aa_0048a780
// Embedded strings (evidence for future rename):
//   - "SetEffect - ENTER\n"
//   - "SetEffect - g_effectSettings.szPath %s, g_effectSettings.capability %d\n"
//   - "SetEffect - EXIT\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0056f570×3, CloseHandle, CreateThread, FUN_0048a780, ResetEvent, SetEvent, WaitForSingleObject, stat.
//  - Strings: "SetEffect - ENTER\n"; "SetEffect - EXIT\n".
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

HANDLE FUN_0048a780(char *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  uint8_t local_24 [36];

  

  FUN_0056f570("SetEffect - ENTER\n");

  iVar2 = stat(param_1,local_24);

  if ((iVar2 != -1) && (DAT_00b034fc != (HANDLE)0x0)) {

    iVar2 = (int)&DAT_00b033f0 - (int)param_1;

    do {

      cVar1 = *param_1;

      param_1[iVar2] = cVar1;

      param_1 = param_1 + 1;

    } while (cVar1 != '\0');

    DAT_00b034f4 = param_2;

    FUN_0056f570("SetEffect - g_effectSettings.szPath %s, g_effectSettings.capability %d\n",

                 &DAT_00b033f0,param_2);

    if (DAT_00b03500 != (HANDLE)0x0) {

      DAT_00b034f8 = 1;

      SetEvent(DAT_00b034fc);

      WaitForSingleObject(DAT_00b03500,0xffffffff);

      CloseHandle(DAT_00b03500);

      DAT_00b03500 = (HANDLE)0x0;

    }

    DAT_00b034f8 = 0;

    ResetEvent(DAT_00b034fc);

    DAT_00b03500 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_0048a550,(LPVOID)0x0,0,(LPDWORD)0x0

                               );

    FUN_0056f570("SetEffect - EXIT\n");

    return DAT_00b03500;

  }

  return (HANDLE)0x0;

}
