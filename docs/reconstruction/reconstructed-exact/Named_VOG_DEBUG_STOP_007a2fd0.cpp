// READABILITY (auto CF):
//  - Body size: ~443 non-empty decompiler lines.
//  - Control keywords: if×30, return×2.
//  - Notable callees: CONCAT31×7, FUN_00414b60×7, FUN_00414bc0×7, FUN_00414c20×7, FUN_00748960×7, FUN_0074b8f0×7, FUN_00764030×7, FUN_007647c0×7.
//  - Strings: "VOG_DEBUG_STOP"; "NDDiffAlphaParticle.fx"; "Particles.dds"; "ParticleTexture".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_007a2fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a2fd0
// Address:   0x007a2fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_VOG_DEBUG_STOP_007a2fd0(int param_1)



{

  uint *puVar1;

  uint uVar2;

  void *pvVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint8_t auStack_50 [4];

  void *local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b289f;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (*(void **)(unaff_ESI + 0x16c) != (void *)0x0) {

    ExceptionList = &local_c;

    operator_delete__(*(void **)(unaff_ESI + 0x16c));

  }

  iVar7 = param_1 * 6;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x16c) = 0;

  *(int *)(unaff_ESI + 0x164) = iVar7;

  if (iVar7 < 1) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    ExceptionList = local_c;

    return;

  }

  uVar2 = param_1 * 0xa8;

  pvVar3 = operator_new__(uVar2);

  *(void **)(unaff_ESI + 0x16c) = pvVar3;

  local_4c = operator_new(0x14c);

  local_4 = 0;

  if (local_4c == (void *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = FUN_00764030();

  }

  local_4 = 0xffffffff;

  *(int *)(unaff_ESI + 0x170) = iVar4;

  FUN_0096b150(iVar4 + 0x98,1);

  puVar6 = &local_48;

  puVar8 = &local_3c;

  local_48 = DAT_00a1401c;

  local_44 = DAT_00a1401c;

  local_40 = DAT_00a1401c;

  local_3c = DAT_00aaab38;

  local_38 = DAT_00aaab38;

  local_34 = DAT_00aaab38;

  (**(code **)(**(int **)(unaff_ESI + 0x170) + 0x4c))(puVar8,puVar6);

  FUN_0074b8f0(puVar8,puVar6);

  local_4c = operator_new(0xc4);

  local_4 = 1;

  if (local_4c == (void *)0x0) {

    uVar5 = 0;

  }

  else {

    uVar5 = FUN_00748960();

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x174) = uVar5;

  FUN_00989e00(auStack_50,"NDDiffAlphaParticle.fx");

  FUN_009701d0(auStack_50);

  local_4 = 2;

  FUN_00989e00(&local_4c,"Particles.dds");

  FUN_0096f3e0(&local_4c,0);

  FUN_00970140("ParticleTexture",0);

  puVar1 = (uint *)(*(int *)(unaff_ESI + 0x174) + 0xbc);

  *puVar1 = *puVar1 | 1;

  uVar5 = FUN_00414bc0(0x10142);

  local_4._0_1_ = 3;

  iVar4 = FUN_00414c20(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x164),uVar5,3,0);

  local_4 = CONCAT31(local_4._1_3_,2);

  FUN_00414b60();

  if (-1 < iVar4) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x174) + 0xa8) = 0;

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x174) + 0xac) = 4;

    puVar1 = (uint *)(*(int *)(unaff_ESI + 0x174) + 0xbc);

    *puVar1 = *puVar1 & 0xfffffffe;

    FUN_007647c0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x174));

    if (*(void **)(unaff_ESI + 0x180) != (void *)0x0) {

      operator_delete__(*(void **)(unaff_ESI + 0x180));

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x180) = 0;

    *(int *)(unaff_ESI + 0x178) = iVar7;

    pvVar3 = operator_new__(uVar2);

    *(void **)(unaff_ESI + 0x180) = pvVar3;

    local_4c = operator_new(0x14c);

    local_4._0_1_ = 4;

    if (local_4c == (void *)0x0) {

      iVar4 = 0;

    }

    else {

      iVar4 = FUN_00764030();

    }

    local_4._0_1_ = 2;

    *(int *)(unaff_ESI + 0x184) = iVar4;

    FUN_0096b150(iVar4 + 0x98,1);

    puVar6 = &local_3c;

    puVar8 = &local_48;

    local_3c = DAT_00a1401c;

    local_38 = DAT_00a1401c;

    local_34 = DAT_00a1401c;

    local_48 = DAT_00aaab38;

    local_44 = DAT_00aaab38;

    local_40 = DAT_00aaab38;

    (**(code **)(**(int **)(unaff_ESI + 0x184) + 0x4c))(puVar8,puVar6);

    FUN_0074b8f0(puVar8,puVar6);

    local_4c = operator_new(0xc4);

    local_4._0_1_ = 5;

    if (local_4c == (void *)0x0) {

      uVar5 = 0;

    }

    else {

      uVar5 = FUN_00748960();

    }

    local_4._0_1_ = 2;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x188) = uVar5;

    FUN_00989e00(&local_4c,"NDDiffAlphaParticleBright.fx");

    FUN_009701d0(&local_4c);

    FUN_00970140("ParticleTexture",0);

    puVar1 = (uint *)(*(int *)(unaff_ESI + 0x188) + 0xbc);

    *puVar1 = *puVar1 | 1;

    uVar5 = FUN_00414bc0(0x10142);

    local_4._0_1_ = 6;

    iVar4 = FUN_00414c20(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x178),uVar5,3,0);

    local_4 = CONCAT31(local_4._1_3_,2);

    FUN_00414b60();

    if (-1 < iVar4) {

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x188) + 0xa8) = 0;

      *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x188) + 0xac) = 4;

      puVar1 = (uint *)(*(int *)(unaff_ESI + 0x188) + 0xbc);

      *puVar1 = *puVar1 & 0xfffffffe;

      FUN_007647c0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x188));

      if (*(void **)(unaff_ESI + 0x194) != (void *)0x0) {

        operator_delete__(*(void **)(unaff_ESI + 0x194));

      }

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x194) = 0;

      *(int *)(unaff_ESI + 0x18c) = iVar7;

      pvVar3 = operator_new__(uVar2);

      *(void **)(unaff_ESI + 0x194) = pvVar3;

      local_4c = operator_new(0x14c);

      local_4._0_1_ = 7;

      if (local_4c == (void *)0x0) {

        uVar5 = 0;

      }

      else {

        uVar5 = FUN_00764030();

      }

      local_4._0_1_ = 2;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x198) = uVar5;

      FUN_007638d0(1);

      puVar6 = &local_3c;

      puVar8 = &local_48;

      local_3c = DAT_00a1401c;

      local_38 = DAT_00a1401c;

      local_34 = DAT_00a1401c;

      local_48 = DAT_00aaab38;

      local_44 = DAT_00aaab38;

      local_40 = DAT_00aaab38;

      (**(code **)(**(int **)(unaff_ESI + 0x198) + 0x4c))(puVar8,puVar6);

      FUN_0074b8f0(puVar8,puVar6);

      local_4c = operator_new(0xc4);

      local_4._0_1_ = 8;

      if (local_4c == (void *)0x0) {

        uVar5 = 0;

      }

      else {

        uVar5 = FUN_00748960();

      }

      local_4._0_1_ = 2;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x19c) = uVar5;

      uVar5 = FUN_00404ba0("NDDiffAlphaParticleTerrain.fx");

      FUN_009701d0(uVar5);

      FUN_00970140("ParticleTexture",0);

      puVar1 = (uint *)(*(int *)(unaff_ESI + 0x19c) + 0xbc);

      *puVar1 = *puVar1 | 1;

      uVar5 = FUN_00414bc0(0x10142);

      local_4._0_1_ = 9;

      iVar4 = FUN_00414c20(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18c),uVar5,3,0);

      local_4 = CONCAT31(local_4._1_3_,2);

      FUN_00414b60();

      if (-1 < iVar4) {

        *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x19c) + 0xa8) = 0;

        *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x19c) + 0xac) = 4;

        puVar1 = (uint *)(*(int *)(unaff_ESI + 0x19c) + 0xbc);

        *puVar1 = *puVar1 & 0xfffffffe;

        FUN_007647c0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x19c));

        if (*(void **)(unaff_ESI + 0x1bc) != (void *)0x0) {

          operator_delete__(*(void **)(unaff_ESI + 0x1bc));

        }

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1bc) = 0;

        *(int *)(unaff_ESI + 0x1b4) = iVar7;

        pvVar3 = operator_new__(uVar2);

        *(void **)(unaff_ESI + 0x1bc) = pvVar3;

        local_4c = operator_new(0x14c);

        local_4._0_1_ = 10;

        if (local_4c == (void *)0x0) {

          uVar5 = 0;

        }

        else {

          uVar5 = FUN_00764030();

        }

        local_4._0_1_ = 2;

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c0) = uVar5;

        FUN_007638d0(1);

        puVar6 = &local_3c;

        puVar8 = &local_48;

        local_3c = DAT_00a1401c;

        local_38 = DAT_00a1401c;

        local_34 = DAT_00a1401c;

        local_48 = DAT_00aaab38;

        local_44 = DAT_00aaab38;

        local_40 = DAT_00aaab38;

        (**(code **)(**(int **)(unaff_ESI + 0x1c0) + 0x4c))(puVar8,puVar6);

        FUN_0074b8f0(puVar8,puVar6);

        local_4c = operator_new(0xc4);

        local_4._0_1_ = 0xb;

        if (local_4c == (void *)0x0) {

          uVar5 = 0;

        }

        else {

          uVar5 = FUN_00748960();

        }

        local_4._0_1_ = 2;

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c4) = uVar5;

        uVar5 = FUN_00404ba0("NDDiffAlphaParticleSkybox.fx");

        FUN_009701d0(uVar5);

        FUN_00970140("ParticleTexture",0);

        puVar1 = (uint *)(*(int *)(unaff_ESI + 0x1c4) + 0xbc);

        *puVar1 = *puVar1 | 1;

        uVar5 = FUN_00414bc0(0x10142);

        local_4._0_1_ = 0xc;

        iVar4 = FUN_00414c20(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1b4),uVar5,3,0);

        local_4 = CONCAT31(local_4._1_3_,2);

        FUN_00414b60();

        if (-1 < iVar4) {

          *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x1c4) + 0xa8) = 0;

          *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x1c4) + 0xac) = 4;

          puVar1 = (uint *)(*(int *)(unaff_ESI + 0x1c4) + 0xbc);

          *puVar1 = *puVar1 & 0xfffffffe;

          FUN_007647c0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c4));

          if (*(void **)(unaff_ESI + 0x1a8) != (void *)0x0) {

            operator_delete__(*(void **)(unaff_ESI + 0x1a8));

          }

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1a8) = 0;

          *(int *)(unaff_ESI + 0x1a0) = iVar7;

          pvVar3 = operator_new__(uVar2);

          *(void **)(unaff_ESI + 0x1a8) = pvVar3;

          local_4c = operator_new(0x14c);

          local_4._0_1_ = 0xd;

          if (local_4c == (void *)0x0) {

            uVar5 = 0;

          }

          else {

            uVar5 = FUN_00764030();

          }

          local_4._0_1_ = 2;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1ac) = uVar5;

          FUN_007638d0(1);

          puVar6 = &local_3c;

          puVar8 = &local_48;

          local_3c = DAT_00a1401c;

          local_38 = DAT_00a1401c;

          local_34 = DAT_00a1401c;

          local_48 = DAT_00aaab38;

          local_44 = DAT_00aaab38;

          local_40 = DAT_00aaab38;

          (**(code **)(**(int **)(unaff_ESI + 0x1ac) + 0x4c))(puVar8,puVar6);

          FUN_0074b8f0(puVar8,puVar6);

          local_4c = operator_new(0xc4);

          local_4._0_1_ = 0xe;

          if (local_4c == (void *)0x0) {

            uVar5 = 0;

          }

          else {

            uVar5 = FUN_00748960();

          }

          local_4._0_1_ = 2;

          *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1b0) = uVar5;

          uVar5 = FUN_00404ba0("NDDiffAlphaParticleBrightSkybox.fx");

          FUN_009701d0(uVar5);

          FUN_00970140("ParticleTexture",0);

          puVar1 = (uint *)(*(int *)(unaff_ESI + 0x1b0) + 0xbc);

          *puVar1 = *puVar1 | 1;

          uVar5 = FUN_00414bc0(0x10142);

          local_4._0_1_ = 0xf;

          iVar4 = FUN_00414c20(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1a0),uVar5,3,0);

          local_4 = CONCAT31(local_4._1_3_,2);

          FUN_00414b60();

          if (-1 < iVar4) {

            *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x1b0) + 0xa8) = 0;

            *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x1b0) + 0xac) = 4;

            puVar1 = (uint *)(*(int *)(unaff_ESI + 0x1b0) + 0xbc);

            *puVar1 = *puVar1 & 0xfffffffe;

            FUN_007647c0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1b0));

            if (*(void **)(unaff_ESI + 0x1ec) != (void *)0x0) {

              operator_delete__(*(void **)(unaff_ESI + 0x1ec));

            }

            *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1ec) = 0;

            *(int *)(unaff_ESI + 0x1e4) = iVar7;

            pvVar3 = operator_new__(uVar2);

            *(void **)(unaff_ESI + 0x1ec) = pvVar3;

            local_4c = operator_new(0x14c);

            local_4._0_1_ = 0x10;

            if (local_4c == (void *)0x0) {

              uVar5 = 0;

            }

            else {

              uVar5 = FUN_00764030();

            }

            local_4._0_1_ = 2;

            *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1f0) = uVar5;

            FUN_007638d0(1);

            puVar6 = &local_3c;

            puVar8 = &local_48;

            local_3c = DAT_00a1401c;

            local_38 = DAT_00a1401c;

            local_34 = DAT_00a1401c;

            local_48 = DAT_00aaab38;

            local_44 = DAT_00aaab38;

            local_40 = DAT_00aaab38;

            (**(code **)(**(int **)(unaff_ESI + 0x1f0) + 0x4c))(puVar8,puVar6);

            FUN_0074b8f0(puVar8,puVar6);

            local_4c = operator_new(0xc4);

            local_4._0_1_ = 0x11;

            if (local_4c == (void *)0x0) {

              uVar5 = 0;

            }

            else {

              uVar5 = FUN_00748960();

            }

            local_4._0_1_ = 2;

            *(uint32_t /* width from decompiler */ *)(unaff_ESI + 500) = uVar5;

            uVar5 = FUN_00404ba0("NDDiffAlphaParticleGlow.fx");

            FUN_009701d0(uVar5);

            FUN_00970140("ParticleTexture",0);

            puVar1 = (uint *)(*(int *)(unaff_ESI + 500) + 0xbc);

            *puVar1 = *puVar1 | 1;

            uVar5 = FUN_00414bc0(0x10142);

            local_4._0_1_ = 0x12;

            iVar4 = FUN_00414c20(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1e4),uVar5,3,0);

            local_4 = CONCAT31(local_4._1_3_,2);

            FUN_00414b60();

            if (-1 < iVar4) {

              *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 500) + 0xa8) = 0;

              *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 500) + 0xac) = 4;

              puVar1 = (uint *)(*(int *)(unaff_ESI + 500) + 0xbc);

              *puVar1 = *puVar1 & 0xfffffffe;

              FUN_007647c0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 500));

              if (*(void **)(unaff_ESI + 0x1d0) != (void *)0x0) {

                operator_delete__(*(void **)(unaff_ESI + 0x1d0));

              }

              *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1d0) = 0;

              *(int *)(unaff_ESI + 0x1c8) = iVar7;

              pvVar3 = operator_new__(uVar2);

              *(void **)(unaff_ESI + 0x1d0) = pvVar3;

              local_4c = operator_new(0x14c);

              local_4._0_1_ = 0x13;

              if (local_4c == (void *)0x0) {

                uVar5 = 0;

              }

              else {

                uVar5 = FUN_00764030();

              }

              local_4._0_1_ = 2;

              *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1d4) = uVar5;

              FUN_007638d0(1);

              puVar6 = &local_3c;

              puVar8 = &local_48;

              local_3c = DAT_00a1401c;

              local_38 = DAT_00a1401c;

              local_34 = DAT_00a1401c;

              local_48 = DAT_00aaab38;

              local_44 = DAT_00aaab38;

              local_40 = DAT_00aaab38;

              (**(code **)(**(int **)(unaff_ESI + 0x1d4) + 0x4c))(puVar8,puVar6);

              FUN_0074b8f0(puVar8,puVar6);

              local_4c = operator_new(0xc4);

              local_4._0_1_ = 0x14;

              if (local_4c == (void *)0x0) {

                uVar5 = 0;

              }

              else {

                uVar5 = FUN_00748960();

              }

              local_4._0_1_ = 2;

              *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1d8) = uVar5;

              puVar6 = operator_new(8);

              if (puVar6 == (uint32_t /* width from decompiler */ *)0x0) {

                puVar6 = (uint32_t /* width from decompiler */ *)0x0;

              }

              else {

                *puVar6 = 0;

                *(uint8_t *)(puVar6 + 1) = 0;

                *(uint8_t *)((int)puVar6 + 5) = 0;

                *(uint8_t *)((int)puVar6 + 6) = 0;

              }

              *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x1e0) = puVar6;

              uVar5 = FUN_00404ba0("NDParticleDistort.fx");

              FUN_009701d0(uVar5);

              uVar9 = 0;

              uVar5 = FUN_00404ba0("Particle_Distort.dds");

              FUN_0096f3e0(uVar5,uVar9);

              FUN_00970140("NormalMapTexture",0);

              FUN_004148e0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1e0));

              puVar1 = (uint *)(*(int *)(unaff_ESI + 0x1d8) + 0xbc);

              *puVar1 = *puVar1 | 1;

              uVar5 = FUN_00414bc0(0x10142);

              local_4._0_1_ = 0x15;

              iVar7 = FUN_00414c20(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c8),uVar5,3,0);

              local_4 = CONCAT31(local_4._1_3_,2);

              FUN_00414b60();

              if (-1 < iVar7) {

                *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x1d8) + 0xa8) = 0;

                *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x1d8) + 0xac) = 4;

                puVar1 = (uint *)(*(int *)(unaff_ESI + 0x1d8) + 0xbc);

                *puVar1 = *puVar1 & 0xfffffffe;

                FUN_007647c0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1d8));

              }

            }

          }

        }

      }

    }

  }

  local_4 = 0xffffffff;

  FUN_0096efd0();

  ExceptionList = local_c;

  return;

}
