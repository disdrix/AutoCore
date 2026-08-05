// =============================================================================
// FUN_00637f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00637f70
// Address:   0x00637f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00637f70 @ 0x00637f70
// Stable ID: aa_00637f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_00637f70.
//  - Return sites: 3.

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

int FUN_00637f70(byte *param_1,byte *param_2)



{

  byte bVar1;

  bool bVar2;

  

  while( true ) {

    bVar1 = *param_1;

    bVar2 = bVar1 < *param_2;

    if (bVar1 != *param_2) break;

    if (bVar1 == 0) {

      return 0;

    }

    bVar1 = param_1[1];

    bVar2 = bVar1 < param_2[1];

    if (bVar1 != param_2[1]) break;

    param_1 = param_1 + 2;

    param_2 = param_2 + 2;

    if (bVar1 == 0) {

      return 0;

    }

  }

  return (1 - (uint)bVar2) - (uint)(bVar2 != 0);

}
