// =============================================================================
// FUN_004c2ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c2ab0
// Address:   0x004c2ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c2ab0 @ 0x004c2ab0
// Stable ID: aa_004c2ab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1.
//  - Notable callees: FUN_004c22a0×2, FUN_004c2ab0, FUN_004c2bb0, memmove.
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

void __thiscall FUN_004c2ab0(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *_Dst;

  

  _Dst = *(int **)(param_1 + 500);

  if (_Dst != *(int **)(param_1 + 0x1f8)) {

    while ((*(int *)*_Dst != param_2 || (((int *)*_Dst)[1] != param_3))) {

      _Dst = _Dst + 1;

      if (_Dst == *(int **)(param_1 + 0x1f8)) {

        return;

      }

    }

    iVar2 = *(int *)(param_1 + 0x1e4);

    if ((iVar2 == 0) ||

       ((uint)(*(int *)(param_1 + 0x1ec) - iVar2 >> 2) <=

        (uint)(*(int *)(param_1 + 0x1e8) - iVar2 >> 2))) {

      FUN_004c2bb0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1e8),1,_Dst);

    }

    else {

      piVar1 = *(int **)(param_1 + 0x1e8);

      *piVar1 = *_Dst;

      *(int **)(param_1 + 0x1e8) = piVar1 + 1;

    }

    iVar2 = FUN_004c22a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1d8),*(uint32_t /* width from decompiler */ *)(param_1 + 0x1dc));

    iVar3 = FUN_004c22a0(*(uint32_t /* width from decompiler */ *)*_Dst,((uint32_t /* width from decompiler */ *)*_Dst)[1]);

    if ((((iVar2 != 0) && (iVar3 != 0)) && (*(int *)(iVar3 + 0x24) < 3)) &&

       (1 < *(int *)(iVar2 + 0x24))) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24) = 1;

    }

    memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0x1f8) - (int)(_Dst + 1) >> 2) * 4);

    *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1f8) + -4;

  }

  return;

}
