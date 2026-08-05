// =============================================================================
// FUN_00476d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00476d60
// Address:   0x00476d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00476d60 @ 0x00476d60
// Stable ID: aa_00476d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00476d60, FUN_00476fa0.
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

void __fastcall FUN_00476d60(char *param_1)



{

  int iVar1;

  int unaff_ESI;

  

  if (((*(byte *)(unaff_ESI + 0x6e) & 0xc) != 0) && (*param_1 == '#')) {

    iVar1 = 1;

    do {

      if ((param_1[iVar1] == ' ') || (param_1[iVar1 + 1] == ' ')) break;

      iVar1 = iVar1 + 2;

    } while (iVar1 < 0xf);

  }

  if (*(code **)(unaff_ESI + 0x44) == (code *)0x0) {

    FUN_00476fa0();

    return;

  }

  (**(code **)(unaff_ESI + 0x44))();

  return;

}
