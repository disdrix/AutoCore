// =============================================================================
// FUN_00553c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00553c50
// Address:   0x00553c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00553c50 @ 0x00553c50
// Stable ID: aa_00553c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_00553c50, _localtime64, _time64.
//  - Return sites: 4.

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

byte __fastcall FUN_00553c50(int param_1)



{

  int iVar1;

  tm *ptVar2;

  bool bVar3;

  uint local_8;

  int local_4;

  

  _time64((__time64_t *)&local_8);

  bVar3 = local_8 < *(uint *)(param_1 + 0x160);

  local_8 = local_8 - *(uint *)(param_1 + 0x160);

  local_4 = (local_4 - *(int *)(param_1 + 0x164)) - (uint)bVar3;

  ptVar2 = _localtime64((__time64_t *)&local_8);

  iVar1 = ptVar2->tm_min;

  if (0x2c < iVar1) {

    return 3;

  }

  if (0x1d < iVar1) {

    return 2;

  }

  if (0xe < iVar1) {

    return 1;

  }

  return (-1 < iVar1) - 1U & 3;

}
