// =============================================================================
// Gfx_NDDiffAlphaParticleTerrain
// -----------------------------------------------------------------------------
// Stable ID: aa_009521c0
// Address:   0x009521c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_NDDiffAlphaParticleTerrain @ 0x009521c0
// Stable ID: aa_009521c0
// Embedded strings (evidence for future rename):
//   - "Particles.dds"
//   - "NDDiffAlphaParticle.fx"
//   - "ParticleTexture"
//   - "NDDiffAlphaParticleBright.fx"
//   - "NDDiffAlphaParticleTerrain.fx"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_00989e00×4, FUN_00752370×3, FUN_00970060×3, FUN_009701d0×3, FUN_0075de80, FUN_007ae100, Gfx_NDDiffAlphaParticleTerrain, FUN_0096efd0.
//  - Strings: "Particles.dds"; "NDDiffAlphaParticle.fx"; "ParticleTexture"; "NDDiffAlphaParticleBright.fx".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "NDDiffAlphaParticleTerrain.fx"
 * Domain alias of FUN_009521c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Gfx_NDDiffAlphaParticleTerrain(int param_1)



{

  int *piVar1;

  uint8_t local_14 [4];

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b16c2;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0075de80(1,0x41200000);

  FUN_007ae100();

  local_4 = 0;

  FUN_00989e00(local_14,"Particles.dds");

  FUN_0096f3e0(local_14,0);

  FUN_00989e00(&local_10,"NDDiffAlphaParticle.fx");

  FUN_009701d0(&local_10);

  piVar1 = &local_10;

  if (*(int *)(*(int *)(*(int *)(param_1 + 0xde8) + 0x174) + 0x20) == 0) {

    local_10 = -1;

  }

  else {

    piVar1 = (int *)FUN_00752370(piVar1,"ParticleTexture");

  }

  if (-1 < *piVar1) {

    FUN_00970060(*piVar1,0);

  }

  FUN_00989e00(&local_10,"NDDiffAlphaParticleBright.fx");

  FUN_009701d0(&local_10);

  piVar1 = &local_10;

  if (*(int *)(*(int *)(*(int *)(param_1 + 0xde8) + 0x188) + 0x20) == 0) {

    local_10 = -1;

  }

  else {

    piVar1 = (int *)FUN_00752370(piVar1,"ParticleTexture");

  }

  if (-1 < *piVar1) {

    FUN_00970060(*piVar1,0);

  }

  FUN_00989e00(&local_10,"NDDiffAlphaParticleTerrain.fx");

  FUN_009701d0(&local_10);

  piVar1 = &local_10;

  if (*(int *)(*(int *)(*(int *)(param_1 + 0xde8) + 0x19c) + 0x20) == 0) {

    local_10 = -1;

  }

  else {

    piVar1 = (int *)FUN_00752370(piVar1,"ParticleTexture");

  }

  if (-1 < *piVar1) {

    FUN_00970060(*piVar1,0);

  }

  local_4 = 0xffffffff;

  FUN_0096efd0();

  ExceptionList = local_c;

  return 1;

}
