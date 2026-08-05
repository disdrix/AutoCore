// =============================================================================
// FUN_0052aae0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052aae0
// Address:   0x0052aae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052aae0 @ 0x0052aae0
// Stable ID: aa_0052aae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, while×1.
//  - Notable callees: FUN_0052aae0, FUN_005710c0, FUN_005714e0, FUN_00571620, FUN_00571830.
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

void __fastcall FUN_0052aae0(int param_1)



{

  void *pvVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint uStack_8;

  uint local_4;

  

  if ((*(int *)(param_1 + 0xd80) != 0) &&

     (local_4 = *(int *)(param_1 + 0xd84) - *(int *)(param_1 + 0xd80) >> 2, local_4 != 0)) {

    iVar7 = 0;

    while( true ) {

      if (*(int *)(param_1 + 0xd80) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 0xd84) - *(int *)(param_1 + 0xd80) >> 2;

      }

      pvVar1 = *(void **)(param_1 + 0xd80);

      if (iVar3 <= iVar7) break;

      iVar3 = iVar7 * 4;

      iVar4 = FUN_005710c0(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)((int)pvVar1 + iVar3) + 0xa8) + 0x34),0,

                           0);

      if (iVar4 == 0) {

        iVar4 = (**(code **)(**(int **)(*(int *)(param_1 + 0xd80) + iVar3) + 0x25c))();

        if (0 < iVar4) {

          local_4 = local_4 & 0xffffff00;

          uStack_8 = uStack_8 & 0xffffff00;

          cVar2 = FUN_005714e0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xd80) + iVar3),&local_4,&uStack_8

                               ,1,0xffffffff);

          if (cVar2 != '\0') {

            puVar8 = (uint32_t /* width from decompiler */ *)(iVar3 + *(int *)(param_1 + 0xd80));

            uVar6 = (**(code **)(*(int *)*puVar8 + 0x25c))();

            FUN_00571620(*puVar8,local_4,uStack_8,uVar6);

          }

        }

        iVar7 = iVar7 + 1;

      }

      else {

        uVar6 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x160);

        uVar9 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164);

        uVar5 = (**(code **)(**(int **)(*(int *)(param_1 + 0xd80) + iVar3) + 0x25c))(uVar6,uVar9);

        FUN_00571830(uVar5,uVar6,uVar9);

        iVar7 = iVar7 + 1;

      }

    }

    if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd80) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd84) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xd88) = 0;

  }

  return;

}
