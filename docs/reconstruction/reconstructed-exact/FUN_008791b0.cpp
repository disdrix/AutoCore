// =============================================================================
// FUN_008791b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008791b0
// Address:   0x008791b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008791b0 @ 0x008791b0
// Stable ID: aa_008791b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_008791b0.
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

int FUN_008791b0(void)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int unaff_ESI;

  

  if ((*(int *)(unaff_ESI + 0x594) != 0) &&

     (iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x594) + 0x464))(),

     iVar1 != *(int *)(unaff_ESI + 0x52c))) {

    iVar2 = 0;

    piVar3 = (int *)(unaff_ESI + 0x530);

    do {

      if (iVar1 == *piVar3) {

        return iVar2;

      }

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 1;

    } while (iVar2 < 7);

  }

  return -1;

}
