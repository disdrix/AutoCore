// =============================================================================
// FUN_00965150
// -----------------------------------------------------------------------------
// Stable ID: aa_00965150
// Address:   0x00965150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00965150 @ 0x00965150
// Stable ID: aa_00965150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00965150, memmove.
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

uint32_t /* width from decompiler */ __thiscall FUN_00965150(int param_1,int param_2)



{

  int *piVar1;

  int *_Dst;

  

  piVar1 = *(int **)(param_1 + 0xc);

  _Dst = *(int **)(param_1 + 8);

  if (_Dst != piVar1) {

    do {

      if (*_Dst == param_2) break;

      _Dst = _Dst + 1;

    } while (_Dst != piVar1);

    if (_Dst != piVar1) {

      memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0xc) - (int)(_Dst + 1) >> 2) * 4);

      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -4;

      return 1;

    }

  }

  return 0;

}
