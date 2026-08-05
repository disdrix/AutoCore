// =============================================================================
// FUN_005229c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005229c0
// Address:   0x005229c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005229c0 @ 0x005229c0
// Stable ID: aa_005229c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CONCAT31, FUN_005229c0.
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

uint __fastcall FUN_005229c0(int param_1)



{

  uint uVar1;

  

  uVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x198))();

  if (((((char)uVar1 == '\0') &&

       (uVar1 = *(uint *)(param_1 + 4),

       (*(byte *)(*(int *)(uVar1 + 4) + 0xb8 + param_1) & 0x12) == 0)) &&

      (*(int *)(param_1 + 0x250) != 0)) && (*(char *)(param_1 + 0x6b9) == '\0')) {

    return CONCAT31((int3)(uVar1 >> 8),1);

  }

  return uVar1 & 0xffffff00;

}
