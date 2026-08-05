// =============================================================================
// FUN_00968c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00968c00
// Address:   0x00968c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00968c00 @ 0x00968c00
// Stable ID: aa_00968c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00968c00.
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

uint32_t /* width from decompiler */ FUN_00968c00(void)



{

  int iVar1;

  

  if (0xfffe02ff < *(uint *)(DAT_00d1f044 + 0xd8)) {

    DAT_00afa360 = 1;

    return 0;

  }

  iVar1 = (**(code **)(**(int **)(DAT_00d1f044 + 4) + 0x28))

                    (*(int **)(DAT_00d1f044 + 4),0,1,0x16,0,1,0x54534e49);

  if ((iVar1 == 0) &&

     (iVar1 = (**(code **)(*DAT_00d1f610 + 0x1c))(DAT_00d1f610,0x9a,0x54534e49), iVar1 == 0)) {

    DAT_00afa360 = 1;

    return 0;

  }

  DAT_00afa360 = 2;

  return 0;

}
