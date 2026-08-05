// =============================================================================
// FUN_0078e670
// -----------------------------------------------------------------------------
// Stable ID: aa_0078e670
// Address:   0x0078e670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078e670 @ 0x0078e670
// Stable ID: aa_0078e670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0078e670.
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

uint32_t /* width from decompiler */ FUN_0078e670(void)



{

  char cVar1;

  int in_EAX;

  

  if ((*(char *)(DAT_00d17948 + 4) != '\0') && (*(int *)(in_EAX + 0x948) != 0)) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x948) + 0x3c4))();

    if (cVar1 != '\0') {

      return 1;

    }

  }

  return 0;

}
