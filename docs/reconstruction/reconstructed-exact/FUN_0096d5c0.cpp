// =============================================================================
// FUN_0096d5c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096d5c0
// Address:   0x0096d5c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096d5c0 @ 0x0096d5c0
// Stable ID: aa_0096d5c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_0044adc0, FUN_0096d5c0, memmove.
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

uint32_t /* width from decompiler */ __thiscall FUN_0096d5c0(int param_1,int param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *_Dst;

  int iVar2;

  

  _Dst = *(uint32_t /* width from decompiler */ **)(param_1 + 0x6c);

  while( true ) {

    if (_Dst == *(uint32_t /* width from decompiler */ **)(param_1 + 0x70)) {

      return 0;

    }

    pvVar1 = (void *)*_Dst;

    if (*(int *)((int)pvVar1 + 0xc) == 0) {

      iVar2 = -1;

    }

    else {

      iVar2 = *(int *)(*(int *)((int)pvVar1 + 0xc) + 8);

    }

    if (iVar2 == param_2) break;

    _Dst = _Dst + 1;

  }

  memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x70) - (int)(_Dst + 1) >> 2) * 4);

  *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -4;

  FUN_0044adc0(pvVar1);

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
