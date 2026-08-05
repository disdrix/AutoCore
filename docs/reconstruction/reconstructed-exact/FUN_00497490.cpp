// =============================================================================
// FUN_00497490
// -----------------------------------------------------------------------------
// Stable ID: aa_00497490
// Address:   0x00497490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00497490 @ 0x00497490
// Stable ID: aa_00497490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×13, return×9.
//  - Notable callees: FUN_0043fb00×2, FUN_0043f850, FUN_0043fae0, FUN_00497490, FUN_005dd920.
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

int __thiscall FUN_00497490(int param_1,int param_2)



{

  void *pvVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  

  if (param_1 == param_2) {

    return param_1;

  }

  iVar4 = *(int *)(param_2 + 4);

  if (iVar4 != 0) {

    uVar6 = *(int *)(param_2 + 8) - iVar4 >> 4;

    if (uVar6 != 0) {

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = *(int *)(param_1 + 8) - (int)pvVar1 >> 4;

      }

      if (uVar6 <= uVar3) {

        FUN_0043fb00(iVar4,*(int *)(param_2 + 8),pvVar1,param_2);

        if (*(int *)(param_2 + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

          return param_1;

        }

        *(int *)(param_1 + 8) =

             (*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 4) * 0x10 + *(int *)(param_1 + 4);

        return param_1;

      }

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = *(int *)(param_1 + 0xc) - (int)pvVar1 >> 4;

      }

      if (uVar3 < uVar6) {

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        if (*(int *)(param_2 + 4) == 0) {

          iVar4 = 0;

        }

        else {

          iVar4 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 4;

        }

        cVar2 = FUN_0043f850(iVar4);

        if (cVar2 == '\0') {

          return param_1;

        }

        uVar5 = FUN_0043fae0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 4));

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

        return param_1;

      }

      if (pvVar1 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(param_1 + 8) - (int)pvVar1 >> 4;

      }

      iVar4 = iVar4 * 0x10 + *(int *)(param_2 + 4);

      FUN_0043fb00(*(int *)(param_2 + 4),iVar4,pvVar1,param_2);

      uVar5 = FUN_005dd920(iVar4,*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1,

                           param_2);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

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
