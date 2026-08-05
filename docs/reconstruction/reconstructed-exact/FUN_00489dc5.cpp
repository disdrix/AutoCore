// =============================================================================
// FUN_00489dc5
// -----------------------------------------------------------------------------
// Stable ID: aa_00489dc5
// Address:   0x00489dc5  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00489dc5 @ 0x00489dc5
// Stable ID: aa_00489dc5
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, goto×2, return×1.
//  - Notable callees: FUN_00416390, FUN_00489d95, FUN_00489dc5, GetVersionExA, memset.
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

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



uint32_t /* width from decompiler */ * __fastcall FUN_00489dc5(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  _OSVERSIONINFOA local_9c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = DAT_00af5894;

  FUN_00489d95();

  param_1[2] = 0x400000;

  param_1[1] = 0x400000;

  *param_1 = 0x3c;

  *(uint8_t *)(param_1 + 3) = 0;

  memset(&local_9c,0,0x94);

  local_9c.dwOSVersionInfoSize = 0x94;

  GetVersionExA(&local_9c);

  if (local_9c.dwPlatformId == 2) {

    if (local_9c.dwMajorVersion < 5) goto LAB_00489e3f;

  }

  else if ((local_9c.dwPlatformId != 1) ||

          ((local_9c.dwMajorVersion < 5 &&

           ((local_9c.dwMajorVersion != 4 || (local_9c.dwMinorVersion == 0)))))) goto LAB_00489e3f;

  *(uint8_t *)(param_1 + 3) = 1;

LAB_00489e3f:

  param_1[4] = 0x710;

  param_1[5] = &DAT_009c6a44;

  iVar1 = FUN_00416390();

  if (iVar1 < 0) {

    DAT_00d1f0f0 = 1;

  }

  return param_1;

}
