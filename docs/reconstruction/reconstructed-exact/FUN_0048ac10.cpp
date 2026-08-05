// =============================================================================
// FUN_0048ac10
// -----------------------------------------------------------------------------
// Stable ID: aa_0048ac10
// Address:   0x0048ac10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048ac10 @ 0x0048ac10
// Stable ID: aa_0048ac10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CloseHandle, DeviceIoControl, FUN_0048aa70, FUN_0048ac10, _itoa.
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

bool FUN_0048ac10(char *param_1)



{

  char *_Dest;

  HANDLE hDevice;

  BOOL BVar1;

  bool bVar2;

  DWORD local_4;

  

  _Dest = param_1;

  bVar2 = false;

  if (param_1 == (char *)0x0) {

    return false;

  }

  hDevice = (HANDLE)FUN_0048aa70();

  if (hDevice != (HANDLE)0xffffffff) {

    local_4 = 0;

    param_1 = (char *)0x0;

    BVar1 = DeviceIoControl(hDevice,0x222080,&param_1,4,&param_1,4,&local_4,(LPOVERLAPPED)0x0);

    bVar2 = BVar1 != 0;

    if (bVar2) {

      _itoa((uint)param_1 & 0xffff,_Dest,10);

    }

    CloseHandle(hDevice);

  }

  return bVar2;

}
