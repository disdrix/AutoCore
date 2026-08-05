// =============================================================================
// Gfx_NDParticleFluidBlendNormal_004c1a10
// -----------------------------------------------------------------------------
// Stable ID: aa_004c1a10
// Address:   0x004c1a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Gfx_NDParticleFluidBlendNormal_004c1a10 for FUN_004c1a10 @ 0x004c1a10
// Stable ID: aa_004c1a10
// Embedded strings (evidence for future rename):
//   - "NDParticleFluidBlendNormal.fx"
//   - "Particle_Fluid_bump.dds"
//   - "NormalMapTexture"
//   - "particle_fluid.dds"
//   - "DiffuseMapTexture2"
//   - "v2NormalMapExtents"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_00970140×6, FUN_00989e00×5, FUN_0096ef70×3, FUN_0096efd0×3, FUN_0096f3e0×3, FUN_005b3400×2, FUN_009701d0×2, CONCAT31.
//  - Strings: "NDParticleFluidBlendNormal.fx"; "Particle_Fluid_bump.dds"; "NormalMapTexture"; "particle_fluid.dds".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "NDParticleFluidBlendNormal.fx"
 * Domain alias of FUN_004c1a10 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Gfx_NDParticleFluidBlendNormal_004c1a10(int param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  void *pvVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint8_t local_1c [4];

  uint8_t local_18 [4];

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1b07;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00989e00(local_1c,"NDParticleFluidBlendNormal.fx");

  FUN_009701d0(local_1c);

  FUN_0096ef70();

  local_4 = 0;

  FUN_00989e00(local_1c,"Particle_Fluid_bump.dds");

  FUN_0096f3e0(local_1c,0);

  FUN_00970140("NormalMapTexture",local_20);

  FUN_0096ef70();

  local_4._0_1_ = 1;

  FUN_00989e00(local_1c,"particle_fluid.dds");

  FUN_0096f3e0(local_1c,0);

  FUN_00970140("DiffuseMapTexture2",local_24);

  local_14 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x9c) + 0x188);

  local_10 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x9c) + 0x18c);

  FUN_00493550("v2NormalMapExtents",&local_14);

  FUN_00989e00(local_1c,"NDParticleFluid.fx");

  FUN_009701d0(local_1c);

  FUN_0096ef70();

  local_4 = CONCAT31(local_4._1_3_,2);

  FUN_00989e00(local_18,"Particles.dds");

  FUN_0096f3e0(local_18,0);

  FUN_00970140("ParticleTexture",local_28);

  if (*(int *)(param_1 + 0x98) != 0) {

    FUN_00970140("NormalMapTexture",*(int *)(param_1 + 0x98));

  }

  if ((*(int *)(param_1 + 0xa8) != 0) && (*(int *)(*(int *)(param_1 + 0xa8) + 0xc4) != 0)) {

    iVar5 = FUN_005b3400();

    if (iVar5 != 0) {

      uVar6 = FUN_005b3400();

      FUN_00970140("ReflectionSurface",uVar6);

    }

  }

  iVar5 = *(int *)(param_1 + 0xb0);

  piVar2 = *(int **)(param_1 + 0x8c);

  if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

    (**(code **)(*piVar2 + 4))();

  }

  piVar3 = *(int **)(iVar5 + 0x20);

  if (piVar3 != (int *)0x0) {

    piVar1 = piVar3 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar3 + 8))();

    }

  }

  *(int **)(iVar5 + 0x20) = piVar2;

  *(uint8_t *)(iVar5 + 0x24) = *(uint8_t *)(param_1 + 0x90);

  *(uint8_t *)(iVar5 + 0x25) = *(uint8_t *)(param_1 + 0x91);

  *(uint8_t *)(iVar5 + 0x26) = *(uint8_t *)(param_1 + 0x92);

  uVar6 = FUN_00491e30(0);

  if (*(int *)(param_1 + 0x8c) != 0) {

    FUN_00970140("BackBufferTexture",uVar6);

  }

  pvVar4 = *(void **)(param_1 + 0xc4);

  if (pvVar4 != (void *)0x0) {

    FUN_004c16f0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar4);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) = 0;

  FUN_004c1960();

  local_4._0_1_ = 1;

  FUN_0096efd0();

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0096efd0();

  local_4 = 0xffffffff;

  FUN_0096efd0();

  ExceptionList = pvStack_c;

  return;

}
