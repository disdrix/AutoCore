// =============================================================================
// FUN_007667f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007667f0
// Address:   0x007667f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007667f0 @ 0x007667f0
// Stable ID: aa_007667f0
// Embedded strings (evidence for future rename):
//   - "stoFileOSFile::Tell() call to SetFilePointer failed with error #%d"
//   - "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoFileOSFile.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007667f0, FUN_0076cec0, GetLastError, SetFilePointer, stoFileOSFile::Tell, vog_LogMessage.
//  - Strings: ",DVar2)

    ;

    vog_LogMessage(".
//  - Return sites: 1.

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

DWORD __fastcall FUN_007667f0(int param_1)



{

  DWORD DVar1;

  DWORD DVar2;

  uint32_t /* width from decompiler */ uVar3;

  int local_4;

  

  local_4 = param_1;

  DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 8),0,(PLONG)0x0,1);

  if (DVar1 == 0xffffffff) {

    DVar2 = GetLastError();

    uVar3 = FUN_0076cec0(&local_4,

                         "stoFileOSFile::Tell() call to SetFilePointer failed with error #%d",DVar2)

    ;

    vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoFileOSFile.cpp",0x1dc,3,uVar3);

  }

  return DVar1;

}
