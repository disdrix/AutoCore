// =============================================================================
// FUN_007a4f50
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4f50
// Address:   0x007a4f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a4f50 @ 0x007a4f50
// Stable ID: aa_007a4f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: FUN_007a4f50, memmove.
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

uint32_t /* width from decompiler */ __thiscall FUN_007a4f50(int param_1,int param_2,int param_3)



{

  int iVar1;

  int *_Dst;

  

  _Dst = *(int **)(param_1 + 0x18);

  while( true ) {

    if (_Dst == *(int **)(param_1 + 0x1c)) {

      return 0;

    }

    iVar1 = *_Dst;

    if (((iVar1 != 0) && (*(int *)(iVar1 + 0x200) == param_2)) &&

       (*(int *)(iVar1 + 0x204) == param_3)) break;

    _Dst = _Dst + 1;

  }

  if ((void *)*_Dst != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)*_Dst);

  }

  memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x1c) - (int)(_Dst + 1) >> 2) * 4);

  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -4;

  return 1;

}
