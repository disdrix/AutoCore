// =============================================================================
// FUN_0048aa70
// -----------------------------------------------------------------------------
// Stable ID: aa_0048aa70
// Address:   0x0048aa70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048aa70 @ 0x0048aa70
// Stable ID: aa_0048aa70
// Embedded strings (evidence for future rename):
//   - "\\\\.\\%s.VXD"
//   - "APPDRV"
//   - "\\\\.\\%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CreateFileA×2, wsprintfA×2, FUN_0048aa70, GetVersionExA.
//  - Strings: "\\\\.\\%s.VXD"; "APPDRV"; "\\\\.\\%s".
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

HANDLE FUN_0048aa70(void)



{

  HANDLE pvVar1;

  _OSVERSIONINFOA local_198;

  CHAR local_104 [260];

  

  local_198.dwOSVersionInfoSize = 0x94;

  GetVersionExA(&local_198);

  if (local_198.dwPlatformId == 1) {

    wsprintfA(local_104,"\\\\.\\%s.VXD","APPDRV");

    pvVar1 = CreateFileA(local_104,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);

    return pvVar1;

  }

  if (local_198.dwPlatformId == 2) {

    wsprintfA(local_104,"\\\\.\\%s","APPDRV");

    pvVar1 = CreateFileA(local_104,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);

    return pvVar1;

  }

  return (HANDLE)0xffffffff;

}
