// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, for×1.
//  - Notable callees: FUN_00766900, FUN_0076cec0, FormatMessageA, GetLastError, SetFilePointer, vog_LogMessage.
//  - Strings: "UNKNOWN"; "Tried to seek %d bytes from %d in file, error was %s"; "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoFileOSFile.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_stoFileOSFile_00766900
// -----------------------------------------------------------------------------
// Stable ID: aa_00766900
// Address:   0x00766900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "stoFileOSFile"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_stoFileOSFile_00766900(int param_1,LONG param_2,int param_3)



{

  DWORD DVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  DWORD dwMoveMethod;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t local_20c [4];

  CHAR local_208 [2];

  uint32_t /* width from decompiler */ local_206 [128];

  

  dwMoveMethod = 1;

  if (param_3 == 0) {

    dwMoveMethod = 0;

  }

  else if (param_3 == 1) {

    dwMoveMethod = 1;

  }

  else if (param_3 == 2) {

    dwMoveMethod = 2;

  }

  DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 8),param_2,(PLONG)0x0,dwMoveMethod);

  if (DVar1 == 0xffffffff) {

    DVar1 = GetLastError();

    local_208[0] = '\0';

    local_208[1] = '\0';

    puVar5 = local_206;

    for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    *(uint16_t *)puVar5 = 0;

    DVar1 = FormatMessageA(0x1000,(LPCVOID)0x0,DVar1,0,local_208,0x200,(va_list *)0x0);

    pcVar2 = local_208;

    if (DVar1 == 0) {

      pcVar2 = "UNKNOWN";

    }

    uVar3 = FUN_0076cec0(local_20c,"Tried to seek %d bytes from %d in file, error was %s",param_2,

                         dwMoveMethod,pcVar2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoFileOSFile.cpp",0x131,3,uVar3);

    return 0xffffffff;

  }

  return 0;

}
