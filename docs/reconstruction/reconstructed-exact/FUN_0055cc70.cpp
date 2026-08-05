// =============================================================================
// FUN_0055cc70
// -----------------------------------------------------------------------------
// Stable ID: aa_0055cc70
// Address:   0x0055cc70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055cc70 @ 0x0055cc70
// Stable ID: aa_0055cc70
// Embedded strings (evidence for future rename):
//   - "NDParticleDistortBlendNormal.fx"
//   - "Particle_Distort.dds"
//   - "NormalMapTexture"
//   - "v2NormalMapExtents"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00989e00×2, FUN_00493550, FUN_0055cc70, FUN_0096ef70, FUN_0096efd0, FUN_0096f3e0, FUN_00970140, FUN_009701d0.
//  - Strings: "NDParticleDistortBlendNormal.fx"; "Particle_Distort.dds"; "NormalMapTexture"; "v2NormalMapExtents".
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

void __fastcall FUN_0055cc70(int param_1)



{

  uint32_t /* width from decompiler */ local_20;

  uint8_t local_1c [4];

  uint8_t local_18 [4];

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4987;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00989e00(local_1c,"NDParticleDistortBlendNormal.fx");

  FUN_009701d0(local_1c);

  FUN_0096ef70();

  local_4 = 0;

  FUN_00989e00(local_18,"Particle_Distort.dds");

  FUN_0096f3e0(local_18,0);

  FUN_00970140("NormalMapTexture",local_20);

  local_14 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x90) + 0x188);

  local_10 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x90) + 0x18c);

  FUN_00493550("v2NormalMapExtents",&local_14);

  local_4 = 0xffffffff;

  FUN_0096efd0();

  ExceptionList = local_c;

  return;

}
