// =============================================================================
// FUN_006526f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006526f0
// Address:   0x006526f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006526f0 @ 0x006526f0
// Stable ID: aa_006526f0
// Embedded strings (evidence for future rename):
//   - "(Windows)WSAStartup failed with error!"
//   - "Error"
//   - "C:\\vog\\1_code\\havok230\\include\\hkbase\\stream\\impl\\hkBsdSocket.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00631dc0, FUN_00631ff0, FUN_00632030, FUN_006526f0, WSAStartup.
//  - Strings: "(Windows)WSAStartup failed with error!"; "Error".
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



void FUN_006526f0(void)



{

  int iVar1;

  uint8_t local_390 [512];

  WSADATA local_190;

  

  if ((_DAT_00d034f4 & 1) == 0) {

    _DAT_00d034f4 = _DAT_00d034f4 | 1;

    DAT_00d034f0 = '\0';

  }

  else if (DAT_00d034f0 != '\0') {

    return;

  }

  iVar1 = WSAStartup(0x202,&local_190);

  if (iVar1 == -1) {

    FUN_00631ff0(local_390,0x200,1);

    FUN_00631dc0("(Windows)WSAStartup failed with error!");

    (**(code **)(*DAT_00bc56d0 + 8))

              ("Error",0x321825f8,local_390,

               "C:\\vog\\1_code\\havok230\\include\\hkbase\\stream\\impl\\hkBsdSocket.cpp",0x3d);

    FUN_00632030();

  }

  DAT_00d034f0 = 1;

  return;

}
