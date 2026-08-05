// =============================================================================
// FUN_0055ef30
// -----------------------------------------------------------------------------
// Stable ID: aa_0055ef30
// Address:   0x0055ef30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055ef30 @ 0x0055ef30
// Stable ID: aa_0055ef30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0055e570×2, FUN_0055ef30.
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

void FUN_0055ef30(void)



{

  int unaff_EBX;

  int unaff_ESI;

  int *piVar1;

  

  piVar1 = *(int **)(unaff_ESI + 8);

  if (piVar1 != piVar1 + *(int *)(unaff_ESI + 0xc)) {

    do {

      FUN_0055e570(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4),*piVar1 + 0x4c);

      piVar1 = piVar1 + 1;

    } while (piVar1 != (int *)(*(int *)(unaff_ESI + 8) + *(int *)(unaff_ESI + 0xc) * 4));

  }

  piVar1 = *(int **)(unaff_ESI + 0x14);

  if (piVar1 != piVar1 + *(int *)(unaff_ESI + 0x18)) {

    do {

      FUN_0055e570(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4),*piVar1 + 0x4c);

      piVar1 = piVar1 + 1;

    } while (piVar1 != (int *)(*(int *)(unaff_ESI + 0x14) + *(int *)(unaff_ESI + 0x18) * 4));

  }

  return;

}
