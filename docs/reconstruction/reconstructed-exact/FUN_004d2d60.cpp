// =============================================================================
// FUN_004d2d60
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2d60
// Address:   0x004d2d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d2d60 @ 0x004d2d60
// Stable ID: aa_004d2d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×1.
//  - Notable callees: FUN_004d2d60, memmove.
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

void __thiscall FUN_004d2d60(int param_1,int param_2)



{

  int iVar1;

  int *_Src;

  int *_Dst;

  

  _Dst = *(int **)(param_1 + 0xe874);

  if ((_Dst != (int *)0x0) && (*(int *)(param_1 + 0xe878) - (int)_Dst >> 2 != 0)) {

    if (_Dst != *(int **)(param_1 + 0xe878)) {

      _Src = _Dst + 1;

      do {

        if ((*_Dst == 0) || (param_2 != *(int *)(*_Dst + 0x260))) {

          _Dst = _Dst + 1;

          _Src = _Src + 1;

        }

        else {

          memmove(_Dst,_Src,(*(int *)(param_1 + 0xe878) - (int)_Src >> 2) * 4);

          *(int *)(param_1 + 0xe878) = *(int *)(param_1 + 0xe878) + -4;

        }

      } while (_Dst != *(int **)(param_1 + 0xe878));

    }

    iVar1 = 0;

    if (0 < *(int *)(param_1 + 0xe810)) {

      do {

        if (*(int *)(*(int *)(param_1 + 0xe80c) + iVar1 * 4) == param_2) {

          *(int *)(param_1 + 0xe810) = *(int *)(param_1 + 0xe810) + -1;

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe80c) + iVar1 * 4) =

               *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xe80c) + *(int *)(param_1 + 0xe810) * 4);

        }

        else {

          iVar1 = iVar1 + 1;

        }

      } while (iVar1 < *(int *)(param_1 + 0xe810));

    }

  }

  return;

}
