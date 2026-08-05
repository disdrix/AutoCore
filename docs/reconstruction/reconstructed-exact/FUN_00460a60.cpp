// =============================================================================
// FUN_00460a60
// -----------------------------------------------------------------------------
// Stable ID: aa_00460a60
// Address:   0x00460a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00460a60 @ 0x00460a60
// Stable ID: aa_00460a60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00460a60.
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

void FUN_00460a60(int param_1,int param_2)



{

  int *in_EAX;

  int iVar1;

  int iVar2;

  int *unaff_EBX;

  

  iVar2 = param_2 - param_1 >> 3;

  if (0 < iVar2) {

    do {

      iVar1 = iVar2 / 2;

      if (*(int *)(param_1 + iVar1 * 8) < *in_EAX) {

        param_1 = param_1 + 8 + iVar1 * 8;

        iVar1 = iVar2 + (-1 - iVar1);

      }

      iVar2 = iVar1;

    } while (0 < iVar1);

  }

  *unaff_EBX = param_1;

  return;

}
