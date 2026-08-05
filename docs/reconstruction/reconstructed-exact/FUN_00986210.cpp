// =============================================================================
// FUN_00986210
// -----------------------------------------------------------------------------
// Stable ID: aa_00986210
// Address:   0x00986210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00986210 @ 0x00986210
// Stable ID: aa_00986210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_004406e0, FUN_0074e3e0, FUN_00986210, memmove.
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

void FUN_00986210(int param_1)



{

  int *piVar1;

  int *_Dst;

  int unaff_EDI;

  

  piVar1 = *(int **)(unaff_EDI + 8);

  _Dst = *(int **)(unaff_EDI + 4);

  if (_Dst != piVar1) {

    do {

      if (*_Dst == param_1) break;

      _Dst = _Dst + 1;

    } while (_Dst != piVar1);

    if (_Dst != piVar1) {

      FUN_0074e3e0();

      memmove(_Dst,_Dst + 1,(*(int *)(unaff_EDI + 8) - (int)(_Dst + 1) >> 2) * 4);

      *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + -4;

      FUN_004406e0();

    }

  }

  return;

}
