// =============================================================================
// FUN_00731480
// -----------------------------------------------------------------------------
// Stable ID: aa_00731480
// Address:   0x00731480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00731480 @ 0x00731480
// Stable ID: aa_00731480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00731480.
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

uint32_t /* width from decompiler */ FUN_00731480(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  if (DAT_00d1ef70 != 0) {

    iVar2 = DAT_00d1ef74 - DAT_00d1ef70 >> 2;

    if (iVar2 != 0) {

      puVar1 = (uint32_t /* width from decompiler */ *)(DAT_00d1ef74 + -4);

      if (iVar2 != 0) {

        DAT_00d1ef74 = DAT_00d1ef74 + -4;

      }

      return *puVar1;

    }

  }

  return 0;

}
