// =============================================================================
// FUN_00872f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00872f30
// Address:   0x00872f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00872f30 @ 0x00872f30
// Stable ID: aa_00872f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00872f30.
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

uint32_t /* width from decompiler */ FUN_00872f30(void)



{

  char cVar1;

  int in_EAX;

  

  if (*(int *)(in_EAX + 0x5a8) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x5a8) + 0x3bc))();

    if (cVar1 != '\0') {

      return 1;

    }

  }

  return 0;

}
