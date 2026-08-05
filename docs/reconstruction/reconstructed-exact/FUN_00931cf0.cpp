// =============================================================================
// FUN_00931cf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00931cf0
// Address:   0x00931cf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00931cf0 @ 0x00931cf0
// Stable ID: aa_00931cf0
// Embedded strings (evidence for future rename):
//   - "You do not meet the requirements to learn this Discipline"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1.
//  - Notable callees: FUN_0052b140, FUN_007fdfb0, FUN_00931cf0.
//  - Strings: "You do not meet the requirements to learn this Discipline".
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

void FUN_00931cf0(void)



{

  char cVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint32_t /* width from decompiler */ local_c;

  

  cVar1 = FUN_0052b140(unaff_EDI);

  if (cVar1 == '\0') {

    FUN_007fdfb0(unaff_ESI,"You do not meet the requirements to learn this Discipline",0xffffffff,1,

                 0);

  }

  else {

    local_c = 0x2097;

    if (*(int *)(unaff_ESI + 0xc78) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,&local_c,0xc,0);

      return;

    }

  }

  return;

}
