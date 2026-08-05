// =============================================================================
// FUN_008e9320
// -----------------------------------------------------------------------------
// Stable ID: aa_008e9320
// Address:   0x008e9320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e9320 @ 0x008e9320
// Stable ID: aa_008e9320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: if×12, do×1, while×1, return×1.
//  - Notable callees: CONCAT13×3, CONCAT11×2, CONCAT21×2, FUN_004c77b0, FUN_00574760, FUN_006a3db0, FUN_008e9320.
//  - Return sites: 1.

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

void FUN_008e9320(int param_1)



{

  int iVar1;

  uint8_t uVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint unaff_EBX;

  uint unaff_ESI;

  int *piVar7;

  bool bVar8;

  float fVar9;

  uint32_t /* width from decompiler */ uStack_20;

  uint8_t local_1c;

  uint8_t local_1b;

  uint8_t local_1a;

  uint8_t local_19;

  int *local_c;

  int local_8;

  float fStack_4;

  

  local_c = (int *)(param_1 + 0x5b8);

  local_1a = 0xff;

  local_1b = 0xff;

  local_1c = 0xff;

  local_19 = 0xff;

  local_8 = 0;

  piVar7 = (int *)(param_1 + 0x608);

  do {

    iVar5 = local_8;

    iVar1 = *(int *)(*local_c + 0x504);

    if (iVar1 != 0) {

      if (*(int *)(param_1 + 0x544) == 0) {

        bVar8 = false;

      }

      else {

        iVar4 = FUN_00574760(local_8);

        bVar8 = iVar4 != 0;

      }

      if (*piVar7 != 0) {

        iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1ac))();

        if ((0 < iVar4) || ((bVar8 && (*(char *)(DAT_00d1b644 + 0xf5) != '\0')))) {

          if ((bVar8) && (*(char *)(DAT_00d1b644 + 0xf5) != '\0')) {

            uStack_20 = g_flOne;

          }

          else {

            iVar5 = *(int *)(*(int *)(iVar1 + 4) + 4);

            iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x1b0))()

            ;

            fStack_4 = (float)iVar4;

            iVar5 = (**(code **)(*(int *)(iVar5 + 4 + iVar1) + 0x1ac))();

            uStack_20 = fStack_4 / (float)iVar5;

          }

          fVar9 = uStack_20;

          (**(code **)(*(int *)*piVar7 + 0x3ac))(uStack_20);

          FUN_004c77b0(&local_1c,fVar9);

          (**(code **)(*(int *)*piVar7 + 0x15c))(1,&local_1c);

          uStack_20._0_3_ =

               CONCAT21(CONCAT11((byte)(unaff_EBX >> 0x10) >> 3,(byte)(unaff_EBX >> 8) >> 3),

                        (char)(unaff_EBX >> 3)) & 0xffff1f;

          uStack_20 = (float)CONCAT13(0xff,(uint3)uStack_20);

          (**(code **)(*(int *)*piVar7 + 0x15c))(0,&uStack_20);

          unaff_EBX = CONCAT13(0xff,CONCAT21(CONCAT11((char)((ulonglong)

                                                             ((longlong)

                                                              (int)(unaff_ESI >> 0x10 & 0xff) *

                                                             0x55555556) >> 0x20),

                                                      (char)((ulonglong)

                                                             ((longlong)(int)(unaff_ESI >> 8 & 0xff)

                                                             * 0x55555556) >> 0x20)),

                                             (char)((ulonglong)

                                                    ((longlong)(int)(unaff_ESI & 0xff) * 0x55555556)

                                                   >> 0x20)));

          (**(code **)(*(int *)*piVar7 + 0x15c))(2,&stack0xffffffdc);

          (**(code **)(*(int *)*piVar7 + 0x34c))();

          iVar5 = local_8;

        }

        (**(code **)(*(int *)*piVar7 + 0x34c))();

      }

      if (piVar7[4] != 0) {

        if ((0 < *(short *)(iVar1 + 0x12e)) || ((bVar8 && (*(char *)(DAT_00d1b644 + 0xf5) != '\0')))

           ) {

          if ((!bVar8) || (uStack_20 = g_flOne, *(char *)(DAT_00d1b644 + 0xf5) == '\0')) {

            uStack_20 = (float)(int)*(short *)(iVar1 + 300) / (float)(int)*(short *)(iVar1 + 0x12e);

          }

          (**(code **)(*(int *)piVar7[4] + 0x3ac))(uStack_20);

        }

        (**(code **)(*(int *)piVar7[4] + 0x34c))();

      }

      if (piVar7[8] != 0) {

        if (((*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) + 0x3c)

                       + 0x532) == '\0') && (iVar1 = *(int *)(iVar1 + 0x250), iVar1 != 0)) &&

           (0 < *(int *)(iVar1 + 0x148))) {

          uStack_20 = (float)*(int *)(iVar1 + 0x144) / (float)*(int *)(iVar1 + 0x148);

          fVar9 = g_flOne;

          if ((g_flOne < uStack_20) || (fVar9 = 0.0, uStack_20 < 0.0)) {

            uStack_20 = fVar9;

          }

          puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)piVar7[8] + 0x164))(0);

          uStack_20 = (float)*puVar6;

          uVar2 = FUN_006a3db0();

          uStack_20 = (float)CONCAT13(uVar2,(uint3)uStack_20);

          (**(code **)(*(int *)piVar7[8] + 0x15c))(0,&uStack_20);

          (**(code **)(*(int *)piVar7[8] + 0xcc))(1);

        }

        else {

          (**(code **)(*(int *)piVar7[8] + 0xcc))(0);

        }

        (**(code **)(*(int *)piVar7[8] + 0x34c))();

      }

      cVar3 = (**(code **)(*(int *)piVar7[-0x14] + 0xd0))();

      if (cVar3 != '\0') {

        (**(code **)(*(int *)piVar7[-0x14] + 0x444))();

      }

      piVar7 = piVar7 + 1;

    }

    local_c = local_c + 1;

    local_8 = iVar5 + 1;

  } while (local_8 < 4);

  return;

}
