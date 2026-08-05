// =============================================================================
// FUN_007fcc10
// -----------------------------------------------------------------------------
// Stable ID: aa_007fcc10
// Address:   0x007fcc10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fcc10 @ 0x007fcc10
// Stable ID: aa_007fcc10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007fcc10, ROUND.
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

void __fastcall FUN_007fcc10(int *param_1)



{

  int iVar1;

  int iVar2;

  int *unaff_ESI;

  float10 fVar3;

  

  if ((param_1 != (int *)0x0) && (unaff_ESI != (int *)0x0)) {

    fVar3 = (float10)(**(code **)(*param_1 + 0x458))();

    iVar1 = (**(code **)(*unaff_ESI + 0x494))();

    iVar2 = (**(code **)(*unaff_ESI + 0x490))();

    iVar1 = (int)ROUND((float)(iVar2 - iVar1) * (float)fVar3);

    if (iVar1 < 0) {

      iVar1 = 0;

    }

    (**(code **)(*unaff_ESI + 0x498))(iVar1);

  }

  return;

}
