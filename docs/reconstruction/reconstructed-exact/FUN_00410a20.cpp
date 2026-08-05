// =============================================================================
// FUN_00410a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00410a20
// Address:   0x00410a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00410a20 @ 0x00410a20
// Stable ID: aa_00410a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×13, return×9.
//  - Notable callees: FUN_004e2e80×2, FUN_0040df00, FUN_00410a20, FUN_00439dd0, memmove.
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

void FUN_00410a20(void)



{

  void *_Src;

  void *_Dst;

  int iVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint uVar6;

  int unaff_ESI;

  

  if (unaff_ESI == in_EAX) {

    return;

  }

  _Src = *(void **)(in_EAX + 4);

  if (_Src != (void *)0x0) {

    uVar6 = *(int *)(in_EAX + 8) - (int)_Src >> 2;

    if (uVar6 != 0) {

      _Dst = *(void **)(unaff_ESI + 4);

      if (_Dst == (void *)0x0) {

        uVar5 = 0;

      }

      else {

        uVar5 = *(int *)(unaff_ESI + 8) - (int)_Dst >> 2;

      }

      if (uVar6 <= uVar5) {

        memmove(_Dst,_Src,(*(int *)(in_EAX + 8) - (int)_Src >> 2) * 4);

        if (*(int *)(in_EAX + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4);

          return;

        }

        *(int *)(unaff_ESI + 8) =

             *(int *)(unaff_ESI + 4) + (*(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2) * 4;

        return;

      }

      if (_Dst == (void *)0x0) {

        uVar5 = 0;

      }

      else {

        uVar5 = *(int *)(unaff_ESI + 0xc) - (int)_Dst >> 2;

      }

      if (uVar5 < uVar6) {

        if (_Dst != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(_Dst);

        }

        if (*(int *)(in_EAX + 4) == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 2;

        }

        cVar2 = FUN_0040df00(iVar3);

        if (cVar2 == '\0') {

          return;

        }

        uVar4 = FUN_004e2e80(*(uint32_t /* width from decompiler */ *)(in_EAX + 4),*(uint32_t /* width from decompiler */ *)(in_EAX + 8),

                             *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4));

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = uVar4;

        return;

      }

      if (_Dst == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(unaff_ESI + 8) - (int)_Dst >> 2;

      }

      iVar1 = *(int *)(in_EAX + 4);

      FUN_00439dd0(_Dst);

      uVar4 = FUN_004e2e80(iVar1 + iVar3 * 4,*(uint32_t /* width from decompiler */ *)(in_EAX + 8),

                           *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = uVar4;

      return;

    }

  }

  if (*(void **)(unaff_ESI + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(unaff_ESI + 4));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  return;

}
