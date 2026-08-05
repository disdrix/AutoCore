// =============================================================================
// FUN_0046ff50
// -----------------------------------------------------------------------------
// Stable ID: aa_0046ff50
// Address:   0x0046ff50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046ff50 @ 0x0046ff50
// Stable ID: aa_0046ff50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00476d60×3, FUN_0046ff50.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_0046ff50(int param_1)



{

  int in_EAX;

  int unaff_EDI;

  

  if ((param_1 != 0) && (unaff_EDI != 0)) {

    if (in_EAX < -0x80000000) {

      if (in_EAX < 0) {

        FUN_00476d60();

        in_EAX = 0;

      }

    }

    else {

      FUN_00476d60();

      in_EAX = 0x7fffffff;

    }

    *(uint *)(unaff_EDI + 8) = *(uint *)(unaff_EDI + 8) | 1;

    *(int *)(unaff_EDI + 0xfc) = in_EAX;

    *(float *)(unaff_EDI + 0x28) = (float)in_EAX * (float)_DAT_00aaa600;

    if (in_EAX == 0) {

      FUN_00476d60();

    }

  }

  return;

}
