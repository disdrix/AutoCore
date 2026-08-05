// =============================================================================
// FUN_0093c370
// -----------------------------------------------------------------------------
// Stable ID: aa_0093c370
// Address:   0x0093c370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093c370 @ 0x0093c370
// Stable ID: aa_0093c370
// Embedded strings (evidence for future rename):
//   - "

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: do×2, if×1, return×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0093bac0, FUN_0093c370.
//  - Strings: "

    ;

    FUN_007a69d0(".
//  - Return sites: 1.

    ;

    FUN_007a69d0("
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

void FUN_0093c370(void)



{

  int unaff_ESI;

  char *pcVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  if (*(char *)(unaff_ESI + 0xb6) == '\0') {

    FUN_0093bac0(unaff_ESI,0);

    uVar5 = 0;

    uVar4 = 1;

    uVar3 = 0x4e23;

    uVar2 = 0xffffffff;

    pcVar1 = 

    "This will SELL ALL ITEMS of the type you selected!  This cannot be undone!  Are you sure you wish to do this?"

    ;

    FUN_007a69d0("This will SELL ALL ITEMS of the type you selected!  This cannot be undone!  Are you sure you wish to do this?"

                 ,0xffffffff,0x4e23,1,0);

    uVar2 = FUN_007a6de0(pcVar1,uVar2);

    FUN_007fdfb0(unaff_ESI,uVar2,uVar3,uVar4,uVar5);

  }

  return;

}
