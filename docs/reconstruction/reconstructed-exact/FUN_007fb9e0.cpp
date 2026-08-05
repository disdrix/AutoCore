// =============================================================================
// FUN_007fb9e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb9e0
// Address:   0x007fb9e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fb9e0 @ 0x007fb9e0
// Stable ID: aa_007fb9e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007fb9e0.
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

void FUN_007fb9e0(void)



{

  char cVar1;

  int unaff_ESI;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if (*(int *)(unaff_ESI + 0x1144) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xd0))();

    if ((cVar1 != '\0') && (unaff_EDI != 0)) {

      uVar3 = 1;

      uVar2 = 1;

      (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0x1d8))();

      (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0x13c))();

                    /* WARNING: Could not recover jumptable at 0x007fba28. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0x34c))(uVar2,uVar3);

      return;

    }

  }

  return;

}
