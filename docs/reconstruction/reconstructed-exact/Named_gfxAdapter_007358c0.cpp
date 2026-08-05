// READABILITY (auto CF):
//  - Body size: ~156 non-empty decompiler lines.
//  - Control keywords: if×12, return×5, do×2, while×2, for×1, goto×1.
//  - Notable callees: FUN_006a5dac×5, FUN_006b7a5a×5, FUN_0076cec0×5, vog_LogMessage×5, FUN_00465c40×2, FUN_00735630×2, FUN_0040ead0, FUN_007358c0.
//  - Strings: "Failed to GetAdapterIdentifier."; "%s - %s\r\n%s"; "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxAdapter.cpp"; "Failed to GetAdapterDisplayMode.".
//  - Return sites: 5.

// =============================================================================
// Named_gfxAdapter_007358c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007358c0
// Address:   0x007358c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxAdapter"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x00735b44) */



uint32_t /* width from decompiler */ __fastcall Named_gfxAdapter_007358c0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  uint uVar4;

  int unaff_EBX;

  int unaff_ESI;

  int unaff_EDI;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ auStack_70 [4];

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  void *pvStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  void *pvStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  void *pvStack_44;

  void *pvStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  void *pvStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  int iStack_20;

  int aiStack_18 [3];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009af8b0;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  iVar1 = (**(code **)(**(int **)(param_1 + 0x48) + 0x14))

                    (*(int **)(param_1 + 0x48),*(uint32_t /* width from decompiler */ *)(param_1 + 0x4c),0,param_1 + 0x50);

  if (iVar1 < 0) {

    uVar2 = FUN_006b7a5a(iVar1,"Failed to GetAdapterIdentifier.");

    uVar2 = FUN_006a5dac(iVar1,uVar2);

    uVar2 = FUN_0076cec0(&pvStack_c,"%s - %s\r\n%s",uVar2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxAdapter.cpp",0x5b,3,uVar2);

  }

  iVar1 = (**(code **)(**(int **)(param_1 + 0x48) + 0x20))

                    (*(int **)(param_1 + 0x48),*(uint32_t /* width from decompiler */ *)(param_1 + 0x4c),param_1 + 0x49c);

  if (iVar1 < 0) {

    uVar2 = FUN_006b7a5a(iVar1,"Failed to GetAdapterDisplayMode.");

    uVar2 = FUN_006a5dac(iVar1,uVar2);

    uVar2 = FUN_0076cec0(aiStack_18,"%s - %s\r\n%s",uVar2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxAdapter.cpp",0x62,3,uVar2);

  }

  iStack_20 = 0;

  pvStack_40 = *(void **)(param_1 + 0x4a8);

  pvStack_4c = (void *)0x0;

  uStack_48 = 0;

  pvStack_44 = (void *)0x0;

  uStack_3c = 0;

  pvStack_38 = (void *)0x0;

  uStack_34 = 0;

  uStack_30 = 0;

  uStack_2c = 0;

  FUN_00735630(&pvStack_4c,1);

  FUN_00465c40();

  puVar5 = &DAT_00a24448;

  do {

    puVar6 = puVar5;

    uVar3 = (**(code **)(**(int **)(param_1 + 0x48) + 0x18))

                      (*(int **)(param_1 + 0x48),*(uint32_t /* width from decompiler */ *)(param_1 + 0x4c),*puVar5);

    uVar7 = 0;

    if (uVar3 != 0) {

      do {

        iVar1 = (**(code **)(**(int **)(param_1 + 0x48) + 0x1c))

                          (*(int **)(param_1 + 0x48),*(uint32_t /* width from decompiler */ *)(param_1 + 0x4c),*puVar5,uVar7,

                           &stack0xffffff80);

        puVar5 = puVar6;

        if (iVar1 < 0) {

          uVar2 = FUN_006b7a5a(iVar1,"Failed to EnumAdapterModes.");

          uVar2 = FUN_006a5dac(iVar1,uVar2);

          uVar2 = FUN_0076cec0(aiStack_18,"%s - %s\r\n%s",uVar2);

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxAdapter.cpp",0x7d,3,

                         uVar2);

          puVar5 = puVar6;

        }

        if (((*(int *)(aiStack_18[0] + 0x3c) <= unaff_EDI) &&

            (*(int *)(aiStack_18[0] + 0x40) <= unaff_ESI)) &&

           (uVar4 = FUN_0040ead0(unaff_EBX), *(uint *)(aiStack_18[0] + 0x44) <= uVar4)) {

          iStack_20._0_1_ = 1;

          uStack_60 = 0;

          uStack_5c = 0;

          uStack_54 = 0;

          uStack_50 = 0;

          iVar1 = *(int *)(param_1 + 0x710);

          pvStack_58 = (void *)0x0;

          auStack_70[0] = 1;

          for (; iVar1 != *(int *)(param_1 + 0x714); iVar1 = iVar1 + 0x24) {

            if (((*(int *)(iVar1 + 4) == unaff_EDI) && (*(int *)(iVar1 + 8) == unaff_ESI)) &&

               (*(int *)(iVar1 + 0xc) == unaff_EBX)) {

              iStack_20 = (uint)iStack_20._1_3_ << 8;

              goto LAB_00735b2c;

            }

          }

          FUN_00735630(auStack_70,0);

          FUN_00465c40();

          iStack_20 = (uint)iStack_20._1_3_ << 8;

          if (pvStack_58 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete(pvStack_58);

          }

LAB_00735b2c:

          pvStack_58 = (void *)0x0;

          uStack_54 = 0;

          uStack_50 = 0;

        }

        uVar7 = uVar7 + 1;

        puVar6 = puVar5;

      } while (uVar7 < uVar3);

    }

    puVar5 = puVar5 + 1;

    if (0xa24457 < (int)puVar5) {

      iVar1 = (**(code **)(**(int **)(param_1 + 0x48) + 0x38))

                        (*(int **)(param_1 + 0x48),*(uint32_t /* width from decompiler */ *)(param_1 + 0x4c),1,param_1 + 0x4ac

                        );

      if (iVar1 < 0) {

        uVar2 = FUN_006b7a5a(iVar1,"No HAL Rasterization Device Available.");

        uVar2 = FUN_006a5dac(iVar1,uVar2);

        uVar2 = FUN_0076cec0(&uStack_30,"%s - %s\r\n%s",uVar2);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxAdapter.cpp",0xa3,3,uVar2)

        ;

        iVar1 = (**(code **)(**(int **)(param_1 + 0x48) + 0x38))

                          (*(int **)(param_1 + 0x48),*(uint32_t /* width from decompiler */ *)(param_1 + 0x4c),2,

                           param_1 + 0x4ac);

        if (iVar1 < 0) {

          uVar2 = FUN_006b7a5a(iVar1,"No Reference Rasterization Device Available.");

          uVar2 = FUN_006a5dac(iVar1,uVar2);

          uVar2 = FUN_0076cec0(&uStack_30,"%s - %s\r\n%s",uVar2);

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxAdapter.cpp",0xa7,3,

                         uVar2);

          if (pvStack_4c == (void *)0x0) {

            ExceptionList = pvStack_40;

            return 0xffffffff;

          }

                    /* WARNING: Subroutine does not return */

          operator_delete(pvStack_4c);

        }

      }

      if (pvStack_44 == (void *)0x0) {

        ExceptionList = pvStack_38;

        return 0;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete(pvStack_44);

    }

  } while( true );

}
