// =============================================================================
// FUN_0067bac0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067bac0
// Address:   0x0067bac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067bac0 @ 0x0067bac0
// Stable ID: aa_0067bac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0067bac0, ioctlsocket.
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

int __thiscall FUN_0067bac0(SOCKET *param_1,byte param_2)



{

  int iVar1;

  

  _param_2 = (uint)param_2;

  iVar1 = ioctlsocket(*param_1,-0x7ffb9982,(u_long *)&param_2);

  return -(uint)(iVar1 != 0);

}
