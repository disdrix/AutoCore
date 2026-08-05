// =============================================================================
// FUN_0096d550
// -----------------------------------------------------------------------------
// Stable ID: aa_0096d550
// Address:   0x0096d550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096d550 @ 0x0096d550
// Stable ID: aa_0096d550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_0044adc0, FUN_0096d550, memmove.
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

uint32_t /* width from decompiler */ __thiscall FUN_0096d550(int param_1,int param_2)



{

  void *pvVar1;

  int *_Dst;

  

  _Dst = *(int **)(param_1 + 0x6c);

  while( true ) {

    if (_Dst == *(int **)(param_1 + 0x70)) {

      return 0xffffffff;

    }

    if (*(int *)(*_Dst + 8) == param_2) break;

    _Dst = _Dst + 1;

  }

  pvVar1 = (void *)*_Dst;

  memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x70) - (int)(_Dst + 1) >> 2) * 4);

  *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -4;

  if (pvVar1 != (void *)0x0) {

    FUN_0044adc0(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  return 0;

}
