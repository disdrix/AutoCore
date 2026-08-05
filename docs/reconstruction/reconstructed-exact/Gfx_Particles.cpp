// =============================================================================
// Gfx_Particles
// -----------------------------------------------------------------------------
// Stable ID: aa_0049a240
// Address:   0x0049a240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Gfx_Particles for FUN_0049a240 @ 0x0049a240
// Stable ID: aa_0049a240
// Embedded strings (evidence for future rename):
//   - "NDFluidMesh.fx"
//   - "Particles.dds"
//   - "DiffuseTexture"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~314 non-empty decompiler lines.
//  - Control keywords: if×39, return×17.
//  - Notable callees: ROUND×6, CONCAT44×3, FUN_00404d80×2, FUN_0040f520×2, FUN_0096efd0×2, CONCAT31, FUN_00404ba0, FUN_00414b60.
//  - Strings: "NDFluidMesh.fx"; "Particles.dds"; "DiffuseTexture".
//  - Return sites: 17.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Particles.dds"
 * Domain alias of FUN_0049a240 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __fastcall Gfx_Particles(int param_1)



{

  uint *puVar1;

  float fVar2;

  float fVar3;

  double dVar4;

  int iVar5;

  void *pvVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  float10 fVar9;

  float10 fVar10;

  uint32_t /* width from decompiler */ *puVar11;

  uint64_t *puVar12;

  uint64_t local_b0;

  uint32_t /* width from decompiler */ uStack_a8;

  uint32_t /* width from decompiler */ uStack_a4;

  float local_a0;

  uint local_9c;

  float local_98;

  uint32_t /* width from decompiler */ local_94;

  uint local_90;

  uint local_8c;

  int local_88;

  int local_84;

  int local_80;

  uint8_t local_7c;

  int local_78;

  void *local_74;

  int local_70;

  int local_6c;

  uint local_68;

  int local_64;

  void *local_60;

  int local_5c;

  uint local_58;

  int local_54;

  int local_50;

  int local_4c;

  uint32_t /* width from decompiler */ local_48;

  int local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a0f03;

  local_c = ExceptionList;

  if (*(char *)(param_1 + 0x178) == '\0') {

    return 1;

  }

  local_a0 = DAT_00aaa688;

  local_94 = DAT_00a0f298;

  local_70 = 0xc;

  local_6c = 0xc;

  local_7c = 1;

  local_98 = (float)DAT_00a10e78;

  local_9c = 1;

  local_90 = 0;

  local_8c = 0;

  local_80 = 0;

  local_78 = 0;

  local_74 = (void *)0x0;

  local_68 = 0;

  local_64 = 0;

  local_60 = (void *)0x0;

  local_58 = 0;

  local_54 = 0;

  local_50 = 0;

  local_4c = 0;

  local_48 = 0;

  local_44 = 0;

  local_40 = 0;

  local_3c = 0;

  local_5c = 4;

  local_38 = 0;

  local_34 = 0;

  iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x1c8) + 0x2c) + 0xe894) + 0xc0);

  local_88 = *(int *)(iVar5 + 0xdc);

  local_84 = *(int *)(iVar5 + 0xe0);

  ExceptionList = &local_c;

  local_80 = FUN_0043f660();

  local_a0 = DAT_00aefb38;

  local_94 = DAT_00aefb34;

  local_7c = 1;

  local_98 = DAT_00aefb30;

  fVar3 = (float)local_88;

  if (local_88 < 0) {

    fVar3 = fVar3 + _DAT_00aaa5dc;

  }

  fVar2 = (float)local_84;

  if (local_84 < 0) {

    fVar2 = fVar2 + _DAT_00aaa5dc;

  }

  iVar8 = ((int)ROUND(fVar2 * (g_flOne / DAT_00aefb38)) + 1) *

          ((int)ROUND(fVar3 * (g_flOne / DAT_00aefb38)) + 1);

  local_b0._0_4_ = (void *)iVar8;

  iVar5 = FUN_006a3db0();

  *(int *)(param_1 + 0x1b4) = iVar5;

  local_b0._0_4_ = operator_new__(iVar5 * 0xc);

  local_4 = 0;

  if ((void *)local_b0 == (void *)0x0) {

    pvVar6 = (void *)0x0;

  }

  else {

    FUN_00404d80((void *)local_b0,0xc,iVar5,FUN_005edf20);

    pvVar6 = (void *)local_b0;

  }

  iVar5 = *(int *)(param_1 + 0x1b4);

  local_4 = 0xffffffff;

  *(void **)(param_1 + 0x1ac) = pvVar6;

  local_b0._0_4_ = operator_new__(iVar5 * 0xc);

  local_4 = 1;

  if ((void *)local_b0 == (void *)0x0) {

    local_74 = (void *)0x0;

  }

  else {

    FUN_00404d80((void *)local_b0,0xc,iVar5,FUN_005edf20);

    local_74 = (void *)local_b0;

  }

  local_78 = *(int *)(param_1 + 0x1ac);

  *(void **)(param_1 + 0x1a8) = local_74;

  local_6c = 0xc;

  local_70 = 0xc;

  local_68 = *(uint *)(param_1 + 0x1b4);

  local_64 = param_1 + 0x1b0;

  local_4 = 0xffffffff;

  *(int *)(param_1 + 0x1c0) = iVar8 * 9;

  local_60 = operator_new__(iVar8 * 0x24);

  local_58 = *(uint *)(param_1 + 0x1c0);

  local_54 = param_1 + 0x1bc;

  *(void **)(param_1 + 0x1b8) = local_60;

  local_5c = 4;

  if (local_64 == 0) {

    if (local_78 != 0) {

      ExceptionList = local_c;

      return 0;

    }

    if (local_74 != (void *)0x0) {

      ExceptionList = local_c;

      return 0;

    }

  }

  else if ((local_78 == 0) && (local_74 == (void *)0x0)) {

    ExceptionList = local_c;

    return 0;

  }

  if (local_54 == 0) {

    if (local_60 != (void *)0x0) {

      ExceptionList = local_c;

      return 0;

    }

  }

  else if (local_60 == (void *)0x0) {

    ExceptionList = local_c;

    return 0;

  }

  if (local_44 == 0) {

    if (local_50 != 0) {

      ExceptionList = local_c;

      return 0;

    }

  }

  else if (local_50 == 0) {

    ExceptionList = local_c;

    return 0;

  }

  if (((((local_78 == 0) || (local_70 != 0)) && ((local_74 == (void *)0x0 || (local_6c != 0)))) &&

      ((((((local_50 == 0 || (local_4c != 0)) && (0.0 < local_a0)) &&

         ((local_a0 <= DAT_00a110d8 && (0.0 < local_98)))) && (local_9c != 0)) &&

       ((local_9c < 0xb && (local_90 < 0xb)))))) && (local_8c < 0xb)) {

    fVar3 = (float)local_88;

    if (local_88 < 0) {

      fVar3 = fVar3 + _DAT_00aaa5dc;

    }

    if (g_flZero < fVar3) {

      fVar2 = (float)local_84;

      if (local_84 < 0) {

        fVar2 = fVar2 + _DAT_00aaa5dc;

      }

      if ((g_flZero < fVar2) && (local_80 != 0)) {

        fVar9 = (float10)FUN_0040f520(fVar3 / local_a0);

        local_b0 = CONCAT44(local_b0._4_4_,(int)ROUND(fVar9));

        fVar3 = (float)local_84;

        if (local_84 < 0) {

          fVar3 = fVar3 + _DAT_00aaa5dc;

        }

        fVar10 = (float10)FUN_0040f520(fVar3 / local_a0);

        if (local_64 == 0) {

          if (local_78 != 0) {

            ExceptionList = local_c;

            return 0;

          }

          if (local_74 != (void *)0x0) {

            ExceptionList = local_c;

            return 0;

          }

        }

        else if ((local_78 == 0) && (local_74 == (void *)0x0)) {

          ExceptionList = local_c;

          return 0;

        }

        if (local_54 == 0) {

          if (local_60 != (void *)0x0) {

            ExceptionList = local_c;

            return 0;

          }

        }

        else if (local_60 == (void *)0x0) {

          ExceptionList = local_c;

          return 0;

        }

        if (local_44 == 0) {

          if (local_50 != 0) {

            ExceptionList = local_c;

            return 0;

          }

        }

        else if (local_50 == 0) {

          ExceptionList = local_c;

          return 0;

        }

        if ((((local_78 == 0) || (local_70 != 0)) && ((local_74 == (void *)0x0 || (local_6c != 0))))

           && (((local_60 == (void *)0x0 || (local_5c != 0)) && ((local_50 == 0 || (local_4c != 0)))

               ))) {

          iVar5 = ((int)ROUND(fVar10) + 1) * ((int)ROUND(fVar9) + 1);

          dVar4 = (double)iVar5;

          if (iVar5 < 0) {

            dVar4 = dVar4 + _DAT_00aaa728;

          }

          local_b0 = (longlong)ROUND(dVar4 * _DAT_009c7b98);

          if (((void *)local_b0 <= local_68) && ((uint)(iVar5 * 9) <= local_58)) {

            iVar5 = (**(code **)(**(int **)(param_1 + 0x18c) + 0x14))(&local_a0);

            *(int *)(param_1 + 400) = iVar5;

            if (iVar5 != 0) {

              pvVar6 = operator_new(0x14c);

              local_b0 = CONCAT44(local_b0._4_4_,pvVar6);

              local_4 = 2;

              if (pvVar6 == (void *)0x0) {

                uVar7 = 0;

              }

              else {

                uVar7 = FUN_00764030();

              }

              local_4 = 0xffffffff;

              *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = uVar7;

              FUN_007638d0(1);

              local_b0._0_4_ = (void *)DAT_00a1109c;

              local_b0._4_4_ = DAT_00a1109c;

              uStack_a8 = DAT_00a1109c;

              puVar12 = &local_b0;

              puVar11 = &uStack_30;

              uStack_30 = DAT_009c7bf8;

              uStack_2c = DAT_009c7bf8;

              uStack_28 = DAT_009c7bf8;

              (**(code **)(**(int **)(param_1 + 0x184) + 0x4c))(puVar11,puVar12);

              FUN_0074b8f0(puVar11,puVar12);

              pvVar6 = operator_new(0xc4);

              local_b0 = CONCAT44(local_b0._4_4_,pvVar6);

              local_4 = 3;

              if (pvVar6 == (void *)0x0) {

                uVar7 = 0;

              }

              else {

                uVar7 = FUN_00748960();

              }

              local_4 = 0xffffffff;

              *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = uVar7;

              if ((-1 < *(int *)(param_1 + 0x170)) && (*(int *)(param_1 + 0x170) < 4)) {

                uVar7 = FUN_00404ba0("NDFluidMesh.fx");

                FUN_009701d0(uVar7);

              }

              FUN_0096ef70();

              local_4 = 4;

              FUN_00989e00(&local_b0,"Particles.dds");

              FUN_0096f3e0(&local_b0,0);

              FUN_00970140("DiffuseTexture",uStack_a4);

              puVar1 = (uint *)(*(int *)(param_1 + 0x188) + 0xbc);

              *puVar1 = *puVar1 | 1;

              uVar7 = FUN_00414bc0(0x12);

              local_4._0_1_ = 5;

              iVar5 = FUN_00414c20(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1b4),uVar7,3,0);

              local_4 = CONCAT31(local_4._1_3_,4);

              FUN_00414b60();

              if ((-1 < iVar5) &&

                 (iVar5 = FUN_0044b9c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1c0),3,0,1), -1 < iVar5)) {

                *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x188) + 0xa8) = 0;

                *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x188) + 0xac) = 4;

                puVar1 = (uint *)(*(int *)(param_1 + 0x188) + 0xbc);

                *puVar1 = *puVar1 & 0xfffffffe;

                FUN_007647c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x188));

                local_4 = 0xffffffff;

                FUN_0096efd0();

                ExceptionList = local_c;

                return 1;

              }

              local_4 = 0xffffffff;

              FUN_0096efd0();

            }

          }

        }

      }

    }

  }

  ExceptionList = local_c;

  return 0;

}
