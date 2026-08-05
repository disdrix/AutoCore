// =============================================================================
// FUN_0089fe40
// -----------------------------------------------------------------------------
// Stable ID: aa_0089fe40
// Address:   0x0089fe40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0089fe40 @ 0x0089fe40
// Stable ID: aa_0089fe40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, while×1, if×1.
//  - Notable callees: CONCAT31, FUN_0089fe40.
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

uint __fastcall FUN_0089fe40(int param_1)



{

  uint uVar1;

  int *piVar2;

  

  uVar1 = 0;

  piVar2 = (int *)(param_1 + 0x63c);

  while ((*piVar2 == 0 || (*(char *)(*piVar2 + 0x4fc) == '\0'))) {

    uVar1 = uVar1 + 1;

    piVar2 = piVar2 + 1;

    if (9 < (int)uVar1) {

      return uVar1 & 0xffffff00;

    }

  }

  return CONCAT31((int3)(uVar1 >> 8),1);

}
