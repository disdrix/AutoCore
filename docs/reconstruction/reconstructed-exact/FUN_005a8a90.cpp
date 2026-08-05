// =============================================================================
// FUN_005a8a90
// -----------------------------------------------------------------------------
// Stable ID: aa_005a8a90
// Address:   0x005a8a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a8a90 @ 0x005a8a90
// Stable ID: aa_005a8a90
// Embedded strings (evidence for future rename):
//   - "CVOGVehicle::UpdateWaterFX"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×15, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_004b7550×4, FUN_004b8dc0×3, SQRT×3, FUN_004e88e0×2, FUN_005a6e00×2, ABS, FUN_005a72d0, FUN_005a74f0.
//  - Strings: "CVOGVehicle::UpdateWaterFX".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_005a8a90(int param_1,int param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  bool bVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  float *pfVar8;

  float *pfVar9;

  uint uVar10;

  int iVar11;

  uint32_t /* width from decompiler */ uVar12;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  float fStack_54;

  float fStack_50;

  float fStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float afStack_30 [3];

  uint8_t auStack_24 [12];

  uint8_t auStack_18 [12];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a643e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CVOGVehicle::UpdateWaterFX");

  uVar10 = 0;

  local_4 = 0;

  if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +

               0x4ce) == '\x04') {

    uVar10 = (int)*(char *)(param_1 + 0xb0) - 2;

    uVar10 = (0 < (int)uVar10) - 1 & uVar10;

  }

  iVar5 = FUN_005a72d0(uVar10,(int)*(char *)(param_1 + 0xb0));

  if ((iVar5 != -1) && ((int)uVar10 < (int)*(char *)(param_1 + 0xb0))) {

    iVar5 = uVar10 * 0xc0;

    do {

      iVar11 = *(int *)(param_2 + 0x80) + iVar5;

      pfVar9 = (float *)(iVar11 + 0x20);

      if (((*(float *)(iVar11 + 0x20) == 0.0) && (*(float *)(iVar11 + 0x24) == 0.0)) &&

         (*(float *)(iVar11 + 0x28) == 0.0)) {

        bVar4 = true;

      }

      else {

        bVar4 = false;

      }

      fVar1 = *(float *)(iVar11 + 0x28) - *(float *)(DAT_00b04c70 + 0x230);

      fVar3 = *(float *)(iVar11 + 0x24) - *(float *)(DAT_00b04c70 + 0x22c);

      fVar2 = *pfVar9 - *(float *)(DAT_00b04c70 + 0x228);

      if ((bVar4) || (_DAT_009d82f4 < SQRT(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2))) {

        if (*(int *)(*(int *)(param_1 + 0x134) + uVar10 * 4) != 0) {

          FUN_004b8dc0(0,0);

        }

        if (*(int *)(*(int *)(param_1 + 0x144) + uVar10 * 4) != 0) {

          uVar12 = 0;

          local_6c = 0;

          goto LAB_005a8e68;

        }

      }

      else {

        iVar6 = FUN_005a74f0(uVar10);

        local_70 = 0;

        local_6c = 0;

        if (iVar6 != -1) {

          if (ABS(*(float *)(iVar11 + 0x8c)) <= DAT_00aaa688) {

            local_70 = 0;

          }

          else {

            local_70 = 1;

            piVar7 = (int *)FUN_005a6e00(uVar10);

            iVar6 = (**(code **)(*piVar7 + 0xc))();

            pfVar8 = (float *)FUN_004e88e0(auStack_24,pfVar9);

            fStack_4c = pfVar8[2] - *(float *)(iVar6 + 0x98);

            fStack_50 = pfVar8[1] - *(float *)(iVar6 + 0x94);

            fStack_54 = *pfVar8 - *(float *)(iVar6 + 0x90);

            if (*(int *)(*(int *)(param_1 + 0x134) + uVar10 * 4) != 0) {

              FUN_004b7550(&fStack_54,1);

            }

            uStack_48 = *(uint32_t /* width from decompiler */ *)(iVar11 + 0x8c);

            uStack_44 = 0;

            uStack_40 = 0;

            if (*(int *)(*(int *)(param_1 + 0x134) + uVar10 * 4) != 0) {

              FUN_004b7550(&uStack_48,2);

            }

          }

          if ((param_3 == 0) ||

             (iVar11 = *(int *)(param_3 + 0x3c),

             SQRT(*(float *)(iVar11 + 0x40) * *(float *)(iVar11 + 0x40) +

                  *(float *)(iVar11 + 0x44) * *(float *)(iVar11 + 0x44) +

                  *(float *)(iVar11 + 0x48) * *(float *)(iVar11 + 0x48)) <= DAT_00aaa688)) {

            local_6c = 0;

          }

          else {

            local_6c = 1;

            piVar7 = (int *)FUN_005a6e00(uVar10);

            iVar11 = (**(code **)(*piVar7 + 0xc))();

            pfVar9 = (float *)FUN_004e88e0(auStack_18,pfVar9);

            fStack_34 = pfVar9[2] - *(float *)(iVar11 + 0x98);

            fStack_38 = pfVar9[1] - *(float *)(iVar11 + 0x94);

            fStack_3c = *pfVar9 - *(float *)(iVar11 + 0x90);

            if (*(int *)(*(int *)(param_1 + 0x144) + uVar10 * 4) != 0) {

              FUN_004b7550(&fStack_3c,1);

            }

            iVar11 = *(int *)(param_3 + 0x3c);

            afStack_30[0] =

                 SQRT(*(float *)(iVar11 + 0x40) * *(float *)(iVar11 + 0x40) +

                      *(float *)(iVar11 + 0x44) * *(float *)(iVar11 + 0x44) +

                      *(float *)(iVar11 + 0x48) * *(float *)(iVar11 + 0x48));

            afStack_30[1] = 0.0;

            afStack_30[2] = 0.0;

            if (*(int *)(*(int *)(param_1 + 0x144) + uVar10 * 4) != 0) {

              FUN_004b7550(afStack_30,2);

            }

          }

        }

        if (*(int *)(*(int *)(param_1 + 0x134) + uVar10 * 4) != 0) {

          FUN_004b8dc0(local_70,1);

        }

        if (*(int *)(*(int *)(param_1 + 0x144) + uVar10 * 4) != 0) {

          uVar12 = 1;

LAB_005a8e68:

          FUN_004b8dc0(local_6c,uVar12);

        }

      }

      uVar10 = uVar10 + 1;

      iVar5 = iVar5 + 0xc0;

    } while ((int)uVar10 < (int)*(char *)(param_1 + 0xb0));

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
