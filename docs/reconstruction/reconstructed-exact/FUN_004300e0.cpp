// =============================================================================
// FUN_004300e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004300e0
// Address:   0x004300e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004300e0 @ 0x004300e0
// Stable ID: aa_004300e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004300e0.
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

void FUN_004300e0(void)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int *in_EAX;

  int *unaff_EDI;

  

  piVar2 = (int *)*unaff_EDI;

  iVar3 = *in_EAX;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *unaff_EDI = iVar3;

  if (iVar3 != 0) {

    *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;

  }

  return;

}
