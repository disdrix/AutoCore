// =============================================================================
// FUN_00695ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00695ad0
// Address:   0x00695ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00695ad0 @ 0x00695ad0
// Stable ID: aa_00695ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×10, return×8.
//  - Notable callees: FUN_00690240×2, FUN_00693430×2, FUN_006954c0×2, FUN_00690ae0, FUN_006944c0, FUN_006949f0, FUN_006954f0, FUN_00695ad0.
//  - Return sites: 8.

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

int __thiscall FUN_00695ad0(int param_1,int param_2)



{

  int iVar1;

  char cVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint uVar6;

  

  if (param_1 == param_2) {

    return param_1;

  }

  if (*(int *)(param_2 + 4) != 0) {

    iVar5 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4);

    iVar1 = iVar5 >> 0x1f;

    iVar5 = iVar5 / 0x30 + iVar1;

    uVar6 = iVar5 - iVar1;

    if (iVar5 != iVar1) {

      iVar1 = *(int *)(param_1 + 4);

      if (iVar1 == 0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)(param_1 + 8) - iVar1) / 0x30;

      }

      if (uVar6 <= uVar3) {

        uVar4 = FUN_00693430(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(int *)(param_2 + 8),iVar1,param_2);

        FUN_006954c0(uVar4,*(uint32_t /* width from decompiler */ *)(param_1 + 8));

        if (*(int *)(param_2 + 4) == 0) {

          *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

          return param_1;

        }

        *(int *)(param_1 + 8) =

             ((*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x30) * 0x30 + *(int *)(param_1 + 4)

        ;

        return param_1;

      }

      if (iVar1 == 0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)(param_1 + 0xc) - iVar1) / 0x30;

      }

      if (uVar3 < uVar6) {

        if (iVar1 != 0) {

          FUN_006954c0(iVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 8));

                    /* WARNING: Subroutine does not return */

          operator_delete(*(void **)(param_1 + 4));

        }

        uVar4 = FUN_00690240();

        cVar2 = FUN_00690ae0(uVar4);

        if (cVar2 == '\0') {

          return param_1;

        }

        uVar4 = FUN_006949f0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 4));

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

        return param_1;

      }

      iVar5 = FUN_00690240();

      iVar5 = iVar5 * 0x30 + *(int *)(param_2 + 4);

      FUN_00693430(*(int *)(param_2 + 4),iVar5,iVar1,param_2);

      uVar4 = FUN_006944c0(iVar5,*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1,

                           param_2);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

      return param_1;

    }

  }

  FUN_006954f0();

  return param_1;

}
