// =============================================================================
// FUN_0040f5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040f5b0
// Address:   0x0040f5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040f5b0 @ 0x0040f5b0
// Stable ID: aa_0040f5b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×13, return×9.
//  - Notable callees: FUN_004e2e80×2, FUN_00506430×2, FUN_0040df00, FUN_0040f5b0.
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

int __thiscall FUN_0040f5b0(int param_1,int param_2)



{

  void *pvVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  

  if (param_1 == param_2) {

    return param_1;

  }

  iVar5 = *(int *)(param_2 + 4);

  if (iVar5 != 0) {

    uVar6 = *(int *)(param_2 + 8) - iVar5 >> 2;

    if (uVar6 != 0) {

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        uVar4 = 0;

      }

      else {

        uVar4 = *(int *)(param_1 + 8) - (int)pvVar1 >> 2;

      }

      if (uVar6 <= uVar4) {

        FUN_00506430(iVar5,*(int *)(param_2 + 8),pvVar1);

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

      if (uVar4 < uVar6) {

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        if (*(int *)(param_2 + 4) == 0) {

          iVar5 = 0;

        }

        else {

          iVar5 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2;

        }

        cVar2 = FUN_0040df00(iVar5);

        if (cVar2 == '\0') {

          return param_1;

        }

        uVar3 = FUN_004e2e80(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 4));

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

        return param_1;

      }

      if (pvVar1 == (void *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - (int)pvVar1 >> 2;

      }

      iVar5 = *(int *)(param_2 + 4) + iVar5 * 4;

      FUN_00506430(*(int *)(param_2 + 4),iVar5,pvVar1);

      uVar3 = FUN_004e2e80(iVar5,*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 8));

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
