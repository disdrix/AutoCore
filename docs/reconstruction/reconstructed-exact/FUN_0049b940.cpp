// =============================================================================
// FUN_0049b940
// -----------------------------------------------------------------------------
// Stable ID: aa_0049b940
// Address:   0x0049b940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049b940 @ 0x0049b940
// Stable ID: aa_0049b940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_00498be0, FUN_00499a70, FUN_00499cb0, FUN_00499e20, FUN_0049aa60, FUN_0049b940, memmove.
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

void FUN_0049b940(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *_Src;

  uint32_t /* width from decompiler */ *_Dst;

  

  _Dst = DAT_00b035d8;

  _Src = DAT_00b035d8;

  if (DAT_00b035d8 != DAT_00b035dc) {

    do {

      _Src = _Src + 1;

      pvVar1 = (void *)*_Dst;

      if (*(char *)((int)pvVar1 + 0x17c) != '\0') {

        memmove(_Dst,_Src,((int)DAT_00b035dc - (int)_Src >> 2) * 4);

        DAT_00b035dc = DAT_00b035dc + -1;

        FUN_00499a70();

        FUN_00499e20();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      if (*(int *)((int)pvVar1 + 0x180) == DAT_00b035d0) {

        if (*(char *)((int)pvVar1 + 0x1dc) == '\0') {

          FUN_0049aa60();

        }

        FUN_00499cb0(param_2);

        FUN_00498be0(param_1);

      }

      _Dst = _Dst + 1;

    } while (_Dst != DAT_00b035dc);

  }

  DAT_00b035d0 = DAT_00b035d0 + 1;

  return;

}
