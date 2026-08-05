// =============================================================================
// FUN_0052ac60
// -----------------------------------------------------------------------------
// Stable ID: aa_0052ac60
// Address:   0x0052ac60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052ac60 @ 0x0052ac60
// Stable ID: aa_0052ac60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_0052ac60, memmove.
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

uint32_t /* width from decompiler */ __thiscall FUN_0052ac60(int param_1,int param_2)



{

  int *_Dst;

  

  _Dst = *(int **)(param_1 + 0xd80);

  if (_Dst != *(int **)(param_1 + 0xd84)) {

    while ((*(int *)(param_2 + 0x160) != *(int *)(*_Dst + 0x160) ||

           (*(int *)(param_2 + 0x164) != *(int *)(*_Dst + 0x164)))) {

      _Dst = _Dst + 1;

      if (_Dst == *(int **)(param_1 + 0xd84)) {

        return 1;

      }

    }

    memmove(_Dst,_Dst + 1,(*(int *)(param_1 + 0xd84) - (int)(_Dst + 1) >> 2) * 4);

    *(int *)(param_1 + 0xd84) = *(int *)(param_1 + 0xd84) + -4;

  }

  return 1;

}
