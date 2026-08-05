// =============================================================================
// FUN_004a7e30
// -----------------------------------------------------------------------------
// Stable ID: aa_004a7e30
// Address:   0x004a7e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a7e30 @ 0x004a7e30
// Stable ID: aa_004a7e30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×13, return×9.
//  - Notable callees: FUN_004bf800×2, FUN_004935b0, FUN_004a69f0, FUN_004a74d0, FUN_004a7e30.
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

int __thiscall FUN_004a7e30(int param_1,int param_2)



{

  void *pvVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  uint uVar5;

  int iVar6;

  

  if (param_1 == param_2) {

    return param_1;

  }

  iVar6 = *(int *)(param_2 + 4);

  if (iVar6 != 0) {

    uVar5 = *(int *)(param_2 + 8) - iVar6 >> 2;

    if (uVar5 != 0) {

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = *(int *)(param_1 + 8) - (int)pvVar1 >> 2;

      }

      if (uVar5 <= uVar4) {

        FUN_004bf800(iVar6,*(int *)(param_2 + 8),pvVar1);

        if (*(int *)(param_2 + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

          return param_1;

        }

        *(int *)(param_1 + 8) =

             *(int *)(param_1 + 4) + (*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2) * 4;

        return param_1;

      }

      if (pvVar1 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = *(int *)(param_1 + 0xc) - (int)pvVar1 >> 2;

      }

      if (uVar4 < uVar5) {

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        if (*(int *)(param_2 + 4) == 0) {

          iVar6 = 0;

        }

        else {

          iVar6 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2;

        }

        cVar2 = FUN_004a69f0(iVar6);

        if (cVar2 == '\0') {

          return param_1;

        }

        uVar3 = FUN_004a74d0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 4));

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

        return param_1;

      }

      if (pvVar1 == (void *)0x0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 8) - (int)pvVar1 >> 2;

      }

      iVar6 = *(int *)(param_2 + 4) + iVar6 * 4;

      FUN_004bf800(*(int *)(param_2 + 4),iVar6,pvVar1);

      uVar3 = FUN_004935b0(iVar6,*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1,

                           param_2);

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
