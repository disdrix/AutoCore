// =============================================================================
// FUN_0067bd70
// -----------------------------------------------------------------------------
// Stable ID: aa_0067bd70
// Address:   0x0067bd70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067bd70 @ 0x0067bd70
// Stable ID: aa_0067bd70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0067bd70, getsockopt.
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

uint __fastcall FUN_0067bd70(SOCKET *param_1)



{

  uint uVar1;

  uint32_t /* width from decompiler */ local_8;

  int local_4;

  

  local_4 = 4;

  uVar1 = getsockopt(*param_1,0xffff,0x80,(char *)&local_8,&local_4);

  if (uVar1 != 0) {

    return uVar1 & 0xffff0000;

  }

  return -(uint)(local_8._2_2_ != 0) & local_8;

}
