// =============================================================================
// Gfx_NDParticleFluid
// -----------------------------------------------------------------------------
// Stable ID: aa_004c1cb0
// Address:   0x004c1cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Gfx_NDParticleFluid for FUN_004c1cb0 @ 0x004c1cb0
// Stable ID: aa_004c1cb0
// Embedded strings (evidence for future rename):
//   - "Invalid arg to CreateFluidParticles %u"
//   - "NDParticleFluid.fx"
//   - "Particles.dds"
//   - "ParticleTexture"
//   - "NormalMapTexture"
//   - "ReflectionSurface"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: if×11, return×3, for×3.
//  - Notable callees: FUN_007a4480×4, FUN_00970140×3, FUN_005b3400×2, FUN_00989e00×2, CONCAT31, FUN_00404d80, FUN_004148e0, FUN_00414c20.
//  - Strings: "Invalid arg to CreateFluidParticles %u"; "NDParticleFluid.fx"; "Particles.dds"; "ParticleTexture".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "NDParticleFluid.fx"
 * Domain alias of FUN_004c1cb0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Gfx_NDParticleFluid(int param_1,int param_2)



{

  uint *puVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  void *local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint8_t auStack_24 [4];

  void *pvStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1b4a;

  local_c = ExceptionList;

  iVar4 = param_2 * 4;

  ExceptionList = &local_c;

  *(int *)(param_1 + 0xbc) = param_2;

  *(int *)(param_1 + 0xb8) = iVar4;

  if (iVar4 == 0) {

    FUN_007a4480(1,"Invalid arg to CreateFluidParticles %u",0);

    ExceptionList = local_c;

    return;

  }

  pvVar2 = operator_new__(param_2 * 0x70);

  local_4 = 0;

  local_40 = pvVar2;

  if (pvVar2 == (void *)0x0) {

    pvVar2 = (void *)0x0;

  }

  else {

    FUN_00404d80(pvVar2,0x1c,iVar4,FUN_005edf20);

  }

  local_4 = 0xffffffff;

  *(void **)(param_1 + 0xb4) = pvVar2;

  local_40 = operator_new(0x14c);

  local_4 = 1;

  if (local_40 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00764030();

  }

  local_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = uVar3;

  FUN_007638d0(1);

  local_3c = DAT_00a1401c;

  local_38 = DAT_00a1401c;

  local_34 = DAT_00a1401c;

  puVar7 = &local_3c;

  puVar6 = &local_30;

  local_30 = DAT_00aaab38;

  local_2c = DAT_00aaab38;

  local_28 = DAT_00aaab38;

  (**(code **)(**(int **)(param_1 + 0xac) + 0x4c))(puVar6,puVar7);

  FUN_0074b8f0(puVar6,puVar7);

  local_40 = operator_new(0xc4);

  local_4 = 2;

  if (local_40 == (void *)0x0) {

    uVar3 = 0;

  }

  else {

    uVar3 = FUN_00748960();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = uVar3;

  local_4 = 0xffffffff;

  FUN_00989e00(&local_40,"NDParticleFluid.fx");

  FUN_009701d0(&local_40);

  FUN_0096ef70();

  local_4 = 3;

  FUN_00989e00(&local_40,"Particles.dds");

  FUN_0096f3e0(&local_40,0);

  FUN_00970140("ParticleTexture",param_2);

  if (*(int *)(param_1 + 0x94) != 0) {

    FUN_00970140("NormalMapTexture",*(int *)(param_1 + 0x94));

  }

  if (((*(int *)(param_1 + 0xa8) != 0) && (*(int *)(*(int *)(param_1 + 0xa8) + 0xc4) != 0)) &&

     (iVar4 = FUN_005b3400(), iVar4 != 0)) {

    uVar3 = FUN_005b3400();

    FUN_00970140("ReflectionSurface",uVar3);

  }

  FUN_004148e0(param_1 + 0x8c);

  puVar1 = (uint *)(*(int *)(param_1 + 0xb0) + 0xbc);

  *puVar1 = *puVar1 | 1;

  pvStack_20 = (void *)0x0;

  uStack_1c = 0;

  uStack_18 = 0;

  local_4._0_1_ = 4;

  uStack_14 = 0;

  uStack_10 = 0;

  FUN_007478c0(0x1c2);

  local_4._0_1_ = 5;

  iVar4 = FUN_00414c20(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8),auStack_24,3,0);

  local_4 = CONCAT31(local_4._1_3_,3);

  uStack_14 = 0;

  uStack_10 = 0;

  if (pvStack_20 == (void *)0x0) {

    pvStack_20 = (void *)0x0;

    uStack_1c = 0;

    uStack_18 = 0;

    if (iVar4 < 0) {

      FUN_007a4480(1,"Unable to allocated %u verts for fluid particles",

                   *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc));

    }

    else {

      iVar4 = *(int *)(param_1 + 0xb0);

      iVar5 = FUN_0044b9c0(*(int *)(param_1 + 0xbc) * 6,2,0,0);

      if (iVar5 < 0) {

        FUN_007a4480(1,"Unable to allocated %u indices for fluid particles",

                     *(int *)(param_1 + 0xbc) * 6);

      }

      else {

        iVar5 = *(int *)(iVar4 + 0xc);

        if ((*(int *)(iVar5 + 0x10) == 0) ||

           (iVar5 = FUN_00743be0(*(uint32_t /* width from decompiler */ *)(iVar5 + 0x18),*(uint32_t /* width from decompiler */ *)(iVar5 + 0x1c),0x800),

           iVar5 == 0)) {

          FUN_007a4480(1,"Unable to lock %u indices for fluid particles",

                       *(int *)(param_1 + 0xbc) * 6);

        }

        else {

          FUN_004c05d0(iVar5);

          if (*(int *)(*(int *)(iVar4 + 0xc) + 0x10) != 0) {

            FUN_00743ba0();

          }

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb0) + 0xa8) = 0;

          *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb0) + 0xac) = 5;

          puVar1 = (uint *)(*(int *)(param_1 + 0xb0) + 0xbc);

          *puVar1 = *puVar1 & 0xfffffffe;

          FUN_007647c0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb0));

        }

      }

    }

    local_4 = 0xffffffff;

    FUN_0096efd0();

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvStack_20);

}
