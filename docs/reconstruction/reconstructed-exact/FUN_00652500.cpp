// =============================================================================
// FUN_00652500
// -----------------------------------------------------------------------------
// Stable ID: aa_00652500
// Address:   0x00652500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00652500 @ 0x00652500
// Stable ID: aa_00652500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00652500, WSAGetLastError, send.
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

int __thiscall FUN_00652500(int *param_1,char *param_2,int param_3)



{

  int iVar1;

  

  if (param_1[8] != 0xffffffff) {

    iVar1 = send(param_1[8],param_2,param_3,0);

    if ((0 < iVar1) && (iVar1 != -1)) {

      return iVar1;

    }

    iVar1 = WSAGetLastError();

    if (iVar1 != 0x2733) {

      (**(code **)(*param_1 + 8))();

    }

  }

  return 0;

}
