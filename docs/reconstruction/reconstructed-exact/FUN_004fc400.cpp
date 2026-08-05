// =============================================================================
// FUN_004fc400
// -----------------------------------------------------------------------------
// Stable ID: aa_004fc400
// Address:   0x004fc400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004fc400 @ 0x004fc400
// Stable ID: aa_004fc400
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_004b8ed0, FUN_004b99c0, FUN_004fc400, FUN_00516de0, memmove.
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

void __thiscall FUN_004fc400(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  void *pvVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *_Src;

  uint32_t /* width from decompiler */ *_Dst;

  

  iVar1 = *(int *)(param_1 + -0x418);

  if (iVar1 != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0xec))(param_2);

  }

  _Dst = *(uint32_t /* width from decompiler */ **)(param_1 + -0x340);

  if (_Dst != *(uint32_t /* width from decompiler */ **)(param_1 + -0x33c)) {

    _Src = _Dst + 1;

    do {

      pvVar2 = (void *)*_Dst;

      cVar3 = FUN_004b8ed0(param_2);

      if (cVar3 == '\0') {

        _Dst = _Dst + 1;

        _Src = _Src + 1;

      }

      else {

        memmove(_Dst,_Src,(*(int *)(param_1 + -0x33c) - (int)_Src >> 2) * 4);

        *(int *)(param_1 + -0x33c) = *(int *)(param_1 + -0x33c) + -4;

        if (pvVar2 != (void *)0x0) {

          FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar2);

        }

      }

    } while (_Dst != *(uint32_t /* width from decompiler */ **)(param_1 + -0x33c));

  }

  FUN_00516de0(param_2);

  return;

}
