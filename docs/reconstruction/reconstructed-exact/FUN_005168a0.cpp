// =============================================================================
// FUN_005168a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005168a0
// Address:   0x005168a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005168a0 @ 0x005168a0
// Stable ID: aa_005168a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_005168a0, memmove.
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

void FUN_005168a0(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *_Src;

  uint32_t /* width from decompiler */ *_Dst;

  

  _Dst = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (_Dst != *(uint32_t /* width from decompiler */ **)(param_1 + 8)) {

    _Src = _Dst + 2;

    do {

      iVar1 = CVOGReaction_ResolveObjectTarget(1,*_Dst,_Dst[1]);

      if ((iVar1 == 0) || ((0 < param_2 && (*(int *)(*(int *)(iVar1 + 0xa8) + 0x38) != param_2)))) {

        memmove(_Dst,_Src,(*(int *)(param_1 + 8) - (int)_Src >> 3) * 8);

        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -8;

      }

      else {

        _Dst = _Dst + 2;

        _Src = _Src + 2;

      }

    } while (_Dst != *(uint32_t /* width from decompiler */ **)(param_1 + 8));

  }

  return;

}
