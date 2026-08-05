// =============================================================================
// FUN_00907be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00907be0
// Address:   0x00907be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00907be0 @ 0x00907be0
// Stable ID: aa_00907be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_00907be0, GetTickCount.
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

uint FUN_00907be0(int param_1)



{

  DWORD DVar1;

  uint uVar2;

  

  DVar1 = GetTickCount();

  uVar2 = DVar1 - *(int *)(param_1 + 0x50c);

  if (uVar2 < 4000) {

    return uVar2 & 0xffffff00;

  }

  uVar2 = (*(ushort *)(DAT_00d1ad2c + 0x26) + 1) * 0x32;

  return CONCAT31((int3)(uVar2 >> 8),uVar2 < *(ushort *)(DAT_00d1ad2c + 0x24));

}
