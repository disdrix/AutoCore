// =============================================================================
// FUN_0042adb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042adb0
// Address:   0x0042adb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042adb0 @ 0x0042adb0
// Stable ID: aa_0042adb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0042adb0, FUN_00780060, swi.
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

void FUN_0042adb0(void)



{

  code *pcVar1;

  char *in_EAX;

  

  if (*in_EAX != '\0') {

    FUN_00780060();

    return;

  }

  if ((DAT_00afddd4 == '\0') && (DAT_00afddd0 < DAT_00d179e8)) {

    return;

  }

  pcVar1 = (code *)swi(3);

  (*pcVar1)();

  return;

}
