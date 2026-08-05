// =============================================================================
// FUN_00481130
// -----------------------------------------------------------------------------
// Stable ID: aa_00481130
// Address:   0x00481130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00481130 @ 0x00481130
// Stable ID: aa_00481130
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00481130, FUN_006848d0, ioctlsocket.
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

uint32_t /* width from decompiler */ FUN_00481130(void)



{

  int iVar1;

  SOCKET unaff_ESI;

  u_long local_4;

  

  iVar1 = FUN_006848d0();

  ioctlsocket(unaff_ESI,0x4004667f,&local_4);

  if ((iVar1 == 1) && (local_4 == 0)) {

    return 1;

  }

  return 0;

}
