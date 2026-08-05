// =============================================================================
// FUN_00423780
// -----------------------------------------------------------------------------
// Stable ID: aa_00423780
// Address:   0x00423780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00423780 @ 0x00423780
// Stable ID: aa_00423780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_00423870×2, FUN_00423780, FUN_004237e0.
//  - Return sites: 3.

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

void __fastcall FUN_00423780(int *param_1)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *param_1;

  if (in_EAX < *(int *)(iVar1 + -0xc)) {

    in_EAX = *(int *)(iVar1 + -0xc);

  }

  if (1 < *(int *)(iVar1 + -4)) {

    FUN_004237e0(param_1);

    return;

  }

  if (*(int *)(iVar1 + -8) < in_EAX) {

    if (0x400 < *(int *)(iVar1 + -8)) {

      FUN_00423870();

      return;

    }

    FUN_00423870();

  }

  return;

}
