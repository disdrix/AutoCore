// =============================================================================
// FUN_0055ca90
// -----------------------------------------------------------------------------
// Stable ID: aa_0055ca90
// Address:   0x0055ca90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055ca90 @ 0x0055ca90
// Stable ID: aa_0055ca90
// Embedded strings (evidence for future rename):
//   - "Particle_Distort.dds"
//   - "NDParticleDistortBlendNormal.fx"
//   - "NormalMapTexture"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00989e00×2, FUN_0055ca90, FUN_0075b390, FUN_0075b3b0, FUN_0075b450, FUN_0075bf40, FUN_00968a50, FUN_0096ef70.
//  - Strings: "Particle_Distort.dds"; "NDParticleDistortBlendNormal.fx"; "NormalMapTexture".
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

void __fastcall FUN_0055ca90(int param_1)



{

  int iVar1;

  uint8_t auStack_1c [4];

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  void *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4975;

  pvStack_c = ExceptionList;

  local_14 = *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1f058 + 0x2c) + 0x80);

  local_10 = *(void **)(*(int *)(DAT_00d1f058 + 0x2c) + 0x84);

  ExceptionList = &pvStack_c;

  local_18 = operator_new(0x198);

  local_4 = 0;

  if (local_18 == (void *)0x0) {

    iVar1 = 0;

  }

  else {

    iVar1 = FUN_00968a50();

  }

  *(int *)(param_1 + 0x90) = iVar1;

  *(byte *)(iVar1 + 0x195) = *(byte *)(iVar1 + 0x195) | 0x40;

  *(int *)(*(int *)(param_1 + 0x90) + 4) = param_1;

  local_4 = 0xffffffff;

  FUN_0075b3b0(0x3e4ccccd);

  FUN_0075b390(0x43fa0000);

  FUN_0075bf40(0xff808000);

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x90) + 0x180) = 0;

  FUN_0075b450();

  iVar1 = *(int *)(param_1 + 0x90);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0xec) = 0;

  *(uint8_t *)(iVar1 + 0x48) = 1;

  *(uint8_t *)(iVar1 + 0xcc) = 1;

  (**(code **)(**(int **)(param_1 + 0x90) + 0x18))(&local_14);

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x90) + 0x108) = 0;

  *(uint8_t *)(*(int *)(param_1 + 0x90) + 400) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x90) + 0x44);

  FUN_0096ef70();

  puStack_8 = (uint8_t *)0x1;

  FUN_00989e00(&stack0xffffffdc,"Particle_Distort.dds");

  FUN_0096f3e0(&stack0xffffffdc,0);

  FUN_00989e00(auStack_1c,"NDParticleDistortBlendNormal.fx");

  FUN_009701d0(auStack_1c);

  FUN_00970140("NormalMapTexture",0xff808000);

  puStack_8 = (uint8_t *)0xffffffff;

  FUN_0096efd0();

  ExceptionList = local_10;

  return;

}
