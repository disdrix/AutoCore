// =============================================================================
// FUN_0093a8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0093a8e0
// Address:   0x0093a8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093a8e0 @ 0x0093a8e0
// Stable ID: aa_0093a8e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0091f580, FUN_0093a8e0.
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

void FUN_0093a8e0(void)



{

  char cVar1;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0xf38) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xf38) + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_0091f580(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xf38));

    }

  }

  return;

}
