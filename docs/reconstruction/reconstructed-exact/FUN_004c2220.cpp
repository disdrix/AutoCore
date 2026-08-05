// =============================================================================
// FUN_004c2220
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2220
// Address:   0x004c2220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c2220 @ 0x004c2220
// Stable ID: aa_004c2220
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_004c2220, memmove.
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

void __thiscall FUN_004c2220(int param_1,int param_2,int param_3)



{

  int *_Dst;

  

  _Dst = *(int **)(param_1 + 500);

  if (_Dst != *(int **)(param_1 + 0x1f8)) {

    while ((*(int *)*_Dst != param_2 || (((int *)*_Dst)[1] != param_3))) {

      _Dst = _Dst + 1;

      if (_Dst == *(int **)(param_1 + 0x1f8)) {

        return;

      }

    }

    if ((void *)*_Dst != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)*_Dst);

    }

    *_Dst = 0;

    memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x1f8) - (int)(_Dst + 1) >> 2) * 4);

    *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1f8) + -4;

  }

  return;

}
