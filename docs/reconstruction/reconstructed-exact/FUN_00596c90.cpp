// =============================================================================
// FUN_00596c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00596c90
// Address:   0x00596c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00596c90 @ 0x00596c90
// Stable ID: aa_00596c90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×13, return×9.
//  - Notable callees: FUN_004e2e80×2, FUN_00506430, FUN_005966b0, FUN_00596c90, memmove.
//  - Return sites: 9.

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

int __thiscall FUN_00596c90(int param_1,int param_2)



{

  void *_Src;

  void *_Dst;

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint uVar5;

  

  if (param_1 == param_2) {

    return param_1;

  }

  _Src = *(void **)(param_2 + 4);

  if (_Src != (void *)0x0) {

    uVar5 = *(int *)(param_2 + 8) - (int)_Src >> 2;

    if (uVar5 != 0) {

      _Dst = *(void **)(param_1 + 4);

      if (_Dst == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = *(int *)(param_1 + 8) - (int)_Dst >> 2;

      }

      if (uVar5 <= uVar4) {

        memmove(_Dst,_Src,(*(int *)(param_2 + 8) - (int)_Src >> 2) * 4);

        if (*(int *)(param_2 + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

          return param_1;

        }

        *(int *)(param_1 + 8) =

             *(int *)(param_1 + 4) + (*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2) * 4;

        return param_1;

      }

      if (_Dst == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = *(int *)(param_1 + 0xc) - (int)_Dst >> 2;

      }

      if (uVar4 < uVar5) {

        if (_Dst != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(_Dst);

        }

        if (*(int *)(param_2 + 4) == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2;

        }

        cVar1 = FUN_005966b0(iVar2);

        if (cVar1 == '\0') {

          return param_1;

        }

        uVar3 = FUN_004e2e80(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 4));

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

        return param_1;

      }

      if (_Dst == (void *)0x0) {

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(param_1 + 8) - (int)_Dst >> 2;

      }

      iVar2 = *(int *)(param_2 + 4) + iVar2 * 4;

      FUN_00506430(*(int *)(param_2 + 4),iVar2,_Dst);

      uVar3 = FUN_004e2e80(iVar2,*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 8));

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

      return param_1;

    }

  }

  if (*(void **)(param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 4));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  return param_1;

}
