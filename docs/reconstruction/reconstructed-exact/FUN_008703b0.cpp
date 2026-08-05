// =============================================================================
// FUN_008703b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008703b0
// Address:   0x008703b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008703b0 @ 0x008703b0
// Stable ID: aa_008703b0
// Embedded strings (evidence for future rename):
//   - "%s %s\n"
//   - "Deathmatch"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008703b0, sprintf.
//  - Strings: "%s %s\n"; "Deathmatch".
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

void FUN_008703b0(void)



{

  int unaff_ESI;

  char *pcVar1;

  char acStack_3e8 [1000];

  

  if (*(int *)(unaff_ESI + 0x5ac) != 0) {

    pcVar1 = acStack_3e8;

    (**(code **)(**(int **)(unaff_ESI + 0x5ac) + 0x34c))();

    if ((int *)(DAT_00d1b644 + 0xc950) == (int *)0x0) {

      pcVar1 = (uint8_t *)0x0;

    }

    else {

      sprintf(acStack_3e8,"%s %s\n","Deathmatch" + *(int *)(DAT_00d1b644 + 0xc950) * 0x10,

              &DAT_00a1e540 + *(int *)(DAT_00d1b644 + 0xc954) * 0x10);

    }

    (**(code **)(**(int **)(unaff_ESI + 0x5ac) + 0x1d8))(pcVar1,1,1);

  }

  return;

}
