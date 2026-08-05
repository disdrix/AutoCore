// =============================================================================
// FUN_0067b9a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b9a0
// Address:   0x0067b9a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067b9a0 @ 0x0067b9a0
// Stable ID: aa_0067b9a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0067b070, FUN_0067b0e0, FUN_0067b110, FUN_0067b9a0, getsockname.
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

uint32_t /* width from decompiler */ __thiscall FUN_0067b9a0(SOCKET *param_1,uint32_t /* width from decompiler */ param_2)



{

  int local_24 [2];

  sockaddr local_1c;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9601;

  local_c = ExceptionList;

  local_24[1] = 0;

  ExceptionList = &local_c;

  FUN_0067b070();

  local_4 = 1;

  local_24[0] = 0x10;

  getsockname(*param_1,&local_1c,local_24);

  FUN_0067b0e0(&local_1c);

  local_24[1] = 1;

  local_4 = local_4 & 0xffffff00;

  FUN_0067b110();

  ExceptionList = local_c;

  return param_2;

}
