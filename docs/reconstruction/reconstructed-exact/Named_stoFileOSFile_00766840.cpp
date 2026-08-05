// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_00766840, FUN_0076cec0, FormatMessageA, GetLastError, ReadFile, vog_LogMessage.
//  - Strings: "UNKNOWN"; "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoFileOSFile.cpp".
//  - Return sites: 2.

// =============================================================================
// Named_stoFileOSFile_00766840
// -----------------------------------------------------------------------------
// Stable ID: aa_00766840
// Address:   0x00766840  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall Named_stoFileOSFile_00766840(int param_1,LPVOID param_2,DWORD param_3)



{

  BOOL BVar1;

  DWORD DVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  DWORD local_20c;

  CHAR local_208 [2];

  uint32_t /* width from decompiler */ local_206 [128];

  

  local_20c = 0;

  BVar1 = ReadFile(*(HANDLE *)(param_1 + 8),param_2,param_3,&local_20c,(LPOVERLAPPED)0x0);

  if (BVar1 != 0) {

    return 0;

  }

  DVar2 = GetLastError();

  local_208[0] = '\0';

  local_208[1] = '\0';

  puVar6 = local_206;

  for (iVar5 = 0x7f; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  *(uint16_t *)puVar6 = 0;

  DVar2 = FormatMessageA(0x1000,(LPCVOID)0x0,DVar2,0,local_208,0x200,(va_list *)0x0);

  pcVar3 = local_208;

  if (DVar2 == 0) {

    pcVar3 = "UNKNOWN";

  }

  uVar4 = FUN_0076cec0(&local_20c,"Tried to read %d bytes, read %d bytes from file, error was %s",

                       param_3,local_20c,pcVar3);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoFileOSFile.cpp",0x188,3,uVar4);

  return 0xffffffff;

}
