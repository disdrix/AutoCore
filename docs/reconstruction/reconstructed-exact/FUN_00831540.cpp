// =============================================================================
// FUN_00831540
// -----------------------------------------------------------------------------
// Stable ID: aa_00831540
// Address:   0x00831540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00831540 @ 0x00831540
// Stable ID: aa_00831540
// Embedded strings (evidence for future rename):
//   - "(Filtered Out)"
//   - "(Not Filtered)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00831340, FUN_00831540, FUN_0095c5a0.
//  - Strings: "(Filtered Out)"; "(Not Filtered)".
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

void FUN_00831540(void)



{

  int *piVar1;

  int in_EAX;

  uint uVar2;

  int unaff_EDI;

  

  uVar2 = 1 << ((byte)in_EAX & 0x1f);

  if ((DAT_00af9218 & uVar2) == 0) {

    DAT_00af9218 = DAT_00af9218 | uVar2;

  }

  else {

    DAT_00af9218 = DAT_00af9218 & ~uVar2;

  }

  if (*(int *)(unaff_EDI + 0x5a0 + in_EAX * 4) != 0) {

    piVar1 = *(int **)(unaff_EDI + 0x5a0 + in_EAX * 4);

    if ((DAT_00af9218 & uVar2) == 0) {

      (**(code **)(*piVar1 + 0x1d8))("(Filtered Out)",1,1);

    }

    else {

      (**(code **)(*piVar1 + 0x1d8))("(Not Filtered)");

    }

    (**(code **)(**(int **)(unaff_EDI + 0x5a0 + in_EAX * 4) + 0x34c))();

  }

  FUN_00831340();

  FUN_0095c5a0();

  return;

}
