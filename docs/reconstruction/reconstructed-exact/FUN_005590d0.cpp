// =============================================================================
// FUN_005590d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005590d0
// Address:   0x005590d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005590d0 @ 0x005590d0
// Stable ID: aa_005590d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×11, return×8.
//  - Notable callees: FUN_004e0e90×2, FUN_004e1400×2, FUN_004e2590, FUN_004e43f0, FUN_00558e10, FUN_005590d0.
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

int __thiscall FUN_005590d0(int param_1,int param_2)



{

  void *pvVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint uVar8;

  

  if (param_1 == param_2) {

    return param_1;

  }

  iVar4 = *(int *)(param_2 + 4);

  if (iVar4 != 0) {

    iVar7 = *(int *)(param_2 + 8) - iVar4;

    iVar5 = iVar7 >> 0x1f;

    iVar7 = iVar7 / 0x134 + iVar5;

    uVar8 = iVar7 - iVar5;

    if (iVar7 != iVar5) {

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)(param_1 + 8) - (int)pvVar1) / 0x134;

      }

      if (uVar8 <= uVar3) {

        FUN_004e1400(iVar4,*(uint32_t /* width from decompiler */ *)(param_2 + 8),pvVar1,param_2);

        iVar4 = 0;

        if (*(int *)(param_2 + 4) != 0) {

          iVar4 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x134;

        }

        *(int *)(param_1 + 8) = *(int *)(param_1 + 4) + iVar4 * 0x134;

        return param_1;

      }

      if (pvVar1 == (void *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = (*(int *)(param_1 + 0xc) - (int)pvVar1) / 0x134;

      }

      if (uVar3 < uVar8) {

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        uVar6 = FUN_004e0e90();

        cVar2 = FUN_00558e10(uVar6);

        if (cVar2 == '\0') {

          return param_1;

        }

        uVar6 = FUN_004e43f0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),*(uint32_t /* width from decompiler */ *)(param_2 + 8),

                             *(uint32_t /* width from decompiler */ *)(param_1 + 4));

        *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar6;

        return param_1;

      }

      iVar5 = FUN_004e0e90();

      iVar4 = iVar4 + iVar5 * 0x134;

      FUN_004e1400(*(uint32_t /* width from decompiler */ *)(param_2 + 4),iVar4,pvVar1,param_2);

      uVar6 = FUN_004e2590(iVar4,*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_1,

                           param_2);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar6;

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
